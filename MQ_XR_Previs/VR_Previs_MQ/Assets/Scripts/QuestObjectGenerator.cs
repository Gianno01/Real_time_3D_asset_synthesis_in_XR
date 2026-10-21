// QuestObjectGenerator.cs
// Compatibile con: Unity 6 + Meta Quest Pro + OpenXR + XR Interaction Toolkit 3.x + AR Foundation + glTFast
//
// Pipeline: voce → Whisper (STT) → n8n (LLM + ComfyUI) → download .glb → glTFast
//           → oggetto davanti all'utente, afferrabile/ruotabile/scalabile con mani o controller.
//
// Due modi per avviare una richiesta:
//   1) MANI LIBERE (handsFreeMode): l'app ascolta sempre; ogni frase viene trascritta e,
//      se inizia con una parola di attivazione ("genera", "crea"...), il resto della frase è la richiesta.
//      Es. "Genera una sedia di legno". Dicendo solo "Genera" l'app aspetta l'oggetto nella frase successiva.
//   2) PULSANTE (recordButton): premi per registrare, la registrazione si chiude dopo una pausa.
//
// Espone uno stato pubblico (State, StateChanged, tempi, stima, MicLevel, IsListening) letto da GenerationStatusUI.

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

public enum PipelineState { Idle, Recording, Transcribing, Generating, Downloading, Loading, Done, Error }

public class QuestObjectGenerator : MonoBehaviour
{
    // ── Configurazione ────────────────────────────────────────────────

    [Header("Input Controller")]
    [Tooltip("Azione per avviare/fermare la registrazione vocale (funziona anche in modalità mani libere)")]
    public InputActionReference recordButton;

    [Header("Mani libere (parola di attivazione)")]
    [Tooltip("Ascolto continuo: le frasi che iniziano con una parola di attivazione avviano la generazione")]
    public bool handsFreeMode = true;
    [Tooltip("Parole di attivazione (minuscolo). Vale anche l'inizio della parola: 'genera' riconosce 'generami'")]
    public string[] wakeWords = { "genera", "crea" };
    [Tooltip("Volume minimo per considerare che stai parlando (0–1)")]
    public float voiceThreshold = 0.04f;
    [Tooltip("Pausa (s) che chiude una frase in ascolto continuo")]
    public float utteranceSilence = 1.0f;
    [Tooltip("Secondi di attesa dell'oggetto dopo aver detto solo la parola di attivazione")]
    public float awaitCommandSeconds = 8f;

    [Header("Configurazione rete")]
    [Tooltip("Webhook di PRODUZIONE n8n (/webhook/, non /webhook-test/)")]
    public string n8nWebhookUrl = "http://127.0.0.1:5678/webhook/quest-generate";
    public string whisperUrl = "http://127.0.0.1:9010";
    [Tooltip("Frase di esempio passata a Whisper: migliora il riconoscimento della parola di attivazione")]
    public string whisperPrompt = "Genera una sedia di legno. Genera un vaso di ceramica. Crea una lampada da tavolo.";
    [Tooltip("Indirizzo di ComfyUI come lo vede il VISORE (con adb reverse: http://127.0.0.1:8188). Vuoto = usa il glb_url così com'è")]
    public string comfyUrl = "http://127.0.0.1:8188";
    public float timeoutSeconds = 700f;

    [Header("Riferimenti XR")]
    [Tooltip("Main Camera dentro XR Origin (opzionale: se vuoto la cerca da solo)")]
    public Transform headTransform;

    [Header("Dimensioni e Posizionamento")]
    public float targetObjectSize = 0.3f;
    public float spawnDistance = 0.8f;
    public float spawnHeightOffset = -0.2f;
    public bool faceUser = true;

    [Header("Manipolazione")]
    public float minScaleRatio = 0.25f;
    public float maxScaleRatio = 5f;

