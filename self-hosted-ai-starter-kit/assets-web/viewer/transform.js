// Conversione delle pose da Unity (sinistrorso: X destra, Y su, Z avanti) a three.js / glTF (destrorso).
// Si specchia l'asse X: F(x, y, z) = (-x, y, z). Le rotazioni diventano il coniugato: (qx, -qy, -qz, qw).
// glTFast (Unity) fa la stessa cosa quando importa un GLB, quindi il modello nel browser, letto "nativo", coincide con quello nel visore.
//
// Struttura di un oggetto, uguale a quella creata nel visore da ModelAlignment:
//   root (posa dell'oggetto, scala) → pivot (centro + correzione di raddrizzamento) → holder (-centro) → modello glTF
// Un punto v del modello finisce in:  p + R(q)·( s · ( c + Rc·(v - c) ) )

export const pos = p => [-p[0], p[1], p[2]];
export const quat = q => [q[0], -q[1], -q[2], q[3]];

/** Dati dal relay (coordinate Unity) → valori per three.js. */
export function objectTransform(o) {
  const al = Array.isArray(o.al) && o.al.length === 7 ? o.al : null;
  const c = al ? pos(al.slice(0, 3)) : [0, 0, 0];
  return {
    pos: pos(o.p || [0, 0, 0]),
    quat: quat(o.r || [0, 0, 0, 1]),
    scale: o.s > 0 ? o.s : 1,
    pivotPos: c,
    pivotQuat: al ? quat(al.slice(3, 7)) : [0, 0, 0, 1],
    holderPos: [-c[0], -c[1], -c[2]],
  };
}

/** Sorgente del modello: libreria (nginx /assets) oppure ComfyUI (proxy /comfy). Stringa vuota se non c'è nulla da caricare. */
export function modelUrl(o, base = '') {
  if (o.glbKey) return `${base}/${o.glbKey}`;
  if (o.src) return `${base}/comfy${o.src}`;
  return '';
}
