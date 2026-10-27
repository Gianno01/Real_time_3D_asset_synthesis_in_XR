// glb.js — lettura dei file .glb e piccolo visualizzatore WebGL2, senza librerie esterne
// (il pannello funziona anche su una rete di laboratorio senza internet).
//
//   const model = await loadGlb(arrayBuffer)   → { prims, bounds: {min, max, size, center}, unsupported, stats }
//   const v = new GlbViewer(canvas); v.setModel(model);
//   const blob = await makeThumbnail(model, 256);
//
// Supporta: mesh a triangoli, nodi con trasformazioni, colore base, texture base (PNG/JPG nel file), colori dei vertici.
// Non supporta (anteprima disattivata, misure comunque calcolate): compressione Draco / Meshopt, texture KTX2.

const COMP = { SCALAR: 1, VEC2: 2, VEC3: 3, VEC4: 4, MAT2: 4, MAT3: 9, MAT4: 16 };
const CSIZE = { 5120: 1, 5121: 1, 5122: 2, 5123: 2, 5125: 4, 5126: 4 };
const COMPRESSED = ['KHR_draco_mesh_compression', 'EXT_meshopt_compression', 'KHR_meshopt_compression', 'KHR_texture_basisu'];

// ── Matrici 4×4 (colonne) ────────────────────────────────────────────

const M = {
  identity: () => new Float32Array([1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1]),
  mul(a, b) {
    const o = new Float32Array(16);
    for (let c = 0; c < 4; c++) for (let r = 0; r < 4; r++) {
      let s = 0;
      for (let k = 0; k < 4; k++) s += a[k * 4 + r] * b[c * 4 + k];
      o[c * 4 + r] = s;
    }
    return o;
  },
  trs(t = [0, 0, 0], q = [0, 0, 0, 1], s = [1, 1, 1]) {
    const [x, y, z, w] = q;
    const xx = x * x, yy = y * y, zz = z * z, xy = x * y, xz = x * z, yz = y * z, wx = w * x, wy = w * y, wz = w * z;
    return new Float32Array([
      (1 - 2 * (yy + zz)) * s[0], (2 * (xy + wz)) * s[0], (2 * (xz - wy)) * s[0], 0,
      (2 * (xy - wz)) * s[1], (1 - 2 * (xx + zz)) * s[1], (2 * (yz + wx)) * s[1], 0,
      (2 * (xz + wy)) * s[2], (2 * (yz - wx)) * s[2], (1 - 2 * (xx + yy)) * s[2], 0,
      t[0], t[1], t[2], 1]);
  },
  // matrice delle normali (inversa trasposta della parte 3×3)
  normal(m) {
    const a = m[0], b = m[4], c = m[8], d = m[1], e = m[5], f = m[9], g = m[2], h = m[6], i = m[10];
    const A = e * i - f * h, B = -(d * i - f * g), C = d * h - e * g;
    const det = a * A + b * B + c * C || 1;
    return new Float32Array([
      A / det, B / det, C / det,
      -(b * i - c * h) / det, (a * i - c * g) / det, -(a * h - b * g) / det,
      (b * f - c * e) / det, -(a * f - c * d) / det, (a * e - b * d) / det]);
  },
  perspective(fovy, aspect, near, far) {
    const f = 1 / Math.tan(fovy / 2), nf = 1 / (near - far);
    return new Float32Array([f / aspect, 0, 0, 0, 0, f, 0, 0, 0, 0, (far + near) * nf, -1, 0, 0, 2 * far * near * nf, 0]);
  },
  lookAt(eye, at, up) {
    let zx = eye[0] - at[0], zy = eye[1] - at[1], zz = eye[2] - at[2];
    let l = Math.hypot(zx, zy, zz) || 1; zx /= l; zy /= l; zz /= l;
    let xx = up[1] * zz - up[2] * zy, xy = up[2] * zx - up[0] * zz, xz = up[0] * zy - up[1] * zx;
    l = Math.hypot(xx, xy, xz) || 1; xx /= l; xy /= l; xz /= l;
    const yx = zy * xz - zz * xy, yy = zz * xx - zx * xz, yz = zx * xy - zy * xx;
    return new Float32Array([xx, yx, zx, 0, xy, yy, zy, 0, xz, yz, zz, 0,
      -(xx * eye[0] + xy * eye[1] + xz * eye[2]), -(yx * eye[0] + yy * eye[1] + yz * eye[2]), -(zx * eye[0] + zy * eye[1] + zz * eye[2]), 1]);
  },
};

