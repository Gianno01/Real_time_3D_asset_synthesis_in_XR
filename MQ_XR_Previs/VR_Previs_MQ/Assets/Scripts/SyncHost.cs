// SyncHost.cs
// Lato "host" e "co-host" del multiplayer: il visore che genera pubblica la scena e, se c'è un co-host, la costruiscono insieme.
//
//  HOST      pubblica la scena (oggetti, posizioni, testa e controller, stato della generazione) sul relay e/o su Netcode.
//            È uno solo. Se arriva un co-host ne accetta le modifiche.
//  CO-HOST   (isCoHost = true) entra nella scena dell'host: all'ingresso la sua scena locale è sostituita da quella dell'host,
//            poi crea, sposta ed elimina oggetti in tempo reale, e gli stessi cambiamenti dell'host compaiono da lui.
//
// Entrambi i lati fanno la stessa cosa (stessi messaggi di SyncProtocol, 10 volte al secondo, solo se è cambiato qualcosa):
//  • mandano i propri oggetti nuovi, spostati o eliminati;
//  • ricevono quelli dell'altro e li applicano a oggetti VERI (con presa, collisioni, gravità), non a semplici copie;
//  • si vedono a vicenda: testa e controller dell'altro sono sfere (SyncAvatar).
// Regole contro i conflitti: un oggetto che stai tenendo in mano non viene toccato dagli aggiornamenti dell'altro;
// per il resto vale l'ultima modifica. Le modifiche ricevute non vengono rimandate indietro (niente eco).

using System;
using System.Collections;
using System.Collections.Generic;
using Unity.XR.CoreUtils;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.XR.Interaction.Toolkit.Interactables;
using UnityEngine.XR.Interaction.Toolkit.Interactors;

public class SyncHost : MonoBehaviour
{
    public float interval = 0.1f;
    [Tooltip("Indirizzo ip:porta dell'host Netcode, comunicato al relay così i visori spettatori lo trovano da soli")]
    public string advertiseAddr = "";
    [Tooltip("Co-host: collabora alla scena di un altro host invece di trasmettere la propria")]
    public bool isCoHost;
    [Tooltip("Velocità con cui gli oggetti dell'altro seguono le sue posizioni")]
    public float smoothing = 16f;

    /// <summary>Host: c'è un co-host collegato. Co-host: l'host è collegato.</summary>
    public bool PeerOnline { get; private set; }
    public string PeerName { get; private set; } = "";
    /// <summary>Co-host: ha ricevuto la scena dell'host.</summary>
    public bool Synced => !isCoHost || _synced;

    SyncLink _client;
    AssetLibrary _library;
    QuestObjectGenerator _gen;
    XROrigin _xr;
    SyncAvatar _peer;

    readonly Dictionary<string, SyncObj> _sent = new Dictionary<string, SyncObj>();
    readonly HashSet<string> _seen = new HashSet<string>();
    readonly HashSet<string> _pending = new HashSet<string>();              // oggetti dell'altro che sto ancora scaricando
    readonly Dictionary<string, SyncObj> _pendingData = new Dictionary<string, SyncObj>();
    readonly Dictionary<string, SyncObj> _targets = new Dictionary<string, SyncObj>();   // posizioni ricevute verso cui l'oggetto si sta muovendo
    XRRayInteractor _left, _right;
    float _next, _nextHands;
    string _sceneId = "", _sceneName = "";
    bool _synced;

    public void Begin(SyncLink client, AssetLibrary library, QuestObjectGenerator generator)
    {
        _client = client; _library = library; _gen = generator;
        _xr = FindAnyObjectByType<XROrigin>();
        // host = blu come prima, co-host = arancione: ciascuno vede l'altro con il colore dell'altro
        _peer = isCoHost
            ? new SyncAvatar("SyncAvatarHost", new Color(0.22f, 0.47f, 1f, 1f), new Color(0.2f, 0.86f, 0.56f, 1f), new Color(1f, 0.71f, 0.30f, 1f))
            : new SyncAvatar("SyncAvatarCoHost", new Color(1f, 0.52f, 0.18f, 1f), new Color(0.95f, 0.35f, 0.75f, 1f), new Color(0.95f, 0.85f, 0.25f, 1f));
        _client.Connected += OnConnected;
        _client.Message += OnMessage;
        if (_gen != null) _gen.StateChanged += OnGenState;
        if (_client.State == SyncLink.Status.Connected) OnConnected();
    }

