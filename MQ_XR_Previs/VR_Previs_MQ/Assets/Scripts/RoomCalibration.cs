// RoomCalibration.cs
// Calibrazione della stanza a DUE PUNTI: ricostruisce ogni volta la stessa origine, anche se il Quest "dimentica" la stanza
// e devi ridisegnare il confine.
//
// IL PROBLEMA: le scene salvano le posizioni rispetto a un'origine. Il Quest ricrea l'origine a ogni avvio (e se il confine va
// ridisegnato, in un punto diverso): riaprendo una scena gli oggetti restano vicini tra loro ma in un altro punto della stanza.
//
// LA SOLUZIONE: scegli due punti FISSI della stanza (es. due angoli della scrivania, o due segni di nastro adesivo sul pavimento)
// e a ogni avvio li tocchi con la punta del controller destro:
//     PUNTO A = origine,   direzione A→B = asse "avanti" della scena.
// Le scene sono salvate e caricate rispetto a questa origine, quindi tornano sempre nello stesso punto della stanza. E se più
// visori si calibrano sugli stessi due punti, condividono la stessa origine (utile per l'esperienza condivisa).
//
// Uso: Impostazioni → STANZA → Calibra (o parte da sola quando provi a salvare/caricare una scena non calibrata).
//   Grilletto destro = conferma il punto; tasto B (secondario destro) = annulla. Durante la calibrazione i raggi dei controller sono spenti.
// Precisione: ±2-3 cm per punto; tieni A e B ad almeno 1 m di distanza (l'errore di direzione è circa 3 cm / distanza).
//
// SETUP: nessuno, AssetLibrary crea il componente da sola.

using System.Collections.Generic;
using TMPro;
using Unity.XR.CoreUtils;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.XR;
using UnityEngine.XR.Interaction.Toolkit.Interactors;

public class RoomCalibration : MonoBehaviour
{
    public AssetLibrary library;
    [Tooltip("Salvare/caricare scene richiede la calibrazione (spento = come prima, con l'XR Origin)")]
    public bool required = true;
    [Tooltip("Distanza minima tra A e B (m)")]
    public float minDistance = 0.5f;
    [Tooltip("Il punto toccato è questo tanto davanti all'origine del raggio del controller (m)")]
    public float tipOffset = 0.02f;

    enum Step { Idle, PointA, PointB }
    Step _step = Step.Idle;

    public bool IsCalibrated { get; private set; }
    public bool InProgress => _step != Step.Idle;
    public string StatusLabel => InProgress ? "Calibrazione: in corso" : (IsCalibrated ? "Calibrazione: ok" : "Calibrazione: no");

    XROrigin _xr;
    Transform _roomOrigin;
    Vector3 _a;
    Transform _panel;
    TextMeshProUGUI _text;
    GameObject _tipMarker, _aMarker;
    XRRayInteractor _rightRay;
    readonly List<XRRayInteractor> _disabled = new List<XRRayInteractor>();
    bool _prevTrigger = true, _prevCancel = true;
    float _hideAt;
    Material _markerMat;

    // ── Avvio della procedura ─────────────────────────────────────────

    public void Begin()
    {
        if (InProgress) return;
        _xr = FindAnyObjectByType<XROrigin>();
        if (_xr == null || _xr.Camera == null) { Debug.LogWarning("[RoomCalibration] Serve un XR Origin con camera."); return; }

        EnsureUi();

        // i raggi dei controller si spengono: il grilletto non deve premere pulsanti o afferrare oggetti
        _disabled.Clear();
        _rightRay = null;
        foreach (var ri in FindObjectsByType<XRRayInteractor>(FindObjectsSortMode.None))
        {
            if (_rightRay == null && IsRight(ri)) _rightRay = ri;
            if (ri.enabled) { ri.enabled = false; _disabled.Add(ri); }
        }
        FindAnyObjectByType<SettingsUI>()?.Hide();
        FindAnyObjectByType<LibraryUI>()?.Hide();

        _prevTrigger = true;   // il grilletto usato per aprire questo comando non conta
        _prevCancel = true;
        _step = Step.PointA;
        _panel.gameObject.SetActive(true);
        _tipMarker.SetActive(true);
        _aMarker.SetActive(false);
        _hideAt = float.MaxValue;
        Debug.Log("[RoomCalibration] Avviata: tocca il punto A.");
    }

