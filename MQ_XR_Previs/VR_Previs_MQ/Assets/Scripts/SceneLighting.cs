// SceneLighting.cs
// Luci virtuali, oscuramento della stanza e blocchi di occlusione invisibili.
//
//  • OSCURAMENTO   una vela nera (shader XR/DimOverlay) copre il passthrough all'80-90% (regolabile).
//                  Anche luce ambiente e luci direzionali della scena virtuale vengono abbassate della stessa quantità.
//  • LUCE          punto luce o faro (spot) che si prende con il controller e si sposta nella stanza.
//                  Temperatura (Kelvin), intensità, raggio e angolo si cambiano dal pannello. Illumina gli OGGETTI VIRTUALI.
//  • BLOCCO        parallelepipedo invisibile che scrive solo la profondità (shader XR/DepthOcclusion): gli oggetti virtuali
//                  che finiscono dietro non vengono disegnati e si vede la stanza vera. Si sposta, si ruota e si ridimensiona.
//  • SALVATAGGIO   luci, blocchi e oscuramento viaggiano dentro la scena (AssetLibrary → campo "extras"), con le posizioni
//                  relative all'ancora della stanza come gli oggetti: si salvano e si ricaricano con "Salva scena".
//
// LIMITE NOTO: le luci virtuali non illuminano le superfici VERE (pareti, tavolo): il Quest Pro non ha un sensore di profondità
// e l'app non conosce la geometria della stanza. L'oscuramento è solo "meno luce reale"; l'effetto luce si vede sugli oggetti generati.
//
// SETUP: nessuno per lo script (SettingsUI lo crea da solo). Servono nella cartella Resources:
//        DimOverlay.shader e DepthOcclusion.shader. Si apre da Impostazioni → STANZA → Luci e oscuramento.

using System;
using System.Collections.Generic;
using TMPro;
using Unity.XR.CoreUtils;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.XR;
using UnityEngine.XR.Interaction.Toolkit.Interactables;
using UnityEngine.XR.Interaction.Toolkit.Interactors;
using UnityEngine.XR.Interaction.Toolkit.UI;

[Serializable]
public class LightData
{
    public int kind;                         // 0 = punto, 1 = faro (spot)
    public float px, py, pz;                 // posizione relativa all'ancora
    public float rx, ry, rz, rw = 1f;        // rotazione relativa all'ancora (direzione del faro)
    public float kelvin = 3200f, intensity = 1.5f, range = 4f, angle = 60f;
}

[Serializable]
public class BlockData
{
    public float px, py, pz;
    public float rx, ry, rz, rw = 1f;
    public float sx = 0.5f, sy = 0.5f, sz = 0.5f;   // dimensioni in metri (per il cilindro: sx e sz sono i diametri)
    public int shape;                        // 0 = scatola, 1 = cilindro
}

[Serializable]
public class LightingData
{
    public int version = 1;
    public bool dimOn;
    public float dim = 0.85f;
    public List<LightData> lights = new List<LightData>();
    public List<BlockData> blocks = new List<BlockData>();
}

public class SceneLighting : MonoBehaviour
{
    [Header("Riferimenti (se vuoti vengono cercati nella scena)")]
    public AssetLibrary library;
    public QuestObjectGenerator generator;

    [Header("Oscuramento")]
    [Range(0f, 0.95f)] public float dim = 0.85f;
    [Tooltip("Luci e oscuramento attivi")] public bool lightingOn = false;
    [Tooltip("Abbassa anche luce ambiente e luci direzionali della scena virtuale con l'oscuramento")]
    public bool dimVirtualAmbient = true;

    [Header("Blocchi di occlusione")]
    [Tooltip("I blocchi nascondono gli oggetti virtuali che finiscono dietro")] public bool blocksEnabled = true;

    [Header("Pannello")]
    public float panelDistance = 0.75f;
    public float panelHeightOffset = -0.05f;

    public bool PanelOpen => _panel != null && _panel.gameObject.activeSelf;

    public string StatusLabel
    {
        get
        {
            string s = lightingOn ? $"Oscurato {Mathf.RoundToInt(dim * 100f)}%" : "Spento";
            return $"{s} - {_lights.Count} luci, {_blocks.Count} blocchi";
        }
    }

    public static SceneLighting EnsureExists(GameObject where)
    {
        var s = FindAnyObjectByType<SceneLighting>();
        if (s == null) s = where.AddComponent<SceneLighting>();
        return s;
    }

    // ── Elementi ──────────────────────────────────────────────────────

    class LightItem { public LightData d; public GameObject go; public Light light; public Renderer gizmo, arrowRenderer; public Transform arrow; public Material gizmoMat, arrowMat; public SpriteRenderer halo; }
    class BlockItem { public BlockData d; public GameObject go; public MeshFilter depthMf, visMf; public Renderer depth, vis; public Collider col; public LineRenderer edges; public Collider phys; public int physShape = -1; public XRGrabInteractable grab; }

    readonly List<LightItem> _lights = new List<LightItem>();
    readonly List<BlockItem> _blocks = new List<BlockItem>();
    LightItem _selLight;
    BlockItem _selBlock;

    Material _dimMat, _depthMat, _visMat, _gizmoBase;
    GameObject _overlay;
    bool _started;
    float _lastBlockW = 0.5f, _lastBlockH = 0.5f, _lastBlockD = 0.5f;
    /// <summary>Mentre modifichi i blocchi sono trasparenti e non nascondono nulla; con questo acceso nascondono anche in modifica (anteprima).</summary>
    public bool previewOcclusion = false;

    // ambiente originale
    bool _envCaptured;
    UnityEngine.Rendering.AmbientMode _ambMode;
    float _ambIntensity;
    Color _ambLight, _ambSky, _ambEq, _ambGround;
    readonly List<(Light light, float intensity)> _dirs = new List<(Light, float)>();

    static readonly Color BlockColor = new Color(0.30f, 0.80f, 1.00f, 0.22f);
    static readonly Color BlockSel   = new Color(1.00f, 0.85f, 0.25f, 0.34f);

    // ── Lifecycle ─────────────────────────────────────────────────────

    void Start()
    {
        if (library == null) library = FindAnyObjectByType<AssetLibrary>();
        if (generator == null) generator = FindAnyObjectByType<QuestObjectGenerator>();
        if (library != null)
        {
            library.SceneExtrasProvider = SerializeExtras;
            library.SceneExtrasApplier = ApplyExtras;
        }
        _started = true;
        ApplyAll();
    }

    void OnDestroy()
    {
        foreach (var ri in _capRays) if (ri != null) ri.enabled = true;
        if (library != null)
        {
            if (library.SceneExtrasProvider == (Func<string>)SerializeExtras) library.SceneExtrasProvider = null;
            if (library.SceneExtrasApplier == (Action<string>)ApplyExtras) library.SceneExtrasApplier = null;
        }
        RestoreEnvironment();
    }

    void OnDisable() { if (_overlay != null) _overlay.SetActive(false); }
    void OnEnable() { if (_started) ApplyAll(); }

    Transform Anchor => library != null ? library.sceneAnchor : null;

    Vector3 ToLocal(Vector3 w) => Anchor != null ? Anchor.InverseTransformPoint(w) : w;
    Quaternion ToLocal(Quaternion w) => Anchor != null ? Quaternion.Inverse(Anchor.rotation) * w : w;
    Vector3 ToWorld(Vector3 l) => Anchor != null ? Anchor.TransformPoint(l) : l;
    Quaternion ToWorld(Quaternion l) => Anchor != null ? Anchor.rotation * l : l;

    // ── Salvataggio (agganciato ad AssetLibrary) ──────────────────────

    /// <summary>JSON con luci, blocchi e oscuramento. Stringa vuota se non c'è nulla da salvare.</summary>
    public string SerializeExtras()
    {
        if (_lights.Count == 0 && _blocks.Count == 0 && !lightingOn) return "";
        var data = new LightingData { dimOn = lightingOn, dim = dim };
        foreach (var l in _lights)
        {
            SyncFromTransform(l);
            data.lights.Add(l.d);
        }
        foreach (var b in _blocks)
        {
            SyncFromTransform(b);
            data.blocks.Add(b.d);
        }
        return JsonUtility.ToJson(data);
    }

