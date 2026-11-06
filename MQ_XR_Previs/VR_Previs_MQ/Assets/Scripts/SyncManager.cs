// SyncManager.cs
// Multiplayer: sceglie ruolo e collegamento di questo dispositivo.
//   Ruolo       Spento · Host (questo visore genera e pubblica la scena) · Spettatore (guarda la scena dell'host; generazione e libreria bloccate)
//   Collegamento
//     Relay     i visori passano dal server sul PC (WebSocket, server/sync). Funziona anche tra reti diverse.
//     Netcode   i visori si collegano direttamente in LAN con Netcode for GameObjects (serve il pacchetto, vedi LEGGIMI).
//               L'host Netcode pubblica COMUNQUE anche sul relay, così telefoni e tablet vedono la scena dal browser:
//               http://<IP_PC>:8090/viewer/
//               Il visore spettatore trova da solo l'indirizzo dell'host chiedendolo al relay (oppure si imposta hostAddress).
//
// Indirizzo del relay: ricavato da AssetLibrary.storageUrl (http://IP:8090 → ws://IP:8090/sync). Si crea da sola (SettingsUI).

using System;
using System.Collections;
using System.Net;
using System.Net.NetworkInformation;
using System.Net.Sockets;
using UnityEngine;
using UnityEngine.Networking;

public class SyncManager : MonoBehaviour
{
    [Tooltip("Indirizzo del relay, es. ws://192.168.50.133:8090/sync. Vuoto = ricavato da Storage Url di AssetLibrary")]
    public string serverUrl = "";
    [Tooltip("Solo Netcode, visore spettatore: ip[:porta] dell'host. Vuoto = lo chiede al relay")]
    public string hostAddress = "";
    [Tooltip("Porta UDP dell'host Netcode")]
    public ushort netPort = 7777;

    public SyncRole Role { get; private set; } = SyncRole.Off;
    public SyncLinkMode LinkMode { get; private set; } = SyncLinkMode.Netcode;

    public bool NetcodeAvailable
    {
        get
        {
#if NETCODE_ENABLED
            return true;
#else
            return false;
#endif
        }
    }

    /// <summary>Modo effettivo: se Netcode non è installato si usa il relay.</summary>
    public SyncLinkMode EffectiveMode => LinkMode == SyncLinkMode.Netcode && NetcodeAvailable ? SyncLinkMode.Netcode : SyncLinkMode.Relay;

    public int ViewerCount
    {
        get
        {
            int n = _relayViewers;
#if NETCODE_ENABLED
            if (_net != null) n += _net.ClientCount;
#endif
            return n;
        }
    }

    public bool HostOnline => _viewer != null ? _viewer.HostOnline : Role == SyncRole.Host && _link != null && _link.State == SyncLink.Status.Connected;

    AssetLibrary _library;
    QuestObjectGenerator _gen;
    SyncClient _client;        // WebSocket verso il relay
    SyncFanout _fan;           // host: relay + Netcode
    SyncLink _link;            // canale usato da SyncHost/SyncViewer
    SyncHost _host;
    SyncViewer _viewer;
#if NETCODE_ENABLED
    NetcodeLink _net;
#endif
    int _epoch, _relayViewers;
    bool _started, _readOnly, _prevHandsFree, _prevGenEnabled;
    string _error = "", _searchNote = "";

    [Serializable] class StateInfo { public bool hostOnline; public string hostAddr = ""; }

    public static SyncManager EnsureExists(GameObject where)
    {
        var m = FindAnyObjectByType<SyncManager>();
        if (m == null) m = where.AddComponent<SyncManager>();
        return m;
    }

    void Start()
    {
        _library = FindAnyObjectByType<AssetLibrary>();
        _gen = FindAnyObjectByType<QuestObjectGenerator>();
        _started = true;
        Apply();
    }

    void OnDestroy() { SetReadOnly(false); }

    /// <summary>Cambia ruolo (dalle Impostazioni, anche prima dell'avvio: in quel caso si applica a Start).</summary>
    public void SetRole(SyncRole role)
    {
        if (role == Role && _started) return;
        Role = role;
        if (_started) Apply();
    }

    public void SetLinkMode(SyncLinkMode mode)
    {
        if (mode == LinkMode && _started) return;
        LinkMode = mode;
        if (_started && Role != SyncRole.Off) Apply();
    }

    public void Reconnect() { if (_started) Apply(); }

    string ResolveUrl()
    {
        if (!string.IsNullOrWhiteSpace(serverUrl)) return serverUrl.Trim();
        try
        {
            var u = new Uri(_library != null ? _library.storageUrl : "http://127.0.0.1:8090");
            string scheme = u.Scheme == "https" ? "wss" : "ws";
            return $"{scheme}://{u.Host}:{u.Port}/sync";
        }
        catch (Exception e) { _error = e.Message; return ""; }
    }

    string StateUrl()
    {
        try
        {
            var u = new Uri(_library != null ? _library.storageUrl : "http://127.0.0.1:8090");
            return $"{u.Scheme}://{u.Host}:{u.Port}/sync/state";
        }
        catch { return ""; }
    }

