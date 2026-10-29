// ContactShadow.cs
// Piccola ombra morbida sotto ogni oggetto generato (aggiunta automaticamente da QuestObjectGenerator).
//
// In passthrough le ombre "vere" (luce in tempo reale + piano che le riceve) costano molto sul Quest e richiedono
// uno shader apposito. Qui si usa un'ombra di contatto: una macchia scura sfumata, della forma dell'impronta
// dell'oggetto, appoggiata sulla superficie sotto di esso (pavimento, scrivania, un altro oggetto).
//  • segue l'oggetto mentre lo sposti e lo ruoti;
//  • si allarga e schiarisce quando lo sollevi (sparisce oltre fadeHeight, di default 2,5 m);
//  • costo quasi nullo: un quadrato con lo shader "Sprites/Default" (sempre incluso nella build, niente materiali rosa).
//
// Perché NON è più un'immagine UI: sul Quest in passthrough un'immagine UI nera semitrasparente viene attenuata due volte
// (il canale alpha si moltiplica per sé stesso) e l'ombra diventa quasi invisibile. "Sprites/Default" scrive l'alpha giusto.
//
// Il log "[ContactShadow] ..." dice, per ogni oggetto, se l'ombra è visibile o nascosta e perché.

using UnityEngine;

public class ContactShadow : MonoBehaviour
{
    [Range(0f, 1f)] public float opacity = 0.85f;
    [Tooltip("Oltre questa altezza dalla superficie l'ombra scompare (m)")]
    public float fadeHeight = 2.5f;
    [Tooltip("Quanto l'ombra è più grande dell'impronta dell'oggetto")]
    public float sizeMultiplier = 1.5f;
    [Tooltip("Altezza del pavimento nel mondo (m)")]
    public float floorHeight = 0f;
    [Tooltip("Distanza massima della superficie cercata sotto l'oggetto (m)")]
    public float maxDistance = 3f;

    [HideInInspector] public Vector3 unscaledSize;   // dimensioni a scala 1, assi dell'oggetto (m)

    static Texture2D s_tex;
    static Mesh s_quad;
    Transform _quad;
    MeshRenderer _mr;
    Material _mat;
    readonly RaycastHit[] _hits = new RaycastHit[16];
    bool _reported, _lastVisible;

    public void Init(Vector3 sizeAtScaleOne, float floorY)
    {
        unscaledSize = sizeAtScaleOne;
        floorHeight = floorY;
    }

    void Start()
    {
        var sh = Shader.Find("Sprites/Default");
        if (sh == null)
        {
            Debug.LogError("[ContactShadow] Shader \"Sprites/Default\" non trovato: ombra disattivata.");
            enabled = false;
            return;
        }
        if (s_tex == null) s_tex = MakeShadowTexture(128);
        if (s_quad == null)
        {
            var tmp = GameObject.CreatePrimitive(PrimitiveType.Quad);
            s_quad = tmp.GetComponent<MeshFilter>().sharedMesh;
            Destroy(tmp);
        }

        _mat = new Material(sh) { name = "ContactShadow", mainTexture = s_tex, color = new Color(0f, 0f, 0f, 0f) };
        var go = new GameObject($"{name}_Shadow", typeof(MeshFilter), typeof(MeshRenderer));
        _quad = go.transform;
        go.GetComponent<MeshFilter>().sharedMesh = s_quad;
        _mr = go.GetComponent<MeshRenderer>();
        _mr.sharedMaterial = _mat;
        _mr.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
        _mr.receiveShadows = false;
        _mr.lightProbeUsage = UnityEngine.Rendering.LightProbeUsage.Off;
        _mr.reflectionProbeUsage = UnityEngine.Rendering.ReflectionProbeUsage.Off;
        _mr.enabled = false;
        go.SetActive(isActiveAndEnabled);
    }

    void OnEnable() { if (_quad != null) _quad.gameObject.SetActive(true); }
    void OnDisable() { if (_quad != null) _quad.gameObject.SetActive(false); }

    void OnDestroy()
    {
        if (_quad != null) Destroy(_quad.gameObject);
        if (_mat != null) Destroy(_mat);
    }