    /// <summary>Ricostruisce luci, blocchi e oscuramento da un JSON (vuoto = niente luci, oscuramento spento).</summary>
    public void ApplyExtras(string json)
    {
        ClearAllItems();
        var data = new LightingData();
        if (!string.IsNullOrEmpty(json))
        {
            try { data = JsonUtility.FromJson<LightingData>(json) ?? data; }
            catch (Exception e) { Debug.LogWarning("[SceneLighting] Dati luci non leggibili: " + e.Message); data = new LightingData(); }
        }
        lightingOn = !string.IsNullOrEmpty(json) && data.dimOn;
        dim = Mathf.Clamp(data.dim <= 0f ? 0.85f : data.dim, 0f, 0.95f);
        foreach (var d in data.lights) CreateLight(d, false);
        foreach (var d in data.blocks) CreateBlock(d, false);
        Select((LightItem)null);
        ApplyAll();
        RefreshPanel();
    }

    void SyncFromTransform(LightItem l)
    {
        if (l.go == null) return;
        Vector3 p = ToLocal(l.go.transform.position);
        Quaternion q = ToLocal(l.go.transform.rotation);
        l.d.px = p.x; l.d.py = p.y; l.d.pz = p.z;
        l.d.rx = q.x; l.d.ry = q.y; l.d.rz = q.z; l.d.rw = q.w;
    }

    void SyncFromTransform(BlockItem b)
    {
        if (b.go == null) return;
        Vector3 p = ToLocal(b.go.transform.position);
        Quaternion q = ToLocal(b.go.transform.rotation);
        b.d.px = p.x; b.d.py = p.y; b.d.pz = p.z;
        b.d.rx = q.x; b.d.ry = q.y; b.d.rz = q.z; b.d.rw = q.w;
    }

    // ── Applicazione dello stato ──────────────────────────────────────

    void ApplyAll()
    {
        if (!_started) return;
        ApplyDim();
        foreach (var l in _lights) ApplyLight(l);
        foreach (var b in _blocks) ApplyBlock(b);
    }

    public void SetLightingOn(bool on) { lightingOn = on; ApplyAll(); RefreshPanel(); }
    public void SetDim(float v) { dim = Mathf.Clamp(v, 0f, 0.95f); ApplyAll(); RefreshPanel(); }
    public void SetBlocksEnabled(bool on) { blocksEnabled = on; ApplyAll(); RefreshPanel(); }

    /// <summary>Blocchi e luci si vedono (e si prendono) solo mentre il pannello è aperto o stai inserendo un blocco da 4 punti.</summary>
    bool Editing => PanelOpen || _cap != Cap.None;

    void ApplyDim()
    {
        bool active = lightingOn && dim > 0.001f;

        if (active)
        {
            EnsureOverlay();
            if (_overlay != null)
            {
                _overlay.SetActive(true);
                if (_dimMat != null) _dimMat.SetFloat("_Dim", dim);
            }
            CaptureEnvironment();
            ScaleEnvironment(dimVirtualAmbient ? 1f - dim : 1f);
        }
        else
        {
            if (_overlay != null) _overlay.SetActive(false);
            RestoreEnvironment();
        }

        // le luci virtuali funzionano solo quando "Luci e oscuramento" è acceso (così si può confrontare con/senza)
        foreach (var l in _lights) if (l.light != null) l.light.enabled = lightingOn;
    }

    void EnsureOverlay()
    {
        if (_overlay != null) return;
        var sh = Shader.Find("XR/DimOverlay");
        if (sh == null)
        {
            Debug.LogError("[SceneLighting] Shader XR/DimOverlay non trovato: metti DimOverlay.shader in Assets/Resources.");
            return;
        }
        _dimMat = new Material(sh) { name = "DimOverlay" };

        var mesh = new Mesh { name = "FullscreenQuad" };
        mesh.vertices = new[] { new Vector3(-0.5f, -0.5f, 0), new Vector3(0.5f, -0.5f, 0), new Vector3(0.5f, 0.5f, 0), new Vector3(-0.5f, 0.5f, 0) };
        mesh.triangles = new[] { 0, 2, 1, 0, 3, 2 };
        mesh.bounds = new Bounds(Vector3.zero, Vector3.one * 100000f);   // mai scartata dal frustum culling

        _overlay = new GameObject("DimOverlay");
        _overlay.transform.SetParent(transform, false);
        _overlay.AddComponent<MeshFilter>().sharedMesh = mesh;
        var mr = _overlay.AddComponent<MeshRenderer>();
        mr.sharedMaterial = _dimMat;
        mr.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
        mr.receiveShadows = false;
    }

    // luce ambiente e luci direzionali della scena virtuale
    void CaptureEnvironment()
    {
        if (_envCaptured) return;
        _envCaptured = true;
        _ambMode = RenderSettings.ambientMode;
        _ambIntensity = RenderSettings.ambientIntensity;
        _ambLight = RenderSettings.ambientLight;
        _ambSky = RenderSettings.ambientSkyColor;
        _ambEq = RenderSettings.ambientEquatorColor;
        _ambGround = RenderSettings.ambientGroundColor;
        _dirs.Clear();
        foreach (var l in FindObjectsByType<Light>(FindObjectsSortMode.None))
            if (l.type == LightType.Directional && !IsOurs(l)) _dirs.Add((l, l.intensity));
    }

    bool IsOurs(Light l) { foreach (var x in _lights) if (x.light == l) return true; return false; }

    void ScaleEnvironment(float k)
    {
        if (!_envCaptured) return;
        RenderSettings.ambientIntensity = _ambIntensity * k;
        RenderSettings.ambientLight = _ambLight * k;
        RenderSettings.ambientSkyColor = _ambSky * k;
        RenderSettings.ambientEquatorColor = _ambEq * k;
        RenderSettings.ambientGroundColor = _ambGround * k;
        foreach (var (light, intensity) in _dirs) if (light != null) light.intensity = intensity * k;
    }

    void RestoreEnvironment()
    {
        if (!_envCaptured) return;
        RenderSettings.ambientMode = _ambMode;
        RenderSettings.ambientIntensity = _ambIntensity;
        RenderSettings.ambientLight = _ambLight;
        RenderSettings.ambientSkyColor = _ambSky;
        RenderSettings.ambientEquatorColor = _ambEq;
        RenderSettings.ambientGroundColor = _ambGround;
        foreach (var (light, intensity) in _dirs) if (light != null) light.intensity = intensity;
        _dirs.Clear();
        _envCaptured = false;
    }

    // ── Luci ──────────────────────────────────────────────────────────

    static Color KelvinToColor(float kelvin)
    {
        float t = Mathf.Clamp(kelvin, 1000f, 40000f) / 100f;
        float r, g, b;
        if (t <= 66f)
        {
            r = 255f;
            g = 99.4708025861f * Mathf.Log(t) - 161.1195681661f;
            b = t <= 19f ? 0f : 138.5177312231f * Mathf.Log(t - 10f) - 305.0447927307f;
        }
        else
        {
            r = 329.698727446f * Mathf.Pow(t - 60f, -0.1332047592f);
            g = 288.1221695283f * Mathf.Pow(t - 60f, -0.0755148492f);
            b = 255f;
        }
        return new Color(Mathf.Clamp01(r / 255f), Mathf.Clamp01(g / 255f), Mathf.Clamp01(b / 255f), 1f);
    }

    Material NewGizmoMaterial()
    {
        if (_gizmoBase == null) _gizmoBase = new Material(Shader.Find("Sprites/Default"));
        return new Material(_gizmoBase);
    }