    void StopAll()
    {
        _epoch++;
        StopAllCoroutines();
        if (_host != null) Destroy(_host);
        if (_viewer != null) Destroy(_viewer);
        _host = null; _viewer = null; _link = null;
        if (_fan != null) { Destroy(_fan); _fan = null; }
#if NETCODE_ENABLED
        if (_net != null) { _net.Stop(); Destroy(_net); _net = null; }
#endif
        if (_client != null) _client.Disconnect();
        _relayViewers = 0;
        _error = ""; _searchNote = "";
    }

    void Apply()
    {
        StopAll();
        if (Role == SyncRole.Off) { SetReadOnly(false); return; }

        if (_library == null) _library = FindAnyObjectByType<AssetLibrary>();
        if (_gen == null) _gen = FindAnyObjectByType<QuestObjectGenerator>();
        SetReadOnly(Role == SyncRole.Viewer);

        if (_client == null)
        {
            _client = gameObject.AddComponent<SyncClient>();
            _client.Message += OnRelayMessage;
        }
        StartCoroutine(Begin(_epoch));
    }

    IEnumerator Begin(int epoch)
    {
#if NETCODE_ENABLED
        // un eventuale arresto precedente di Netcode deve essere finito
        for (int i = 0; i < 120 && NetcodeBusy(); i++) yield return null;
#else
        yield return null;
#endif
        if (epoch != _epoch) yield break;

        bool useNet = EffectiveMode == SyncLinkMode.Netcode;
        string url = ResolveUrl();

        if (Role == SyncRole.Host)
        {
            _fan = gameObject.AddComponent<SyncFanout>();
            _fan.Add(_client);
            string advertise = "";
#if NETCODE_ENABLED
            if (useNet)
            {
                _net = gameObject.AddComponent<NetcodeLink>();
                string who = _library != null ? _library.Author : SystemInfo.deviceName;
                if (_net.StartHost(netPort, who))
                {
                    _fan.Add(_net);
                    string ip = LocalAddress();
                    advertise = string.IsNullOrEmpty(ip) ? "" : $"{ip}:{netPort}";
                    Debug.Log($"[Sync] Netcode host in ascolto su {advertise}");
                }
                else { _error = _net.LastError; Debug.LogWarning($"[Sync] {_error}"); }
            }
#endif
            _link = _fan;
            _host = gameObject.AddComponent<SyncHost>();
            _host.advertiseAddr = advertise;
            _host.Begin(_fan, _library, _gen);
            if (!string.IsNullOrEmpty(url)) { Debug.Log($"[Sync] Host → relay {url}"); _client.Connect(url); }
            yield break;
        }

        // Spettatore
        if (!useNet)
        {
            _link = _client;
            _viewer = gameObject.AddComponent<SyncViewer>();
            _viewer.Begin(_client, _library, _gen);
            if (!string.IsNullOrEmpty(url)) { Debug.Log($"[Sync] Spettatore → relay {url}"); _client.Connect(url); }
            yield break;
        }
#if NETCODE_ENABLED
        _net = gameObject.AddComponent<NetcodeLink>();
        _link = _net;
        _viewer = gameObject.AddComponent<SyncViewer>();
        _viewer.Begin(_net, _library, _gen);
        yield return NetClientLoop(epoch);
#endif
    }

#if NETCODE_ENABLED
    bool NetcodeBusy() { return _net != null ? _net.Busy : Unity.Netcode.NetworkManager.Singleton != null && Unity.Netcode.NetworkManager.Singleton.ShutdownInProgress; }

    // Cerca l'host (indirizzo manuale o chiesto al relay), si collega, e se cade riprova.
    IEnumerator NetClientLoop(int epoch)
    {
        while (epoch == _epoch && Role == SyncRole.Viewer && _net != null)
        {
            string addr = hostAddress != null ? hostAddress.Trim() : "";
            if (addr.Length == 0)
            {
                string su = StateUrl();
                if (su.Length > 0)
                {
                    using (var req = UnityWebRequest.Get(su))
                    {
                        req.timeout = 4;
                        yield return req.SendWebRequest();
                        if (req.result == UnityWebRequest.Result.Success)
                        {
                            try
                            {
                                var info = JsonUtility.FromJson<StateInfo>(req.downloadHandler.text);
                                if (info != null && info.hostOnline && !string.IsNullOrEmpty(info.hostAddr)) addr = info.hostAddr;
                                else _searchNote = info != null && info.hostOnline ? "host senza indirizzo" : "host non connesso";
                            }
                            catch (Exception e) { _searchNote = e.Message; }
                        }
                        else _searchNote = "server non raggiungibile";
                    }
                }
            }
            if (epoch != _epoch || _net == null) yield break;

            if (addr.Length > 0)
            {
                ParseAddress(addr, out string ip, out ushort port);
                while (_net != null && _net.Busy) yield return null;
                if (epoch != _epoch || _net == null) yield break;
                _searchNote = "";
                if (_net.StartClientTo(ip, port))
                {
                    float t = 0;
                    while (epoch == _epoch && _net != null && _net.State == SyncLink.Status.Connecting && t < 10f) { t += Time.unscaledDeltaTime; yield return null; }
                    while (epoch == _epoch && _net != null && _net.State == SyncLink.Status.Connected) yield return null;
                    if (epoch != _epoch || _net == null) yield break;
                    _error = _net.LastError;
                    _net.Stop();
                }
                else _error = _net.LastError;
            }

            float w = 0;
            while (epoch == _epoch && w < 2f) { w += Time.unscaledDeltaTime; yield return null; }
        }
    }

