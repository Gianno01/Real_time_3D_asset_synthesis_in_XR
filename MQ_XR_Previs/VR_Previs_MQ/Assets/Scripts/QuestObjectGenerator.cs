// QuestObjectGenerator.cs
// Compatibile con: Unity 6 + Meta Quest Pro + OpenXR + XR Interaction Toolkit 3.x + AR Foundation + glTFast
//
// Pipeline: tasto A → registrazione microfono → Whisper (STT) → n8n (LLM + ComfyUI) → download .glb → glTFast
//           → oggetto davanti all'utente, afferrabile/ruotabile/scalabile con mani o controller.
//
// INSPECTOR:
//   - Record Button     → XRI RightHand/Primary Button (tasto A)
//   - N8n Webhook Url   → es. http://127.0.0.1:5678/webhook/quest-generate   (con adb reverse)
//   - Whisper Url       → es. http://127.0.0.1:9001
//   - Comfy Url         → es. http://127.0.0.1:8188  (riscrive l'host del glb_url restituito da n8n)
//   - Head Transform    → Main Camera dentro XR Origin (opzionale, altrimenti la cerca da solo)
//   - Fallback Material → materiale URP/Lit per mesh senza texture (Hunyuan)

using System;
using System.Collections;
using System.Text;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.Android;
using UnityEngine.InputSystem;
using Unity.XR.CoreUtils;
using UnityEngine.XR.Interaction.Toolkit.Interactables;
using UnityEngine.XR.Interaction.Toolkit.Transformers;
using GLTFast;

public class QuestObjectGenerator : MonoBehaviour
{
    // ── Configurazione ────────────────────────────────────────────────

    [Header("Input Controller")]
    [Tooltip("Tasto per avviare/fermare la registrazione vocale (es. XRI RightHand/Primary Button - Tasto A)")]
    public InputActionReference recordButton;

    [Header("Configurazione rete")]
    [Tooltip("Webhook di PRODUZIONE n8n (/webhook/, non /webhook-test/)")]
    public string n8nWebhookUrl = "http://127.0.0.1:5678/webhook/quest-generate";
    public string whisperUrl = "http://127.0.0.1:9001";
    [Tooltip("Indirizzo di ComfyUI come lo vede il VISORE (con adb reverse: http://127.0.0.1:8188). Vuoto = usa il glb_url così com'è")]
    public string comfyUrl = "http://127.0.0.1:8188";
    public float timeoutSeconds = 700f;

    [Header("Riferimenti XR")]
    [Tooltip("Main Camera dentro XR Origin (opzionale: se vuoto la cerca da solo)")]
    public Transform headTransform;

    [Header("Dimensioni e Posizionamento")]
    public float targetObjectSize = 0.3f;
    [Tooltip("Distanza (in metri) davanti allo sguardo a cui compare l'oggetto")]
    public float spawnDistance = 0.8f;
    [Tooltip("Spostamento verticale rispetto all'altezza degli occhi (negativo = più in basso)")]
    public float spawnHeightOffset = -0.2f;
    [Tooltip("Se attivo, l'oggetto viene ruotato (solo sull'asse Y) in modo che il suo fronte guardi l'utente")]
    public bool faceUser = true;

    [Header("Manipolazione")]
    [Tooltip("Scala minima rispetto a quella iniziale (presa a due mani)")]
    public float minScaleRatio = 0.25f;
    [Tooltip("Scala massima rispetto a quella iniziale (presa a due mani)")]
    public float maxScaleRatio = 5f;

    [Header("Materiali")]
    [Tooltip("Materiale URP/Lit applicato ai modelli senza texture (Hunyuan). Lascia vuoto per modelli texturizzati (Meshy)")]
    public Material fallbackMaterial;

    [Header("Feedback Visivo / Sonoro")]
    public AudioClip successSound;
    public AudioClip errorSound;
    public AudioClip recordingStartSound;

    // ── Stato interno ─────────────────────────────────────────────────

    private bool _isGenerating = false;
    private bool _isRecording = false;
    private AudioSource _audioSource;
    private string _sessionId;

    // ── Registrazione audio ───────────────────────────────────────────

    private AudioClip _recordingClip;
    private string _micDevice;
    private const int SAMPLE_RATE = 16000;
    private const int MAX_RECORDING_SECONDS = 30;
    private const float SILENCE_THRESHOLD = 0.03f;
    private const float SILENCE_DURATION = 1.5f;

    // ── Unity lifecycle ───────────────────────────────────────────────

