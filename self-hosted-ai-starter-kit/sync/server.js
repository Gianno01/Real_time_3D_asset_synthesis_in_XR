'use strict';
// Relay in tempo reale della scena XR.
//
//  • UN solo "host" (il visore che genera) pubblica lo stato: oggetti, posizioni, testa/mani, stato della generazione.
//  • N "spettatori" (secondo visore, telefono/tablet nel browser) ricevono tutto in tempo reale.
//  • Lo stato vive in memoria: chi entra dopo riceve subito la fotografia attuale (snapshot).
//  • Un solo "co-host" (secondo visore) collabora alla stessa scena: crea, sposta ed elimina oggetti come l'host.
//    Le sue modifiche passano dal server, che le applica allo stato, le gira all'host e agli spettatori.
//  • Se c'è già un host, un secondo host viene RIFIUTATO (denied{reason:"host"}); se c'è già un co-host, un secondo co-host
//    pure (denied{reason:"cohost"}). Restano liberi i posti da spettatore. Un host "morto" (non risponde al ping) o lo
//    stesso dispositivo che si ricollega (stesso nome) sostituisce quello vecchio.
//  • Gli spettatori NON possono modificare niente: i loro messaggi di scrittura sono ignorati.
//
// Protocollo: messaggi JSON di testo, campo "t" = tipo. Vedi LEGGIMI.md (sezione Multiplayer).
//   host → server: hello{role:"host",name,addr?} · full{objs,sceneId,sceneName} · obj{o} · del{id} · clear · scene{sceneId,sceneName}
//                  · pose{hp,lp,rp} · gen{genState,genText}
//   co-host → server: hello{role:"cohost",name} · obj{o} · del{id} · clear · scene{...} · pose2{hp,lp,rp}
//   spettatore → server: hello{role:"viewer",name}
//   server → tutti: snapshot{... cohostOnline,cohostName} · obj · del · clear · scene · pose · pose2 · gen · host{hostOnline,hostName}
//                   · cohost{cohostOnline,cohostName} · viewers{n}      server → chi è rifiutato: denied{reason} e chiusura (4003)
//
// Gratuito: Node + libreria "ws" (MIT). Nessun cloud.

const http = require('http');
const fs = require('fs');
const path = require('path');
const { WebSocketServer, WebSocket } = require('ws');

const MAX_OBJECTS = 500;
const MAX_LIGHTING = 200 * 1024;   // JSON di SceneLighting
const MAX_VIEWERS = 30;
const HELLO_TIMEOUT_MS = 5000;

