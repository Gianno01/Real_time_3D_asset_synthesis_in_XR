// import_scene.js
// Scompone una scena .glb (per esempio esportata da Blender) in un file .glb per ogni oggetto, più la posa di ciascuno.
//
// Un "oggetto" è un nodo di primo livello che contiene almeno una mesh (con tutti i suoi figli). Luci, camere e nodi vuoti
// vengono ignorati. Se tutta la scena è dentro un unico nodo contenitore (succede con alcuni esportatori) si scende di un livello.
// Oggetti identici (stessa geometria e stessa scala, tipico di copie/istanze) condividono lo stesso file.
//
// Conversioni verso il visore (Unity è sinistrorso, Z avanti; glTF destrorso):
//   come fa glTFast quando carica un .glb in Unity: si inverte l'asse X
//   posizione (x,y,z) → (-x,y,z)      rotazione (qx,qy,qz,qw) → (qx,-qy,-qz,qw)
// L'origine del file di ogni oggetto resta l'origine dell'oggetto nella scena: nel visore compare esattamente dove era in Blender.

const CHUNK_JSON = 0x4E4F534A, CHUNK_BIN = 0x004E4942;
const UNSUPPORTED = ['KHR_draco_mesh_compression', 'EXT_meshopt_compression', 'KHR_meshopt_compression', 'KHR_texture_basisu'];
const DROP_EXT = ['KHR_lights_punctual', 'KHR_materials_variants'];

// ── Matrici 4×4 (colonne, come glTF) ─────────────────────────────────

const ident = () => [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1];
function mul(a, b) {
  const o = new Array(16).fill(0);
  for (let c = 0; c < 4; c++) for (let r = 0; r < 4; r++) {
    let s = 0;
    for (let k = 0; k < 4; k++) s += a[k * 4 + r] * b[c * 4 + k];
    o[c * 4 + r] = s;
  }
  return o;
}
function trsMatrix(t, q, s) {
  const [x, y, z, w] = q;
  const xx = x * x, yy = y * y, zz = z * z, xy = x * y, xz = x * z, yz = y * z, wx = w * x, wy = w * y, wz = w * z;
  return [
    (1 - 2 * (yy + zz)) * s[0], (2 * (xy + wz)) * s[0], (2 * (xz - wy)) * s[0], 0,
    (2 * (xy - wz)) * s[1], (1 - 2 * (xx + zz)) * s[1], (2 * (yz + wx)) * s[1], 0,
    (2 * (xz + wy)) * s[2], (2 * (yz - wx)) * s[2], (1 - 2 * (xx + yy)) * s[2], 0,
    t[0], t[1], t[2], 1];
}
function localMatrix(n) {
  if (n.matrix && n.matrix.length === 16) return n.matrix.slice();
  return trsMatrix(n.translation || [0, 0, 0], n.rotation || [0, 0, 0, 1], n.scale || [1, 1, 1]);
}
function quatFromRot(m) {   // m: 9 valori (colonne normalizzate)
  const [m00, m10, m20, m01, m11, m21, m02, m12, m22] = m;
  const tr = m00 + m11 + m22;
  let x, y, z, w;
  if (tr > 0) { const s = Math.sqrt(tr + 1) * 2; w = s / 4; x = (m21 - m12) / s; y = (m02 - m20) / s; z = (m10 - m01) / s; }
  else if (m00 > m11 && m00 > m22) { const s = Math.sqrt(1 + m00 - m11 - m22) * 2; w = (m21 - m12) / s; x = s / 4; y = (m01 + m10) / s; z = (m02 + m20) / s; }
  else if (m11 > m22) { const s = Math.sqrt(1 + m11 - m00 - m22) * 2; w = (m02 - m20) / s; x = (m01 + m10) / s; y = s / 4; z = (m12 + m21) / s; }
  else { const s = Math.sqrt(1 + m22 - m00 - m11) * 2; w = (m10 - m01) / s; x = (m02 + m20) / s; y = (m12 + m21) / s; z = s / 4; }
  const l = Math.hypot(x, y, z, w) || 1;
  return [x / l, y / l, z / l, w / l];
}
function decompose(m) {
  let sx = Math.hypot(m[0], m[1], m[2]), sy = Math.hypot(m[4], m[5], m[6]), sz = Math.hypot(m[8], m[9], m[10]);
  const det = m[0] * (m[5] * m[10] - m[6] * m[9]) - m[4] * (m[1] * m[10] - m[2] * m[9]) + m[8] * (m[1] * m[6] - m[2] * m[5]);
  if (det < 0) sx = -sx;
  const ix = sx || 1, iy = sy || 1, iz = sz || 1;
  const q = quatFromRot([m[0] / ix, m[1] / ix, m[2] / ix, m[4] / iy, m[5] / iy, m[6] / iy, m[8] / iz, m[9] / iz, m[10] / iz]);
  return { t: [m[12], m[13], m[14]], q, s: [sx, sy, sz] };
}

