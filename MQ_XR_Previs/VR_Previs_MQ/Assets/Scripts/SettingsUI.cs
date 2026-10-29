// SettingsUI.cs
// Pannello "Impostazioni" nel visore: le opzioni che si possono cambiare anche dall'Inspector di Unity,
// modificabili al volo senza rifare la build.
//
//  • Cerchietto con l'ingranaggio sopra il pannello di controllo.
//  • Voce, generazione, posizionamento, ombra, interfaccia: interruttori (Attivo/Spento) e selettori (– valore +).
//  • Le scelte restano salvate SU QUESTO VISORE (PlayerPrefs) e vengono riapplicate all'avvio.
//    "Ripristina" torna ai valori impostati nell'Inspector.
//  • Griglia, aggancio e ombra cambiano subito anche sugli oggetti già in scena.
//  • Sezione STANZA: calibrazione a due punti (RoomCalibration). Le voci sull'occlusione (SceneOcclusion) compaiono solo se nel progetto
//    c'è SceneOcclusion.cs E in Project Settings > Player > Scripting Define Symbols aggiungi SCENE_OCCLUSION.
//
// SETUP: aggiungi questo componente allo stesso GameObject di LibraryUI (es. "Library").

using System;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.XR.Interaction.Toolkit.UI;

public class SettingsUI : MonoBehaviour
{
    [Header("Riferimenti (se vuoti vengono cercati nella scena)")]
    public QuestObjectGenerator generator;
    public GenerationStatusUI statusUI;
    public AssetLibrary library;
#if SCENE_OCCLUSION
    [Tooltip("Occlusione della stanza (se vuoto viene creato da solo)")]
    public SceneOcclusion occlusion;
#endif
    [Tooltip("Calibrazione della stanza (se vuoto viene cercata nella scena)")]
    public RoomCalibration roomCalibration;

    [Header("Posizione")]
    [Tooltip("Pulsante \"Impostazioni\" usato solo se nella scena non c'è il pannello di controllo (GenerationStatusUI)")]
    public Vector3 dockOffset = new Vector3(0.40f, -0.065f, 0f);
#if SCENE_OCCLUSION
    public Vector3 panelOffset = new Vector3(0f, 0.61f, 0.10f);
#else
    public Vector3 panelOffset = new Vector3(0f, 0.545f, 0.10f);
#endif
    public float panelTilt = -30f;

    const string Prefix = "xr.settings.";
#if SCENE_OCCLUSION
    const float PanelH = 780f;
#else
    const float PanelH = 650f;
#endif
    const float PanelW = 720f, ColW = 324f, RowH = 44f;

    static readonly Color CardBg   = new Color(0.07f, 0.08f, 0.11f, 0.94f);
    static readonly Color TextMain = new Color(0.95f, 0.96f, 0.98f);
    static readonly Color TextDim  = new Color(0.60f, 0.64f, 0.72f);
    static readonly Color Accent   = new Color(0.40f, 0.64f, 1.00f);
    static readonly Color On       = new Color(0.33f, 0.86f, 0.56f, 0.45f);
    static readonly Color BtnBg    = new Color(1f, 1f, 1f, 0.10f);
    static readonly Color Warn     = new Color(1.00f, 0.55f, 0.20f, 0.55f);

    // ── Definizione delle impostazioni ────────────────────────────────

    abstract class Setting
    {
        public string key, label;
        public float defaultValue;
        public TextMeshProUGUI valueLabel;
        public Image toggleBg;
        public abstract float Get();
        public abstract void Set(float v);
        public abstract string Text();
    }

    class BoolSetting : Setting
    {
        public Func<bool> get; public Action<bool> set;
        public override float Get() => get() ? 1f : 0f;
        public override void Set(float v) => set(v > 0.5f);
        public override string Text() => get() ? "Attivo" : "Spento";
    }

