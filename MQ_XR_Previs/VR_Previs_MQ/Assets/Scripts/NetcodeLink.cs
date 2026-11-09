// NetcodeLink.cs
// Collegamento tra visori con Netcode for GameObjects (UnityTransport, UDP, LAN). Usa la messaggistica personalizzata di Netcode:
// gli stessi messaggi JSON di SyncProtocol viaggiano come messaggio nominato "xrsync". Nessun prefab, nessuna scena da sincronizzare:
// il caricamento dei modelli resta quello di SyncViewer (GLB dalla libreria o da ComfyUI).
//
//  • Host    StartHost(): fa da "server" per gli altri visori. Tiene una copia dello stato (come il relay) e la manda ai visori che entrano dopo.
//  • Client  StartClientTo(ip, porta): si collega all'host e riceve gli stessi messaggi del relay (snapshot, obj, del, pose…).
//  • Co-host: un solo client può presentarsi come "cohost" (hello): l'host accetta le sue modifiche (obj, del, clear, scene, pose2),
//    le tiene nello stato, le gira agli altri client e le consegna a SyncHost. Un secondo co-host viene rifiutato (denied).
//    Gli altri client sono spettatori: i loro messaggi vengono scartati (ClientMessage resta come punto d'estensione).
//
// Richiede il pacchetto com.unity.netcode.gameobjects (Package Manager → Add by name). Il simbolo NETCODE_ENABLED viene aggiunto
// da solo da Editor/NetcodeDefine.cs; senza il pacchetto questo file non viene compilato.

#if NETCODE_ENABLED
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Unity.Collections;
using Unity.Netcode;
using Unity.Netcode.Transports.UTP;
using UnityEngine;

public class NetcodeLink : SyncLink
{
    public const string MessageName = "xrsync";
    const int MaxPayload = 4 * 1024 * 1024;

    public int ClientCount { get; private set; }
    public bool IsHost { get; private set; }
    public bool Busy { get { var nm = _nm != null ? _nm : NetworkManager.Singleton; return nm != null && nm.ShutdownInProgress; } }

    /// <summary>Messaggio ricevuto da un client che non è il co-host (id Netcode, messaggio): ignorato, solo sola visione.</summary>
    public event Action<ulong, SyncMsg> ClientMessage;

    public bool HasCoHost => _hasCohost;
    ulong _cohostId;
    bool _hasCohost;
    string _cohostName = "";

    NetworkManager _nm;
    UnityTransport _utp;
    bool _callbacks;

    // stato che l'host conserva per i visori che entrano dopo
    readonly Dictionary<string, SyncObj> _objs = new Dictionary<string, SyncObj>();
    string _sceneId = "", _sceneName = "", _hostName = "", _genState = "", _genText = "";
    SyncMsg _pose;

    bool EnsureManager()
    {
        try
        {
            if (_nm == null) _nm = NetworkManager.Singleton != null ? NetworkManager.Singleton : FindAnyObjectByType<NetworkManager>();
            if (_nm == null)
            {
                var go = new GameObject("NetcodeSync");
                _utp = go.AddComponent<UnityTransport>();
                _nm = go.AddComponent<NetworkManager>();
            }
            if (_utp == null) _utp = _nm.GetComponent<UnityTransport>();
            if (_utp == null) _utp = _nm.gameObject.AddComponent<UnityTransport>();
            if (_nm.NetworkConfig == null) _nm.NetworkConfig = new NetworkConfig();
            _nm.NetworkConfig.NetworkTransport = _utp;
            _nm.NetworkConfig.EnableSceneManagement = false;   // le scene sono già caricate su ogni visore: Netcode non deve toccarle
            if (!_callbacks)
            {
                _nm.OnClientConnectedCallback += OnClientConnected;
                _nm.OnClientDisconnectCallback += OnClientDisconnected;
                _callbacks = true;
            }
            return true;
        }
        catch (Exception e) { LastError = e.Message; Debug.LogException(e); return false; }
    }

    // ── Avvio / arresto ───────────────────────────────────────────────

    public bool StartHost(ushort port, string hostName)
    {
        if (!EnsureManager()) return false;
        if (_nm.IsListening || _nm.ShutdownInProgress) return false;
        _hostName = hostName ?? "";
        _objs.Clear(); _pose = null; _hasCohost = false;
        _utp.SetConnectionData("127.0.0.1", port, "0.0.0.0");   // ascolta su tutte le interfacce
        if (!_nm.StartHost()) { LastError = "Netcode: avvio host non riuscito"; return false; }
        _nm.CustomMessagingManager.RegisterNamedMessageHandler(MessageName, OnNamedMessage);
        IsHost = true; ClientCount = 0; LastError = "";
        State = Status.Connected;
        RaiseConnected();
        return true;
    }

