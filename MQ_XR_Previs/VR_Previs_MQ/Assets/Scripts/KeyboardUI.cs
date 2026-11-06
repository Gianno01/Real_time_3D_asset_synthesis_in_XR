// KeyboardUI.cs
// Tastiera a schermo (nel mondo 3D, si usa con i raggi dei controller) per scrivere al posto di dire un comando a voce.
// Accanto al testo c'è il pulsante del MICROFONO per dettare dentro lo stesso campo.
//
// Si attiva da Impostazioni → VOCE → "Tastiera al posto della voce" (spenta di default). Quando è attiva compare dove prima si parlava:
//   • nuova richiesta   pulsante tastiera nella barra sopra il pannello (o stick destro)
//   • anteprima         "Correggi"
//   • libreria          ricerca, nome della scena, nome dell'oggetto, nuovo stile
// Funziona anche con una tastiera Bluetooth collegata al visore (lettere, Invio = conferma, Esc = annulla, Backspace).
//
// SETUP: nessuno, QuestObjectGenerator la crea da sola alla prima apertura.

using System;
using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.UI;
using UnityEngine.XR.Interaction.Toolkit.UI;

public class KeyboardUI : MonoBehaviour
{
    public QuestObjectGenerator generator;
    [Tooltip("Distanza dal viso (m)")] public float distance = 0.65f;
    [Tooltip("Altezza rispetto agli occhi (m): negativo = più in basso")] public float heightOffset = -0.22f;
    [Tooltip("Lunghezza massima del testo")] public int maxLength = 140;

    public bool IsOpen => _root != null && _root.gameObject.activeSelf;

    public static KeyboardUI EnsureExists(GameObject where)
    {
        var k = FindAnyObjectByType<KeyboardUI>();
        if (k == null) k = where.AddComponent<KeyboardUI>();
        return k;
    }

    const float W = 900f, H = 592f, Gap = 6f, KeyH = 62f, RowPitch = 70f;
    static readonly Color CardBg   = new Color(0.07f, 0.08f, 0.11f, 0.96f);
    static readonly Color FieldBg  = new Color(0f, 0f, 0f, 0.35f);
    static readonly Color KeyBg    = new Color(1f, 1f, 1f, 0.11f);
    static readonly Color TextMain = new Color(0.95f, 0.96f, 0.98f);
    static readonly Color TextDim  = new Color(0.60f, 0.64f, 0.72f);
    static readonly Color Accent   = new Color(0.40f, 0.64f, 1.00f);
    static readonly Color Ok       = new Color(0.33f, 0.86f, 0.56f);
    static readonly Color Bad      = new Color(1.00f, 0.43f, 0.41f);

    enum Shift { Off, Once, Lock }

    RectTransform _root;
    Sprite _rounded;
    TextMeshProUGUI _title, _field, _status, _shiftLabel;
    Image _micBg, _shiftBg;
    TextMeshProUGUI _micLabel;
    readonly List<(TextMeshProUGUI label, string baseChar)> _letterKeys = new List<(TextMeshProUGUI, string)>();

    string _text = "";
    Action<string> _onDone;
    Shift _shift = Shift.Off;
    bool _dictating;
    Keyboard _hw;

    // ── Lifecycle ─────────────────────────────────────────────────────

    void Awake()
    {
        _rounded = MakeRoundedSprite(64, 24);
        if (generator == null) generator = FindAnyObjectByType<QuestObjectGenerator>();
        BuildUI();
        _root.gameObject.SetActive(false);
    }

    void OnDestroy() { DetachHardwareKeyboard(); }

    void Update()
    {
        if (!IsOpen) return;
        bool caret = ((int)(Time.unscaledTime * 2f)) % 2 == 0;
        _field.text = Tail(_text, 80) + (caret ? "|" : " ");

        var kb = Keyboard.current;
        if (kb != null && kb.escapeKey.wasPressedThisFrame) Close(false);
    }

    // ── API ───────────────────────────────────────────────────────────

