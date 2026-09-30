// ARObjectGenerator.cs
// Compatibile con: MRTK Foundation 2.x + Unity 2022.3 LTS + GLTFast
//
// SETUP:
//   1. Crea cartella Assets/Scripts nel progetto Unity
//   2. Copia questo file in Assets/Scripts/ARObjectGenerator.cs
//   3. Aggiungi il componente al GameObject MixedRealitySceneContent
//   4. Imposta N8nWebhookUrl e WhisperUrl nell'Inspector con l'IP del tuo PC
//
// DIPENDENZE (installa via Package Manager):
//   - GLTFast: com.unity.cloud.gltfast
//   - Newtonsoft Json: com.unity.nuget.newtonsoft-json
//
// SPEECH COMMANDS da aggiungere nel profilo MRTK:
//   - "create"  → avvia registrazione audio
//   - "stop"    → ferma registrazione e invia a Whisper
//   - "close"   → chiude l'app

using System;
using System.Collections;
using System.Text;
using UnityEngine;
using UnityEngine.Networking;
using GLTFast;
using Microsoft.MixedReality.Toolkit.Input;
using Microsoft.MixedReality.Toolkit;
using Microsoft.MixedReality.Toolkit.Windows.Input;

using Microsoft.MixedReality.Toolkit.UI;
using Microsoft.MixedReality.Toolkit.Input;
using Microsoft.MixedReality.Toolkit.UI.BoundsControl;

public class ARObjectGenerator : MonoBehaviour, IMixedRealitySpeechHandler
{
    // ── Configurazione ────────────────────────────────────────────────

    public string ip_address = "http://10.54.128.46";

    [Header("Configurazione n8n")]
    [Tooltip("URL webhook n8n — es. http://10.54.128.46:5678/webhook-test/hololens-generate")]
    public string n8nWebhookUrl = "http://10.54.128.46:5678/webhook-test/hololens-generate";

    [Tooltip("URL Whisper — es. http://10.54.128.46:9001")]
    public string whisperUrl = "http://10.54.128.46:9001";


    [Tooltip("Timeout totale pipeline AI in secondi")]
    public float timeoutSeconds = 700f;

    [Header("Posizionamento oggetto")]
    [Tooltip("Distanza dall'utente in metri")]
    public float placementDistance = 1.5f;

    [Tooltip("Dimensione target dell'oggetto in metri")]
    public float targetObjectSize = 0.3f;

    [Header("Feedback visivo")]
    public AudioClip successSound;
    public AudioClip errorSound;

    // ── Stato interno ─────────────────────────────────────────────────

    private bool _isGenerating = false;
    private bool _isListening = false;
    private bool _isRecording = false;
    private AudioSource _audioSource;
    private string _sessionId;

    // ── Registrazione audio ───────────────────────────────────────────

    private AudioClip _recordingClip;
    private float _recordingStartTime;
    private const int SAMPLE_RATE = 16000;
    private const int MAX_RECORDING_SECONDS = 30;

    // ── Unity lifecycle ───────────────────────────────────────────────

    void OnEnable()
    {
        CoreServices.InputSystem?.RegisterHandler<IMixedRealitySpeechHandler>(this);
    }

    void OnDisable()
    {
        CoreServices.InputSystem?.UnregisterHandler<IMixedRealitySpeechHandler>(this);
    }

    void Awake()
    {
        Debug.Log("[ARObjectGenerator] AWAKE chiamato!");
        _audioSource = gameObject.AddComponent<AudioSource>();
        _sessionId = Guid.NewGuid().ToString("N").Substring(0, 8);
    }

    void Start() { }

    void Update()
    {
#if UNITY_EDITOR
        if (Input.GetKeyDown(KeyCode.Space) && !_isGenerating)
            TriggerGeneration("una sedia medievale in legno");
#endif
    }

    // ── Keyword recognition ───────────────────────────────────────────

