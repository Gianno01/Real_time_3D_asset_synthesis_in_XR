// blender_export.js
// Unisce gli oggetti di una scena in UN solo file .glb pronto per Blender (File → Importa → glTF 2.0, oppure trascinalo nella finestra):
// ogni oggetto è al suo posto (posizione, rotazione, scala, raddrizzamento automatico) e le luci sono luci vere (KHR_lights_punctual).
// Blocchi di occlusione e oscuramento NON vengono esportati.
//
// Conversioni: Unity è sinistrorso (Z avanti), glTF destrorso: posizione (x,y,z) → (x,y,-z), rotazione (qx,qy,qz,qw) → (-qx,-qy,qz,qw).
// Blender poi converte da glTF (Y in alto) al suo asse Z in alto. L'origine è l'origine del pavimento (ancora di scena).

const WATT_PER_UNIT = 250;                    // potenza Blender (W) per ogni unità di intensità del visore
const CANDELA_PER_WATT = 683 / (4 * Math.PI); // l'importatore di Blender converte candele → watt con questo fattore
const CHUNK_JSON = 0x4E4F534A, CHUNK_BIN = 0x004E4942;
const UNSUPPORTED = ['KHR_draco_mesh_compression', 'EXT_meshopt_compression', 'KHR_meshopt_compression', 'KHR_texture_basisu'];

const tr = (x, y, z) => [x, y, -z];
const rot = (x, y, z, w) => {
  const q = [-x, -y, z, w], l = Math.hypot(...q);
  return l < 1e-6 ? [0, 0, 0, 1] : q.map(v => v / l);
};

export function kelvinToRgb(kelvin) {
  const t = Math.min(Math.max(kelvin, 1000), 40000) / 100;
  let r, g, b;
  if (t <= 66) {
    r = 255; g = 99.4708025861 * Math.log(t) - 161.1195681661;
    b = t <= 19 ? 0 : 138.5177312231 * Math.log(t - 10) - 305.0447927307;
  } else {
    r = 329.698727446 * Math.pow(t - 60, -0.1332047592);
    g = 288.1221695283 * Math.pow(t - 60, -0.0755148492);
    b = 255;
  }
  const c = v => Math.round(Math.min(Math.max(v / 255, 0), 1) * 1000) / 1000;
  return [c(r), c(g), c(b)];
}

function parseGlb(buf) {
  const dv = new DataView(buf.buffer, buf.byteOffset, buf.byteLength);
  if (buf.byteLength < 20 || dv.getUint32(0, true) !== 0x46546C67) throw new Error('non è un file GLB');
  let off = 12, json = null, bin = null;
  while (off + 8 <= buf.byteLength) {
    const len = dv.getUint32(off, true), type = dv.getUint32(off + 4, true);
    const data = buf.subarray(off + 8, off + 8 + len);
    if (type === CHUNK_JSON) json = JSON.parse(new TextDecoder().decode(data));
    else if (type === CHUNK_BIN && !bin) bin = data;
    off += 8 + len + ((4 - (len % 4)) % 4);
  }
  if (!json) throw new Error('GLB senza JSON');
  const b0 = (json.buffers || [])[0];
  if (b0 && b0.uri) {   // buffer incorporato come data URI
    const m = /^data:[^,]*;base64,(.*)$/.exec(b0.uri);
    if (!m) throw new Error('buffer esterno non supportato');
    const bin64 = atob(m[1]); bin = new Uint8Array(bin64.length);
    for (let i = 0; i < bin64.length; i++) bin[i] = bin64.charCodeAt(i);
  }
  if ((json.buffers || []).length > 1) throw new Error('più buffer non supportati');
  for (const e of json.extensionsRequired || []) if (UNSUPPORTED.includes(e)) throw new Error(`compressione ${e} non supportata`);
  return { json, bin: bin || new Uint8Array(0) };
}

// Somma `base` agli indici di texture dentro un materiale (baseColorTexture, normalTexture, estensioni…)
function offsetTextures(obj, base, parentKey = '') {
  if (!obj || typeof obj !== 'object') return;
  if (Array.isArray(obj)) { obj.forEach(v => offsetTextures(v, base, parentKey)); return; }
  for (const [k, v] of Object.entries(obj)) {
    if (v && typeof v === 'object') {
      if (/texture$/i.test(k) && typeof v.index === 'number') v.index += base;
      offsetTextures(v, base, k);
    }
  }
}

