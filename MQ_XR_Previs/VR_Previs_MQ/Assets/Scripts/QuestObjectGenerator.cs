using System;
using System.Collections;
using System.Text;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.Android;
using UnityEngine.InputSystem;
using UnityEngine.XR.Interaction.Toolkit;
using GLTFast;

#if UNITY_EDITOR
using UnityEditor;
#endif

// Compatibile con: Meta Quest Pro + XR Interaction Toolkit + GLTFast + OpenXR
public class QuestObjectGenerator : MonoBehaviour
{
    // ── Configurazione ────────────────────────────────────────────────

    [Header("Input Controller")]
    [Tooltip("Tasto per avviare la registrazione vocale (es. XRI RightHand/Primary Button - Tasto A)")]
    public InputActionReference recordButton;

    [Tooltip("Tasto per posizionare/fissare l'oggetto nel mondo (es. XRI RightHand/Trigger o Secondary Button - Tasto B)")]
    public InputActionReference placeButton;

    [Header("Riferimenti XR")]
    [Tooltip("Trascina qui il controller sinistro (es. XR Origin -> Camera Offset -> Left Controller)")]
    public Transform leftHandTransform;

    [Header("Configurazione n8n e Whisper")]
    public string n8nWebhookUrl = "http://10.54.15.50:5678/webhook-test/hololens-generate";
    public string whisperUrl = "http://10.54.15.50:9001";
    public float timeoutSeconds = 700f;

    [Header("Dimensioni e Posizionamento")]
    public float targetObjectSize = 0.3f;
    public Vector3 handOffset = new Vector3(0, 0.05f, 0.1f); // Distanza dal palmo della mano

    [Header("Feedback Visivo / Sonoro")]
    public AudioClip successSound;
    public AudioClip errorSound;
    public AudioClip recordingStartSound;
    public AudioClip placeSound;

    // ── Stato interno ─────────────────────────────────────────────────

    private bool _isGenerating = false;
    private bool _isRecording = false;
    private AudioSource _audioSource;
    private string _sessionId;

    private GameObject _currentlyHeldObject;
    private bool _isObjectAttachedToHand = false;

    // ── Registrazione audio ───────────────────────────────────────────

    private AudioClip _recordingClip;
    private float _recordingStartTime;
    private const int SAMPLE_RATE = 16000;
    private const int MAX_RECORDING_SECONDS = 30;
    private const float SILENCE_THRESHOLD = 0.03f;
    private const float SILENCE_DURATION = 1.5f;

    // ── Unity lifecycle ───────────────────────────────────────────────

    void Awake()
    {
        _audioSource = gameObject.AddComponent<AudioSource>();
        _sessionId = Guid.NewGuid().ToString("N").Substring(0, 8);

        // Se la mano sinistra non è assegnata nell'Inspector, tenta il recupero automatico
        if (leftHandTransform == null)
        {
            GameObject leftHand = GameObject.Find("Left Controller") ?? GameObject.Find("LeftHand Direct Interactor");
            if (leftHand != null) leftHandTransform = leftHand.transform;
            else Debug.LogWarning("[QuestObjectGenerator] LeftHandTransform non assegnata nell'Inspector!");
        }

#if UNITY_ANDROID
        if (!Permission.HasUserAuthorizedPermission(Permission.Microphone))
        {
            Permission.RequestUserPermission(Permission.Microphone);
        }
#endif
    }

    void OnEnable()
    {
        if (recordButton != null && recordButton.action != null)
        {
            recordButton.action.Enable();
            recordButton.action.started += OnRecordButtonPressed;
        }

        if (placeButton != null && placeButton.action != null)
        {
            placeButton.action.Enable();
            placeButton.action.started += OnPlaceButtonPressed;
        }
    }

    void OnDisable()
    {
        if (recordButton != null && recordButton.action != null)
        {
            recordButton.action.started -= OnRecordButtonPressed;
            recordButton.action.Disable();
        }

        if (placeButton != null && placeButton.action != null)
        {
            placeButton.action.started -= OnPlaceButtonPressed;
            placeButton.action.Disable();
        }
    }

    void Update()
    {
#if UNITY_EDITOR
        // Test veloci nell'Editor tramite tastiera
        if (Input.GetKeyDown(KeyCode.Space) && !_isGenerating)
            TriggerGeneration("un vaso di ceramica decorato");

        if (Input.GetKeyDown(KeyCode.P) && _isObjectAttachedToHand)
            DetachAndPlaceObject();
#endif
    }

    // ── Gestione Input Controller ─────────────────────────────────────

    private void OnRecordButtonPressed(InputAction.CallbackContext context)
    {
        if (_isGenerating) return;

        if (!_isRecording)
        {
            StartRecording();
        }
        else
        {
            StopRecordingAndSend();
        }
    }

    private void OnPlaceButtonPressed(InputAction.CallbackContext context)
    {
        if (_isObjectAttachedToHand)
        {
            DetachAndPlaceObject();
        }
    }

