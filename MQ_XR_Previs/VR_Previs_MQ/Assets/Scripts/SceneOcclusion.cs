// SceneOcclusion.cs
// Occlusione degli oggetti virtuali da parte della stanza vera, per il Quest Pro (che non ha il sensore di profondità).
//
// Come funziona
//  1) Il visore conosce la tua stanza dalla "Configurazione dello spazio" (Impostazioni → Spazio fisico): pareti, pavimento,
//     soffitto e mobili disegnati come scatole (scrivania = "Table", divano = "Couch", ecc.).
//  2) Questo script legge quei dati con AR Foundation (ARPlaneManager per pareti/pavimento/soffitto,
//     ARBoundingBoxManager per i mobili) e per ognuno crea una forma INVISIBILE con lo shader XR/DepthOcclusion:
//     non disegna colore (si continua a vedere la stanza vera in passthrough) ma scrive la profondità,
//     quindi nasconde gli oggetti virtuali che stanno dietro.
//  3) I mobili hanno anche un collider: gli oggetti si appoggiano sulla scrivania vera (aggancio al rilascio e ombra incluse).
//
// Limiti: la precisione è quella delle scatole disegnate in Configurazione spazio; persone, mani e mobili spostati
// dopo la configurazione non occludono (la mappa è statica).
//
// SETUP: nessuno, se c'è SettingsUI: il componente viene creato da solo. Per cambiare i valori di default
// aggiungilo a mano a un GameObject (es. "Library"). Serve il file Resources/DepthOcclusion.shader (vedi LEGGIMI).

using System.Collections;
using System.Collections.Generic;
using Unity.XR.CoreUtils;
using UnityEngine;
using UnityEngine.Android;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;

public class SceneOcclusion : MonoBehaviour
{
    [Header("Occlusione")]
    [Tooltip("Nasconde gli oggetti virtuali che stanno dietro mobili, pareti e pavimento reali")]
    public bool occlusionEnabled = true;
    [Tooltip("Mostra le forme di occlusione come scatole colorate (azzurro = mobili, arancio = pareti/pavimento) per controllare che combacino con la stanza")]
    public bool showDebug = false;

    [Header("Mobili (scatole di Configurazione spazio)")]
    [Tooltip("Gli oggetti possono appoggiarsi sui mobili (aggancio al rilascio e ombra)")]
    public bool furnitureColliders = true;
    [Tooltip("Di quanto la forma invisibile è più bassa del piano del mobile (m): evita che gli oggetti appoggiati vengano tagliati")]
    public float furnitureTopInset = 0.02f;
    [Tooltip("Correzione dell'altezza dei mobili (m): se la scrivania virtuale è più bassa/alta di quella vera")]
    [Range(-0.1f, 0.1f)] public float furnitureHeightOffset = 0f;

    [Header("Pareti, pavimento e soffitto (piani)")]
    public bool occludeStructure = true;
    [Tooltip("Distanza tra la superficie e la forma invisibile, dal lato opposto alla stanza (m): gli oggetti a filo parete non vengono tagliati")]
    public float surfaceGap = 0.04f;
    [Tooltip("Spessore della forma dietro la superficie (m)")]
    public float structureThickness = 0.10f;

    [Header("Avanzate")]
    public float refreshInterval = 0.5f;
    [Tooltip("Chiede il permesso \"Spazio\" (com.oculus.permission.USE_SCENE) all'avvio")]
    public bool requestPermission = true;

    const string ScenePermission = "com.oculus.permission.USE_SCENE";

    class Entry
    {
        public GameObject root;        // l'oggetto creato da AR Foundation (segue la posizione tracciata)
        public GameObject occluder;    // cubo invisibile
        public Renderer renderer;
        public GameObject surface;     // solo mobili: collider per appoggiare gli oggetti
        public Collider collider;
        public bool isBox;
        public float side = 1f;        // piani: da che parte della superficie sta la stanza (+1 = lungo la normale)
    }

    readonly Dictionary<TrackableId, Entry> _entries = new Dictionary<TrackableId, Entry>();
    readonly HashSet<TrackableId> _seen = new HashSet<TrackableId>();
    readonly List<TrackableId> _gone = new List<TrackableId>();

    ARPlaneManager _planes;
    ARBoundingBoxManager _boxes;
    Material _occMat, _dbgBoxMat, _dbgPlaneMat;
    static Mesh s_cube;

    bool _initialized, _failed, _permissionOk;
    float _startTime;
    int _lastBoxes = -1, _lastPlanes = -1;
    bool _warnedEmpty;