    static bool IsRight(XRRayInteractor ri) => ri.handedness.ToString() == "Right" || ri.name.ToLowerInvariant().Contains("right");

    void End(string message, float showSeconds)
    {
        foreach (var ri in _disabled) if (ri != null) ri.enabled = true;
        _disabled.Clear();
        _step = Step.Idle;
        _tipMarker.SetActive(false);
        _aMarker.SetActive(false);
        _text.text = message;
        _hideAt = Time.unscaledTime + showSeconds;
    }

    void OnDisable()
    {
        foreach (var ri in _disabled) if (ri != null) ri.enabled = true;
        _disabled.Clear();
        _step = Step.Idle;
    }

    // ── Ciclo ─────────────────────────────────────────────────────────

    void Update()
    {
        if (_panel == null) return;

        if (_step == Step.Idle)
        {
            if (_panel.gameObject.activeSelf && Time.unscaledTime > _hideAt) _panel.gameObject.SetActive(false);
            else if (_panel.gameObject.activeSelf) FollowHead();
            return;
        }

        FollowHead();
        Vector3 tip = TipPosition();
        _tipMarker.transform.position = tip;

        var dev = InputDevices.GetDeviceAtXRNode(XRNode.RightHand);
        bool trigger = false, cancel = false;
        dev.TryGetFeatureValue(CommonUsages.triggerButton, out trigger);
        dev.TryGetFeatureValue(CommonUsages.secondaryButton, out cancel);
        bool triggerDown = trigger && !_prevTrigger;
        bool cancelDown = cancel && !_prevCancel;
        _prevTrigger = trigger;
        _prevCancel = cancel;

        if (cancelDown) { End("Calibrazione annullata", 2f); return; }

        if (_step == Step.PointA)
        {
            _text.text = "<b>Calibrazione 1/2</b>\nPoggia la punta del controller destro sul <b>PUNTO A</b>\n(es. un angolo della scrivania) e premi il <b>grilletto</b>\n<size=70%>B = annulla</size>";
            if (triggerDown)
            {
                _a = tip;
                _aMarker.transform.position = _a;
                _aMarker.SetActive(true);
                _step = Step.PointB;
                Haptic();
            }
        }
        else
        {
            float d = Vector3.ProjectOnPlane(tip - _a, Vector3.up).magnitude;
            string dist = d < minDistance ? $"<color=#ffb060>distanza da A: {d:0.00} m (servono almeno {minDistance:0.0} m)</color>" : $"distanza da A: {d:0.00} m";
            _text.text = $"<b>Calibrazione 2/2</b>\nOra sul <b>PUNTO B</b>, lontano da A (meglio oltre 1 m)\ne premi il <b>grilletto</b>\n<size=70%>{dist} - B = annulla</size>";
            if (triggerDown && d >= minDistance)
            {
                Apply(_a, tip);
                Haptic();
                End("<b>Stanza calibrata</b>\nOra puoi salvare e caricare le scene.", 2.5f);
            }
        }
    }

    // ── Calcolo dell'origine ──────────────────────────────────────────

    void Apply(Vector3 a, Vector3 b)
    {
        Vector3 dir = Vector3.ProjectOnPlane(b - a, Vector3.up).normalized;
        var rot = Quaternion.LookRotation(dir, Vector3.up);   // +Z = da A verso B

        if (_roomOrigin == null) _roomOrigin = new GameObject("RoomOrigin").transform;
        _roomOrigin.SetParent(_xr.transform, false);           // segue il rig se si sposta
        _roomOrigin.SetPositionAndRotation(a, rot);

        IsCalibrated = true;
        if (library != null) library.sceneAnchor = _roomOrigin;
        Debug.Log($"[RoomCalibration] Stanza calibrata: A={a}, B={b}, distanza {Vector3.ProjectOnPlane(b - a, Vector3.up).magnitude:F2} m, rotazione Y {rot.eulerAngles.y:F0}°.");
    }

    // Punta del controller destro: origine del raggio (posa "aim") + un piccolo scarto avanti.
    Vector3 TipPosition()
    {
        if (_rightRay != null) return _rightRay.transform.position + _rightRay.transform.forward * tipOffset;

        // senza un Ray Interactor: posa della mano, spostata un po' avanti
        var dev = InputDevices.GetDeviceAtXRNode(XRNode.RightHand);
        if (dev.TryGetFeatureValue(CommonUsages.devicePosition, out Vector3 p) && dev.TryGetFeatureValue(CommonUsages.deviceRotation, out Quaternion r))
        {
            Transform space = _xr.CameraFloorOffsetObject != null ? _xr.CameraFloorOffsetObject.transform : _xr.transform;
            return space.TransformPoint(p) + (space.rotation * r) * Vector3.forward * (tipOffset + 0.05f);
        }
        return _xr.Camera.transform.position + _xr.Camera.transform.forward * 0.5f;
    }