// ── Lettura del contenitore GLB ──────────────────────────────────────

function parseGlb(u8) {
  const dv = new DataView(u8.buffer, u8.byteOffset, u8.byteLength);
  if (u8.byteLength < 20 || dv.getUint32(0, true) !== 0x46546C67) throw new Error('Non è un file .glb (glTF binario)');
  let off = 12, json = null, bin = null;
  while (off + 8 <= u8.byteLength) {
    const len = dv.getUint32(off, true), type = dv.getUint32(off + 4, true);
    const data = u8.subarray(off + 8, off + 8 + len);
    if (type === CHUNK_JSON) json = JSON.parse(new TextDecoder().decode(data));
    else if (type === CHUNK_BIN && !bin) bin = data;
    off += 8 + len + ((4 - (len % 4)) % 4);
  }
  if (!json) throw new Error('File .glb senza descrizione JSON');
  const b0 = (json.buffers || [])[0];
  if (b0 && b0.uri) {
    const m = /^data:[^,]*;base64,(.*)$/.exec(b0.uri);
    if (!m) throw new Error('Buffer esterno al file non supportato');
    const raw = atob(m[1]); bin = new Uint8Array(raw.length);
    for (let i = 0; i < raw.length; i++) bin[i] = raw.charCodeAt(i);
  }
  if ((json.buffers || []).length > 1) throw new Error('File con più buffer non supportato');
  for (const e of json.extensionsRequired || []) if (UNSUPPORTED.includes(e)) throw new Error(`Compressione ${e} non supportata: riesporta senza compressione`);
  return { json, bin: bin || new Uint8Array(0) };
}

function writeGlb(gltf, chunks, size) {
  const enc = new TextEncoder().encode(JSON.stringify(gltf));
  const jpad = (4 - (enc.byteLength % 4)) % 4;
  const jsonBytes = new Uint8Array(enc.byteLength + jpad).fill(0x20); jsonBytes.set(enc);
  const total = 12 + 8 + jsonBytes.byteLength + 8 + size;
  const out = new Uint8Array(total), dv = new DataView(out.buffer);
  dv.setUint32(0, 0x46546C67, true); dv.setUint32(4, 2, true); dv.setUint32(8, total, true);
  dv.setUint32(12, jsonBytes.byteLength, true); dv.setUint32(16, CHUNK_JSON, true);
  out.set(jsonBytes, 20);
  let p = 20 + jsonBytes.byteLength;
  dv.setUint32(p, size, true); dv.setUint32(p + 4, CHUNK_BIN, true); p += 8;
  for (const c of chunks) { out.set(c, p); p += c.byteLength; }
  return out;
}

// ── Estrazione di un sottoalbero in un GLB autonomo ──────────────────