// ── Lettura del file ─────────────────────────────────────────────────

export function isGlb(buf) {
  return buf.byteLength >= 20 && new DataView(buf).getUint32(0, true) === 0x46546C67;
}

function parseContainer(buf) {
  const dv = new DataView(buf);
  if (!isGlb(buf)) throw new Error('Non è un file .glb (glTF binario)');
  if (dv.getUint32(4, true) !== 2) throw new Error('Versione glTF non supportata (serve la 2.0)');
  let off = 12, json = null, bin = null;
  while (off + 8 <= buf.byteLength) {
    const len = dv.getUint32(off, true), type = dv.getUint32(off + 4, true);
    const data = new Uint8Array(buf, off + 8, len);
    if (type === 0x4E4F534A) json = JSON.parse(new TextDecoder().decode(data));
    else if (type === 0x004E4942) bin = data;
    off += 8 + len;
  }
  if (!json) throw new Error('File .glb senza descrizione JSON');
  return { json, bin };
}

function dataUriBytes(uri) {
  const comma = uri.indexOf(',');
  const raw = atob(uri.slice(comma + 1));
  const out = new Uint8Array(raw.length);
  for (let i = 0; i < raw.length; i++) out[i] = raw.charCodeAt(i);
  return out;
}

/** Legge un .glb e prepara i dati per il visualizzatore (vertici già trasformati nello spazio del modello). */
export async function loadGlb(buf) {
  const { json, bin } = parseContainer(buf);
  const buffers = (json.buffers || []).map((b, i) =>
    b.uri ? (b.uri.startsWith('data:') ? dataUriBytes(b.uri) : null) : (i === 0 ? bin : null));
  const required = json.extensionsRequired || [];
  const unsupported = required.find(e => COMPRESSED.includes(e)) || null;

  const viewBytes = (bvIndex) => {
    const bv = json.bufferViews[bvIndex];
    const b = buffers[bv.buffer];
    if (!b) throw new Error('Dati esterni al file non supportati');
    return { bytes: b, offset: bv.byteOffset || 0, length: bv.byteLength, stride: bv.byteStride || 0 };
  };

  function readAccessor(index, asInt = false) {
    const a = json.accessors[index];
    const n = COMP[a.type], count = a.count;
    const out = asInt ? new Uint32Array(count * n) : new Float32Array(count * n);
    if (a.bufferView === undefined) return { data: out, n, count };
    const v = viewBytes(a.bufferView);
    const csize = CSIZE[a.componentType];
    const stride = v.stride || csize * n;
    const base = v.offset + (a.byteOffset || 0);
    const dv = new DataView(v.bytes.buffer, v.bytes.byteOffset, v.bytes.byteLength);
    const norm = !!a.normalized && !asInt;
    const read = {
      5120: o => norm ? Math.max(dv.getInt8(o) / 127, -1) : dv.getInt8(o),
      5121: o => norm ? dv.getUint8(o) / 255 : dv.getUint8(o),
      5122: o => norm ? Math.max(dv.getInt16(o, true) / 32767, -1) : dv.getInt16(o, true),
      5123: o => norm ? dv.getUint16(o, true) / 65535 : dv.getUint16(o, true),
      5125: o => dv.getUint32(o, true),
      5126: o => dv.getFloat32(o, true),
    }[a.componentType];
    for (let i = 0; i < count; i++) {
      const o = base + i * stride;
      for (let k = 0; k < n; k++) out[i * n + k] = read(o + k * csize);
    }
    return { data: out, n, count };
  }

  // immagini (texture del colore base)
  const imageCache = new Map();
  async function image(index) {
    if (imageCache.has(index)) return imageCache.get(index);
    const p = (async () => {
      const im = json.images?.[index];
      if (!im) return null;
      let bytes, type = im.mimeType || 'image/png';
      if (im.bufferView !== undefined) {
        const v = viewBytes(im.bufferView);
        bytes = new Uint8Array(v.bytes.buffer, v.bytes.byteOffset + v.offset, v.length);
      } else if (im.uri?.startsWith('data:')) {
        bytes = dataUriBytes(im.uri);
        type = im.uri.slice(5, im.uri.indexOf(';')) || type;
      } else return null;
      if (!/png|jpe?g|webp/.test(type)) return null;
      try {
        return await createImageBitmap(new Blob([bytes], { type }), { imageOrientation: 'none', premultiplyAlpha: 'none', colorSpaceConversion: 'none' });
      } catch { return null; }
    })();
    imageCache.set(index, p);
    return p;
  }

  const min = [Infinity, Infinity, Infinity], max = [-Infinity, -Infinity, -Infinity];
  const grow = (x, y, z) => {
    if (x < min[0]) min[0] = x; if (y < min[1]) min[1] = y; if (z < min[2]) min[2] = z;
    if (x > max[0]) max[0] = x; if (y > max[1]) max[1] = y; if (z > max[2]) max[2] = z;
  };
  const prims = [];
  let triangles = 0, vertices = 0;

  async function addMesh(meshIndex, world) {
    const mesh = json.meshes[meshIndex];
    const nm = M.normal(world);
    for (const p of mesh.primitives) {
      const posIndex = p.attributes?.POSITION;
      if (posIndex === undefined) continue;
      const mode = p.mode ?? 4;
      const compressed = p.extensions && Object.keys(p.extensions).some(e => COMPRESSED.includes(e));

      if (compressed || unsupported) {
        // vertici non leggibili: le misure arrivano dai min/max dell'accessor
        const a = json.accessors[posIndex];
        if (a.min && a.max) for (let c = 0; c < 8; c++) {
          const x = c & 1 ? a.max[0] : a.min[0], y = c & 2 ? a.max[1] : a.min[1], z = c & 4 ? a.max[2] : a.min[2];
          grow(world[0] * x + world[4] * y + world[8] * z + world[12],
               world[1] * x + world[5] * y + world[9] * z + world[13],
               world[2] * x + world[6] * y + world[10] * z + world[14]);
        }
        continue;
      }

      const pos = readAccessor(posIndex).data;
      const count = pos.length / 3;
      for (let i = 0; i < count; i++) {
        const x = pos[i * 3], y = pos[i * 3 + 1], z = pos[i * 3 + 2];
        pos[i * 3]     = world[0] * x + world[4] * y + world[8] * z + world[12];
        pos[i * 3 + 1] = world[1] * x + world[5] * y + world[9] * z + world[13];
        pos[i * 3 + 2] = world[2] * x + world[6] * y + world[10] * z + world[14];
        grow(pos[i * 3], pos[i * 3 + 1], pos[i * 3 + 2]);
      }
      if (mode !== 4) continue;   // punti / linee: solo misure

      let idx = p.indices !== undefined ? readAccessor(p.indices, true).data : null;
      if (!idx) { idx = new Uint32Array(count); for (let i = 0; i < count; i++) idx[i] = i; }

      let nrm;
      if (p.attributes.NORMAL !== undefined) {
        nrm = readAccessor(p.attributes.NORMAL).data;
        for (let i = 0; i < count; i++) {
          const x = nrm[i * 3], y = nrm[i * 3 + 1], z = nrm[i * 3 + 2];
          const nx = nm[0] * x + nm[3] * y + nm[6] * z, ny = nm[1] * x + nm[4] * y + nm[7] * z, nz = nm[2] * x + nm[5] * y + nm[8] * z;
          const l = Math.hypot(nx, ny, nz) || 1;
          nrm[i * 3] = nx / l; nrm[i * 3 + 1] = ny / l; nrm[i * 3 + 2] = nz / l;
        }
      } else nrm = computeNormals(pos, idx);

      const uv = p.attributes.TEXCOORD_0 !== undefined ? readAccessor(p.attributes.TEXCOORD_0).data : null;
      let col = null;
      if (p.attributes.COLOR_0 !== undefined) {
        const c = readAccessor(p.attributes.COLOR_0);
        col = new Float32Array(count * 4);
        for (let i = 0; i < count; i++) {
          col[i * 4] = c.data[i * c.n]; col[i * 4 + 1] = c.data[i * c.n + 1]; col[i * 4 + 2] = c.data[i * c.n + 2];
          col[i * 4 + 3] = c.n === 4 ? c.data[i * 4 + 3] : 1;
        }
      }

      const mat = json.materials?.[p.material] || {};
      const pbr = mat.pbrMetallicRoughness || {};
      const sg = mat.extensions?.KHR_materials_pbrSpecularGlossiness;
      const color = pbr.baseColorFactor || sg?.diffuseFactor || [1, 1, 1, 1];
      const texInfo = pbr.baseColorTexture || sg?.diffuseTexture;
      let img = null, sampler = null;
      if (texInfo && uv) {
        const tex = json.textures?.[texInfo.index];
        if (tex && tex.source !== undefined) img = await image(tex.source);
        if (tex && tex.sampler !== undefined) sampler = json.samplers?.[tex.sampler] || null;
      }
      prims.push({ pos, nrm, uv, col, idx, color, img, sampler,
                   alphaCutoff: mat.alphaMode === 'MASK' ? (mat.alphaCutoff ?? 0.5) : -1 });
      triangles += idx.length / 3;
      vertices += count;
    }
  }

  async function visit(nodeIndex, parent, depth) {
    if (depth > 64) return;
    const n = json.nodes[nodeIndex];
    const local = n.matrix ? new Float32Array(n.matrix) : M.trs(n.translation, n.rotation, n.scale);
    const world = M.mul(parent, local);
    if (n.mesh !== undefined) await addMesh(n.mesh, world);
    for (const c of n.children || []) await visit(c, world, depth + 1);
  }

  const scene = json.scenes?.[json.scene ?? 0];
  if (scene) for (const r of scene.nodes || []) await visit(r, M.identity(), 0);
  else if (json.meshes) for (let i = 0; i < json.meshes.length; i++) await addMesh(i, M.identity());

  if (!isFinite(min[0])) throw new Error('Il file non contiene geometria');
  const size = [max[0] - min[0], max[1] - min[1], max[2] - min[2]];
  const center = [(min[0] + max[0]) / 2, (min[1] + max[1]) / 2, (min[2] + max[2]) / 2];
  return {
    prims, unsupported, bounds: { min, max, size, center },
    stats: { triangles, vertices, textures: [...imageCache.keys()].length, generator: json.asset?.generator || '' },
  };
}

