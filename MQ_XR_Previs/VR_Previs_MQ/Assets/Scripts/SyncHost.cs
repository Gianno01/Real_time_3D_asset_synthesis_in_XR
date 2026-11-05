// SyncHost.cs
// Lato "host" del multiplayer in sola visione: il visore che genera pubblica la scena sul relay (server/sync),
// così telefono, tablet o un secondo visore la vedono in tempo reale.
//
// Cosa invia (10 volte al secondo, solo se è cambiato qualcosa):
//  • ogni oggetto: id, nome, file (libreria o ComfyUI), posizione/rotazione/scala rispetto alla stanza calibrata, blocco, raddrizzamento;
//  • eliminazioni e svuotamento della scena;
//  • posizione di testa e controller;
//  • stato della generazione ("sta generando il modello…") e nome della scena.
// Alla (ri)connessione manda lo stato completo, così gli spettatori sono sempre allineati.

using System;
using System.Collections.Generic;
using Unity.XR.CoreUtils;
using UnityEngine;
using UnityEngine.XR.Interaction.Toolkit.Interactors;

public class SyncHost : MonoBehaviour
{
    public float interval = 0.1f;
    [Tooltip("Indirizzo ip:porta dell'host Netcode, comunicato al relay così i visori spettatori lo trovano da soli")]
    public string advertiseAddr = "";

    SyncLink _client;
    AssetLibrary _library;
    QuestObjectGenerator _gen;
    XROrigin _xr;

    readonly Dictionary<string, SyncObj> _sent = new Dictionary<string, SyncObj>();
    readonly HashSet<string> _seen = new HashSet<string>();
    XRRayInteractor _left, _right;
    float _next, _nextHands;
    string _sceneId = "", _sceneName = "";

    public void Begin(SyncLink client, AssetLibrary library, QuestObjectGenerator generator)
    {
        _client = client; _library = library; _gen = generator;
        _xr = FindAnyObjectByType<XROrigin>();
        _client.Connected += OnConnected;
        if (_gen != null) _gen.StateChanged += OnGenState;
        if (_client.State == SyncLink.Status.Connected) OnConnected();
    }

    void OnDestroy()
    {
        if (_client != null) _client.Connected -= OnConnected;
        if (_gen != null) _gen.StateChanged -= OnGenState;
    }

    Transform Anchor => _library != null && _library.sceneAnchor != null ? _library.sceneAnchor : (_xr != null ? _xr.transform : null);

    void OnConnected()
    {
        _sent.Clear();
        _client.Send(new SyncMsg { t = "hello", role = "host", addr = advertiseAddr ?? "", name = _library != null ? _library.Author : SystemInfo.deviceName });

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

    void Update()
    {
        if (_client == null || _client.State != SyncLink.Status.Connected || Time.unscaledTime < _next) return;
        _next = Time.unscaledTime + interval;

        // oggetti nuovi o cambiati
        _seen.Clear();
        foreach (var so in SceneObject.All)
        {
            if (so == null) continue;
            var cur = Build(so);
            _seen.Add(cur.id);
            if (!_sent.TryGetValue(cur.id, out var prev) || Changed(prev, cur))
            {
                _client.Send(new SyncMsg { t = "obj", o = cur });
                _sent[cur.id] = cur;
            }
        }
        // oggetti eliminati
        List<string> gone = null;
        foreach (var id in _sent.Keys) if (!_seen.Contains(id)) (gone ??= new List<string>()).Add(id);
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
            t = "pose",
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
        if (_client == null || _client.State != SyncLink.Status.Connected) return;
        string text = detail ?? "";
        int nl = text.IndexOf('\n'); if (nl >= 0) text = text.Substring(0, nl);
        text = System.Text.RegularExpressions.Regex.Replace(text, "<[^>]+>", "");   // via i tag di formattazione (<i>…</i>)
        if (text.Length > 200) text = text.Substring(0, 200);
        _client.Send(new SyncMsg { t = "gen", genState = state.ToString(), genText = text });
    }
}