    void Awake()
    {
        _audioSource = gameObject.AddComponent<AudioSource>();
        _sessionId = Guid.NewGuid().ToString("N").Substring(0, 8);

#if UNITY_ANDROID && !UNITY_EDITOR
        if (!Permission.HasUserAuthorizedPermission(Permission.Microphone))
            Permission.RequestUserPermission(Permission.Microphone);
#endif
    }

    void OnEnable()
    {
        if (recordButton != null && recordButton.action != null)
        {
            recordButton.action.Enable();
            recordButton.action.started += OnRecordButtonPressed;
        }
    }

    void OnDisable()
    {
        if (recordButton != null && recordButton.action != null)
        {
            recordButton.action.started -= OnRecordButtonPressed;
            recordButton.action.Disable();
        }
    }

    void Update()
    {
#if UNITY_EDITOR
        // Test veloci nell'Editor tramite tastiera (nuovo Input System)
        if (Keyboard.current != null && Keyboard.current.spaceKey.wasPressedThisFrame && !_isGenerating)
            TriggerGeneration("un vaso di ceramica decorato");
#endif
    }

    // ── Gestione Input Controller ─────────────────────────────────────

    private void OnRecordButtonPressed(InputAction.CallbackContext context)
    {
        if (_isGenerating) return;

        if (!_isRecording) StartRecording();
        else StopRecordingAndSend();
    }

    // ── Registrazione audio ───────────────────────────────────────────

    private void StartRecording()
    {
        if (_isRecording) return;

#if UNITY_ANDROID && !UNITY_EDITOR
        if (!Permission.HasUserAuthorizedPermission(Permission.Microphone))
        {
            Debug.LogWarning("[QuestObjectGenerator] Permesso microfono mancante!");
            Permission.RequestUserPermission(Permission.Microphone);
            return;
        }
#endif

        _micDevice = Microphone.devices.Length > 0 ? Microphone.devices[0] : null;
        _recordingClip = Microphone.Start(_micDevice, false, MAX_RECORDING_SECONDS, SAMPLE_RATE);
        _isRecording = true;

        PlaySound(recordingStartSound);
        Debug.Log($"[QuestObjectGenerator] Registrazione avviata su: {_micDevice ?? "default"}");

        StartCoroutine(SilenceDetection());
    }

    private IEnumerator SilenceDetection()
    {
        yield return new WaitForSeconds(1.0f);

        float silenceTimer = 0f;
        int sampleWindow = SAMPLE_RATE / 10; // 100 ms
        float[] window = new float[sampleWindow];
        var wait = new WaitForSeconds(0.1f);

        while (_isRecording)
        {
            // Buffer di 30 s esaurito → invia quello che c'è
            if (!Microphone.IsRecording(_micDevice))
            {
                StopRecordingAndSend();
                yield break;
            }

            int micPos = Microphone.GetPosition(_micDevice);
            if (micPos > sampleWindow)
            {
                _recordingClip.GetData(window, micPos - sampleWindow);
                float maxVol = 0f;
                foreach (float s in window) maxVol = Mathf.Max(maxVol, Mathf.Abs(s));

                silenceTimer = maxVol < SILENCE_THRESHOLD ? silenceTimer + 0.1f : 0f;
                if (silenceTimer >= SILENCE_DURATION)
                {
                    Debug.Log("[QuestObjectGenerator] Silenzio rilevato — invio audio...");
                    StopRecordingAndSend();
                    yield break;
                }
            }
            yield return wait;
        }
    }

    private void StopRecordingAndSend()
    {
        if (!_isRecording) return;

        int micPos = Microphone.GetPosition(_micDevice);
        int sampleCount = micPos > 0 ? micPos : _recordingClip.samples; // 0 = buffer pieno
        Microphone.End(_micDevice);
        _isRecording = false;

        if (sampleCount < SAMPLE_RATE / 2)
        {
            Debug.LogWarning("[QuestObjectGenerator] Registrazione troppo corta, ignoro.");
            return;
        }

        float[] samples = new float[sampleCount];
        _recordingClip.GetData(samples, 0);

        Debug.Log($"[QuestObjectGenerator] Registrazione terminata: {sampleCount / (float)SAMPLE_RATE:F1}s");
        StartCoroutine(SendAudioToWhisper(ConvertToWav(samples, SAMPLE_RATE)));
    }

