// GenerationStatusUI.cs
// Interfaccia minimale "da pannello di controllo" per QuestObjectGenerator.
//
//  • Posizione  → davanti a te, in basso (circa all'altezza di una scrivania), inclinata verso di te come
//                 una tastiera / un pannello di controllo. Resta ferma finché non ti giri; se ti giri oltre
//                 un certo angolo si ricentra con calma. Puoi anche afferrarla dalla MANIGLIA e lasciarla dove vuoi.
//  • In attesa  → "pillola" con l'istruzione su come inviare la richiesta (pallino che reagisce alla voce)
//  • In corso   → card: stato, cosa hai chiesto, 4 step, tempo trascorso, stima rimanente, barra, pulsante Annulla
//  • Anteprima  → immagine generata, richiesta e prompt, pulsanti Correggi / Ripeti / Annulla / Prosegui
//  • Esito      → conferma verde / errore rosso / annullata grigia, poi torna alla pillola
//  • Riduci a icona → pulsante "–" in alto a destra o tasto A del controller destro; tocca l'icona per riaprire.
//                 Da icona, il pallino colorato continua a mostrare lo stato (blu = in corso, verde = pronto, rosso = errore).
//
// SETUP: GameObject vuoto (es. "StatusUI") + questo componente. La UI è generata via codice.
// Richiede: TextMeshPro e un EventSystem con XR UI Input Module (per i pulsanti).

using System.Collections;
using TMPro;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.UI;
using UnityEngine.XR;
using UnityEngine.XR.Interaction.Toolkit.Interactables;
using UnityEngine.XR.Interaction.Toolkit.UI;

public class GenerationStatusUI : MonoBehaviour
{
    [Header("Riferimenti")]
    [Tooltip("Se vuoto viene cercato nella scena")]
    public QuestObjectGenerator generator;
    [Tooltip("Se vuoto usa la testa del generator (Main Camera dell'XR Origin)")]
    public Transform head;

    [Header("Riduci a icona")]
    [Tooltip("Azione che riduce/riapre il pannello. Se vuota usa il tasto A del controller destro")]
    public InputActionReference toggleButton;
    public bool startMinimized = false;

    [Header("Testi")]
    [TextArea] public string idleHint = "<b>Premi lo stick destro</b> e di' il nome di un oggetto";
    [TextArea] public string handsFreeHint = "Di' <b>\"Genera...\"</b> seguito dall'oggetto, ad esempio <i>\"Genera una sedia di legno\"</i>";
    [TextArea] public string previewHintHandsFree = "Di' <b>\"modifica...\"</b> o <b>\"aggiungi...\"</b> per correggerla · <b>\"genera...\"</b> per un altro oggetto";
    [TextArea] public string previewHintButton = "Premi <b>Correggi</b> (o lo stick) e di' cosa cambiare";

    [Header("Posizione \"da scrivania\"")]
    [Tooltip("Distanza orizzontale davanti a te (m)")]
    public float distance = 0.5f;
    [Tooltip("Quanto sotto gli occhi (m, negativo = più in basso). -0.55 ≈ altezza scrivania")]
    public float heightOffset = -0.55f;
    [Tooltip("Inclinazione del pannello (0 = verticale, 90 = piatto come un tavolo)")]
    [Range(0f, 80f)] public float deskTilt = 40f;
    [Tooltip("Il pannello si ricentra solo se ti giri oltre questo angolo")]
    public float recenterAngle = 40f;
    [Tooltip("Velocità del ricentramento")]
    public float followSpeed = 2.5f;

    [Header("Spostamento manuale")]
    [Tooltip("Mostra una maniglia sotto il pannello per afferrarlo e spostarlo")]
    public bool movable = true;
    [Tooltip("Se il pannello fissato è fuori vista quando parte una nuova richiesta, torna davanti a te")]
    public bool recallWhenOutOfView = true;

    [Header("Comportamento")]
    public bool showIdleHint = true;
    public float showDoneSeconds = 6f;
    public float showErrorSeconds = 10f;
    public float showCancelledSeconds = 3f;
    public bool haptics = true;

    // ── Palette ───────────────────────────────────────────────────────

    static readonly Color CardBg   = new Color(0.07f, 0.08f, 0.11f, 0.92f);
    static readonly Color PillBg   = new Color(0.07f, 0.08f, 0.11f, 0.78f);
    static readonly Color TextMain = new Color(0.95f, 0.96f, 0.98f);
    static readonly Color TextDim  = new Color(0.60f, 0.64f, 0.72f);
    static readonly Color Pending  = new Color(1f, 1f, 1f, 0.16f);
    static readonly Color Accent   = new Color(0.40f, 0.64f, 1.00f);
    static readonly Color Ok       = new Color(0.33f, 0.86f, 0.56f);
    static readonly Color Bad      = new Color(1.00f, 0.43f, 0.41f);

    static readonly string[] StepNames = { "Voce", "Immagine", "Modello 3D", "Caricamento" };

    const float CardW = 640f, CardH = 304f, PillW = 620f, PillH = 72f, IconSize = 76f, PreviewW = 640f, PreviewH = 470f;

    // ── Riferimenti UI ────────────────────────────────────────────────

    Sprite _rounded, _circle;
    CanvasGroup _pill, _card, _icon, _preview;
    TextMeshProUGUI _hint, _title, _timer, _subline, _label, _quote, _footer;
    Image _statusDot, _barFill, _micDot, _handle, _iconDot;
    RectTransform _barFillRt, _handleRt;
    GameObject _cancelButton;