    [Header("Materiali")]
    [Tooltip("Materiale URP/Lit applicato ai modelli senza texture (Hunyuan). Vuoto per modelli texturizzati (Meshy)")]
    public Material fallbackMaterial;

    [Header("Feedback Sonoro")]
    public AudioClip successSound;
    public AudioClip errorSound;
    public AudioClip recordingStartSound;

    // ── Stato pubblico (letto dalla UI) ───────────────────────────────

    public event Action<PipelineState, string> StateChanged;

    public PipelineState State { get; private set; } = PipelineState.Idle;
    public float StateStartTime { get; private set; }
    public string LastTranscript { get; private set; } = "";
    public string LastObjectName { get; private set; } = "";
    /// <summary>Volume istantaneo del microfono (0–1), sia in ascolto continuo sia in registrazione.</summary>
    public float MicLevel { get; private set; }
    /// <summary>True quando l'app è in ascolto continuo della parola di attivazione.</summary>
    public bool IsListening { get; private set; }
    public float EstimatedGenerationSeconds => PlayerPrefs.GetFloat(PREF_AVG_GEN, 0f);
    public Transform Head => GetHead();

    // ── Stato interno ─────────────────────────────────────────────────

    private const string PREF_AVG_GEN = "qog_avg_generation_seconds";

    private bool _isGenerating = false;
    private bool _isRecording = false;
    private bool _awaitingCommand = false;
    private AudioSource _audioSource;
    private string _sessionId;
    private float _sttSeconds, _genSeconds, _dlSeconds, _loadSeconds;

    // ── Audio ─────────────────────────────────────────────────────────

    private AudioClip _recordingClip;   // registrazione con pulsante (non in loop)
    private AudioClip _listenClip;      // ascolto continuo (buffer circolare)
    private Coroutine _listenRoutine;
    private string _micDevice;
    private const int SAMPLE_RATE = 16000;
    private const int MAX_RECORDING_SECONDS = 30;
    private const int LISTEN_BUFFER_SECONDS = 20;
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

    void Start()
    {
        if (handsFreeMode) StartListening();
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
        StopListening();
    }

    void Update()
    {
#if UNITY_EDITOR
        if (Keyboard.current != null && Keyboard.current.spaceKey.wasPressedThisFrame && !_isGenerating)
            TriggerGeneration("un vaso di ceramica decorato");
#endif
    }

    // ── Stato ─────────────────────────────────────────────────────────

    private void SetState(PipelineState state, string detail = "")
    {
        State = state;
        StateStartTime = Time.realtimeSinceStartup;
        Debug.Log($"[QuestObjectGenerator] Stato → {state} {detail}");
        StateChanged?.Invoke(state, detail);
    }

    private void Fail(string message)
    {
        Debug.LogError($"[QuestObjectGenerator] {message}");
        PlaySound(errorSound);
        _isGenerating = false;
        _awaitingCommand = false;
        SetState(PipelineState.Error, message);
        if (handsFreeMode) StartListening();
    }

    private void UpdateEstimate(float seconds)
    {
        float avg = PlayerPrefs.GetFloat(PREF_AVG_GEN, 0f);
        avg = avg <= 0f ? seconds : avg * 0.7f + seconds * 0.3f;
        PlayerPrefs.SetFloat(PREF_AVG_GEN, avg);
        PlayerPrefs.Save();
    }

    public static string FormatTime(float seconds)
    {
        int s = Mathf.Max(0, Mathf.RoundToInt(seconds));
        return $"{s / 60}:{s % 60:00}";
    }

    // ── Pulsante ──────────────────────────────────────────────────────

    private void OnRecordButtonPressed(InputAction.CallbackContext context)
    {
        if (_isGenerating || State == PipelineState.Transcribing) return;
        if (GenerationStatusUI.IsPointerOverUI) return;   // il grilletto sta premendo un pulsante della UI

        if (!_isRecording)
        {
            _awaitingCommand = false;
            StopListening();      // il pulsante ha la precedenza sull'ascolto continuo
            StartRecording();
        }
        else StopRecordingAndSend();
    }