    public bool IsReady => _initialized;
    public int BoxCount { get; private set; }
    public int PlaneCount { get; private set; }

    /// <summary>Crea il componente se nella scena non c'è (chiamato da SettingsUI).</summary>
    public static SceneOcclusion EnsureExists(GameObject host)
    {
        var existing = FindAnyObjectByType<SceneOcclusion>();
        if (existing != null) return existing;
        return host.AddComponent<SceneOcclusion>();
    }

    void Start()
    {
        _startTime = Time.time;
        StartCoroutine(Run());
    }

    void OnDestroy()
    {
        if (_occMat != null) Destroy(_occMat);
        if (_dbgBoxMat != null) Destroy(_dbgBoxMat);
        if (_dbgPlaneMat != null) Destroy(_dbgPlaneMat);
    }

    // ── Ciclo principale ──────────────────────────────────────────────

    IEnumerator Run()
    {
        var wait = new WaitForSeconds(Mathf.Max(0.1f, refreshInterval));
        while (true)
        {
            if (!occlusionEnabled) _failed = false;   // se lo si riaccende si riprova (es. dopo aver concesso il permesso)

            if (occlusionEnabled && !_initialized && !_failed)
                yield return Init();

            if (_initialized) Refresh();
            yield return wait;
        }
    }

    IEnumerator Init()
    {
        _permissionOk = true;
        yield return EnsurePermission();
        if (!_permissionOk) { _failed = true; yield break; }

        var origin = FindAnyObjectByType<XROrigin>();
        if (origin == null)
        {
            Debug.LogWarning("[SceneOcclusion] Serve un XR Origin nella scena: occlusione non attivata.");
            _failed = true;
            yield break;
        }

        BuildMaterials();
        if (_occMat == null)
        {
            Debug.LogError("[SceneOcclusion] Shader \"XR/DepthOcclusion\" non trovato. Copia DepthOcclusion.shader in Assets/Resources/ (la cartella Resources va creata se manca).");
            _failed = true;
            yield break;
        }

        _boxes = GetOrAdd<ARBoundingBoxManager>(origin.gameObject);
        _planes = GetOrAdd<ARPlaneManager>(origin.gameObject);
        if (_planes != null) _planes.requestedDetectionMode = PlaneDetectionMode.Horizontal | PlaneDetectionMode.Vertical;

        // i sottosistemi partono al frame successivo
        yield return new WaitForSeconds(1f);
        if (_boxes == null || _boxes.subsystem == null)
            Debug.LogWarning("[SceneOcclusion] Bounding box non disponibili: in Project Settings > XR Plug-in Management > OpenXR (scheda Android) attiva \"Meta Quest: Bounding Boxes\" (e \"Meta Quest: Planes\", \"Meta Quest: Session\"). Senza, i mobili non occludono.");
        if (_planes == null || _planes.subsystem == null)
            Debug.LogWarning("[SceneOcclusion] Piani non disponibili: attiva \"Meta Quest: Planes\" nelle impostazioni OpenXR. Senza, pareti e pavimento non occludono.");

        _initialized = true;
        Debug.Log("[SceneOcclusion] Avviato: lettura di mobili e pareti dalla Configurazione spazio.");
    }

    IEnumerator EnsurePermission()
    {
#if UNITY_ANDROID && !UNITY_EDITOR
        if (!requestPermission || Permission.HasUserAuthorizedPermission(ScenePermission)) yield break;

        yield return new WaitForSeconds(2f);   // lascia passare la richiesta del microfono, due richieste insieme si perdono
        for (int attempt = 0; attempt < 3 && !Permission.HasUserAuthorizedPermission(ScenePermission); attempt++)
        {
            Permission.RequestUserPermission(ScenePermission);
            float t = 0f;
            while (t < 15f && !Permission.HasUserAuthorizedPermission(ScenePermission))
            {
                t += 0.5f;
                yield return new WaitForSeconds(0.5f);
            }
        }
        if (!Permission.HasUserAuthorizedPermission(ScenePermission))
        {
            _permissionOk = false;
            Debug.LogWarning("[SceneOcclusion] Permesso \"Spazio\" non concesso: occlusione non attiva. Concedilo da Impostazioni del Quest > App > Autorizzazioni, poi riaccendi \"Occlusione stanza\".");
        }
#else
        yield break;
#endif
    }

    static T GetOrAdd<T>(GameObject go) where T : Behaviour
    {
        var c = go.GetComponent<T>();
        if (c == null) c = go.AddComponent<T>();
        if (!c.enabled) c.enabled = true;
        return c;
    }