    public bool StartClientTo(string address, ushort port)
    {
        if (!EnsureManager()) return false;
        if (_nm.IsListening || _nm.ShutdownInProgress) return false;
        _utp.SetConnectionData(address, port);
        if (!_nm.StartClient()) { LastError = "Netcode: avvio client non riuscito"; return false; }
        _nm.CustomMessagingManager.RegisterNamedMessageHandler(MessageName, OnNamedMessage);
        IsHost = false; LastError = "";
        State = Status.Connecting;
        return true;
    }

    public void Stop()
    {
        bool was = State == Status.Connected;
        State = Status.Disconnected;
        ClientCount = 0; IsHost = false;
        _hasCohost = false; _cohostName = "";
        if (_nm != null && (_nm.IsListening || _nm.IsServer || _nm.IsClient)) { try { _nm.Shutdown(); } catch (Exception e) { Debug.LogException(e); } }
        if (was) RaiseDisconnected();
    }

    void OnDestroy()
    {
        if (_nm != null && _callbacks)
        {
            _nm.OnClientConnectedCallback -= OnClientConnected;
            _nm.OnClientDisconnectCallback -= OnClientDisconnected;
        }
        if (_nm != null && _nm.IsListening) { try { _nm.Shutdown(); } catch { } }
    }

    // ── Eventi di Netcode (thread principale) ─────────────────────────

    void OnClientConnected(ulong id)
    {
        if (_nm == null) return;
        if (_nm.IsServer)
        {
            if (id == _nm.LocalClientId) return;     // l'host stesso
            ClientCount++;
            // chi entra riceve subito la fotografia della scena, come dal relay
            SendRaw(id, JsonUtility.ToJson(BuildSnapshot()), NetworkDelivery.ReliableFragmentedSequenced);
        }
        else if (id == _nm.LocalClientId)
        {
            State = Status.Connected; LastError = "";
            RaiseConnected();
        }
    }

    void OnClientDisconnected(ulong id)
    {
        if (_nm == null) return;
        if (_nm.IsServer)
        {
            if (id != _nm.LocalClientId) ClientCount = Mathf.Max(0, ClientCount - 1);
            if (_hasCohost && id == _cohostId)
            {
                _hasCohost = false; _cohostName = "";
                var off = new SyncMsg { t = "cohost", cohostOnline = false };
                RaiseMessage(off);
                BroadcastExcept(JsonUtility.ToJson(off), NetworkDelivery.ReliableFragmentedSequenced, id);
            }
        }
        else
        {
            bool was = State == Status.Connected;
            State = Status.Disconnected;
            string why = _nm.DisconnectReason;
            LastError = string.IsNullOrEmpty(why) ? "Netcode: host non raggiungibile" : why;
            if (was) RaiseDisconnected();
        }
    }

    // ── Invio ─────────────────────────────────────────────────────────

    public override bool Send(SyncMsg m)
    {
        if (m == null || _nm == null || !_nm.IsListening || State != Status.Connected) return false;
        if (_nm.IsServer) return HostSend(m);
        // client → host (per ora l'host scarta tutto tranne l'hello)
        return SendRaw(NetworkManager.ServerClientId, JsonUtility.ToJson(m), NetworkDelivery.ReliableFragmentedSequenced);
    }

    bool HostSend(SyncMsg m)
    {
        switch (m.t)
        {
            case "hello": _hostName = m.name ?? _hostName; return true;      // il relay lo usa per l'indirizzo; qui non serve inoltrarlo
            case "full":
                _objs.Clear();
                if (m.objs != null) foreach (var o in m.objs) if (o != null && !string.IsNullOrEmpty(o.id)) _objs[o.id] = o;
                _sceneId = m.sceneId ?? ""; _sceneName = m.sceneName ?? "";
                return Broadcast(JsonUtility.ToJson(BuildSnapshot()), NetworkDelivery.ReliableFragmentedSequenced);
            case "obj": if (m.o != null && !string.IsNullOrEmpty(m.o.id)) _objs[m.o.id] = m.o; break;
            case "del": _objs.Remove(m.id ?? ""); break;
            case "clear": _objs.Clear(); break;
            case "scene": _sceneId = m.sceneId ?? ""; _sceneName = m.sceneName ?? ""; break;
            case "gen": _genState = m.genState ?? ""; _genText = m.genText ?? ""; break;
            case "pose": _pose = m; break;
        }
        var delivery = (m.t == "pose" || m.t == "pose2") ? NetworkDelivery.UnreliableSequenced : NetworkDelivery.ReliableFragmentedSequenced;
        return Broadcast(JsonUtility.ToJson(m), delivery);
    }