    // ── Ascolto continuo (mani libere) ────────────────────────────────

    private void StartListening()
    {
        if (!handsFreeMode || IsListening || _isGenerating || _isRecording) return;
        IsListening = true;
        _listenRoutine = StartCoroutine(ListenLoop());
    }

    private void StopListening()
    {
        if (!IsListening) return;
        IsListening = false;
        if (_listenRoutine != null) StopCoroutine(_listenRoutine);
        _listenRoutine = null;
        if (Microphone.IsRecording(_micDevice)) Microphone.End(_micDevice);
        MicLevel = 0f;
    }

    private IEnumerator ListenLoop()
    {
#if UNITY_ANDROID && !UNITY_EDITOR
        while (!Permission.HasUserAuthorizedPermission(Permission.Microphone))
            yield return new WaitForSeconds(0.5f);
#endif
        _micDevice = Microphone.devices.Length > 0 ? Microphone.devices[0] : null;
        _listenClip = Microphone.Start(_micDevice, true, LISTEN_BUFFER_SECONDS, SAMPLE_RATE);
        while (Microphone.GetPosition(_micDevice) <= 0) yield return null;
        Debug.Log("[QuestObjectGenerator] Ascolto continuo attivo: di' \"" + string.Join("\" o \"", wakeWords) + "\" seguito dall'oggetto");

        int total = _listenClip.samples;
        int window = SAMPLE_RATE / 10;       // 100 ms
        int preRoll = SAMPLE_RATE * 3 / 10;  // 300 ms prima dell'inizio della voce
        float[] buf = new float[window];
        var wait = new WaitForSeconds(0.1f);

        bool inSpeech = false;
        int speechStart = 0;
        float silence = 0f, speechTime = 0f;

        while (IsListening)
        {
            int pos = Microphone.GetPosition(_micDevice);
            int start = pos - window;
            if (start < 0) start += total;
            _listenClip.GetData(buf, start); // per clip in loop la lettura si avvolge da sola

            float max = 0f;
            foreach (float s in buf) max = Mathf.Max(max, Mathf.Abs(s));
            MicLevel = max;

            if (!inSpeech)
            {
                if (max >= voiceThreshold)
                {
                    inSpeech = true;
                    speechStart = pos - window - preRoll;
                    if (speechStart < 0) speechStart += total;
                    silence = 0f;
                    speechTime = 0f;
                }
            }
            else
            {
                speechTime += 0.1f;
                silence = max < SILENCE_THRESHOLD ? silence + 0.1f : 0f;

                if (silence >= utteranceSilence || speechTime >= LISTEN_BUFFER_SECONDS - 2)
                {
                    inSpeech = false;
                    int len = pos - speechStart;
                    if (len < 0) len += total;

                    if (len >= SAMPLE_RATE * 6 / 10) // ignora rumori brevi (< 0,6 s)
                    {
                        float[] samples = new float[len];
                        _listenClip.GetData(samples, speechStart);
                        yield return StartCoroutine(HandleUtterance(samples));
                    }
                }
            }
            yield return wait;
        }
    }