    static Sprite _glowSprite;
    static Sprite GlowSprite()
    {
        if (_glowSprite != null) return _glowSprite;
        const int n = 64;
        var tex = new Texture2D(n, n, TextureFormat.RGBA32, false) { wrapMode = TextureWrapMode.Clamp, filterMode = FilterMode.Bilinear };
        var px = new Color32[n * n];
        for (int y = 0; y < n; y++)
        for (int x = 0; x < n; x++)
        {
            float dx = (x + 0.5f) / n * 2f - 1f, dy = (y + 0.5f) / n * 2f - 1f;
            float r = Mathf.Sqrt(dx * dx + dy * dy);
            float a = Mathf.Pow(Mathf.Clamp01(1f - r), 2.2f);
            px[y * n + x] = new Color32(255, 255, 255, (byte)(a * 255f));
        }
        tex.SetPixels32(px);
        tex.Apply(false, true);
        _glowSprite = Sprite.Create(tex, new Rect(0, 0, n, n), new Vector2(0.5f, 0.5f), n);   // larga 1 unità
        return _glowSprite;
    }

    LightItem CreateLight(LightData d, bool selectIt)
    {
        var go = new GameObject("SceneLight");
        go.transform.SetParent(transform, true);
        go.transform.SetPositionAndRotation(ToWorld(new Vector3(d.px, d.py, d.pz)),
            ToWorld(new Quaternion(d.rx, d.ry, d.rz, d.rw == 0f && d.rx == 0f && d.ry == 0f && d.rz == 0f ? 1f : d.rw)));

        var item = new LightItem { d = d, go = go };

        var lg = new GameObject("Light");
        lg.transform.SetParent(go.transform, false);
        item.light = lg.AddComponent<Light>();
        item.light.shadows = LightShadows.None;       // le ombre in tempo reale pesano troppo sul Quest
        item.light.renderMode = LightRenderMode.ForcePixel;

        // lampadina: nucleo chiaro + alone sfumato che guarda sempre verso di te (sembra una sorgente luminosa, non un puntino)
        var vis = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        vis.name = "Lampadina";
        Destroy(vis.GetComponent<Collider>());
        vis.transform.SetParent(go.transform, false);
        vis.transform.localScale = Vector3.one * 0.06f;
        item.gizmo = vis.GetComponent<Renderer>();
        item.gizmo.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
        item.gizmo.receiveShadows = false;

        var haloGo = new GameObject("Alone");
        haloGo.transform.SetParent(go.transform, false);
        item.halo = haloGo.AddComponent<SpriteRenderer>();
        item.halo.sprite = GlowSprite();
        item.halo.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
        item.halo.receiveShadows = false;

        var arrow = GameObject.CreatePrimitive(PrimitiveType.Cube);
        arrow.name = "Direzione";
        Destroy(arrow.GetComponent<Collider>());
        arrow.transform.SetParent(go.transform, false);
        arrow.transform.localPosition = new Vector3(0f, 0f, 0.12f);
        arrow.transform.localScale = new Vector3(0.012f, 0.012f, 0.16f);
        item.arrowRenderer = arrow.GetComponent<Renderer>();
        item.arrowRenderer.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
        item.arrow = arrow.transform;
        item.gizmoMat = NewGizmoMaterial();
        item.arrowMat = NewGizmoMaterial();
        item.arrowMat.color = new Color(1f, 1f, 1f, 0.9f);
        item.gizmo.sharedMaterial = item.gizmoMat;
        item.arrowRenderer.sharedMaterial = item.arrowMat;

        MakeGrabbable(go, () => Select(item), 0.12f);

        _lights.Add(item);
        ApplyLight(item);
        if (selectIt) Select(item);
        return item;
    }

    void ApplyLight(LightItem l)
    {
        if (l.go == null) return;
        var d = l.d;
        d.kelvin = Mathf.Clamp(d.kelvin, 1500f, 10000f);
        d.intensity = Mathf.Clamp(d.intensity, 0.1f, 10f);
        d.range = Mathf.Clamp(d.range, 0.5f, 20f);
        d.angle = Mathf.Clamp(d.angle, 20f, 120f);

        Color c = KelvinToColor(d.kelvin);
        l.light.type = d.kind == 1 ? LightType.Spot : LightType.Point;
        l.light.color = c;
        l.light.intensity = d.intensity;
        l.light.range = d.range;
        if (d.kind == 1) { l.light.spotAngle = d.angle; l.light.innerSpotAngle = d.angle * 0.7f; }
        l.light.enabled = lightingOn;

        // la lampadina con l'alone si vede quando le luci sono attive (o mentre modifichi); la barretta di direzione solo in modifica
        bool bulb = lightingOn || Editing;
        l.gizmo.enabled = bulb;
        l.halo.enabled = bulb;
        l.arrow.gameObject.SetActive(Editing && d.kind == 1);

        l.gizmoMat.color = Color.Lerp(c, Color.white, 0.55f);                       // nucleo quasi bianco, tinto dalla temperatura
        l.gizmo.transform.localScale = Vector3.one * (l == _selLight ? 0.085f : 0.06f);
        float glow = Mathf.Clamp(0.20f + 0.07f * d.intensity, 0.2f, 0.8f);
        l.halo.color = new Color(c.r, c.g, c.b, Mathf.Clamp01(0.40f + 0.08f * d.intensity));
        l.halo.transform.localScale = Vector3.one * (l == _selLight ? glow * 1.25f : glow);

        var col = l.go.GetComponent<Collider>();
        if (col != null) col.enabled = Editing;
    }

    // ── Blocchi ───────────────────────────────────────────────────────

    static Mesh _cubeMesh, _cylMesh;
    static void EnsureMeshes()
    {
        if (_cubeMesh != null && _cylMesh != null) return;
        var c = GameObject.CreatePrimitive(PrimitiveType.Cube);
        _cubeMesh = c.GetComponent<MeshFilter>().sharedMesh;
        Destroy(c);
        var y = GameObject.CreatePrimitive(PrimitiveType.Cylinder);   // diametro 1, altezza 2
        _cylMesh = y.GetComponent<MeshFilter>().sharedMesh;
        Destroy(y);
    }

    // punti dello spigolo (spazio locale, scatola/cilindro unitari centrati nell'origine)
    static Vector3[] _boxEdges, _cylEdges;
    static Vector3[] EdgePoints(int shape)
    {
        if (shape == 1)
        {
            if (_cylEdges != null) return _cylEdges;
            const int n = 32;
            var pts = new List<Vector3>();
            for (int i = 0; i <= n; i++) { float a = i * Mathf.PI * 2f / n; pts.Add(new Vector3(Mathf.Cos(a) * 0.5f, -0.5f, Mathf.Sin(a) * 0.5f)); }
            for (int i = 0; i <= n; i++)
            {
                float a = i * Mathf.PI * 2f / n;
                var top = new Vector3(Mathf.Cos(a) * 0.5f, 0.5f, Mathf.Sin(a) * 0.5f);
                var bot = new Vector3(top.x, -0.5f, top.z);
                if (i == 0) pts.Add(top);
                else
                {
                    pts.Add(top);
                    if (i % 8 == 0 && i < n) { pts.Add(bot); pts.Add(top); }   // 4 linee verticali
                }
            }
            return _cylEdges = pts.ToArray();
        }
        if (_boxEdges != null) return _boxEdges;
        Vector3 b0 = new Vector3(-.5f, -.5f, -.5f), b1 = new Vector3(.5f, -.5f, -.5f), b2 = new Vector3(.5f, -.5f, .5f), b3 = new Vector3(-.5f, -.5f, .5f);
        Vector3 t0 = b0 + Vector3.up, t1 = b1 + Vector3.up, t2 = b2 + Vector3.up, t3 = b3 + Vector3.up;
        return _boxEdges = new[] { b0, b1, b2, b3, b0, t0, t1, t2, t3, t0, t1, b1, b2, t2, t3, b3 };
    }

