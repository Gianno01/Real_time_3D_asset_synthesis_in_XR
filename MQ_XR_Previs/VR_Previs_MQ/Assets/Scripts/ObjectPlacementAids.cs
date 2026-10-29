// ObjectPlacementAids.cs
// Aiuti al posizionamento per gli oggetti generati (aggiunto automaticamente da QuestObjectGenerator).
//
//  • Griglia sotto l'oggetto mentre lo tieni in mano: allineata al MONDO (le linee restano ferme nello spazio
//    mentre l'oggetto si muove), utile per allineare più oggetti tra loro.
//  • Misure sopra l'oggetto: base (larghezza × profondità) e altezza in cm, aggiornate mentre lo sposti e lo scali.
//  • Aggancio al rilascio (opzionale):
//      - l'oggetto torna dritto e la rotazione scatta a passi di yawStep gradi;
//      - la posizione orizzontale si allinea alla griglia (gridStep);
//      - se sotto c'è una superficie entro surfaceSnapDistance (un altro oggetto, un piano AR, il pavimento)
//        l'oggetto ci si appoggia sopra.
//
// Grafica fatta con UI in world space (shader UI sempre inclusi nella build: niente materiali rosa).

using System.Collections;
using TMPro;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.XR.Interaction.Toolkit.Interactables;

public class ObjectPlacementAids : MonoBehaviour
{
    [Header("Visualizzazione")]
    public bool showGrid = true;
    public bool showDimensions = true;
    [Tooltip("Per quanti secondi griglia e misure restano visibili dopo il rilascio")]
    public float lingerSeconds = 1.5f;
    [Tooltip("Quante celle della griglia ci sono sul lato più lungo dell'oggetto: la griglia è proporzionale all'oggetto (si rimpicciolisce con lui)")]
    public float gridDivisions = 5f;

    [Header("Aggancio al rilascio")]
    public bool snapOnRelease = true;
    [Tooltip("Passo di allineamento orizzontale (m). 0 = disattivato")]
    public float gridStep = 0.05f;
    [Tooltip("Passo della rotazione (gradi). 0 = mantiene la rotazione libera")]
    public float yawStep = 15f;
    [Tooltip("Distanza massima (m) per appoggiarsi a una superficie sottostante")]
    public float surfaceSnapDistance = 0.15f;
    [Tooltip("Altezza del pavimento nel mondo (m): con Tracking Origin = Floor è 0")]
    public float floorHeight = 0f;

    [HideInInspector] public Vector3 unscaledSize;   // dimensioni dell'oggetto a scala 1 (m)
    [HideInInspector] public Transform head;

    static Texture2D s_gridTex;

    XRGrabInteractable _grab;
    bool _grabbed;
    float _visibleUntil;
    Coroutine _snapRoutine;

    RectTransform _gridRt;
    RawImage _gridImg;
    CanvasGroup _gridGroup;
    RectTransform _labelRt;
    CanvasGroup _labelGroup;
    TextMeshProUGUI _label;

    // ── Inizializzazione ──────────────────────────────────────────────

    public void Init(Vector3 sizeAtScaleOne, Transform headTransform)
    {
        unscaledSize = sizeAtScaleOne;
        head = headTransform;
    }

    void Start()
    {
        _grab = GetComponent<XRGrabInteractable>();
        if (_grab != null)
        {
            _grab.selectEntered.AddListener(_ => OnGrab());
            _grab.selectExited.AddListener(_ => { if (!_grab.isSelected) OnRelease(); });
        }
        if (s_gridTex == null) s_gridTex = MakeGridTexture(128, 3);
        BuildVisuals();
    }

    void OnDestroy()
    {
        if (_gridRt != null) Destroy(_gridRt.gameObject);
        if (_labelRt != null) Destroy(_labelRt.gameObject);
    }

    bool Locked { get { if (_so == null) _so = GetComponent<SceneObject>(); return _so != null && _so.locked; } }
    SceneObject _so;

    void OnGrab()
    {
        if (Locked) return;   // oggetto bloccato: niente griglia, misure né aggancio
        _grabbed = true;
        if (_snapRoutine != null) { StopCoroutine(_snapRoutine); _snapRoutine = null; }
    }

    void OnRelease()
    {
        if (Locked) return;
        _grabbed = false;
        _visibleUntil = Time.time + lingerSeconds;
        if (snapOnRelease) _snapRoutine = StartCoroutine(SnapRoutine());
    }

    // ── Ogni frame ────────────────────────────────────────────────────