function computeNormals(pos, idx) {
  const n = new Float32Array(pos.length);
  for (let t = 0; t < idx.length; t += 3) {
    const a = idx[t] * 3, b = idx[t + 1] * 3, c = idx[t + 2] * 3;
    const ux = pos[b] - pos[a], uy = pos[b + 1] - pos[a + 1], uz = pos[b + 2] - pos[a + 2];
    const vx = pos[c] - pos[a], vy = pos[c + 1] - pos[a + 1], vz = pos[c + 2] - pos[a + 2];
    const nx = uy * vz - uz * vy, ny = uz * vx - ux * vz, nz = ux * vy - uy * vx;
    for (const i of [a, b, c]) { n[i] += nx; n[i + 1] += ny; n[i + 2] += nz; }
  }
  for (let i = 0; i < n.length; i += 3) {
    const l = Math.hypot(n[i], n[i + 1], n[i + 2]) || 1;
    n[i] /= l; n[i + 1] /= l; n[i + 2] /= l;
  }
  return n;
}

// ── Visualizzatore ───────────────────────────────────────────────────

const VS = `#version 300 es
layout(location=0) in vec3 aPos; layout(location=1) in vec3 aNrm; layout(location=2) in vec2 aUv; layout(location=3) in vec4 aCol;
uniform mat4 uVP; out vec3 vN; out vec2 vUv; out vec4 vCol;
void main() { vN = aNrm; vUv = aUv; vCol = aCol; gl_Position = uVP * vec4(aPos, 1.0); }`;
const FS = `#version 300 es
precision highp float;
in vec3 vN; in vec2 vUv; in vec4 vCol;
uniform vec4 uColor; uniform sampler2D uTex; uniform bool uHasTex; uniform float uCutoff; uniform vec3 uL1; uniform vec3 uL2;
out vec4 o;
void main() {
  vec4 base = uColor * vCol;
  if (uHasTex) base *= texture(uTex, vUv);
  if (uCutoff >= 0.0 && base.a < uCutoff) discard;
  vec3 n = normalize(vN); if (!gl_FrontFacing) n = -n;
  float l = 0.42 + 0.62 * max(dot(n, uL1), 0.0) + 0.22 * max(dot(n, uL2), 0.0) + 0.08 * max(n.y, 0.0);
  o = vec4(base.rgb * l, 1.0);
}`;

