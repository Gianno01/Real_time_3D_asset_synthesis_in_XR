// app.js — pannello web della Libreria XR
//
// Parla con lo stesso workflow n8n del visore ("Quest - Libreria") attraverso nginx (/api/library) e carica i file
// direttamente nello storage (/upload/assets/<id>/...). I file si leggono da /assets/... come fanno i visori.

import { loadGlb, GlbViewer, makeThumbnail, isGlb } from './glb.js';

const API = '/api/library';
const CATEGORIES = ['Personaggio', 'Environment', 'Decorazione', 'Props'];   // come in LibraryUI.cs
const DEFAULT_STYLES = ['Realistico', 'Moderno', 'Medievale', 'Rinascimentale', 'Futuristico', 'Fantasy', 'Cartoon', 'Punk'];
const PAGE = 24, SEMANTIC_LIMIT = 60, MAX_FILE_MB = 300;

const $ = id => document.getElementById(id);
const el = (tag, props = {}, ...children) => {
  const e = document.createElement(tag);
  for (const [k, v] of Object.entries(props)) {
    if (k === 'class') e.className = v;
    else if (k === 'dataset') Object.assign(e.dataset, v);
    else if (k.startsWith('on')) e.addEventListener(k.slice(2), v);
    else if (v !== undefined && v !== null && v !== false) e.setAttribute(k, v === true ? '' : v);
  }
  for (const c of children.flat()) if (c !== null && c !== undefined && c !== false) e.append(c instanceof Node ? c : document.createTextNode(String(c)));
  return e;
};
const fileUrl = key => key ? '/' + String(key).replace(/^\/+/, '') : '';
const store = {
  get(k, d) { try { return localStorage.getItem(k) ?? d; } catch { return d; } },
  set(k, v) { try { localStorage.setItem(k, v); } catch { /* archiviazione non disponibile */ } },
};
let author = store.get('xr.author', 'PC');
const knownStyles = new Set(DEFAULT_STYLES);

// ── Utilità ──────────────────────────────────────────────────────────

async function api(action, data = {}) {
  let res;
  try {
    res = await fetch(API, { method: 'POST', headers: { 'Content-Type': 'application/json' }, body: JSON.stringify({ action, author, ...data }) });
  } catch { throw new Error('Server non raggiungibile'); }
  const text = await res.text();
  let json = null;
  try { json = JSON.parse(text); } catch { /* non JSON */ }
  if (!res.ok) {
    if (res.status === 404 && !json) throw new Error('Webhook non trovato: il workflow "Quest - Libreria" è pubblicato?');
    throw new Error(json?.message || json?.error || `Errore HTTP ${res.status}`);
  }
  if (!json) throw new Error('Risposta non valida dal server');
  if (json.ok === false) throw new Error(json.error || 'Operazione non riuscita');
  return json;
}

function uploadFile(key, blob, filename, onProgress) {
  return new Promise((resolve, reject) => {
    const fd = new FormData();
    fd.append('file', blob, filename);
    const x = new XMLHttpRequest();
    x.open('POST', '/upload/' + key);
    x.upload.onprogress = e => { if (e.lengthComputable) onProgress?.(e.loaded / e.total); };
    x.onload = () => (x.status >= 200 && x.status < 300) ? resolve() : reject(new Error(`Caricamento non riuscito (HTTP ${x.status})`));
    x.onerror = () => reject(new Error('Caricamento interrotto: storage non raggiungibile'));
    x.send(fd);
  });
}

function uuid() {
  const b = crypto.getRandomValues(new Uint8Array(16));
  b[6] = (b[6] & 0x0f) | 0x40; b[8] = (b[8] & 0x3f) | 0x80;
  const h = [...b].map(x => x.toString(16).padStart(2, '0')).join('');
  return `${h.slice(0, 8)}-${h.slice(8, 12)}-${h.slice(12, 16)}-${h.slice(16, 20)}-${h.slice(20)}`;
}

function toast(msg, kind = '') {
  const t = el('div', { class: 'toast ' + kind }, msg);
  $('toasts').append(t);
  setTimeout(() => t.remove(), kind === 'bad' ? 7000 : 3500);
}

// "Elimina" → "Conferma?" per 3 s; il secondo clic conferma (nessuna finestra di dialogo)
function confirmClick(btn, text = 'Conferma?') {
  const now = Date.now();
  if (btn.dataset.armed && now < +btn.dataset.armed) {
    delete btn.dataset.armed; btn.classList.remove('armed'); btn.textContent = btn.dataset.label;
    return true;
  }
  btn.dataset.label = btn.dataset.label || btn.textContent;
  btn.dataset.armed = now + 3000; btn.classList.add('armed'); btn.textContent = text;
  setTimeout(() => {
    if (btn.dataset.armed && Date.now() >= +btn.dataset.armed) { delete btn.dataset.armed; btn.classList.remove('armed'); btn.textContent = btn.dataset.label; }
  }, 3100);
  return false;
}

