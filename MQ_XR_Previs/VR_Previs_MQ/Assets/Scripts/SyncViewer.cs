// SyncViewer.cs
// Lato "spettatore" del multiplayer in sola visione, per un secondo visore: mostra gli oggetti dell'host in tempo reale,
// nello stesso punto della stanza (serve la stessa calibrazione a due punti dell'host), più testa e controller dell'host.
// Gli oggetti sono copie di sola visione: niente presa, niente collisioni. Per scaricare i modelli usa la stessa cache
// e gli stessi percorsi dell'host (libreria nginx oppure ComfyUI per gli oggetti non ancora salvati).

using System.Collections;
using System.Collections.Generic;
using Unity.XR.CoreUtils;
using UnityEngine;
using UnityEngine.Networking;

public class SyncViewer : MonoBehaviour
{
    public float smoothing = 14f;

    class Replica
    {
        public string id;
        public SyncObj data;
        public GameObject go;
        public bool loading, dead, placed;
        public string failedKey = "";   // file per cui il caricamento è già fallito: si riprova solo se cambia
        public float born;
    }

    SyncLink _client;
    SyncAvatar _co;   // co-host (se c'è)
    AssetLibrary _library;
    QuestObjectGenerator _gen;
    XROrigin _xr;

    readonly Dictionary<string, Replica> _rep = new Dictionary<string, Replica>();
    GameObject _avatar, _head, _handL, _handR;
    float[] _hp = new float[0], _lp = new float[0], _rp = new float[0];
    Material _matHead, _matNose, _matL, _matR;
    bool _askedCalibration;

    public bool HostOnline { get; private set; }
    public string SceneName { get; private set; } = "";
    public int ObjectCount => _rep.Count;

    public void Begin(SyncLink client, AssetLibrary library, QuestObjectGenerator generator)
    {
        _client = client; _library = library; _gen = generator;
        _xr = FindAnyObjectByType<XROrigin>();
        _client.Connected += OnConnected;
        _client.Message += OnMessage;
        BuildAvatar();
        _co = new SyncAvatar("SyncAvatarCoHost", new Color(1f, 0.52f, 0.18f, 1f), new Color(0.95f, 0.35f, 0.75f, 1f), new Color(0.95f, 0.85f, 0.25f, 1f));
        if (_client.State == SyncLink.Status.Connected) OnConnected();
    }

    void OnDestroy()
    {
        if (_client != null) { _client.Connected -= OnConnected; _client.Message -= OnMessage; }
        ClearAll();
        if (_co != null) _co.Destroy();
        if (_avatar != null) Destroy(_avatar);
        foreach (var m in new[] { _matHead, _matNose, _matL, _matR }) if (m != null) Destroy(m);
    }

    Transform Anchor => _library != null && _library.sceneAnchor != null ? _library.sceneAnchor : (_xr != null ? _xr.transform : null);

    void OnConnected()
    {
        _client.Send(new SyncMsg { t = "hello", role = "viewer", name = _library != null ? _library.Author : SystemInfo.deviceName });
    }

    // ── Messaggi dal relay ────────────────────────────────────────────

    void OnMessage(SyncMsg m)
    {
        switch (m.t)
        {
            case "snapshot":
                HostOnline = m.hostOnline;
                SceneName = m.sceneName ?? "";
                SetAll(m.objs);
                SetPose(m);
                _co.SetOnline(m.cohostOnline);
                AskCalibrationOnce();
                break;
            case "obj": if (m.o != null) Upsert(m.o); break;
            case "del": Remove(m.id); break;
            case "clear": ClearAll(); break;
            case "scene": SceneName = m.sceneName ?? ""; break;
            case "pose": SetPose(m); break;
            case "pose2": _co.SetPose(m.hp, m.lp, m.rp); break;
            case "cohost": _co.SetOnline(m.cohostOnline); break;
            case "host": HostOnline = m.hostOnline; if (!HostOnline && _avatar != null) _avatar.SetActive(false); break;
        }
    }

    // Se la stanza non è calibrata gli oggetti compaiono nel posto sbagliato: si avvia la procedura (una volta)
    void AskCalibrationOnce()
    {
        if (_askedCalibration) return;
        _askedCalibration = true;
        var cal = _library != null ? _library.roomCalibration : null;
        if (cal != null && cal.required && !cal.IsCalibrated && !cal.InProgress) cal.Begin();
    }