    // ── Aggiornamento delle forme ─────────────────────────────────────

    void Refresh()
    {
        _seen.Clear();
        int boxes = 0, planes = 0;
        Transform head = Head();

        if (occlusionEnabled)
        {
            if (_boxes != null && _boxes.enabled)
                foreach (var bb in _boxes.trackables)
                {
                    if (bb == null) continue;
                    SyncBox(bb);
                    boxes++;
                }

            if (occludeStructure && _planes != null && _planes.enabled)
                foreach (var p in _planes.trackables)
                {
                    if (p == null || !IsStructure(p.classifications.ToString())) continue;
                    SyncPlane(p, head);
                    planes++;
                }
        }

        // via le forme di ciò che non esiste più (o che non va più occluso)
        _gone.Clear();
        foreach (var kv in _entries)
            if (kv.Value.root == null || !_seen.Contains(kv.Key)) _gone.Add(kv.Key);
        foreach (var id in _gone)
        {
            var e = _entries[id];
            if (e.occluder != null) Destroy(e.occluder);
            if (e.surface != null) Destroy(e.surface);
            _entries.Remove(id);
        }

        ApplyVisibility();

        BoxCount = boxes; PlaneCount = planes;
        if (boxes != _lastBoxes || planes != _lastPlanes)
        {
            _lastBoxes = boxes; _lastPlanes = planes;
            Debug.Log($"[SceneOcclusion] {boxes} mobili e {planes} superfici (pareti/pavimento/soffitto) in uso.");
        }
        if (!_warnedEmpty && occlusionEnabled && boxes + planes == 0 && Time.time - _startTime > 12f)
        {
            _warnedEmpty = true;
            Debug.LogWarning("[SceneOcclusion] Nessuna superficie trovata. Controlla: 1) Configurazione spazio completata sul visore (con scrivania e mobili); " +
                             "2) permesso \"Spazio\" concesso; 3) funzioni Meta Quest Planes/Bounding Boxes attive nelle impostazioni OpenXR.");
        }
    }

    /// <summary>Riapplica subito interruttori e debug (da chiamare dopo aver cambiato i campi).</summary>
    public void Apply()
    {
        if (_initialized) { ApplyVisibility(); }
    }

    void ApplyVisibility()
    {
        foreach (var e in _entries.Values)
        {
            if (e.renderer == null) continue;
            e.renderer.enabled = occlusionEnabled;
            e.renderer.sharedMaterial = showDebug ? (e.isBox ? _dbgBoxMat : _dbgPlaneMat) : _occMat;
            if (e.collider != null) e.collider.enabled = occlusionEnabled && furnitureColliders;
        }
    }

    // Mobile: scatola centrata sulla posizione tracciata; l'asse "su" può essere uno qualsiasi degli assi locali.
    void SyncBox(ARBoundingBox bb)
    {
        var id = bb.trackableId;
        _seen.Add(id);
        if (!_entries.TryGetValue(id, out var e) || e.root == null)
        {
            e = Create(bb.gameObject, true);
            _entries[id] = e;
        }

        Vector3 size = bb.size;
        size = new Vector3(Mathf.Max(Mathf.Abs(size.x), 0.01f), Mathf.Max(Mathf.Abs(size.y), 0.01f), Mathf.Max(Mathf.Abs(size.z), 0.01f));

        int v = VerticalAxis(bb.transform, out float s);
        float inset = Mathf.Max(0f, furnitureTopInset);

        // forma invisibile: più bassa del piano di 'inset' (dall'alto), niente tagli agli oggetti appoggiati
        Vector3 occScale = size;
        occScale[v] = Mathf.Max(size[v] - inset, 0.01f);
        Vector3 occPos = Vector3.zero;
        occPos[v] = s * (furnitureHeightOffset - inset * 0.5f);
        e.occluder.transform.localPosition = occPos;
        e.occluder.transform.localRotation = Quaternion.identity;
        e.occluder.transform.localScale = occScale;

        // collider alla misura piena: gli oggetti si appoggiano sul piano vero
        if (e.surface != null)
        {
            Vector3 colPos = Vector3.zero;
            colPos[v] = s * furnitureHeightOffset;
            e.surface.transform.localPosition = colPos;
            e.surface.transform.localRotation = Quaternion.identity;
            e.surface.transform.localScale = size;
        }
    }

