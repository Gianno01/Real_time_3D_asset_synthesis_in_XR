// SyncClient.cs
// Connessione WebSocket al relay (server/sync). Si riconnette da sola. Tutti gli eventi arrivano sul thread principale di Unity.
// Usa solo System.Net.WebSockets (incluso in Unity/Android): nessun pacchetto da installare.

using System;
using System.Collections.Concurrent;
using System.Net.WebSockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using UnityEngine;

public class SyncClient : SyncLink
{
    string _url = "";
    bool _want;
    int _generation;
    CancellationTokenSource _cts;
    ClientWebSocket _ws;

    readonly ConcurrentQueue<string> _in = new ConcurrentQueue<string>();
    readonly ConcurrentQueue<string> _out = new ConcurrentQueue<string>();
    readonly ConcurrentQueue<Action> _main = new ConcurrentQueue<Action>();

    public void Connect(string url)
    {
        Disconnect();
        _url = url;
        _want = true;
        int gen = ++_generation;
        _ = RunAsync(gen);
    }

    public void Disconnect()
    {
        _want = false;
        _generation++;
        try { _cts?.Cancel(); } catch { }
        try { _ws?.Dispose(); } catch { }
        State = Status.Disconnected;
        while (_out.TryDequeue(out _)) { }
    }

    /// <summary>Mette il messaggio in coda. false se non si è connessi (il messaggio si perde: lo stato completo viene rinviato alla riconnessione).</summary>
    public override bool Send(SyncMsg m) => State == Status.Connected && Enqueue(JsonUtility.ToJson(m));

    bool Enqueue(string json) { _out.Enqueue(json); return true; }

    void Post(Action a) => _main.Enqueue(a);

    async Task RunAsync(int gen)
    {
        int backoff = 1000;
        while (_want && gen == _generation)
        {
            var ws = new ClientWebSocket();
            var cts = new CancellationTokenSource();
            _ws = ws; _cts = cts;
            try
            {
                Post(() => { if (gen == _generation) State = Status.Connecting; });
                ws.Options.KeepAliveInterval = TimeSpan.FromSeconds(15);
                await ws.ConnectAsync(new Uri(_url), cts.Token);
                backoff = 1000;
                Post(() => { if (gen == _generation) { State = Status.Connected; LastError = ""; RaiseConnected(); } });
                await Task.WhenAny(ReceiveLoop(ws, cts.Token), SendLoop(ws, cts.Token));
            }
            catch (Exception e)
            {
                string msg = e.InnerException != null ? e.InnerException.Message : e.Message;
                Post(() => { if (gen == _generation) LastError = msg; });
            }
            finally
            {
                try { cts.Cancel(); } catch { }
                try { ws.Dispose(); } catch { }
                Post(() =>
                {
                    if (gen != _generation) return;
                    bool was = State == Status.Connected;
                    State = Status.Disconnected;
                    if (was) RaiseDisconnected();
                });
            }
            if (!_want || gen != _generation) break;
            while (_out.TryDequeue(out _)) { }
            try { await Task.Delay(backoff); } catch { }
            backoff = Math.Min(backoff * 2, 5000);
        }
    }

    async Task ReceiveLoop(ClientWebSocket ws, CancellationToken ct)
    {
        var buf = new byte[16 * 1024];
        var sb = new StringBuilder();
        while (ws.State == WebSocketState.Open && !ct.IsCancellationRequested)
        {
            var res = await ws.ReceiveAsync(new ArraySegment<byte>(buf), ct);
            if (res.MessageType == WebSocketMessageType.Close) return;
            if (res.MessageType != WebSocketMessageType.Text) continue;
            sb.Append(Encoding.UTF8.GetString(buf, 0, res.Count));
            if (res.EndOfMessage) { _in.Enqueue(sb.ToString()); sb.Clear(); }
        }
    }

    async Task SendLoop(ClientWebSocket ws, CancellationToken ct)
    {
        while (ws.State == WebSocketState.Open && !ct.IsCancellationRequested)
        {
            if (_out.TryDequeue(out var json))
            {
                var bytes = Encoding.UTF8.GetBytes(json);
                await ws.SendAsync(new ArraySegment<byte>(bytes), WebSocketMessageType.Text, true, ct);
            }
            else await Task.Delay(8, ct);
        }
    }

    void Update()
    {
        int guard = 0;
        while (guard++ < 64 && _main.TryDequeue(out var a)) { try { a(); } catch (Exception e) { Debug.LogException(e); } }
        guard = 0;
        while (guard++ < 64 && _in.TryDequeue(out var json))
        {
            SyncMsg m = null;
            try { m = JsonUtility.FromJson<SyncMsg>(json); } catch (Exception e) { Debug.LogWarning($"[Sync] Messaggio non valido: {e.Message}"); }
            if (m != null && !string.IsNullOrEmpty(m.t)) { RaiseMessage(m); }
        }
    }

    void OnDestroy() { Disconnect(); }
}