/** Copia in un nuovo .glb il nodo `root` con tutti i suoi figli (solo i dati che usa). `bakeScale`: scala da incorporare nel nodo radice. */
function extractSubtree(json, bin, root, bakeScale) {
  const J = json;
  const nodeIdx = new Map(), order = [];
  (function walk(i) {
    if (nodeIdx.has(i)) return;
    nodeIdx.set(i, order.length); order.push(i);
    for (const c of J.nodes[i].children || []) walk(c);
  })(root);

  const g = { nodes: [], meshes: [], materials: [], textures: [], images: [], samplers: [], accessors: [], bufferViews: [], skins: [] };
  const chunks = []; let size = 0;
  const memo = (map, key, make) => { if (!map.has(key)) map.set(key, make()); return map.get(key); };
  const M = { bv: new Map(), acc: new Map(), img: new Map(), smp: new Map(), tex: new Map(), mat: new Map(), mesh: new Map(), skin: new Map() };

  const addBV = bi => memo(M.bv, bi, () => {
    const bv = J.bufferViews[bi];
    const data = bin.subarray(bv.byteOffset || 0, (bv.byteOffset || 0) + bv.byteLength);
    const n = { buffer: 0, byteOffset: size, byteLength: bv.byteLength };
    if (bv.byteStride) n.byteStride = bv.byteStride;
    if (bv.target) n.target = bv.target;
    chunks.push(data);
    const pad = (4 - (data.byteLength % 4)) % 4;
    if (pad) chunks.push(new Uint8Array(pad));
    size += data.byteLength + pad;
    g.bufferViews.push(n); return g.bufferViews.length - 1;
  });
  const addAcc = ai => memo(M.acc, ai, () => {
    const a = { ...J.accessors[ai] };
    if (a.bufferView !== undefined) a.bufferView = addBV(a.bufferView);
    if (a.sparse) a.sparse = { ...a.sparse, indices: { ...a.sparse.indices, bufferView: addBV(a.sparse.indices.bufferView) }, values: { ...a.sparse.values, bufferView: addBV(a.sparse.values.bufferView) } };
    g.accessors.push(a); return g.accessors.length - 1;
  });
  const addImg = ii => memo(M.img, ii, () => {
    const im = { ...J.images[ii] };
    if (im.bufferView !== undefined) im.bufferView = addBV(im.bufferView);
    else if (!(im.uri || '').startsWith('data:')) throw new Error('Texture esterne al file non supportate');
    g.images.push(im); return g.images.length - 1;
  });
  const addSmp = si => memo(M.smp, si, () => { g.samplers.push({ ...J.samplers[si] }); return g.samplers.length - 1; });
  const addTex = ti => memo(M.tex, ti, () => {
    const t = { ...J.textures[ti] };
    if (t.sampler !== undefined) t.sampler = addSmp(t.sampler);
    if (t.source !== undefined) t.source = addImg(t.source);
    g.textures.push(t); return g.textures.length - 1;
  });
  const remapTextures = o => {
    if (!o || typeof o !== 'object') return;
    if (Array.isArray(o)) { o.forEach(remapTextures); return; }
    for (const [k, v] of Object.entries(o)) {
      if (v && typeof v === 'object') {
        if (/texture$/i.test(k) && typeof v.index === 'number') v.index = addTex(v.index);
        remapTextures(v);
      }
    }
  };
  const addMat = mi => memo(M.mat, mi, () => {
    const m = JSON.parse(JSON.stringify(J.materials[mi]));
    remapTextures(m);
    g.materials.push(m); return g.materials.length - 1;
  });
  const addMesh = mi => memo(M.mesh, mi, () => {
    const m = JSON.parse(JSON.stringify(J.meshes[mi]));
    for (const p of m.primitives || []) {
      for (const k of Object.keys(p.attributes || {})) p.attributes[k] = addAcc(p.attributes[k]);
      if (p.indices !== undefined) p.indices = addAcc(p.indices);
      if (p.material !== undefined) p.material = addMat(p.material);
      for (const t of p.targets || []) for (const k of Object.keys(t)) t[k] = addAcc(t[k]);
      delete p.extensions;
    }
    g.meshes.push(m); return g.meshes.length - 1;
  });

  for (const oi of order) {
    const n = JSON.parse(JSON.stringify(J.nodes[oi]));
    delete n.camera; delete n.extensions; delete n.matrix;
    if (n.mesh !== undefined) n.mesh = addMesh(n.mesh);
    if (n.children) n.children = n.children.map(c => nodeIdx.get(c));
    if (n.skin !== undefined) {
      const sk = J.skins[n.skin];
      if (sk.joints.every(j => nodeIdx.has(j))) {
        n.skin = memo(M.skin, n.skin, () => {
          const s = { ...sk, joints: sk.joints.map(j => nodeIdx.get(j)) };
          if (s.skeleton !== undefined) s.skeleton = nodeIdx.has(s.skeleton) ? nodeIdx.get(s.skeleton) : undefined;
          if (s.inverseBindMatrices !== undefined) s.inverseBindMatrices = addAcc(s.inverseBindMatrices);
          g.skins.push(s); return g.skins.length - 1;
        });
      } else delete n.skin;
    }
    if (oi === root) {   // la posa della radice sta nella scena, non nel file
      delete n.translation; delete n.rotation; delete n.scale;
      if (bakeScale) n.scale = bakeScale;
    } else if (J.nodes[oi].matrix) { n.matrix = J.nodes[oi].matrix; }
    g.nodes.push(n);
  }
  // se il nodo radice aveva la matrice, è stata tolta: i figli con matrice la mantengono (rimessa sopra)

  const gltf = { asset: { version: '2.0', generator: 'Libreria XR' }, scene: 0, scenes: [{ nodes: [0] }], nodes: g.nodes, buffers: [{ byteLength: size }] };
  for (const k of ['meshes', 'materials', 'textures', 'images', 'samplers', 'accessors', 'bufferViews', 'skins']) if (g[k].length) gltf[k] = g[k];
  const used = (J.extensionsUsed || []).filter(e => !DROP_EXT.includes(e));
  if (used.length) gltf.extensionsUsed = used;
  return writeGlb(gltf, chunks, size);
}