    // Anteprima
    RawImage _previewImage;
    TextMeshProUGUI _pvTitle, _pvTimer, _pvSub, _pvRequest, _pvPrompt, _pvHint, _pvNoImage, _pvCorrectLabel;
    Image _pvDot;
    readonly Image[] _stepDots = new Image[4];
    readonly TextMeshProUGUI[] _stepLabels = new TextMeshProUGUI[4];
    readonly Image[] _stepLinks = new Image[3];

    XRGrabInteractable _grab;
    Transform _handleCollider;
    InputAction _toggleAction;
    bool _ownsToggleAction;

    // ── Stato locale ──────────────────────────────────────────────────

    PipelineState _state = PipelineState.Idle;
    int _activeStep = -1, _failedStep = -1;
    float _requestStart = -1f, _finalElapsed, _stateShownAt, _nextText;
    bool _showCard, _placed, _pinned, _grabbed, _minimized, _recentering;
    Vector3 _anchorFwd = Vector3.forward;
    Color _accentNow = Accent;

    // ── Lifecycle ─────────────────────────────────────────────────────

    void Awake()
    {
        _rounded = MakeRoundedSprite(64, 24);
        _circle = MakeRoundedSprite(64, 32);
        BuildUI();
        if (movable) SetupGrab();
        _pill.alpha = _card.alpha = _icon.alpha = _preview.alpha = 0f;
        _minimized = startMinimized;
    }

    void OnEnable()
    {
        if (toggleButton != null && toggleButton.action != null)
        {
            _toggleAction = toggleButton.action;
            _ownsToggleAction = false;
        }
        else
        {
            // Tasto A del controller destro (Touch / Touch Pro / Touch Plus via OpenXR)
            _toggleAction = new InputAction("ToggleStatusUI", InputActionType.Button, "<XRController>{RightHand}/primaryButton");
            _ownsToggleAction = true;
        }
        _toggleAction.performed += OnToggle;
        _toggleAction.Enable();
    }

    void OnDisable()
    {
        if (_toggleAction == null) return;
        _toggleAction.performed -= OnToggle;
        if (_ownsToggleAction) { _toggleAction.Disable(); _toggleAction.Dispose(); }
        _toggleAction = null;
    }

    void Start()
    {
        if (generator == null) generator = FindAnyObjectByType<QuestObjectGenerator>();
        if (generator == null)
        {
            Debug.LogError("[GenerationStatusUI] QuestObjectGenerator non trovato.");
            enabled = false;
            return;
        }
        generator.StateChanged += OnStateChanged;
        if (generator.handsFreeMode) _hint.text = handsFreeHint;
    }

    void OnDestroy()
    {
        if (generator != null) generator.StateChanged -= OnStateChanged;
    }

    void LateUpdate()
    {
        float now = Time.realtimeSinceStartup;
        float dt = Time.unscaledDeltaTime;

#if UNITY_EDITOR
        if (Keyboard.current != null && Keyboard.current.mKey.wasPressedThisFrame) ToggleMinimized();
#endif

        // Dopo l'esito torna alla pillola
        float shown = now - _stateShownAt;
        if (_showCard &&
            ((_state == PipelineState.Done && shown > showDoneSeconds) ||
             (_state == PipelineState.Error && shown > showErrorSeconds) ||
             (_state == PipelineState.Cancelled && shown > showCancelledSeconds)))
        {
            _showCard = false;
            _state = PipelineState.Idle;
        }

        bool previewOn = _showCard && _state == PipelineState.Preview;
        Fade(_card, !_minimized && _showCard && !previewOn, dt * 5f);
        Fade(_preview, !_minimized && previewOn, dt * 5f);
        Fade(_pill, !_minimized && !_showCard && showIdleHint, dt * 3f);
        Fade(_icon, _minimized, dt * 5f);

        bool anyVisible = _card.alpha > 0f || _pill.alpha > 0f || _icon.alpha > 0f || _preview.alpha > 0f;
        if (_handleCollider != null) _handleCollider.gameObject.SetActive(anyVisible);
        if (!anyVisible) return;

        UpdatePlacement(!_placed, dt);
        _placed = true;
        UpdateHandle(dt);

        bool cancellable = generator.CanCancel;
        if (_cancelButton.activeSelf != cancellable) _cancelButton.SetActive(cancellable);

        if (_pill.alpha > 0f) UpdateMicDot(_micDot, dt);
        if (_icon.alpha > 0f) UpdateIcon(now, dt);

        if (_card.alpha > 0f)
        {
            UpdateSteps(now);
            UpdateBar(now, dt);
            if (now >= _nextText) { _nextText = now + 0.25f; UpdateTimeTexts(now); }
        }

        if (_preview.alpha > 0f) UpdatePreview(now, dt);
    }

    static void Fade(CanvasGroup g, bool on, float step)
    {
        g.alpha = Mathf.MoveTowards(g.alpha, on ? 1f : 0f, step);
        bool interactive = on && g.alpha > 0.5f;
        g.interactable = interactive;
        g.blocksRaycasts = interactive;
    }

    // ── Riduci a icona ────────────────────────────────────────────────

    void OnToggle(InputAction.CallbackContext _) => ToggleMinimized();

    public void ToggleMinimized() => SetMinimized(!_minimized);

    public void SetMinimized(bool value)
    {
        _minimized = value;
        Haptic(0.2f, 0.04f);
    }