    public void OnSpeechKeywordRecognized(SpeechEventData eventData)
    {
        Debug.Log($"[ARObjectGenerator] Keyword ricevuta: '{eventData.Command.Keyword}'");
        switch (eventData.Command.Keyword.ToLower())
        {
            case "start":
                if (!_isListening && !_isGenerating)
                {
                    Debug.Log("[ARObjectGenerator] Comando CREA — avvio registrazione...");
                    StartRecording();
                }
                break;

            /*case "stop":
                if (_isRecording)
                {
                    Debug.Log("[ARObjectGenerator] Comando STOP — elaboro audio...");
                    StopRecordingAndSend();
                }
                break;*/

            case "close":
                Debug.Log("[ARObjectGenerator] Comando CHIUDI");
                Application.Quit();
                break;
        }
    }

    // ── Registrazione audio ───────────────────────────────────────────

    private const float SILENCE_THRESHOLD = 0.03f;  // volume sotto cui consideriamo silenzio
    private const float SILENCE_DURATION = 1.5f;     // secondi di silenzio per terminare

    private void StartRecording()
    {
        if (_isRecording) return;

        _isRecording = true;
        _isListening = true;
        _recordingStartTime = Time.time;
        _recordingClip = Microphone.Start(null, false, MAX_RECORDING_SECONDS, SAMPLE_RATE);
        Debug.Log("[ARObjectGenerator] Registrazione avviata — parla!");
        StartCoroutine(SilenceDetection());
    }

    private IEnumerator SilenceDetection()
    {
        // Aspetta un minimo prima di iniziare a monitorare il silenzio
        yield return new WaitForSeconds(1.0f);

        float silenceTimer = 0f;
        int sampleWindow = SAMPLE_RATE / 10; // 100ms di campioni
        float[] window = new float[sampleWindow];

        while (_isRecording)
        {
            int micPos = Microphone.GetPosition(null);
            if (micPos > sampleWindow)
            {
                _recordingClip.GetData(window, micPos - sampleWindow);
                float maxVol = 0f;
                foreach (float s in window)
                    maxVol = Mathf.Max(maxVol, Mathf.Abs(s));

                if (maxVol < SILENCE_THRESHOLD)
                {
                    silenceTimer += 0.1f;
                    if (silenceTimer >= SILENCE_DURATION)
                    {
                        Debug.Log("[ARObjectGenerator] Silenzio rilevato — invio audio...");
                        StopRecordingAndSend();
                        yield break;
                    }
                }
                else
                {
                    silenceTimer = 0f; // reset se c'è voce
                }
            }

            yield return new WaitForSeconds(0.1f);
        }
    }

    private void StopRecordingAndSend()
    {
        if (!_isRecording) return;

        // Ritaglia gli ultimi 0.8s per escludere la parola "stop"
        float recordedSeconds = Time.time - _recordingStartTime - 0.8f;

        if (recordedSeconds < 0.5f)
        {
            Debug.LogWarning("[ARObjectGenerator] Registrazione troppo corta, ignoro.");
            Microphone.End(null);
            _isRecording = false;
            _isListening = false;
            return;
        }

        int sampleCount = (int)(recordedSeconds * SAMPLE_RATE);
        float[] samples = new float[sampleCount];
        _recordingClip.GetData(samples, 0);

        Microphone.End(null);
        _isRecording = false;
        _isListening = false;

        Debug.Log($"[ARObjectGenerator] Registrazione terminata: {recordedSeconds:F1}s, {sampleCount} campioni");

        byte[] wavData = ConvertToWav(samples, SAMPLE_RATE);
        StartCoroutine(SendAudioToWhisper(wavData));

        // DEBUG: salva il WAV
        string debugPath = System.IO.Path.Combine(
            Application.persistentDataPath,
            "debug_audio.wav");
        System.IO.File.WriteAllBytes(debugPath, wavData);
        Debug.Log($"[ARObjectGenerator] WAV salvato in: {debugPath}");

    }

    private byte[] ConvertToWav(float[] samples, int sampleRate)
    {
        using var stream = new System.IO.MemoryStream();
        using var writer = new System.IO.BinaryWriter(stream);

        int byteCount = samples.Length * 2;

        // WAV header
        writer.Write(Encoding.ASCII.GetBytes("RIFF"));
        writer.Write(36 + byteCount);
        writer.Write(Encoding.ASCII.GetBytes("WAVE"));
        writer.Write(Encoding.ASCII.GetBytes("fmt "));
        writer.Write(16);
        writer.Write((short)1);       // PCM
        writer.Write((short)1);       // mono
        writer.Write(sampleRate);
        writer.Write(sampleRate * 2); // byte rate
        writer.Write((short)2);       // block align
        writer.Write((short)16);      // bits per sample
        writer.Write(Encoding.ASCII.GetBytes("data"));
        writer.Write(byteCount);

        // Campioni audio
        foreach (float s in samples)
        {
            short val = (short)(Mathf.Clamp(s, -1f, 1f) * 32767f);
            writer.Write(val);
        }

        return stream.ToArray();
    }

