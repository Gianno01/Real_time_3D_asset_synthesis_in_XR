# Real-Time 3D Asset Synthesis in XR

Voice-driven, real-time generation of 3D assets inside a Mixed Reality application for **Meta Quest Pro**.

The user presses a button on the controller, says the name of an object (e.g. *"a wooden medieval chair"*), and after a short wait the object appears in front of them as a 3D model, overlaid on the real room through passthrough. The object can then be grabbed, moved, rotated and scaled with hands or controllers.

The project was developed as part of a Master's thesis and internship at RAI on real-time 3D asset synthesis for XR.

---

## Table of contents

1. [How it works](#how-it-works)
2. [Repository structure](#repository-structure)
3. [Requirements](#requirements)
4. [Backend setup (PC / server)](#backend-setup-pc--server)
5. [n8n workflow setup](#n8n-workflow-setup)
6. [Unity project setup](#unity-project-setup)
7. [Meta Quest setup and build](#meta-quest-setup-and-build)
8. [Networking: connecting the headset to the server](#networking-connecting-the-headset-to-the-server)
9. [Usage](#usage)
10. [Troubleshooting](#troubleshooting)
11. [Security notes](#security-notes)
12. [Known limitations](#known-limitations)

---

## How it works

```
 ┌──────────────────────── Meta Quest Pro (Unity 6) ────────────────────────┐
 │  Button A → microphone recording → silence detection → .wav              │
 └───────────────┬───────────────────────────────────────────────▲──────────┘
                 │ 1. audio (.wav)                                │ 6. .glb download
                 ▼                                                │
        ┌─────────────────┐   2. text    ┌──────────────────────────────────┐
        │ Faster-Whisper  │ ───────────► │ n8n (orchestration)              │
        │ :9001 (Docker)  │   (via Unity)│ :5678 (Docker)                   │
        └─────────────────┘              │  a. LLM (Ollama / Qwen3) →       │
                                         │     English JSON prompt          │
                                         │  b. ComfyUI: text → image        │
                                         │  c. ComfyUI: image → 3D (.glb)   │
                                         │  d. polling until .glb is ready  │
                                         │  e. respond to Unity with URL    │
                                         └──────────────┬───────────────────┘
                                                        │ 3–5. HTTP API
                                                        ▼
                                         ┌──────────────────────────────────┐
                                         │ ComfyUI :8188 (host, GPU)        │
                                         │  Qwen-Image (2-step LoRA)        │
                                         │  Hunyuan 3D 2.1  (or Meshy API)  │
                                         └──────────────────────────────────┘
```

**Step by step**

1. **Unity** records the user's voice from the headset microphone and stops automatically after 1.5 s of silence.
2. The audio is sent to **Faster-Whisper** (OpenAI-compatible API), which returns the transcription (Italian by default).
3. Unity sends the text to an **n8n** webhook.
4. n8n asks an **LLM** (Qwen3 via Ollama, or Gemini) to turn the description into a structured English JSON prompt (`flux_prompt`, `object_name`, `style_tags`).
5. n8n calls **ComfyUI**:
   - **Qwen-Image** generates a single object on a white background;
   - the image is converted to Base64 and passed to **Hunyuan 3D 2.1**, which generates a mesh and saves it as `.glb`. **Meshy** (Comfy.org partner node, paid) is an optional alternative with PBR textures.
6. n8n polls ComfyUI's `/api/history/{prompt_id}` until the `.glb` is ready, then responds to Unity with its URL.
7. Unity downloads the `.glb`, loads it with **glTFast**, normalizes its size, places it in front of the user and makes it grabbable with the **XR Interaction Toolkit**: one hand moves and rotates it, two hands rotate and scale it.

---

## Repository structure

> Adjust the paths below if your layout differs.

```
Real_time_3D_asset_synthesis_in_XR/
├── MQ_XR_Previs/VR_Previs_MQ/        # Unity 6 project (Meta Quest Pro)
│   └── Assets/Scripts/
│       └── QuestObjectGenerator.cs   # Core runtime script
├── n8n/
│   └── AR Hololens_texture_multi.json  # n8n workflow (import into n8n)
├── docker-compose.yml                # n8n, Postgres, Ollama, Qdrant, Whisper
├── .env.example                      # Template for environment variables
└── README.md
```

Large binary assets are tracked with **Git LFS**. Install it before cloning:

```bash
git lfs install
git clone <repository-url>
```

---

## Requirements

### Hardware

| Component | Notes |
|---|---|
| **PC / server** | Windows 10/11 (tested), NVIDIA GPU with plenty of VRAM. The LLM, image model and Hunyuan 3D share the GPU; 24 GB or more is recommended. |
| **Meta Quest Pro** | Developer mode enabled. Other Quest devices with passthrough should work but are untested. |
| **USB-C cable** | For building to the headset and for the `adb reverse` tunnel. |

### Software

| Software | Version / notes |
|---|---|
| **Unity** | 6 (tested with `6000.6.3f1`), with the **Android Build Support** module (OpenJDK, Android SDK & NDK) |
| **Docker Desktop** | With NVIDIA GPU support (WSL2 backend on Windows) |
| **ComfyUI** | Recent version, running natively on the host (not in Docker) |
| **Meta Horizon app** | On a smartphone, to enable developer mode |
| **Meta developer account** | Free, required for developer mode |
| **Git + Git LFS** | To clone the repository |

---

## Backend setup (PC / server)

### 1. Environment variables

Create a `.env` file next to `docker-compose.yml`. Never commit it.

```env
POSTGRES_USER=n8n
POSTGRES_PASSWORD=change_me
POSTGRES_DB=n8n

N8N_ENCRYPTION_KEY=change_me_long_random_string
N8N_USER_MANAGEMENT_JWT_SECRET=change_me_long_random_string

# Optional – only if you use the Meshy (Comfy.org) branch
COMFY_ORG_API_KEY=
```

### 2. Start the Docker stack

```bash
docker compose --profile gpu-nvidia up -d
```

This starts the following services:

| Service | Port | Purpose |
|---|---|---|
| n8n | 5678 | Workflow orchestration |
| Postgres | – | n8n database |
| Ollama | 11434 | Local LLM |
| Qdrant | 6333 | Vector DB (from the starter kit, not used by the pipeline) |
| Whisper (`fedirz/faster-whisper-server`) | 9001 | Speech-to-text |

Then pull the LLM used by the workflow:

```bash
docker exec -it ollama ollama pull qwen3:30b-a3b-instruct-2507-q8_0
```

> **Linux hosts:** add `extra_hosts: ["host.docker.internal:host-gateway"]` to the n8n service if you want containers to reach services on the host by name.

> **VRAM tip:** if you get out-of-memory errors, set `OLLAMA_KEEP_ALIVE=0` on the Ollama container. The LLM is then unloaded after each request, which is slower but frees VRAM for ComfyUI.

### 3. ComfyUI

1. Install ComfyUI following the official instructions.
2. Install the custom node pack **ComfyUI-Easy-Use**, which provides the `easy loadImageBase64` node, for example via ComfyUI-Manager.
3. Download the models and place them in the corresponding `ComfyUI/models/` folders:

| File | Folder | Used by |
|---|---|---|
| `qwen_image_2512_fp8_e4m3fn.safetensors` | `diffusion_models/` | Qwen-Image |
| `qwen_2.5_vl_7b_fp8_scaled.safetensors` | `text_encoders/` | Qwen-Image |
| `qwen_image_vae.safetensors` | `vae/` | Qwen-Image |
| `Wuli-Qwen-Image-2512-Turbo-LoRA-2steps-V1.0-bf16.safetensors` | `loras/` | Qwen-Image (2-step) |
| `hunyuan_3d_v2.1.safetensors` | `checkpoints/` | Hunyuan 3D 2.1 |

4. Start ComfyUI so it accepts connections from the network:

```bash
python main.py --listen 0.0.0.0 --port 8188
```

5. Check it at `http://<SERVER_IP>:8188`.

### 4. Firewall (Windows)

Allow inbound connections on the three ports used by the headset. Run in an **administrator** PowerShell:

```powershell
New-NetFirewallRule -DisplayName "XR - n8n"     -Direction Inbound -Protocol TCP -LocalPort 5678 -Action Allow -Profile Any
New-NetFirewallRule -DisplayName "XR - Whisper" -Direction Inbound -Protocol TCP -LocalPort 9001 -Action Allow -Profile Any
New-NetFirewallRule -DisplayName "XR - ComfyUI" -Direction Inbound -Protocol TCP -LocalPort 8188 -Action Allow -Profile Any
```

This is not needed if you only use the USB tunnel (see [Networking](#networking-connecting-the-headset-to-the-server)).

---

## n8n workflow setup

1. Open n8n at `http://localhost:5678` and create the owner account.
2. **Import** the workflow JSON: *Workflows → Import from file*.
3. **Credentials**
   - **Ollama**: base URL `http://ollama:11434`, the container name inside the Docker network.
   - **ComfyUI** (used by the `n8n-nodes-comfyui` community node): URL `http://<SERVER_IP>:8188`.
   - **Google Gemini** (optional): only needed if you switch the LLM to Gemini.
4. **Update hard-coded addresses.** A sticky note in the workflow marks them.

| Node | Field | Value |
|---|---|---|
| `Comfy3D - Hunyuan` | URL | `http://<SERVER_IP>:8188/prompt` |
| `HTTP Request` (polling) | URL (Expression mode, no leading `=`) | `http://<SERVER_IP>:8188/api/history/{{ $('Comfy3D - Hunyuan').first().json.prompt_id }}` |
| `Code in JavaScript` (polling) | `host` / `port` | `<SERVER_IP>` / `8188` |

5. **Webhook.** Set the path (e.g. `quest-generate`). Make sure no other active workflow uses the same path.
6. **Activate** the workflow (toggle in the top-right corner). The headset must call the **production** URL `/webhook/...`. The test URL `/webhook-test/...` only works once, right after pressing *Execute workflow* in the editor.

### Hunyuan vs Meshy

| | Hunyuan 3D 2.1 (default) | Meshy (optional) |
|---|---|---|
| Runs on | Local GPU | Cloud (Comfy.org partner node) |
| Cost | Free | Paid with Comfy.org credits (≈ 30 credits per textured model) |
| Output | Untextured mesh | Textured mesh with optional PBR maps |
| Setup | Models above | Comfy.org account, credits and API key in `extra_data.api_key_comfy_org` (use `{{ $env.COMFY_ORG_API_KEY }}`, never a literal key) |

With Meshy, keep only the `SaveGLB` connected to the **GLB** output (index 2) of the Meshy node; index 3 is FBX. Set `should_remesh.target_polycount` to around 50 000 for Quest performance.

---

## Unity project setup

### 1. Open the project

Open `MQ_XR_Previs/VR_Previs_MQ` with **Unity 6** through Unity Hub, and switch the platform to **Android** (*File → Build Profiles → Android → Switch Platform*).

### 2. Packages (*Window → Package Manager*)

| Package | Purpose |
|---|---|
| OpenXR Plugin | XR runtime |
| Unity OpenXR: Meta (`com.unity.xr.meta-openxr`) | Meta Quest support and passthrough |
| AR Foundation | AR session and camera (passthrough) |
| XR Interaction Toolkit 3.x (+ *Starter Assets* sample) | Grabbing and manipulation |
| XR Hands (+ *Hands Interaction Demo* sample, optional) | Hand tracking |
| glTFast (`com.unity.cloud.gltfast`) | Runtime `.glb` loading |
| Input System | Controller input |

### 3. XR Plug-in Management (*Project Settings → XR Plug-in Management*, **Android** tab)

- ✅ **OpenXR** (only; not Oculus).
- **OpenXR → Android → Feature Groups → Meta Quest**:
  - ✅ Meta Quest Support
  - ✅ Meta Quest: Session
  - ✅ **Meta Quest: Camera (Passthrough)**
- **Interaction Profiles**: Oculus Touch Controller Profile, Meta Quest Touch Pro Controller Profile, Hand Interaction Profile.
- **Features**: Hand Tracking Subsystem, Meta Hand Tracking Aim.
- Open **Project Validation** and apply *Fix All*.

### 4. Player Settings (*Project Settings → Player → Android*)

| Setting | Value |
|---|---|
| Minimum API Level | **32** |
| Scripting Backend | **IL2CPP** |
| Target Architectures | **ARM64** only |
| Graphics APIs | **Vulkan** |
| Active Input Handling | **Input System Package (New)** |
| Internet Access | **Require** |
| **Allow downloads over HTTP** | **Always allowed** (all backend URLs are plain `http://`) |

### 5. Scene setup

- **XR Origin** with a single **Main Camera** inside `XR Origin → Camera Offset`. Delete any other camera tagged *MainCamera*.
- **AR Session** GameObject (*GameObject → XR → AR Session*).
- On the **Main Camera**:
  - **AR Camera Manager** component;
  - **Background Type**: *Solid Color*, colour **RGBA (0, 0, 0, 0)**. Alpha 0 is required for passthrough;
  - **Post Processing**: off.
- In the **URP Asset** used for Android: **HDR off**.
- **Lighting → Environment → Skybox Material**: *None*. Remove floors and sample environments.

### 6. `QuestObjectGenerator` component

Add `QuestObjectGenerator` to a GameObject in the scene and configure it **in the Inspector**. Inspector values override the defaults written in the script.

| Field | Example | Notes |
|---|---|---|
| Record Button | `XRI RightHand/Primary Button` | Button **A** |
| N8n Webhook Url | `http://127.0.0.1:5678/webhook/quest-generate` | Production URL |
| Whisper Url | `http://127.0.0.1:9001` | |
| Comfy Url | `http://127.0.0.1:8188` | Rewrites the host of the `.glb` URL returned by n8n, so the workflow does not need to change between networks |
| Head Transform | *Main Camera* | Optional; found automatically if empty |
| Fallback Material | a *URP/Lit* material | Applied to untextured meshes (Hunyuan). Leave empty for textured Meshy models |
| Target Object Size | `0.3` | Size of the largest dimension, in metres |
| Spawn Distance / Height Offset | `0.8` / `-0.2` | Placement in front of the user |

Use `127.0.0.1` addresses with the USB tunnel, or `<SERVER_IP>` on a shared network. Remember to **save the scene** after editing.

In Play mode in the Editor, press **Space** to trigger a test generation without speaking. In the Editor the background stays grey, because passthrough exists only on the device.

---

## Meta Quest setup and build

### One-time setup

1. In the **Meta Horizon** app on your phone: *Devices → your headset → Headset settings → Developer mode → On*. Restart the headset.
2. Connect the headset to the PC with the USB-C cable and accept **"Allow USB debugging"** in the headset (tick *Always allow*).
3. Verify the connection. `adb` is shipped with Unity:

```powershell
cd "C:\Program Files\Unity\Hub\Editor\<version>\Editor\Data\PlaybackEngines\AndroidPlayer\SDK\platform-tools"
.\adb devices      # should list the headset as "device"
```

### Build

1. *File → Build Profiles → Android*, with the scene included in the **Scene List**.
2. **Run Device**: select the Quest (*Refresh* if needed).
3. **Build And Run**. The app is installed and launched automatically.
4. At first launch, grant the **Microphone** permission.
5. To reopen the app later: *App Library → filter "Unknown sources"*.

### Logs

```powershell
.\adb logcat -s Unity
```

All runtime logs are prefixed with `[QuestObjectGenerator]`.

---

## Networking: connecting the headset to the server

The headset must reach three ports on the server: **5678** (n8n), **9001** (Whisper) and **8188** (ComfyUI, for the `.glb` download).

### Option A – USB tunnel (recommended for development)

Works on any network, including corporate Wi-Fi with client isolation or a PC on wired LAN. Run each command separately:

```powershell
.\adb reverse tcp:5678 tcp:5678
.\adb reverse tcp:9001 tcp:9001
.\adb reverse tcp:8188 tcp:8188
.\adb reverse --list
```

Use `http://127.0.0.1:<port>` in the Inspector. The tunnels are lost when the cable is unplugged or the headset reboots, so recreate them before each session.

### Option B – Same network (wireless)

The PC and the headset must be on the **same subnet**, with no client isolation. Use `http://<SERVER_IP>:<port>` in the Inspector and open the firewall ports.

To check reachability, open `http://<SERVER_IP>:8188` in the **headset's browser**: it should show ComfyUI. If it does not load:
- compare the headset IP (*Settings → Wi-Fi → network details*) with the server IP (`ipconfig`);
- check the firewall;
- ask IT to allow traffic between the headset and the server, or use a dedicated router or hotspot.

---

## Usage

1. Start Docker, ComfyUI and check that the n8n workflow is **active**.
2. **Warm up** the pipeline with one generation from the Editor (Space). The first request after start-up loads all models into VRAM and is much slower.
3. If using the USB tunnel, create the `adb reverse` tunnels.
4. Launch the app on the headset. You should see your room through passthrough.
5. Press **A**, say the object (e.g. *"una sedia di legno"*), then stay silent. Recording stops after 1.5 s of silence.
6. Wait for the generation (about 1–2 minutes with Hunyuan once the models are warm). The object appears about 0.8 m in front of you.
7. Interact with the object:
   - **one hand or controller grip**: grab, move, rotate;
   - **two hands**: rotate, and scale by moving the hands apart or together;
   - released objects stay in place (no gravity).

---

## Troubleshooting

| Symptom | Cause / fix |
|---|---|
| `The service refused the connection` in an n8n HTTP node | Wrong host or port for ComfyUI. Use the same URL as the working ComfyUI credential (`:8188`). |
| `Invalid URL: =http://…` | The field is already in **Expression** mode; remove the leading `=`. |
| Polling times out, but ComfyUI history shows `success` with only node `13` executed | A node failed **validation** and its outputs were skipped. Read `node_errors` in the `/prompt` response (e.g. `required_input_missing` after a node update). Check `/api/object_info/<NodeClass>` and re-export with *Export (API)*. |
| Polling loops forever after the mesh is done | The final `return` of the polling Code node must output `_ready: true` with `glb_url`; use `$runIndex` for the attempt counter. |
| Meshy fails at execution | No Comfy.org credits or invalid API key. Partner nodes are billed through Comfy.org, not through a Meshy subscription. |
| Unity: `n8n errore … HTTP 404` | Workflow inactive, wrong path, or using `/webhook-test/` without listening. |
| Object spawns far away | `Camera.main` points to a stray camera. Delete extra cameras or assign **Head Transform**. |
| Headset: links do not load in the browser | Network separation (see [Networking](#networking-connecting-the-headset-to-the-server)); use the USB tunnel. |
| Headset: everything black, only the Guardian boundary visible | Passthrough not started. Enable *Meta Quest: Camera (Passthrough)* in the **Android** tab, add **AR Session** and **AR Camera Manager**, set the camera background alpha to 0, and turn HDR and post-processing off. |
| Object invisible or pink in the build | glTFast shader stripped from the build. Assign a **Fallback Material**, or add glTFast shaders to *Graphics → Always Included Shaders*. |
| `Active Input Handling is set to "Both"` | Set it to **Input System Package (New)**. |
| Low framerate with several objects | Meshes are too dense. Lower the polycount (Meshy) or decimate the Hunyuan output. |

---

## Security notes

- **Never commit API keys** or the `.env` file. Add `.env` to `.gitignore`.
- In n8n, read secrets from environment variables (`{{ $env.COMFY_ORG_API_KEY }}`, with `N8N_BLOCK_ENV_ACCESS_IN_NODE=false`) instead of hard-coding them in node parameters. Exported workflow JSON files include node parameters in plain text.
- If a key has ever been committed or shared, **revoke it** and generate a new one.
- The backend services have no authentication on their HTTP APIs. Expose them only on trusted networks.

---

## Known limitations

- Recording is started with controller button **A**; there is no hand-only gesture yet.
- Hunyuan 3D output is untextured and can be high-poly for a mobile GPU.
- No visual feedback while the model is being generated (1–2 minutes).
- The polling Code node contains a hard-coded host; the Unity `Comfy Url` field rewrites it on the client side.
- Tested only on Meta Quest Pro with Unity 6 (`6000.6.3f1`) on Windows.