    /// <summary>Apre la tastiera. onDone riceve il testo, oppure null se annulli.</summary>
    public void Open(string title, string initial, Action<string> onDone)
    {
        if (generator == null) generator = FindAnyObjectByType<QuestObjectGenerator>();
        if (IsOpen) FinishCallback(null);   // una sola tastiera alla volta: la precedente viene annullata

        _onDone = onDone;
        _text = initial ?? "";
        _shift = _text.Length == 0 ? Shift.Once : Shift.Off;   // prima lettera maiuscola
        _dictating = false;
        _title.text = title ?? "Scrivi";
        _status.text = "Il microfono detta dentro il testo";
        RefreshKeys();
        PlaceInFrontOfHead();
        _root.gameObject.SetActive(true);
        AttachHardwareKeyboard();
        if (generator != null) generator.SetTextEntryActive(true);
    }

    public void Close(bool submit)
    {
        if (!IsOpen) return;
        string result = submit ? _text.Trim() : null;
        _root.gameObject.SetActive(false);
        DetachHardwareKeyboard();
        if (generator != null) generator.SetTextEntryActive(false);
        FinishCallback(result);
    }

    void FinishCallback(string result)
    {
        var cb = _onDone;
        _onDone = null;
        try { cb?.Invoke(result); } catch (Exception e) { Debug.LogException(e); }
    }

    void PlaceInFrontOfHead()
    {
        var head = generator != null ? generator.Head : null;
        if (head == null) return;
        Vector3 fwd = Vector3.ProjectOnPlane(head.forward, Vector3.up);
        if (fwd.sqrMagnitude < 0.001f) fwd = Vector3.forward;
        fwd.Normalize();
        Vector3 pos = head.position + fwd * distance + Vector3.up * heightOffset;
        _root.position = pos;
        _root.rotation = Quaternion.LookRotation((pos - head.position).normalized, Vector3.up);   // guarda verso il viso, leggermente inclinata
    }

    // ── Testo ─────────────────────────────────────────────────────────

    void Append(string s)
    {
        if (string.IsNullOrEmpty(s)) return;
        if (_text.Length + s.Length > maxLength) return;
        _text += s;
    }

    void TypeKey(string baseChar)
    {
        string c = _shift == Shift.Off ? baseChar : baseChar.ToUpperInvariant();
        Append(c);
        if (_shift == Shift.Once) { _shift = Shift.Off; RefreshKeys(); }
    }

    void Backspace()
    {
        if (_text.Length > 0) _text = _text.Substring(0, _text.Length - 1);
        if (_text.Length == 0 && _shift == Shift.Off) { _shift = Shift.Once; RefreshKeys(); }
    }

    void ClearAll()
    {
        _text = "";
        _shift = Shift.Once;
        RefreshKeys();
    }

    void CycleShift()
    {
        _shift = _shift == Shift.Off ? Shift.Once : _shift == Shift.Once ? Shift.Lock : Shift.Off;
        RefreshKeys();
    }

    void RefreshKeys()
    {
        foreach (var (label, baseChar) in _letterKeys)
            label.text = _shift == Shift.Off ? baseChar : baseChar.ToUpperInvariant();
        if (_shiftBg != null) _shiftBg.color = _shift == Shift.Off ? KeyBg : new Color(Accent.r, Accent.g, Accent.b, _shift == Shift.Lock ? 0.75f : 0.45f);
        if (_shiftLabel != null) _shiftLabel.text = _shift == Shift.Lock ? "MAIUSC" : "Maiusc";
    }

    static string Tail(string s, int max) => s.Length <= max ? s : "..." + s.Substring(s.Length - max);

    // ── Dettatura (microfono accanto al testo) ────────────────────────

    void StartDictation()
    {
        if (_dictating || generator == null) return;
        StartCoroutine(DictateRoutine());
    }