    BlockItem CreateBlock(BlockData d, bool selectIt)
    {
        EnsureMeshes();
        var go = new GameObject("OcclusionBlock");
        go.transform.SetParent(transform, true);
        go.transform.SetPositionAndRotation(ToWorld(new Vector3(d.px, d.py, d.pz)),
            ToWorld(new Quaternion(d.rx, d.ry, d.rz, d.rw == 0f && d.rx == 0f && d.ry == 0f && d.rz == 0f ? 1f : d.rw)));
        go.transform.localScale = new Vector3(d.sx, d.sy, d.sz);

        var item = new BlockItem { d = d, go = go };

        // collider: sempre la scatola che contiene la forma (serve solo per prenderlo in mano)
        var box = go.AddComponent<BoxCollider>();
        box.size = Vector3.one;
        item.col = box;

        // forma che scrive solo la profondità (invisibile)
        var dg = new GameObject("Profondita");
        dg.transform.SetParent(go.transform, false);
        item.depthMf = dg.AddComponent<MeshFilter>();
        item.depth = dg.AddComponent<MeshRenderer>();
        item.depth.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
        item.depth.receiveShadows = false;
        if (_depthMat == null)
        {
            var sh = Shader.Find("XR/DepthOcclusion");
            if (sh == null) Debug.LogError("[SceneLighting] Shader XR/DepthOcclusion non trovato: metti DepthOcclusion.shader in Assets/Resources.");
            else _depthMat = new Material(sh) { name = "BlockDepth" };
        }
        if (_depthMat != null) item.depth.sharedMaterial = _depthMat;

        // involucro azzurro trasparente + spigoli, solo in modifica
        var vg = new GameObject("Vis");
        vg.transform.SetParent(go.transform, false);
        item.visMf = vg.AddComponent<MeshFilter>();
        item.vis = vg.AddComponent<MeshRenderer>();
        item.vis.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
        item.vis.receiveShadows = false;
        if (_visMat == null) _visMat = new Material(Shader.Find("Sprites/Default"));
        item.vis.sharedMaterial = new Material(_visMat) { color = BlockColor };

        var eg = new GameObject("Spigoli");
        eg.transform.SetParent(transform, false);   // coordinate del mondo: la larghezza della linea non dipende dalla scala del blocco
        item.edges = eg.AddComponent<LineRenderer>();
        item.edges.useWorldSpace = true;
        item.edges.widthMultiplier = 0.004f;
        item.edges.numCapVertices = 0;
        item.edges.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
        item.edges.sharedMaterial = new Material(_visMat) { color = new Color(0.55f, 0.9f, 1f, 0.95f) };

        item.grab = MakeGrabbable(go, () => Select(item), 0f);

        _blocks.Add(item);
        ApplyBlock(item);
        if (selectIt) Select(item);
        return item;
    }

    void ApplyBlock(BlockItem b)
    {
        if (b.go == null) return;
        EnsureMeshes();
        var d = b.d;
        d.sx = Mathf.Clamp(d.sx, 0.05f, 6f); d.sy = Mathf.Clamp(d.sy, 0.05f, 6f); d.sz = Mathf.Clamp(d.sz, 0.05f, 6f);
        b.go.transform.localScale = new Vector3(d.sx, d.sy, d.sz);

        bool cyl = d.shape == 1;
        b.depthMf.sharedMesh = cyl ? _cylMesh : _cubeMesh;
        b.visMf.sharedMesh = cyl ? _cylMesh : _cubeMesh;
        Vector3 shapeScale = cyl ? new Vector3(1f, 0.5f, 1f) : Vector3.one;   // il cilindro di Unity è alto 2
        b.depth.transform.localScale = shapeScale;
        b.vis.transform.localScale = shapeScale * 1.01f;

        // scena normale: la forma nasconde ciò che sta dietro ma non si vede. In modifica non nasconde niente (resta solo l'involucro trasparente).
        b.depth.enabled = blocksEnabled && (!Editing || previewOcclusion);
        bool showVis = Editing;
        b.vis.enabled = showVis;
        b.edges.enabled = showVis;
        b.vis.sharedMaterial.color = b == _selBlock ? BlockSel : BlockColor;
        b.edges.widthMultiplier = b == _selBlock ? 0.007f : 0.004f;
        b.edges.sharedMaterial.color = b == _selBlock ? new Color(1f, 0.9f, 0.4f, 1f) : new Color(0.55f, 0.9f, 1f, 0.95f);
        // COLLISIONE: la forma vera (scatola o cilindro) resta sempre solida, anche a pannello chiuso, così gli oggetti ci si appoggiano
        if (b.physShape != d.shape)
        {
            if (b.phys != null) Destroy(b.phys);
            if (cyl)
            {
                var mc = b.depth.gameObject.AddComponent<MeshCollider>();
                mc.sharedMesh = _cylMesh;
                mc.convex = true;
                b.phys = mc;
            }
            else b.phys = b.depth.gameObject.AddComponent<BoxCollider>();   // 1 m: la scala la dà il blocco
            b.physShape = d.shape;
        }
        b.phys.enabled = blocksEnabled;
        // PRESA: solo in modifica. A pannello chiuso il blocco non si può prendere né intercetta la selezione dei controller.
        if (b.col != null) b.col.enabled = Editing;
        if (b.grab != null) b.grab.enabled = Editing;
        UpdateEdges(b);
    }

    void UpdateEdges(BlockItem b)
    {
        if (b.go == null || b.edges == null || !b.edges.enabled) return;
        var pts = EdgePoints(b.d.shape);
        if (b.edges.positionCount != pts.Length) b.edges.positionCount = pts.Length;
        var t = b.go.transform;
        for (int i = 0; i < pts.Length; i++) b.edges.SetPosition(i, t.TransformPoint(pts[i]));
    }

    void Update()
    {
        // alone delle lampadine: sempre rivolto verso di te
        var head = generator != null ? generator.Head : null;
        if (head != null)
            foreach (var l in _lights)
                if (l.halo != null && l.halo.enabled)
                {
                    Vector3 dir = l.halo.transform.position - head.position;
                    if (dir.sqrMagnitude > 0.0001f) l.halo.transform.rotation = Quaternion.LookRotation(dir, Vector3.up);
                }
        if (Editing) foreach (var b in _blocks) UpdateEdges(b);
        if (_cap != Cap.None) UpdateCapture();
    }

    // ── Presa con il controller ───────────────────────────────────────

    XRGrabInteractable MakeGrabbable(GameObject go, Action onSelected, float sphereRadius)
    {
        if (sphereRadius > 0f)
        {
            var sc = go.AddComponent<SphereCollider>();
            sc.radius = sphereRadius;
        }
        var rb = go.AddComponent<Rigidbody>();
        rb.useGravity = false;
        rb.isKinematic = true;

        var grab = go.AddComponent<XRGrabInteractable>();
        grab.movementType = XRBaseInteractable.MovementType.Instantaneous;
        grab.useDynamicAttach = true;
        grab.throwOnDetach = false;
        grab.selectEntered.AddListener(_ => { onSelected(); });
        return grab;
    }

    // ── Selezione e modifica ──────────────────────────────────────────

    void Select(LightItem l)
    {
        var prevL = _selLight; var prevB = _selBlock;
        _selLight = l; _selBlock = null;
        if (prevL != null) ApplyLight(prevL);
        if (prevB != null) ApplyBlock(prevB);
        if (l != null) ApplyLight(l);
        RefreshPanel();
    }

    void Select(BlockItem b)
    {
        var prevL = _selLight; var prevB = _selBlock;
        _selLight = null; _selBlock = b;
        if (prevL != null) ApplyLight(prevL);
        if (prevB != null) ApplyBlock(prevB);
        if (b != null) ApplyBlock(b);
        RefreshPanel();
    }

    void SelectNext(int dir)
    {
        int total = _lights.Count + _blocks.Count;
        if (total == 0) return;
        int cur = _selLight != null ? _lights.IndexOf(_selLight) : _selBlock != null ? _lights.Count + _blocks.IndexOf(_selBlock) : -1;
        int next = cur < 0 ? (dir > 0 ? 0 : total - 1) : ((cur + dir) % total + total) % total;
        if (next < _lights.Count) Select(_lights[next]); else Select(_blocks[next - _lights.Count]);
    }