    // Una frase ascoltata in modalità mani libere: la trascrive e cerca la parola di attivazione
    private IEnumerator HandleUtterance(float[] samples)
    {
        string text = null, error = null;
        yield return StartCoroutine(Transcribe(ConvertToWav(samples, SAMPLE_RATE), (t, e) => { text = t; error = e; }));

        if (text == null)
        {
            Debug.LogWarning($"[QuestObjectGenerator] Ascolto: trascrizione fallita ({error})");
            yield break; // in ascolto continuo non disturbiamo l'utente con errori
        }

        Debug.Log($"[QuestObjectGenerator] Sentito: \"{text}\"");

        if (_awaitingCommand)
        {
            _awaitingCommand = false;
            string cmd = CleanCommand(text);
            if (TryExtractCommand(text, out string again) && !string.IsNullOrEmpty(again)) cmd = again;
            if (cmd.Length < 2) { Fail("Non ho capito l'oggetto: riprova"); yield break; }
            StopListening();
            TriggerGeneration(cmd);
            yield break;
        }

        if (!TryExtractCommand(text, out string command)) yield break; // frase normale: ignorata

        if (string.IsNullOrEmpty(command))
        {
            // Ha detto solo "genera": aspetta l'oggetto nella prossima frase
            _awaitingCommand = true;
            PlaySound(recordingStartSound);
            SetState(PipelineState.Recording, "Dimmi quale oggetto vuoi generare");
            StartCoroutine(AwaitCommandTimeout());
            yield break;
        }

        StopListening();
        TriggerGeneration(command);
    }

    private IEnumerator AwaitCommandTimeout()
    {
        float t0 = Time.realtimeSinceStartup;
        while (_awaitingCommand && Time.realtimeSinceStartup - t0 < awaitCommandSeconds) yield return null;
        if (_awaitingCommand)
        {
            _awaitingCommand = false;
            SetState(PipelineState.Idle);
        }
    }

    // "Ok, genera una sedia di legno." → true, command = "una sedia di legno"
    private bool TryExtractCommand(string text, out string command)
    {
        command = null;
        if (string.IsNullOrWhiteSpace(text)) return false;

        var words = text.Split(new[] { ' ', '\t', ',', '.', '!', '?', ';', ':', '"', '«', '»' },
                               StringSplitOptions.RemoveEmptyEntries);

        // la parola di attivazione può trovarsi tra le prime 3 parole ("ok genera...", "allora crea...")
        for (int i = 0; i < Mathf.Min(words.Length, 3); i++)
        {
            string w = words[i].ToLowerInvariant();
            foreach (var wake in wakeWords)
            {
                if (string.IsNullOrEmpty(wake) || !w.StartsWith(wake.ToLowerInvariant())) continue;
                command = string.Join(" ", words, i + 1, words.Length - i - 1).Trim();
                return true;
            }
        }
        return false;
    }

    private static string CleanCommand(string text) => text.Trim().Trim('.', '!', '?', ',', ' ');

    // ── Registrazione con pulsante ────────────────────────────────────

    private void StartRecording()
    {
        if (_isRecording) return;

#if UNITY_ANDROID && !UNITY_EDITOR
        if (!Permission.HasUserAuthorizedPermission(Permission.Microphone))
        {
            Permission.RequestUserPermission(Permission.Microphone);
            Fail("Permesso microfono mancante");
            return;
        }
#endif

        _micDevice = Microphone.devices.Length > 0 ? Microphone.devices[0] : null;
        _recordingClip = Microphone.Start(_micDevice, false, MAX_RECORDING_SECONDS, SAMPLE_RATE);
        _isRecording = true;
        MicLevel = 0f;

        PlaySound(recordingStartSound);
        SetState(PipelineState.Recording, "Parla ora: l'invio parte dopo 1,5 s di silenzio");

        StartCoroutine(SilenceDetection());
    }