const r0 = v => Math.round(Number(v) || 0);
const fmtDims = (w, h, d) => (w > 0 || h > 0) ? `${r0(w)} × ${r0(d)} cm · H ${r0(h)} cm` : 'misure non disponibili';
const fmtBytes = n => !n ? '—' : n > 1048576 ? `${(n / 1048576).toFixed(1)} MB` : `${Math.max(1, Math.round(n / 1024))} KB`;
const fmtDate = s => { const d = new Date(s); return isNaN(d) ? (s || '—') : d.toLocaleString('it-IT', { day: '2-digit', month: '2-digit', year: '2-digit', hour: '2-digit', minute: '2-digit' }); };
const parseTags = s => [...new Set(String(s || '').split(',').map(t => t.trim()).filter(Boolean))].slice(0, 20);
const niceName = filename => {
  const s = filename.replace(/\.glb$/i, '').replace(/[_\-.]+/g, ' ').replace(/\s+/g, ' ').trim();
  return s ? s[0].toUpperCase() + s.slice(1) : 'Oggetto';
};

function rememberStyles(list) {
  for (const s of list || []) if (s) knownStyles.add(s);
  const dl = $('styleList');
  dl.replaceChildren(...[...knownStyles].sort((a, b) => a.localeCompare(b, 'it')).map(s => el('option', { value: s })));
  const sel = $('fStyle'), cur = sel.value;
  sel.replaceChildren(el('option', { value: '' }, 'Tutti gli stili'), ...[...knownStyles].sort((a, b) => a.localeCompare(b, 'it')).map(s => el('option', { value: s }, s)));
  sel.value = cur;
}

function chipGroup(container, values, getSel, onPick) {
  const render = () => container.replaceChildren(...values.map(v =>
    el('button', { type: 'button', 'aria-pressed': String(getSel() === v), onclick: () => { onPick(getSel() === v ? '' : v); render(); } }, v)));
  render();
  return render;
}

// ── Schede ───────────────────────────────────────────────────────────

const tabs = [...document.querySelectorAll('.tabs button')];
const entered = new Set();
function showTab(name) {
  if (!tabs.some(t => t.dataset.tab === name)) name = 'inventory';
  for (const t of tabs) t.setAttribute('aria-selected', String(t.dataset.tab === name));
  for (const s of document.querySelectorAll('.tab')) s.hidden = s.id !== 'tab-' + name;
  if (location.hash !== '#' + name) history.replaceState(null, '', '#' + name);
  if (name === 'inventory' && (!entered.has(name) || inv.stale)) loadInventory();
  if (name === 'scenes') loadScenes();
  if (name === 'tools' && !entered.has(name)) checkServices();
  entered.add(name);
}
tabs.forEach(t => t.addEventListener('click', () => showTab(t.dataset.tab)));

// ── Inventario ───────────────────────────────────────────────────────

const inv = { q: '', scope: '', category: '', style: '', offset: 0, items: [], total: 0, mode: 'list', stale: false, req: 0 };

$('fCategory').replaceChildren(el('option', { value: '' }, 'Tutte le categorie'), ...CATEGORIES.map(c => el('option', { value: c }, c)));
$('fCategory').addEventListener('change', e => { inv.category = e.target.value; loadInventory(); });
$('fStyle').addEventListener('change', e => { inv.style = e.target.value; loadInventory(); });
$('searchForm').addEventListener('submit', e => { e.preventDefault(); inv.q = $('q').value.trim(); loadInventory(); });
$('q').addEventListener('search', () => { if (!$('q').value) { inv.q = ''; loadInventory(); } });
for (const b of document.querySelectorAll('#scope button')) b.addEventListener('click', () => {
  inv.scope = b.dataset.scope;
  document.querySelectorAll('#scope button').forEach(x => x.setAttribute('aria-pressed', String(x === b)));
  loadInventory();
});
$('more').addEventListener('click', () => loadInventory(false));

async function loadInventory(reset = true) {
  const my = ++inv.req;
  inv.stale = false;
  if (reset) { inv.offset = 0; inv.items = []; }
  const semantic = !!inv.q && !inv.scope;
  $('more').hidden = true;
  $('invCount').textContent = 'Carico…';
  try {
    const r = await api('list_assets', {
      q: inv.q, scope: inv.scope, category: inv.category, style: inv.style,
      offset: semantic ? 0 : inv.offset, limit: semantic ? SEMANTIC_LIMIT : PAGE,
    });
    if (my !== inv.req) return;
    rememberStyles(r.styles);
    inv.mode = r.mode || 'list';
    inv.items = reset ? (r.items || []) : inv.items.concat(r.items || []);
    inv.total = inv.mode === 'semantic' ? inv.items.length : r.total;
    inv.offset = inv.items.length;
    renderGrid();
  } catch (e) {
    if (my !== inv.req) return;
    $('invCount').textContent = '';
    $('grid').replaceChildren();
    $('invEmpty').hidden = false;
    $('invEmpty').textContent = 'Inventario non disponibile: ' + e.message;
  }
}