    void LateUpdate()
    {
        bool visible = _grabbed || Time.time < _visibleUntil;
        float dt = Time.deltaTime;
        if (_gridGroup != null) _gridGroup.alpha = Mathf.MoveTowards(_gridGroup.alpha, visible && showGrid ? 1f : 0f, dt * 6f);
        if (_labelGroup != null) _labelGroup.alpha = Mathf.MoveTowards(_labelGroup.alpha, visible && showDimensions ? 1f : 0f, dt * 6f);
        if ((_gridGroup == null || _gridGroup.alpha <= 0f) && (_labelGroup == null || _labelGroup.alpha <= 0f)) return;

        Bounds b = WorldBounds();
        Vector3 size = CurrentSize();

        // Griglia: sotto l'oggetto, piatta, allineata agli assi del mondo
        if (_gridRt != null)
        {
            float maxDim = Mathf.Max(Mathf.Max(size.x, size.z), 0.02f);
            float side = maxDim * 1.8f;                                   // tutto proporzionale all'oggetto
            float gridCell = side / (gridDivisions * 1.8f);               // = maxDim / gridDivisions
            Vector3 c = new Vector3(b.center.x, b.min.y + 0.002f, b.center.z);
            _gridRt.position = c;
            _gridRt.rotation = Quaternion.Euler(90f, 0f, 0f);
            _gridRt.sizeDelta = new Vector2(side, side) * 1000f;   // canvas in mm (scala 0.001)
            float cells = side / gridCell;
            _gridImg.uvRect = new Rect((c.x - side / 2f) / gridCell, (c.z - side / 2f) / gridCell, cells, cells);
        }

        // Misure: sopra l'oggetto, rivolte verso di te
        if (_labelRt != null)
        {
            _labelRt.position = new Vector3(b.center.x, b.max.y + 0.06f, b.center.z);
            if (head != null)
            {
                Vector3 look = _labelRt.position - head.position;
                if (look.sqrMagnitude > 0.0001f) _labelRt.rotation = Quaternion.LookRotation(look, Vector3.up);
            }
            _label.text = $"<b>{Cm(size.x)} × {Cm(size.z)}</b> cm  ·  H <b>{Cm(size.y)}</b> cm";
        }
    }

    /// <summary>Dimensioni reali attuali (m): larghezza, altezza, profondità, indipendenti dalla rotazione.</summary>
    public Vector3 CurrentSize() => Vector3.Scale(unscaledSize, transform.lossyScale);

    static string Cm(float meters) => Mathf.RoundToInt(meters * 100f).ToString();

    Bounds WorldBounds()
    {
        var rs = GetComponentsInChildren<Renderer>();
        bool has = false;
        var b = new Bounds(transform.position, Vector3.zero);
        foreach (var r in rs)
        {
            if (r.bounds.size.sqrMagnitude <= 0f) continue;
            if (!has) { b = r.bounds; has = true; } else b.Encapsulate(r.bounds);
        }
        return b;
    }

    // ── Aggancio ──────────────────────────────────────────────────────

    IEnumerator SnapRoutine()
    {
        Vector3 startPos = transform.position;
        Quaternion startRot = transform.rotation;

        // 1) dritto + rotazione a scatti
        Quaternion targetRot = startRot;
        if (yawStep > 0f)
        {
            float yaw = Mathf.Round(startRot.eulerAngles.y / yawStep) * yawStep;
            targetRot = Quaternion.Euler(0f, yaw, 0f);
        }

        // calcolo dei bounds nella rotazione finale
        transform.rotation = targetRot;
        Bounds b = WorldBounds();
        transform.rotation = startRot;
        Vector3 targetPos = startPos;

        // 2) posizione orizzontale sulla griglia (si allinea il centro dei bounds)
        if (gridStep > 0f)
        {
            // il passo non supera mai la cella della griglia visibile: su un oggetto piccolo l'aggancio è più fine
            Vector3 sz = CurrentSize();
            float step = Mathf.Min(gridStep, Mathf.Max(Mathf.Max(sz.x, sz.z), 0.02f) / gridDivisions);
            float nx = Mathf.Round(b.center.x / step) * step;
            float nz = Mathf.Round(b.center.z / step) * step;
            targetPos += new Vector3(nx - b.center.x, 0f, nz - b.center.z);
            b.center += new Vector3(nx - b.center.x, 0f, nz - b.center.z);
        }

        // 3) appoggio su una superficie sottostante (altro oggetto, piano AR, pavimento)
        if (surfaceSnapDistance > 0f && TryFindSupport(b, out float supportY))
            targetPos.y += supportY - b.min.y;

        // animazione breve verso la posa agganciata
        const float duration = 0.12f;
        for (float t = 0f; t < duration; t += Time.deltaTime)
        {
            float k = Mathf.SmoothStep(0f, 1f, t / duration);
            transform.SetPositionAndRotation(Vector3.Lerp(startPos, targetPos, k), Quaternion.Slerp(startRot, targetRot, k));
            yield return null;
        }
        transform.SetPositionAndRotation(targetPos, targetRot);
        var col = GetComponent<ObjectCollision>();
        if (col != null) col.ResolveNow();   // l'aggancio non deve far entrare l'oggetto in un altro
        _snapRoutine = null;
    }

