// MaterializeEffect.cs
// Effetto "si materializza" per un oggetto appena creato: una banda luminosa sale lungo la sagoma (guscio ologramma
// azzurro a righe), poi compare l'oggetto vero con un piccolo "pop" mentre il guscio svanisce.
//
// Come funziona (leggero per il Quest, nessuna modifica ai materiali dell'oggetto):
//  • all'inizio i renderer dell'oggetto vengono nascosti e per ogni mesh si crea un guscio con lo shader
//    "XR/MaterializeShell" (file Resources/MaterializeShell.shader; se manca si ripiega su "Sprites/Default");
//  • la scala passa da 0.8 a 1 tenendo fermo il centro dell'oggetto;
//  • se l'utente afferra l'oggetto durante l'effetto, l'effetto si interrompe subito.
// Si avvia con MaterializeEffect.Begin(oggetto, durata). Chiamarlo dopo che posizione, rotazione e scala sono state impostate
// nello stesso frame: la scala di riferimento viene letta al frame successivo.

using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.Interaction.Toolkit.Interactables;

public class MaterializeEffect : MonoBehaviour
{
    public float duration = 1.6f;
    public Color color = new Color(0.2f, 0.9f, 1f, 1f);
    [Range(0.5f, 1f)] public float startScale = 0.8f;
    [Tooltip("Frazione della durata in cui si vede solo il guscio; poi compare l'oggetto vero")]
    [Range(0.2f, 0.8f)] public float revealAt = 0.55f;

    readonly List<Renderer> _hidden = new();
    readonly List<GameObject> _shells = new();
    Material _mat;
    Vector3 _baseScale, _basePos, _center;
    float _minY, _maxY, _t;
    bool _started, _shown, _finished;
    XRGrabInteractable _grab;

    public static MaterializeEffect Begin(GameObject obj, float duration = 1.6f)
    {
        if (obj == null) return null;
        var old = obj.GetComponent<MaterializeEffect>();
        if (old != null) old.Finish(true);
        var fx = obj.AddComponent<MaterializeEffect>();
        fx.duration = Mathf.Max(0.3f, duration);
        return fx;   // Awake ha già nascosto i renderer: nessun frame con l'oggetto "intero"
    }

    void Awake()
    {
        foreach (var r in GetComponentsInChildren<Renderer>(true))
        {
            if (!r.enabled || r.name.EndsWith("_Shadow")) continue;
            if (r is MeshRenderer || r is SkinnedMeshRenderer) { _hidden.Add(r); r.enabled = false; }
        }
    }

    void Start()
    {
        _baseScale = transform.localScale;
        _basePos = transform.position;
        _grab = GetComponent<XRGrabInteractable>();

        bool any = false; Bounds b = default;
        foreach (var r in _hidden)
        {
            if (r == null) continue;
            if (!any) { b = r.bounds; any = true; } else b.Encapsulate(r.bounds);
        }
        if (!any) { Finish(false); return; }
        _center = b.center; _minY = b.min.y; _maxY = b.max.y;

        var shader = Resources.Load<Shader>("MaterializeShell");
        if (shader == null) shader = Shader.Find("Sprites/Default");
        _mat = new Material(shader) { color = color, hideFlags = HideFlags.HideAndDontSave };
        if (_mat.HasProperty("_Color")) _mat.SetColor("_Color", color);

        foreach (var r in _hidden)
        {
            if (r is not MeshRenderer) continue;
            var mf = r.GetComponent<MeshFilter>();
            if (mf == null || mf.sharedMesh == null) continue;
            var sh = new GameObject("MaterializeShell", typeof(MeshFilter), typeof(MeshRenderer));
            sh.transform.SetParent(r.transform, false);
            sh.GetComponent<MeshFilter>().sharedMesh = mf.sharedMesh;
            var mr = sh.GetComponent<MeshRenderer>();
            mr.sharedMaterial = _mat;
            mr.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
            mr.receiveShadows = false;
            _shells.Add(sh);
        }
        _started = true;
        Apply(0f);
    }

    void Update()
    {
        if (!_started || _finished) return;
        if (_grab != null && _grab.isSelected) { Finish(false); return; }   // l'utente l'ha afferrato: stop

        _t += Time.deltaTime;
        float p = Mathf.Clamp01(_t / duration);
        Apply(p);
        if (p >= 1f) Finish(true);
    }

    void Apply(float p)
    {
        // guscio: la banda sale da sotto a sopra, poi il guscio svanisce
        float scan = Mathf.SmoothStep(0f, 1f, Mathf.Clamp01(p / revealAt));
        float band = 0.08f * Mathf.Max(0.2f, _maxY - _minY) + 0.02f;
        float reveal = Mathf.Lerp(_minY, _maxY + band, scan);
        float fade = p < revealAt ? 1f : 1f - Mathf.SmoothStep(0f, 1f, (p - revealAt) / (1f - revealAt));
        if (_mat != null)
        {
            if (_mat.HasProperty("_Reveal")) { _mat.SetFloat("_Reveal", reveal); _mat.SetFloat("_Band", band); _mat.SetFloat("_Fade", fade); }
            else _mat.color = new Color(color.r, color.g, color.b, fade * 0.6f);   // ripiego senza shader dedicato
        }

        // l'oggetto vero compare quando la banda ha finito di salire
        if (!_shown && p >= revealAt) { _shown = true; foreach (var r in _hidden) if (r != null) r.enabled = true; }

        // scala con un piccolo rimbalzo, tenendo fermo il centro
        float k = Mathf.LerpUnclamped(startScale, 1f, EaseOutBack(Mathf.Clamp01(p)));
        transform.localScale = _baseScale * k;
        transform.position = _center + (_basePos - _center) * k;
    }

    static float EaseOutBack(float x)
    {
        const float c1 = 1.2f, c3 = c1 + 1f;
        float u = x - 1f;
        return 1f + c3 * u * u * u + c1 * u * u;
    }

    void Finish(bool restore)
    {
        if (_finished) return;
        _finished = true;
        foreach (var r in _hidden) if (r != null) r.enabled = true;
        foreach (var s in _shells) if (s != null) Destroy(s);
        if (_mat != null) Destroy(_mat);
        if (_started)
        {
            transform.localScale = _baseScale;                 // la scala va sempre ripristinata
            if (restore) transform.position = _basePos;        // la posizione solo se non l'ha già mossa l'utente
        }
        Destroy(this);
    }

    void OnDestroy()
    {
        if (_finished) return;
        foreach (var r in _hidden) if (r != null) r.enabled = true;
        foreach (var s in _shells) if (s != null) Destroy(s);
        if (_mat != null) Destroy(_mat);
    }
}