    Vector3 SpawnPoint()
    {
        var head = generator != null ? generator.Head : (Camera.main != null ? Camera.main.transform : null);
        if (head == null) return transform.position + Vector3.forward;
        Vector3 fwd = Vector3.ProjectOnPlane(head.forward, Vector3.up);
        if (fwd.sqrMagnitude < 0.001f) fwd = Vector3.forward;
        // a lato del pannello, così non ci finisce sopra
        return head.position + fwd.normalized * 0.9f + head.right * 0.35f - Vector3.up * 0.15f;
    }

    void AddLight(int kind)
    {
        string warn = LightingWarning();
        if (warn != null) Debug.LogWarning("[SceneLighting] " + warn);
        if (!lightingOn) { lightingOn = true; }
        var d = new LightData { kind = kind };
        Vector3 p = ToLocal(SpawnPoint());
        d.px = p.x; d.py = p.y; d.pz = p.z;
        if (kind == 1)
        {
            // il faro parte puntato in avanti e un po' in basso
            Quaternion q = ToLocal(Quaternion.Euler(30f, generator != null && generator.Head != null ? generator.Head.eulerAngles.y : 0f, 0f));
            d.rx = q.x; d.ry = q.y; d.rz = q.z; d.rw = q.w;
        }
        CreateLight(d, true);
        ApplyAll();
    }

    void AddBlock()
    {
        var d = new BlockData { sx = _lastBlockW, sy = _lastBlockH, sz = _lastBlockD };
        Vector3 p = ToLocal(SpawnPoint());
        d.px = p.x; d.py = p.y; d.pz = p.z;
        if (generator != null && generator.Head != null)
        {
            Quaternion q = ToLocal(Quaternion.Euler(0f, generator.Head.eulerAngles.y, 0f));
            d.rx = q.x; d.ry = q.y; d.rz = q.z; d.rw = q.w;
        }
        CreateBlock(d, true);
        ApplyAll();
    }

    void DuplicateBlock()
    {
        if (_selBlock == null) return;
        SyncFromTransform(_selBlock);
        var d = JsonUtility.FromJson<BlockData>(JsonUtility.ToJson(_selBlock.d));
        Vector3 w = ToWorld(new Vector3(d.px, d.py, d.pz)) + _selBlock.go.transform.right * (d.sx + 0.05f);
        Vector3 p = ToLocal(w);
        d.px = p.x; d.py = p.y; d.pz = p.z;
        CreateBlock(d, true);
        ApplyAll();
    }

    void DeleteSelected()
    {
        if (_selLight != null)
        {
            var l = _selLight;
            _lights.Remove(l);
            if (l.go != null) Destroy(l.go);
            _selLight = null;
        }
        else if (_selBlock != null)
        {
            var b = _selBlock;
            _blocks.Remove(b);
            if (b.go != null) Destroy(b.go);
            if (b.edges != null) Destroy(b.edges.gameObject);
            _selBlock = null;
        }
        RefreshPanel();
    }

    void ClearAllItems()
    {
        foreach (var l in _lights) if (l.go != null) Destroy(l.go);
        foreach (var b in _blocks) { if (b.go != null) Destroy(b.go); if (b.edges != null) Destroy(b.edges.gameObject); }
        _lights.Clear(); _blocks.Clear();
        _selLight = null; _selBlock = null;
    }

    // ── Blocco da 4 punti (come la calibrazione) ──────────────────────
    // Tocchi con la punta del controller destro i 4 angoli (es. di un tavolo) e premi il grilletto su ognuno;
    // poi un punto in alto per l'altezza. Il blocco prende la base dai 4 punti (rettangolo orientato lungo il primo lato).
    // Per il cilindro gli stessi 4 punti, sul bordo, danno i diametri.
    // Comandi: grilletto = conferma punto · A = annulla l'ultimo punto · B = esci.

    enum Cap { None, Corners, Height }
    Cap _cap;
    bool _capCylinder;
    readonly List<Vector3> _capPts = new List<Vector3>();
    readonly List<GameObject> _capMarkers = new List<GameObject>();
    readonly List<XRRayInteractor> _capRays = new List<XRRayInteractor>();
    XRRayInteractor _capRightRay;
    XROrigin _xr;
    GameObject _capTip;
    LineRenderer _capLine;
    RectTransform _capPanel;
    TextMeshProUGUI _capText;
    bool _capPrevTrig = true, _capPrevA = true, _capPrevB = true;

    void BeginCapture(bool cylinder)
    {
        if (_cap != Cap.None) return;
        _xr = FindAnyObjectByType<XROrigin>();
        if (generator == null) generator = FindAnyObjectByType<QuestObjectGenerator>();
        _capCylinder = cylinder;
        EnsureCaptureUi();

        // i raggi si spengono: il grilletto non deve premere pulsanti né afferrare oggetti
        _capRays.Clear(); _capRightRay = null;
        foreach (var ri in FindObjectsByType<XRRayInteractor>(FindObjectsSortMode.None))
        {
            if (_capRightRay == null && IsRight(ri)) _capRightRay = ri;
            if (ri.enabled) { ri.enabled = false; _capRays.Add(ri); }
        }
        if (_panel != null) _panel.gameObject.SetActive(false);
        FindAnyObjectByType<SettingsUI>()?.Hide();

        _capPts.Clear();
        foreach (var m in _capMarkers) if (m != null) Destroy(m);
        _capMarkers.Clear();
        _capPrevTrig = _capPrevA = _capPrevB = true;   // i tasti usati per aprire il comando non contano
        _cap = Cap.Corners;
        _capPanel.gameObject.SetActive(true);
        _capTip.SetActive(true);
        _capLine.enabled = true;
        ApplyAll();
    }

    void EndCapture(bool reopenPanel)
    {
        foreach (var ri in _capRays) if (ri != null) ri.enabled = true;
        _capRays.Clear();
        _cap = Cap.None;
        if (_capPanel != null) _capPanel.gameObject.SetActive(false);
        if (_capTip != null) _capTip.SetActive(false);
        if (_capLine != null) _capLine.enabled = false;
        foreach (var m in _capMarkers) if (m != null) Destroy(m);
        _capMarkers.Clear();
        _capPts.Clear();
        if (reopenPanel) OpenPanel(); else ApplyAll();
    }

    static bool IsRight(XRRayInteractor ri) => ri.handedness.ToString() == "Right" || ri.name.ToLowerInvariant().Contains("right");

    Vector3 TipPosition()
    {
        if (_capRightRay != null) return _capRightRay.transform.position + _capRightRay.transform.forward * 0.02f;
        var dev = InputDevices.GetDeviceAtXRNode(XRNode.RightHand);
        if (_xr != null && dev.TryGetFeatureValue(CommonUsages.devicePosition, out Vector3 p) && dev.TryGetFeatureValue(CommonUsages.deviceRotation, out Quaternion r))
        {
            Transform space = _xr.CameraFloorOffsetObject != null ? _xr.CameraFloorOffsetObject.transform : _xr.transform;
            return space.TransformPoint(p) + (space.rotation * r) * Vector3.forward * 0.07f;
        }
        var head = generator != null ? generator.Head : null;
        return head != null ? head.position + head.forward * 0.5f : Vector3.zero;
    }