    private byte[] ConvertToWav(float[] samples, int sampleRate)
    {
        using var stream = new System.IO.MemoryStream();
        using var writer = new System.IO.BinaryWriter(stream);

        int byteCount = samples.Length * 2;
        writer.Write(Encoding.ASCII.GetBytes("RIFF"));
        writer.Write(36 + byteCount);
        writer.Write(Encoding.ASCII.GetBytes("WAVE"));
        writer.Write(Encoding.ASCII.GetBytes("fmt "));
        writer.Write(16);
        writer.Write((short)1);        // PCM
        writer.Write((short)1);        // mono
        writer.Write(sampleRate);
        writer.Write(sampleRate * 2);  // byte rate
        writer.Write((short)2);        // block align
        writer.Write((short)16);       // bit per campione
        writer.Write(Encoding.ASCII.GetBytes("data"));
        writer.Write(byteCount);

        foreach (float s in samples)
        {
            short val = (short)(Mathf.Clamp(s, -1f, 1f) * 32767f);
            writer.Write(val);
        }
        return stream.ToArray();
    }

    // ── Whisper ───────────────────────────────────────────────────────

    private IEnumerator SendAudioToWhisper(byte[] wavData)
    {
        Debug.Log($"[QuestObjectGenerator] Invio audio a Whisper ({wavData.Length / 1024} KB)...");
        string boundary = "----UnityBoundary" + DateTime.Now.Ticks;
        var bodyStream = new System.IO.MemoryStream();
        var bodyWriter = new System.IO.BinaryWriter(bodyStream);

        bodyWriter.Write(Encoding.UTF8.GetBytes($"--{boundary}\r\nContent-Disposition: form-data; name=\"file\"; filename=\"audio.wav\"\r\nContent-Type: audio/wav\r\n\r\n"));
        bodyWriter.Write(wavData);
        bodyWriter.Write(Encoding.UTF8.GetBytes($"\r\n--{boundary}\r\nContent-Disposition: form-data; name=\"model\"\r\n\r\nSystran/faster-whisper-medium\r\n"));
        bodyWriter.Write(Encoding.UTF8.GetBytes($"--{boundary}\r\nContent-Disposition: form-data; name=\"language\"\r\n\r\nit\r\n"));
        bodyWriter.Write(Encoding.UTF8.GetBytes($"--{boundary}--\r\n"));

        using var request = new UnityWebRequest($"{whisperUrl}/v1/audio/transcriptions", "POST");
        request.uploadHandler = new UploadHandlerRaw(bodyStream.ToArray());
        request.downloadHandler = new DownloadHandlerBuffer();
        request.SetRequestHeader("Content-Type", $"multipart/form-data; boundary={boundary}");
        request.timeout = 30;

        yield return request.SendWebRequest();

        if (request.result != UnityWebRequest.Result.Success)
        {
            Debug.LogError($"[QuestObjectGenerator] Whisper err: {request.error} | HTTP {request.responseCode} | {whisperUrl}");
            PlaySound(errorSound);
            yield break;
        }

        var response = JsonUtility.FromJson<WhisperResponse>(request.downloadHandler.text);
        if (response != null && !string.IsNullOrWhiteSpace(response.text))
        {
            string text = response.text.Trim();
            Debug.Log($"[QuestObjectGenerator] Whisper trascritto: {text}");
            TriggerGeneration(text);
        }
        else
        {
            Debug.LogError($"[QuestObjectGenerator] Whisper: nessun testo. Risposta: {request.downloadHandler.text}");
            PlaySound(errorSound);
        }
    }

    // ── API pubblica ──────────────────────────────────────────────────

    public void TriggerGeneration(string prompt)
    {
        if (_isGenerating || string.IsNullOrWhiteSpace(prompt)) return;
        StartCoroutine(RunPipeline(prompt));
    }

    // ── Pipeline ──────────────────────────────────────────────────────

    private IEnumerator RunPipeline(string prompt)
    {
        _isGenerating = true;
        _sessionId = Guid.NewGuid().ToString("N").Substring(0, 8);
        string glbUrl = null;

        yield return StartCoroutine(CallN8N(prompt, url => glbUrl = url));

        if (!string.IsNullOrEmpty(glbUrl))
        {
            glbUrl = RewriteToComfyHost(glbUrl);

            GameObject loadedObject = null;
            yield return StartCoroutine(LoadGLB(glbUrl, obj => loadedObject = obj));

            if (loadedObject != null)
            {
                PlaceInScene(loadedObject);
                PlaySound(successSound);
            }
            else PlaySound(errorSound);
        }
        else PlaySound(errorSound);

        _isGenerating = false;
    }