    // ── Eventi dal generator ──────────────────────────────────────────

    void OnStateChanged(PipelineState state, string detail)
    {
        float now = Time.realtimeSinceStartup;
        bool startingNew = state == PipelineState.Recording ||
                           ((state == PipelineState.Generating || state == PipelineState.GeneratingImage) && _requestStart < 0f);
        _state = state;
        _stateShownAt = now;
        _nextText = 0f;
        if (state != PipelineState.Error) _failedStep = -1;

        if (startingNew && _pinned && recallWhenOutOfView && IsOutOfView()) { _pinned = false; _placed = false; }

        switch (state)
        {
            case PipelineState.Recording:
                _requestStart = -1f;
                _activeStep = 0;
                Show("Ti ascolto...", "PARLA ORA", string.IsNullOrEmpty(detail)
                     ? "Pronuncia il nome di un oggetto: l'invio parte da solo dopo una breve pausa." : detail, Accent);
                Haptic(0.25f, 0.05f);
                break;

            case PipelineState.Transcribing:
                _requestStart = now;
                _activeStep = 0;
                Show("Richiesta inviata", "AUDIO INVIATO", detail, Accent);
                Haptic(0.6f, 0.08f);
                break;

            case PipelineState.Suggesting:
                if (_requestStart < 0f) _requestStart = now;
                _activeStep = 1;
                Show("Esiste già qualcosa di simile", "HAI CHIESTO", $"\"{detail}\"", Ok);
                StartCoroutine(DoubleHaptic());
                break;

            case PipelineState.GeneratingImage:
                if (_requestStart < 0f) { _requestStart = now; Haptic(0.6f, 0.08f); }
                _activeStep = 1;
                Show(generator.PreviewAttempt > 1 ? "Creo una nuova immagine" : "Creo l'immagine",
                     "HAI CHIESTO", $"\"{detail}\"", Accent);
                break;

            case PipelineState.Preview:
                _activeStep = 2;
                Show("Ti piace?", "HAI CHIESTO", $"\"{generator.LastTranscript}\"", Ok);
                ShowPreview();
                StartCoroutine(DoubleHaptic());
                break;

            case PipelineState.Generating:
                if (_requestStart < 0f) { _requestStart = now; Haptic(0.6f, 0.08f); }
                _activeStep = 2;
                Show("Sto creando il modello 3D", "HAI CHIESTO", $"\"{detail}\"", Accent);
                break;

            case PipelineState.Downloading:
            case PipelineState.Loading:
                _activeStep = 3;
                Show("Quasi pronto...", "HAI CHIESTO", $"\"{generator.LastTranscript}\"", Accent);
                break;

            case PipelineState.Done:
                _finalElapsed = Elapsed(now);
                _activeStep = 4;
                Show($"{(generator.LastFromInventory ? "Inserito" : "Creato")}: {generator.LastObjectName}", "HAI CHIESTO", $"\"{generator.LastTranscript}\"", Ok);
                _requestStart = -1f;
                StartCoroutine(DoubleHaptic());
                break;

            case PipelineState.Error:
                _finalElapsed = Elapsed(now);
                _failedStep = Mathf.Clamp(_activeStep, 0, 3);
                Show("Qualcosa è andato storto", "ERRORE", detail, Bad);
                _requestStart = -1f;
                Haptic(0.8f, 0.25f);
                break;

            case PipelineState.Cancelled:
                _finalElapsed = Elapsed(now);
                Show("Richiesta annullata", "ANNULLATA", _activeStep >= 2
                     ? $"\"{generator.LastTranscript}\"" : "Nessuna richiesta inviata", TextDim);
                _requestStart = -1f;
                Haptic(0.3f, 0.1f);
                break;

            default: // Idle
                _showCard = false;
                _requestStart = -1f;
                break;
        }
    }

    void Show(string title, string label, string quote, Color accent)
    {
        _showCard = true;
        _accentNow = accent;
        _title.text = title;
        _label.text = label;
        _quote.text = quote;
        _statusDot.color = accent;
        _barFill.color = accent;
    }

    float Elapsed(float now) => _requestStart >= 0f ? now - _requestStart : 0f;

    // ── Aggiornamenti per frame ───────────────────────────────────────

    void UpdateMicDot(Image dot, float dt)
    {
        bool listening = generator.IsListening;
        float s = listening ? 1f + Mathf.Clamp01(generator.MicLevel * 6f) * 0.9f : 1f;
        dot.rectTransform.localScale = Vector3.Lerp(dot.rectTransform.localScale, Vector3.one * s, dt * 15f);
        dot.color = listening ? Accent : TextDim;
    }

    void UpdateIcon(float now, float dt)
    {
        if (_showCard)
        {
            bool finished = _state == PipelineState.Done || _state == PipelineState.Error || _state == PipelineState.Cancelled;
            var c = _accentNow;
            c.a = finished ? 1f : 0.55f + 0.45f * Mathf.Sin(now * 5f);
            _iconDot.color = c;
            _iconDot.rectTransform.localScale = Vector3.Lerp(_iconDot.rectTransform.localScale, Vector3.one, dt * 10f);
        }
        else UpdateMicDot(_iconDot, dt);
    }

