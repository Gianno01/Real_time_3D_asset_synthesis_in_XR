// QuestObjectGenerator.cs
// Compatibile con: Unity 6 + Meta Quest Pro + OpenXR + XR Interaction Toolkit 3.x + AR Foundation + glTFast
//
// Pipeline: voce → Whisper (STT) → n8n (LLM + ComfyUI) → download .glb → glTFast
//           → oggetto davanti all'utente, afferrabile/ruotabile/scalabile con mani o controller.
//
// Avvio di una richiesta:
//   1) MANI LIBERE (handsFreeMode): ascolto continuo; le frasi che iniziano con una parola di attivazione
//      ("genera", "crea") avviano la generazione. Es. "Genera una sedia di legno".
//   2) PULSANTE (recordButton): premi per registrare, la registrazione si chiude dopo una pausa.
//
// Anteprima (previewBeforeModel): prima del 3D viene mostrata l'immagine generata.
//   Ripeti → nuova immagine · Correzione a voce → nuova immagine con la modifica · Prosegui → modello 3D.
//   Correzioni: con il pulsante "Correggi" / lo stick, oppure a mani libere iniziando con "modifica", "aggiungi"...
//   Proseguire a voce ("prosegui", "vai") è previsto ma disattivato (voiceProceedEnabled = false).
//   n8n: un solo webhook con il campo "action" ("image" → anteprima, "model" → 3D dall'immagine approvata).
//
// Annullamento: CancelRequest() — dal pulsante "Annulla" dell'interfaccia (GenerationStatusUI).
//
// Libreria (AssetLibrary): ogni oggetto inserito riceve un componente SceneObject con i dati per salvarlo
// (percorsi su ComfyUI, prompt, miniatura). PrepareObject / InstantiateGlb / Dictate sono usati da AssetLibrary e LibraryUI.
//
// Espone uno stato pubblico (State, StateChanged, tempi, stima, MicLevel, IsListening, CanCancel)
// letto da GenerationStatusUI.

using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.Android;
using UnityEngine.InputSystem;
using Unity.XR.CoreUtils;
using UnityEngine.XR.Interaction.Toolkit.Interactables;
using UnityEngine.XR.Interaction.Toolkit.Transformers;
using UnityEngine.XR.Interaction.Toolkit.UI;
using GLTFast;

public enum PipelineState { Idle, Recording, Transcribing, Suggesting, GeneratingImage, Preview, Generating, Downloading, Loading, Done, Error, Cancelled }

public class QuestObjectGenerator : MonoBehaviour
{
    // ── Configurazione ────────────────────────────────────────────────

    [Header("Input Controller")]
    [Tooltip("Azione per avviare/fermare la registrazione vocale. Lasciala VUOTA per usare il percorso qui sotto")]
    public InputActionReference recordButton;
    [Tooltip("Usato se Record Button è vuoto. Default: pressione dello stick (pad) del controller destro")]
    public string recordBindingPath = "<XRController>{RightHand}/{Primary2DAxisClick}";

    [Header("Mani libere (parola di attivazione)")]
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
    [Tooltip("Interrompe DIRETTAMENTE ComfyUI all'annullamento. Ferma qualunque job in corso, anche di altri utenti: " +
             "lascialo DISATTIVO con più visori (ci pensa il workflow n8n quest-cancel, che ferma solo i job della sessione)")]
    public bool interruptComfyOnCancel = false;
    [Tooltip("Webhook n8n che annulla l'esecuzione della sessione (workflow \"quest-cancel\"). Vuoto = non usato")]
    public string n8nCancelUrl = "http://127.0.0.1:5678/webhook/quest-cancel";
    public float timeoutSeconds = 700f;

    [Header("Riferimenti XR")]
    [Tooltip("Main Camera dentro XR Origin (opzionale: se vuoto la cerca da solo)")]
    public Transform headTransform;

    [Header("Dimensioni e Posizionamento")]
    public float targetObjectSize = 0.3f;
    public float spawnDistance = 0.8f;
    public float spawnHeightOffset = -0.2f;
    public bool faceUser = true;
    [Tooltip("Rotazione extra (gradi, asse verticale) dell'oggetto appena creato. 180 = lo si vede di fronte invece che di spalle")]
    public float modelYawOffset = 180f;

    [Header("Effetto di creazione")]
    [Tooltip("Banda luminosa + guscio ologramma quando un oggetto compare (serve Resources/MaterializeShell.shader)")]
    public bool materializeEffect = true;
    public float materializeDuration = 1.6f;

    [Header("Manipolazione")]
    public float minScaleRatio = 0.25f;
    public float maxScaleRatio = 5f;

    [Header("Allineamento (griglia, misure, aggancio)")]
    [Tooltip("Griglia sotto l'oggetto e misure (base × profondità, altezza) mentre lo muovi")]
    public bool showPlacementAids = true;
    [Tooltip("Al rilascio: oggetto dritto, rotazione a scatti, posizione sulla griglia, appoggio sulle superfici")]
    public bool snapOnRelease = true;
    [Tooltip("Passo di allineamento orizzontale (m). 0 = solo appoggio, senza griglia")]
    public float snapGridStep = 0.05f;
    [Tooltip("Passo della rotazione (gradi). 0 = rotazione libera")]
    public float snapYawStep = 15f;
    [Tooltip("Raddrizza i modelli generati storti: base orizzontale e lati paralleli agli assi (griglia e misure più precise)")]
    public bool autoAlignModels = true;
    [Tooltip("Corregge anche l'inclinazione (solo se il modello ha una base o dei piedi su cui poggiare)")]
    public bool alignTilt = true;
    [Tooltip("Inclinazione massima corretta (gradi): oltre, l'inclinazione è considerata voluta")]
    public float maxTiltCorrection = 12f;