    SyncMsg BuildSnapshot()
    {
        var list = new List<SyncObj>(_objs.Values);
        var s = new SyncMsg
        {
            t = "snapshot", objs = list.ToArray(), sceneId = _sceneId, sceneName = _sceneName,
            hostOnline = true, hostName = _hostName, n = ClientCount, genState = _genState, genText = _genText,
            cohostOnline = _hasCohost, cohostName = _cohostName,
        };
        if (_pose != null) { s.hp = _pose.hp; s.lp = _pose.lp; s.rp = _pose.rp; }
        return s;
    }

    bool Broadcast(string json, NetworkDelivery delivery) => BroadcastExcept(json, delivery, ulong.MaxValue);

    bool BroadcastExcept(string json, NetworkDelivery delivery, ulong except)
    {
        if (ClientCount == 0) return true;
        foreach (var id in _nm.ConnectedClientsIds)
            if (id != _nm.LocalClientId && id != except) SendRaw(id, json, delivery);
        return true;
    }

    bool SendRaw(ulong target, string json, NetworkDelivery delivery)
    {
        try
        {
            var bytes = Encoding.UTF8.GetBytes(json);
            if (bytes.Length > MaxPayload) return false;
            using (var w = new FastBufferWriter(4 + bytes.Length, Allocator.Temp))
            {
                w.WriteValueSafe(bytes.Length);
                w.WriteBytesSafe(bytes);
                _nm.CustomMessagingManager.SendNamedMessage(MessageName, target, w, delivery);
            }
            return true;
        }
        catch (Exception e) { Debug.LogWarning($"[Netcode] invio fallito: {e.Message}"); return false; }
    }

    // ── Messaggi dei client verso l'host ──────────────────────────────

    void HandleClientMessage(ulong sender, SyncMsg m)
    {
        if (m.t == "hello")
        {
            if (m.role == "cohost")
            {
                if (_hasCohost && _cohostId != sender)
                {
                    // un solo co-host: il secondo viene rifiutato e scollegato (può rientrare come spettatore)
                    SendRaw(sender, JsonUtility.ToJson(new SyncMsg { t = "denied", reason = "cohost" }), NetworkDelivery.ReliableFragmentedSequenced);
                    StartCoroutine(KickLater(sender));
                    return;
                }
                _hasCohost = true; _cohostId = sender; _cohostName = m.name ?? "";
                var on = new SyncMsg { t = "cohost", cohostOnline = true, cohostName = _cohostName };
                RaiseMessage(on);                                                                      // all'host (SyncHost) e, via SyncFanout, al relay
                BroadcastExcept(JsonUtility.ToJson(on), NetworkDelivery.ReliableFragmentedSequenced, sender);   // agli spettatori
            }
            ClientMessage?.Invoke(sender, m);
            return;
        }

        if (!_hasCohost || sender != _cohostId) { ClientMessage?.Invoke(sender, m); return; }   // spettatori: sola visione

        switch (m.t)
        {
            case "obj": if (m.o != null && !string.IsNullOrEmpty(m.o.id)) _objs[m.o.id] = m.o; else return; break;
            case "del": _objs.Remove(m.id ?? ""); break;
            case "clear": _objs.Clear(); break;
            case "scene": _sceneId = m.sceneId ?? ""; _sceneName = m.sceneName ?? ""; break;
            case "pose2": break;
            default: return;   // il co-host non può inviare altro (niente "full", "gen", ecc.)
        }
        var delivery = m.t == "pose2" ? NetworkDelivery.UnreliableSequenced : NetworkDelivery.ReliableFragmentedSequenced;
        BroadcastExcept(JsonUtility.ToJson(m), delivery, sender);   // agli spettatori
        RaiseMessage(m);                                            // all'host e, via SyncFanout, al relay (browser)
    }

    System.Collections.IEnumerator KickLater(ulong id)
    {
        yield return new WaitForSeconds(0.4f);   // il tempo che il "denied" arrivi
        if (_nm != null && _nm.IsServer && _nm.ConnectedClientsIds.Contains(id)) _nm.DisconnectClient(id);
    }

    // ── Ricezione ─────────────────────────────────────────────────────

    void OnNamedMessage(ulong sender, FastBufferReader reader)
    {
        try
        {
            reader.ReadValueSafe(out int len);
            if (len <= 0 || len > MaxPayload) return;
            var bytes = new byte[len];
            reader.ReadBytesSafe(ref bytes, len);
            var m = JsonUtility.FromJson<SyncMsg>(Encoding.UTF8.GetString(bytes));
            if (m == null || string.IsNullOrEmpty(m.t)) return;

            if (_nm != null && _nm.IsServer) HandleClientMessage(sender, m);
            else RaiseMessage(m);
        }
        catch (Exception e) { Debug.LogWarning($"[Netcode] messaggio non valido: {e.Message}"); }
    }
}
#endif