    void UpdateTimeTexts(float now)
    {
        string F(float s) => QuestObjectGenerator.FormatTime(s);

        switch (_state)
        {
            case PipelineState.Recording:
                _timer.text = F(now - _stateShownAt);
                _subline.text = "in ascolto";
                break;
            case PipelineState.Transcribing:
                _timer.text = F(Elapsed(now));
                _subline.text = "trascrizione in corso";
                break;
            case PipelineState.Suggesting:
                _timer.text = F(Elapsed(now));
                _subline.text = "scegli nella Libreria: Usa o Genera nuovo";
                break;
            case PipelineState.GeneratingImage:
            case PipelineState.Generating:
                _timer.text = F(Elapsed(now));
                float est = _state == PipelineState.GeneratingImage ? generator.EstimatedImageSeconds : generator.EstimatedGenerationSeconds;
                float genEl = now - generator.StateStartTime;
                _subline.text = est <= 0f ? "prima generazione: stima in corso"
                              : est - genEl > 0f ? $"circa {F(est - genEl)} rimanenti"
                              : "manca poco...";
                break;
            case PipelineState.Downloading:
            case PipelineState.Loading:
                _timer.text = F(Elapsed(now));
                _subline.text = "download e caricamento";
                break;
            case PipelineState.Done:
                _timer.text = F(_finalElapsed);
                _subline.text = "completato";
                break;
            case PipelineState.Error:
                _timer.text = _finalElapsed > 0f ? F(_finalElapsed) : "";
                _subline.text = "riprova quando vuoi";
                break;
            case PipelineState.Cancelled:
                _timer.text = _finalElapsed > 0f ? F(_finalElapsed) : "";
                _subline.text = "annullata";
                break;
        }
    }

    void UpdateSteps(float now)
    {
        bool finished = _state == PipelineState.Done || _state == PipelineState.Error || _state == PipelineState.Cancelled;
        float pulse = 1f + 0.22f * (0.5f + 0.5f * Mathf.Sin(now * 6f));

        for (int i = 0; i < 4; i++)
        {
            Color c;
            float scale = 1f;

            if (_state == PipelineState.Error && i == _failedStep) c = Bad;
            else if (i < _activeStep) c = Ok;
            else if (i == _activeStep && !finished) { c = Accent; scale = pulse; }
            else c = Pending;

            _stepDots[i].color = c;
            _stepDots[i].rectTransform.localScale = Vector3.one * scale;
            _stepLabels[i].color = (i <= _activeStep || i == _failedStep) ? TextMain : TextDim;
            if (i < 3) _stepLinks[i].color = i < _activeStep ? Ok : Pending;
        }

        var sc = _accentNow;
        sc.a = finished ? 1f : 0.55f + 0.45f * Mathf.Sin(now * 5f);
        _statusDot.color = sc;
    }

    void UpdateBar(float now, float dt)
    {
        float target;
        switch (_state)
        {
            case PipelineState.Recording:
                target = Mathf.Clamp01(generator.MicLevel * 4f);
                break;
            case PipelineState.GeneratingImage:
            case PipelineState.Generating:
                float est = _state == PipelineState.GeneratingImage ? generator.EstimatedImageSeconds : generator.EstimatedGenerationSeconds;
                float genEl = now - generator.StateStartTime;
                target = est > 0f ? Mathf.Lerp(0.25f, 0.95f, Mathf.Clamp01(genEl / est))
                                  : 0.25f + 0.1f * Mathf.PingPong(now * 0.5f, 1f);
                break;
            case PipelineState.Transcribing: target = 0.15f; break;
            case PipelineState.Downloading:
            case PipelineState.Loading:      target = 0.97f; break;
            case PipelineState.Cancelled:    target = _barFillRt.anchorMax.x; break;
            default:                         target = 1f; break;
        }

        float x = Mathf.Lerp(_barFillRt.anchorMax.x, target, dt * 8f);
        _barFillRt.anchorMax = new Vector2(Mathf.Max(x, 0.02f), 1f);
    }

    // ── Anteprima ─────────────────────────────────────────────────────

    void ShowPreview()
    {
        var tex = generator.PreviewTexture;
        _previewImage.texture = tex;
        _previewImage.color = tex != null ? Color.white : new Color(1f, 1f, 1f, 0f);
        _pvNoImage.gameObject.SetActive(tex == null);

        _pvTitle.text = generator.PreviewAttempt > 1 ? $"Ti piace? <size=70%><color=#9AA3B5>· immagine {generator.PreviewAttempt}</color></size>" : "Ti piace?";
        _pvRequest.text = $"\"{generator.LastTranscript}\"";
        _pvPrompt.text = string.IsNullOrEmpty(generator.PreviewPrompt) ? "" : $"<i>{generator.PreviewPrompt}</i>";
        _pvSub.text = generator.EstimatedImageSeconds > 0f ? "scegli come continuare" : "";
    }

    void UpdatePreview(float now, float dt)
    {
        if (now >= _nextText)
        {
            _nextText = now + 0.25f;
            _pvTimer.text = QuestObjectGenerator.FormatTime(Elapsed(now));
        }

        bool rec = generator.IsRecordingCorrection;
        bool listening = generator.IsListening;
        string hint = rec ? "<color=#66A3FF><b>Ti ascolto:</b></color> di' cosa cambiare..."
                    : generator.handsFreeMode ? previewHintHandsFree : previewHintButton;
        if (_pvHint.text != hint) _pvHint.text = hint;
        string label = rec ? "Ascolto..." : "Correggi";
        if (_pvCorrectLabel.text != label) _pvCorrectLabel.text = label;

        // pallino: reagisce alla voce mentre ascolta (correzioni), altrimenti verde fisso
        float level = (rec || listening) ? Mathf.Clamp01(generator.MicLevel * 6f) : 0f;
        _pvDot.rectTransform.localScale = Vector3.Lerp(_pvDot.rectTransform.localScale, Vector3.one * (1f + level * 0.9f), dt * 15f);
        _pvDot.color = rec || level > 0.05f ? Accent : Ok;
    }