    [Header("Ombra")]
    [Tooltip("Ombra morbida sotto gli oggetti, sul pavimento o sulla superficie sottostante")]
    public bool contactShadows = true;
    [Range(0f, 1f)] public float shadowOpacity = 0.85f;
    [Tooltip("Distanza massima (m) per appoggiarsi a pavimento, piani o altri oggetti")]
    public float surfaceSnapDistance = 0.15f;

    [Header("Materiali")]
    [Tooltip("Materiale URP/Lit applicato ai modelli senza texture (Hunyuan). Vuoto per modelli texturizzati (Meshy)")]
    public Material fallbackMaterial;

    [Header("Anteprima immagine")]
    [Tooltip("Mostra l'immagine generata e aspetta Ripeti / Correggi / Prosegui prima del 3D")]
    public bool previewBeforeModel = true;
    [Tooltip("A mani libere, una frase durante l'anteprima vale come correzione solo se inizia con una di queste parole " +
             "(evita che una conversazione nella stanza diventi una correzione)")]
    public bool requireCorrectionKeyword = true;
    public string[] correctionWords = { "modifica", "aggiungi", "cambia", "togli", "rendi", "fallo", "falla", "mettici", "più", "meno" };
    [Tooltip("Proseguire al 3D dicendo una di queste parole. Disattivato per ora")]
    public bool voiceProceedEnabled = false;
    public string[] proceedWords = { "prosegui", "procedi", "vai", "conferma" };

    [Header("Libreria")]
    [Tooltip("Libreria condivisa (AssetLibrary). Se vuota viene cercata nella scena")]
    public AssetLibrary library;
    [Tooltip("Prima di generare cerca nell'inventario oggetti simili (ricerca semantica) e li propone")]
    public bool suggestFromLibrary = true;

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
    public float MicLevel { get; private set; }
    public bool IsListening { get; private set; }
    /// <summary>Durata media della generazione 3D (0 se non ancora disponibile).</summary>
    public float EstimatedGenerationSeconds => PlayerPrefs.GetFloat(PREF_AVG_GEN, 0f);
    /// <summary>Durata media della generazione dell'immagine di anteprima.</summary>
    public float EstimatedImageSeconds => PlayerPrefs.GetFloat(PREF_AVG_IMG, 0f);

    /// <summary>Immagine dell'anteprima corrente (stato Preview).</summary>
    public Texture2D PreviewTexture { get; private set; }
    /// <summary>Prompt (inglese) usato dall'LLM per l'immagine corrente.</summary>
    public string PreviewPrompt { get; private set; } = "";
    /// <summary>Ultima correzione applicata a voce.</summary>
    public string LastCorrection { get; private set; } = "";
    /// <summary>True mentre registra una correzione (pulsante "Correggi" o stick) durante l'anteprima.</summary>
    public bool IsRecordingCorrection { get; private set; }
    /// <summary>Quante immagini sono state generate per questa richiesta (1 = prima).</summary>
    public int PreviewAttempt { get; private set; }
    /// <summary>True mentre registra un testo dettato (es. nome di un oggetto o di una scena).</summary>
    public bool IsDictating { get; private set; }
    public Transform Head => GetHead();

    /// <summary>Oggetti simili trovati nell'inventario (stato Suggesting).</summary>
    public List<AssetRecord> Suggestions { get; private set; } = new List<AssetRecord>();
    /// <summary>True se l'ultimo oggetto è stato preso dall'inventario (non va salvato di nuovo).</summary>
    public bool LastFromInventory { get; private set; }
    /// <summary>Percorso ComfyUI ("/view?...") del GLB dell'ultimo oggetto inserito.</summary>
    public string LastGlbPath { get; private set; } = "";
    /// <summary>Percorso ComfyUI dell'immagine generata prima del 3D (anteprima).</summary>
    public string LastImagePath { get; private set; } = "";

    /// <summary>True quando c'è qualcosa da annullare (registrazione, trascrizione, generazione, download).</summary>
    public bool CanCancel =>
        State == PipelineState.Recording || State == PipelineState.Transcribing || State == PipelineState.Suggesting ||
        State == PipelineState.GeneratingImage || State == PipelineState.Preview ||
        State == PipelineState.Generating || State == PipelineState.Downloading || State == PipelineState.Loading;

    // ── Stato interno ─────────────────────────────────────────────────

    private const string PREF_AVG_GEN = "qog_avg_generation_seconds";
    private const string PREF_AVG_IMG = "qog_avg_image_seconds";

    private bool _isGenerating = false;
    private bool _isRecording = false;
    private bool _awaitingCommand = false;
    private int _requestId = 0;                 // cambia a ogni nuova richiesta e a ogni annullamento
    private UnityWebRequest _activeRequest;     // richiesta di rete in corso (per poterla interrompere)
    private InputAction _recordAction;          // azione effettivamente usata per la registrazione
    private bool _ownsRecordAction;
    private AudioSource _audioSource;
    private string _sessionId;
    private float _sttSeconds, _imgSeconds, _genSeconds, _dlSeconds, _loadSeconds;

    private enum SuggestionDecision { None, Generate, Use }
    private SuggestionDecision _decision = SuggestionDecision.None;
    private AssetRecord _chosenItem;

    private enum PreviewDecision { None, Retry, Proceed }
    private PreviewDecision _previewDecision = PreviewDecision.None;
    private string _workingPrompt = "";   // richiesta + correzioni accumulate
    private string _originalPrompt = "";  // prima richiesta (nome proposto dell'oggetto)
    private bool _correctionMode;         // la registrazione in corso è una correzione dell'anteprima

    // ── Audio ─────────────────────────────────────────────────────────