    IEnumerator DictateRoutine()
    {
        _dictating = true;
        _micBg.color = new Color(Bad.r, Bad.g, Bad.b, 0.6f);
        _micLabel.text = "Ascolto";
        _status.text = "Parla ora: la dettatura finisce con una pausa";

        string heard = null;
        yield return generator.Dictate(t => heard = t);

        _dictating = false;
        _micBg.color = KeyBg;
        _micLabel.text = "Detta";
        if (!IsOpen) yield break;
        if (string.IsNullOrWhiteSpace(heard)) { _status.text = "Non ho capito: riprova"; yield break; }

        string add = heard.Trim();
        if (_text.Length > 0 && !_text.EndsWith(" ")) add = " " + add;
        Append(add);
        _shift = Shift.Off;
        RefreshKeys();
        _status.text = "Aggiunto: puoi correggere con la tastiera";
    }

    // ── Tastiera fisica (Bluetooth) ───────────────────────────────────

    void AttachHardwareKeyboard()
    {
        DetachHardwareKeyboard();
        _hw = Keyboard.current;
        if (_hw != null) _hw.onTextInput += OnHardwareChar;
    }

    void DetachHardwareKeyboard()
    {
        if (_hw != null) _hw.onTextInput -= OnHardwareChar;
        _hw = null;
    }

    void OnHardwareChar(char c)
    {
        if (!IsOpen) return;
        if (c == '\b') { Backspace(); return; }
        if (c == '\r' || c == '\n') { Close(true); return; }
        if (char.IsControl(c)) return;
        Append(c.ToString());
        if (_shift == Shift.Once) { _shift = Shift.Off; RefreshKeys(); }
    }

    // ── Costruzione UI ────────────────────────────────────────────────

    void BuildUI()
    {
        var go = new GameObject("KeyboardCanvas", typeof(RectTransform), typeof(Canvas), typeof(TrackedDeviceGraphicRaycaster));
        go.transform.SetParent(transform, false);
        go.GetComponent<Canvas>().renderMode = RenderMode.WorldSpace;
        _root = (RectTransform)go.transform;
        _root.sizeDelta = new Vector2(W, H);
        _root.localScale = Vector3.one * 0.001f;

        var bg = Img(_root, "Background", _rounded, CardBg, true, 1f);
        Stretch(bg.rectTransform);
        bg.raycastTarget = true;   // i clic non passano attraverso la tastiera

        _title = Txt(_root, "Title", 26, FontStyles.Bold, TextMain, TextAlignmentOptions.MidlineLeft);
        Place(_title.rectTransform, 24, 12, 700, 40);

        // campo di testo + microfono + svuota
        var fieldBg = Img(_root, "FieldBg", _rounded, FieldBg, true, 1f);
        Place(fieldBg.rectTransform, 24, 58, 636, 84);
        _field = Txt(_root, "Field", 30, FontStyles.Normal, TextMain, TextAlignmentOptions.MidlineLeft);
        Place(_field.rectTransform, 38, 62, 610, 76);
        _field.overflowMode = TextOverflowModes.Truncate;
        _field.richText = false;   // il testo scritto non deve essere letto come markup

        var mic = MakeButton(_root, "Mic", "", 672, 58, 100, 84, StartDictation);
        _micBg = mic.GetComponent<Image>();
        var icon = new GameObject("Icon", typeof(RectTransform), typeof(RawImage));
        icon.transform.SetParent(mic.transform, false);
        var raw = icon.GetComponent<RawImage>();
        raw.texture = UiIcons.Mic; raw.color = TextMain; raw.raycastTarget = false;
        var irt = raw.rectTransform;
        irt.anchorMin = irt.anchorMax = new Vector2(0.5f, 0.5f);
        irt.sizeDelta = new Vector2(46, 46);
        irt.anchoredPosition = new Vector2(0, 8);
        _micLabel = Txt(mic.GetComponent<RectTransform>(), "MicLabel", 15, FontStyles.Bold, TextDim, TextAlignmentOptions.Bottom);
        Stretch(_micLabel.rectTransform);
        _micLabel.rectTransform.offsetMin = new Vector2(0, 4);
        _micLabel.text = "Detta";

        MakeButton(_root, "Clear", "Svuota", 784, 58, 92, 84, ClearAll, 20);

        // tasti
        float u = (852f - 9f * Gap) / 10f;
        float y = 156f;
        BuildRow(y, u, Keys("1234567890", 1f)); y += RowPitch;
        BuildRow(y, u, Keys("qwertyuiop", 1f)); y += RowPitch;
        BuildRow(y, u, Keys("asdfghjkl'", 1f)); y += RowPitch;

        var r3 = new List<KeyDef>();
        r3.Add(new KeyDef { label = "Maiusc", w = 1.5f, action = CycleShift, isShift = true, size = 20 });
        r3.AddRange(Keys("zxcvbnm", 1f));
        r3.Add(new KeyDef { label = "Canc", w = 1.5f, action = Backspace, size = 20 });
        BuildRow(y, u, r3); y += RowPitch;

        var r4 = new List<KeyDef>();
        r4.AddRange(Keys("àèéìòù", 0.8f));
        r4.Add(new KeyDef { label = "spazio", w = 3.4f, action = () => Append(" "), size = 22 });
        r4.AddRange(Keys(".,", 0.9f));
        BuildRow(y, u, r4);

        // azioni
        float ay = H - 76f;
        MakeButton(_root, "Cancel", "Annulla", 24, ay, 200, 52, () => Close(false), 22);
        _status = Txt(_root, "Status", 16, FontStyles.Normal, TextDim, TextAlignmentOptions.Center);
        Place(_status.rectTransform, 240, ay, 420, 52);
        var send = MakeButton(_root, "Send", "Invia", W - 24 - 200, ay, 200, 52, () => Close(true), 24);
        send.GetComponent<Image>().color = new Color(Ok.r, Ok.g, Ok.b, 0.55f);
    }