    // ── Posizionamento ────────────────────────────────────────────────

    Transform Head() => head != null ? head : generator != null ? generator.Head : null;

    static Vector3 Flat(Vector3 v)
    {
        v = Vector3.ProjectOnPlane(v, Vector3.up);
        return v.sqrMagnitude < 0.0001f ? Vector3.forward : v.normalized;
    }

    void UpdatePlacement(bool snap, float dt)
    {
        Transform h = Head();
        if (h == null) return;

        if (_grabbed || _pinned)
        {
            // Fissato dove l'hai lasciato: si gira solo verso di te, mantenendo l'inclinazione da pannello
            Vector3 toPanel = Flat(transform.position - h.position);
            Quaternion r = Quaternion.LookRotation(toPanel, Vector3.up) * Quaternion.Euler(deskTilt, 0f, 0f);
            transform.rotation = Quaternion.Slerp(transform.rotation, r, 1f - Mathf.Exp(-10f * dt));
            return;
        }

        // Modalità "scrivania": resta davanti al corpo, si ricentra solo se ti giri oltre recenterAngle
        Vector3 fwd = Flat(h.forward);
        if (snap) { _anchorFwd = fwd; _recentering = false; }
        else
        {
            float ang = Vector3.Angle(_anchorFwd, fwd);
            if (ang > recenterAngle) _recentering = true;
            if (_recentering)
            {
                _anchorFwd = Vector3.Slerp(_anchorFwd, fwd, 1f - Mathf.Exp(-followSpeed * dt)).normalized;
                if (Vector3.Angle(_anchorFwd, fwd) < 3f) _recentering = false;
            }
        }

        Vector3 target = h.position + _anchorFwd * distance + Vector3.up * heightOffset;
        Quaternion rot = Quaternion.LookRotation(_anchorFwd, Vector3.up) * Quaternion.Euler(deskTilt, 0f, 0f);

        float t = snap ? 1f : 1f - Mathf.Exp(-followSpeed * dt);
        transform.position = Vector3.Lerp(transform.position, target, t);
        transform.rotation = snap ? rot : Quaternion.Slerp(transform.rotation, rot, t);
    }

    bool IsOutOfView()
    {
        Transform h = Head();
        if (h == null) return false;
        Vector3 to = transform.position - h.position;
        return to.magnitude > 3f || Vector3.Angle(Flat(h.forward), Flat(to)) > 70f;
    }

    /// <summary>Riporta il pannello nella posizione "da scrivania" davanti a te.</summary>
    public void Recenter()
    {
        _pinned = false;
        _placed = false;
    }

    // ── Maniglia per spostare il pannello ─────────────────────────────

    void SetupGrab()
    {
        var rb = gameObject.AddComponent<Rigidbody>();
        rb.isKinematic = true;
        rb.useGravity = false;

        var colGo = new GameObject("GrabHandle");
        colGo.transform.SetParent(transform, false);
        var col = colGo.AddComponent<BoxCollider>();
        col.size = new Vector3(0.24f, 0.06f, 0.03f);
        _handleCollider = colGo.transform;

        _grab = gameObject.AddComponent<XRGrabInteractable>();
        _grab.movementType = XRBaseInteractable.MovementType.Instantaneous;
        _grab.trackRotation = false;   // la rotazione la gestiamo noi
        _grab.throwOnDetach = false;
        _grab.useDynamicAttach = true;
        _grab.selectEntered.AddListener(_ => _grabbed = true);
        _grab.selectExited.AddListener(_ => { _grabbed = false; _pinned = true; });
    }

    void UpdateHandle(float dt)
    {
        if (_handleRt == null) return;

        float panelH = _minimized ? IconSize : !_showCard ? PillH : _state == PipelineState.Preview ? PreviewH : CardH;
        float y = -(panelH / 2f + 22f);
        var p = _handleRt.anchoredPosition;
        p.y = Mathf.Lerp(p.y, y, dt * 10f);
        _handleRt.anchoredPosition = p;

        if (_handleCollider != null) _handleCollider.localPosition = new Vector3(0f, p.y * 0.001f, 0.005f);

        bool active = _grab != null && (_grab.isHovered || _grabbed);
        var c = _handle.color;
        c.a = Mathf.MoveTowards(c.a, active ? 0.9f : 0.35f, dt * 4f);
        _handle.color = c;
        _handleRt.localScale = Vector3.Lerp(_handleRt.localScale, Vector3.one * (active ? 1.25f : 1f), dt * 10f);
    }

    // ── Aptica ────────────────────────────────────────────────────────

    void Haptic(float amplitude, float duration)
    {
        if (!haptics) return;
        var device = InputDevices.GetDeviceAtXRNode(XRNode.RightHand);
        if (device.isValid && device.TryGetHapticCapabilities(out var caps) && caps.supportsImpulse)
            device.SendHapticImpulse(0, amplitude, duration);
    }

    IEnumerator DoubleHaptic()
    {
        Haptic(0.5f, 0.06f);
        yield return new WaitForSecondsRealtime(0.12f);
        Haptic(0.5f, 0.06f);
    }