    void OnDestroy()
    {
        if (_client != null) { _client.Connected -= OnConnected; _client.Message -= OnMessage; }
        if (_gen != null) _gen.StateChanged -= OnGenState;
        if (_peer != null) _peer.Destroy();
    }

    Transform Anchor => _library != null && _library.sceneAnchor != null ? _library.sceneAnchor : (_xr != null ? _xr.transform : null);

    void OnConnected()
    {
        _sent.Clear();
        string who = _library != null ? _library.Author : SystemInfo.deviceName;

        if (isCoHost)
        {
            // il co-host non pubblica la propria scena: aspetta quella dell'host (snapshot) e la sostituisce alla sua
            _synced = false;
            _client.Send(new SyncMsg { t = "hello", role = "cohost", name = who });
            return;
        }

        _client.Send(new SyncMsg { t = "hello", role = "host", addr = advertiseAddr ?? "", name = who });

        var objs = new List<SyncObj>();
        foreach (var so in SceneObject.All)
        {
            if (so == null) continue;
            var o = Build(so);
            objs.Add(o);
            _sent[o.id] = o;
        }
        _sceneId = _library != null ? _library.CurrentSceneId : "";
        _sceneName = _library != null ? _library.CurrentSceneName : "";
        _client.Send(new SyncMsg { t = "full", objs = objs.ToArray(), sceneId = _sceneId, sceneName = _sceneName });
        if (_gen != null) OnGenState(_gen.State, "");
    }

    // ── Aggiornamento ─────────────────────────────────────────────────

    void Update()
    {
        // ogni frame: gli oggetti dell'altro si muovono verso le posizioni ricevute; avatar dell'altro
        ApplyTargets();
        _peer?.Tick(1f - Mathf.Exp(-smoothing * Time.deltaTime), Anchor);

        if (_client == null || _client.State != SyncLink.Status.Connected || Time.unscaledTime < _next) return;
        _next = Time.unscaledTime + interval;
        if (isCoHost && !_synced) return;   // prima di aver ricevuto la scena dell'host non si pubblica niente

        // oggetti nuovi o cambiati
        _seen.Clear();
        foreach (var so in SceneObject.All)
        {
            if (so == null) continue;
            var cur = Build(so);
            _seen.Add(cur.id);
            if (_targets.ContainsKey(cur.id)) continue;   // si sta muovendo per effetto dell'altro: non rimandarlo indietro
            if (!_sent.TryGetValue(cur.id, out var prev) || Changed(prev, cur))
            {
                _client.Send(new SyncMsg { t = "obj", o = cur });
                _sent[cur.id] = cur;
            }
        }
        // oggetti eliminati
        List<string> gone = null;
        foreach (var id in _sent.Keys) if (!_seen.Contains(id) && !_pending.Contains(id)) (gone ??= new List<string>()).Add(id);
        if (gone != null)
            foreach (var id in gone) { _client.Send(new SyncMsg { t = "del", id = id }); _sent.Remove(id); }

        // nome della scena
        if (_library != null && (_library.CurrentSceneId != _sceneId || _library.CurrentSceneName != _sceneName))
        {
            _sceneId = _library.CurrentSceneId; _sceneName = _library.CurrentSceneName;
            _client.Send(new SyncMsg { t = "scene", sceneId = _sceneId, sceneName = _sceneName });
        }

        SendPose();
    }

    // ── Costruzione dei dati ──────────────────────────────────────────

    SyncObj Build(SceneObject so)
    {
        if (string.IsNullOrEmpty(so.syncId)) so.syncId = Guid.NewGuid().ToString("N");
        Transform a = Anchor, t = so.transform;
        Vector3 p = a != null ? a.InverseTransformPoint(t.position) : t.position;
        Quaternion q = a != null ? Quaternion.Inverse(a.rotation) * t.rotation : t.rotation;

        var o = new SyncObj
        {
            id = so.syncId,
            name = !string.IsNullOrEmpty(so.displayName) ? so.displayName : so.objectName,
            assetId = so.assetId ?? "",
            glbKey = so.glbKey ?? "",
            src = string.IsNullOrEmpty(so.glbKey) ? (so.sourceGlbPath ?? "") : "",   // oggetto non ancora salvato: file su ComfyUI
            p = new[] { p.x, p.y, p.z },
            r = new[] { q.x, q.y, q.z, q.w },
            s = t.localScale.x,
            locked = so.locked,
        };
        // raddrizzamento del modello (figlio "Allineamento" creato da ModelAlignment): senza, il browser mostrerebbe il modello storto
        var al = t.Find("Allineamento");
        if (al != null)
        {
            Vector3 c = al.localPosition; Quaternion r = al.localRotation;
            o.al = new[] { c.x, c.y, c.z, r.x, r.y, r.z, r.w };
        }
        return o;
    }