    // Pulsante che esegue un'azione (non è un valore: non si salva e "Ripristina" non lo tocca)
    class ActionSetting : Setting
    {
        public Action run; public string buttonText; public bool confirm; public Func<string> status;
        public float armedUntil; public TextMeshProUGUI rowLabel;
        public override float Get() => 0f;
        public override void Set(float v) { }
        public override string Text() => buttonText;
    }

    class StepSetting : Setting
    {
        public float[] options; public Func<float> get; public Action<float> set; public Func<float, string> format;
        public override float Get() => get();
        public override void Set(float v) => set(v);
        public override string Text() => format(get());
        public int Index()
        {
            float v = get(); int best = 0;
            for (int i = 1; i < options.Length; i++) if (Mathf.Abs(options[i] - v) < Mathf.Abs(options[best] - v)) best = i;
            return best;
        }
    }

    readonly List<(string section, List<Setting> items)> _left = new List<(string, List<Setting>)>();
    readonly List<(string section, List<Setting> items)> _right = new List<(string, List<Setting>)>();
    readonly List<Setting> _all = new List<Setting>();
    readonly List<ActionSetting> _actions = new List<ActionSetting>();

    Sprite _rounded, _circle;
    Transform _panel;
    bool _open;

    // ── Avvio ─────────────────────────────────────────────────────────

    void Start()
    {
        if (generator == null) generator = FindAnyObjectByType<QuestObjectGenerator>();
        if (statusUI == null) statusUI = FindAnyObjectByType<GenerationStatusUI>();
        if (library == null) library = FindAnyObjectByType<AssetLibrary>();
#if SCENE_OCCLUSION
        if (occlusion == null) occlusion = SceneOcclusion.EnsureExists(gameObject);
#endif
        if (roomCalibration == null) roomCalibration = FindAnyObjectByType<RoomCalibration>();
        if (generator == null) { Debug.LogError("[SettingsUI] Serve QuestObjectGenerator nella scena."); enabled = false; return; }

        Define();
        foreach (var s in _all) s.defaultValue = s.Get();   // valori dell'Inspector = predefiniti
        Load();

        _rounded = MakeRoundedSprite(64, 24);
        _circle = MakeRoundedSprite(64, 32);
        BuildPanel();
        if (statusUI == null) BuildDock();   // con il pannello di controllo si apre dal cerchietto con l'ingranaggio
        SetOpen(false);
    }