    class KeyDef
    {
        public string label, baseChar; public float w = 1f; public Action action; public bool isShift, isLetter; public int size = 30;
    }

    List<KeyDef> Keys(string chars, float w)
    {
        var list = new List<KeyDef>();
        foreach (char c in chars)
        {
            string s = c.ToString();
            bool letter = char.IsLetter(c);
            list.Add(new KeyDef { label = s, baseChar = s, w = w, isLetter = letter, action = () => TypeKey(s) });
        }
        return list;
    }

    void BuildRow(float y, float u, List<KeyDef> keys)
    {
        float x = 24f;
        foreach (var k in keys)
        {
            float kw = k.w * u + (k.w - 1f) * Gap;
            var btn = MakeButton(_root, "Key", k.label, x, y, kw, KeyH, k.action, k.size);
            var label = btn.GetComponentInChildren<TextMeshProUGUI>();
            if (k.isLetter) _letterKeys.Add((label, k.baseChar));
            if (k.isShift) { _shiftBg = btn.GetComponent<Image>(); _shiftLabel = label; }
            x += kw + Gap;
        }
    }

    GameObject MakeButton(RectTransform parent, string name, string label, float x, float y, float w, float h, Action onClick, int fontSize = 24)
    {
        var img = Img(parent, name, _rounded, KeyBg, true, 24f / 18f);
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
        btn.onClick.AddListener(() => onClick());

        if (!string.IsNullOrEmpty(label))
        {
            var t = Txt(img.rectTransform, "Label", fontSize, FontStyles.Bold, TextMain, TextAlignmentOptions.Center);
            Stretch(t.rectTransform);
            t.text = label;
        }
        return img.gameObject;
    }

    // ── Helper grafici ────────────────────────────────────────────────

    static Image Img(RectTransform parent, string name, Sprite sprite, Color color, bool sliced, float cornerMul)
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
        t.overflowMode = TextOverflowModes.Truncate;
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
            byte a = (byte)(Mathf.Clamp01(radius - d + 0.5f) * 255f);
            px[y * size + x] = new Color32(255, 255, 255, a);
        }
        tex.SetPixels32(px);
        tex.Apply(false, true);
        return Sprite.Create(tex, new Rect(0, 0, size, size), new Vector2(0.5f, 0.5f), 100f, 0,
                             SpriteMeshType.FullRect, new Vector4(radius, radius, radius, radius));
    }
}