    private AudioClip _recordingClip;
    private AudioClip _listenClip;
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
        if (library == null) library = FindAnyObjectByType<AssetLibrary>();
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
            _recordAction = recordButton.action;
            _ownsRecordAction = false;
        }
        else if (!string.IsNullOrEmpty(recordBindingPath))
        {
            _recordAction = new InputAction("RecordRequest", InputActionType.Button, recordBindingPath);
            _ownsRecordAction = true;
        }
        if (_recordAction != null)
        {
            _recordAction.started += OnRecordButtonPressed;
            _recordAction.Enable();
        }
    }

    void OnDisable()
    {
        if (_recordAction != null)
        {
            _recordAction.started -= OnRecordButtonPressed;
            _recordAction.Disable();
            if (_ownsRecordAction) _recordAction.Dispose();
            _recordAction = null;
        }
        StopListening();
    }

    void Update()
    {
#if UNITY_EDITOR
        if (Keyboard.current != null)
        {
            if (Keyboard.current.spaceKey.wasPressedThisFrame && !_isGenerating)
                TriggerGeneration("un vaso di ceramica decorato");
            if (Keyboard.current.escapeKey.wasPressedThisFrame)
                CancelRequest();
            if (Keyboard.current.enterKey.wasPressedThisFrame) ProceedToModel();   // anteprima: Prosegui
            if (Keyboard.current.rKey.wasPressedThisFrame) RetryImage();           // anteprima: Ripeti
        }
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

    private void UpdateEstimate(string key, float seconds)
    {
        float avg = PlayerPrefs.GetFloat(key, 0f);
        avg = avg <= 0f ? seconds : avg * 0.7f + seconds * 0.3f;
        PlayerPrefs.SetFloat(key, avg);
        PlayerPrefs.Save();
    }

    public static string FormatTime(float seconds)
    {
        int s = Mathf.Max(0, Mathf.RoundToInt(seconds));
        return $"{s / 60}:{s % 60:00}";
    }

    // ── Annullamento ──────────────────────────────────────────────────

    /// <summary>Annulla la richiesta in corso. Chiamabile dalla UI, da un tasto o dalla voce.</summary>
    public void CancelRequest()
    {
        if (!CanCancel) return;

        bool comfyMayBeWorking = State == PipelineState.Generating || State == PipelineState.GeneratingImage;
        string cancelledSession = _sessionId;
        _requestId++;   // invalida le coroutine della richiesta corrente

        if (_activeRequest != null)
        {
            try { _activeRequest.Abort(); } catch { /* già conclusa */ }
            _activeRequest = null;
        }
        if (_isRecording)
        {
            Microphone.End(_micDevice);
            _isRecording = false;
        }
        _correctionMode = false;
        IsRecordingCorrection = false;

        _awaitingCommand = false;
        _isGenerating = false;
        MicLevel = 0f;

        if (comfyMayBeWorking)
        {
            StartCoroutine(NotifyN8NCancel(cancelledSession));   // ferma il workflow n8n di questa sessione
            if (interruptComfyOnCancel) StartCoroutine(InterruptComfy()); // ferma subito la GPU
        }

        SetState(PipelineState.Cancelled, "Richiesta annullata");
        if (handsFreeMode) StartListening();
    }

    private IEnumerator NotifyN8NCancel(string sessionId)
    {
        if (string.IsNullOrEmpty(n8nCancelUrl)) yield break;

        var payload = JsonUtility.ToJson(new N8NRequest { prompt = "", session_id = sessionId });
        using var r = new UnityWebRequest(n8nCancelUrl, "POST");
        r.uploadHandler = new UploadHandlerRaw(Encoding.UTF8.GetBytes(payload));
        r.downloadHandler = new DownloadHandlerBuffer();
        r.SetRequestHeader("Content-Type", "application/json");
        r.timeout = 5;
        yield return r.SendWebRequest();

        Debug.Log(r.result == UnityWebRequest.Result.Success
            ? $"[QuestObjectGenerator] n8n: annullamento inviato per la sessione {sessionId}"
            : $"[QuestObjectGenerator] n8n: annullamento non riuscito ({r.error})");
    }

    private IEnumerator InterruptComfy()
    {
        if (string.IsNullOrEmpty(comfyUrl)) yield break;

        using var r = new UnityWebRequest(comfyUrl.TrimEnd('/') + "/interrupt", "POST");
        r.uploadHandler = new UploadHandlerRaw(Encoding.UTF8.GetBytes("{}"));
        r.downloadHandler = new DownloadHandlerBuffer();
        r.SetRequestHeader("Content-Type", "application/json");
        r.timeout = 5;
        yield return r.SendWebRequest();

        Debug.Log(r.result == UnityWebRequest.Result.Success
            ? "[QuestObjectGenerator] ComfyUI: esecuzione interrotta"
            : $"[QuestObjectGenerator] ComfyUI interrupt non riuscito: {r.error}");
    }

    // ── Pulsante di registrazione ─────────────────────────────────────

    private void OnRecordButtonPressed(InputAction.CallbackContext context)
    {
        // Se stai puntando l'interfaccia (es. "Prosegui"), la pressione serve a cliccare, non a registrare
        if (IsPointingAtUI() || IsDictating) return;

        if (State == PipelineState.Preview)
        {
            if (!_isRecording) StartCorrectionRecording();
            else StopRecordingAndSend();
            return;
        }
        if (_isGenerating || State == PipelineState.Transcribing) return;

        if (!_isRecording)
        {
            _awaitingCommand = false;
            StopListening();
            StartRecording();
        }
        else StopRecordingAndSend();
    }

    // Vero se un raggio di controller o mano sta puntando un elemento dell'interfaccia
    private bool IsPointingAtUI()
    {
        foreach (var mb in FindObjectsByType<MonoBehaviour>(FindObjectsSortMode.None))
        {
            if (mb is not IUIInteractor ui || !mb.isActiveAndEnabled) continue;
            if (ui.TryGetUIModel(out TrackedDeviceModel model) &&
                model.currentRaycast.isValid && model.currentRaycast.gameObject != null)
                return true;
        }
        return false;
    }

    // ── Ascolto continuo (mani libere) ────────────────────────────────

    private void StartListening()
    {
        if (!handsFreeMode || IsListening || _isRecording) return;
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
        int window = SAMPLE_RATE / 10;
        int preRoll = SAMPLE_RATE * 3 / 10;
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
            _listenClip.GetData(buf, start);

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

                    if (len >= SAMPLE_RATE * 6 / 10)
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

    private IEnumerator HandleUtterance(float[] samples)
    {
        string text = null, error = null;
        yield return StartCoroutine(Transcribe(ConvertToWav(samples, SAMPLE_RATE), (t, e) => { text = t; error = e; }, trackForCancel: false));

        if (text == null)
        {
            Debug.LogWarning($"[QuestObjectGenerator] Ascolto: trascrizione fallita ({error})");
            yield break;
        }
        if (IsHallucination(text)) yield break;
        Debug.Log($"[QuestObjectGenerator] Sentito: \"{text}\"");

        if (State == PipelineState.Preview) { HandlePreviewSpeech(text, fromButton: false); yield break; }
        if (_isGenerating) yield break; // durante la generazione le frasi vengono ignorate

        if (_awaitingCommand)
        {
            _awaitingCommand = false;
            string cmd = CleanCommand(text);
            if (TryExtractCommand(text, out string again) && !string.IsNullOrEmpty(again)) cmd = again;
            if (cmd.Length < 2) { Fail("Non ho capito l'oggetto: riprova"); yield break; }
            TriggerGeneration(cmd);
            yield break;
        }

        if (!TryExtractCommand(text, out string command)) yield break;

        if (string.IsNullOrEmpty(command))
        {
            _awaitingCommand = true;
            PlaySound(recordingStartSound);
            SetState(PipelineState.Recording, "Dimmi quale oggetto vuoi generare");
            StartCoroutine(AwaitCommandTimeout());
            yield break;
        }

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

    private static string[] SplitWords(string text) =>
        text.Split(new[] { ' ', '\t', ',', '.', '!', '?', ';', ':', '"', '«', '»' }, StringSplitOptions.RemoveEmptyEntries);

    // "Ok, genera una sedia di legno." → true, command = "una sedia di legno"
    private bool TryExtractCommand(string text, out string command)
    {
        command = null;
        if (string.IsNullOrWhiteSpace(text)) return false;

        var words = SplitWords(text);
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

    private static readonly string[] HallucinationMarkers =
        { "amara.org", "amara org", "sottotitoli", "sottotitolato", "grazie per la visione", "iscriviti al canale" };

    private static bool IsHallucination(string text)
    {
        string t = text.ToLowerInvariant();
        foreach (var m in HallucinationMarkers) if (t.Contains(m)) return true;
        return false;
    }

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
        if (_correctionMode) IsRecordingCorrection = true;   // resta in anteprima, la UI mostra "ti ascolto"
        else SetState(PipelineState.Recording, "Parla ora: l'invio parte dopo 1,5 s di silenzio");

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
            if (_correctionMode) { EndCorrectionRecording(); return; }   // in anteprima: nessuna correzione, si resta lì
            Fail("Registrazione troppo corta: riprova");
            return;
        }

        float[] samples = new float[sampleCount];
        _recordingClip.GetData(samples, 0);

        if (_correctionMode)
        {
            StartCoroutine(TranscribeCorrection(ConvertToWav(samples, SAMPLE_RATE)));
            return;
        }

        float seconds = sampleCount / (float)SAMPLE_RATE;
        SetState(PipelineState.Transcribing, $"{seconds:F1} s di audio inviati a Whisper");
        StartCoroutine(TranscribeAndGenerate(ConvertToWav(samples, SAMPLE_RATE)));
    }

    private IEnumerator TranscribeAndGenerate(byte[] wav)
    {
        int myId = _requestId;
        string text = null, error = null;
        yield return StartCoroutine(Transcribe(wav, (t, e) => { text = t; error = e; }, trackForCancel: true));
        if (myId != _requestId) yield break; // annullata

        if (text == null) { Fail(error); yield break; }
        if (IsHallucination(text)) { Fail("Non ho sentito nulla: riprova"); yield break; }

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

    private IEnumerator Transcribe(byte[] wavData, Action<string, string> callback, bool trackForCancel)
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
        request.timeout = 120;

        if (trackForCancel) _activeRequest = request;
        float t0 = Time.realtimeSinceStartup;
        yield return request.SendWebRequest();
        if (trackForCancel && _activeRequest == request) _activeRequest = null;
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
        int myId = ++_requestId;
        _isGenerating = true;
        _sessionId = NewSessionId();
        _workingPrompt = prompt;
        _originalPrompt = prompt;
        LastTranscript = prompt;
        LastObjectName = "";
        LastCorrection = "";
        LastFromInventory = false;
        LastGlbPath = LastImagePath = "";
        PreviewAttempt = 0;
        StopListening(); // niente ascolto durante la generazione

        // 0) Esiste già qualcosa di simile nell'inventario? (Qdrant; se non risponde si genera e basta)
        if (suggestFromLibrary && library != null)
        {
            List<AssetRecord> matches = null;
            yield return StartCoroutine(library.Suggest(prompt, r => matches = r));
            if (myId != _requestId) yield break;

            if (matches != null && matches.Count > 0)
            {
                Suggestions = matches;
                _decision = SuggestionDecision.None;
                _chosenItem = null;
                SetState(PipelineState.Suggesting, prompt);

                while (_decision == SuggestionDecision.None && myId == _requestId) yield return null;
                if (myId != _requestId) yield break; // annullata

                if (_decision == SuggestionDecision.Use && _chosenItem != null)
                {
                    yield return StartCoroutine(SpawnSuggestionRoutine(_chosenItem, myId));
                    yield break;
                }
            }
            Suggestions = new List<AssetRecord>();
        }

        // 1) Immagine + anteprima: si ripete finché l'utente non preme "Prosegui"
        N8NResponse image = null;
        while (true)
        {
            _sessionId = NewSessionId();   // ogni immagine ha la sua sessione (nome file + annullamento)
            PreviewAttempt++;
            LastTranscript = _workingPrompt;
            PlaySound(recordingStartSound);
            SetState(PipelineState.GeneratingImage, _workingPrompt);

            float ti = Time.realtimeSinceStartup;
            string imgError = null;
            image = null;
            yield return StartCoroutine(CallN8N(
                new N8NRequest { action = "image", prompt = _workingPrompt, session_id = _sessionId },
                "preview", r => image = r, e => imgError = e));
            if (myId != _requestId) yield break; // annullata
            if (image == null) { Fail(imgError ?? "Generazione dell'immagine fallita"); yield break; }

            _imgSeconds = Time.realtimeSinceStartup - ti;
            UpdateEstimate(PREF_AVG_IMG, _imgSeconds);
            LastObjectName = string.IsNullOrEmpty(image.object_name) ? "oggetto" : image.object_name;
            LastImagePath = image.image_path;
            PreviewPrompt = image.flux_prompt ?? "";

            Texture2D tex = null;
            yield return StartCoroutine(LoadTexture(ComfyFullUrl(image.image_path), t => tex = t));
            if (myId != _requestId) { if (tex != null) Destroy(tex); yield break; }
            SetPreviewTexture(tex);

            if (!previewBeforeModel) break;   // anteprima disattivata: si prosegue subito

            _previewDecision = PreviewDecision.None;
            SetState(PipelineState.Preview, PreviewPrompt);
            if (handsFreeMode) StartListening();   // per correzioni ("modifica ...") o una nuova richiesta ("genera ...")

            while (_previewDecision == PreviewDecision.None && myId == _requestId) yield return null;
            if (myId != _requestId) yield break; // annullata dall'anteprima
            StopListening();
            if (_isRecording) { Microphone.End(_micDevice); _isRecording = false; }
            _correctionMode = false;
            IsRecordingCorrection = false;

            if (_previewDecision == PreviewDecision.Proceed) break;
            // Retry: nuova immagine (con le eventuali correzioni già aggiunte a _workingPrompt)
        }

        // 2) Modello 3D dall'immagine approvata
        PlaySound(recordingStartSound);
        SetState(PipelineState.Generating, _workingPrompt);

        float t0 = Time.realtimeSinceStartup;
        N8NResponse result = null;
        string error = null;
        yield return StartCoroutine(CallN8N(
            new N8NRequest
            {
                action = "model", session_id = _sessionId, prompt = _workingPrompt,
                image_path = image.image_path, object_name = image.object_name,
                flux_prompt = image.flux_prompt, seed = image.seed
            },
            "ready", r => result = r, e => error = e));
        if (myId != _requestId) yield break; // annullata
        _genSeconds = Time.realtimeSinceStartup - t0;

        if (result == null)
        {
            Fail(error ?? "Generazione 3D fallita");
            yield break;
        }
        UpdateEstimate(PREF_AVG_GEN, _genSeconds);
        if (!string.IsNullOrEmpty(result.object_name)) LastObjectName = result.object_name;

        string glbUrl = RewriteToComfyHost(result.glb_url);
        GameObject loadedObject = null;
        yield return StartCoroutine(LoadGLB(glbUrl, myId, (obj, e) => { loadedObject = obj; error = e; }));
        if (myId != _requestId)
        {
            if (loadedObject != null) Destroy(loadedObject);
            yield break;
        }

        if (loadedObject == null)
        {
            Fail(error ?? "Caricamento del modello fallito");
            yield break;
        }

        PlaceInScene(loadedObject);
        PlaySound(successSound);

        LastGlbPath = PathOf(result.glb_url);

        // Dati per la libreria (salvataggio nell'inventario e nelle scene)
        var so = loadedObject.AddComponent<SceneObject>();
        so.sourceGlbPath = LastGlbPath;
        so.sourceImagePath = LastImagePath;
        so.displayName = NiceName(_originalPrompt);
        so.objectName = LastObjectName;
        so.promptIt = _workingPrompt;
        so.promptEn = PreviewPrompt;
        so.model = "pixal3d";
        so.genImageSeconds = _imgSeconds;
        so.genModelSeconds = _genSeconds;
        so.placedBy = SystemInfo.deviceName;
        so.thumbnail = MakeThumbnail(PreviewTexture, 256);

        float total = _sttSeconds + _imgSeconds + _genSeconds + _dlSeconds + _loadSeconds;
        string detail = $"Totale {FormatTime(total)}   ·   immagine {_imgSeconds:F0} s   ·   3D {FormatTime(_genSeconds)}   ·   download {_dlSeconds:F0} s";
        if (!string.IsNullOrEmpty(PreviewPrompt))
            detail += $"\n<i>{Truncate(PreviewPrompt, 160)}</i>";

        _sttSeconds = 0f;
        _isGenerating = false;
        SetState(PipelineState.Done, detail);

        if (handsFreeMode) StartListening();
    }

    private static string NewSessionId() => Guid.NewGuid().ToString("N").Substring(0, 8);

    // ── API per la libreria (AssetLibrary / LibraryUI) ───────────────

    /// <summary>Prepara un oggetto caricato: davanti all'utente, collider, presa con una/due mani, griglia/misure/aggancio.</summary>
    public void PrepareObject(GameObject obj, bool animate = true) => PlaceInScene(obj, animate);

    /// <summary>Crea un oggetto da un GLB già scaricato (non cambia lo stato della pipeline).</summary>
    public IEnumerator InstantiateGlb(byte[] data, string sourceUrl, string objectName, Action<GameObject, string> callback)
    {
        var gltf = new GltfImport();
        var loadTask = gltf.Load(data, new Uri(sourceUrl));
        while (!loadTask.IsCompleted) yield return null;
        if (!loadTask.Result) { callback(null, "glTFast: parsing del GLB fallito"); yield break; }

        var container = new GameObject(objectName);
        var instantiateTask = gltf.InstantiateMainSceneAsync(container.transform);
        while (!instantiateTask.IsCompleted) yield return null;
        if (!instantiateTask.Result)
        {
            Destroy(container);
            callback(null, "glTFast: istanziazione fallita");
            yield break;
        }
        callback(container, null);
    }

    /// <summary>Registra una frase e la restituisce trascritta (null se non capita). Per nomi di oggetti e scene.</summary>
    public IEnumerator Dictate(Action<string> callback, float maxSeconds = 8f)
    {
        if (_isRecording || IsDictating || State == PipelineState.Recording || State == PipelineState.Transcribing)
        {
            callback(null);
            yield break;
        }
        IsDictating = true;
        bool resumeListening = IsListening;
        StopListening();

        string dev = Microphone.devices.Length > 0 ? Microphone.devices[0] : null;
        var clip = Microphone.Start(dev, false, Mathf.CeilToInt(maxSeconds), SAMPLE_RATE);
        PlaySound(recordingStartSound);
        yield return new WaitForSeconds(0.8f);

        int window = SAMPLE_RATE / 10;
        var buf = new float[window];
        float silence = 0f;
        var wait = new WaitForSeconds(0.1f);
        while (Microphone.IsRecording(dev))
        {
            int pos = Microphone.GetPosition(dev);
            if (pos > window)
            {
                clip.GetData(buf, pos - window);
                float max = 0f;
                foreach (float v in buf) max = Mathf.Max(max, Mathf.Abs(v));
                MicLevel = max;
                silence = max < SILENCE_THRESHOLD ? silence + 0.1f : 0f;
                if (silence >= 1.2f) break;
            }
            yield return wait;
        }

        int count = Microphone.GetPosition(dev);
        if (count <= 0) count = clip.samples;
        Microphone.End(dev);
        MicLevel = 0f;

        string text = null;
        if (count > SAMPLE_RATE / 3)
        {
            var samples = new float[count];
            clip.GetData(samples, 0);
            yield return StartCoroutine(Transcribe(ConvertToWav(samples, SAMPLE_RATE), (t, e) => text = t, trackForCancel: false));
        }
        IsDictating = false;
        if (text != null && IsHallucination(text)) text = null;
        if (resumeListening || (handsFreeMode && !_isGenerating)) StartListening();
        callback(text == null ? null : CleanCommand(text));
    }

    // "una sedia di legno" → "Sedia di legno"
    private static string NiceName(string request)
    {
        string t = CleanCommand(request ?? "");
        string lower = t.ToLowerInvariant();
        foreach (var art in new[] { "un ", "una ", "uno ", "un'", "il ", "lo ", "la ", "l'", "i ", "gli ", "le ", "dei ", "delle ", "degli " })
            if (lower.StartsWith(art)) { t = t.Substring(art.Length).TrimStart(); break; }
        if (t.Length == 0) return "Oggetto";
        if (t.Length > 60) t = t.Substring(0, 60);
        return char.ToUpper(t[0]) + t.Substring(1);
    }

    // Miniatura quadrata (per l'inventario) a partire dall'anteprima
    private static Texture2D MakeThumbnail(Texture2D src, int size)
    {
        if (src == null) return null;
        var rt = RenderTexture.GetTemporary(size, size, 0, RenderTextureFormat.ARGB32);
        Graphics.Blit(src, rt);
        var prev = RenderTexture.active;
        RenderTexture.active = rt;
        var thumb = new Texture2D(size, size, TextureFormat.RGB24, false);
        thumb.ReadPixels(new Rect(0, 0, size, size), 0, 0);
        thumb.Apply();
        RenderTexture.active = prev;
        RenderTexture.ReleaseTemporary(rt);
        return thumb;
    }

    // ── Anteprima: Ripeti / Correggi / Prosegui ──────────────────────

    /// <summary>Anteprima: genera una nuova immagine con la stessa richiesta.</summary>
    public void RetryImage()
    {
        if (State != PipelineState.Preview) return;
        _previewDecision = PreviewDecision.Retry;
    }

    /// <summary>Anteprima: l'immagine va bene, genera il modello 3D.</summary>
    public void ProceedToModel()
    {
        if (State != PipelineState.Preview) return;
        _previewDecision = PreviewDecision.Proceed;
    }

    /// <summary>Anteprima: aggiunge una correzione alla richiesta e rigenera l'immagine.</summary>
    public void ApplyCorrection(string correction)
    {
        if (State != PipelineState.Preview || string.IsNullOrWhiteSpace(correction)) return;
        LastCorrection = CleanCommand(correction);
        _workingPrompt = $"{_workingPrompt}. Modifica richiesta: {LastCorrection}";
        _previewDecision = PreviewDecision.Retry;
    }

    /// <summary>Anteprima: registra una correzione a voce (pulsante "Correggi" o stick).</summary>
    public void StartCorrectionRecording()
    {
        if (State != PipelineState.Preview || _isRecording) return;
        StopListening();
        _correctionMode = true;
        StartRecording();
    }

    private void EndCorrectionRecording()
    {
        _correctionMode = false;
        IsRecordingCorrection = false;
        if (State == PipelineState.Preview && handsFreeMode) StartListening();
    }

    private IEnumerator TranscribeCorrection(byte[] wav)
    {
        IsRecordingCorrection = false;
        string text = null, error = null;
        yield return StartCoroutine(Transcribe(wav, (t, e) => { text = t; error = e; }, trackForCancel: false));
        _correctionMode = false;

        if (State != PipelineState.Preview) yield break;   // nel frattempo annullata o già proseguita
        if (text == null || IsHallucination(text))
        {
            Debug.LogWarning($"[QuestObjectGenerator] Correzione non capita ({error ?? text})");
            if (handsFreeMode) StartListening();
            yield break;
        }
        HandlePreviewSpeech(text, fromButton: true);
        if (State == PipelineState.Preview && _previewDecision == PreviewDecision.None && handsFreeMode) StartListening();
    }

    // Cosa fare con una frase detta durante l'anteprima
    private void HandlePreviewSpeech(string text, bool fromButton)
    {
        Debug.Log($"[QuestObjectGenerator] Anteprima, sentito: \"{text}\"");

        // "Genera ..." → nuova richiesta al posto di quella corrente
        if (TryExtractCommand(text, out string cmd) && !string.IsNullOrEmpty(cmd))
        {
            _workingPrompt = cmd;
            LastCorrection = "";
            _previewDecision = PreviewDecision.Retry;
            return;
        }

        if (StartsWithAny(text, proceedWords))
        {
            if (voiceProceedEnabled) ProceedToModel();
            else Debug.Log("[QuestObjectGenerator] Proseguire a voce è disattivato (voiceProceedEnabled)");
            return;
        }

        // A mani libere serve una parola chiave, altrimenti è probabilmente una conversazione nella stanza
        if (!fromButton && requireCorrectionKeyword && !StartsWithAny(text, correctionWords)) return;

        ApplyCorrection(text);
    }

    private static bool StartsWithAny(string text, string[] targets)
    {
        if (string.IsNullOrWhiteSpace(text) || targets == null) return false;
        var words = SplitWords(text);
        for (int i = 0; i < Mathf.Min(words.Length, 2); i++)
        {
            string w = words[i].ToLowerInvariant();
            foreach (var t in targets)
                if (!string.IsNullOrEmpty(t) && w.StartsWith(t.ToLowerInvariant())) return true;
        }
        return false;
    }

    private void SetPreviewTexture(Texture2D tex)
    {
        if (PreviewTexture != null && PreviewTexture != tex) Destroy(PreviewTexture);
        PreviewTexture = tex;
    }

    private IEnumerator LoadTexture(string url, Action<Texture2D> callback)
    {
        using var r = UnityWebRequestTexture.GetTexture(url);
        r.timeout = 30;
        _activeRequest = r;
        yield return r.SendWebRequest();
        if (_activeRequest == r) _activeRequest = null;

        if (r.result != UnityWebRequest.Result.Success)
        {
            Debug.LogWarning($"[QuestObjectGenerator] Anteprima non scaricata: {r.error} ({url})");
            callback(null);
            yield break;
        }
        callback(DownloadHandlerTexture.GetContent(r));
    }

    // ── Suggerimenti dalla libreria ───────────────────────────────────

    /// <summary>Usa l'oggetto suggerito al posto di generarne uno nuovo.</summary>
    public void ChooseSuggestion(AssetRecord item)
    {
        if (State != PipelineState.Suggesting || item == null) return;
        _chosenItem = item;
        _decision = SuggestionDecision.Use;
    }

    /// <summary>Ignora i suggerimenti e genera comunque un oggetto nuovo.</summary>
    public void GenerateAnyway()
    {
        if (State != PipelineState.Suggesting) return;
        _decision = SuggestionDecision.Generate;
    }

    private IEnumerator SpawnSuggestionRoutine(AssetRecord item, int myId)
    {
        LastObjectName = string.IsNullOrEmpty(item.name) ? "oggetto" : item.name;
        LastFromInventory = true;
        SetState(PipelineState.Downloading, LastObjectName);
        float t0 = Time.realtimeSinceStartup;

        SceneObject so = null; string error = null;
        yield return StartCoroutine(library.SpawnFromInventory(item, (o, e) => { so = o; error = e; }));
        if (myId != _requestId)
        {
            if (so != null) Destroy(so.gameObject);
            yield break;
        }
        if (so == null) { Fail(error ?? "Caricamento dall'inventario non riuscito"); yield break; }

        PlaySound(successSound);
        _isGenerating = false;
        SetState(PipelineState.Done, $"Dall'inventario   ·   {Time.realtimeSinceStartup - t0:F0} s");
        if (handsFreeMode) StartListening();
    }

    /// <summary>URL completo di ComfyUI a partire da un percorso "/view?..." (o da un URL da riscrivere).</summary>
    public string ComfyFullUrl(string pathOrUrl)
    {
        if (string.IsNullOrEmpty(pathOrUrl)) return pathOrUrl;
        if (pathOrUrl.StartsWith("http", StringComparison.OrdinalIgnoreCase)) return RewriteToComfyHost(pathOrUrl);
        return comfyUrl.TrimEnd('/') + (pathOrUrl.StartsWith("/") ? pathOrUrl : "/" + pathOrUrl);
    }

    private static string PathOf(string url)
    {
        try { return new Uri(url).PathAndQuery; } catch { return url; }
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

    // expectedStatus: "preview" (fase immagine) oppure "ready" (fase 3D)
    private IEnumerator CallN8N(N8NRequest req, string expectedStatus, Action<N8NResponse> onOk, Action<string> onFail)
    {
        var payload = JsonUtility.ToJson(req);
        using var request = new UnityWebRequest(n8nWebhookUrl, "POST");
        request.uploadHandler = new UploadHandlerRaw(Encoding.UTF8.GetBytes(payload));
        request.downloadHandler = new DownloadHandlerBuffer();
        request.SetRequestHeader("Content-Type", "application/json");
        request.timeout = (int)timeoutSeconds;

        Debug.Log($"[QuestObjectGenerator] POST → {n8nWebhookUrl} | {payload}");
        _activeRequest = request;
        yield return request.SendWebRequest();
        if (_activeRequest == request) _activeRequest = null;

        string body = request.downloadHandler?.text ?? "";
        if (request.result != UnityWebRequest.Result.Success)
        {
            onFail($"n8n: HTTP {request.responseCode} {Truncate(body, 200)}".Trim());
            yield break;
        }

        Debug.Log($"[QuestObjectGenerator] n8n risposta: {Truncate(body, 400)}");

        N8NResponse response = null;
        try { response = JsonUtility.FromJson<N8NResponse>(body); }
        catch (Exception e) { onFail($"Risposta n8n non valida: {e.Message}"); yield break; }

        bool ok = response != null && response.status == expectedStatus &&
                  (expectedStatus == "preview" ? !string.IsNullOrEmpty(response.image_path) : !string.IsNullOrEmpty(response.glb_url));
        if (ok) onOk(response);
        else onFail(expectedStatus == "preview" ? "Risposta n8n senza immagine di anteprima" : "Risposta n8n senza glb_url valido");
    }

    // ── Caricamento GLB con glTFast ───────────────────────────────────

    private IEnumerator LoadGLB(string url, int myId, Action<GameObject, string> callback)
    {
        SetState(PipelineState.Downloading, LastObjectName);
        float t0 = Time.realtimeSinceStartup;

        using var request = UnityWebRequest.Get(url);
        request.timeout = 120;
        _activeRequest = request;
        yield return request.SendWebRequest();
        if (_activeRequest == request) _activeRequest = null;
        if (myId != _requestId) yield break;
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
        if (myId != _requestId) yield break;

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

    private void PlaceInScene(GameObject obj, bool animate = true)
    {
        if (autoAlignModels) ModelAlignment.Align(obj, alignTilt, maxTiltCorrection);   // prima di misurare: griglia e misure sui lati veri
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
        Quaternion rot = faceUser ? Quaternion.LookRotation(flatForward, Vector3.up) * Quaternion.Euler(0f, modelYawOffset, 0f) : Quaternion.identity;
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
        grab.selectMode = InteractableSelectMode.Multiple;

        var transformer = obj.AddComponent<XRGeneralGrabTransformer>();
        transformer.allowTwoHandedScaling = true;
        transformer.minimumScaleRatio = minScaleRatio;
        transformer.maximumScaleRatio = maxScaleRatio;

        // Griglia, misure e aggancio
        // Griglia, misure, aggancio e ombra: componenti sempre presenti, attivati secondo le impostazioni
        // (così si possono accendere e spegnere anche dopo, dal pannello Impostazioni)
        var origin = FindAnyObjectByType<XROrigin>();
        float floorY = origin != null ? origin.transform.position.y : 0f;
        float unit = Mathf.Max(obj.transform.localScale.x, 0.0001f);
        var aids = obj.GetComponent<ObjectPlacementAids>();
        if (aids == null) aids = obj.AddComponent<ObjectPlacementAids>();
        aids.Init(bounds.size / unit, cam);   // bounds misurati prima della rotazione → dimensioni reali
        aids.floorHeight = floorY;
        var shadow = obj.GetComponent<ContactShadow>();
        if (shadow == null) shadow = obj.AddComponent<ContactShadow>();
        shadow.Init(bounds.size / unit, floorY);
        ApplySettingsTo(obj);

        if (animate && materializeEffect) MaterializeEffect.Begin(obj, materializeDuration);   // per ultimo: legge scala e posizione finali

        Debug.Log($"[QuestObjectGenerator] Oggetto '{obj.name}' inserito in {obj.transform.position}.");
    }

    /// <summary>Applica le impostazioni correnti (griglia, aggancio, ombra) a un oggetto in scena.</summary>
    public void ApplySettingsTo(GameObject obj)
    {
        var aids = obj.GetComponent<ObjectPlacementAids>();
        if (aids != null)
        {
            aids.showGrid = aids.showDimensions = showPlacementAids;
            aids.snapOnRelease = snapOnRelease;
            aids.gridStep = snapGridStep;
            aids.yawStep = snapYawStep;
            aids.surfaceSnapDistance = surfaceSnapDistance;
        }
        var shadow = obj.GetComponent<ContactShadow>();
        if (shadow != null)
        {
            shadow.opacity = shadowOpacity;
            shadow.enabled = contactShadows;
        }
    }

    /// <summary>Applica le impostazioni correnti a tutti gli oggetti già in scena.</summary>
    public void ApplySettingsToScene()
    {
        foreach (var a in FindObjectsByType<ObjectPlacementAids>(FindObjectsSortMode.None)) ApplySettingsTo(a.gameObject);
    }

    /// <summary>Attiva o disattiva l'ascolto continuo con parola di attivazione.</summary>
    public void SetHandsFree(bool on)
    {
        handsFreeMode = on;
        if (!on) StopListening();
        else if (!_isRecording && !IsDictating && (!_isGenerating || State == PipelineState.Preview)) StartListening();
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
    [Serializable] private class N8NRequest
    {
        public string action;        // "image" | "model"
        public string prompt;
        public string session_id;
        public string image_path;    // solo "model": immagine approvata
        public string object_name;
        public string flux_prompt;
        public string seed;
    }
    [Serializable] private class N8NResponse
    {
        public string status;        // "preview" | "ready"
        public string glb_url;
        public string image_path;
        public string object_name;
        public string flux_prompt;
        public string seed;
    }
}