    void Define()
    {
        var g = generator;
        string Cm(float m) => $"{Mathf.RoundToInt(m * 100f)} cm";

        Add(_left, "VOCE",
            Bool("hands_free", "Mani libere (\"genera...\")", () => g.handsFreeMode, v => g.SetHandsFree(v)),
            Bool("voice_proceed", "Prosegui a voce", () => g.voiceProceedEnabled, v => g.voiceProceedEnabled = v),
            Step("mic_threshold", "Sensibilità microfono", new[] { 0.08f, 0.06f, 0.04f, 0.03f, 0.02f },
                 () => g.voiceThreshold, v => g.voiceThreshold = v,
                 v => new[] { "Bassa", "Medio-bassa", "Media", "Alta", "Molto alta" }[NearestIndex(new[] { 0.08f, 0.06f, 0.04f, 0.03f, 0.02f }, v)]));

        var gen = new List<Setting>
        {
            Bool("preview", "Anteprima dell'immagine", () => g.previewBeforeModel, v => g.previewBeforeModel = v),
            Bool("suggest", "Proponi oggetti simili", () => g.suggestFromLibrary, v => g.suggestFromLibrary = v),
        };
        if (library != null)
            gen.Add(Step("suggest_score", "Somiglianza minima", new[] { 0.5f, 0.55f, 0.6f, 0.65f, 0.7f, 0.75f, 0.8f, 0.85f },
                         () => library.suggestMinScore, v => library.suggestMinScore = v, v => $"{Mathf.RoundToInt(v * 100f)}%"));
        gen.Add(Bool("auto_align", "Raddrizza i modelli", () => g.autoAlignModels, v => g.autoAlignModels = v));
        gen.Add(Step("target_size", "Dimensione iniziale", new[] { 0.15f, 0.2f, 0.3f, 0.5f, 0.75f, 1f, 1.5f },
                     () => g.targetObjectSize, v => g.targetObjectSize = v, Cm));
        Add(_left, "GENERAZIONE", gen.ToArray());

        Add(_left, "OGGETTI",
            Bool("collide", "Collisione tra oggetti", () => g.objectCollisions, v => { g.objectCollisions = v; g.ApplySettingsToScene(); }));

        Add(_right, "POSIZIONAMENTO",
            Bool("aids", "Griglia e misure", () => g.showPlacementAids, v => { g.showPlacementAids = v; g.ApplySettingsToScene(); }),
            Bool("snap", "Aggancio al rilascio", () => g.snapOnRelease, v => { g.snapOnRelease = v; g.ApplySettingsToScene(); }),
            Step("grid_step", "Passo della griglia", new[] { 0f, 0.01f, 0.025f, 0.05f, 0.1f },
                 () => g.snapGridStep, v => { g.snapGridStep = v; g.ApplySettingsToScene(); },
                 v => v <= 0f ? "Libero" : $"{v * 100f:0.#} cm"),
            Step("yaw_step", "Passo della rotazione", new[] { 0f, 5f, 15f, 45f, 90f },
                 () => g.snapYawStep, v => { g.snapYawStep = v; g.ApplySettingsToScene(); },
                 v => v <= 0f ? "Libera" : $"{v:0}°"));

        Add(_right, "OMBRA",
            Bool("shadow", "Ombra sotto gli oggetti", () => g.contactShadows, v => { g.contactShadows = v; g.ApplySettingsToScene(); }),
            Step("shadow_opacity", "Intensità dell'ombra", new[] { 0.2f, 0.3f, 0.4f, 0.5f, 0.55f, 0.6f, 0.7f, 0.8f, 0.9f },
                 () => g.shadowOpacity, v => { g.shadowOpacity = v; g.ApplySettingsToScene(); }, v => $"{Mathf.RoundToInt(v * 100f)}%"));

        var room = new List<Setting>();
        if (roomCalibration != null)
            room.Add(new ActionSetting
            {
                key = "calib", label = "Calibrazione", buttonText = "Calibra", confirm = false,
                status = () => roomCalibration.StatusLabel,
                run = () => { Hide(); roomCalibration.Begin(); },
            });
#if SCENE_OCCLUSION
        if (occlusion != null)
        {
            room.Add(Bool("occlusion", "Occlusione stanza", () => occlusion.occlusionEnabled, v => { occlusion.occlusionEnabled = v; occlusion.Apply(); }));
            room.Add(Bool("furniture", "Appoggia sui mobili", () => occlusion.furnitureColliders, v => { occlusion.furnitureColliders = v; occlusion.Apply(); }));
            room.Add(Bool("occl_debug", "Mostra occlusori (prova)", () => occlusion.showDebug, v => { occlusion.showDebug = v; occlusion.Apply(); }));
        }
#endif
        if (room.Count > 0) Add(_right, "STANZA", room.ToArray());

        if (statusUI != null)
            Add(_right, "INTERFACCIA",
                Bool("haptics", "Vibrazione dei controller", () => statusUI.haptics, v => statusUI.haptics = v));
    }

    void Add(List<(string, List<Setting>)> column, string section, params Setting[] items)
    {
        column.Add((section, new List<Setting>(items)));
        foreach (var it in items)
        {
            if (it is ActionSetting a) _actions.Add(a);
            else _all.Add(it);
        }
    }

    static BoolSetting Bool(string key, string label, Func<bool> get, Action<bool> set) =>
        new BoolSetting { key = key, label = label, get = get, set = set };

