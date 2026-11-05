// Vista live della scena XR (sola visione): si collega al relay (/sync) e mostra gli oggetti del visore in tempo reale.
import * as THREE from 'three';
import { GLTFLoader } from 'three/addons/loaders/GLTFLoader.js';
import { OrbitControls } from 'three/addons/controls/OrbitControls.js';
import { objectTransform, modelUrl, pos, quat } from './transform.js';

const $ = id => document.getElementById(id);
const params = new URLSearchParams(location.search);
const WS_URL = params.get('ws') || `${location.protocol === 'https:' ? 'wss' : 'ws'}://${location.host}/sync`;

// ── Scena ────────────────────────────────────────────────────────────

const renderer = new THREE.WebGLRenderer({ antialias: true, powerPreference: 'high-performance' });
renderer.setPixelRatio(Math.min(window.devicePixelRatio || 1, 2));
renderer.toneMapping = THREE.ACESFilmicToneMapping;
$('stage').appendChild(renderer.domElement);

const scene = new THREE.Scene();
scene.background = new THREE.Color(0x0b0d12);
scene.fog = new THREE.Fog(0x0b0d12, 12, 30);
scene.add(new THREE.HemisphereLight(0xffffff, 0x2b3345, 1.5));
const sun = new THREE.DirectionalLight(0xffffff, 2.2);
sun.position.set(3, 6, 2);
scene.add(sun);

const grid = new THREE.GridHelper(10, 20, 0x3a4a6b, 0x1c2433);
scene.add(grid);
const axes = new THREE.AxesHelper(0.4);   // origine della stanza (punto A della calibrazione)
scene.add(axes);

const camera = new THREE.PerspectiveCamera(55, 1, 0.02, 100);
camera.position.set(2.6, 2.0, 3.2);
const controls = new OrbitControls(camera, renderer.domElement);
controls.target.set(0, 0.5, 0);
controls.enableDamping = true;
controls.maxPolarAngle = Math.PI * 0.499;
controls.update();

function resize() {
  const w = $('stage').clientWidth, h = $('stage').clientHeight;
  renderer.setSize(w, h, false);
  camera.aspect = w / h;
  camera.updateProjectionMatrix();
}
window.addEventListener('resize', resize);
resize();

// ── Oggetti ──────────────────────────────────────────────────────────

const loader = new GLTFLoader();
const objects = new Map();   // id → { root, pivot, holder, model, info, target, placeholder, born }

function makePlaceholder() {
  const m = new THREE.Mesh(new THREE.BoxGeometry(0.2, 0.2, 0.2),
    new THREE.MeshBasicMaterial({ color: 0x6aa3ff, wireframe: true, transparent: true, opacity: 0.6 }));
  m.position.y = 0.1;
  return m;
}

function dispose(node) {
  node.traverse(n => {
    if (n.geometry) n.geometry.dispose();
    const mats = n.material ? (Array.isArray(n.material) ? n.material : [n.material]) : [];
    for (const m of mats) {
      for (const k of Object.keys(m)) if (m[k] && m[k].isTexture) m[k].dispose();
      m.dispose();
    }
  });
}

function applyTarget(e, o, snap) {
  const t = objectTransform(o);
  e.target = t;
  e.pivot.position.fromArray(t.pivotPos);
  e.pivot.quaternion.fromArray(t.pivotQuat);
  e.holder.position.fromArray(t.holderPos);
  if (snap) {
    e.root.position.fromArray(t.pos);
    e.root.quaternion.fromArray(t.quat);
    e.root.scale.setScalar(t.scale * 0.6);   // piccola comparsa (cresce fino a 1)
  }
}

async function loadModel(e) {
  const url = modelUrl(e.info);
  if (!url) return;
  const wanted = url;
  e.url = url;
  try {
    const gltf = await loader.loadAsync(url);
    if (!objects.has(e.info.id) || e.url !== wanted) { dispose(gltf.scene); return; }   // nel frattempo eliminato o cambiato
    e.model = gltf.scene;
    e.holder.add(e.model);
    e.holder.remove(e.placeholder);
    dispose(e.placeholder);
    e.placeholder = null;
    e.born = performance.now();
  } catch (err) {
    console.warn('Modello non caricato', url, err);
    if (e.placeholder) e.placeholder.material.color.set(0xff6b6b);
    e.failed = true;
  }
  refreshList();
}