function renderGrid() {
  const scopeName = inv.scope ? 'oggetti salvati solo nelle scene' : 'oggetti';
  $('invCount').textContent = inv.q ? `${inv.total} risultati per "${inv.q}"` : `${inv.total} ${scopeName}`;
  const badge = $('invMode');
  badge.hidden = !inv.q;
  badge.className = 'badge' + (inv.mode === 'semantic' ? '' : ' text');
  badge.textContent = inv.mode === 'semantic' ? 'ricerca semantica' : 'ricerca per parole';
  badge.title = inv.mode === 'semantic' ? 'Qdrant + bge-m3: trova anche sinonimi e descrizioni'
                                        : 'Qdrant o Ollama non rispondono (oppure modalità "solo nelle scene"): somiglianza delle parole';
  $('grid').replaceChildren(...inv.items.map(tile));
  const empty = inv.items.length === 0;
  $('invEmpty').hidden = !empty;
  $('invEmpty').textContent = inv.q ? 'Nessun oggetto simile.'
    : inv.scope ? 'Nessun oggetto salvato solo nelle scene.'
    : 'L\'inventario è vuoto: carica un modello dalla scheda "Carica" o salvane uno dal visore.';
  $('more').hidden = inv.mode === 'semantic' || inv.items.length >= inv.total;
}

function thumbBox(a, size) {
  const box = el('div', { class: 'thumb' });
  const ph = el('span', { class: 'ph' }, (a.name || '?').slice(0, 1).toUpperCase());
  if (a.thumb_key) {
    const img = el('img', { src: fileUrl(a.thumb_key), alt: '', loading: 'lazy', width: size, height: size });
    img.onerror = () => img.replaceWith(ph);
    box.append(img);
  } else box.append(ph);
  return box;
}

function tile(a) {
  const box = thumbBox(a, 256);
  if (inv.q && a.score) box.append(el('span', { class: 'score' }, `${Math.round(Math.min(1, a.score) * 100)}%`));
  return el('button', { class: 'tile', type: 'button', onclick: () => openAsset(a) }, box,
    el('div', { class: 'info' },
      el('div', { class: 'name', title: a.name }, a.name || 'Oggetto'),
      el('div', { class: 'sub' }, fmtDims(a.width_cm, a.height_cm, a.depth_cm)),
      el('div', { class: 'sub' }, [a.category || 'senza categoria', a.style].filter(Boolean).join(' · '))));
}

// ── Dettaglio oggetto ────────────────────────────────────────────────

const det = { a: null, cat: '', viewer: null, base: null, loadId: 0 };
const renderDetCats = chipGroup($('dCats'), CATEGORIES, () => det.cat, v => { det.cat = v; });