    // Sostituisce schema/host/porta del glb_url con quelli di comfyUrl (utile con adb reverse o cambi di rete)
    private string RewriteToComfyHost(string url)
    {
        if (string.IsNullOrEmpty(comfyUrl)) return url;
        try
        {
            var src = new Uri(url);
            var dest = new Uri(comfyUrl);
            var b = new UriBuilder(src) { Scheme = dest.Scheme, Host = dest.Host, Port = dest.Port };
            return b.Uri.ToString();
        }
        catch (Exception e)
        {
            Debug.LogWarning($"[QuestObjectGenerator] Impossibile riscrivere l'URL '{url}': {e.Message}");
            return url;
        }
    }

    // ── Chiamata n8n ──────────────────────────────────────────────────

    private IEnumerator CallN8N(string prompt, Action<string> callback)
    {
        // JsonUtility non serializza i tipi anonimi, quindi si usa una classe [Serializable]
        var payload = JsonUtility.ToJson(new N8NRequest { prompt = prompt, session_id = _sessionId });
        using var request = new UnityWebRequest(n8nWebhookUrl, "POST");
        request.uploadHandler = new UploadHandlerRaw(Encoding.UTF8.GetBytes(payload));
        request.downloadHandler = new DownloadHandlerBuffer();
        request.SetRequestHeader("Content-Type", "application/json");
        request.timeout = (int)timeoutSeconds;

        Debug.Log($"[QuestObjectGenerator] POST → {n8nWebhookUrl} | {payload}");
        float t0 = Time.realtimeSinceStartup;
        yield return request.SendWebRequest();
        float dt = Time.realtimeSinceStartup - t0;

        string body = request.downloadHandler?.text ?? "";
        if (request.result != UnityWebRequest.Result.Success)
        {
            Debug.LogError($"[QuestObjectGenerator] n8n errore dopo {dt:F0}s: {request.error} | HTTP {request.responseCode} | {body}");
            callback(null);
            yield break;
        }

        Debug.Log($"[QuestObjectGenerator] n8n risposta dopo {dt:F0}s: {body}");

        N8NResponse response = null;
        try { response = JsonUtility.FromJson<N8NResponse>(body); }
        catch (Exception e) { Debug.LogError($"[QuestObjectGenerator] JSON n8n non valido: {e.Message}"); }

        if (response != null && response.status == "ready" && !string.IsNullOrEmpty(response.glb_url))
            callback(response.glb_url);
        else
        {
            Debug.LogError("[QuestObjectGenerator] Risposta n8n senza glb_url valido.");
            callback(null);
        }
    }

    // ── Caricamento GLB con glTFast ───────────────────────────────────

    private IEnumerator LoadGLB(string url, Action<GameObject> callback)
    {
        Debug.Log($"[QuestObjectGenerator] Download GLB: {url}");
        using var request = UnityWebRequest.Get(url);
        request.timeout = 120;
        yield return request.SendWebRequest();

        if (request.result != UnityWebRequest.Result.Success)
        {
            Debug.LogError($"[QuestObjectGenerator] Download GLB fallito: {request.error} | HTTP {request.responseCode}");
            callback(null);
            yield break;
        }

        byte[] data = request.downloadHandler.data;
        Debug.Log($"[QuestObjectGenerator] GLB scaricato: {data.Length / 1024} KB");

        var gltf = new GltfImport();
        var loadTask = gltf.LoadGltfBinary(data, new Uri(url));
        while (!loadTask.IsCompleted) yield return null;

        if (!loadTask.Result)
        {
            Debug.LogError("[QuestObjectGenerator] glTFast: parsing del GLB fallito.");
            callback(null);
            yield break;
        }

        // Il container viene creato alla radice della scena, in (0,0,0)
        var container = new GameObject($"AR_{_sessionId}");
        var instantiateTask = gltf.InstantiateMainSceneAsync(container.transform);
        while (!instantiateTask.IsCompleted) yield return null;

        if (!instantiateTask.Result)
        {
            Debug.LogError("[QuestObjectGenerator] glTFast: istanziazione fallita.");
            Destroy(container);
            callback(null);
            yield break;
        }
        callback(container);
    }

    // ── Posizionamento nella scena ────────────────────────────────────

    private Transform GetHead()
    {
        if (headTransform != null) return headTransform;

        var origin = FindFirstObjectByType<XROrigin>();
        if (origin != null && origin.Camera != null) headTransform = origin.Camera.transform;
        else if (Camera.main != null) headTransform = Camera.main.transform;

        if (headTransform == null) Debug.LogError("[QuestObjectGenerator] Nessuna camera XR trovata!");
        return headTransform;
    }