function createRelay() {
  const state = {
    objs: new Map(), sceneId: '', sceneName: '', pose: null, lighting: '', genState: '', genText: '', hostName: '', hostAddr: '', pose2: null, cohostName: '',
  };
  let host = null;
  let cohost = null;
  const viewers = new Set();

  const OPEN = WebSocket.OPEN;
  const str = (s, max) => (typeof s === 'string' ? s.slice(0, max) : '');
  const nums = (a, n) => (Array.isArray(a) && a.length === n && a.every(Number.isFinite) ? a.map(Number) : null);

  // percorsi ammessi: il viewer web costruisce gli URL da questi campi, quindi si accetta solo la forma attesa
  const GLB_KEY = /^assets\/[0-9a-f-]{36}\/model\.glb$/;
  const HOST_ADDR = /^[0-9A-Za-z.:\-\[\]]{1,80}$/;   // indirizzo LAN del visore host (Netcode), es. 192.168.1.20:7777
  const COMFY_SRC = /^\/view\?[A-Za-z0-9_.=&%+\-\/ ]{1,500}$/;

  function cleanObj(o) {
    if (!o || typeof o.id !== 'string' || !o.id || o.id.length > 64) return null;
    const glbKey = GLB_KEY.test(o.glbKey || '') ? o.glbKey : '';
    const src = COMFY_SRC.test(o.src || '') ? o.src : '';
    return {
      id: o.id,
      name: str(o.name, 120),
      assetId: str(o.assetId, 64),
      glbKey,
      src,
      p: nums(o.p, 3) || [0, 0, 0],
      r: nums(o.r, 4) || [0, 0, 0, 1],
      s: Number.isFinite(o.s) && o.s > 0 ? o.s : 1,
      locked: !!o.locked,
      al: nums(o.al, 7),
    };
  }

  const snapshot = () => ({
    t: 'snapshot',
    objs: [...state.objs.values()],
    sceneId: state.sceneId, sceneName: state.sceneName,
    hostOnline: !!host, hostName: state.hostName, hostAddr: host ? state.hostAddr : '',
    n: viewers.size,
    cohostOnline: !!cohost, cohostName: cohost ? state.cohostName : '',
    genState: state.genState, genText: state.genText,
    lighting: state.lighting,
    ...(state.pose || {}),
  });

  function send(ws, msg) { if (ws && ws.readyState === OPEN) ws.send(JSON.stringify(msg)); }
  function toViewers(msg) {
    const data = JSON.stringify(msg);
    for (const v of viewers) if (v.readyState === OPEN) v.send(data);
  }
  // modifiche di scena: agli spettatori e all'altro redattore (host ↔ co-host)
  function toAll(msg, from) {
    toViewers(msg);
    const other = from === host ? cohost : host;
    if (other && other !== from) send(other, msg);
  }
  function announceViewers() {
    const m = { t: 'viewers', n: viewers.size };
    toViewers(m); send(host, m);
  }
  function announceHost() {
    const m = { t: 'host', hostOnline: !!host, hostName: state.hostName };
    toViewers(m); send(cohost, m);
  }
  function announceCoHost() {
    const m = { t: 'cohost', cohostOnline: !!cohost, cohostName: cohost ? state.cohostName : '' };
    toViewers(m); send(host, m);
    if (!cohost) state.pose2 = null;
  }

  function onEditorMessage(ws, m) {
    const isHost = ws === host;
    switch (m.t) {
      case 'full': {
        if (!isHost) return;
        state.objs.clear();
        for (const o of Array.isArray(m.objs) ? m.objs.slice(0, MAX_OBJECTS) : []) {
          const c = cleanObj(o); if (c) state.objs.set(c.id, c);
        }
        state.sceneId = str(m.sceneId, 64); state.sceneName = str(m.sceneName, 120);
        toAll(snapshot(), ws);
        break;
      }
      case 'obj': {
        const c = cleanObj(m.o); if (!c) return;
        if (!state.objs.has(c.id) && state.objs.size >= MAX_OBJECTS) return;
        state.objs.set(c.id, c);
        toAll({ t: 'obj', o: c }, ws);
        break;
      }
      case 'del': {
        const id = str(m.id, 64);
        if (state.objs.delete(id)) toAll({ t: 'del', id }, ws);
        break;
      }
      case 'clear':
        state.objs.clear();
        toAll({ t: 'clear' }, ws);
        break;
      case 'scene':
        state.sceneId = str(m.sceneId, 64); state.sceneName = str(m.sceneName, 120);
        toAll({ t: 'scene', sceneId: state.sceneId, sceneName: state.sceneName }, ws);
        break;
      case 'light':   // luci, blocchi di occlusione e oscuramento: host e co-host li modificano, tutti li vedono
        state.lighting = str(m.lighting, MAX_LIGHTING);
        toAll({ t: 'light', lighting: state.lighting }, ws);
        break;
      case 'pose': {
        if (!isHost) return;
        const hp = nums(m.hp, 7), lp = nums(m.lp, 7), rp = nums(m.rp, 7);
        state.pose = { hp: hp || [], lp: lp || [], rp: rp || [] };
        toAll({ t: 'pose', ...state.pose }, ws);
        break;
      }
      case 'pose2': {
        if (isHost) return;
        const hp = nums(m.hp, 7), lp = nums(m.lp, 7), rp = nums(m.rp, 7);
        state.pose2 = { hp: hp || [], lp: lp || [], rp: rp || [] };
        toViewers({ t: 'pose2', ...state.pose2 }); send(host, { t: 'pose2', ...state.pose2 });
        break;
      }
      case 'gen':
        if (!isHost) return;
        state.genState = str(m.genState, 40); state.genText = str(m.genText, 240);
        toViewers({ t: 'gen', genState: state.genState, genText: state.genText });
        break;
      default: break;
    }
  }

  function attach(ws) {
    let role = null;
    ws.isAlive = true;
    ws.on('pong', () => { ws.isAlive = true; });
    const helloTimer = setTimeout(() => { if (!role) ws.close(4000, 'hello mancante'); }, HELLO_TIMEOUT_MS);

    ws.on('message', (data, isBinary) => {
      if (isBinary) return;
      let m; try { m = JSON.parse(data.toString()); } catch { return; }
      if (!m || typeof m.t !== 'string') return;

      if (!role) {
        if (m.t !== 'hello') return;
        clearTimeout(helloTimer);
        const deny = reason => { send(ws, { t: 'denied', reason }); role = 'denied'; setTimeout(() => { try { ws.close(4003, 'ruolo rifiutato: ' + reason); } catch {} }, 300); };
        if (m.role === 'host') {
          if (host && host !== ws && host.readyState === OPEN && host.isAlive !== false && state.hostName !== str(m.name, 60)) { deny('host'); return; }
          role = 'host';
          if (host && host !== ws) { try { host.close(4001, 'sostituito da un altro host'); } catch {} }
          host = ws;
          state.hostName = str(m.name, 60);
          state.hostAddr = typeof m.addr === 'string' && HOST_ADDR.test(m.addr) ? m.addr : '';
          announceHost();
          send(ws, { t: 'welcome', role, n: viewers.size });
          if (cohost) send(ws, { t: 'cohost', cohostOnline: true, cohostName: state.cohostName });
        } else if (m.role === 'cohost') {
          if (cohost && cohost !== ws && cohost.readyState === OPEN && cohost.isAlive !== false && state.cohostName !== str(m.name, 60)) { deny('cohost'); return; }
          role = 'cohost';
          if (cohost && cohost !== ws) { try { cohost.close(4001, 'sostituito'); } catch {} }
          cohost = ws;
          state.cohostName = str(m.name, 60);
          send(ws, snapshot());
          announceCoHost();
        } else {
          if (viewers.size >= MAX_VIEWERS) { ws.close(4002, 'troppi spettatori'); return; }
          role = 'viewer';
          viewers.add(ws);
          send(ws, snapshot());
          announceViewers();
        }
        return;
      }
      if ((role === 'host' && host === ws) || (role === 'cohost' && cohost === ws)) onEditorMessage(ws, m);
      // gli spettatori non scrivono: tutto il resto è ignorato
    });

    ws.on('close', () => {
      clearTimeout(helloTimer);
      if (role === 'host' && host === ws) { host = null; announceHost(); }
      if (role === 'cohost' && cohost === ws) { cohost = null; announceCoHost(); }
      if (role === 'viewer') { viewers.delete(ws); announceViewers(); }
    });
    ws.on('error', () => {});
  }

  const info = () => ({ cohost: !!cohost, cohostName: cohost ? state.cohostName : '', host: !!host, hostName: state.hostName, hostAddr: host ? state.hostAddr : '', viewers: viewers.size, objects: state.objs.size, sceneName: state.sceneName });
  return { attach, info, state, snapshot };
}

