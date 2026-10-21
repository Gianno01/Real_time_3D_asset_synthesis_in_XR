// GenerationStatusUI.cs
// Interfaccia minimale in world space per QuestObjectGenerator.
//
//  • In attesa  → una "pillola" discreta con l'istruzione su come inviare la richiesta
//  • In corso   → una card con: stato, cosa hai chiesto, 4 step (Voce · Testo · Modello 3D · Caricamento),
//                 tempo trascorso dall'invio, stima del tempo rimanente e barra di avanzamento
//  • Esito      → conferma verde (o errore rosso con il motivo), poi torna alla pillola
//  • Feedback aptico sul controller destro: invio, successo, errore
//  • Pulsante "–" per ridurre a icona: l'icona mostra comunque lo stato e, puntata e premuta, riapre la finestra
//
// SETUP: GameObject vuoto (es. "StatusUI") + questo componente. La UI è generata via codice.
// Richiede: TextMeshPro (TMP Essential Resources) e QuestObjectGenerator con StateChanged/State.
// I pulsanti si premono con il raggio di controller/mani XRI (serve un EventSystem con XRUIInputModule).

using System.Collections;
using TMPro;
using UnityEngine;
using UnityEngine.Events;
using UnityEngine.EventSystems;
using UnityEngine.InputSystem;
using UnityEngine.UI;
using UnityEngine.XR;
using UnityEngine.XR.Interaction.Toolkit.UI;

public class GenerationStatusUI : MonoBehaviour
{
    [Header("Riferimenti")]
    [Tooltip("Se vuoto viene cercato nella scena")]
    public QuestObjectGenerator generator;
    [Tooltip("Se vuoto usa la testa del generator (Main Camera dell'XR Origin)")]
    public Transform head;

    [Header("Testi")]
    [TextArea]
    public string idleHint = "Premi il <b>grilletto destro</b> e di' il nome di un oggetto";
    [TextArea]
    [Tooltip("Mostrato al posto di Idle Hint quando il generator è in modalità mani libere")]
    public string handsFreeHint = "Di' <b>\"Genera...\"</b> seguito dall'oggetto, ad esempio <i>\"Genera una sedia di legno\"</i>";

    [Header("Posizionamento")]
    public float distance = 1.0f;
    public float heightOffset = -0.30f;
    [Tooltip("Più alto = il pannello segue lo sguardo più rapidamente")]
    public float followSpeed = 2.5f;

    [Header("Comportamento")]
    public bool showIdleHint = true;
    public float showDoneSeconds = 6f;
    public float showErrorSeconds = 10f;
    public bool haptics = true;

    [Header("Riduci a icona")]
    public bool startMinimized = false;
    [Tooltip("Opzionale: azione che alterna finestra/icona. Se vuoto usa Toggle Binding")]
    public InputActionReference toggleMinimizeButton;
    [Tooltip("Binding usato se Toggle Minimize Button è vuoto (default: tasto A del controller destro)")]
    public string toggleBinding = "<XRController>{RightHand}/primaryButton";

    InputAction _toggleAction;

    /// <summary>True mentre il raggio punta un pulsante del pannello: il generator ignora il grilletto.</summary>
    public static bool IsPointerOverUI => _hoverCount > 0;
    static int _hoverCount;

    // ── Palette ───────────────────────────────────────────────────────

    static readonly Color CardBg   = new Color(0.07f, 0.08f, 0.11f, 0.92f);
    static readonly Color PillBg   = new Color(0.07f, 0.08f, 0.11f, 0.78f);
    static readonly Color TextMain = new Color(0.95f, 0.96f, 0.98f);
    static readonly Color TextDim  = new Color(0.60f, 0.64f, 0.72f);
    static readonly Color Pending  = new Color(1f, 1f, 1f, 0.16f);
    static readonly Color Accent   = new Color(0.40f, 0.64f, 1.00f);
    static readonly Color Ok       = new Color(0.33f, 0.86f, 0.56f);
    static readonly Color Bad      = new Color(1.00f, 0.43f, 0.41f);
    static readonly Color ButtonBg = new Color(0.20f, 0.22f, 0.28f, 0.95f);

    static readonly string[] StepNames = { "Voce", "Testo", "Modello 3D", "Caricamento" };

    // ── Riferimenti UI ────────────────────────────────────────────────