    static bool Changed(SyncObj a, SyncObj b)
    {
        if (a.name != b.name || a.assetId != b.assetId || a.glbKey != b.glbKey || a.src != b.src || a.locked != b.locked) return true;
        if (Mathf.Abs(a.s - b.s) > 0.001f) return true;
        if (Dist2(a.p, b.p) > 1e-6f) return true;                              // > 1 mm
        float dot = a.r[0] * b.r[0] + a.r[1] * b.r[1] + a.r[2] * b.r[2] + a.r[3] * b.r[3];
        if (1f - Mathf.Abs(dot) > 1e-6f) return true;                           // > ~0,16°
        if (a.al.Length != b.al.Length) return true;
        return false;
    }

    static float Dist2(float[] a, float[] b)
    {
        float dx = a[0] - b[0], dy = a[1] - b[1], dz = a[2] - b[2];
        return dx * dx + dy * dy + dz * dz;
    }

    // ── Testa e controller ────────────────────────────────────────────

    void SendPose()
    {
        var head = _gen != null ? _gen.Head : null;
        if (head == null) return;

        if (Time.unscaledTime > _nextHands)
        {
            _nextHands = Time.unscaledTime + 2f;
            foreach (var ri in FindObjectsByType<XRRayInteractor>(FindObjectsSortMode.None))
            {
                string h = ri.handedness.ToString();
                if (h == "Left" || ri.name.ToLowerInvariant().Contains("left")) _left = ri;
                else if (h == "Right" || ri.name.ToLowerInvariant().Contains("right")) _right = ri;
            }
        }
        _client.Send(new SyncMsg
        {
            t = isCoHost ? "pose2" : "pose",   // pose = host, pose2 = co-host
            hp = PoseOf(head),
            lp = _left != null ? PoseOf(_left.transform) : new float[0],
            rp = _right != null ? PoseOf(_right.transform) : new float[0],
        });
    }

    float[] PoseOf(Transform t)
    {
        Transform a = Anchor;
        Vector3 p = a != null ? a.InverseTransformPoint(t.position) : t.position;
        Quaternion q = a != null ? Quaternion.Inverse(a.rotation) * t.rotation : t.rotation;
        return new[] { p.x, p.y, p.z, q.x, q.y, q.z, q.w };
    }

    // ── Stato della generazione ───────────────────────────────────────

    void OnGenState(PipelineState state, string detail)
    {
        if (isCoHost) return;   // lo stato "sta generando" lo pubblica l'host (per gli spettatori)
        if (_client == null || _client.State != SyncLink.Status.Connected) return;
        string text = detail ?? "";
        int nl = text.IndexOf('\n'); if (nl >= 0) text = text.Substring(0, nl);
        text = System.Text.RegularExpressions.Regex.Replace(text, "<[^>]+>", "");   // via i tag di formattazione (<i>…</i>)
        if (text.Length > 200) text = text.Substring(0, 200);
        _client.Send(new SyncMsg { t = "gen", genState = state.ToString(), genText = text });
    }

    // ── Messaggi dall'altro (co-host → host, host → co-host) ──────────

    void OnMessage(SyncMsg m)
    {
        switch (m.t)
        {
            case "snapshot": if (isCoHost) ApplySnapshot(m); break;
            case "obj": if (m.o != null) ApplyRemote(m.o); break;
            case "del": ApplyRemoteDelete(m.id); break;
            case "clear": ApplyRemoteClear(); break;
            case "scene": ApplyRemoteScene(m.sceneId, m.sceneName); break;
            case "pose": if (isCoHost) SetPeerPose(m); break;     // pose dell'host
            case "pose2": if (!isCoHost) SetPeerPose(m); break;   // pose del co-host
            case "host":
                if (isCoHost) { PeerOnline = m.hostOnline; PeerName = m.hostName ?? ""; _peer?.SetOnline(PeerOnline); }
                break;
            case "cohost":
                if (!isCoHost) { PeerOnline = m.cohostOnline; PeerName = m.cohostName ?? ""; _peer?.SetOnline(PeerOnline); }
                break;
        }
    }