    void UpdateCapture()
    {
        var head = generator != null ? generator.Head : null;
        if (head != null)
        {
            Vector3 fwd = Vector3.ProjectOnPlane(head.forward, Vector3.up);
            fwd = fwd.sqrMagnitude < 0.0001f ? Vector3.forward : fwd.normalized;
            Vector3 target = head.position + fwd * 0.9f + Vector3.up * 0.12f;
            _capPanel.position = Vector3.Lerp(_capPanel.position, target, 1f - Mathf.Exp(-6f * Time.unscaledDeltaTime));
            _capPanel.rotation = Quaternion.LookRotation(_capPanel.position - head.position, Vector3.up);
        }

        Vector3 tip = TipPosition();
        _capTip.transform.position = tip;

        var dev = InputDevices.GetDeviceAtXRNode(XRNode.RightHand);
        bool trig = false, a = false, b = false;
        dev.TryGetFeatureValue(CommonUsages.triggerButton, out trig);
        dev.TryGetFeatureValue(CommonUsages.primaryButton, out a);
        dev.TryGetFeatureValue(CommonUsages.secondaryButton, out b);
        bool trigDown = trig && !_capPrevTrig, aDown = a && !_capPrevA, bDown = b && !_capPrevB;
        _capPrevTrig = trig; _capPrevA = a; _capPrevB = b;

        if (bDown) { EndCapture(true); return; }

        string what = _capCylinder ? "Cilindro" : "Blocco";
        if (_cap == Cap.Corners)
        {
            int n = _capPts.Count;
            _capText.text = $"<b>{what}: angolo {n + 1} di 4</b>\nPoggia la punta del controller destro su un angolo\n(in ordine, partendo da uno spigolo) e premi il <b>grilletto</b>\n<size=70%>A = annulla l'ultimo punto - B = esci</size>";
            if (trigDown)
            {
                _capPts.Add(tip);
                var m = GameObject.CreatePrimitive(PrimitiveType.Sphere);
                Destroy(m.GetComponent<Collider>());
                m.transform.position = tip;
                m.transform.localScale = Vector3.one * 0.03f;
                var mr = m.GetComponent<Renderer>();
                mr.sharedMaterial = new Material(Shader.Find("Sprites/Default")) { color = new Color(0.3f, 1f, 0.5f, 0.95f) };
                mr.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
                _capMarkers.Add(m);
                Haptic();
                if (_capPts.Count >= 4) _cap = Cap.Height;
            }
            else if (aDown && n > 0)
            {
                _capPts.RemoveAt(n - 1);
                Destroy(_capMarkers[n - 1]);
                _capMarkers.RemoveAt(n - 1);
            }
            // linea dai punti già presi fino alla punta del controller
            var pts = new List<Vector3>(_capPts);
            if (_cap == Cap.Corners) pts.Add(tip);
            _capLine.positionCount = pts.Count;
            for (int i = 0; i < pts.Count; i++) _capLine.SetPosition(i, pts[i]);
        }
        else
        {
            float baseY = 0f; foreach (var p in _capPts) baseY += p.y; baseY /= _capPts.Count;
            float h = tip.y - baseY;   // positivo = verso l'alto, negativo = verso il basso
            string dirTxt = Mathf.Abs(h) < 0.03f ? "" : (h > 0f ? "verso l'alto" : "verso il basso");
            _capText.text = $"<b>{what}: altezza</b>\nTocca un punto <b>più in alto o più in basso</b> della base (es. il pavimento sotto i piedi del tavolo) e premi il <b>grilletto</b>\n<size=85%>{Mathf.Abs(h) * 100f:0} cm {dirTxt}</size>\n<size=70%>A = usa {Mathf.RoundToInt(_lastBlockH * 100f)} cm verso l'alto - B = esci</size>";
            var pts = new List<Vector3>(_capPts) { _capPts[0] };   // base chiusa
            _capLine.positionCount = pts.Count;
            for (int i = 0; i < pts.Count; i++) _capLine.SetPosition(i, pts[i]);
            if (trigDown) { Haptic(); FinishCapture(Mathf.Abs(h) > 0.03f ? h : _lastBlockH); }
            else if (aDown) FinishCapture(_lastBlockH);
        }
    }

    void FinishCapture(float signedHeight)
    {
        // base orizzontale a quota media; asse lungo il primo lato
        float baseY = 0f; foreach (var p in _capPts) baseY += p.y; baseY /= _capPts.Count;
        Vector3 origin = _capPts[0];
        Vector3 u = Vector3.ProjectOnPlane(_capPts[1] - _capPts[0], Vector3.up);
        if (u.sqrMagnitude < 0.0004f) u = Vector3.right;
        u.Normalize();
        Vector3 f = Vector3.Cross(u, Vector3.up);   // avanti tale che destra = u
        float minA = float.MaxValue, maxA = float.MinValue, minB = float.MaxValue, maxB = float.MinValue;
        foreach (var p in _capPts)
        {
            Vector3 r = p - origin;
            float pa = Vector3.Dot(r, u), pb = Vector3.Dot(r, f);
            minA = Mathf.Min(minA, pa); maxA = Mathf.Max(maxA, pa);
            minB = Mathf.Min(minB, pb); maxB = Mathf.Max(maxB, pb);
        }
        float sx = Mathf.Max(0.05f, maxA - minA), sz = Mathf.Max(0.05f, maxB - minB);
        if (_capCylinder && Mathf.Abs(sx - sz) < 0.08f * (sx + sz) * 0.5f) sx = sz = (sx + sz) * 0.5f;   // quasi tondo → tondo
        float h = Mathf.Max(0.05f, Mathf.Abs(signedHeight));
        float dirSign = signedHeight < 0f ? -1f : 1f;   // verso il basso: il blocco va dalla base 4 punti giù fino al punto toccato

        Vector3 center = origin + u * ((minA + maxA) * 0.5f) + f * ((minB + maxB) * 0.5f);
        center.y = baseY + dirSign * h * 0.5f;

        Vector3 lp = ToLocal(center);
        Quaternion lq = ToLocal(Quaternion.LookRotation(f, Vector3.up));
        var d = new BlockData
        {
            px = lp.x, py = lp.y, pz = lp.z, rx = lq.x, ry = lq.y, rz = lq.z, rw = lq.w,
            sx = sx, sy = h, sz = sz, shape = _capCylinder ? 1 : 0,
        };
        _lastBlockW = sx; _lastBlockH = h; _lastBlockD = sz;
        CreateBlock(d, true);
        EndCapture(true);
    }

    void Haptic()
    {
        var dev = InputDevices.GetDeviceAtXRNode(XRNode.RightHand);
        if (dev.TryGetHapticCapabilities(out var cap) && cap.supportsImpulse) dev.SendHapticImpulse(0, 0.5f, 0.1f);
    }

    void EnsureCaptureUi()
    {
        if (_capPanel != null) return;
        if (_rounded == null) _rounded = MakeRoundedSprite(64, 24);

        var go = new GameObject("BlockCapturePanel", typeof(RectTransform), typeof(Canvas));
        go.transform.SetParent(transform, false);
        go.GetComponent<Canvas>().renderMode = RenderMode.WorldSpace;
        _capPanel = (RectTransform)go.transform;
        _capPanel.sizeDelta = new Vector2(680f, 200f);
        _capPanel.localScale = Vector3.one * 0.001f;
        var bg = Img(_capPanel, "Background", _rounded, new Color(0.07f, 0.08f, 0.11f, 0.92f), true, 1f);
        Stretch(bg.rectTransform);
        _capText = Txt(_capPanel, "Text", 26, FontStyles.Normal, TextMain, TextAlignmentOptions.Center);
        _capText.richText = true;
        Stretch(_capText.rectTransform);
        _capText.rectTransform.offsetMin = new Vector2(20f, 10f);
        _capText.rectTransform.offsetMax = new Vector2(-20f, -10f);
        go.SetActive(false);

        _capTip = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        _capTip.name = "CapturePunta";
        Destroy(_capTip.GetComponent<Collider>());
        _capTip.transform.localScale = Vector3.one * 0.025f;
        var tr = _capTip.GetComponent<Renderer>();
        tr.sharedMaterial = new Material(Shader.Find("Sprites/Default")) { color = new Color(0.2f, 0.9f, 1f, 0.95f) };
        tr.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
        _capTip.transform.SetParent(transform, true);
        _capTip.SetActive(false);

        var lg = new GameObject("CaptureLinea");
        lg.transform.SetParent(transform, false);
        _capLine = lg.AddComponent<LineRenderer>();
        _capLine.useWorldSpace = true;
        _capLine.widthMultiplier = 0.005f;
        _capLine.sharedMaterial = new Material(Shader.Find("Sprites/Default")) { color = new Color(0.3f, 1f, 0.5f, 0.95f) };
        _capLine.enabled = false;
    }

    // ── Pannello ──────────────────────────────────────────────────────