    // ── Costruzione UI (unità canvas ≈ millimetri) ────────────────────

    void BuildUI()
    {
        var canvasGo = new GameObject("StatusCanvas", typeof(RectTransform), typeof(Canvas), typeof(TrackedDeviceGraphicRaycaster));
        canvasGo.transform.SetParent(transform, false);
        canvasGo.GetComponent<Canvas>().renderMode = RenderMode.WorldSpace;
        var root = (RectTransform)canvasGo.transform;
        root.sizeDelta = new Vector2(CardW, CardH);
        root.localScale = Vector3.one * 0.001f;

        // ── Pillola (attesa) ──
        var pillRt = Panel(root, "IdlePill", PillW, PillH, PillBg, out _pill, 24f / 36f);
        _micDot = Img(pillRt, "MicDot", _circle, Accent, false);
        Place(_micDot.rectTransform, 28, 29, 14, 14);
        _micDot.rectTransform.pivot = new Vector2(0.5f, 0.5f);
        _micDot.rectTransform.anchoredPosition = new Vector2(35, -36);
        _hint = Txt(pillRt, "Hint", 24, FontStyles.Normal, TextMain, TextAlignmentOptions.MidlineLeft);
        Place(_hint.rectTransform, 56, 0, PillW - 56 - 66, PillH);
        _hint.text = idleHint;
        MakeRoundButton(pillRt, "MinimizePill", "–", PillW - 54, 18, 36, ToggleMinimized);

        // ── Card (richiesta in corso) ──
        var cardRt = Panel(root, "Card", CardW, CardH, CardBg, out _card, 1f);

        _statusDot = Img(cardRt, "StatusDot", _circle, Accent, false);
        Place(_statusDot.rectTransform, 28, 30, 14, 14);

        _title = Txt(cardRt, "Title", 30, FontStyles.Bold, TextMain, TextAlignmentOptions.MidlineLeft);
        Place(_title.rectTransform, 52, 16, 340, 42);

        _timer = Txt(cardRt, "Timer", 36, FontStyles.Bold, TextMain, TextAlignmentOptions.MidlineRight);
        Place(_timer.rectTransform, 396, 12, 172, 46);

        MakeRoundButton(cardRt, "MinimizeCard", "–", 584, 17, 36, ToggleMinimized);

        _subline = Txt(cardRt, "Subline", 18, FontStyles.Normal, TextDim, TextAlignmentOptions.TopRight);
        Place(_subline.rectTransform, 248, 58, 320, 26);

        _label = Txt(cardRt, "Label", 16, FontStyles.Bold, TextDim, TextAlignmentOptions.TopLeft);
        _label.characterSpacing = 8f;
        Place(_label.rectTransform, 28, 72, 260, 24);

        _quote = Txt(cardRt, "Quote", 28, FontStyles.Normal, TextMain, TextAlignmentOptions.TopLeft);
        Place(_quote.rectTransform, 28, 96, 584, 70);

        const float colW = 146f, startX = 28f, dotY = 176f, dot = 16f;
        for (int i = 0; i < 4; i++)
        {
            float cx = startX + colW * i + colW / 2f;
            _stepDots[i] = Img(cardRt, $"StepDot{i}", _circle, Pending, false);
            Place(_stepDots[i].rectTransform, cx - dot / 2f, dotY, dot, dot);
            _stepDots[i].rectTransform.pivot = new Vector2(0.5f, 0.5f);
            _stepDots[i].rectTransform.anchoredPosition = new Vector2(cx, -(dotY + dot / 2f));

            _stepLabels[i] = Txt(cardRt, $"StepLabel{i}", 17, FontStyles.Normal, TextDim, TextAlignmentOptions.Top);
            Place(_stepLabels[i].rectTransform, startX + colW * i, dotY + 24, colW, 24);
            _stepLabels[i].text = StepNames[i];

            if (i < 3)
            {
                _stepLinks[i] = Img(cardRt, $"StepLink{i}", null, Pending, false);
                Place(_stepLinks[i].rectTransform, cx + 14, dotY + dot / 2f - 1, colW - 28, 2);
            }
        }

        var barBg = Img(cardRt, "BarBg", _rounded, Pending, true, 8f);
        Place(barBg.rectTransform, 28, 236, 584, 6);
        _barFill = Img(barBg.rectTransform, "BarFill", _rounded, Accent, true, 8f);
        _barFillRt = _barFill.rectTransform;
        _barFillRt.anchorMin = Vector2.zero;
        _barFillRt.anchorMax = new Vector2(0.02f, 1f);
        _barFillRt.pivot = new Vector2(0f, 0.5f);
        _barFillRt.offsetMin = Vector2.zero;
        _barFillRt.offsetMax = Vector2.zero;

        _footer = Txt(cardRt, "Footer", 18, FontStyles.Normal, TextDim, TextAlignmentOptions.MidlineLeft);
        Place(_footer.rectTransform, 28, 252, 420, 36);
        _footer.text = "<b>A</b>  riduci a icona";

        _cancelButton = MakeButton(cardRt, "CancelButton", "Annulla", 482, 252, 130, 36,
                                   () => { if (generator != null) generator.CancelRequest(); });
        _cancelButton.SetActive(false);

        // ── Anteprima (immagine + scelta) ──
        var pvRt = Panel(root, "Preview", PreviewW, PreviewH, CardBg, out _preview, 1f);

        _pvDot = Img(pvRt, "PreviewDot", _circle, Ok, false);
        Place(_pvDot.rectTransform, 28, 30, 14, 14);
        _pvDot.rectTransform.pivot = new Vector2(0.5f, 0.5f);
        _pvDot.rectTransform.anchoredPosition = new Vector2(35, -37);

        _pvTitle = Txt(pvRt, "Title", 30, FontStyles.Bold, TextMain, TextAlignmentOptions.MidlineLeft);
        Place(_pvTitle.rectTransform, 52, 16, 340, 42);
        _pvTimer = Txt(pvRt, "Timer", 36, FontStyles.Bold, TextMain, TextAlignmentOptions.MidlineRight);
        Place(_pvTimer.rectTransform, 396, 12, 172, 46);
        MakeRoundButton(pvRt, "MinimizePreview", "–", 584, 17, 36, ToggleMinimized);
        _pvSub = Txt(pvRt, "Subline", 18, FontStyles.Normal, TextDim, TextAlignmentOptions.TopRight);
        Place(_pvSub.rectTransform, 248, 58, 320, 26);

        var frame = Img(pvRt, "ImageFrame", _rounded, Pending, true, 24f / 12f);
        Place(frame.rectTransform, 28, 80, 300, 300);
        var imgGo = new GameObject("PreviewImage", typeof(RectTransform), typeof(RawImage));
        imgGo.transform.SetParent(frame.rectTransform, false);
        _previewImage = imgGo.GetComponent<RawImage>();
        _previewImage.raycastTarget = false;
        var irt = _previewImage.rectTransform;
        irt.anchorMin = Vector2.zero; irt.anchorMax = Vector2.one;
        irt.offsetMin = new Vector2(4, 4); irt.offsetMax = new Vector2(-4, -4);
        _pvNoImage = Txt(frame.rectTransform, "NoImage", 18, FontStyles.Normal, TextDim, TextAlignmentOptions.Center);
        Stretch(_pvNoImage.rectTransform);
        _pvNoImage.text = "Anteprima non disponibile";

        var lbl1 = Txt(pvRt, "LabelRequest", 16, FontStyles.Bold, TextDim, TextAlignmentOptions.TopLeft);
        lbl1.characterSpacing = 8f;
        Place(lbl1.rectTransform, 348, 80, 264, 24);
        lbl1.text = "HAI CHIESTO";
        _pvRequest = Txt(pvRt, "Request", 22, FontStyles.Normal, TextMain, TextAlignmentOptions.TopLeft);
        Place(_pvRequest.rectTransform, 348, 104, 264, 110);

        var lbl2 = Txt(pvRt, "LabelPrompt", 16, FontStyles.Bold, TextDim, TextAlignmentOptions.TopLeft);
        lbl2.characterSpacing = 8f;
        Place(lbl2.rectTransform, 348, 224, 264, 24);
        lbl2.text = "PROMPT";
        _pvPrompt = Txt(pvRt, "Prompt", 15, FontStyles.Normal, TextDim, TextAlignmentOptions.TopLeft);
        Place(_pvPrompt.rectTransform, 348, 248, 264, 132);

        _pvHint = Txt(pvRt, "Hint", 18, FontStyles.Normal, TextDim, TextAlignmentOptions.MidlineLeft);
        Place(_pvHint.rectTransform, 28, 384, 584, 30);

        var correct = MakeButton(pvRt, "CorrectButton", "Correggi", 28, 420, 136, 36,
                                 () => { if (generator != null) generator.StartCorrectionRecording(); });
        _pvCorrectLabel = correct.GetComponentInChildren<TextMeshProUGUI>();
        MakeButton(pvRt, "RetryButton", "Ripeti", 176, 420, 136, 36,
                   () => { if (generator != null) generator.RetryImage(); });
        MakeButton(pvRt, "PreviewCancelButton", "Annulla", 324, 420, 136, 36,
                   () => { if (generator != null) generator.CancelRequest(); });
        var proceed = MakeButton(pvRt, "ProceedButton", "Prosegui", 472, 420, 140, 36,
                                 () => { if (generator != null) generator.ProceedToModel(); });
        proceed.GetComponent<Image>().color = new Color(Ok.r, Ok.g, Ok.b, 0.55f);

        // ── Icona (pannello ridotto) ──
        var iconRt = Panel(root, "Icon", IconSize, IconSize, CardBg, out _icon, 1f);
        var iconImg = iconRt.GetComponent<Image>();
        iconImg.sprite = _circle;
        iconImg.type = Image.Type.Simple;
        iconImg.raycastTarget = true;
        var iconBtn = iconRt.gameObject.AddComponent<Button>();
        iconBtn.targetGraphic = iconImg;
        iconBtn.onClick.AddListener(() => SetMinimized(false));
        _iconDot = Img(iconRt, "IconDot", _circle, Accent, false);
        _iconDot.rectTransform.anchorMin = _iconDot.rectTransform.anchorMax = new Vector2(0.5f, 0.5f);
        _iconDot.rectTransform.pivot = new Vector2(0.5f, 0.5f);
        _iconDot.rectTransform.sizeDelta = new Vector2(24, 24);
        _iconDot.rectTransform.anchoredPosition = Vector2.zero;

        // ── Maniglia sotto il pannello ──
        _handle = Img(root, "Handle", _rounded, new Color(1f, 1f, 1f, 0.35f), true, 24f / 5f);
        _handleRt = _handle.rectTransform;
        _handleRt.sizeDelta = new Vector2(110, 10);
        _handleRt.anchoredPosition = new Vector2(0, -(PillH / 2f + 22f));
        _handle.gameObject.SetActive(movable);
    }