    void SetPeerPose(SyncMsg m) { _peer?.SetPose(m.hp, m.lp, m.rp); }

    SceneObject FindLocal(string id)
    {
        foreach (var so in SceneObject.All) if (so != null && so.syncId == id) return so;
        return null;
    }

    static bool IsGrabbed(SceneObject so)
    {
        var g = so.GetComponent<XRGrabInteractable>();
        return g != null && g.isSelected;
    }

    // Toglie un oggetto dalla scena senza che venga rimandato come "eliminato" all'altro
    void RemoveLocalSilently(SceneObject so)
    {
        if (so == null) return;
        if (!string.IsNullOrEmpty(so.syncId)) { _sent.Remove(so.syncId); _targets.Remove(so.syncId); }
        so.enabled = false;   // OnDisable lo toglie subito da SceneObject.All (Destroy agisce solo a fine frame)
        Destroy(so.gameObject);
    }

    void ApplySnapshot(SyncMsg m)
    {
        PeerOnline = m.hostOnline;
        PeerName = m.hostName ?? "";
        _peer?.SetOnline(PeerOnline);

        var ids = new HashSet<string>();
        if (m.objs != null) foreach (var o in m.objs) if (o != null && !string.IsNullOrEmpty(o.id)) ids.Add(o.id);

        // la scena locale è sostituita da quella dell'host
        foreach (var so in new List<SceneObject>(SceneObject.All))
            if (so != null && (string.IsNullOrEmpty(so.syncId) || !ids.Contains(so.syncId))) RemoveLocalSilently(so);
        foreach (var id in new List<string>(_pending)) if (!ids.Contains(id)) { _pending.Remove(id); _pendingData.Remove(id); }

        if (m.objs != null) foreach (var o in m.objs) if (o != null) ApplyRemote(o);
        ApplyRemoteScene(m.sceneId, m.sceneName);
        _synced = true;
    }

    void ApplyRemoteScene(string id, string name)
    {
        if (_library == null) return;
        _sceneId = id ?? ""; _sceneName = name ?? "";
        _library.SetCurrentScene(_sceneId, _sceneName);
    }

    void ApplyRemote(SyncObj o)
    {
        if (string.IsNullOrEmpty(o.id) || o.p == null || o.r == null || o.p.Length < 3 || o.r.Length < 4) return;

        if (_pending.Contains(o.id)) { _pendingData[o.id] = o; return; }   // sta ancora scaricando: tiene l'ultimo stato

        var so = FindLocal(o.id);
        if (so == null)
        {
            _pending.Add(o.id);
            _pendingData[o.id] = o;
            StartCoroutine(SpawnRemote(o.id));
            return;
        }
        if (IsGrabbed(so)) return;   // lo sto tenendo io: vale la mia mano finché non lo lascio

        string nm = !string.IsNullOrEmpty(o.name) ? o.name : so.displayName;
        if (nm != so.displayName) { so.displayName = nm; so.objectName = nm; }
        if (so.locked != o.locked) so.SetLocked(o.locked);
        _targets[o.id] = o;
    }

    void ApplyRemoteDelete(string id)
    {
        if (string.IsNullOrEmpty(id)) return;
        _pending.Remove(id); _pendingData.Remove(id); _targets.Remove(id); _sent.Remove(id);
        RemoveLocalSilently(FindLocal(id));
    }

    void ApplyRemoteClear()
    {
        foreach (var so in new List<SceneObject>(SceneObject.All)) RemoveLocalSilently(so);
        _pending.Clear(); _pendingData.Clear(); _targets.Clear(); _sent.Clear();
    }