    const float W = 760f, RowH = 48f, Pitch = 56f;
    static readonly Color CardBg   = new Color(0.07f, 0.08f, 0.11f, 0.96f);
    static readonly Color BtnBg    = new Color(1f, 1f, 1f, 0.11f);
    static readonly Color TextMain = new Color(0.95f, 0.96f, 0.98f);
    static readonly Color TextDim  = new Color(0.60f, 0.64f, 0.72f);
    static readonly Color Accent   = new Color(0.20f, 0.45f, 1.00f);
    // i bottoni moltiplicano il colore x2 (colorMultiplier): qui la metà del colore voluto
    static readonly Color OnBlue   = new Color(0.05f, 0.13f, 0.43f, 0.50f);   // → blu scuro
    static readonly Color DelRed   = new Color(0.48f, 0.04f, 0.04f, 0.50f);   // → rosso acceso
    static readonly Color OkCol    = new Color(0.33f, 0.86f, 0.56f);
    static readonly Color BadCol   = new Color(1.00f, 0.43f, 0.41f);

    RectTransform _panel;
    Sprite _rounded;
    GameObject _groupLight, _groupBlock;
    TextMeshProUGUI _selLabel, _hint;
    Image _onBg, _blocksOnBg;
    TextMeshProUGUI _onLabel, _blocksOnLabel, _shapeLabel, _previewLabel;
    Image _previewBg;
    readonly List<Action> _refreshers = new List<Action>();

    public void OpenPanel()
    {
        if (_panel == null) BuildPanel();
        PlacePanel();
        _panel.gameObject.SetActive(true);
        ApplyAll();
        RefreshPanel();
    }

    public void ClosePanel()
    {
        if (_panel != null) _panel.gameObject.SetActive(false);
        ApplyAll();
    }

    void PlacePanel()
    {
        var head = generator != null ? generator.Head : (Camera.main != null ? Camera.main.transform : null);
        if (head == null) return;
        Vector3 fwd = Vector3.ProjectOnPlane(head.forward, Vector3.up);
        if (fwd.sqrMagnitude < 0.001f) fwd = Vector3.forward;
        fwd.Normalize();
        Vector3 pos = head.position + fwd * panelDistance + Vector3.up * panelHeightOffset;
        _panel.position = pos;
        _panel.rotation = Quaternion.LookRotation((pos - head.position).normalized, Vector3.up);
    }

    /// <summary>Avviso se la pipeline URP non calcola le luci aggiuntive (allora le luci virtuali non illuminano nulla).</summary>
    static string LightingWarning()
    {
        try
        {
            var rp = UnityEngine.Rendering.GraphicsSettings.currentRenderPipeline;
            if (rp == null || !rp.GetType().Name.Contains("Universal")) return null;
            var pi = rp.GetType().GetProperty("additionalLightsRenderingMode");
            if (pi == null) return null;
            var v = pi.GetValue(rp, null);
            if (v != null && v.ToString() == "Disabled")
                return "ATTENZIONE: nell'asset URP \"Additional Lights\" è Disabled, quindi le luci non illuminano gli oggetti. In Unity: menu XR, Attiva luci aggiuntive (URP), poi rifai la build.";
        }
        catch (Exception) { }
        return null;
    }

    void RefreshPanel()
    {
        if (!PanelOpen) return;
        foreach (var r in _refreshers) r();
        if (_groupLight != null) _groupLight.SetActive(_selLight != null);
        if (_groupBlock != null) _groupBlock.SetActive(_selBlock != null);
        if (_selLabel != null)
        {
            if (_selLight != null) _selLabel.text = $"Luce {_lights.IndexOf(_selLight) + 1} ({(_selLight.d.kind == 1 ? "faro" : "puntiforme")})";
            else if (_selBlock != null) _selLabel.text = $"{(_selBlock.d.shape == 1 ? "Cilindro" : "Blocco")} {_blocks.IndexOf(_selBlock) + 1}";
            else _selLabel.text = "Prendi una luce o un blocco col controller";
        }
        SetToggle(_onBg, _onLabel, lightingOn, "Luci: attive", "Luci: spente");
        SetToggle(_blocksOnBg, _blocksOnLabel, blocksEnabled, "Blocchi: attivi", "Blocchi: spenti");
        if (_selBlock != null)
        {
            if (_shapeLabel != null) _shapeLabel.text = _selBlock.d.shape == 1 ? "Forma: cilindro" : "Forma: scatola";
            SetToggle(_previewBg, _previewLabel, previewOcclusion, "Anteprima: sì", "Anteprima: no");
        }
        if (_hint != null)
        {
            string warn = LightingWarning();
            _hint.text = warn ?? "Luci e blocchi si salvano con la scena (Libreria, Salva scena). In modifica i blocchi sono trasparenti.";
            _hint.color = warn != null ? new Color(1f, 0.65f, 0.3f) : TextDim;
        }
    }

    void SetToggle(Image bg, TextMeshProUGUI label, bool on, string onText, string offText)
    {
        if (bg == null || label == null) return;
        bg.color = on ? OnBlue : BtnBg;
        label.text = on ? onText : offText;
    }