    private IEnumerator SendAudioToWhisper(byte[] wavData)
    {
        Debug.Log($"[ARObjectGenerator] Invio audio a Whisper ({wavData.Length} bytes)...");

        string boundary = "----UnityBoundary" + DateTime.Now.Ticks;
        var bodyStream = new System.IO.MemoryStream();
        var bodyWriter = new System.IO.BinaryWriter(bodyStream);

        // File field
        string fileHeader = $"--{boundary}\r\nContent-Disposition: form-data; name=\"file\"; filename=\"audio.wav\"\r\nContent-Type: audio/wav\r\n\r\n";
        bodyWriter.Write(Encoding.UTF8.GetBytes(fileHeader));
        bodyWriter.Write(wavData);

        // Model field
        string modelField = $"\r\n--{boundary}\r\nContent-Disposition: form-data; name=\"model\"\r\n\r\nSystran/faster-whisper-medium\r\n";
        bodyWriter.Write(Encoding.UTF8.GetBytes(modelField));

        // Language field
        string languageField = $"--{boundary}\r\nContent-Disposition: form-data; name=\"language\"\r\n\r\nit\r\n";
        bodyWriter.Write(Encoding.UTF8.GetBytes(languageField));

        // Close boundary
        string closeBoundary = $"--{boundary}--\r\n";
        bodyWriter.Write(Encoding.UTF8.GetBytes(closeBoundary));

        byte[] body = bodyStream.ToArray();

        using var request = new UnityWebRequest($"{whisperUrl}/v1/audio/transcriptions", "POST");
        request.uploadHandler = new UploadHandlerRaw(body);
        request.downloadHandler = new DownloadHandlerBuffer();
        request.SetRequestHeader("Content-Type", $"multipart/form-data; boundary={boundary}");
        request.timeout = 30;


        yield return request.SendWebRequest();

        if (request.result != UnityWebRequest.Result.Success)
        {
            Debug.LogError($"[ARObjectGenerator] Whisper errore: {request.error} | Code: {request.responseCode}");
            yield break;
        }

        var json = request.downloadHandler.text;
        Debug.Log($"[ARObjectGenerator] Whisper risposta: {json}");

        try
        {
            var response = JsonUtility.FromJson<WhisperResponse>(json);
            if (response != null && !string.IsNullOrEmpty(response.text))
            {
                string transcribed = response.text.Trim();
                Debug.Log($"[ARObjectGenerator] Trascritto: '{transcribed}'");
                TriggerGeneration(transcribed);
            }
            else
            {
                Debug.LogError("[ARObjectGenerator] Whisper: nessun testo trascritto.");
            }
        }
        catch (Exception e)
        {
            Debug.LogError($"[ARObjectGenerator] Whisper JSON parse fallito: {e.Message}");
        }
    }

    // ── API pubblica ──────────────────────────────────────────────────

    public void TriggerGeneration(string prompt)
    {
        Debug.Log($"[ARObjectGenerator] TriggerGeneration CHIAMATA con: {prompt}");
        if (_isGenerating)
        {
            Debug.Log("[ARObjectGenerator] Generazione già in corso.");
            return;
        }
        if (string.IsNullOrWhiteSpace(prompt))
        {
            Debug.LogWarning("[ARObjectGenerator] Prompt vuoto.");
            return;
        }
        Debug.Log($"[ARObjectGenerator] Avvio generazione: '{prompt}'");
        StartCoroutine(RunPipeline(prompt));
    }

    public void TriggerGenerationDefault()
    {
        Debug.Log("[ARObjectGenerator] TriggerGenerationDefault CHIAMATA!");
        TriggerGeneration("una sedia medievale in legno");
    }

    // ── Pipeline ──────────────────────────────────────────────────────