function openAsset(a) {
  det.a = a;
  det.cat = a.category || '';
  det.base = (a.height_cm > 0) ? [a.width_cm, a.height_cm, a.depth_cm] : null;
  $('dTitle').textContent = a.name || 'Oggetto';
  $('dName').value = a.name || '';
  $('dStyle').value = a.style || '';
  $('dDesc').value = a.prompt_it || '';
  $('dTags').value = (a.tags || []).join(', ');
  $('dHeight').value = a.height_cm > 0 ? r0(a.height_cm) : '';
  renderDetCats();
  updateDetDims();
  const sceneOnly = !a.in_inventory;
  $('dSave').textContent = sceneOnly ? 'Aggiungi all\'inventario' : 'Salva modifiche';
  $('dDelete').hidden = sceneOnly;
  $('dDownload').href = fileUrl(a.glb_key);
  $('dDownload').setAttribute('download', (a.name || 'oggetto').replace(/[\\/:*?"<>|]+/g, '_') + '.glb');
  renderMeta(null);
  $('drawer').hidden = $('drawerBg').hidden = false;
  $('dName').focus({ preventScroll: true });
  loadDetailModel(a);
}

function renderMeta(stats) {
  const a = det.a;
  const rows = [
    ['Autore', a.author || '—'], ['Creato', fmtDate(a.created_at)],
    ['Usato nelle scene', `${a.use_count || 0} volte`], ['File', fmtBytes(a.glb_bytes)],
    stats && ['Geometria', `${stats.triangles.toLocaleString('it-IT')} triangoli`],
    a.model && ['Origine', a.model], a.object_name && ['Oggetto (EN)', a.object_name], a.prompt_en && ['Prompt (EN)', a.prompt_en],
    ['Id', a.id],
  ].filter(Boolean);
  $('dMeta').replaceChildren(...rows.flatMap(([k, v]) => [el('dt', {}, k), el('dd', {}, v)]));
}

async function loadDetailModel(a) {
  const my = ++det.loadId;
  const note = $('dNote');
  note.textContent = 'Carico il modello…';
  try {
    if (!det.viewer) det.viewer = new GlbViewer($('dCanvas'));
    det.viewer.clear();
    const res = await fetch(fileUrl(a.glb_key));
    if (!res.ok) throw new Error(`file non trovato nello storage (HTTP ${res.status})`);
    const model = await loadGlb(await res.arrayBuffer());
    if (my !== det.loadId) return;
    if (model.unsupported) note.textContent = `Anteprima non disponibile (${model.unsupported})`;
    else { det.viewer.setModel(model); note.textContent = ''; }
    if (!det.base) {   // misure mai registrate: proporzioni dal file
      const s = model.bounds.size;
      det.base = [s[0] * 100, s[1] * 100, s[2] * 100];
      updateDetDims();
    }
    renderMeta(model.stats);
  } catch (e) {
    if (my === det.loadId) note.textContent = 'Anteprima non disponibile: ' + e.message;
  }
}

function scaledDims(base, h) {
  if (!base || !(h > 0) || !(base[1] > 0)) return null;
  const k = h / base[1];
  return [base[0] * k, h, base[2] * k];
}

function updateDetDims() {
  const d = scaledDims(det.base, Number($('dHeight').value));
  $('dDims').textContent = d ? fmtDims(...d) : (det.a?.height_cm > 0 ? fmtDims(det.a.width_cm, det.a.height_cm, det.a.depth_cm) : 'inserisci l\'altezza reale');
}
$('dHeight').addEventListener('input', updateDetDims);

function closeDrawer() {
  $('drawer').hidden = $('drawerBg').hidden = true;
  det.loadId++;
  det.viewer?.clear();
  det.a = null;
}
$('dClose').addEventListener('click', closeDrawer);
$('drawerBg').addEventListener('click', closeDrawer);
document.addEventListener('keydown', e => { if (e.key === 'Escape' && !$('drawer').hidden) closeDrawer(); });

$('dSave').addEventListener('click', async () => {
  const a = det.a;
  if (!a) return;
  const promote = !a.in_inventory;
  if (promote && !det.cat) { toast('Scegli una categoria', 'bad'); return; }
  const dims = scaledDims(det.base, Number($('dHeight').value));
  const btn = $('dSave');
  btn.disabled = true;
  try {
    const r = await api('save_asset', {   // con asset_id = aggiorna un oggetto esistente
      asset_id: a.id, name: $('dName').value.trim(), category: det.cat, style: $('dStyle').value.trim(),
      prompt_it: $('dDesc').value.trim(), tags: parseTags($('dTags').value),
      width_cm: dims ? dims[0] : 0, height_cm: dims ? dims[1] : 0, depth_cm: dims ? dims[2] : 0,
      ...(promote ? { in_inventory: true } : {}),
    });
    Object.assign(a, r.asset);
    rememberStyles([a.style]);
    toast(promote ? `"${a.name}" aggiunto all'inventario` : `"${a.name}" aggiornato`, 'ok');
    if (promote) { inv.items = inv.items.filter(x => x.id !== a.id); inv.total = Math.max(0, inv.total - 1); closeDrawer(); }
    else { $('dTitle').textContent = a.name; det.base = [a.width_cm, a.height_cm, a.depth_cm]; }
    renderGrid();
  } catch (e) { toast('Non salvato: ' + e.message, 'bad'); }
  finally { btn.disabled = false; }
});

$('dDelete').addEventListener('click', async e => {
  const a = det.a;
  if (!a || !confirmClick(e.currentTarget)) return;
  try {
    await api('delete_asset', { asset_id: a.id });
    toast(`"${a.name}" eliminato dall'inventario`, 'ok');
    inv.items = inv.items.filter(x => x.id !== a.id);
    inv.total = Math.max(0, inv.total - 1);
    closeDrawer();
    renderGrid();
  } catch (err) { toast('Non eliminato: ' + err.message, 'bad'); }
});

// ── Carica ───────────────────────────────────────────────────────────

const queue = [];
let selected = null, upViewer = null;

const drop = $('drop');
$('files').addEventListener('change', e => { addFiles(e.target.files); e.target.value = ''; });
['dragenter', 'dragover'].forEach(t => drop.addEventListener(t, e => { e.preventDefault(); drop.classList.add('over'); }));
['dragleave', 'drop'].forEach(t => drop.addEventListener(t, () => drop.classList.remove('over')));
drop.addEventListener('drop', e => { e.preventDefault(); addFiles(e.dataTransfer.files); });
// file lasciati fuori dalla zona: non aprirli nel browser; nella scheda Carica vanno in coda
window.addEventListener('dragover', e => e.preventDefault());
window.addEventListener('drop', e => {
  e.preventDefault();
  if (!$('tab-upload').hidden && e.target !== drop && !drop.contains(e.target)) addFiles(e.dataTransfer.files);
});

function addFiles(list) {
  let first = null;
  for (const file of list) {
    if (!/\.glb$/i.test(file.name)) { toast(`"${file.name}" ignorato: servono file .glb`, 'bad'); continue; }
    if (file.size > MAX_FILE_MB * 1048576) { toast(`"${file.name}" supera ${MAX_FILE_MB} MB`, 'bad'); continue; }
    const it = { id: uuid(), file, name: niceName(file.name), category: '', style: '', desc: '', tags: '', heightCm: '',
                 size: null, stats: null, model: null, thumb: null, thumbUrl: '', status: 'loading', progress: 0, error: '', note: '' };
    queue.push(it);
    first ??= it;
    analyze(it);
  }
  renderQueue();
  if (first && (!selected || selected.status === 'saved')) select(first);
}

async function analyze(it) {
  try {
    const buf = await it.file.arrayBuffer();
    if (!isGlb(buf)) throw new Error('non è un file glTF binario');
    const model = await loadGlb(buf);
    it.size = model.bounds.size;
    it.stats = model.stats;
    if (model.unsupported) it.note = `Anteprima e miniatura non disponibili (${model.unsupported}): il visore lo caricherà comunque se glTFast lo supporta.`;
    else {
      it.thumb = await makeThumbnail(model, 256);
      if (it.thumb) it.thumbUrl = URL.createObjectURL(it.thumb);
    }
    const hCm = it.size[1] * 100, maxCm = Math.max(...it.size) * 100;
    if (maxCm >= 1 && maxCm <= 3000) it.heightCm = Math.max(1, r0(hCm));
    else it.note = (it.note ? it.note + ' ' : '') + 'Le misure nel file non sembrano in metri: inserisci l\'altezza reale.';
    it.status = 'ready';
    if (selected === it) { it.model = model; showEditor(); } // il modello resta in memoria solo per l'elemento aperto
  } catch (e) {
    it.status = 'error';
    it.error = e.message;
    if (selected === it) showEditor();
  }
  renderQueue();
}

function statusOf(it) {
  switch (it.status) {
    case 'loading': return ['Analisi del file…', ''];
    case 'uploading': return [`Caricamento ${Math.round(it.progress * 100)}%`, ''];
    case 'saved': return ['Salvato nell\'inventario ✓', 'ok'];
    case 'error': return ['Errore: ' + it.error, 'bad'];
    default:
      if (!it.category) return ['Manca la categoria', 'warn'];
      if (!(Number(it.heightCm) > 0)) return ['Manca l\'altezza', 'warn'];
      return ['Pronto', ''];
  }
}

function renderQueue() {
  $('queue').replaceChildren(...queue.map(it => {
    const [txt, cls] = statusOf(it);
    return el('li', { class: it === selected ? 'sel' : '', onclick: () => select(it), title: it.file.name },
      it.thumbUrl ? el('img', { src: it.thumbUrl, alt: '' }) : el('span', { class: 'noimg' }),
      el('div', {}, el('div', { class: 'qn' }, it.name || it.file.name), el('div', { class: 'qs ' + cls }, txt),
        it.status === 'uploading' ? el('progress', { max: 1, value: it.progress }) : null));
  }));
  const pending = queue.filter(i => i.status === 'ready' || i.status === 'error').length;
  $('queueActions').hidden = queue.length === 0;
  $('saveAll').textContent = `Salva tutti (${pending})`;
  $('saveAll').disabled = pending === 0;
  $('clearDone').hidden = !queue.some(i => i.status === 'saved');
}

const renderUpCats = chipGroup($('upCats'), CATEGORIES, () => selected?.category || '', v => {
  if (selected) { selected.category = v; renderQueue(); }
});

async function select(it) {
  if (selected && selected !== it) selected.model = null;
  selected = it;
  renderQueue();
  showEditor();
  if (it.status !== 'error' && it.status !== 'loading' && !it.model && !it.note.startsWith('Anteprima')) {
    try { it.model = await loadGlb(await it.file.arrayBuffer()); if (selected === it) showEditor(); }
    catch (e) { /* l'errore è già stato segnalato dall'analisi */ }
  }
}

function showEditor() {
  const it = selected;
  $('editorEmpty').hidden = !!it;
  $('editorBody').hidden = !it;
  if (!it) { upViewer?.clear(); return; }
  if (!upViewer) {
    try { upViewer = new GlbViewer($('upCanvas')); }
    catch (e) { $('upNote').textContent = e.message; }
  }
  upViewer?.clear();
  if (it.model && !it.model.unsupported) { upViewer?.setModel(it.model); $('upNote').textContent = ''; }
  else $('upNote').textContent = it.status === 'loading' ? 'Analisi del file…' : it.status === 'error' ? it.error : it.note || '';
  $('upName').value = it.name;
  $('upStyle').value = it.style;
  $('upDesc').value = it.desc;
  $('upTags').value = it.tags;
  $('upHeight').value = it.heightCm;
  renderUpCats();
  updateUpDims();
  const s = it.size;
  $('upFileInfo').textContent = [
    it.file.name, fmtBytes(it.file.size),
    it.stats && `${it.stats.triangles.toLocaleString('it-IT')} triangoli`,
    s && `nel file: ${s.map(v => v.toFixed(3)).join(' × ')} (unità del file, di norma metri)`,
    it.note && !it.note.startsWith('Anteprima') ? it.note : null,
  ].filter(Boolean).join(' · ');
  const busy = it.status === 'uploading' || it.status === 'loading';
  $('upSave').disabled = busy || it.status === 'saved';
  $('upSave').textContent = it.status === 'saved' ? 'Salvato ✓' : it.status === 'error' && it.size ? 'Riprova' : 'Salva nell\'inventario';
  $('upRemove').disabled = it.status === 'uploading';
}

function uploadDims(it) {
  const h = Number(it.heightCm);
  if (!it.size || !(h > 0)) return null;
  const hFile = it.size[1] > 1e-9 ? it.size[1] : Math.max(...it.size);
  const k = h / (hFile * 100);
  return [it.size[0] * 100 * k, h, it.size[2] * 100 * k];
}
function updateUpDims() {
  const d = selected && uploadDims(selected);
  $('upDims').textContent = d ? fmtDims(...d) : 'inserisci l\'altezza reale';
}

const bind = (id, key, after) => $(id).addEventListener('input', e => { if (selected) { selected[key] = e.target.value; after?.(); } });
bind('upName', 'name', renderQueue);
bind('upStyle', 'style');
bind('upDesc', 'desc');
bind('upTags', 'tags');
bind('upHeight', 'heightCm', () => { updateUpDims(); renderQueue(); });

$('upRemove').addEventListener('click', () => {
  const it = selected;
  if (!it || it.status === 'uploading') return;
  queue.splice(queue.indexOf(it), 1);
  if (it.thumbUrl) URL.revokeObjectURL(it.thumbUrl);
  selected = null;
  const next = queue.find(i => i.status !== 'saved');
  if (next) select(next); else { renderQueue(); showEditor(); }
});
$('upSave').addEventListener('click', () => selected && saveItem(selected));
$('saveAll').addEventListener('click', async () => {
  const items = queue.filter(i => i.status === 'ready' || (i.status === 'error' && i.size));
  const missing = items.filter(i => !i.category || !(Number(i.heightCm) > 0));
  for (const it of items) if (!missing.includes(it)) await saveItem(it, true);
  if (missing.length) toast(`${missing.length} oggetti senza categoria o altezza: completali e riprova`, 'bad');
});
$('clearDone').addEventListener('click', () => {
  for (let i = queue.length - 1; i >= 0; i--) if (queue[i].status === 'saved') {
    if (queue[i].thumbUrl) URL.revokeObjectURL(queue[i].thumbUrl);
    if (queue[i] === selected) selected = null;
    queue.splice(i, 1);
  }
  renderQueue(); showEditor();
});

async function saveItem(it, quiet = false) {
  if (!it.size) { toast('Il file non è ancora stato analizzato', 'bad'); return; }
  if (!it.category) { toast('Scegli una categoria', 'bad'); return; }
  const dims = uploadDims(it);
  if (!dims) { toast('Inserisci l\'altezza reale in cm', 'bad'); return; }
  const id = it.id, base = `assets/${id}/`;
  it.status = 'uploading'; it.progress = 0; it.error = '';
  renderQueue(); if (selected === it) showEditor();
  const step = (from, to) => p => { it.progress = from + (to - from) * p; renderQueue(); };
  try {
    await uploadFile(base + 'model.glb', new Blob([it.file], { type: 'model/gltf-binary' }), 'model.glb', step(0, it.thumb ? 0.9 : 0.97));
    if (it.thumb) await uploadFile(base + 'thumb.jpg', it.thumb, 'thumb.jpg', step(0.9, 0.97));
    const r = await api('register_asset', {
      id, glb_key: base + 'model.glb', thumb_key: it.thumb ? base + 'thumb.jpg' : '',
      name: it.name.trim() || niceName(it.file.name), category: it.category, style: it.style.trim(),
      prompt_it: it.desc.trim(), tags: parseTags(it.tags), model: 'caricato dal PC',
      width_cm: dims[0], height_cm: dims[1], depth_cm: dims[2], glb_bytes: it.file.size,
    });
    it.status = 'saved'; it.progress = 1; it.model = null;
    rememberStyles([r.asset?.style]);
    inv.stale = true;
    if (!quiet) toast(`"${r.asset?.name || it.name}" salvato nell'inventario`, 'ok');
  } catch (e) {
    it.status = 'error'; it.error = e.message;
    toast(`"${it.name}": ${e.message}`, 'bad');
  }
  renderQueue();
  if (selected === it) showEditor();
}

window.addEventListener('beforeunload', e => {
  if (queue.some(i => i.status === 'uploading')) { e.preventDefault(); e.returnValue = ''; }
});

// ── Scene ────────────────────────────────────────────────────────────

const sc = { list: [], open: null, editing: null };
$('scRefresh').addEventListener('click', loadScenes);

async function loadScenes() {
  $('scCount').textContent = 'Carico…';
  try {
    const r = await api('list_scenes', { limit: 200 });
    sc.list = r.scenes || [];
    renderScenes();
  } catch (e) {
    $('scCount').textContent = 'Scene non disponibili: ' + e.message;
    $('scRows').replaceChildren();
  }
}

function renderScenes() {
  $('scCount').textContent = `${sc.list.length} scene`;
  $('scEmpty').hidden = sc.list.length > 0;
  $('scRows').replaceChildren(...sc.list.map(s => {
    const nameCell = sc.editing === s.id
      ? el('td', {}, el('input', { value: s.name, maxlength: 80, id: 'renameInput',
          onkeydown: e => { if (e.key === 'Enter') commitRename(s); if (e.key === 'Escape') { sc.editing = null; renderScenes(); } } }))
      : el('td', {}, el('b', {}, s.name));
    const del = el('button', { class: 'btn small danger', onclick: e => deleteScene(s, e.currentTarget) }, 'Elimina');
    const acts = sc.editing === s.id
      ? [el('button', { class: 'btn small primary', onclick: () => commitRename(s) }, 'Salva'),
         el('button', { class: 'btn small ghost', onclick: () => { sc.editing = null; renderScenes(); } }, 'Annulla')]
      : [el('button', { class: 'btn small', onclick: () => openScene(s) }, 'Apri'),
         el('button', { class: 'btn small ghost', onclick: () => { sc.editing = s.id; renderScenes(); $('renameInput')?.focus(); } }, 'Rinomina'), del];
    return el('tr', { class: sc.open === s.id ? 'sel' : '' }, nameCell,
      el('td', {}, s.object_count), el('td', {}, s.author || '—'), el('td', {}, fmtDate(s.updated_at)), el('td', { class: 'acts' }, acts));
  }));
}

async function commitRename(s) {
  const name = $('renameInput')?.value.trim();
  if (!name) return;
  try {
    const r = await api('rename_scene', { scene_id: s.id, name });
    s.name = r.name; sc.editing = null;
    renderScenes();
    if (sc.open === s.id) $('scTitle').textContent = s.name;
    toast('Scena rinominata', 'ok');
  } catch (e) { toast('Non rinominata: ' + e.message, 'bad'); }
}

async function deleteScene(s, btn) {
  if (!confirmClick(btn)) return;
  try {
    await api('delete_scene', { scene_id: s.id });
    sc.list = sc.list.filter(x => x.id !== s.id);
    if (sc.open === s.id) { sc.open = null; $('scDetail').hidden = true; }
    renderScenes();
    toast(`Scena "${s.name}" eliminata`, 'ok');
  } catch (e) { toast('Non eliminata: ' + e.message, 'bad'); }
}

async function openScene(s) {
  sc.open = s.id;
  renderScenes();
  $('scDetail').hidden = false;
  $('scTitle').textContent = s.name;
  $('scInfo').textContent = 'Carico…';
  $('scObjects').replaceChildren();
  try {
    const r = await api('load_scene', { scene_id: s.id });
    if (sc.open !== s.id) return;
    const objs = r.objects || [];
    $('scInfo').textContent = `${objs.length} oggetti · ${s.author || 'autore sconosciuto'} · ${fmtDate(s.updated_at)}`;
    drawMap(objs);
    $('scObjects').replaceChildren(...objs.map(o => {
      const img = o.thumb_key ? el('img', { src: fileUrl(o.thumb_key), alt: '', loading: 'lazy' }) : el('span', { class: 'noimg' });
      if (img.tagName === 'IMG') img.onerror = () => img.replaceWith(el('span', { class: 'noimg' }));
      return el('li', {}, img,
        el('div', {}, el('span', { class: 'n' }, o.name), o.in_inventory ? null : el('span', { class: 'tag', title: 'Salvato solo per questa scena' }, 'solo scena'),
          el('div', { class: 'p' }, `x ${o.px.toFixed(2)} · z ${o.pz.toFixed(2)} · h ${o.py.toFixed(2)} m`)),
        el('span', { class: 'p' }, `×${(o.scale || 1).toFixed(2)}`));
    }));
  } catch (e) { $('scInfo').textContent = 'Scena non caricata: ' + e.message; }
}

function drawMap(objs) {
  const c = $('scMap'), dpr = Math.min(window.devicePixelRatio || 1, 2);
  const W = 520, H = 360;
  c.width = W * dpr; c.height = H * dpr;
  const g = c.getContext('2d');
  g.setTransform(dpr, 0, 0, dpr, 0, 0);
  g.clearRect(0, 0, W, H);
  const xs = [0, ...objs.map(o => o.px)], zs = [0, ...objs.map(o => o.pz)];
  let minX = Math.min(...xs) - 1, maxX = Math.max(...xs) + 1, minZ = Math.min(...zs) - 1, maxZ = Math.max(...zs) + 1;
  const scale = Math.min((W - 40) / (maxX - minX), (H - 40) / (maxZ - minZ));
  const cx = (minX + maxX) / 2, cz = (minZ + maxZ) / 2;
  const X = x => W / 2 + (x - cx) * scale, Y = z => H / 2 - (z - cz) * scale;   // z in avanti = verso l'alto

  g.strokeStyle = 'rgba(255,255,255,.06)'; g.lineWidth = 1;
  for (let x = Math.floor(minX - 2); x <= maxX + 2; x++) { g.beginPath(); g.moveTo(X(x), 0); g.lineTo(X(x), H); g.stroke(); }
  for (let z = Math.floor(minZ - 2); z <= maxZ + 2; z++) { g.beginPath(); g.moveTo(0, Y(z)); g.lineTo(W, Y(z)); g.stroke(); }
  g.strokeStyle = '#99a3b5'; g.lineWidth = 1.5;
  g.beginPath(); g.moveTo(X(0) - 7, Y(0)); g.lineTo(X(0) + 7, Y(0)); g.moveTo(X(0), Y(0) - 7); g.lineTo(X(0), Y(0) + 7); g.stroke();
  g.fillStyle = '#99a3b5'; g.font = '11px system-ui, sans-serif'; g.fillText('origine', X(0) + 9, Y(0) + 13);

  g.font = '600 12px system-ui, sans-serif';
  for (const o of objs) {
    const x = X(o.px), y = Y(o.pz);
    g.fillStyle = o.in_inventory ? '#66a3ff' : '#ffc15e';
    g.beginPath(); g.arc(x, y, 6, 0, Math.PI * 2); g.fill();
    // direzione dell'oggetto (rotazione attorno a Y)
    const yaw = Math.atan2(2 * (o.rw * o.ry + o.rx * o.rz), 1 - 2 * (o.ry * o.ry + o.rx * o.rx));
    g.strokeStyle = g.fillStyle; g.lineWidth = 2;
    g.beginPath(); g.moveTo(x, y); g.lineTo(x + Math.sin(yaw) * 14, y - Math.cos(yaw) * 14); g.stroke();
    g.fillStyle = '#f2f4f8';
    g.fillText(o.name.length > 22 ? o.name.slice(0, 21) + '…' : o.name, x + 10, y - 8);
  }
}

// ── Strumenti ────────────────────────────────────────────────────────

$('author').value = author;
$('author').addEventListener('input', e => { author = e.target.value.trim() || 'PC'; store.set('xr.author', author); });
$('checkAll').addEventListener('click', checkServices);

async function checkServices() {
  const rows = [
    ['Storage (file)', async () => { const r = await fetch('/health', { cache: 'no-store' }); if (!r.ok) throw new Error('HTTP ' + r.status); return ['ok', 'raggiungibile']; }],
    ['n8n + Postgres', async () => { const r = await api('list_assets', { limit: 1 }); return ['ok', `${r.total} oggetti nell'inventario`]; }],
    ['Ricerca semantica', async () => {
      const r = await api('list_assets', { q: 'oggetto', limit: 1, min_score: 0.01 });
      return r.mode === 'semantic' ? ['ok', 'attiva (Qdrant + bge-m3)'] : ['warn', 'non disponibile: si usa la ricerca per parole (vedi LEGGIMI → Problemi comuni)'];
    }],
    ['Scene', async () => { const r = await api('list_scenes', { limit: 200 }); return ['ok', `${(r.scenes || []).length} scene salvate`]; }],
  ];
  const ul = $('status');
  ul.replaceChildren(...rows.map(([n]) => el('li', {}, el('i'), el('span', {}, n), el('span', {}, 'controllo…'))));
  const results = await Promise.all(rows.map(async ([, fn], i) => {
    let res;
    try { res = await fn(); } catch (e) { res = ['bad', e.message]; }
    const li = ul.children[i];
    li.className = res[0];
    li.lastChild.textContent = res[1];
    return res[0];
  }));
  setHealth(results.includes('bad') ? 'bad' : results.includes('warn') ? 'warn' : 'ok',
            results.includes('bad') ? 'Problemi sul server' : results.includes('warn') ? 'Ricerca semantica non attiva' : 'Server attivo');
}

function setHealth(kind, text) {
  const h = $('health');
  h.className = 'health ' + kind;
  h.lastElementChild.textContent = text;
}

$('enrich').addEventListener('click', async e => {
  const btn = e.currentTarget, out = $('enrichOut');
  btn.disabled = true;
  let done = 0, remaining = null, failed = [];
  try {
    for (let i = 0; i < 300; i++) {
      out.textContent = remaining === null ? 'Genero le parole chiave…' : `Parole chiave generate: ${done}, ne mancano ${remaining}…`;
      const r = await api('enrich_assets', { limit: 3 });
      done += r.processed; remaining = r.remaining; failed = r.failed || [];
      if (r.remaining === 0) break;
      if (r.processed === 0) { out.textContent = `Non riesco a generare le parole chiave per: ${failed.join(', ') || 'alcuni oggetti'}. Ricostruisco comunque l'indice…`; break; }
    }
    if (remaining === 0 || done > 0) {
      out.textContent += ' Ricostruisco l\'indice…';
      const x = await api('reindex');
      out.textContent = `Fatto: ${done} oggetti arricchiti${remaining ? `, ne restano ${remaining}` : ''}; ${x.indexed} su ${x.total} indicizzati.`;
      toast('Ricerca migliorata', 'ok');
    }
  } catch (err) { out.textContent = 'Non riuscita: ' + err.message; }
  finally { btn.disabled = false; }
});

$('reindex').addEventListener('click', async e => {
  const btn = e.currentTarget, out = $('reindexOut');
  btn.disabled = true;
  out.textContent = 'Reindicizzazione in corso…';
  try {
    const r = await api('reindex');
    out.textContent = `Indicizzati ${r.indexed} oggetti su ${r.total}.`;
    toast('Indice ricostruito', 'ok');
  } catch (err) { out.textContent = 'Non riuscita: ' + err.message; }
  finally { btn.disabled = false; }
});

// ── Avvio ────────────────────────────────────────────────────────────

rememberStyles([]);
showTab(location.hash.slice(1) || 'inventory');
window.addEventListener('hashchange', () => showTab(location.hash.slice(1)));
// stato rapido in alto a destra (il controllo completo è in Strumenti)
api('list_assets', { limit: 1 }).then(() => setHealth('ok', 'Server attivo')).catch(e => setHealth('bad', e.message));