    // Oggetto dell'altro non ancora presente da me: scarico il modello e creo un oggetto vero (presa, collisioni, gravità)
    IEnumerator SpawnRemote(string id)
    {
        var d = _pendingData.TryGetValue(id, out var first) ? first : null;
        if (d == null || _gen == null) { _pending.Remove(id); yield break; }

        byte[] data = null; string url = null, error = null;
        if (!string.IsNullOrEmpty(d.glbKey) && _library != null)
        {
            url = _library.StorageUrl(d.glbKey);
            yield return _library.GetGlb(d.glbKey, (b, e) => { data = b; error = e; });
        }
        else if (!string.IsNullOrEmpty(d.src))
        {
            url = _gen.ComfyFullUrl(d.src);
            using (var req = UnityWebRequest.Get(url))
            {
                req.timeout = 120;
                yield return req.SendWebRequest();
                if (req.result == UnityWebRequest.Result.Success) data = req.downloadHandler.data;
                else error = $"{req.error} (HTTP {req.responseCode})";
            }
        }
        else error = "nessun file";

        if (!_pending.Contains(id)) yield break;   // nel frattempo eliminato
        if (data == null)
        {
            Debug.LogWarning($"[SyncHost] {d.name}: {error}");
            _pending.Remove(id); _pendingData.Remove(id);
            yield break;
        }

        GameObject go = null;
        yield return _gen.InstantiateGlb(data, url, string.IsNullOrEmpty(d.name) ? "Oggetto" : d.name, (g, e) => { go = g; error = e; });
        if (go == null || !_pending.Contains(id))
        {
            if (go != null) Destroy(go);
            else Debug.LogWarning($"[SyncHost] {d.name}: {error}");
            _pending.Remove(id); _pendingData.Remove(id);
            yield break;
        }

        d = _pendingData.TryGetValue(id, out var latest) ? latest : d;   // l'altro può averlo già spostato mentre scaricavo

        _gen.PrepareObject(go, false);   // collider, presa, griglia/misure/aggancio, raddrizzamento: come per gli oggetti caricati da una scena
        var so = go.GetComponent<SceneObject>();
        if (so == null) so = go.AddComponent<SceneObject>();
        so.syncId = id;
        so.assetId = d.assetId ?? ""; so.glbKey = d.glbKey ?? ""; so.sourceGlbPath = d.src ?? "";
        so.displayName = d.name ?? ""; so.objectName = d.name ?? "";
        so.placedBy = PeerName;

        Transform a = Anchor;
        Vector3 lp = new Vector3(d.p[0], d.p[1], d.p[2]);
        Quaternion lr = new Quaternion(d.r[0], d.r[1], d.r[2], d.r[3]);
        go.transform.localScale = Vector3.one * (d.s > 0f ? d.s : 1f);
        go.transform.SetPositionAndRotation(a != null ? a.TransformPoint(lp) : lp, a != null ? a.rotation * lr : lr);
        if (d.locked) so.SetLocked(true);

        _pending.Remove(id); _pendingData.Remove(id);
        _sent[id] = Build(so);   // stato noto a entrambi: non va rimandato
    }

    // Ogni frame: gli oggetti dell'altro raggiungono morbidamente la posizione ricevuta
    void ApplyTargets()
    {
        if (_targets.Count == 0) return;
        float k = 1f - Mathf.Exp(-smoothing * Time.deltaTime);
        Transform a = Anchor;

        List<string> done = null;
        foreach (var kv in _targets)
        {
            var d = kv.Value;
            var so = FindLocal(kv.Key);
            if (so == null || IsGrabbed(so)) { (done ??= new List<string>()).Add(kv.Key); continue; }

            Vector3 lp = new Vector3(d.p[0], d.p[1], d.p[2]);
            Quaternion lr = new Quaternion(d.r[0], d.r[1], d.r[2], d.r[3]);
            Vector3 wp = a != null ? a.TransformPoint(lp) : lp;
            Quaternion wr = a != null ? a.rotation * lr : lr;
            float s = d.s > 0f ? d.s : 1f;

            var t = so.transform;
            t.SetPositionAndRotation(Vector3.Lerp(t.position, wp, k), Quaternion.Slerp(t.rotation, wr, k));
            t.localScale = Vector3.one * Mathf.Lerp(t.localScale.x, s, k);

            if ((t.position - wp).sqrMagnitude < 1e-6f && Quaternion.Angle(t.rotation, wr) < 0.3f && Mathf.Abs(t.localScale.x - s) < 0.002f)
            {
                t.SetPositionAndRotation(wp, wr);
                t.localScale = Vector3.one * s;
                (done ??= new List<string>()).Add(kv.Key);
            }
        }
        if (done == null) return;
        foreach (var id in done)
        {
            _targets.Remove(id);
            var so = FindLocal(id);
            if (so != null && !IsGrabbed(so)) _sent[id] = Build(so);   // arrivato: da qui in poi vale come stato condiviso
        }
    }
}