    Sprite _rounded, _circle;
    CanvasGroup _pill, _card;
    TextMeshProUGUI _hint, _title, _timer, _subline, _label, _quote;
    Image _statusDot, _barFill, _micDot;
    RectTransform _barFillRt;
    readonly Image[] _stepDots = new Image[4];
    readonly TextMeshProUGUI[] _stepLabels = new TextMeshProUGUI[4];
    readonly Image[] _stepLinks = new Image[3];
    CanvasGroup _minBtn, _icon;
    RectTransform _minBtnRt;
    Image _iconDot;
    TextMeshProUGUI _iconTimer;

    // ── Stato locale ──────────────────────────────────────────────────

    PipelineState _state = PipelineState.Idle;
    int _activeStep = -1, _failedStep = -1;
    float _requestStart = -1f, _finalElapsed, _stateShownAt, _nextText;
    bool _showCard, _placed, _minimized;
    Color _accentNow = Accent;

    // Angolo in alto a destra (sopra il pannello) dove sta il pulsante "–"
    static readonly Vector2 PillButtonPos = new Vector2(288, 66);
    static readonly Vector2 CardButtonPos = new Vector2(298, 158);

    // ── Lifecycle ─────────────────────────────────────────────────────

    void Awake()
    {
        _rounded = MakeRoundedSprite(64, 24);
        _circle = MakeRoundedSprite(64, 32);
        BuildUI();
        _pill.alpha = 0f;
        _card.alpha = 0f;
        _minimized = startMinimized;
    }

    void OnEnable()
    {
        if (toggleMinimizeButton != null && toggleMinimizeButton.action != null)
            _toggleAction = toggleMinimizeButton.action;
        else if (!string.IsNullOrEmpty(toggleBinding))
            _toggleAction ??= new InputAction("ToggleMinimize", InputActionType.Button, toggleBinding);

        if (_toggleAction != null)
        {
            _toggleAction.Enable();
            _toggleAction.performed += OnToggleMinimize;
        }
    }

    void OnDisable()
    {
        if (_toggleAction != null) _toggleAction.performed -= OnToggleMinimize;
        _hoverCount = 0;
    }

    void OnToggleMinimize(InputAction.CallbackContext _) => SetMinimized(!_minimized);

    public void SetMinimized(bool minimized)
    {
        if (_minimized == minimized) return;
        _minimized = minimized;
        _nextText = 0f;
        Haptic(0.3f, 0.04f);
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
        if (toggleMinimizeButton == null) _toggleAction?.Dispose();   // creata da codice
    }

    void LateUpdate()
    {
        float now = Time.realtimeSinceStartup;
        float dt = Time.unscaledDeltaTime;

        // Dopo l'esito torna alla pillola
        if (_showCard &&
            ((_state == PipelineState.Done && now - _stateShownAt > showDoneSeconds) ||
             (_state == PipelineState.Error && now - _stateShownAt > showErrorSeconds)))
        {
            _showCard = false;
            _state = PipelineState.Idle;
        }

        bool cardOn = _showCard && !_minimized;
        bool pillOn = !_showCard && showIdleHint && !_minimized;
        _card.alpha = Mathf.MoveTowards(_card.alpha, cardOn ? 1f : 0f, dt * 5f);
        _pill.alpha = Mathf.MoveTowards(_pill.alpha, pillOn ? 1f : 0f, dt * 3f);
        FadeButton(_minBtn, cardOn || pillOn, dt);
        FadeButton(_icon, _minimized, dt);
        if (_card.alpha <= 0f && _pill.alpha <= 0f && _icon.alpha <= 0f) return;

        Follow(!_placed);
        _placed = true;

        _minBtnRt.anchoredPosition = Vector2.Lerp(_minBtnRt.anchoredPosition,
                                                  _showCard ? CardButtonPos : PillButtonPos, dt * 10f);

        // Pillola: il pallino del microfono reagisce alla voce mentre l'app ascolta
        if (_pill.alpha > 0f) MicPulse(_micDot, dt);

        // Icona: stessa logica della pillola in attesa, colore/pulsazione della card durante una richiesta
        if (_icon.alpha > 0f)
        {
            bool working = _showCard && _state != PipelineState.Done && _state != PipelineState.Error;
            if (_showCard)
            {
                var c = _accentNow;
                if (working) c.a = 0.55f + 0.45f * Mathf.Sin(now * 5f);
                _iconDot.color = c;
                _iconDot.rectTransform.localScale = Vector3.one;
            }
            else MicPulse(_iconDot, dt);

            _iconTimer.text = working && _requestStart >= 0f ? QuestObjectGenerator.FormatTime(Elapsed(now)) : "";
        }

        if (_card.alpha > 0f)
        {
            UpdateSteps(now);
            UpdateBar(now, dt);
            if (now >= _nextText) { _nextText = now + 0.25f; UpdateTimeTexts(now); }
        }
    }