    private IEnumerator SilenceDetection()
    {
        yield return new WaitForSeconds(1.0f);

        float silenceTimer = 0f;
        int sampleWindow = SAMPLE_RATE / 10;
        float[] window = new float[sampleWindow];
        var wait = new WaitForSeconds(0.1f);

        while (_isRecording)
        {
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
                MicLevel = maxVol;

                silenceTimer = maxVol < SILENCE_THRESHOLD ? silenceTimer + 0.1f : 0f;
                if (silenceTimer >= SILENCE_DURATION)
                {
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
        int sampleCount = micPos > 0 ? micPos : _recordingClip.samples;
        Microphone.End(_micDevice);
        _isRecording = false;
        MicLevel = 0f;

        if (sampleCount < SAMPLE_RATE / 2)
        {
            Fail("Registrazione troppo corta: riprova");
            return;
        }

        float[] samples = new float[sampleCount];
        _recordingClip.GetData(samples, 0);

        float seconds = sampleCount / (float)SAMPLE_RATE;
        SetState(PipelineState.Transcribing, $"{seconds:F1} s di audio inviati a Whisper");
        StartCoroutine(TranscribeAndGenerate(ConvertToWav(samples, SAMPLE_RATE)));
    }

    private IEnumerator TranscribeAndGenerate(byte[] wav)
    {
        string text = null, error = null;
        yield return StartCoroutine(Transcribe(wav, (t, e) => { text = t; error = e; }));

        if (text == null) { Fail(error); yield break; }

        // Se l'utente ha detto comunque "genera ...", togli la parola di attivazione
        string prompt = TryExtractCommand(text, out string cmd) && !string.IsNullOrEmpty(cmd) ? cmd : CleanCommand(text);
        if (prompt.Length < 2) { Fail("Non ho capito: riprova"); yield break; }

        TriggerGeneration(prompt);
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
            writer.Write((short)(Mathf.Clamp(s, -1f, 1f) * 32767f));

        return stream.ToArray();
    }

    // ── Whisper ───────────────────────────────────────────────────────

    // callback(testo, errore): testo != null se la trascrizione è riuscita
    private IEnumerator Transcribe(byte[] wavData, Action<string, string> callback)
    {
        string boundary = "----UnityBoundary" + DateTime.Now.Ticks;
        var bodyStream = new System.IO.MemoryStream();
        var bodyWriter = new System.IO.BinaryWriter(bodyStream);

        void Field(string name, string value) =>
            bodyWriter.Write(Encoding.UTF8.GetBytes($"--{boundary}\r\nContent-Disposition: form-data; name=\"{name}\"\r\n\r\n{value}\r\n"));

        bodyWriter.Write(Encoding.UTF8.GetBytes($"--{boundary}\r\nContent-Disposition: form-data; name=\"file\"; filename=\"audio.wav\"\r\nContent-Type: audio/wav\r\n\r\n"));
        bodyWriter.Write(wavData);
        bodyWriter.Write(Encoding.UTF8.GetBytes("\r\n"));
        Field("model", "Systran/faster-whisper-medium");
        Field("language", "it");
        if (!string.IsNullOrEmpty(whisperPrompt)) Field("prompt", whisperPrompt);
        bodyWriter.Write(Encoding.UTF8.GetBytes($"--{boundary}--\r\n"));

        using var request = new UnityWebRequest($"{whisperUrl}/v1/audio/transcriptions", "POST");
        request.uploadHandler = new UploadHandlerRaw(bodyStream.ToArray());
        request.downloadHandler = new DownloadHandlerBuffer();
        request.SetRequestHeader("Content-Type", $"multipart/form-data; boundary={boundary}");
        request.timeout = 120; // la prima richiesta dopo l'avvio può caricare il modello

        float t0 = Time.realtimeSinceStartup;
        yield return request.SendWebRequest();
        _sttSeconds = Time.realtimeSinceStartup - t0;

        if (request.result != UnityWebRequest.Result.Success)
        {
            callback(null, $"Whisper non raggiungibile: {request.error} (HTTP {request.responseCode})");
            yield break;
        }

        var response = JsonUtility.FromJson<WhisperResponse>(request.downloadHandler.text);
        if (response == null || string.IsNullOrWhiteSpace(response.text))
        {
            callback(null, "Non ho capito: nessun testo trascritto");
            yield break;
        }

        callback(response.text.Trim(), null);
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
        StopListening(); // niente ascolto durante la generazione
        _sessionId = Guid.NewGuid().ToString("N").Substring(0, 8);
        LastTranscript = prompt;
        LastObjectName = "";

        PlaySound(recordingStartSound);
        SetState(PipelineState.Generating, prompt);
        float t0 = Time.realtimeSinceStartup;
        N8NResponse result = null;
        string error = null;
        yield return StartCoroutine(CallN8N(prompt, (r, e) => { result = r; error = e; }));
        _genSeconds = Time.realtimeSinceStartup - t0;

        if (result == null)
        {
            Fail(error ?? "Generazione fallita");
            yield break;
        }
        UpdateEstimate(_genSeconds);
        LastObjectName = string.IsNullOrEmpty(result.object_name) ? "oggetto" : result.object_name;

        string glbUrl = RewriteToComfyHost(result.glb_url);
        GameObject loadedObject = null;
        yield return StartCoroutine(LoadGLB(glbUrl, (obj, e) => { loadedObject = obj; error = e; }));

        if (loadedObject == null)
        {
            Fail(error ?? "Caricamento del modello fallito");
            yield break;
        }

        PlaceInScene(loadedObject);
        PlaySound(successSound);

        float total = _sttSeconds + _genSeconds + _dlSeconds + _loadSeconds;
        string detail = $"Totale {FormatTime(total)}   ·   voce {_sttSeconds:F0} s   ·   generazione {FormatTime(_genSeconds)}   ·   download {_dlSeconds:F0} s";
        if (!string.IsNullOrEmpty(result.flux_prompt))
            detail += $"\n<i>{Truncate(result.flux_prompt, 160)}</i>";

        _sttSeconds = 0f;
        _isGenerating = false;
        SetState(PipelineState.Done, detail);

        if (handsFreeMode) StartListening();
    }

    private static string Truncate(string s, int max) => s.Length <= max ? s : s.Substring(0, max) + "…";

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

    private IEnumerator CallN8N(string prompt, Action<N8NResponse, string> callback)
    {
        var payload = JsonUtility.ToJson(new N8NRequest { prompt = prompt, session_id = _sessionId });
        using var request = new UnityWebRequest(n8nWebhookUrl, "POST");
        request.uploadHandler = new UploadHandlerRaw(Encoding.UTF8.GetBytes(payload));
        request.downloadHandler = new DownloadHandlerBuffer();
        request.SetRequestHeader("Content-Type", "application/json");
        request.timeout = (int)timeoutSeconds;

        Debug.Log($"[QuestObjectGenerator] POST → {n8nWebhookUrl} | {payload}");
        yield return request.SendWebRequest();

        string body = request.downloadHandler?.text ?? "";
        if (request.result != UnityWebRequest.Result.Success)
        {
            callback(null, $"n8n: HTTP {request.responseCode} {Truncate(body, 200)}".Trim());
            yield break;
        }

        Debug.Log($"[QuestObjectGenerator] n8n risposta: {body}");

        N8NResponse response = null;
        try { response = JsonUtility.FromJson<N8NResponse>(body); }
        catch (Exception e) { callback(null, $"Risposta n8n non valida: {e.Message}"); yield break; }

        if (response != null && response.status == "ready" && !string.IsNullOrEmpty(response.glb_url))
            callback(response, null);
        else
            callback(null, "Risposta n8n senza glb_url valido");
    }

    // ── Caricamento GLB con glTFast ───────────────────────────────────

    private IEnumerator LoadGLB(string url, Action<GameObject, string> callback)
    {
        SetState(PipelineState.Downloading, LastObjectName);
        float t0 = Time.realtimeSinceStartup;

        using var request = UnityWebRequest.Get(url);
        request.timeout = 120;
        yield return request.SendWebRequest();
        _dlSeconds = Time.realtimeSinceStartup - t0;

        if (request.result != UnityWebRequest.Result.Success)
        {
            callback(null, $"Download del modello fallito: {request.error} (HTTP {request.responseCode})");
            yield break;
        }

        byte[] data = request.downloadHandler.data;
        SetState(PipelineState.Loading, $"{LastObjectName} · {data.Length / 1024} KB");
        t0 = Time.realtimeSinceStartup;

        var gltf = new GltfImport();
        var loadTask = gltf.Load(data, new Uri(url));
        while (!loadTask.IsCompleted) yield return null;

        if (!loadTask.Result)
        {
            callback(null, "glTFast: parsing del GLB fallito");
            yield break;
        }

        var container = new GameObject($"AR_{_sessionId}");
        var instantiateTask = gltf.InstantiateMainSceneAsync(container.transform);
        while (!instantiateTask.IsCompleted) yield return null;
        _loadSeconds = Time.realtimeSinceStartup - t0;

        if (!instantiateTask.Result)
        {
            Destroy(container);
            callback(null, "glTFast: istanziazione fallita");
            yield break;
        }
        callback(container, null);
    }

    // ── Posizionamento nella scena ────────────────────────────────────

    private Transform GetHead()
    {
        if (headTransform != null) return headTransform;

        var origin = FindAnyObjectByType<XROrigin>();
        if (origin != null && origin.Camera != null) headTransform = origin.Camera.transform;
        else if (Camera.main != null) headTransform = Camera.main.transform;

        return headTransform;
    }

    private void PlaceInScene(GameObject obj)
    {
        AdjustScale(obj);
        Bounds bounds = GetWorldBounds(obj);

        if (obj.GetComponent<Collider>() == null && bounds.size.sqrMagnitude > 0f)
        {
            float s = Mathf.Max(obj.transform.localScale.x, 0.0001f);
            BoxCollider col = obj.AddComponent<BoxCollider>();
            col.center = obj.transform.InverseTransformPoint(bounds.center);
            col.size = bounds.size / s;
        }

        Transform cam = GetHead();
        if (cam == null) cam = transform;

        Vector3 flatForward = Vector3.ProjectOnPlane(cam.forward, Vector3.up);
        if (flatForward.sqrMagnitude < 0.0001f) flatForward = Vector3.forward;
        flatForward.Normalize();

        Vector3 spawnPos = cam.position + flatForward * spawnDistance + Vector3.up * spawnHeightOffset;
        Quaternion rot = faceUser ? Quaternion.LookRotation(flatForward, Vector3.up) : Quaternion.identity;
        obj.transform.rotation = rot;

        Vector3 centerOffset = bounds.center - obj.transform.position;
        obj.transform.position = spawnPos - rot * centerOffset;

        if (fallbackMaterial != null)
            foreach (var r in obj.GetComponentsInChildren<Renderer>())
                r.sharedMaterial = fallbackMaterial;

        Rigidbody rb = obj.GetComponent<Rigidbody>();
        if (rb == null) rb = obj.AddComponent<Rigidbody>();
        rb.useGravity = false;
        rb.isKinematic = true;
        rb.interpolation = RigidbodyInterpolation.Interpolate;

        var grab = obj.AddComponent<XRGrabInteractable>();
        grab.movementType = XRBaseInteractable.MovementType.Instantaneous;
        grab.useDynamicAttach = true;
        grab.throwOnDetach = false;
        grab.selectMode = InteractableSelectMode.Multiple; // due mani (o due controller) insieme

        var transformer = obj.AddComponent<XRGeneralGrabTransformer>();
        transformer.allowTwoHandedScaling = true;
        transformer.minimumScaleRatio = minScaleRatio;
        transformer.maximumScaleRatio = maxScaleRatio;

        Debug.Log($"[QuestObjectGenerator] Oggetto '{obj.name}' inserito in {obj.transform.position}.");
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

    private void PlaySound(AudioClip clip)
    {
        if (clip != null && _audioSource != null) _audioSource.PlayOneShot(clip);
    }

    // ── Strutture JSON ────────────────────────────────────────────────

    [Serializable] private class WhisperResponse { public string text; }
    [Serializable] private class N8NRequest { public string prompt; public string session_id; }
    [Serializable] private class N8NResponse { public string status; public string glb_url; public string object_name; public string flux_prompt; }
}