export class GlbViewer {
  constructor(canvas, { preserve = false, background = [0.106, 0.118, 0.153] } = {}) {
    this.canvas = canvas;
    this.bg = background;
    const gl = canvas.getContext('webgl2', { antialias: true, preserveDrawingBuffer: preserve });
    if (!gl) throw new Error('WebGL2 non disponibile in questo browser');
    this.gl = gl;
    this.prog = this._program(VS, FS);
    this.u = {};
    for (const n of ['uVP', 'uColor', 'uTex', 'uHasTex', 'uCutoff', 'uL1', 'uL2']) this.u[n] = gl.getUniformLocation(this.prog, n);
    this.draws = [];
    this.textures = new Map();
    this.yaw = 0.6; this.pitch = 0.32; this.zoom = 1;
    this.center = [0, 0, 0]; this.radius = 1;
    this._dirty = true;
    this._bindInput();
    this._loop = () => { if (this._dirty) { this._dirty = false; this.render(); } this._raf = requestAnimationFrame(this._loop); };
    if (!preserve) this._raf = requestAnimationFrame(this._loop);
  }

  _program(vs, fs) {
    const gl = this.gl;
    const sh = (type, src) => {
      const s = gl.createShader(type); gl.shaderSource(s, src); gl.compileShader(s);
      if (!gl.getShaderParameter(s, gl.COMPILE_STATUS)) throw new Error(gl.getShaderInfoLog(s));
      return s;
    };
    const p = gl.createProgram();
    gl.attachShader(p, sh(gl.VERTEX_SHADER, vs)); gl.attachShader(p, sh(gl.FRAGMENT_SHADER, fs));
    gl.linkProgram(p);
    if (!gl.getProgramParameter(p, gl.LINK_STATUS)) throw new Error(gl.getProgramInfoLog(p));
    return p;
  }