    void SetAll(SyncObj[] list)
    {
        var ids = new HashSet<string>();
        if (list != null) foreach (var o in list) if (o != null) ids.Add(o.id);
        foreach (var id in new List<string>(_rep.Keys)) if (!ids.Contains(id)) Remove(id);
        if (list != null) foreach (var o in list) if (o != null) Upsert(o);
    }

    void Upsert(SyncObj o)
    {
        if (string.IsNullOrEmpty(o.id) || o.p.Length < 3 || o.r.Length < 4) return;
        if (!_rep.TryGetValue(o.id, out var r))
        {
            r = new Replica { id = o.id, data = o, born = Time.time };
            _rep[o.id] = r;
            StartCoroutine(Spawn(r));
        }
        else
        {
            r.data = o;
            // il caricamento era fallito (es. oggetto non ancora salvato e ComfyUI irraggiungibile) e ora c'è un percorso utilizzabile: si riprova
            if (r.go == null && !r.loading && !r.dead && (o.glbKey + "|" + o.src) != r.failedKey) StartCoroutine(Spawn(r));
        }
    }

    void Remove(string id)
    {
        if (string.IsNullOrEmpty(id) || !_rep.TryGetValue(id, out var r)) return;
        r.dead = true;
        if (r.go != null) Destroy(r.go);
        _rep.Remove(id);
    }

    void ClearAll()
    {
        foreach (var r in _rep.Values) { r.dead = true; if (r.go != null) Destroy(r.go); }
        _rep.Clear();
    }

    // ── Creazione delle copie ─────────────────────────────────────────

    IEnumerator Spawn(Replica r)
    {
        r.loading = true;
        var d = r.data;
        byte[] data = null; string url = null, error = null;

        if (!string.IsNullOrEmpty(d.glbKey) && _library != null)
        {
            url = _library.StorageUrl(d.glbKey);
            yield return _library.GetGlb(d.glbKey, (b, e) => { data = b; error = e; });
        }
        else if (!string.IsNullOrEmpty(d.src) && _gen != null)
        {
            url = _gen.ComfyFullUrl(d.src);
            using var req = UnityWebRequest.Get(url);
            req.timeout = 120;
            yield return req.SendWebRequest();
            if (req.result == UnityWebRequest.Result.Success) data = req.downloadHandler.data;
            else error = $"{req.error} (HTTP {req.responseCode})";
        }
        else { r.failedKey = d.glbKey + "|" + d.src; r.loading = false; yield break; }

        if (r.dead) yield break;
        if (data == null) { Debug.LogWarning($"[SyncViewer] {d.name}: {error}"); r.failedKey = d.glbKey + "|" + d.src; r.loading = false; yield break; }

        GameObject go = null;
        yield return _gen.InstantiateGlb(data, url, $"SYNC_{d.name}", (g, e) => { go = g; error = e; });
        if (go == null || r.dead)
        {
            if (go != null) Destroy(go);
            if (!r.dead) Debug.LogWarning($"[SyncViewer] {d.name}: {error}");
            r.failedKey = d.glbKey + "|" + d.src;
            r.loading = false;
            yield break;
        }

        ApplyAlignment(go, r.data.al);
        foreach (var rd in go.GetComponentsInChildren<Renderer>()) { rd.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off; }
        r.go = go;
        r.loading = false;
        r.born = Time.time;
        r.placed = false;
        Pose(r, true);
    }

    // Stessa struttura creata nel visore host da ModelAlignment: pivot al centro, modello dentro, pivot ruotato
    static void ApplyAlignment(GameObject root, float[] al)
    {
        if (al == null || al.Length < 7) return;
        var pivot = new GameObject("Allineamento").transform;
        pivot.SetParent(root.transform, false);
        pivot.localPosition = new Vector3(al[0], al[1], al[2]);
        pivot.localRotation = Quaternion.identity;
        var children = new List<Transform>();
        foreach (Transform c in root.transform) if (c != pivot) children.Add(c);
        foreach (var c in children) c.SetParent(pivot, true);
        pivot.localRotation = new Quaternion(al[3], al[4], al[5], al[6]);
    }

    // ── Posizionamento (ogni frame) ───────────────────────────────────