    private IEnumerator RunPipeline(string prompt)
    {
        _isGenerating = true;
        _sessionId = Guid.NewGuid().ToString("N").Substring(0, 8);

        Debug.Log("[ARObjectGenerator] Pipeline avviata...");

        string glbUrl = null;
        string objectName = null;
        yield return StartCoroutine(CallN8N(prompt, (url, name) =>
        {
            glbUrl = url;
            objectName = name;
        }));

        if (string.IsNullOrEmpty(glbUrl))
        {
            Debug.LogError("[ARObjectGenerator] Pipeline fallita — nessun URL ricevuto.");
            PlaySound(errorSound);
            _isGenerating = false;
            yield break;
        }

        Debug.Log($"[ARObjectGenerator] GLB URL ricevuto: {glbUrl}");

        GameObject loadedObject = null;
        yield return StartCoroutine(LoadGLB(glbUrl, obj => loadedObject = obj));

        if (loadedObject == null)
        {
            Debug.LogError("[ARObjectGenerator] Caricamento .glb fallito.");
            PlaySound(errorSound);
            _isGenerating = false;
            yield break;
        }

        PlaceObject(loadedObject);
        PlaySound(successSound);

        Debug.Log($"[ARObjectGenerator] '{objectName}' piazzato con successo!");
        _isGenerating = false;
    }

    // ── Chiamata n8n ──────────────────────────────────────────────────

    private IEnumerator CallN8N(string prompt, Action<string, string> callback)
    {
        var payload = JsonUtility.ToJson(new N8NRequest
        {
            prompt = prompt,
            session_id = _sessionId
        });

        using var request = new UnityWebRequest(n8nWebhookUrl, "POST");
        request.uploadHandler = new UploadHandlerRaw(Encoding.UTF8.GetBytes(payload));
        request.downloadHandler = new DownloadHandlerBuffer();
        request.SetRequestHeader("Content-Type", "application/json");
        request.timeout = (int)timeoutSeconds;

        Debug.Log($"[ARObjectGenerator] POST → n8n: {payload}");
        yield return request.SendWebRequest();

        if (request.result != UnityWebRequest.Result.Success)
        {
            Debug.LogError($"[ARObjectGenerator] Errore HTTP: {request.error} | Code: {request.responseCode}");
            callback(null, null);
            yield break;
        }

        var responseText = request.downloadHandler.text;
        Debug.Log($"[ARObjectGenerator] Risposta n8n: {responseText}");

        try
        {
            var response = JsonUtility.FromJson<N8NResponse>(responseText);
            if (response != null && response.status == "ready" && !string.IsNullOrEmpty(response.glb_url))
            {
                callback(response.glb_url, response.object_name ?? "oggetto");
            }
            else
            {
                Debug.LogError($"[ARObjectGenerator] Risposta non valida: {responseText}");
                callback(null, null);
            }
        }
        catch (Exception e)
        {
            Debug.LogError($"[ARObjectGenerator] JSON parse fallito: {e.Message} | Raw: {responseText}");
            callback(null, null);
        }
    }

    // ── Caricamento GLB con GLTFast ───────────────────────────────────

    private IEnumerator LoadGLB(string url, Action<GameObject> callback)
    {
        Debug.Log($"[ARObjectGenerator] Download .glb da: {url}");

        using var request = UnityWebRequest.Get(url);
        request.timeout = 30;
        yield return request.SendWebRequest();

        if (request.result != UnityWebRequest.Result.Success)
        {
            Debug.LogError($"[ARObjectGenerator] Download fallito: {request.error}");
            callback(null);
            yield break;
        }

        byte[] glbData = request.downloadHandler.data;
        Debug.Log($"[ARObjectGenerator] .glb scaricato: {glbData.Length / 1024}KB");

        var gltf = new GltfImport();
        var loadTask = gltf.LoadGltfBinary(glbData, new Uri(url));
        while (!loadTask.IsCompleted)
            yield return null;

        if (!loadTask.Result)
        {
            Debug.LogError("[ARObjectGenerator] GLTFast load fallito.");
            callback(null);
            yield break;
        }

        var container = new GameObject($"AR_{_sessionId}");
        var instantiateTask = gltf.InstantiateMainSceneAsync(container.transform);
        while (!instantiateTask.IsCompleted)
            yield return null;

        if (!instantiateTask.Result)
        {
            Debug.LogError("[ARObjectGenerator] GLTFast instantiate fallito.");
            Destroy(container);
            callback(null);
            yield break;
        }

        callback(container);
    }