  _texture(img, sampler) {
    if (!img) return null;
    if (this.textures.has(img)) return this.textures.get(img);
    const gl = this.gl, t = gl.createTexture();
    gl.bindTexture(gl.TEXTURE_2D, t);
    gl.pixelStorei(gl.UNPACK_FLIP_Y_WEBGL, false);
    gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, gl.RGBA, gl.UNSIGNED_BYTE, img);
    gl.generateMipmap(gl.TEXTURE_2D);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.LINEAR_MIPMAP_LINEAR);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.LINEAR);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, sampler?.wrapS ?? gl.REPEAT);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, sampler?.wrapT ?? gl.REPEAT);
    this.textures.set(img, t);
    return t;
  }

  setModel(model) {
    const gl = this.gl;
    this._clear();
    for (const p of model.prims) {
      const vao = gl.createVertexArray();
      gl.bindVertexArray(vao);
      const buffers = [];
      const attr = (loc, data, size) => {
        if (!data) { gl.disableVertexAttribArray(loc); return; }
        const b = gl.createBuffer(); buffers.push(b);
        gl.bindBuffer(gl.ARRAY_BUFFER, b); gl.bufferData(gl.ARRAY_BUFFER, data, gl.STATIC_DRAW);
        gl.enableVertexAttribArray(loc); gl.vertexAttribPointer(loc, size, gl.FLOAT, false, 0, 0);
      };
      attr(0, p.pos, 3); attr(1, p.nrm, 3); attr(2, p.uv, 2); attr(3, p.col, 4);
      const ib = gl.createBuffer(); buffers.push(ib);
      gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, ib); gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, p.idx, gl.STATIC_DRAW);
      gl.bindVertexArray(null);
      this.draws.push({ vao, buffers, count: p.idx.length, color: p.color, tex: this._texture(p.img, p.sampler), cutoff: p.alphaCutoff, hasCol: !!p.col });
    }
    const b = model.bounds;
    this.center = b.center;
    this.radius = Math.max(Math.hypot(...b.size) / 2, 1e-4);
    this.resetView();
  }

  resetView(yaw = 0.6, pitch = 0.32) { this.yaw = yaw; this.pitch = pitch; this.zoom = 1; this._dirty = true; }

  render() {
    const gl = this.gl, c = this.canvas;
    const dpr = this._dpr ?? Math.min(window.devicePixelRatio || 1, 2);
    const w = Math.max(1, Math.round(c.clientWidth * dpr)) || c.width, h = Math.max(1, Math.round(c.clientHeight * dpr)) || c.height;
    if (c.clientWidth && (c.width !== w || c.height !== h)) { c.width = w; c.height = h; }
    gl.viewport(0, 0, c.width, c.height);
    gl.clearColor(this.bg[0], this.bg[1], this.bg[2], 1);
    gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
    if (!this.draws.length) return;

    const fov = 0.6;
    const dist = (this.radius / Math.sin(fov / 2)) * 1.08 * this.zoom;
    const cp = Math.cos(this.pitch);
    const eye = [this.center[0] + dist * cp * Math.sin(this.yaw), this.center[1] + dist * Math.sin(this.pitch), this.center[2] + dist * cp * Math.cos(this.yaw)];
    const proj = M.perspective(fov, c.width / c.height, dist / 100, dist * 4 + this.radius * 4);
    const vp = M.mul(proj, M.lookAt(eye, this.center, [0, 1, 0]));

    gl.enable(gl.DEPTH_TEST); gl.disable(gl.CULL_FACE); gl.disable(gl.BLEND);
    gl.useProgram(this.prog);
    gl.uniformMatrix4fv(this.u.uVP, false, vp);
    // luce principale dall'alto, dalla parte della camera
    const l1 = norm([Math.sin(this.yaw + 0.7), 1.3, Math.cos(this.yaw + 0.7)]), l2 = norm([-Math.sin(this.yaw), 0.2, -Math.cos(this.yaw)]);
    gl.uniform3fv(this.u.uL1, l1); gl.uniform3fv(this.u.uL2, l2);
    gl.uniform1i(this.u.uTex, 0);
    for (const d of this.draws) {
      gl.uniform4fv(this.u.uColor, d.color);
      gl.uniform1i(this.u.uHasTex, d.tex ? 1 : 0);
      gl.uniform1f(this.u.uCutoff, d.cutoff);
      gl.activeTexture(gl.TEXTURE0); gl.bindTexture(gl.TEXTURE_2D, d.tex);
      gl.bindVertexArray(d.vao);
      if (!d.hasCol) gl.vertexAttrib4f(3, 1, 1, 1, 1);   // senza colori dei vertici: bianco (il valore di default è nero)
      gl.drawElements(gl.TRIANGLES, d.count, gl.UNSIGNED_INT, 0);
    }
    gl.bindVertexArray(null);
  }

  _bindInput() {
    const c = this.canvas;
    let drag = null;
    this._onDown = e => { drag = { x: e.clientX, y: e.clientY }; c.setPointerCapture?.(e.pointerId); };
    this._onMove = e => {
      if (!drag) return;
      this.yaw -= (e.clientX - drag.x) * 0.01;
      this.pitch = Math.max(-1.45, Math.min(1.45, this.pitch + (e.clientY - drag.y) * 0.01));
      drag = { x: e.clientX, y: e.clientY };
      this._dirty = true;
    };
    this._onUp = () => { drag = null; };
    this._onWheel = e => { e.preventDefault(); this.zoom = Math.max(0.25, Math.min(4, this.zoom * Math.exp(e.deltaY * 0.001))); this._dirty = true; };
    this._onDbl = () => this.resetView();
    c.addEventListener('pointerdown', this._onDown);
    c.addEventListener('pointermove', this._onMove);
    c.addEventListener('pointerup', this._onUp);
    c.addEventListener('pointercancel', this._onUp);
    c.addEventListener('wheel', this._onWheel, { passive: false });
    c.addEventListener('dblclick', this._onDbl);
    this._ro = typeof ResizeObserver !== 'undefined' ? new ResizeObserver(() => { this._dirty = true; }) : null;
    this._ro?.observe(c);
  }

  _clear() {
    const gl = this.gl;
    for (const d of this.draws) { gl.deleteVertexArray(d.vao); d.buffers.forEach(b => gl.deleteBuffer(b)); }
    for (const t of this.textures.values()) gl.deleteTexture(t);
    this.draws = []; this.textures.clear();
    this._dirty = true;
  }

  clear() { this._clear(); }

  dispose() {
    cancelAnimationFrame(this._raf);
    this._clear();
    this._ro?.disconnect();
    const c = this.canvas;
    c.removeEventListener('pointerdown', this._onDown); c.removeEventListener('pointermove', this._onMove);
    c.removeEventListener('pointerup', this._onUp); c.removeEventListener('pointercancel', this._onUp);
    c.removeEventListener('wheel', this._onWheel); c.removeEventListener('dblclick', this._onDbl);
    this.gl.getExtension('WEBGL_lose_context')?.loseContext();
  }
}

function norm(v) { const l = Math.hypot(...v) || 1; return [v[0] / l, v[1] / l, v[2] / l]; }

/** Miniatura JPG quadrata (vista 3/4 dall'alto), come quelle create dal visore. */
export async function makeThumbnail(model, size = 256) {
  if (!model.prims.length) return null;
  const canvas = document.createElement('canvas');
  canvas.width = canvas.height = size;
  const v = new GlbViewer(canvas, { preserve: true });
  try {
    v._dpr = 1;
    v.setModel(model);
    v.resetView(0.65, 0.38);
    v.render();
    return await new Promise(res => canvas.toBlob(res, 'image/jpeg', 0.86));
  } finally { v.dispose(); }
}