    // Parete / pavimento / soffitto: lastra spessa dietro la superficie, dal lato opposto alla stanza.
    void SyncPlane(ARPlane p, Transform head)
    {
        var id = p.trackableId;
        _seen.Add(id);
        if (!_entries.TryGetValue(id, out var e) || e.root == null)
        {
            e = Create(p.gameObject, false);
            if (head != null)
                e.side = Vector3.Dot(p.transform.up, head.position - p.transform.position) >= 0f ? 1f : -1f;
            _entries[id] = e;
        }

        Vector2 sz = p.size;
        float t = Mathf.Max(0.01f, structureThickness);
        e.occluder.transform.localRotation = Quaternion.identity;
        e.occluder.transform.localScale = new Vector3(Mathf.Max(sz.x, 0.01f), t, Mathf.Max(sz.y, 0.01f));
        e.occluder.transform.localPosition = new Vector3(p.center.x, -e.side * (Mathf.Max(0f, surfaceGap) + t * 0.5f), p.center.y);
    }

    // Quali piani occludono: pareti, pavimento, soffitto. Non porte/finestre (sono aperture) né le "pareti invisibili".
    static bool IsStructure(string classifications)
    {
        if (classifications.Contains("Door") || classifications.Contains("Window") || classifications.Contains("Invisible")) return false;
        return classifications.Contains("Wall") || classifications.Contains("Floor") || classifications.Contains("Ceiling");
    }

    static int VerticalAxis(Transform t, out float sign)
    {
        float dx = Vector3.Dot(t.right, Vector3.up);
        float dy = Vector3.Dot(t.up, Vector3.up);
        float dz = Vector3.Dot(t.forward, Vector3.up);
        float ax = Mathf.Abs(dx), ay = Mathf.Abs(dy), az = Mathf.Abs(dz);
        if (ay >= ax && ay >= az) { sign = dy >= 0f ? 1f : -1f; return 1; }
        if (ax >= az) { sign = dx >= 0f ? 1f : -1f; return 0; }
        sign = dz >= 0f ? 1f : -1f;
        return 2;
    }

    // ── Creazione ─────────────────────────────────────────────────────

    Entry Create(GameObject root, bool isBox)
    {
        var e = new Entry { root = root, isBox = isBox };

        e.occluder = new GameObject("RoomOccluder", typeof(MeshFilter), typeof(MeshRenderer));
        e.occluder.transform.SetParent(root.transform, false);
        e.occluder.GetComponent<MeshFilter>().sharedMesh = CubeMesh();
        var r = e.occluder.GetComponent<MeshRenderer>();
        r.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
        r.receiveShadows = false;
        r.lightProbeUsage = UnityEngine.Rendering.LightProbeUsage.Off;
        r.reflectionProbeUsage = UnityEngine.Rendering.ReflectionProbeUsage.Off;
        r.sharedMaterial = _occMat;
        e.renderer = r;

        if (isBox)
        {
            e.surface = new GameObject("RoomSurface", typeof(BoxCollider));
            e.surface.transform.SetParent(root.transform, false);
            var col = e.surface.GetComponent<BoxCollider>();
            col.size = Vector3.one;
            e.collider = col;
        }
        return e;
    }

    static Mesh CubeMesh()
    {
        if (s_cube == null)
        {
            var tmp = GameObject.CreatePrimitive(PrimitiveType.Cube);
            s_cube = tmp.GetComponent<MeshFilter>().sharedMesh;
            Destroy(tmp);
        }
        return s_cube;
    }

    void BuildMaterials()
    {
        if (_occMat == null)
        {
            var sh = Resources.Load<Shader>("DepthOcclusion");
            if (sh == null) sh = Shader.Find("XR/DepthOcclusion");
            if (sh != null) _occMat = new Material(sh) { name = "RoomOcclusion" };
        }
        var dbg = Shader.Find("Sprites/Default");   // sempre incluso nella build
        if (dbg != null)
        {
            if (_dbgBoxMat == null) _dbgBoxMat = new Material(dbg) { color = new Color(0.10f, 0.85f, 1.00f, 0.28f) };
            if (_dbgPlaneMat == null) _dbgPlaneMat = new Material(dbg) { color = new Color(1.00f, 0.55f, 0.10f, 0.18f) };
        }
        else
        {
            _dbgBoxMat = _dbgPlaneMat = _occMat;
        }
    }

    Transform Head()
    {
        var origin = FindAnyObjectByType<XROrigin>();
        if (origin != null && origin.Camera != null) return origin.Camera.transform;
        return Camera.main != null ? Camera.main.transform : null;
    }
}