    static StepSetting Step(string key, string label, float[] options, Func<float> get, Action<float> set, Func<float, string> format) =>
        new StepSetting { key = key, label = label, options = options, get = get, set = set, format = format };

    static int NearestIndex(float[] options, float v)
    {
        int best = 0;
        for (int i = 1; i < options.Length; i++) if (Mathf.Abs(options[i] - v) < Mathf.Abs(options[best] - v)) best = i;
        return best;
    }

    // ── Salvataggio sul visore ────────────────────────────────────────

    void Load()
    {
        foreach (var s in _all)
            if (PlayerPrefs.HasKey(Prefix + s.key)) s.Set(PlayerPrefs.GetFloat(Prefix + s.key));
    }

    void Save(Setting s)
    {
        PlayerPrefs.SetFloat(Prefix + s.key, s.Get());
        PlayerPrefs.Save();
    }

    void ResetAll()
    {
        foreach (var s in _all)
        {
            s.Set(s.defaultValue);
            PlayerPrefs.DeleteKey(Prefix + s.key);
        }
        PlayerPrefs.Save();
        Refresh();
    }

    // ── Interazione ───────────────────────────────────────────────────

    void Toggle(Setting s)
    {
        s.Set(s.Get() > 0.5f ? 0f : 1f);
        Save(s);
        Refresh();
    }

    void StepBy(StepSetting s, int dir)
    {
        int i = Mathf.Clamp(s.Index() + dir, 0, s.options.Length - 1);
        s.Set(s.options[i]);
        Save(s);
        Refresh();
    }

    void RunAction(ActionSetting a)
    {
        if (a.confirm && Time.unscaledTime > a.armedUntil)
        {
            // primo tocco: chiede conferma
            a.armedUntil = Time.unscaledTime + 4f;
            if (a.valueLabel != null) a.valueLabel.text = "Conferma?";
            if (a.toggleBg != null) a.toggleBg.color = Warn;
            StartCoroutine(Disarm(a));
            return;
        }
        a.armedUntil = 0f;
        if (a.valueLabel != null) a.valueLabel.text = a.buttonText;
        if (a.toggleBg != null) a.toggleBg.color = BtnBg;
        a.run?.Invoke();
    }

    System.Collections.IEnumerator Disarm(ActionSetting a)
    {
        yield return new WaitForSecondsRealtime(4.1f);
        if (Time.unscaledTime >= a.armedUntil)
        {
            if (a.valueLabel != null) a.valueLabel.text = a.buttonText;
            if (a.toggleBg != null) a.toggleBg.color = BtnBg;
        }
    }

    float _nextActionRefresh;

    void Update()
    {
        if (!_open || Time.unscaledTime < _nextActionRefresh) return;
        _nextActionRefresh = Time.unscaledTime + 0.5f;
        RefreshActions();
    }

    void RefreshActions()
    {
        foreach (var a in _actions)
            if (a.rowLabel != null && a.status != null) a.rowLabel.text = a.status();
    }

    void Refresh()
    {
        RefreshActions();
        foreach (var s in _all)
        {
            if (s.valueLabel != null) s.valueLabel.text = s.Text();
            if (s.toggleBg != null) s.toggleBg.color = s.Get() > 0.5f ? On : BtnBg;
        }
    }

    public bool IsOpen => _open;
    public void Hide() => SetOpen(false);
    public void Toggle() => SetOpen(!_open);

    void SetOpen(bool open)
    {
        _open = open;
        if (_panel != null) _panel.gameObject.SetActive(open);
        if (open)
        {
            FindAnyObjectByType<LibraryUI>()?.Hide();   // stesso spazio del pannello Libreria
            Refresh();
        }
    }

    // ── Costruzione UI ────────────────────────────────────────────────