    void Update()
    {
        float k = 1f - Mathf.Exp(-smoothing * Time.deltaTime);
        foreach (var r in _rep.Values) if (r.go != null) Pose(r, false, k);
        UpdateAvatar(k);
        _co?.Tick(k, Anchor);
    }

    void Pose(Replica r, bool snap, float k = 1f)
    {
        var d = r.data;
        if (d.p.Length < 3 || d.r.Length < 4) return;
        Transform a = Anchor;
        Vector3 lp = new Vector3(d.p[0], d.p[1], d.p[2]);
        Quaternion lr = new Quaternion(d.r[0], d.r[1], d.r[2], d.r[3]);
        Vector3 wp = a != null ? a.TransformPoint(lp) : lp;
        Quaternion wr = a != null ? a.rotation * lr : lr;

        // piccola comparsa: la scala cresce da 60% a 100% in mezzo secondo
        float grow = Mathf.Clamp01((Time.time - r.born) / 0.5f);
        float s = d.s * (0.6f + 0.4f * (1f - Mathf.Pow(1f - grow, 3f)));

        var t = r.go.transform;
        if (snap || !r.placed) { t.SetPositionAndRotation(wp, wr); t.localScale = Vector3.one * s; r.placed = true; }
        else
        {
            t.SetPositionAndRotation(Vector3.Lerp(t.position, wp, k), Quaternion.Slerp(t.rotation, wr, k));
            t.localScale = Vector3.one * Mathf.Lerp(t.localScale.x, s, Mathf.Min(1f, k * 1.5f));
        }
    }

    // ── Testa e controller dell'host ──────────────────────────────────

    void BuildAvatar()
    {
        var sh = Shader.Find("Sprites/Default");   // sempre incluso nella build, senza luci
        Material Mat(Color c) => new Material(sh) { color = c };
        _matHead = Mat(new Color(0.22f, 0.47f, 1f, 1f)); _matNose = Mat(Color.white);
        _matL = Mat(new Color(0.2f, 0.86f, 0.56f, 1f)); _matR = Mat(new Color(1f, 0.71f, 0.30f, 1f));

        _avatar = new GameObject("SyncAvatar");
        _head = Part(PrimitiveType.Sphere, _matHead, 0.18f, _avatar.transform);
        var nose = Part(PrimitiveType.Cube, _matNose, 0.05f, _head.transform);
        nose.transform.localPosition = new Vector3(0f, 0f, 0.6f);   // il naso indica dove guarda l'host
        nose.transform.localScale = new Vector3(0.25f, 0.25f, 0.5f);
        _handL = Part(PrimitiveType.Sphere, _matL, 0.07f, _avatar.transform);
        _handR = Part(PrimitiveType.Sphere, _matR, 0.07f, _avatar.transform);
        _avatar.SetActive(false);
    }

    static GameObject Part(PrimitiveType type, Material m, float size, Transform parent)
    {
        var go = GameObject.CreatePrimitive(type);
        Destroy(go.GetComponent<Collider>());
        go.GetComponent<Renderer>().sharedMaterial = m;
        go.transform.SetParent(parent, false);
        go.transform.localScale = Vector3.one * size;
        return go;
    }

    void SetPose(SyncMsg m)
    {
        _hp = m.hp ?? new float[0]; _lp = m.lp ?? new float[0]; _rp = m.rp ?? new float[0];
        if (_avatar != null) _avatar.SetActive(HostOnline && _hp.Length >= 7);
    }

    void UpdateAvatar(float k)
    {
        if (_avatar == null || !_avatar.activeSelf) return;
        Move(_head.transform, _hp, k);
        _handL.SetActive(_lp.Length >= 7); if (_lp.Length >= 7) Move(_handL.transform, _lp, k);
        _handR.SetActive(_rp.Length >= 7); if (_rp.Length >= 7) Move(_handR.transform, _rp, k);
    }

    void Move(Transform t, float[] p, float k)
    {
        Transform a = Anchor;
        Vector3 lp = new Vector3(p[0], p[1], p[2]);
        Quaternion lr = new Quaternion(p[3], p[4], p[5], p[6]);
        Vector3 wp = a != null ? a.TransformPoint(lp) : lp;
        Quaternion wr = a != null ? a.rotation * lr : lr;
        t.SetPositionAndRotation(Vector3.Lerp(t.position, wp, k), Quaternion.Slerp(t.rotation, wr, k));
    }
}