    void Haptic()
    {
        var dev = InputDevices.GetDeviceAtXRNode(XRNode.RightHand);
        if (dev.TryGetHapticCapabilities(out var cap) && cap.supportsImpulse) dev.SendHapticImpulse(0, 0.5f, 0.1f);
    }

    // ── Interfaccia ───────────────────────────────────────────────────

    void FollowHead()
    {
        var head = _xr != null && _xr.Camera != null ? _xr.Camera.transform : null;
        if (head == null) return;
        Vector3 fwd = Vector3.ProjectOnPlane(head.forward, Vector3.up);
        fwd = fwd.sqrMagnitude < 0.0001f ? Vector3.forward : fwd.normalized;
        Vector3 target = head.position + fwd * 0.9f + Vector3.up * 0.05f;
        _panel.position = Vector3.Lerp(_panel.position, target, 1f - Mathf.Exp(-6f * Time.unscaledDeltaTime));
        _panel.rotation = Quaternion.LookRotation(_panel.position - head.position, Vector3.up);
    }

    void EnsureUi()
    {
        if (_panel != null) return;

        var go = new GameObject("RoomCalibrationPanel", typeof(RectTransform), typeof(Canvas));
        go.GetComponent<Canvas>().renderMode = RenderMode.WorldSpace;
        var rt = (RectTransform)go.transform;
        rt.sizeDelta = new Vector2(640f, 190f);
        rt.localScale = Vector3.one * 0.001f;
        _panel = rt;

        var bgGo = new GameObject("Background", typeof(RectTransform), typeof(Image));
        bgGo.transform.SetParent(rt, false);
        var bg = bgGo.GetComponent<Image>();
        bg.color = new Color(0.07f, 0.08f, 0.11f, 0.92f);
        bg.raycastTarget = false;
        var brt = bg.rectTransform;
        brt.anchorMin = Vector2.zero; brt.anchorMax = Vector2.one; brt.offsetMin = brt.offsetMax = Vector2.zero;

        var tGo = new GameObject("Text", typeof(RectTransform), typeof(TextMeshProUGUI));
        tGo.transform.SetParent(rt, false);
        _text = tGo.GetComponent<TextMeshProUGUI>();
        _text.fontSize = 26;
        _text.color = new Color(0.95f, 0.96f, 0.98f);
        _text.alignment = TextAlignmentOptions.Center;
        _text.textWrappingMode = TextWrappingModes.Normal;
        _text.richText = true;
        _text.raycastTarget = false;
        var trt = _text.rectTransform;
        trt.anchorMin = Vector2.zero; trt.anchorMax = Vector2.one;
        trt.offsetMin = new Vector2(20f, 10f); trt.offsetMax = new Vector2(-20f, -10f);

        go.SetActive(false);

        var sh = Shader.Find("Sprites/Default");
        _markerMat = new Material(sh != null ? sh : Shader.Find("Standard")) { color = new Color(0.2f, 0.9f, 1f, 0.9f) };
        _tipMarker = MakeMarker("CalibrationTip", new Color(0.2f, 0.9f, 1f, 0.9f), 0.025f);
        _aMarker = MakeMarker("CalibrationPointA", new Color(0.3f, 1f, 0.5f, 0.9f), 0.03f);
    }

    GameObject MakeMarker(string name, Color color, float size)
    {
        var m = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        m.name = name;
        var col = m.GetComponent<Collider>();
        if (col != null) Destroy(col);
        m.transform.localScale = Vector3.one * size;
        var mr = m.GetComponent<MeshRenderer>();
        mr.sharedMaterial = new Material(_markerMat) { color = color };
        mr.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
        mr.receiveShadows = false;
        m.SetActive(false);
        return m;
    }

    void OnDestroy()
    {
        if (_panel != null) Destroy(_panel.gameObject);
        if (_tipMarker != null) Destroy(_tipMarker);
        if (_aMarker != null) Destroy(_aMarker);
        if (_roomOrigin != null) Destroy(_roomOrigin.gameObject);
    }
}