    void BuildPanel()
    {
        _rounded = MakeRoundedSprite(64, 24);

        var go = new GameObject("LightingCanvas", typeof(RectTransform), typeof(Canvas), typeof(TrackedDeviceGraphicRaycaster));
        go.transform.SetParent(transform, false);
        go.GetComponent<Canvas>().renderMode = RenderMode.WorldSpace;
        _panel = (RectTransform)go.transform;
        _panel.localScale = Vector3.one * 0.0009f;

        // altezze dei due gruppi (luce / blocco) per calcolare quella del pannello
        const float lightGroupH = 56f + 48f + 56f + 56f + 56f + RowH;
        const float blockGroupH = 4f * Pitch + Pitch + RowH;
        const float gy = 70f + 5f * Pitch + 4f;
        float H = gy + Mathf.Max(lightGroupH, blockGroupH) + 70f;
        _panel.sizeDelta = new Vector2(W, H);

        var bg = Img(_panel, "Background", _rounded, CardBg, true, 1f);
        Stretch(bg.rectTransform);
        bg.raycastTarget = true;

        var title = Txt(_panel, "Title", 28, FontStyles.Bold, TextMain, TextAlignmentOptions.MidlineLeft);
        Place(title.rectTransform, 24, 12, 520, 44);
        title.text = "Luci e occlusione";
        Btn(_panel, "Chiudi", W - 24 - 150, 12, 150, 44, ClosePanel, 22);

        float half = (W - 48f - 10f) / 2f;
        float y = 70f;

        // interruttori
        var onBtn = Btn(_panel, "", 24, y, half, RowH, () => SetLightingOn(!lightingOn), 20);
        _onBg = onBtn.GetComponent<Image>(); _onLabel = onBtn.GetComponentInChildren<TextMeshProUGUI>();
        var bBtn = Btn(_panel, "", 24 + half + 10f, y, half, RowH, () => SetBlocksEnabled(!blocksEnabled), 20);
        _blocksOnBg = bBtn.GetComponent<Image>(); _blocksOnLabel = bBtn.GetComponentInChildren<TextMeshProUGUI>();
        y += Pitch;

        Stepper(_panel, "Oscuramento", y, () => $"{Mathf.RoundToInt(dim * 100f)}%",
            () => SetDim(Mathf.Round((dim - 0.05f) * 100f) / 100f), () => SetDim(Mathf.Round((dim + 0.05f) * 100f) / 100f));
        y += Pitch;

        // aggiunta luci
        Btn(_panel, "+ Luce", 24, y, half, RowH, () => AddLight(0), 22);
        Btn(_panel, "+ Faro (spot)", 24 + half + 10f, y, half, RowH, () => AddLight(1), 22);
        y += Pitch;

        // aggiunta blocchi
        float bw = (W - 48f - 20f) / 3f;
        Btn(_panel, "+ Blocco", 24, y, bw, RowH, AddBlock, 20);
        Btn(_panel, "Blocco da 4 punti", 24 + bw + 10f, y, bw, RowH, () => BeginCapture(false), 18);
        Btn(_panel, "Cilindro da 4 punti", 24 + 2f * (bw + 10f), y, bw, RowH, () => BeginCapture(true), 18);
        y += Pitch;

        // selezione
        Btn(_panel, "Prec.", 24, y, 110, RowH, () => SelectNext(-1), 20);
        _selLabel = Txt(_panel, "Sel", 20, FontStyles.Bold, Accent, TextAlignmentOptions.Center);
        Place(_selLabel.rectTransform, 142, y, W - 142 - 142, RowH);
        Btn(_panel, "Succ.", W - 24 - 110, y, 110, RowH, () => SelectNext(1), 20);

        // gruppo luce
        _groupLight = Group("GroupLight", gy, lightGroupH);
        var gl = (RectTransform)_groupLight.transform;
        float ly = 0f;
        Stepper(gl, "Temperatura", ly, () => _selLight == null ? "" : $"{Mathf.RoundToInt(_selLight.d.kelvin)} K",
            () => ChangeLight(l => l.d.kelvin -= 250f), () => ChangeLight(l => l.d.kelvin += 250f));
        ly += Pitch;
        float pw = (W - 48f - 4f * 8f) / 5f;
        string[] names = { "Candela", "Calda", "Neutra", "Giorno", "Cielo" };
        float[] ks = { 1900f, 2700f, 4000f, 5600f, 7500f };
        for (int i = 0; i < names.Length; i++)
        {
            float k = ks[i];
            Btn(gl, names[i], 24 + i * (pw + 8f), ly, pw, 40, () => ChangeLight(l => l.d.kelvin = k), 18);
        }
        ly += 48f;
        Stepper(gl, "Intensità", ly, () => _selLight == null ? "" : _selLight.d.intensity.ToString("0.00"),
            () => ChangeLight(l => l.d.intensity -= 0.25f), () => ChangeLight(l => l.d.intensity += 0.25f));
        ly += Pitch;
        Stepper(gl, "Raggio", ly, () => _selLight == null ? "" : $"{_selLight.d.range:0.0} m",
            () => ChangeLight(l => l.d.range -= 0.5f), () => ChangeLight(l => l.d.range += 0.5f));
        ly += Pitch;
        Stepper(gl, "Apertura faro", ly, () => _selLight == null ? "" : (_selLight.d.kind == 1 ? $"{Mathf.RoundToInt(_selLight.d.angle)} gradi" : "solo faro"),
            () => ChangeLight(l => { if (l.d.kind == 1) l.d.angle -= 10f; }), () => ChangeLight(l => { if (l.d.kind == 1) l.d.angle += 10f; }));
        ly += Pitch;
        var del1 = Btn(gl, "Elimina luce", 24, ly, W - 48, RowH, DeleteSelected, 22);
        del1.GetComponent<Image>().color = DelRed;

        // gruppo blocco
        _groupBlock = Group("GroupBlock", gy, blockGroupH);
        var gb = (RectTransform)_groupBlock.transform;
        float by = 0f;
        Stepper(gb, "Larghezza", by, () => _selBlock == null ? "" : $"{Mathf.RoundToInt(_selBlock.d.sx * 100f)} cm",
            () => ChangeBlock(b => { b.d.sx -= 0.05f; _lastBlockW = b.d.sx; }), () => ChangeBlock(b => { b.d.sx += 0.05f; _lastBlockW = b.d.sx; }));
        by += Pitch;
        Stepper(gb, "Altezza", by, () => _selBlock == null ? "" : $"{Mathf.RoundToInt(_selBlock.d.sy * 100f)} cm",
            () => ChangeBlock(b => { b.d.sy -= 0.05f; _lastBlockH = b.d.sy; }), () => ChangeBlock(b => { b.d.sy += 0.05f; _lastBlockH = b.d.sy; }));
        by += Pitch;
        Stepper(gb, "Profondità", by, () => _selBlock == null ? "" : $"{Mathf.RoundToInt(_selBlock.d.sz * 100f)} cm",
            () => ChangeBlock(b => { b.d.sz -= 0.05f; _lastBlockD = b.d.sz; }), () => ChangeBlock(b => { b.d.sz += 0.05f; _lastBlockD = b.d.sz; }));
        by += Pitch;
        Stepper(gb, "Rotazione", by, () => "15 gradi",
            () => ChangeBlock(b => b.go.transform.Rotate(0f, -15f, 0f, Space.Self)), () => ChangeBlock(b => b.go.transform.Rotate(0f, 15f, 0f, Space.Self)));
        by += Pitch;
        var shapeBtn = Btn(gb, "", 24, by, half, RowH, () => ChangeBlock(b => b.d.shape = b.d.shape == 1 ? 0 : 1), 20);
        _shapeLabel = shapeBtn.GetComponentInChildren<TextMeshProUGUI>();
        var prevBtn = Btn(gb, "", 24 + half + 10f, by, half, RowH, () => { previewOcclusion = !previewOcclusion; ApplyAll(); RefreshPanel(); }, 20);
        _previewBg = prevBtn.GetComponent<Image>(); _previewLabel = prevBtn.GetComponentInChildren<TextMeshProUGUI>();
        by += Pitch;
        float third = (W - 48f - 20f) / 3f;
        Btn(gb, "Duplica", 24, by, third, RowH, DuplicateBlock, 22);
        Btn(gb, "Rifai a 4 punti", 24 + third + 10f, by, third, RowH, () => { if (_selBlock == null) return; bool cyl = _selBlock.d.shape == 1; DeleteSelected(); BeginCapture(cyl); }, 18);
        var del2 = Btn(gb, "Elimina", 24 + 2f * (third + 10f), by, third, RowH, DeleteSelected, 22);
        del2.GetComponent<Image>().color = DelRed;

        _hint = Txt(_panel, "Hint", 16, FontStyles.Normal, TextDim, TextAlignmentOptions.Center);
        Place(_hint.rectTransform, 24, H - 62f, W - 48f, 54f);

        _panel.gameObject.SetActive(false);
    }

    void ChangeLight(Action<LightItem> f)
    {
        if (_selLight == null) return;
        f(_selLight);
        ApplyLight(_selLight);
        RefreshPanel();
    }

    void ChangeBlock(Action<BlockItem> f)
    {
        if (_selBlock == null) return;
        f(_selBlock);
        ApplyBlock(_selBlock);
        RefreshPanel();
    }

    // ── Costruzione UI: componenti ────────────────────────────────────

    GameObject Group(string name, float y, float h)
    {
        var g = new GameObject(name, typeof(RectTransform));
        g.transform.SetParent(_panel, false);
        var rt = (RectTransform)g.transform;
        Place(rt, 0, y, W, h);
        g.SetActive(false);
        return g;
    }

    void Lbl(RectTransform parent, string text, float x, float y, float w)
    {
        var t = Txt(parent, "Label", 22, FontStyles.Normal, TextMain, TextAlignmentOptions.MidlineLeft);
        Place(t.rectTransform, x, y, w, RowH);
        t.text = text;
    }

    // riga "nome  [-]  valore  [+]"
    void Stepper(RectTransform parent, string label, float y, Func<string> text, Action dec, Action inc)
    {
        Lbl(parent, label, 24, y, 270);
        Btn(parent, "-", 300, y, 80, RowH, dec, 28);
        var v = Txt(parent, "Value", 24, FontStyles.Bold, Accent, TextAlignmentOptions.Center);
        Place(v.rectTransform, 388, y, 260, RowH);
        Btn(parent, "+", W - 24 - 80, y, 80, RowH, inc, 28);
        _refreshers.Add(() => { if (v != null) v.text = text(); });
    }

    GameObject Btn(RectTransform parent, string label, float x, float y, float w, float h, Action onClick, int fontSize)
    {
        var img = Img(parent, "Button", _rounded, BtnBg, true, 24f / 18f);
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

        var t = Txt(img.rectTransform, "Label", fontSize, FontStyles.Bold, TextMain, TextAlignmentOptions.Center);
        Stretch(t.rectTransform);
        t.text = label;
        return img.gameObject;
    }

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
        t.richText = false;
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