    // ── Posizionamento ────────────────────────────────────────────────

    private Bounds GetObjectBounds(GameObject obj)
    {
        Bounds bounds = new Bounds(obj.transform.position, Vector3.zero);
        foreach (Renderer r in obj.GetComponentsInChildren<Renderer>())
            bounds.Encapsulate(r.bounds);
        return bounds;
    }

    private void PlaceObject(GameObject obj)
    {
        Camera cam = Camera.main;
        if (cam == null)
        {
            obj.transform.position = Vector3.forward * placementDistance;
            return;
        }

        Vector3 origin = cam.transform.position;
        Vector3 direction = cam.transform.forward;

        if (Physics.Raycast(origin, direction, out RaycastHit hit, placementDistance * 2f))
        {
            obj.transform.position = hit.point;
            Vector3 lookDir = origin - obj.transform.position;
            lookDir.y = 0;
            if (lookDir != Vector3.zero)
                obj.transform.rotation = Quaternion.LookRotation(lookDir);
        }
        else
        {
            obj.transform.position = origin + direction * placementDistance;
            obj.transform.LookAt(cam.transform);
            obj.transform.Rotate(0, 180f, 0);
        }

        NormalizeScale(obj);
        ApplyDefaultMaterial(obj);

        Debug.Log($"[ARObjectGenerator] Posizione: {obj.transform.position}");

        // Collider per l'interazione
        if (obj.GetComponent<Collider>() == null)
        {
            BoxCollider col = obj.AddComponent<BoxCollider>();
            Bounds meshBounds = GetObjectBounds(obj);
            col.center = meshBounds.center - obj.transform.position;
            col.size = meshBounds.size;
        }

        // Layer su Default per oggetto e tutti i figli
        obj.layer = LayerMask.NameToLayer("Default");
        foreach (Transform child in obj.GetComponentsInChildren<Transform>())
            child.gameObject.layer = LayerMask.NameToLayer("Default");

        // Manipolazione manuale MRTK
        obj.AddComponent<ObjectManipulator>();
        obj.AddComponent<NearInteractionGrabbable>();
        obj.AddComponent<NearInteractionTouchableVolume>();
        obj.AddComponent<BoundsControl>();

    }

    private void NormalizeScale(GameObject obj)
    {
        var renderers = obj.GetComponentsInChildren<Renderer>();
        if (renderers.Length == 0) return;

        Bounds bounds = renderers[0].bounds;
        foreach (var r in renderers)
            bounds.Encapsulate(r.bounds);

        float maxDim = Mathf.Max(bounds.size.x, bounds.size.y, bounds.size.z);
        if (maxDim > 0.001f)
            obj.transform.localScale = Vector3.one * (targetObjectSize / maxDim);
    }

    private void ApplyDefaultMaterial(GameObject obj)
    {
        Material defaultMat = new Material(Shader.Find("Standard"));
        defaultMat.color = new Color(0.8f, 0.8f, 0.8f, 1f);
        defaultMat.SetFloat("_Metallic", 0f);
        defaultMat.SetFloat("_Glossiness", 0.3f);

        var renderers = obj.GetComponentsInChildren<Renderer>();
        foreach (var r in renderers)
        {
            var mats = r.materials;
            for (int i = 0; i < mats.Length; i++)
            {
                if (mats[i] == null || mats[i].name.Contains("Default-Material")
                    || mats[i].shader.name == "Hidden/InternalErrorShader")
                {
                    mats[i] = defaultMat;
                }
            }
            r.materials = mats;
        }
    }

    // ── Audio feedback ────────────────────────────────────────────────

    private void PlaySound(AudioClip clip)
    {
        if (clip != null && _audioSource != null)
            _audioSource.PlayOneShot(clip);
    }

    // ── Strutture JSON ────────────────────────────────────────────────

    [Serializable]
    private class N8NRequest
    {
        public string prompt;
        public string session_id;
    }

    [Serializable]
    private class N8NResponse
    {
        public string status;
        public string glb_url;
        public string object_name;
        public string session_id;
    }

    [Serializable]
    private class WhisperResponse
    {
        public string text;
    }
}