// ── Scomposizione ────────────────────────────────────────────────────

const r5 = v => Math.round(v * 1e5) / 1e5;

/**
 * @param {Uint8Array} u8 contenuto del file .glb
 * @returns {{assets: Array<{key:string, name:string, glb:Uint8Array, scale:number[]|null, count:number}>,
 *            objects: Array<{assetKey:string, name:string, p:number[], q:number[], s:number}>,   // già nelle coordinate del visore (Unity)
 *            skipped: string[]}}
 */
export function splitScene(u8) {
  const { json, bin } = parseGlb(u8);
  const nodes = json.nodes || [];
  const sceneRoots = (json.scenes && json.scenes[json.scene || 0] && json.scenes[json.scene || 0].nodes) || [];

  const meshMemo = new Map();
  const hasMesh = i => {
    if (meshMemo.has(i)) return meshMemo.get(i);
    meshMemo.set(i, false);   // protezione da cicli
    const n = nodes[i];
    const v = n.mesh !== undefined || (n.children || []).some(hasMesh);
    meshMemo.set(i, v); return v;
  };

  // contenitore unico → si scende, componendo la sua trasformazione
  let level = sceneRoots.slice(), parent = ident();
  while (level.length === 1 && nodes[level[0]].mesh === undefined && (nodes[level[0]].children || []).length) {
    const n = nodes[level[0]];
    if (!(n.children || []).some(hasMesh)) break;
    parent = mul(parent, localMatrix(n));
    level = n.children.slice();
  }

  const assets = new Map(), objects = [], skipped = [];
  for (const ni of level) {
    const n = nodes[ni], name = n.name || `Oggetto ${objects.length + 1}`;
    if (!hasMesh(ni)) { if (n.extensions || n.camera !== undefined) skipped.push(name); continue; }
    const W = decompose(mul(parent, localMatrix(n)));
    const sMin = Math.min(...W.s.map(Math.abs)), sMax = Math.max(...W.s.map(Math.abs));
    const uniform = W.s.every(v => v > 0) && sMax / (sMin || 1) < 1.01 && sMin > 1e-6;
    const sc = uniform ? (W.s[0] + W.s[1] + W.s[2]) / 3 : 1;
    const bake = uniform ? null : W.s.map(r5);

    // chiave: stessa geometria e stessa scala incorporata = stesso file
    const sig = [];
    (function walk(i) {
      const c = nodes[i];
      sig.push([c.mesh ?? -1, (c.translation || c.rotation || c.scale || c.matrix) ? [c.translation, c.rotation, c.scale, c.matrix].map(a => a ? a.map(r5) : 0) : 0, (c.children || []).length]);
      (c.children || []).forEach(walk);
    })(ni);
    const key = JSON.stringify([sig, bake]);

    let a = assets.get(key);
    if (!a) {
      let glb;
      try { glb = extractSubtree(json, bin, ni, bake); } catch (e) { skipped.push(`${name}: ${e.message}`); continue; }
      a = { key, name: name.replace(/\.\d{3}$/, ''), glb, scale: bake, count: 0, unitScale: sc };
      assets.set(key, a);
    }
    a.count++;
    objects.push({
      assetKey: key, name,
      p: [-W.t[0], W.t[1], W.t[2]],
      q: (l => l < 1e-6 ? [0, 0, 0, 1] : [W.q[0] / l, -W.q[1] / l, -W.q[2] / l, W.q[3] / l])(Math.hypot(...W.q)),
      s: sc,
    });
  }
  if (!objects.length) throw new Error('Nessun oggetto con una mesh nella scena');
  return { assets: [...assets.values()], objects, skipped };
}