    void BuildPanel()
    {
        var root = NewCanvas("SettingsPanel", PanelW, PanelH, out _panel);
        if (statusUI != null)
        {
            _panel.SetParent(statusUI.transform, false);
            _panel.localPosition = panelOffset;
            _panel.localRotation = Quaternion.Euler(panelTilt, 0f, 0f);
        }
        else
        {
            _panel.SetParent(transform, false);
            var head = generator.Head;
            if (head != null)
            {
                Vector3 fwd = Vector3.ProjectOnPlane(head.forward, Vector3.up).normalized;
                _panel.position = head.position + fwd * 1.0f;
                _panel.rotation = Quaternion.LookRotation(fwd, Vector3.up);
            }
        }

        var bg = Img(root, "Background", _rounded, CardBg, true, 1f);
        Stretch(bg.rectTransform);

        var title = Txt(root, "Title", 26, FontStyles.Bold, TextMain, TextAlignmentOptions.MidlineLeft);
        Place(title.rectTransform, 24, 16, 400, 40);
        title.text = "Impostazioni";
        MakeRoundButton(root, "Close", "×", 664, 18, 36, () => SetOpen(false));

        BuildColumn(root, _left, 24);
        BuildColumn(root, _right, 24 + ColW + 24);

        var note = Txt(root, "Note", 15, FontStyles.Normal, TextDim, TextAlignmentOptions.MidlineLeft);
        Place(note.rectTransform, 24, PanelH - 60, 440, 40);
        note.text = "Salvate su questo visore. «Ripristina» torna ai valori dell'Inspector.";
        MakeButton(root, "Reset", "Ripristina", PanelW - 24 - 160, PanelH - 60, 160, 40, ResetAll, out _);
    }

    void BuildColumn(RectTransform root, List<(string section, List<Setting> items)> col, float x)
    {
        float y = 70;
        foreach (var (section, items) in col)
        {
            var h = Txt(root, "Section", 14, FontStyles.Bold, Accent, TextAlignmentOptions.BottomLeft);
            h.characterSpacing = 8f;
            Place(h.rectTransform, x, y, ColW, 24);
            h.text = section;
            y += 30;
            foreach (var s in items)
            {
                var label = Txt(root, s.key, 16, FontStyles.Normal, TextMain, TextAlignmentOptions.MidlineLeft);
                Place(label.rectTransform, x, y, ColW - (s is StepSetting ? 152 : 128), RowH - 4);
                label.text = s.label;

                if (s is ActionSetting act)
                {
                    act.rowLabel = label;
                    label.text = act.status != null ? act.status() : act.label;
                    Place(label.rectTransform, x, y, ColW - 126, RowH - 4);
                    act.toggleBg = MakeButton(root, s.key + "A", act.buttonText, x + ColW - 120, y + 2, 120, 34, () => RunAction(act), out var at);
                    at.fontSize = 15;
                    act.valueLabel = at;
                }
                else if (s is StepSetting st)
                {
                    MakeButton(root, s.key + "-", "-", x + ColW - 146, y + 2, 34, 34, () => StepBy(st, -1), out _);
                    var v = Txt(root, s.key + "V", 16, FontStyles.Bold, TextMain, TextAlignmentOptions.Center);
                    Place(v.rectTransform, x + ColW - 110, y, 76, RowH - 6);
                    s.valueLabel = v;
                    MakeButton(root, s.key + "+", "+", x + ColW - 34, y + 2, 34, 34, () => StepBy(st, +1), out _);
                }
                else
                {
                    s.toggleBg = MakeButton(root, s.key + "T", "", x + ColW - 120, y + 2, 120, 34, () => Toggle(s), out var t);
                    t.fontSize = 16;
                    s.valueLabel = t;
                }
                y += RowH;
            }
            y += 8;
        }
    }