class Builder {
  constructor() {
    this.parts = []; this.size = 0;
    this.g = { bufferViews: [], accessors: [], images: [], samplers: [], textures: [], materials: [], meshes: [], nodes: [], skins: [] };
    this.used = new Set();
  }
  addBin(bin) {
    const off = this.size;
    this.parts.push(bin);
    const pad = (4 - (bin.byteLength % 4)) % 4;
    if (pad) this.parts.push(new Uint8Array(pad));
    this.size += bin.byteLength + pad;
    return off;
  }
  // Aggiunge i dati di un GLB (senza i nodi): restituisce il "modello" da istanziare
  addAsset(src) {
    const { json: j, bin } = parseGlb(src);
    const g = this.g;
    const bo = this.addBin(bin);
    const base = { bv: g.bufferViews.length, acc: g.accessors.length, img: g.images.length, smp: g.samplers.length, tex: g.textures.length, mat: g.materials.length, mesh: g.meshes.length };

    for (const bv of j.bufferViews || []) g.bufferViews.push({ ...bv, buffer: 0, byteOffset: (bv.byteOffset || 0) + bo });
    for (const a0 of j.accessors || []) {
      const a = { ...a0 };
      if (a.bufferView !== undefined) a.bufferView += base.bv;
      if (a.sparse) a.sparse = { ...a.sparse, indices: { ...a.sparse.indices, bufferView: a.sparse.indices.bufferView + base.bv }, values: { ...a.sparse.values, bufferView: a.sparse.values.bufferView + base.bv } };
      g.accessors.push(a);
    }
    for (const im of j.images || []) { const i = { ...im }; if (i.bufferView !== undefined) i.bufferView += base.bv; g.images.push(i); }
    for (const s of j.samplers || []) g.samplers.push({ ...s });
    for (const t of j.textures || []) {
      const x = { ...t };
      if (x.sampler !== undefined) x.sampler += base.smp;
      if (x.source !== undefined) x.source += base.img;
      g.textures.push(x);
    }
    for (const m of j.materials || []) { const c = JSON.parse(JSON.stringify(m)); offsetTextures(c, base.tex); g.materials.push(c); }
    for (const me of j.meshes || []) {
      const c = JSON.parse(JSON.stringify(me));
      for (const p of c.primitives || []) {
        for (const k of Object.keys(p.attributes || {})) p.attributes[k] += base.acc;
        if (p.indices !== undefined) p.indices += base.acc;
        if (p.material !== undefined) p.material += base.mat;
        for (const t of p.targets || []) for (const k of Object.keys(t)) t[k] += base.acc;
      }
      g.meshes.push(c);
    }
    for (const e of j.extensionsUsed || []) this.used.add(e);

    const si = j.scene || 0;
    const roots = (j.scenes && j.scenes[si] && j.scenes[si].nodes) || [];
    return { nodes: j.nodes || [], skins: j.skins || [], roots, meshBase: base.mesh, accBase: base.acc };
  }
  // Copia i nodi di un modello nel file: restituisce gli indici delle radici
  instantiate(a) {
    const g = this.g, nb = g.nodes.length, sb = g.skins.length;
    for (const n0 of a.nodes) {
      const n = { ...n0 };
      delete n.camera; delete n.extensions;
      if (n.mesh !== undefined) n.mesh += a.meshBase;
      if (n.skin !== undefined) n.skin += sb;
      if (n.children) n.children = n.children.map(c => c + nb);
      g.nodes.push(n);
    }
    for (const s0 of a.skins) {
      const s = { ...s0, joints: s0.joints.map(x => x + nb) };
      if (s.skeleton !== undefined) s.skeleton += nb;
      if (s.inverseBindMatrices !== undefined) s.inverseBindMatrices += a.accBase;
      g.skins.push(s);
    }
    return a.roots.map(r => r + nb);
  }
  addNode(n) { this.g.nodes.push(n); return this.g.nodes.length - 1; }
}

/**
 * @param {object} scene    { name, extras }  (extras = JSON stringa con luci e raddrizzamenti)
 * @param {Array}  objects  record della scena (glb_key, px..rw, scale, name, asset_id)
 * @param {(key:string)=>Promise<Uint8Array>} fetchGlb
 * @param {(msg:string)=>void} [progress]
 * @returns {Promise<{blob:Blob, warnings:string[], objects:number, lights:number}>}
 */