    bool TryFindSupport(Bounds b, out float supportY)
    {
        supportY = 0f;
        float bottom = b.min.y;
        Vector3 origin = new Vector3(b.center.x, b.max.y + 0.01f, b.center.z);
        float maxDist = (b.max.y - b.min.y) + surfaceSnapDistance + 0.01f;

        float best = float.NegativeInfinity;
        foreach (var hit in Physics.RaycastAll(origin, Vector3.down, maxDist, ~0, QueryTriggerInteraction.Ignore))
        {
            if (hit.collider.transform.IsChildOf(transform)) continue;   // se stesso
            if (hit.point.y > bottom + surfaceSnapDistance) continue;      // troppo in alto (dentro l'oggetto)
            if (hit.point.y > best) best = hit.point.y;
        }
        if (best > float.NegativeInfinity && Mathf.Abs(bottom - best) <= surfaceSnapDistance)
        {
            supportY = best;
            return true;
        }

        // pavimento
        if (Mathf.Abs(bottom - floorHeight) <= surfaceSnapDistance)
        {
            supportY = floorHeight;
            return true;
        }
        return false;
    }

    // ── Grafica (UI in world space) ───────────────────────────────────

    void BuildVisuals()
    {
        // Griglia
        var gridGo = new GameObject($"{name}_Grid", typeof(RectTransform), typeof(Canvas), typeof(CanvasGroup));
        gridGo.GetComponent<Canvas>().renderMode = RenderMode.WorldSpace;
        _gridRt = (RectTransform)gridGo.transform;
        _gridRt.localScale = Vector3.one * 0.001f;
        _gridGroup = gridGo.GetComponent<CanvasGroup>();
        _gridGroup.alpha = 0f;
        _gridGroup.interactable = false;
        _gridGroup.blocksRaycasts = false;

        var imgGo = new GameObject("GridImage", typeof(RectTransform), typeof(RawImage));
        imgGo.transform.SetParent(_gridRt, false);
        _gridImg = imgGo.GetComponent<RawImage>();
        _gridImg.texture = s_gridTex;
        _gridImg.color = new Color(0.55f, 0.75f, 1f, 0.75f);
        _gridImg.raycastTarget = false;
        var irt = _gridImg.rectTransform;
        irt.anchorMin = Vector2.zero; irt.anchorMax = Vector2.one;
        irt.offsetMin = irt.offsetMax = Vector2.zero;

        // Etichetta misure
        var labelGo = new GameObject($"{name}_Size", typeof(RectTransform), typeof(Canvas), typeof(CanvasGroup));
        labelGo.GetComponent<Canvas>().renderMode = RenderMode.WorldSpace;
        _labelRt = (RectTransform)labelGo.transform;
        _labelRt.sizeDelta = new Vector2(360, 56);
        _labelRt.localScale = Vector3.one * 0.0008f;
        _labelGroup = labelGo.GetComponent<CanvasGroup>();
        _labelGroup.alpha = 0f;
        _labelGroup.interactable = false;
        _labelGroup.blocksRaycasts = false;

        var bgGo = new GameObject("Bg", typeof(RectTransform), typeof(Image));
        bgGo.transform.SetParent(_labelRt, false);
        var bg = bgGo.GetComponent<Image>();
        bg.color = new Color(0.07f, 0.08f, 0.11f, 0.85f);
        bg.raycastTarget = false;
        var brt = bg.rectTransform;
        brt.anchorMin = Vector2.zero; brt.anchorMax = Vector2.one;
        brt.offsetMin = brt.offsetMax = Vector2.zero;

        var txtGo = new GameObject("Text", typeof(RectTransform), typeof(TextMeshProUGUI));
        txtGo.transform.SetParent(_labelRt, false);
        _label = txtGo.GetComponent<TextMeshProUGUI>();
        _label.fontSize = 26;
        _label.alignment = TextAlignmentOptions.Center;
        _label.color = new Color(0.95f, 0.96f, 0.98f);
        _label.raycastTarget = false;
        _label.richText = true;
        var trt = _label.rectTransform;
        trt.anchorMin = Vector2.zero; trt.anchorMax = Vector2.one;
        trt.offsetMin = trt.offsetMax = Vector2.zero;
    }

    // Texture di una cella: bordo luminoso su fondo trasparente (ripetuta con uvRect)
    static Texture2D MakeGridTexture(int size, int line)
    {
        var tex = new Texture2D(size, size, TextureFormat.RGBA32, true)
        {
            wrapMode = TextureWrapMode.Repeat,
            filterMode = FilterMode.Trilinear,
            anisoLevel = 4
        };
        var px = new Color32[size * size];
        for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
        {
            bool edge = x < line || y < line;
            px[y * size + x] = edge ? new Color32(255, 255, 255, 255) : new Color32(255, 255, 255, 18);
        }
        tex.SetPixels32(px);
        tex.Apply(true, true);
        return tex;
    }
}