    private void PlaceInScene(GameObject obj)
    {
        // 1) Scala (l'oggetto è ancora in (0,0,0), senza rotazione)
        AdjustScale(obj);

        // 2) Bounds dell'oggetto già scalato, in coordinate mondo
        Bounds bounds = GetWorldBounds(obj);

        // 3) Collider locale sul container
        if (obj.GetComponent<Collider>() == null && bounds.size.sqrMagnitude > 0f)
        {
            float s = Mathf.Max(obj.transform.localScale.x, 0.0001f);
            BoxCollider col = obj.AddComponent<BoxCollider>();
            col.center = obj.transform.InverseTransformPoint(bounds.center);
            col.size = bounds.size / s;
        }

        // 4) Punto di comparsa: davanti allo sguardo dell'utente (camera dentro XR Origin)
        Transform cam = GetHead();
        if (cam == null) cam = transform;

        Vector3 flatForward = Vector3.ProjectOnPlane(cam.forward, Vector3.up);
        if (flatForward.sqrMagnitude < 0.0001f) flatForward = Vector3.forward;
        flatForward.Normalize();

        Vector3 spawnPos = cam.position + flatForward * spawnDistance + Vector3.up * spawnHeightOffset;

        // 5) Rotazione: il fronte glTF punta verso -Z in Unity, quindi guardando "avanti"
        //    il fronte risulta rivolto verso l'utente
        Quaternion rot = faceUser ? Quaternion.LookRotation(flatForward, Vector3.up) : Quaternion.identity;
        obj.transform.rotation = rot;

        // 6) Posizione: il centro dei bounds finisce esattamente su spawnPos
        Vector3 centerOffset = bounds.center - obj.transform.position; // il container era in (0,0,0)
        obj.transform.position = spawnPos - rot * centerOffset;

        // 7) Materiale di fallback (Hunyuan non produce texture)
        if (fallbackMaterial != null)
            foreach (var r in obj.GetComponentsInChildren<Renderer>())
                r.sharedMaterial = fallbackMaterial;

        // 8) Fisica: l'oggetto resta esattamente dove lo lasci
        Rigidbody rb = obj.GetComponent<Rigidbody>();
        if (rb == null) rb = obj.AddComponent<Rigidbody>();
        rb.useGravity = false;
        rb.isKinematic = true;
        rb.interpolation = RigidbodyInterpolation.Interpolate;

        // 9) Afferrabile con una o due mani (o controller)
        var grab = obj.AddComponent<XRGrabInteractable>();
        grab.movementType = XRBaseInteractable.MovementType.Instantaneous;
        grab.useDynamicAttach = true;                       // lo afferri dal punto in cui lo tocchi
        grab.throwOnDetach = false;                         // rilasciato, resta fermo
        grab.selectMode = InteractableSelectMode.Multiple;  // presa a due mani

        // 10) Due mani: allontanandole scali, ruotandole ruoti
        var transformer = obj.AddComponent<XRGeneralGrabTransformer>();
        transformer.allowTwoHandedScaling = true;
        transformer.minimumScaleRatio = minScaleRatio;
        transformer.maximumScaleRatio = maxScaleRatio;

        Debug.Log($"[QuestObjectGenerator] Oggetto '{obj.name}' inserito nella scena davanti all'utente in {obj.transform.position}.");
    }

    private Bounds GetWorldBounds(GameObject obj)
    {
        var renderers = obj.GetComponentsInChildren<Renderer>();
        bool hasBounds = false;
        Bounds bounds = new Bounds(obj.transform.position, Vector3.zero);

        foreach (var r in renderers)
        {
            if (r.bounds.size.magnitude <= 0.001f) continue;
            if (!hasBounds) { bounds = r.bounds; hasBounds = true; }
            else bounds.Encapsulate(r.bounds);
        }
        return bounds;
    }

    private void AdjustScale(GameObject obj)
    {
        Bounds bounds = GetWorldBounds(obj);
        float maxDim = Mathf.Max(bounds.size.x, bounds.size.y, bounds.size.z);

        if (maxDim > 0.001f && maxDim < 100f)
            obj.transform.localScale = Vector3.one * (targetObjectSize / maxDim);
        else
            obj.transform.localScale = Vector3.one * 0.3f;
    }

    // ── Audio feedback ────────────────────────────────────────────────

    private void PlaySound(AudioClip clip)
    {
        if (clip != null && _audioSource != null) _audioSource.PlayOneShot(clip);
    }

    // ── Strutture JSON ────────────────────────────────────────────────

    [Serializable] private class WhisperResponse { public string text; }
    [Serializable] private class N8NRequest { public string prompt; public string session_id; }
    [Serializable] private class N8NResponse { public string status; public string glb_url; public string object_name; }
}