export async function buildSceneGlb(scene, objects, fetchGlb, progress = () => {}) {
  let extras = {};
  try { extras = scene.extras ? JSON.parse(scene.extras) : {}; } catch { extras = {}; }
  const aligns = extras.align || [];
  const warnings = [];
  const b = new Builder();
  const assets = new Map();   // glb_key → modello già aggiunto
  const sceneNodes = [];
  let done = 0, missing = 0;

  for (let i = 0; i < objects.length; i++) {
    const o = objects[i], name = o.name || o.object_name || 'Oggetto';
    progress(`Scarico gli oggetti (${i + 1}/${objects.length})…`);
    try {
      if (!o.glb_key) throw new Error('nessun file');
      if (!assets.has(o.glb_key)) assets.set(o.glb_key, b.addAsset(await fetchGlb(o.glb_key)));
      const roots = b.instantiate(assets.get(o.glb_key));

      const al = aligns[i] && aligns[i].asset_id === o.asset_id && aligns[i].al && aligns[i].al.length >= 7 ? aligns[i].al : null;
      if (!aligns[i] || aligns[i].asset_id !== o.asset_id) missing++;
      const holder = b.addNode({ name: name + '_modello', children: roots, ...(al ? { translation: tr(-al[0], -al[1], -al[2]) } : {}) });
      const pivot = b.addNode({ name: name + '_allineamento', children: [holder], ...(al ? { translation: tr(al[0], al[1], al[2]), rotation: rot(al[3], al[4], al[5], al[6]) } : {}) });
      const s = o.scale > 0 ? o.scale : 1;
      const q = (o.rx || o.ry || o.rz || o.rw) ? rot(o.rx, o.ry, o.rz, o.rw) : [0, 0, 0, 1];
      sceneNodes.push(b.addNode({ name, children: [pivot], translation: tr(o.px, o.py, o.pz), rotation: q, scale: [s, s, s] }));
      done++;
    } catch (e) { warnings.push(`${name}: ${e.message}`); }
  }
  if (missing) warnings.push(`${missing} oggetti senza dati di raddrizzamento (scena salvata con una versione precedente del visore): risalva la scena dal visore per avere le rotazioni esatte.`);

  // luci
  const lights = [];
  (extras.lights || []).forEach((d, i) => {
    const spot = d.kind === 1;
    const L = { name: `Luce ${i + 1}`, type: spot ? 'spot' : 'point', color: kelvinToRgb(d.kelvin || 3200), intensity: Math.max(d.intensity ?? 1.5, 0) * WATT_PER_UNIT * CANDELA_PER_WATT };
    if (spot) { const outer = Math.min(Math.max((d.angle || 60) / 2, 1), 89) * Math.PI / 180; L.spot = { innerConeAngle: outer * 0.7, outerConeAngle: outer }; }
    lights.push(L);
    const qr = d.rw === undefined ? [0, 0, 0, 1] : rot(d.rx || 0, d.ry || 0, d.rz || 0, d.rw);
    sceneNodes.push(b.addNode({ name: L.name, translation: tr(d.px, d.py, d.pz), rotation: qr, extensions: { KHR_lights_punctual: { light: lights.length - 1 } } }));
  });
  if (lights.length) b.used.add('KHR_lights_punctual');

  if (!done && !lights.length) throw new Error('nessun oggetto esportabile' + (warnings.length ? ': ' + warnings[0] : ''));

  const g = b.g;
  const gltf = { asset: { version: '2.0', generator: 'Libreria XR' }, scene: 0, scenes: [{ name: scene.name || 'Scena XR', nodes: sceneNodes }], nodes: g.nodes, buffers: [{ byteLength: b.size }] };
  for (const k of ['bufferViews', 'accessors', 'images', 'samplers', 'textures', 'materials', 'meshes', 'skins']) if (g[k].length) gltf[k] = g[k];
  if (lights.length) gltf.extensions = { KHR_lights_punctual: { lights } };
  if (b.used.size) gltf.extensionsUsed = [...b.used];

  progress('Creo il file…');
  const enc = new TextEncoder().encode(JSON.stringify(gltf));
  const jpad = (4 - (enc.byteLength % 4)) % 4;
  const jsonBytes = new Uint8Array(enc.byteLength + jpad).fill(0x20); jsonBytes.set(enc);
  const total = 12 + 8 + jsonBytes.byteLength + 8 + b.size;
  const head = new DataView(new ArrayBuffer(20));
  head.setUint32(0, 0x46546C67, true); head.setUint32(4, 2, true); head.setUint32(8, total, true);
  head.setUint32(12, jsonBytes.byteLength, true); head.setUint32(16, CHUNK_JSON, true);
  const binHead = new DataView(new ArrayBuffer(8));
  binHead.setUint32(0, b.size, true); binHead.setUint32(4, CHUNK_BIN, true);
  const blob = new Blob([head, jsonBytes, binHead, ...b.parts], { type: 'model/gltf-binary' });
  return { blob, warnings, objects: done, lights: lights.length };
}