    void BuildDock()
    {
        var root = NewCanvas("SettingsDock", 150, 48, out var t);
        if (statusUI != null)
        {
            t.SetParent(statusUI.transform, false);
            t.localPosition = dockOffset;
            t.localRotation = Quaternion.identity;
        }
        else t.SetParent(transform, false);
        var b = MakeButton(root, "Settings", "Impostazioni", 0, 0, 150, 48, () => SetOpen(!_open), out var lbl);
        b.color = new Color(0.07f, 0.08f, 0.11f, 0.85f);
        lbl.fontSize = 18;
    }

    // ── Utilità UI (come in LibraryUI) ────────────────────────────────

    RectTransform NewCanvas(string name, float w, float h, out Transform t)
    {
        var go = new GameObject(name, typeof(RectTransform), typeof(Canvas), typeof(TrackedDeviceGraphicRaycaster));
        go.GetComponent<Canvas>().renderMode = RenderMode.WorldSpace;
        var rt = (RectTransform)go.transform;
        rt.sizeDelta = new Vector2(w, h);
        rt.localScale = Vector3.one * 0.001f;
        t = rt;
        return rt;
    }

    Image MakeButton(RectTransform parent, string name, string label, float x, float y, float w, float h, Action onClick, out TextMeshProUGUI text)
    {
        var img = Img(parent, name, _rounded, BtnBg, true, 24f / Mathf.Max(10f, Mathf.Min(h, 24f) * 0.75f));
        img.raycastTarget = true;
        Place(img.rectTransform, x, y, w, h);
        var btn = img.gameObject.AddComponent<Button>();
        var colors = btn.colors;
        colors.normalColor = Color.white;
        colors.highlightedColor = new Color(1.6f, 1.6f, 1.6f, 1f);
        colors.pressedColor = new Color(2.2f, 2.2f, 2.2f, 1f);
        colors.colorMultiplier = 2f;
        btn.colors = colors;
        btn.targetGraphic = img;
        if (onClick != null) btn.onClick.AddListener(() => onClick());

        text = Txt(img.rectTransform, "Label", 18, FontStyles.Bold, TextMain, TextAlignmentOptions.Center);
        Stretch(text.rectTransform);
        text.text = label;
        return img;
    }

    void MakeRoundButton(RectTransform parent, string name, string glyph, float x, float y, float size, Action onClick)
    {
        var img = Img(parent, name, _circle, BtnBg, false);
        img.raycastTarget = true;
        Place(img.rectTransform, x, y, size, size);
        var btn = img.gameObject.AddComponent<Button>();
        btn.targetGraphic = img;
        btn.onClick.AddListener(() => onClick());
        var t = Txt(img.rectTransform, "Glyph", 26, FontStyles.Bold, TextMain, TextAlignmentOptions.Center);
        Stretch(t.rectTransform);
        t.text = glyph;
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

    static void Stretch(RectTransform rt)
    {
        rt.anchorMin = Vector2.zero;
        rt.anchorMax = Vector2.one;
        rt.offsetMin = Vector2.zero;
        rt.offsetMax = Vector2.zero;
    }

    static Sprite MakeRoundedSprite(int size, int radius)
    {
        var tex = new Texture2D(size, size, TextureFormat.RGBA32, false) { wrapMode = TextureWrapMode.Clamp, filterMode = FilterMode.Bilinear };
        var px = new Color32[size * size];
        for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
        {
            float fx = x + 0.5f, fy = y + 0.5f;
            float dx = Mathf.Max(radius - fx, fx - (size - radius), 0f);
            float dy = Mathf.Max(radius - fy, fy - (size - radius), 0f);
            float d = Mathf.Sqrt(dx * dx + dy * dy);
            px[y * size + x] = new Color32(255, 255, 255, (byte)(Mathf.Clamp01(radius - d + 0.5f) * 255f));
        }
        tex.SetPixels32(px);
        tex.Apply(false, true);
        return Sprite.Create(tex, new Rect(0, 0, size, size), new Vector2(0.5f, 0.5f), 100f, 0,
                             SpriteMeshType.FullRect, new Vector4(radius, radius, radius, radius));
    }
}