    void ParseAddress(string addr, out string ip, out ushort port)
    {
        ip = addr; port = netPort;
        int i = addr.LastIndexOf(':');
        if (i > 0 && ushort.TryParse(addr.Substring(i + 1), out var p)) { ip = addr.Substring(0, i); port = p; }
    }
#endif

    // Indirizzo LAN di questo dispositivo: quello con cui raggiungerebbe il PC del relay
    string LocalAddress()
    {
        try
        {
            string reach = "8.8.8.8";
            try { reach = new Uri(_library != null ? _library.storageUrl : "http://8.8.8.8").Host; } catch { }
            using (var s = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp))
            {
                s.Connect(reach, 65530);   // UDP: non invia nulla, serve solo a sapere da quale interfaccia si uscirebbe
                var ep = s.LocalEndPoint as IPEndPoint;
                if (ep != null && !IPAddress.IsLoopback(ep.Address)) return ep.Address.ToString();
            }
        }
        catch { }
        try
        {
            foreach (var ni in NetworkInterface.GetAllNetworkInterfaces())
            {
                if (ni.OperationalStatus != OperationalStatus.Up || ni.NetworkInterfaceType == NetworkInterfaceType.Loopback) continue;
                foreach (var ua in ni.GetIPProperties().UnicastAddresses)
                    if (ua.Address.AddressFamily == AddressFamily.InterNetwork) return ua.Address.ToString();
            }
        }
        catch { }
        return "";
    }

    void OnRelayMessage(SyncMsg m)
    {
        if (m.t == "viewers" || m.t == "snapshot" || m.t == "welcome") _relayViewers = m.n;
    }

    // Lo spettatore non può chiedere nulla: niente generazione a voce, niente libreria
    void SetReadOnly(bool on)
    {
        if (on == _readOnly) return;
        _readOnly = on;
        if (_gen == null) _gen = FindAnyObjectByType<QuestObjectGenerator>();
        var lib = FindAnyObjectByType<LibraryUI>();
        if (on)
        {
            if (_gen != null) { _prevHandsFree = _gen.handsFreeMode; _prevGenEnabled = _gen.enabled; _gen.SetHandsFree(false); _gen.enabled = false; }
            if (lib != null) { lib.Hide(); lib.enabled = false; }
        }
        else
        {
            if (_gen != null) { _gen.enabled = _prevGenEnabled; if (_prevHandsFree) _gen.SetHandsFree(true); }
            if (lib != null) lib.enabled = true;
        }
    }

    /// <summary>Testo di stato per le Impostazioni.</summary>
    public string StatusLabel
    {
        get
        {
            if (Role == SyncRole.Off) return "Rete: spenta";
            if (LinkMode == SyncLinkMode.Netcode && !NetcodeAvailable) { if (Role == SyncRole.Host) return "Netcode non installato · uso il relay"; }
            bool net = EffectiveMode == SyncLinkMode.Netcode;

            if (Role == SyncRole.Host)
            {
                if (_fan == null) return "Rete: avvio...";
                int relay = _relayViewers;
                int visori = 0;
#if NETCODE_ENABLED
                if (_net != null) visori = _net.ClientCount;
#endif
                bool relayUp = _client != null && _client.State == SyncLink.Status.Connected;
                string s = net ? $"Host · {visori} visori · {relay} browser" : $"Host · {relay} spettatori";
                if (!relayUp) s += net ? " (web non raggiungibile)" : "";
                if (!relayUp && !net) return "Rete: server non raggiungibile";
                if (net && _fan.State != SyncLink.Status.Connected) return string.IsNullOrEmpty(_error) ? "Rete: avvio host..." : "Netcode: avvio non riuscito";
                return s;
            }

            if (_link == null) return "Rete: avvio...";
            if (_link.State == SyncLink.Status.Connecting) return "Rete: connessione...";
            if (_link.State == SyncLink.Status.Disconnected)
            {
                if (net) return _searchNote.Length > 0 ? $"Spettatore · cerco l'host ({_searchNote})" : "Spettatore · cerco l'host...";
                return string.IsNullOrEmpty(_link.LastError) ? "Rete: non connesso" : "Rete: server non raggiungibile";
            }
            return _viewer != null && _viewer.HostOnline ? $"Spettatore · {_viewer.ObjectCount} oggetti" : "Spettatore · host non connesso";
        }
    }
}