function upsert(o) {
  let e = objects.get(o.id);
  if (!e) {
    const root = new THREE.Group(), pivot = new THREE.Group(), holder = new THREE.Group();
    root.add(pivot); pivot.add(holder);
    const placeholder = makePlaceholder();
    holder.add(placeholder);
    scene.add(root);
    e = { root, pivot, holder, placeholder, model: null, info: o, target: null, born: 0, url: '' };
    objects.set(o.id, e);
    applyTarget(e, o, true);
    loadModel(e);
  } else {
    const before = modelUrl(e.info);
    e.info = o;
    applyTarget(e, o, false);
    if (modelUrl(o) !== before) {   // l'oggetto è stato salvato: ora ha un percorso di libreria
      if (e.model) { e.holder.remove(e.model); dispose(e.model); e.model = null; }
      if (!e.placeholder) { e.placeholder = makePlaceholder(); e.holder.add(e.placeholder); }
      e.failed = false;
      loadModel(e);
    }
  }
  refreshList();
}

function remove(id) {
  const e = objects.get(id);
  if (!e) return;
  scene.remove(e.root);
  dispose(e.root);
  objects.delete(id);
  refreshList();
}

function setAll(list) {
  const ids = new Set(list.map(o => o.id));
  for (const id of [...objects.keys()]) if (!ids.has(id)) remove(id);
  for (const o of list) upsert(o);
}

// ── Avatar dell'host (testa e controller) ────────────────────────────

const avatar = new THREE.Group();
avatar.visible = false;
scene.add(avatar);
const head = new THREE.Group();
head.add(new THREE.Mesh(new THREE.SphereGeometry(0.09, 20, 14), new THREE.MeshStandardMaterial({ color: 0x6aa3ff, roughness: 0.5 })));
const nose = new THREE.Mesh(new THREE.ConeGeometry(0.035, 0.1, 12), new THREE.MeshStandardMaterial({ color: 0xffffff }));
nose.rotation.x = Math.PI / 2;      // il cono punta verso +Z (avanti, come nel visore)
nose.position.z = 0.12;
head.add(nose);
avatar.add(head);
function hand(color) {
  const m = new THREE.Mesh(new THREE.SphereGeometry(0.035, 14, 10), new THREE.MeshStandardMaterial({ color }));
  m.visible = false; avatar.add(m); return m;
}
const handL = hand(0x33dc8f), handR = hand(0xffb44d);
const poseTarget = { head: null, l: null, r: null };

function setPose(m) {
  const ok = a => Array.isArray(a) && a.length === 7;
  poseTarget.head = ok(m.hp) ? m.hp : null;
  poseTarget.l = ok(m.lp) ? m.lp : null;
  poseTarget.r = ok(m.rp) ? m.rp : null;
  avatar.visible = !!poseTarget.head && hostOnline;
  handL.visible = !!poseTarget.l; handR.visible = !!poseTarget.r;
}

function damp(obj, p, k) {
  const tp = pos(p.slice(0, 3)), tq = quat(p.slice(3, 7));
  obj.position.lerp(new THREE.Vector3(...tp), k);
  obj.quaternion.slerp(new THREE.Quaternion(...tq), k);
}

// ── Stato e interfaccia ──────────────────────────────────────────────

let hostOnline = false, viewerCount = 0, connected = false, mode = 'orbit';

function setStatus() {
  const dot = $('dot'), txt = $('status');
  if (!connected) { dot.className = 'dot bad'; txt.textContent = 'Server non raggiungibile…'; }
  else if (!hostOnline) { dot.className = 'dot warn'; txt.textContent = 'Visore non connesso'; }
  else { dot.className = 'dot ok'; txt.textContent = 'In diretta'; }
  $('viewers').textContent = connected ? `${viewerCount} ${viewerCount === 1 ? 'spettatore' : 'spettatori'}` : '';
  avatar.visible = avatar.visible && hostOnline;
  if (!hostOnline) avatar.visible = false;
}

function refreshList() {
  const ul = $('list');
  ul.textContent = '';
  const items = [...objects.values()];
  $('count').textContent = String(items.length);
  for (const e of items) {
    const li = document.createElement('li');
    const name = document.createElement('span');
    name.textContent = e.info.name || 'oggetto';
    li.appendChild(name);
    const tag = document.createElement('small');
    tag.textContent = e.failed ? 'non disponibile' : (e.model ? (e.info.locked ? '🔒 bloccato' : '') : 'carico…');
    li.appendChild(tag);
    li.addEventListener('click', () => {
      setMode('orbit');
      controls.target.copy(e.root.position);
      $('drawer').classList.remove('open');
    });
    ul.appendChild(li);
  }
}