    GameObject MakeButton(RectTransform parent, string name, string label, float x, float y, float w, float h, System.Action onClick)
    {
        var img = Img(parent, name, _rounded, new Color(1f, 1f, 1f, 0.10f), true, 24f / 18f);
        img.raycastTarget = true;
        Place(img.rectTransform, x, y, w, h);
        AddButton(img, onClick);

        var t = Txt(img.rectTransform, "Label", 20, FontStyles.Bold, TextMain, TextAlignmentOptions.Center);
        Stretch(t.rectTransform);
        t.text = label;
        return img.gameObject;
    }

    GameObject MakeRoundButton(RectTransform parent, string name, string glyph, float x, float y, float size, System.Action onClick)
    {
        var img = Img(parent, name, _circle, new Color(1f, 1f, 1f, 0.10f), false);
        img.raycastTarget = true;
        Place(img.rectTransform, x, y, size, size);
        AddButton(img, onClick);

        var t = Txt(img.rectTransform, "Glyph", 26, FontStyles.Bold, TextMain, TextAlignmentOptions.Center);
        Stretch(t.rectTransform);
        t.text = glyph;
        return img.gameObject;
    }

    static void AddButton(Image img, System.Action onClick)
    {
        var btn = img.gameObject.AddComponent<Button>();
        var colors = btn.colors;
        colors.normalColor = Color.white;
        colors.highlightedColor = new Color(1.6f, 1.6f, 1.6f, 1f);
        colors.pressedColor = new Color(2.2f, 2.2f, 2.2f, 1f);
        colors.colorMultiplier = 2f;
        btn.colors = colors;
        btn.targetGraphic = img;
        btn.onClick.AddListener(() => onClick());
    }