    void LateUpdate()
    {
        if (_quad == null) return;
        Bounds b = WorldBounds();
        if (b.size.sqrMagnitude <= 0f) { Hide("l'oggetto non ha mesh visibili"); return; }

        float supportY = FindSupport(b, out string supportName);
        float h = b.min.y - supportY;
        if (h < -0.05f) { Hide($"l'oggetto è {-h:F2} m SOTTO la superficie trovata ({supportName})"); return; }
        if (h > fadeHeight) { Hide($"troppo alto: {h:F2} m sopra {supportName} (limite {fadeHeight:F1} m)"); return; }

        float k = Mathf.Clamp01(Mathf.Max(0f, h) / fadeHeight);   // 0 = appoggiato, 1 = al limite
        Vector3 size = Vector3.Scale(unscaledSize, transform.lossyScale);
        float grow = sizeMultiplier * (1f + 0.6f * k);
        float sx = Mathf.Max(size.x, 0.02f) * grow, sz = Mathf.Max(size.z, 0.02f) * grow;

        _quad.SetPositionAndRotation(new Vector3(b.center.x, supportY + 0.0015f, b.center.z),
                                     Quaternion.Euler(0f, transform.eulerAngles.y, 0f) * Quaternion.Euler(90f, 0f, 0f));
        _quad.localScale = new Vector3(sx, sz, 1f);

        // appoggiato: piena; sollevato: più chiara e più larga (a 2,5 m resta il 35%)
        float a = opacity * (1f - 0.65f * k);
        _mat.color = new Color(0f, 0f, 0f, a);
        _mr.enabled = true;
        Report(true, $"{h:F2} m sopra {supportName}, opacità {a:F2}, {sx:F2}×{sz:F2} m");
    }

    void Hide(string why)
    {
        if (_mr != null) _mr.enabled = false;
        Report(false, why);
    }

    void Report(bool visible, string why)
    {
        if (_reported && visible == _lastVisible) return;
        _reported = true;
        _lastVisible = visible;
        Debug.Log($"[ContactShadow] {name}: ombra {(visible ? "visibile" : "NASCOSTA")} ({why})");
    }

    float FindSupport(Bounds b, out string supportName)
    {
        Vector3 origin = new Vector3(b.center.x, b.min.y + 0.02f, b.center.z);
        int n = Physics.RaycastNonAlloc(origin, Vector3.down, _hits, maxDistance, ~0, QueryTriggerInteraction.Ignore);
        float best = float.NegativeInfinity;
        supportName = "pavimento";
        for (int i = 0; i < n; i++)
        {
            var hit = _hits[i];
            if (hit.collider.transform.IsChildOf(transform)) continue;   // se stesso
            if (hit.point.y > best) { best = hit.point.y; supportName = $"'{hit.collider.name}'"; }
        }
        // la superficie più alta sotto l'oggetto, ma mai sotto il pavimento
        if (best <= floorHeight) { supportName = "pavimento"; return floorHeight; }
        return best;
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

    // Rettangolo arrotondato: pieno al centro (sotto l'oggetto), sfumato verso i bordi
    static Texture2D MakeShadowTexture(int size)
    {
        var tex = new Texture2D(size, size, TextureFormat.RGBA32, false) { wrapMode = TextureWrapMode.Clamp, filterMode = FilterMode.Bilinear };
        var px = new Color32[size * size];
        for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
        {
            float u = Mathf.Abs((x + 0.5f) / size * 2f - 1f), v = Mathf.Abs((y + 0.5f) / size * 2f - 1f);
            float d = Mathf.Pow(Mathf.Pow(u, 4f) + Mathf.Pow(v, 4f), 0.25f);   // superellisse: quasi rettangolare
            float a = 1f - Mathf.SmoothStep(0.55f, 1f, d);   // piena sotto l'oggetto, sfuma solo nell'ultimo tratto: l'alone resta visibile attorno
            px[y * size + x] = new Color32(0, 0, 0, (byte)(a * 255f));
        }
        tex.SetPixels32(px);
        tex.Apply(false, true);
        return tex;
    }
}
