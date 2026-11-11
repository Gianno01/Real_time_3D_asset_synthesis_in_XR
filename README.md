# Real-Time 3D Asset Synthesis in XR

Voice-driven, real-time generation of 3D assets inside a Mixed Reality application for **Meta Quest Pro**.

The user presses a button, says what they want (*"una sedia di legno medievale"*), approves a preview image, and after a short wait the object appears in front of them as a 3D model overlaid on the real room. Objects can be grabbed, moved, rotated and scaled, saved to a shared **library**, arranged into **scenes**, lit with virtual lights, shared live with other headsets and browsers, and exported to **Blender**.

Developed for a Master's thesis and internship at RAI – Radiotelevisione Italiana.

> Everything in this repository runs on one PC on your local network. The only internet access needed is for the first-time downloads (Docker images, models, Unity packages).

---

## Table of contents

1. [What it does](#what-it-does)
2. [Architecture](#architecture)
3. [Repository structure](#repository-structure)
4. [Requirements](#requirements)
5. [Quick start](#quick-start)
6. [Backend setup in detail](#backend-setup-in-detail)
7. [ComfyUI](#comfyui)
8. [n8n workflows](#n8n-workflows)
9. [Unity project and headset build](#unity-project-and-headset-build)
10. [Moving to another PC / changing the IP](#moving-to-another-pc--changing-the-ip)
11. [Usage](#usage)
12. [Web panel and Blender export](#web-panel-and-blender-export)
13. [Multiplayer: host, co-host, spectators](#multiplayer-host-co-host-spectators)
14. [Choosing the models](#choosing-the-models)
15. [Troubleshooting](#troubleshooting)
16. [Security notes](#security-notes)
17. [Known limitations](#known-limitations)

---

## What it does

- **Voice → image → 3D.** Speech is transcribed (Whisper), an LLM writes an English image prompt, ComfyUI generates a preview image (Qwen Image 2.1 Turbo), the user approves it, and an image-to-3D model produces a `.glb` (IDOL, Pixal3D or Trellis2, selectable at runtime).
- **Library.** Approved objects are stored on a server (Postgres + SeaweedFS) with a semantic search (Qdrant + `bge-m3`). Before generating, the app suggests similar objects already in the inventory.
- **Scenes.** Save, load, duplicate and rename scenes with object positions, scales and lights.
- **Lighting and occlusion.** Virtual lights, room dimming and occlusion blocks, calibrated on the real room.
- **Placement aids.** Grid snapping, measurements, contact shadows, collisions, optional gravity.
- **Multiplayer.** One host, one co-host and any number of spectators (headsets or browsers).
- **Web panel.** Manage the inventory and scenes from a browser, preview models in 3D, and **export a scene to Blender**.

---

## Architecture

```
 ┌──────────────────────── Meta Quest Pro (Unity 6) ────────────────────────┐
 │  voice / keyboard UI · library · scenes · lights · multiplayer client    │
 └──────┬───────────────┬──────────────────────┬────────────────────────────┘
        │ audio         │ requests             │ files / library / sync
        ▼               ▼                      ▼
  Whisper :9010    n8n :5678              nginx :8090  (assets, /admin, /viewer, /sync)
                   │  quest-generate        │        │
                   │  quest-library         ▼        ▼
                   │  quest-cancel      SeaweedFS   relay "sync" (Node + ws)
                   ▼
      ┌──────────────────────────┐        Postgres · Qdrant :6333 · Ollama :11434
      │ ComfyUI :8188 (host, GPU)│
      │  Qwen Image 2.1 Turbo    │   text → image
      │  IDOL / Pixal3D / Trellis2│  image → 3D (.glb)
      └──────────────────────────┘
```

**Generation flow (two phases, one webhook `quest-generate`)**

1. Unity records the voice (stops after silence) and sends it to **Whisper**.
2. Unity asks the library for similar objects; if there are any, it offers them first.
3. `action = "image"`: n8n asks the **LLM** (Ollama) for a JSON prompt, ComfyUI makes a preview image. The user can approve, repeat or correct it.
4. `action = "model"`: n8n sends the approved image to the selected 3D model in ComfyUI and polls `/api/history/{prompt_id}` until the `.glb` exists, then answers Unity with its URL.
5. Unity downloads the `.glb` with **glTFast**, aligns and scales it, adds colliders and grab interaction, and places it in front of the user.
6. *Annulla* calls the webhook `quest-cancel`, which interrupts ComfyUI and clears its queue. The generation workflow also checks an n8n data table (`quest_cancel`, column `session_id`) in its polling loop and stops if the session is listed there.

---

## Repository structure

```
Real_time_3D_asset_synthesis_in_XR/
├── README.md                            this file
├── set_ip.sh                            finds this PC's IP and replaces the old one in the project
├── AR_MetaQuest.json                    n8n workflow: generation (webhook quest-generate)
├── Quest - Libreria.json                n8n workflow: library and scenes (webhook quest-library)
├── n8n_quest_cancel.json                n8n workflow: cancel a running generation
├── MQ_XR_Previs/VR_Previs_MQ/           Unity 6 project for Meta Quest Pro
│   └── Assets/Scripts/                  all C# scripts; Assets/Resources/ holds the shaders
├── self-hosted-ai-starter-kit/          Docker stack
│   ├── docker-compose.yml               n8n, Postgres, Ollama, Qdrant, Whisper
│   ├── docker-compose.override.yml      SeaweedFS, nginx (:8090), multiplayer relay
│   ├── library_schema.sql               Postgres tables for the library
│   ├── assets-web/                      web panel (admin/), 3D viewer (viewer/), nginx.conf, LEGGIMI.md
│   ├── sync/                            multiplayer relay (Node.js)
│   ├── n8n/demo-data/                   starter-kit demo data
│   └── .env                             secrets — NOT in git, see below
├── HL_XR_Previs/                        earlier HoloLens version
├── old_workflow/                        previous workflow versions
└── paper/                               thesis material
```

Large binaries are tracked with **Git LFS**. Install it before cloning:

```bash
git lfs install
git clone <repository-url>
```

---

## Requirements

### Hardware

| Component | Notes |
|---|---|
| **PC / server** | Windows 10/11 (tested). NVIDIA GPU with plenty of VRAM for ComfyUI; the image and 3D models share it. 24 GB or more is recommended. Without a suitable GPU the pipeline will not run in a useful time. |
| **Meta Quest Pro** | Developer mode on. Other Quest headsets with passthrough are untested. |
| **Network** | PC and headset on the **same subnet**, no client isolation. A dedicated router or phone hotspot is the safest option. |
| **USB-C cable** | For building and the optional `adb reverse` tunnel. |

### Software

| Software | Version / notes |
|---|---|
| **Unity** | 6 (`6000.6.3f1`) with the **Android Build Support** module (OpenJDK, SDK & NDK) |
| **Docker Desktop** | WSL2 backend, NVIDIA GPU support if you use the GPU profile |
| **ComfyUI** | Recent version (≥ 0.22), running natively on the host, not in Docker |
| **Git + Git LFS** | To clone |
| **Bash** | To run `set_ip.sh`: Git Bash (comes with Git for Windows), WSL, Linux or macOS |
| **Meta Horizon app + developer account** | To enable developer mode on the headset |

Unity packages are already declared in `Packages/manifest.json` and install by themselves on first open: OpenXR, Unity OpenXR: Meta, AR Foundation, XR Interaction Toolkit 3.x, XR Hands, glTFast, Input System, Netcode for GameObjects, URP.

---

## Quick start

For a clean PC, in this order:

1. Install Git + Git LFS, Docker Desktop, Unity 6000.6.3f1 (with Android module) and ComfyUI.
2. `git lfs install` and clone the repository.
3. Create `self-hosted-ai-starter-kit/.env` ([template](#1-environment-file)).
4. `cd self-hosted-ai-starter-kit` and `docker compose --profile gpu-nvidia up -d` (use `--profile cpu` without an Nvidia GPU).
5. Pull the Ollama models and create the database ([details](#backend-setup-in-detail)).
6. Install ComfyUI custom nodes and download the models ([ComfyUI](#comfyui)); start it with `--listen 0.0.0.0`.
7. In n8n import the three workflows, create the credentials and the `quest_cancel` data table, then activate them ([n8n workflows](#n8n-workflows)).
8. Run `bash set_ip.sh` to put this PC's IP everywhere, then `bash set_ip.sh --apply` ([IP](#moving-to-another-pc--changing-the-ip)). Re-import the workflows afterwards.
9. Open the firewall ports ([Firewall](#4-firewall-windows)).
10. Open the Unity project, check the URLs, build to the headset ([Unity](#unity-project-and-headset-build)).

---

## Backend setup in detail

All commands run in `self-hosted-ai-starter-kit/`.

### 1. Environment file

Create `.env` next to `docker-compose.yml`. It is in `.gitignore` and **is not in the repository**: you must create it on every machine.

```env
POSTGRES_USER=root
POSTGRES_PASSWORD=change_me
POSTGRES_DB=n8n

N8N_ENCRYPTION_KEY=change_me_long_random_string
N8N_USER_MANAGEMENT_JWT_SECRET=change_me_long_random_string
N8N_DEFAULT_BINARY_DATA_MODE=filesystem
```

On a new PC you can invent new values. Credentials saved in n8n are encrypted with `N8N_ENCRYPTION_KEY`: if you copy an existing n8n volume you must keep the same key.

### 2. Start the stack

```bash
docker compose --profile gpu-nvidia up -d      # Nvidia GPU
docker compose --profile cpu up -d             # no GPU (slow LLM)
```

`docker-compose.override.yml` is merged automatically. Services:

| Service | Host port | Purpose |
|---|---|---|
| n8n | 5678 | Workflow orchestration |
| Postgres | – | n8n database and library |
| Ollama | 11434 | LLM and embeddings |
| Qdrant | 6333 | Semantic search index |
| Whisper (`faster-whisper-server`) | **9010** | Speech-to-text (maps to 8000 in the container) |
| nginx (`assets-web`) | **8090** | Files, web panel `/admin/`, viewer `/viewer/`, relay `/sync`, health `/health` |
| SeaweedFS | – | File storage, internal only |
| sync | – | Multiplayer relay, reached through nginx |

On first start the `sync` container installs its Node packages, which needs internet once. Check `http://localhost:8090/health` → `ok`.

### 3. Ollama models and database

```bash
docker exec -it ollama ollama pull bge-m3          # embeddings for the library search (required)
docker exec -it ollama ollama pull <your LLM>      # the model selected in the n8n AI Agent node
```

The LLM name must match the one in the n8n *Ollama Chat Model* nodes (see [Choosing the models](#choosing-the-models)).

Create the library tables (safe to run again, data is kept):

```bash
docker compose exec -T postgres psql -U <POSTGRES_USER> -d <POSTGRES_DB> < library_schema.sql
```

### 4. Firewall (Windows)

Administrator PowerShell, so that the headset can reach the PC:

```powershell
foreach ($p in 5678,8090,8188,9010) {
  New-NetFirewallRule -DisplayName "XR - port $p" -Direction Inbound -Protocol TCP -LocalPort $p -Action Allow -Profile Any
}
```

Not needed if you only use the USB tunnel.

---

## ComfyUI

Install ComfyUI natively, then:

1. Install **ComfyUI-Easy-Use** (node `easy loadImageBase64`) from ComfyUI-Manager.
2. Open each workflow below in ComfyUI once and use *Manager → Install Missing Custom Nodes* for anything else it reports (the Pixal3D and Trellis2 branches depend on their own node packs and models).
3. Download the models into `ComfyUI/models/`:

| File | Folder | Used by |
|---|---|---|
| `qwen_image_2.1_turbo_int8_convrot.safetensors` | `diffusion_models/` | Preview image (Qwen Image 2.1 Turbo) |
| `qwen3vl_8b_int8_convrot.safetensors` | `text_encoders/` | Preview image |
| `qwen_image_2.1_vae_bf16.safetensors` | `vae/` | Preview image |
| `idol_fp16.safetensors` | `diffusion_models/` | IDOL (image → gaussian splat → mesh) |
| `idol_decoder_fp16.safetensors` | `vae/` | IDOL |
| `dino_v3_vit_h_bf16.safetensors` | `clip_vision/` | IDOL |
| `flux2-vae.safetensors` | `vae/` | IDOL |
| `birefnet.safetensors` | background-removal models folder | IDOL background removal |
| Pixal3D / Trellis2 files | as required by their node packs | Alternative 3D models |

4. Start it so the network can reach it:

```bash
python main.py --listen 0.0.0.0 --port 8188
```

Check `http://<PC_IP>:8188` from the headset browser.

---

## n8n workflows

Open `http://localhost:5678` and create the owner account.

### 1. Import

*Workflows → Import from file*, one by one:

| File | Webhook path | Role |
|---|---|---|
| `AR_MetaQuest.json` | `quest-generate` | Image and 3D generation |
| `Quest - Libreria.json` | `quest-library` | Inventory, scenes, semantic search |
| `n8n_quest_cancel.json` | `quest-cancel` | Cancel a generation |

Make sure no other **active** workflow uses the same webhook path, otherwise the old one answers and your edits seem to have no effect.

### 2. Credentials

| Credential | Value |
|---|---|
| **Ollama** | Base URL `http://ollama:11434` |
| **Postgres** | Host `postgres`, port `5432`, database/user/password from `.env`, SSL off |
| **ComfyUI** (community node `n8n-nodes-comfyui`) | URL `http://host.docker.internal:8188` |

Open every node that shows a red credential warning and select the credential you just created. In `Quest - Libreria` only the **Database** node uses Postgres.

### 3. Data table

*Data tables → Create* a table named **`quest_cancel`** with a text column `session_id`. The polling loop of `AR_MetaQuest.json` reads it (nodes *Annullata? (polling)* and *Get row(s)*) to stop a request cancelled by the user; select the table again in those nodes after importing. The `n8n_quest_cancel.json` in this repository only interrupts ComfyUI; if you want cancelled sessions to be recorded, add a *Data table → Insert row* node (`session_id`) to it.

### 4. IP addresses

Nodes that call ComfyUI use `http://host.docker.internal:8188` (works from inside Docker, nothing to change). The polling *Code* nodes that build the `.glb` URL contain the PC's LAN IP, which the **headset** must be able to reach. `set_ip.sh` replaces it for you — see below.

### 5. Activate

Switch each workflow to **Active**. The headset must call the **production** URL `/webhook/...`; `/webhook-test/...` works only once from the editor.

### 6. Build the search index

```bash
curl.exe -X POST http://localhost:5678/webhook/quest-library -H "Content-Type: application/json" -d "{\"action\":\"list_assets\"}"
curl.exe -X POST http://localhost:5678/webhook/quest-library -H "Content-Type: application/json" -d "{\"action\":\"reindex\"}"
```

The first must answer `"ok":true`. `reindex` creates the Qdrant collection `xr_assets`; run it again whenever Qdrant is empty (also available in the web panel: *Strumenti → Reindicizza*).

---

## Unity project and headset build

### 1. Open

Open `MQ_XR_Previs/VR_Previs_MQ` with Unity Hub (6000.6.3f1). Let it import (first time takes a while) and switch to **Android** (*File → Build Profiles*).

### 2. Project settings (already saved in the project, verify after opening)

- *XR Plug-in Management → Android*: **OpenXR** only, features *Meta Quest Support/Session/Camera (Passthrough)*, interaction profiles *Oculus Touch*, *Touch Pro*, *Hand Interaction*.
- *Player → Android*: min API 32, IL2CPP, ARM64, Vulkan, Input System (New), Internet Access Require, **Allow downloads over HTTP: Always** (all backend URLs are plain `http://`).
- Camera background **RGBA (0,0,0,0)**, HDR off, post-processing off.
- `Assets/Resources/` contains the shaders (depth occlusion, dimming, materialize effect and `VertexColorLit`) and must stay there: they are loaded by name at runtime.

### 3. Server addresses

Select the GameObjects and set:

| Component | Field | Value |
|---|---|---|
| `QuestObjectGenerator` | N8n Webhook Url | `http://<PC_IP>:5678/webhook/quest-generate` |
| | Whisper Url | `http://<PC_IP>:9010` |
| | Comfy Url | `http://<PC_IP>:8188` |
| `AssetLibrary` | Library Url | `http://<PC_IP>:5678/webhook/quest-library` |
| | Storage Url | `http://<PC_IP>:8090` |

The multiplayer relay address is derived from *Storage Url* (`ws://<PC_IP>:8090/sync`). Most options can also be changed on the headset in the **Settings** panel. Save the scene.

> `set_ip.sh` rewrites these defaults if they are stored in script or scene files.

### 4. Headset

1. Meta Horizon app → *Devices → headset → Developer mode → On*, restart the headset.
2. Connect USB-C and accept *Allow USB debugging*. Check with `adb devices` (`adb` is in `…\Editor\Data\PlaybackEngines\AndroidPlayer\SDK\platform-tools`).
3. *Build And Run* with the Quest as Run Device. Grant the **Microphone** permission at first launch. To reopen later: *App Library → Unknown sources*.
4. Logs: `adb logcat -s Unity`.

### USB tunnel (alternative to Wi-Fi)

```powershell
.\adb reverse tcp:5678 tcp:5678
.\adb reverse tcp:9010 tcp:9010
.\adb reverse tcp:8188 tcp:8188
.\adb reverse tcp:8090 tcp:8090
```

Then use `http://127.0.0.1:<port>` in the Unity fields. Tunnels are lost when the cable is removed.

---

## Moving to another PC / changing the IP

`set_ip.sh` finds the PC's IPv4 address and replaces the old one in JSON, C#, scene, prefab, asset, YAML, config and text files (skipping `.git`, `Library`, `Temp`, `obj`, `node_modules`, builds).

```bash
bash set_ip.sh                      # dry run: shows what would change
bash set_ip.sh --apply              # applies (keeps *.bak_ip backups)
bash set_ip.sh --apply --ip 192.168.1.20      # force an IP if detection picks the wrong adapter
bash set_ip.sh --apply --old 10.0.0.5         # another old IP to replace (repeatable)
```

Afterwards:

1. **Re-import** the modified workflows into n8n (n8n keeps its own copy).
2. Enter the new IP in the headset **Settings** panel, or rebuild.
3. Check there is no old address left, for example with `grep -r "10.54" .`.
4. Delete the `*.bak_ip` backups.

What does **not** travel with the repository: `.env`, Docker volumes (database, library files, Qdrant, n8n credentials), ComfyUI and its models. To keep the existing library, dump Postgres (`pg_dump`) and copy the SeaweedFS and Qdrant volumes; otherwise start empty and let the library fill again.

---

## Usage

1. Start Docker, ComfyUI, and check the three n8n workflows are active.
2. **Warm up** with one generation: the first request loads all models into VRAM and is slow.
3. Launch the app on the headset. After opening it, the calibration of the room starts by itself (two points).
4. Press the record button, say the object, stay silent. Choose among the library suggestions or *Genera nuovo*.
5. Approve the preview image (or repeat / correct it). The 3D model arrives in about a minute with IDOL.
6. Interact: one hand or controller grip moves and rotates; two hands rotate and scale. Released objects stay in place.
7. Under a held object: **Salva · Duplica · Elimina**. *Salva* stores it in the inventory.
8. **Libreria** (right of the control panel): *Inventario*, *Scene*, search by voice, insert, save or load scenes.
9. **Settings** (gear): model selection (IDOL / Pixal3D / Trellis2), grid and snapping, shadows, microphone sensitivity, multiplayer role, and more.

In the Editor, **Space** triggers a test generation without speaking. In the Editor the background is grey; passthrough exists only on the device.

---

## Web panel and Blender export

Open `http://<PC_IP>:8090/admin/` from any browser on the network.

- **Inventario** – search, filters, 3D preview, edit name / category / style / description / real height, download the `.glb`.
- **Carica** – drag in `.glb` files, complete the metadata and save them to the inventory.
- **Scene** – list, top-down plan, rename, delete, and **Export to Blender**: downloads a `.glb` with the objects placed exactly as in the scene (position, rotation, scale and alignment) plus the lights. Occlusion blocks and room dimming are **not** exported. In Blender: *File → Import → glTF 2.0*.
- **Strumenti** – service status, re-index, author name.
- **Viewer** – `http://<PC_IP>:8090/viewer/` is a read-only 3D view for phones and tablets.

More details on the library, thresholds and the semantic search are in `self-hosted-ai-starter-kit/assets-web/LEGGIMI.md` (Italian).

---

## Multiplayer: host, co-host, spectators

Set the role in *Settings → MULTIPLAYER → Questo dispositivo*:

| Role | Can do |
|---|---|
| **Host** | Owns the scene; changes are published to everyone. One at a time. |
| **Co-host** | Edits the same scene together with the host. One at a time. |
| **Spectator** | Sees the scene live (headset or browser at `/viewer/`). |

A second host or co-host is refused with a message. Links: WebSocket relay (`ws://<PC_IP>:8090/sync`) and, if the Netcode package is present, direct headset-to-headset. To restart the relay: `docker compose restart sync`.

---

## Choosing the models

**3D model** – *Settings → Modello 3D*, or the default in the n8n *Switch* node:

| Model | Characteristics |
|---|---|
| **IDOL** | Fastest (whole pipeline about 1 minute). Image → gaussian splat → mesh with vertex colors only. Quality depends on the `SplatToMesh` parameters; holes behind the object are normal because only the front view is known. |
| **Pixal3D** | Higher quality, slower. |
| **Trellis2** | Alternative, slower. |

**IDOL mesh quality** – in the IDOL request body of `AR_MetaQuest.json`:

| Node | Parameter | Effect |
|---|---|---|
| `88:55` | `num_gaussians` | More points, fewer gaps, slower |
| `76` SplatToMesh | `resolution`, `level`, `min_opacity`, `min_component` | Detail vs holes vs floating fragments. A very low `level` creates double shells and flicker |
| `300` DecimateMesh | `target_face_count` | **Quest performance.** ~100 000–300 000 faces is a good range; millions of faces make the headset flicker and drop frames |

IDOL files only have vertex colors and an unlit material. The Unity script recalculates normals and swaps in the lit `VertexColorLit` shader so they react to scene lights.

**LLM** – any instruct model served by Ollama. Pull it, then set the same name in the *Ollama Chat Model* nodes. The agent must return only the JSON (`flux_prompt`, `subject_type`, `aspect`, `object_name`, `style_tags`); small models sometimes add text, in which case the fallback loses `subject_type`/`aspect`.

**Preview image** – Qwen Image 2.1 Turbo, 8-step schedule, CFG 1, no negative prompt. Sizes: 704×928 (tall), 928×704 (wide), 800×800 (square).

---

## Troubleshooting

| Symptom | Cause / fix |
|---|---|
| New settings in n8n seem to have no effect | Two active workflows share the webhook path, or you edited a branch the webhook does not reach. Check *Executions* and the node input. |
| `Bad request` in an n8n HTTP node calling ComfyUI | The JSON body is wrong. It must be `{"prompt": {...}}`, with valid node ids. ComfyUI's response shows the offending node. |
| `The value in the "JSON Body" field is not valid JSON` | The field starts with `==`. Keep a single `=`. |
| `The service refused the connection` | Wrong host or port. Containers reach ComfyUI at `host.docker.internal:8188`. |
| Polling times out, history shows success but no `.glb` | A node failed validation and its outputs were skipped. Read `node_errors` of the `/prompt` response. |
| Headset cannot reach the server | Different subnet / client isolation / firewall. Open `http://<PC_IP>:8090/health` in the headset browser. Use a dedicated router or the USB tunnel. |
| Everything black, only the boundary visible | Passthrough not started: enable *Meta Quest: Camera (Passthrough)* on the **Android** tab, add AR Session and AR Camera Manager, camera alpha 0, HDR and post-processing off. |
| Object invisible or pink | glTFast shader stripped. Assign a **Fallback Material** or add the glTFast shaders to *Always Included Shaders*. |
| IDOL model flickers, many frames lost | Too many faces. Lower `target_face_count` in node `300`; check the `.glb` is a few MB, not 100+ MB. |
| IDOL model ignores the lights | `Assets/Resources/VertexColorLit.shader` missing or the Unity script is not updated. |
| Library search says `"mode":"text"` | Qdrant or Ollama not answering, `bge-m3` not pulled, or `reindex` never run. |
| Web panel: "Webhook non trovato" | The `Quest - Libreria` workflow is not active. |
| `assets-web` does not start | `docker compose logs assets-web`; nginx needs the `n8n` and `seaweedfs` services. |
| `Active Input Handling is set to "Both"` | Set it to **Input System Package (New)**. |
| Object spawns far away | A stray camera tagged MainCamera. Delete extra cameras or assign **Head Transform**. |
| Second host / co-host is refused | By design, only one of each. Free the slot or join as spectator. |

---

## Security notes

- **Never commit API keys or `.env`.** Exported n8n workflow JSON files contain node parameters in plain text; check them for keys (for example Comfy.org) before pushing, and revoke any key that was ever shared.
- The webhooks, the web panel and the relay have **no authentication**: anyone on the same network can read, save and delete. Use a private router or hotspot. A password for the panel is described at the top of `assets-web/nginx.conf`.
- Qdrant's port 6333 is published only for its dashboard; remove `ports` from the `qdrant` service if you do not need it.

---

## Known limitations

- IDOL meshes have vertex colors only and may show holes on the unseen side.
- Calibration and occlusion work in the calibrated room; moving the headset between rooms requires recalibration.
- Tested only on Meta Quest Pro with Unity `6000.6.3f1` and Windows.
- ComfyUI and its models are not part of the repository and must be installed separately.