    static void Stretch(RectTransform rt)
    {
        rt.anchorMin = Vector2.zero;
        rt.anchorMax = Vector2.one;
        rt.offsetMin = Vector2.zero;
        rt.offsetMax = Vector2.zero;
    }

    RectTransform Panel(RectTransform parent, string name, float w, float h, Color bg, out CanvasGroup group, float cornerMul)
    {
        var go = new GameObject(name, typeof(RectTransform), typeof(CanvasGroup), typeof(Image));
        go.transform.SetParent(parent, false);
        var rt = (RectTransform)go.transform;
        rt.sizeDelta = new Vector2(w, h);
        var img = go.GetComponent<Image>();
        img.sprite = _rounded;
        img.type = Image.Type.Sliced;
        img.pixelsPerUnitMultiplier = cornerMul;
        img.color = bg;
        img.raycastTarget = false;
        group = go.GetComponent<CanvasGroup>();
        group.interactable = false;
        group.blocksRaycasts = false;
        return rt;
    }

    static Image Img(RectTransform parent, string name, Sprite sprite, Color color, bool sliced, float cornerMul = 1f)
    {
        var go = new GameObject(name, typeof(RectTransform), typeof(Image));
        go.transform.SetParent(parent, false);
        var img = go.GetComponent<Image>();
        img.sprite = sprite;
        img.type = sliced ? Image.Type.Sliced : Image.Type.Simple;
        img.pixelsPerUnitMultiplier = cornerMul;
        img.color = color;
        img.raycastTarget = false;
        return img;
    }

    static TextMeshProUGUI Txt(RectTransform parent, string name, float size, FontStyles style, Color color, TextAlignmentOptions align)
    {
        var go = new GameObject(name, typeof(RectTransform), typeof(TextMeshProUGUI));
        go.transform.SetParent(parent, false);
        var t = go.GetComponent<TextMeshProUGUI>();
        t.fontSize = size;
        t.fontStyle = style;
        t.color = color;
        t.alignment = align;
        t.textWrappingMode = TextWrappingModes.Normal;
        t.overflowMode = TextOverflowModes.Ellipsis;
        t.richText = true;
        t.raycastTarget = false;
        return t;
    }

    static void Place(RectTransform rt, float x, float y, float w, float h)
    {
        rt.anchorMin = rt.anchorMax = new Vector2(0f, 1f);
        rt.pivot = new Vector2(0f, 1f);
        rt.anchoredPosition = new Vector2(x, -y);
        rt.sizeDelta = new Vector2(w, h);
    }

    static Sprite MakeRoundedSprite(int size, int radius)
    {
        var tex = new Texture2D(size, size, TextureFormat.RGBA32, false)
        {
            wrapMode = TextureWrapMode.Clamp,
            filterMode = FilterMode.Bilinear
        };
        var px = new Color32[size * size];
        for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
        {
            float fx = x + 0.5f, fy = y + 0.5f;
            float dx = Mathf.Max(radius - fx, fx - (size - radius), 0f);
            float dy = Mathf.Max(radius - fy, fy - (size - radius), 0f);
            float d = Mathf.Sqrt(dx * dx + dy * dy);
            byte a = (byte)(Mathf.Clamp01(radius - d + 0.5f) * 255f);
            px[y * size + x] = new Color32(255, 255, 255, a);
        }
        tex.SetPixels32(px);
        tex.Apply(false, true);

        return Sprite.Create(tex, new Rect(0, 0, size, size), new Vector2(0.5f, 0.5f), 100f, 0,
                             SpriteMeshType.FullRect, new Vector4(radius, radius, radius, radius));
    }
}