    // ── Registrazione audio ───────────────────────────────────────────

    private void StartRecording()
    {
        if (_isRecording) return;
        
#if UNITY_ANDROID
        if (!Permission.HasUserAuthorizedPermission(Permission.Microphone))
        {
            Debug.LogWarning("[QuestObjectGenerator] Permesso microfono mancante!");
            return;
        }
#endif

        _isRecording = true;
        _recordingStartTime = Time.time;
        
        string micDevice = Microphone.devices.Length > 0 ? Microphone.devices[0] : null;
        _recordingClip = Microphone.Start(micDevice, false, MAX_RECORDING_SECONDS, SAMPLE_RATE);
        
        PlaySound(recordingStartSound);
        Debug.Log($"[QuestObjectGenerator] Registrazione avviata su: {micDevice}");
        
        StartCoroutine(SilenceDetection());
    }

    private IEnumerator SilenceDetection()
    {
        yield return new WaitForSeconds(1.0f);

        float silenceTimer = 0f;
        int sampleWindow = SAMPLE_RATE / 10;
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
                        Debug.Log("[QuestObjectGenerator] Silenzio rilevato — invio audio...");
                        StopRecordingAndSend();
                        yield break;
                    }
                }
                else
                {
                    silenceTimer = 0f;
                }
            }
            yield return new WaitForSeconds(0.1f);
        }
    }

    private void StopRecordingAndSend()
    {
        if (!_isRecording) return;

        float recordedSeconds = Time.time - _recordingStartTime;

        if (recordedSeconds < 0.5f)
        {
            Microphone.End(null);
            _isRecording = false;
            return;
        }

        int sampleCount = (int)(recordedSeconds * SAMPLE_RATE);
        float[] samples = new float[sampleCount];
        _recordingClip.GetData(samples, 0);

        Microphone.End(null);
        _isRecording = false;

        byte[] wavData = ConvertToWav(samples, SAMPLE_RATE);
        StartCoroutine(SendAudioToWhisper(wavData));
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
        writer.Write((short)1);
        writer.Write((short)1);
        writer.Write(sampleRate);
        writer.Write(sampleRate * 2);
        writer.Write((short)2);
        writer.Write((short)16);
        writer.Write(Encoding.ASCII.GetBytes("data"));
        writer.Write(byteCount);

        foreach (float s in samples)
        {
            short val = (short)(Mathf.Clamp(s, -1f, 1f) * 32767f);
            writer.Write(val);
        }
        return stream.ToArray();
    }

    private IEnumerator SendAudioToWhisper(byte[] wavData)
    {
        Debug.Log("[QuestObjectGenerator] Invio audio a Whisper...");
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
        
        yield return request.SendWebRequest();

        if (request.result == UnityWebRequest.Result.Success)
        {
            var response = JsonUtility.FromJson<WhisperResponse>(request.downloadHandler.text);
            if (response != null && !string.IsNullOrEmpty(response.text))
            {
                Debug.Log($"[QuestObjectGenerator] Whisper trascritto: {response.text.Trim()}");
                TriggerGeneration(response.text.Trim());
            }
        }
        else Debug.LogError($"[QuestObjectGenerator] Whisper err: {request.error}");
    }

    public void TriggerGeneration(string prompt)
    {
        if (_isGenerating || string.IsNullOrWhiteSpace(prompt)) return;
        StartCoroutine(RunPipeline(prompt));
    }

    private IEnumerator RunPipeline(string prompt)
    {
        _isGenerating = true;
        _sessionId = Guid.NewGuid().ToString("N").Substring(0, 8);
        string glbUrl = null;

        yield return StartCoroutine(CallN8N(prompt, url => glbUrl = url));

        if (!string.IsNullOrEmpty(glbUrl))
        {
            GameObject loadedObject = null;
            yield return StartCoroutine(LoadGLB(glbUrl, obj => loadedObject = obj));
            
            if (loadedObject != null)
            {
                AttachToLeftHand(loadedObject);
                PlaySound(successSound);
            }
            else PlaySound(errorSound);
        }
        else PlaySound(errorSound);

        _isGenerating = false;
    }

    private IEnumerator CallN8N(string prompt, Action<string> callback)
    {
        var payload = JsonUtility.ToJson(new { prompt = prompt, session_id = _sessionId });
        using var request = new UnityWebRequest(n8nWebhookUrl, "POST");
        request.uploadHandler = new UploadHandlerRaw(Encoding.UTF8.GetBytes(payload));
        request.downloadHandler = new DownloadHandlerBuffer();
        request.SetRequestHeader("Content-Type", "application/json");
        request.timeout = (int)timeoutSeconds;

        yield return request.SendWebRequest();

        if (request.result == UnityWebRequest.Result.Success)
        {
            var response = JsonUtility.FromJson<N8NResponse>(request.downloadHandler.text);
            if (response != null && response.status == "ready") callback(response.glb_url);
            else callback(null);
        }
        else callback(null);
    }

    private IEnumerator LoadGLB(string url, Action<GameObject> callback)
    {
        using var request = UnityWebRequest.Get(url);
        request.timeout = 120;
        yield return request.SendWebRequest();

        if (request.result != UnityWebRequest.Result.Success)
        {
            callback(null);
            yield break;
        }

        var gltf = new GltfImport();
        var loadTask = gltf.LoadGltfBinary(request.downloadHandler.data, new Uri(url));
        while (!loadTask.IsCompleted) yield return null;

        if (loadTask.Result)
        {
            var container = new GameObject($"AR_{_sessionId}");
            var instantiateTask = gltf.InstantiateMainSceneAsync(container.transform);
            while (!instantiateTask.IsCompleted) yield return null;
            callback(instantiateTask.Result ? container : null);
        }
        else callback(null);
    }

    // ── AGGANCIO ALLA MANO SINISTRA ───────────────────────────────────

    private void AttachToLeftHand(GameObject obj)
    {
        _currentlyHeldObject = obj;
        _isObjectAttachedToHand = true;

        Transform parentTarget = leftHandTransform != null ? leftHandTransform : Camera.main.transform;

        // Imparenta l'oggetto alla mano sinistra
        obj.transform.SetParent(parentTarget, false);
        obj.transform.localPosition = handOffset;
        obj.transform.localRotation = Quaternion.identity;

        // Calcolo scala corretta
        AdjustScale(obj);

        // Prepara Rigidbody per seguire la mano in modo fluido
        Rigidbody rb = obj.GetComponent<Rigidbody>();
        if (rb == null) rb = obj.AddComponent<Rigidbody>();
        rb.isKinematic = true;
        rb.useGravity = false;

        Debug.Log("[QuestObjectGenerator] Oggetto agganciato alla mano sinistra! Muovi la mano per posizionarlo e premi il tasto di posizionamento per fissarlo.");
    }

    private void DetachAndPlaceObject()
    {
        if (_currentlyHeldObject == null) return;

        // Sgancia dalla mano e lascia l'oggetto nel punto esatto dello spazio 3D
        _currentlyHeldObject.transform.SetParent(null, true);
        _isObjectAttachedToHand = false;

        // Configura la fisica senza gravità
        Rigidbody rb = _currentlyHeldObject.GetComponent<Rigidbody>();
        if (rb != null)
        {
            rb.isKinematic = false;
            rb.useGravity = false;
            rb.linearDamping = 5f;
            rb.angularDamping = 2f;
        }

        // Aggiungi Collider per l'interazione
        Renderer[] renderers = _currentlyHeldObject.GetComponentsInChildren<Renderer>();
        if (_currentlyHeldObject.GetComponent<Collider>() == null && renderers.Length > 0)
        {
            BoxCollider col = _currentlyHeldObject.AddComponent<BoxCollider>();
            Bounds meshBounds = new Bounds(_currentlyHeldObject.transform.position, Vector3.zero);
            foreach (Renderer r in renderers) meshBounds.Encapsulate(r.bounds);
            col.center = meshBounds.center - _currentlyHeldObject.transform.position;
            col.size = meshBounds.size;
        }

        // Aggiungi il componente XR per poterlo afferrare e riposizionare in seguito
        var grabInteractable = _currentlyHeldObject.GetComponent<UnityEngine.XR.Interaction.Toolkit.Interactables.XRGrabInteractable>();
        if (grabInteractable == null)
            grabInteractable = _currentlyHeldObject.AddComponent<UnityEngine.XR.Interaction.Toolkit.Interactables.XRGrabInteractable>();
        
        grabInteractable.useDynamicAttach = true;

        PlaySound(placeSound);
        Debug.Log("[QuestObjectGenerator] Oggetto posizionato e fissato nel mondo!");
        _currentlyHeldObject = null;
    }

    private void AdjustScale(GameObject obj)
    {
        var renderers = obj.GetComponentsInChildren<Renderer>();
        if (renderers.Length > 0)
        {
            Bounds bounds = renderers[0].bounds;
            bool hasValidBounds = false;

            foreach (var r in renderers)
            {
                if (r.bounds.size.magnitude > 0.001f)
                {
                    if (!hasValidBounds)
                    {
                        bounds = r.bounds;
                        hasValidBounds = true;
                    }
                    else bounds.Encapsulate(r.bounds);
                }
            }

            if (hasValidBounds)
            {
                float maxDim = Mathf.Max(bounds.size.x, bounds.size.y, bounds.size.z);
                if (maxDim > 0.001f && maxDim < 100f)
                {
                    obj.transform.localScale = Vector3.one * (targetObjectSize / maxDim);
                }
                else
                {
                    obj.transform.localScale = Vector3.one * 0.3f;
                }
            }
        }
    }

    private void PlaySound(AudioClip clip)
    {
        if (clip != null && _audioSource != null) _audioSource.PlayOneShot(clip);
    }

    [Serializable] private class WhisperResponse { public string text; }
    [Serializable] private class N8NResponse { public string status; public string glb_url; }
}