    // ── Eventi dal generator ──────────────────────────────────────────

    void OnStateChanged(PipelineState state, string detail)
    {
        float now = Time.realtimeSinceStartup;
        _state = state;
        _stateShownAt = now;
        _nextText = 0f;
        if (state != PipelineState.Error) _failedStep = -1;

        switch (state)
        {
            case PipelineState.Recording:
                _requestStart = -1f;
                _activeStep = 0;
                Show("Ti ascolto...", "PARLA ORA",
                     "Pronuncia il nome di un oggetto: l'invio parte da solo dopo una breve pausa.", Accent);
                Haptic(0.25f, 0.05f);
                break;

            case PipelineState.Transcribing:
                _requestStart = now;
                _activeStep = 1;
                Show("Richiesta inviata", "AUDIO INVIATO", detail, Accent);
                Haptic(0.6f, 0.08f);
                break;

            case PipelineState.Generating:
                if (_requestStart < 0f) _requestStart = now; // es. test da tastiera senza voce
                _activeStep = 2;
                Show("Sto creando l'oggetto", "HAI CHIESTO", $"\"{detail}\"", Accent);
                break;

            case PipelineState.Downloading:
            case PipelineState.Loading:
                _activeStep = 3;
                Show("Quasi pronto...", "HAI CHIESTO", $"\"{generator.LastTranscript}\"", Accent);
                break;

            case PipelineState.Done:
                _finalElapsed = Elapsed(now);
                _activeStep = 4;
                Show($"Creato: {generator.LastObjectName}", "HAI CHIESTO", $"\"{generator.LastTranscript}\"", Ok);
                StartCoroutine(DoubleHaptic());
                break;

            case PipelineState.Error:
                _finalElapsed = Elapsed(now);
                _failedStep = Mathf.Clamp(_activeStep, 0, 3);
                Show("Qualcosa è andato storto", "ERRORE", detail, Bad);
                Haptic(0.8f, 0.25f);
                break;

            default:
                _showCard = false;
                break;
        }
    }