// Libreria three.js per il viewer web, servita da qui (installata da npm al primo avvio): il viewer funziona anche senza Internet.
//   /sync/vendor/three.module.js        → node_modules/three/build/three.module.js
//   /sync/vendor/addons/<percorso>.js   → node_modules/three/examples/jsm/<percorso>.js
function serveVendor(url, res) {
  const rel = url.slice('/sync/vendor/'.length);
  let file = null;
  if (rel === 'three.module.js') file = path.join(__dirname, 'node_modules/three/build/three.module.js');
  else if (rel.startsWith('addons/') && /^[A-Za-z0-9_\/.-]+\.js$/.test(rel) && !rel.includes('..')) {
    file = path.join(__dirname, 'node_modules/three/examples/jsm', rel.slice('addons/'.length));
  }
  if (!file) { res.writeHead(404); res.end(); return; }
  fs.readFile(file, (err, data) => {
    if (err) { res.writeHead(404); res.end(); return; }
    res.writeHead(200, { 'Content-Type': 'text/javascript; charset=utf-8', 'Cache-Control': 'public, max-age=86400' });
    res.end(data);
  });
}

function start(port = Number(process.env.PORT || 8765)) {
  const relay = createRelay();
  const server = http.createServer((req, res) => {
    const url = (req.url || '').split('?')[0];
    if (url === '/health' || url === '/sync/health') {
      res.writeHead(200, { 'Content-Type': 'application/json' });
      res.end(JSON.stringify({ ok: true, ...relay.info() }));
    } else if (url.startsWith('/sync/vendor/')) {
      serveVendor(url, res);
    } else if (url === '/sync/state') {
      res.writeHead(200, { 'Content-Type': 'application/json' });
      res.end(JSON.stringify(relay.snapshot()));
    } else { res.writeHead(404); res.end(); }
  });
  const wss = new WebSocketServer({ server, maxPayload: 256 * 1024, perMessageDeflate: false });
  wss.on('connection', ws => relay.attach(ws));
  const beat = setInterval(() => {
    for (const ws of wss.clients) {
      if (ws.isAlive === false) { ws.terminate(); continue; }
      ws.isAlive = false; try { ws.ping(); } catch {}
    }
  }, 15000);
  wss.on('close', () => clearInterval(beat));
  return new Promise(resolve => server.listen(port, () => {
    console.log(`[sync] in ascolto sulla porta ${server.address().port}`);
    resolve({ server, wss, relay, close: () => { clearInterval(beat); wss.close(); server.close(); } });
  }));
}

module.exports = { start, createRelay };
if (require.main === module) start();
