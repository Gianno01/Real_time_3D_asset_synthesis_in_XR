// ContactShadow.cs
// Piccola ombra morbida sotto ogni oggetto generato (aggiunta automaticamente da QuestObjectGenerator).
//
// In passthrough le ombre "vere" (luce in tempo reale + piano che le riceve) costano molto sul Quest e richiedono
// uno shader apposito. Qui si usa un'ombra di contatto: una macchia scura sfumata, della forma dell'impronta
// dell'oggetto, appoggiata sulla superficie sotto di esso (pavimento, un altro oggetto, un piano AR con collider).
//  • segue l'oggetto mentre lo sposti e lo ruoti;
//  • si allarga e sbiadisce quando lo sollevi (sparisce oltre fadeHeight, di default 2,5 m);
//  • costo quasi nullo: un'immagine UI (shader UI sempre incluso nella build, niente materiali rosa).

using UnityEngine;
using UnityEngine.UI;

public class ContactShadow : MonoBehaviour
{
    [Range(0f, 1f)] public float opacity = 0.55f;
    [Tooltip("Oltre questa altezza dalla superficie l'ombra scompare (m)")]
    public float fadeHeight = 2.5f;
    [Tooltip("Quanto l'ombra è più grande dell'impronta dell'oggetto")]
    public float sizeMultiplier = 1.15f;
    [Tooltip("Altezza del pavimento nel mondo (m)")]
    public float floorHeight = 0f;
    [Tooltip("Distanza massima della superficie cercata sotto l'oggetto (m)")]
    public float maxDistance = 3f;

    [HideInInspector] public Vector3 unscaledSize;   // dimensioni a scala 1, assi dell'oggetto (m)

    static Texture2D s_tex;
    RectTransform _rt;
    RawImage _img;
    readonly RaycastHit[] _hits = new RaycastHit[16];

    public void Init(Vector3 sizeAtScaleOne, float floorY)
    {
        unscaledSize = sizeAtScaleOne;
        floorHeight = floorY;
    }

    void Start()
    {
        if (s_tex == null) s_tex = MakeShadowTexture(128);
        var go = new GameObject($"{name}_Shadow", typeof(RectTransform), typeof(Canvas));
        go.GetComponent<Canvas>().renderMode = RenderMode.WorldSpace;
        go.GetComponent<Canvas>().sortingOrder = -10;   // sotto griglia ed etichette
        _rt = (RectTransform)go.transform;
        _rt.localScale = Vector3.one * 0.001f;         // canvas in mm

        var imgGo = new GameObject("Shadow", typeof(RectTransform), typeof(RawImage));
        imgGo.transform.SetParent(_rt, false);
        _img = imgGo.GetComponent<RawImage>();
        _img.texture = s_tex;
        _img.raycastTarget = false;
        var irt = _img.rectTransform;
        irt.anchorMin = Vector2.zero; irt.anchorMax = Vector2.one;
        irt.offsetMin = irt.offsetMax = Vector2.zero;
    }

    void OnEnable() { if (_rt != null) _rt.gameObject.SetActive(true); }
    void OnDisable() { if (_rt != null) _rt.gameObject.SetActive(false); }
    void OnDestroy() { if (_rt != null) Destroy(_rt.gameObject); }

    void LateUpdate()
    {
        if (_rt == null) return;
        Bounds b = WorldBounds();
        if (b.size.sqrMagnitude <= 0f) { _img.enabled = false; return; }

        float supportY = FindSupport(b);
        float h = b.min.y - supportY;
        if (h < -0.05f || h > fadeHeight) { _img.enabled = false; return; }
        _img.enabled = true;

        float k = Mathf.Clamp01(Mathf.Max(0f, h) / fadeHeight);   // 0 = appoggiato, 1 = al limite
        Vector3 size = Vector3.Scale(unscaledSize, transform.lossyScale);
        float grow = sizeMultiplier * (1f + 0.6f * k);
        _rt.sizeDelta = new Vector2(Mathf.Max(size.x, 0.02f), Mathf.Max(size.z, 0.02f)) * grow * 1000f;

        float yaw = transform.eulerAngles.y;
        _rt.SetPositionAndRotation(new Vector3(b.center.x, supportY + 0.0015f, b.center.z),
                                   Quaternion.Euler(0f, yaw, 0f) * Quaternion.Euler(90f, 0f, 0f));
        _img.color = new Color(0f, 0f, 0f, opacity * (1f - k));   // appoggiato: piena; sollevato: più chiara e più larga
    }

    float FindSupport(Bounds b)
    {
        Vector3 origin = new Vector3(b.center.x, b.min.y + 0.02f, b.center.z);
        int n = Physics.RaycastNonAlloc(origin, Vector3.down, _hits, maxDistance, ~0, QueryTriggerInteraction.Ignore);
        float best = float.NegativeInfinity;
        for (int i = 0; i < n; i++)
        {
            var hit = _hits[i];
            if (hit.collider.transform.IsChildOf(transform)) continue;   // se stesso
            if (hit.point.y > best) best = hit.point.y;
        }
        // la superficie più alta sotto l'oggetto, ma mai sotto il pavimento
        return Mathf.Max(best, floorHeight);
    }

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

    // Rettangolo arrotondato molto sfumato: scuro al centro, trasparente ai bordi
    static Texture2D MakeShadowTexture(int size)
    {
        var tex = new Texture2D(size, size, TextureFormat.RGBA32, false) { wrapMode = TextureWrapMode.Clamp, filterMode = FilterMode.Bilinear };
        var px = new Color32[size * size];
        for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
        {
            float u = Mathf.Abs((x + 0.5f) / size * 2f - 1f), v = Mathf.Abs((y + 0.5f) / size * 2f - 1f);
            float d = Mathf.Pow(Mathf.Pow(u, 4f) + Mathf.Pow(v, 4f), 0.25f);   // superellisse: quasi rettangolare
            float a = 1f - Mathf.SmoothStep(0.35f, 1f, d);
            px[y * size + x] = new Color32(0, 0, 0, (byte)(a * 255f));
        }
        tex.SetPixels32(px);
        tex.Apply(false, true);
        return tex;
    }
}