    void Show(string title, string label, string quote, Color accent)
    {
        if (!_showCard) Follow(true);
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

    void MicPulse(Image dot, float dt)
    {
        bool listening = generator.IsListening;
        float s = listening ? 1f + Mathf.Clamp01(generator.MicLevel * 6f) * 0.9f : 1f;
        dot.rectTransform.localScale = Vector3.Lerp(dot.rectTransform.localScale, Vector3.one * s, dt * 15f);
        dot.color = listening ? Accent : TextDim;
    }

    // Un pulsante nascosto non deve intercettare il raggio
    static void FadeButton(CanvasGroup group, bool visible, float dt)
    {
        group.alpha = Mathf.MoveTowards(group.alpha, visible ? 1f : 0f, dt * 5f);
        group.interactable = group.blocksRaycasts = visible && group.alpha > 0.5f;
    }

    void UpdateTimeTexts(float now)
    {
        string F(float s) => QuestObjectGenerator.FormatTime(s);

        switch (_state)
        {
            case PipelineState.Recording:
                _timer.text = F(now - _stateShownAt);
                _subline.text = "registrazione";
                break;

            case PipelineState.Transcribing:
                _timer.text = F(Elapsed(now));
                _subline.text = "trascrizione in corso";
                break;

            case PipelineState.Generating:
                _timer.text = F(Elapsed(now));
                float est = generator.EstimatedGenerationSeconds;
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
                _subline.text = "premi di nuovo per riprovare";
                break;
        }
    }

    void UpdateSteps(float now)
    {
        float pulse = 1f + 0.22f * (0.5f + 0.5f * Mathf.Sin(now * 6f));

        for (int i = 0; i < 4; i++)
        {
            Color c;
            float scale = 1f;

            if (_state == PipelineState.Error && i == _failedStep) c = Bad;
            else if (i < _activeStep) c = Ok;
            else if (i == _activeStep && _state != PipelineState.Error) { c = Accent; scale = pulse; }
            else c = Pending;

            _stepDots[i].color = c;
            _stepDots[i].rectTransform.localScale = Vector3.one * scale;
            _stepLabels[i].color = (i <= _activeStep || i == _failedStep) ? TextMain : TextDim;

            if (i < 3) _stepLinks[i].color = i < _activeStep ? Ok : Pending;
        }

        // Pallino di stato nell'intestazione: pulsa mentre lavora
        bool working = _state != PipelineState.Done && _state != PipelineState.Error;
        var sc = _accentNow;
        sc.a = working ? 0.55f + 0.45f * Mathf.Sin(now * 5f) : 1f;
        _statusDot.color = sc;
    }

    void UpdateBar(float now, float dt)
    {
        float target;
        switch (_state)
        {
            case PipelineState.Recording:
                target = Mathf.Clamp01(generator.MicLevel * 4f);  // volume della voce
                break;
            case PipelineState.Generating:
                float est = generator.EstimatedGenerationSeconds;
                float genEl = now - generator.StateStartTime;
                target = est > 0f ? Mathf.Lerp(0.25f, 0.95f, Mathf.Clamp01(genEl / est))
                                  : 0.25f + 0.1f * Mathf.PingPong(now * 0.5f, 1f);
                break;
            case PipelineState.Transcribing: target = 0.15f; break;
            case PipelineState.Downloading:
            case PipelineState.Loading:      target = 0.97f; break;
            default:                         target = 1f; break;   // Done / Error
        }

        float x = Mathf.Lerp(_barFillRt.anchorMax.x, target, dt * 8f);
        _barFillRt.anchorMax = new Vector2(Mathf.Max(x, 0.02f), 1f);
    }

    // ── Posizionamento (lazy follow) ──────────────────────────────────

    void Follow(bool snap)
    {
        Transform h = head != null ? head : generator != null ? generator.Head : null;
        if (h == null) return;

        Vector3 flat = Vector3.ProjectOnPlane(h.forward, Vector3.up);
        if (flat.sqrMagnitude < 0.0001f) flat = Vector3.forward;
        flat.Normalize();

        Vector3 target = h.position + flat * distance + Vector3.up * heightOffset;
        float t = snap ? 1f : 1f - Mathf.Exp(-followSpeed * Time.unscaledDeltaTime);
        transform.position = Vector3.Lerp(transform.position, target, t);

        Vector3 look = transform.position - h.position;
        if (look.sqrMagnitude > 0.0001f) transform.rotation = Quaternion.LookRotation(look, Vector3.up);
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

    // ── Costruzione UI ────────────────────────────────────────────────
    // Unità del canvas ≈ millimetri (scala 0.001)

    void BuildUI()
    {
        var canvasGo = new GameObject("StatusCanvas", typeof(RectTransform), typeof(Canvas), typeof(TrackedDeviceGraphicRaycaster));
        canvasGo.transform.SetParent(transform, false);
        canvasGo.GetComponent<Canvas>().renderMode = RenderMode.WorldSpace;
        var root = (RectTransform)canvasGo.transform;
        root.sizeDelta = new Vector2(640, 256);
        root.localScale = Vector3.one * 0.001f;

        // ── Pillola (stato di attesa) ──
        var pillRt = Panel(root, "IdlePill", 620, 72, PillBg, out _pill, 24f / 36f);
        _micDot = Img(pillRt, "MicDot", _circle, Accent, false);
        Place(_micDot.rectTransform, 28, 29, 14, 14);
        _micDot.rectTransform.pivot = new Vector2(0.5f, 0.5f);
        _micDot.rectTransform.anchoredPosition = new Vector2(35, -36);
        _hint = Txt(pillRt, "Hint", 24, FontStyles.Normal, TextMain, TextAlignmentOptions.MidlineLeft);
        Place(_hint.rectTransform, 56, 0, 546, 72);
        _hint.text = idleHint;

        // ── Card (richiesta in corso) ──
        var cardRt = Panel(root, "Card", 640, 256, CardBg, out _card, 1f);

        _statusDot = Img(cardRt, "StatusDot", _circle, Accent, false);
        Place(_statusDot.rectTransform, 28, 30, 14, 14);

        _title = Txt(cardRt, "Title", 30, FontStyles.Bold, TextMain, TextAlignmentOptions.MidlineLeft);
        Place(_title.rectTransform, 52, 16, 380, 42);

        _timer = Txt(cardRt, "Timer", 36, FontStyles.Bold, TextMain, TextAlignmentOptions.MidlineRight);
        Place(_timer.rectTransform, 432, 12, 180, 46);

        _subline = Txt(cardRt, "Subline", 18, FontStyles.Normal, TextDim, TextAlignmentOptions.TopRight);
        Place(_subline.rectTransform, 292, 58, 320, 26);

        _label = Txt(cardRt, "Label", 16, FontStyles.Bold, TextDim, TextAlignmentOptions.TopLeft);
        _label.characterSpacing = 8f;
        Place(_label.rectTransform, 28, 72, 260, 24);

        _quote = Txt(cardRt, "Quote", 28, FontStyles.Normal, TextMain, TextAlignmentOptions.TopLeft);
        Place(_quote.rectTransform, 28, 96, 584, 70);

        // Step: 4 colonne con pallino + etichetta, collegati da una linea
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

        // Barra di avanzamento
        var barBg = Img(cardRt, "BarBg", _rounded, Pending, true, 8f);
        Place(barBg.rectTransform, 28, 236, 584, 6);
        _barFill = Img(barBg.rectTransform, "BarFill", _rounded, Accent, true, 8f);
        _barFillRt = _barFill.rectTransform;
        _barFillRt.anchorMin = Vector2.zero;
        _barFillRt.anchorMax = new Vector2(0.02f, 1f);
        _barFillRt.pivot = new Vector2(0f, 0.5f);
        _barFillRt.offsetMin = Vector2.zero;
        _barFillRt.offsetMax = Vector2.zero;

        // ── Pulsante "–" (riduci a icona), sopra l'angolo in alto a destra ──
        _minBtnRt = RoundButton(root, "MinimizeButton", 44, out _minBtn, () => SetMinimized(true));
        _minBtnRt.anchoredPosition = PillButtonPos;
        var glyph = Img(_minBtnRt, "Glyph", null, TextMain, false);
        glyph.rectTransform.sizeDelta = new Vector2(18, 3);

        // ── Icona (finestra ridotta): premila per riaprire ──
        var iconRt = RoundButton(root, "MinimizedIcon", 64, out _icon, () => SetMinimized(false));
        _iconDot = Img(iconRt, "Dot", _circle, Accent, false);
        _iconDot.rectTransform.sizeDelta = new Vector2(20, 20);
        _iconTimer = Txt(iconRt, "Timer", 20, FontStyles.Bold, TextDim, TextAlignmentOptions.Top);
        _iconTimer.rectTransform.anchoredPosition = new Vector2(0, -50);
        _iconTimer.rectTransform.sizeDelta = new Vector2(120, 28);
    }

    // Pulsante rotondo cliccabile col raggio XR; tiene il conto dell'hover per IsPointerOverUI
    RectTransform RoundButton(RectTransform parent, string name, float size, out CanvasGroup group, UnityAction onClick)
    {
        var go = new GameObject(name, typeof(RectTransform), typeof(CanvasGroup), typeof(Image), typeof(Button), typeof(EventTrigger));
        go.transform.SetParent(parent, false);
        var rt = (RectTransform)go.transform;
        rt.sizeDelta = new Vector2(size, size);

        var img = go.GetComponent<Image>();
        img.sprite = _circle;
        img.color = ButtonBg;

        var btn = go.GetComponent<Button>();
        btn.targetGraphic = img;
        btn.navigation = new Navigation { mode = Navigation.Mode.None };
        var colors = btn.colors;
        colors.normalColor = colors.selectedColor = new Color(0.8f, 0.8f, 0.8f);
        colors.highlightedColor = Color.white;
        colors.pressedColor = new Color(0.6f, 0.6f, 0.6f);
        btn.colors = colors;
        btn.onClick.AddListener(onClick);

        var trigger = go.GetComponent<EventTrigger>();
        AddTrigger(trigger, EventTriggerType.PointerEnter, () => _hoverCount++);
        AddTrigger(trigger, EventTriggerType.PointerExit, () => _hoverCount = Mathf.Max(0, _hoverCount - 1));

        group = go.GetComponent<CanvasGroup>();
        group.alpha = 0f;
        group.interactable = group.blocksRaycasts = false;
        return rt;
    }

    static void AddTrigger(EventTrigger trigger, EventTriggerType type, UnityAction action)
    {
        var entry = new EventTrigger.Entry { eventID = type };
        entry.callback.AddListener(_ => action());
        trigger.triggers.Add(entry);
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

    // Posiziona dall'angolo in alto a sinistra del genitore (x, y verso il basso), dimensioni w × h
    static void Place(RectTransform rt, float x, float y, float w, float h)
    {
        rt.anchorMin = rt.anchorMax = new Vector2(0f, 1f);
        rt.pivot = new Vector2(0f, 1f);
        rt.anchoredPosition = new Vector2(x, -y);
        rt.sizeDelta = new Vector2(w, h);
    }

    // Sprite bianco con angoli arrotondati e bordi antialiasing (per pannelli 9-slice e cerchi)
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