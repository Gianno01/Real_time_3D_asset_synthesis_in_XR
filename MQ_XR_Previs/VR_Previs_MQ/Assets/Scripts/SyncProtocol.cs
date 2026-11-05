// SyncProtocol.cs
// Messaggi del multiplayer in sola visione (JSON, campo "t" = tipo). Il relay è server/sync/server.js.
// Le pose sono nello spazio dell'ancora di scena (la stanza calibrata): uguali per tutti i visori calibrati sugli stessi due punti.

using System;

public enum SyncRole { Off = 0, Host = 1, Viewer = 2 }

/// <summary>Come i visori si parlano: Relay = tramite il server sul PC; Netcode = direttamente in LAN (Netcode for GameObjects).</summary>
public enum SyncLinkMode { Relay = 0, Netcode = 1 }

[Serializable]
public class SyncObj
{
    public string id = "", name = "", assetId = "", glbKey = "", src = "";
    public float[] p = new float[0];    // posizione x,y,z (m) rispetto all'ancora
    public float[] r = new float[0];    // rotazione x,y,z,w rispetto all'ancora
    public float s = 1f;                // scala uniforme
    public bool locked;
    public float[] al = new float[0];   // correzione di raddrizzamento ("Allineamento"): centro x,y,z + rotazione x,y,z,w (spazio locale della radice); vuoto = nessuna
}

[Serializable]
public class SyncMsg
{
    public string t = "";
    public string role = "", name = "";
    public SyncObj o;
    public SyncObj[] objs = new SyncObj[0];
    public string id = "";
    public string sceneId = "", sceneName = "";
    public float[] hp = new float[0], lp = new float[0], rp = new float[0];   // testa, mano sinistra, mano destra: x,y,z,qx,qy,qz,qw
    public string genState = "", genText = "";
    public bool hostOnline;
    public string hostName = "";
    public string addr = "";           // hello dell'host: indirizzo LAN ip:porta dove i visori si collegano via Netcode
    public int n;
}
