// SyncProtocol.cs
// Messaggi del multiplayer: host, co-host e spettatori (JSON, campo "t" = tipo).
// pose = testa/mani dell'host · pose2 = testa/mani del co-host · cohost = il co-host è entrato/uscito · denied = ruolo non disponibile. Il relay è server/sync/server.js.
// Le pose sono nello spazio dell'ancora di scena (la stanza calibrata): uguali per tutti i visori calibrati sugli stessi due punti.

using System;

/// <summary>Host = trasmette la scena (uno solo) · Viewer = guarda · CoHost = collabora alla scena dell'host: vede, crea, sposta ed elimina oggetti in tempo reale.</summary>
public enum SyncRole { Off = 0, Host = 1, Viewer = 2, CoHost = 3 }

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
    public bool cohostOnline;          // c'è un co-host collegato
    public string cohostName = "";
    public string reason = "";         // denied: host (c'è già un host) · cohost (c'è già un co-host) · viewers (troppi spettatori)
    public int n;
    public string lighting = "";       // t="light" e snapshot: luci, blocchi di occlusione e oscuramento (JSON di SceneLighting, spazio dell'ancora; "" = niente)
}
