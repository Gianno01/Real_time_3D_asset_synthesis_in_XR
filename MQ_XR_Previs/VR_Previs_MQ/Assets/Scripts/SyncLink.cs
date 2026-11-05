// SyncLink.cs
// Un "canale" su cui viaggiano i messaggi di SyncProtocol. Implementazioni:
//   SyncClient    WebSocket verso il relay sul PC (browser, telefoni, tablet)
//   NetcodeLink   Netcode for GameObjects tra visori (LAN)
//   SyncFanout    manda lo stesso messaggio a più canali (l'host Netcode pubblica anche sul relay per i browser)
// SyncHost e SyncViewer non sanno su quale canale stanno parlando.

using System;
using System.Collections.Generic;
using UnityEngine;

public abstract class SyncLink : MonoBehaviour
{
    public enum Status { Disconnected, Connecting, Connected }

    public Status State { get; protected set; } = Status.Disconnected;
    public string LastError { get; protected set; } = "";

    public event Action Connected;
    public event Action Disconnected;
    public event Action<SyncMsg> Message;

    protected void RaiseConnected() { try { Connected?.Invoke(); } catch (Exception e) { Debug.LogException(e); } }
    protected void RaiseDisconnected() { try { Disconnected?.Invoke(); } catch (Exception e) { Debug.LogException(e); } }
    protected void RaiseMessage(SyncMsg m) { try { Message?.Invoke(m); } catch (Exception e) { Debug.LogException(e); } }

    /// <summary>false se il messaggio non è partito (non connesso): lo stato completo viene rinviato alla riconnessione.</summary>
    public abstract bool Send(SyncMsg m);
}

/// <summary>Inoltra ogni messaggio a tutti i canali. È "connesso" se almeno uno lo è; a ogni nuova connessione di un canale
/// avvisa (Connected), così l'host rimanda lo stato completo.</summary>
public class SyncFanout : SyncLink
{
    readonly List<SyncLink> _links = new List<SyncLink>();

    public void Add(SyncLink l)
    {
        if (l == null || _links.Contains(l)) return;
        _links.Add(l);
        l.Connected += OnChildConnected;
        l.Message += RaiseMessage;
        Refresh();
    }

    public void Clear()
    {
        foreach (var l in _links) if (l != null) { l.Connected -= OnChildConnected; l.Message -= RaiseMessage; }
        _links.Clear();
        State = Status.Disconnected;
    }

    void OnChildConnected()
    {
        Refresh();
        RaiseConnected();
    }

    void Update() { Refresh(); }

    void Refresh()
    {
        bool any = false, connecting = false;
        string err = "";
        foreach (var l in _links)
        {
            if (l == null) continue;
            if (l.State == Status.Connected) any = true;
            else if (l.State == Status.Connecting) connecting = true;
            if (err.Length == 0 && !string.IsNullOrEmpty(l.LastError)) err = l.LastError;
        }
        State = any ? Status.Connected : (connecting ? Status.Connecting : Status.Disconnected);
        LastError = err;
    }

    public override bool Send(SyncMsg m)
    {
        bool sent = false;
        foreach (var l in _links) if (l != null && l.Send(m)) sent = true;
        return sent;
    }

    void OnDestroy() { Clear(); }
}