function setMode(m) {
  mode = m;
  controls.enabled = m === 'orbit';
  for (const b of document.querySelectorAll('[data-mode]')) b.classList.toggle('on', b.dataset.mode === m);
  if (m === 'top') {
    camera.position.set(controls.target.x, 7, controls.target.z + 0.001);
    controls.target.y = 0;
    camera.lookAt(controls.target);
    controls.enabled = true;
  }
  if (m === 'follow' && !poseTarget.head) $('hint').textContent = 'Il visore non ha ancora inviato la posizione della testa.';
  else $('hint').textContent = '';
}
for (const b of document.querySelectorAll('[data-mode]')) b.addEventListener('click', () => setMode(b.dataset.mode));
$('listBtn').addEventListener('click', () => $('drawer').classList.toggle('open'));

// ── Collegamento al relay ────────────────────────────────────────────

let ws = null, retry = 800;

function connect() {
  ws = new WebSocket(WS_URL);
  ws.onopen = () => {
    connected = true; retry = 800;
    ws.send(JSON.stringify({ t: 'hello', role: 'viewer', name: 'browser' }));
    setStatus();
  };
  ws.onclose = () => {
    connected = false; hostOnline = false; setStatus();
    setTimeout(connect, retry); retry = Math.min(retry * 1.7, 5000);
  };
  ws.onerror = () => { try { ws.close(); } catch {} };
  ws.onmessage = ev => {
    let m; try { m = JSON.parse(ev.data); } catch { return; }
    switch (m.t) {
      case 'snapshot':
        hostOnline = !!m.hostOnline; viewerCount = m.n || 0;
        $('scene').textContent = m.sceneName || '';
        setAll(m.objs || []);
        setPose(m);
        showGen(m.genState, m.genText);
        break;
      case 'obj': if (m.o) upsert(m.o); break;
      case 'del': remove(m.id); break;
      case 'clear': setAll([]); break;
      case 'scene': $('scene').textContent = m.sceneName || ''; break;
      case 'pose': setPose(m); break;
      case 'gen': showGen(m.genState, m.genText); break;
      case 'host': hostOnline = !!m.hostOnline; if (!hostOnline) showGen('', ''); break;
      case 'viewers': viewerCount = m.n || 0; break;
    }
    setStatus();
  };
}

function showGen(state, text) {
  const busy = state && !['Idle', 'Done', 'Error', 'Cancelled'].includes(state);
  const el = $('gen');
  el.hidden = !busy;
  if (busy) el.textContent = text ? `${label(state)} · ${text}` : label(state);
}
function label(s) {
  return ({ Recording: 'Sta ascoltando', Transcribing: 'Trascrizione', Suggesting: 'Cerca oggetti simili', GeneratingImage: 'Genera l’immagine',
    Preview: 'Anteprima', Generating: 'Genera il modello 3D', Downloading: 'Scarica il modello', Loading: 'Carica il modello' })[s] || s;
}

// ── Ciclo di disegno ─────────────────────────────────────────────────

const clock = new THREE.Clock();
const tmpV = new THREE.Vector3(), tmpQ = new THREE.Quaternion();
function frame() {
  const dt = Math.min(clock.getDelta(), 0.1);
  const k = 1 - Math.exp(-dt * 14);
  for (const e of objects.values()) {
    const t = e.target;
    if (!t) continue;
    e.root.position.lerp(tmpV.fromArray(t.pos), k);
    e.root.quaternion.slerp(tmpQ.fromArray(t.quat), k);
    const grow = e.born ? Math.min(1, (performance.now() - e.born) / 450) : 0;
    const ease = e.born ? 0.6 + 0.4 * (1 - Math.pow(1 - grow, 3)) : 0.6;
    const sTarget = t.scale * (e.born ? ease : 0.6);
    e.root.scale.setScalar(e.root.scale.x + (sTarget - e.root.scale.x) * Math.min(1, k * 1.5));
  }
  if (poseTarget.head) damp(head, poseTarget.head, k);
  if (poseTarget.l) damp(handL, poseTarget.l, k);
  if (poseTarget.r) damp(handR, poseTarget.r, k);

  if (mode === 'follow' && poseTarget.head) {
    // la camera guarda dove guarda il visore (la testa è orientata verso +Z, la camera verso -Z)
    camera.position.copy(head.position);
    camera.quaternion.copy(head.quaternion).multiply(tmpQ.setFromAxisAngle(new THREE.Vector3(0, 1, 0), Math.PI));
    avatar.visible = false;
  } else {
    avatar.visible = !!poseTarget.head && hostOnline;
    controls.update();
  }
  renderer.render(scene, camera);
  requestAnimationFrame(frame);
}

window.__xrViewer = { objects, get hostOnline() { return hostOnline; }, get connected() { return connected; } };   // per i test
setStatus();
connect();
frame();
