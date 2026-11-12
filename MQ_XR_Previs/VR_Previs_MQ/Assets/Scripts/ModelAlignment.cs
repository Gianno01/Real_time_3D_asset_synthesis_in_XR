// ModelAlignment.cs
// Raddrizza i modelli generati prima di metterli in scena (chiamato da QuestObjectGenerator.PlaceInScene).
//
// I modelli image-to-3D escono spesso leggermente ruotati: la base non è parallela agli assi e a volte è un po' inclinata.
// Così la griglia, le misure e l'aggancio a scatti non corrispondono ai lati "veri" dell'oggetto.
//
//  1) Inclinazione: si prendono i punti più bassi del modello (piedi, gambe, base) e si stima il piano su cui poggiano.
//     Se è inclinato di poco (entro maxTiltDegrees) lo si riporta orizzontale. Oggetti senza una base piana
//     (sfere, vasi tondi…) vengono lasciati come sono.
//  2) Rotazione: si cerca l'angolo (entro ±45°, così il fronte resta davanti) per cui l'impronta a terra
//     occupa il rettangolo più piccolo: i lati dell'oggetto diventano paralleli agli assi.
//  3) Ricerca diretta: si prova anche, insieme, ogni combinazione di inclinazione (fino a 30°) e rotazione cercando quella
//     che rende più piccolo il riquadro che contiene l'oggetto. Tra i due metodi vince quello con il riquadro minore
//     (serve un guadagno netto, altrimenti l'oggetto resta com'è). Il log dice quale metodo ha vinto.
//
// La correzione va su un figlio "Allineamento" che contiene il modello: la radice (presa, collider, SceneObject) resta pulita.
// È deterministica: lo stesso GLB viene raddrizzato sempre allo stesso modo (scene salvate e ricaricate coincidono).

using System.Collections.Generic;
using UnityEngine;

public static class ModelAlignment
{
    const int MaxSamples = 30000;

    /// <summary>Raddrizza il modello. Restituisce la correzione applicata (identity se nessuna).</summary>
    public static Quaternion Align(GameObject root, bool fixTilt = true, float maxTiltDegrees = 12f, bool fixYaw = true)
    {
        if (root == null) return Quaternion.identity;
        if (root.GetComponent<Renderer>() != null)
        {
            Debug.LogWarning($"[ModelAlignment] {root.name}: la radice ha un renderer, allineamento saltato");
            return Quaternion.identity;
        }

        var orig = CollectPoints(root);
        if (orig.Count < 50)
        {
            Debug.LogWarning($"[ModelAlignment] {root.name}: vertici non leggibili ({orig.Count}), allineamento saltato");
            return Quaternion.identity;
        }

        // Candidato 1: metodo "a piani" (piano dei punti più bassi + rettangolo d'impronta minimo)
        var pts = new List<Vector3>(orig);
        Quaternion legacy = Quaternion.identity;
        if (fixTilt)
        {
            Quaternion tilt = EstimateTilt(pts, maxTiltDegrees);
            if (tilt != Quaternion.identity)
            {
                legacy = tilt;
                for (int i = 0; i < pts.Count; i++) pts[i] = tilt * pts[i];
            }
        }
        float yaw = fixYaw ? BestYaw(pts) : 0f;
        if (Mathf.Abs(yaw) > 0.05f) legacy = Quaternion.Euler(0f, yaw, 0f) * legacy;

        // Candidato 2: ricerca diretta dell'assetto che rende il riquadro dell'oggetto più piccolo (inclinazione e rotazione insieme).
        // Funziona anche quando il modello è molto storto o non ha una base piana da cui stimare il piano.
        float searchTilt = fixTilt ? Mathf.Max(maxTiltDegrees, SearchTiltDegrees) : 0f;
        Quaternion corr = ChooseBest(orig, legacy, searchTilt, fixYaw, out string info);

        if (corr == Quaternion.identity)
        {
            Debug.Log($"[ModelAlignment] {root.name}: già dritto, nessuna correzione ({info})");
            return corr;
        }

        var corrected = new List<Vector3>(orig.Count);
        for (int i = 0; i < orig.Count; i++) corrected.Add(corr * orig[i]);
        ApplyCorrection(root, corrected, corr);
        Debug.Log($"[ModelAlignment] {root.name}: corretto di {Quaternion.Angle(Quaternion.identity, corr):F1}° ({info})");
        return corr;
    }

    /// <summary>Riapplica un raddrizzamento SALVATO (centro x,y,z + rotazione x,y,z,w) senza ricalcolarlo. Vuoto/nullo = nessuna correzione.
    /// Serve a ricaricare le scene: il risultato è identico a quando sono state salvate, anche se nel frattempo è cambiato l'algoritmo
    /// o l'impostazione "Raddrizza i modelli".</summary>
    public static void ApplyStored(GameObject root, float[] al)
    {
        if (root == null || al == null || al.Length < 7) return;
        var pivot = new GameObject("Allineamento").transform;
        pivot.SetParent(root.transform, false);
        pivot.localPosition = new Vector3(al[0], al[1], al[2]);
        pivot.localRotation = Quaternion.identity;
        pivot.localScale = Vector3.one;
        var children = new List<Transform>();
        foreach (Transform c in root.transform) if (c != pivot) children.Add(c);
        foreach (var c in children) c.SetParent(pivot, true);
        pivot.localRotation = new Quaternion(al[3], al[4], al[5], al[6]);
    }

    // ── Ricerca dell'assetto con il riquadro più piccolo ─────────────

    const float SearchTiltDegrees = 30f;   // inclinazione massima cercata (almeno questa, anche se l'impostazione è più bassa)

    static Quaternion ChooseBest(List<Vector3> orig, Quaternion legacy, float maxTilt, bool fixYaw, out string info)
    {
        // pochi punti "estremi" bastano a conoscere il riquadro in qualsiasi rotazione
        Vector3 mn = Vector3.positiveInfinity, mx = Vector3.negativeInfinity;
        foreach (var p in orig) { mn = Vector3.Min(mn, p); mx = Vector3.Max(mx, p); }
        var ext = ModelBounds.ExtremePoints(orig, mn, mx).ToArray();

        float Vol(Quaternion q)
        {
            Matrix4x4 m = Matrix4x4.Rotate(q);
            float x0 = float.MaxValue, y0 = x0, z0 = x0, x1 = float.MinValue, y1 = x1, z1 = x1;
            for (int i = 0; i < ext.Length; i++)
            {
                Vector3 p = m.MultiplyVector(ext[i]);
                if (p.x < x0) x0 = p.x; if (p.x > x1) x1 = p.x;
                if (p.y < y0) y0 = p.y; if (p.y > y1) y1 = p.y;
                if (p.z < z0) z0 = p.z; if (p.z > z1) z1 = p.z;
            }
            return (x1 - x0) * (y1 - y0) * (z1 - z0);
        }
        Quaternion Rot(float yaw, float pitch, float roll) => Quaternion.Euler(0f, yaw, 0f) * Quaternion.Euler(pitch, 0f, 0f) * Quaternion.Euler(0f, 0f, roll);
        // piccola preferenza per le correzioni più lievi, a parità di riquadro
        float Score(float yaw, float pitch, float roll) => Vol(Rot(yaw, pitch, roll)) * (1f + 0.001f * (Mathf.Abs(pitch) + Mathf.Abs(roll)));

        float v0 = Vol(Quaternion.identity);
        float yawMax = fixYaw ? 45f : 0f;

        // ricerca grossolana (inclinazione a passi di 4°, rotazione a passi di 3°), poi raffinamento
        float bestS = float.MaxValue, bYaw = 0f, bPitch = 0f, bRoll = 0f;
        for (float pitch = -maxTilt; pitch <= maxTilt + 0.01f; pitch += 4f)
        for (float roll = -maxTilt; roll <= maxTilt + 0.01f; roll += 4f)
        {
            if (maxTilt <= 0f && (pitch != 0f || roll != 0f)) continue;
            for (float yaw = -yawMax; yaw < yawMax || (yawMax == 0f && yaw == 0f); yaw += 3f)
            {
                float sc = Score(yaw, pitch, roll);
                if (sc < bestS) { bestS = sc; bYaw = yaw; bPitch = pitch; bRoll = roll; }
                if (yawMax == 0f) break;
            }
            if (maxTilt <= 0f) break;
        }
        foreach (float stepSize in new[] { 2f, 1f, 0.5f, 0.25f })
        {
            bool improved = true; int guard = 0;
            while (improved && guard++ < 40)
            {
                improved = false;
                for (int axis = 0; axis < 3; axis++)
                for (int sign = -1; sign <= 1; sign += 2)
                {
                    float y = bYaw, p = bPitch, r = bRoll;
                    if (axis == 0) { if (yawMax == 0f) continue; y = Mathf.Clamp(y + sign * stepSize, -yawMax, yawMax); }
                    else if (axis == 1) { if (maxTilt <= 0f) continue; p = Mathf.Clamp(p + sign * stepSize, -maxTilt, maxTilt); }
                    else { if (maxTilt <= 0f) continue; r = Mathf.Clamp(r + sign * stepSize, -maxTilt, maxTilt); }
                    float sc = Score(y, p, r);
                    if (sc < bestS - 1e-9f) { bestS = sc; bYaw = y; bPitch = p; bRoll = r; improved = true; }
                }
            }
        }
        Quaternion fit = Rot(bYaw, bPitch, bRoll);

        // si sceglie il candidato con il riquadro più piccolo; serve un guadagno netto (>3%) rispetto a non toccare niente
        float vLegacy = legacy == Quaternion.identity ? v0 : Vol(legacy), vFit = Vol(fit);
        Quaternion best = Quaternion.identity; float bestVol = v0; string who = "nessuna";
        if (vLegacy < bestVol * 0.97f) { best = legacy; bestVol = vLegacy; who = "piani"; }
        if (vFit < bestVol * 0.99f && vFit < v0 * 0.97f) { best = fit; bestVol = vFit; who = "ricerca"; }
        info = $"metodo {who}, riquadro {bestVol / Mathf.Max(v0, 1e-12f) * 100f:F0}% dell'originale; ricerca: rotazione {bYaw:F1}°, inclinazione {bPitch:F1}°/{bRoll:F1}°";
        return best;
    }

    // ── Punti del modello nello spazio della radice ──────────────────

    static List<Vector3> CollectPoints(GameObject root)
    {
        var meshes = new List<(Mesh mesh, Matrix4x4 m)>();
        int total = 0;
        Matrix4x4 toRoot = root.transform.worldToLocalMatrix;
        foreach (var mf in root.GetComponentsInChildren<MeshFilter>())
        {
            var mesh = mf.sharedMesh;
            if (mesh == null) continue;
            if (!mesh.isReadable) { Debug.LogWarning($"[ModelAlignment] mesh \"{mesh.name}\" non leggibile: saltata"); continue; }
            meshes.Add((mesh, toRoot * mf.transform.localToWorldMatrix));
            total += mesh.vertexCount;
        }
        foreach (var smr in root.GetComponentsInChildren<SkinnedMeshRenderer>())
        {
            var mesh = smr.sharedMesh;
            if (mesh == null || !mesh.isReadable) continue;
            meshes.Add((mesh, toRoot * smr.transform.localToWorldMatrix));
            total += mesh.vertexCount;
        }

        var pts = new List<Vector3>(Mathf.Min(total, MaxSamples) + 16);
        int step = Mathf.Max(1, total / MaxSamples);
        foreach (var (mesh, m) in meshes)
        {
            var v = mesh.vertices;
            for (int i = 0; i < v.Length; i += step) pts.Add(m.MultiplyPoint3x4(v[i]));
        }
        return pts;
    }

    // ── Inclinazione: piano dei punti più bassi ──────────────────────

    static Quaternion EstimateTilt(List<Vector3> pts, float maxDeg)
    {
        float minY = float.MaxValue, maxY = float.MinValue;
        Vector3 bmin = Vector3.positiveInfinity, bmax = Vector3.negativeInfinity;
        foreach (var p in pts)
        {
            bmin = Vector3.Min(bmin, p); bmax = Vector3.Max(bmax, p);
        }
        minY = bmin.y; maxY = bmax.y;
        float height = maxY - minY;
        if (height <= 1e-5f) return Quaternion.identity;

        // fascia bassa: il 6% dell'altezza (più margine per l'inclinazione stessa)
        float footprint = Mathf.Max(bmax.x - bmin.x, bmax.z - bmin.z);
        float band = height * 0.06f + footprint * Mathf.Tan(maxDeg * Mathf.Deg2Rad);
        var low = new List<Vector3>();
        foreach (var p in pts) if (p.y <= minY + band) low.Add(p);
        if (low.Count < 20) return Quaternion.identity;

        // i punti bassi devono essere distribuiti su gran parte dell'impronta (base, piedi, gambe), non concentrati in un punto
        Vector3 lmin = Vector3.positiveInfinity, lmax = Vector3.negativeInfinity, c = Vector3.zero;
        foreach (var p in low) { lmin = Vector3.Min(lmin, p); lmax = Vector3.Max(lmax, p); c += p; }
        c /= low.Count;
        if ((lmax.x - lmin.x) < 0.35f * (bmax.x - bmin.x) || (lmax.z - lmin.z) < 0.35f * (bmax.z - bmin.z)) return Quaternion.identity;

        // piano dei minimi: in ogni cella di una griglia 8×8 si tiene il punto più basso (ignora i punti delle pareti)
        const int G = 8;
        var cellMin = new Vector3?[G, G];
        float sx = Mathf.Max(lmax.x - lmin.x, 1e-6f), sz = Mathf.Max(lmax.z - lmin.z, 1e-6f);
        foreach (var p in low)
        {
            int ix = Mathf.Min(G - 1, (int)((p.x - lmin.x) / sx * G)), iz = Mathf.Min(G - 1, (int)((p.z - lmin.z) / sz * G));
            if (cellMin[ix, iz] == null || p.y < cellMin[ix, iz].Value.y) cellMin[ix, iz] = p;
        }
        var support = new List<Vector3>();
        foreach (var v in cellMin) if (v != null) support.Add(v.Value);
        if (support.Count < 6) return Quaternion.identity;

        // minimi quadrati: y = a·x + b·z + d
        double sxx = 0, sxz = 0, szz = 0, sxv = 0, szv = 0, sxs = 0, szs = 0, sys = 0; int n = support.Count;
        foreach (var p in support) { sxs += p.x; szs += p.z; sys += p.y; }
        double mx = sxs / n, mz = szs / n, my = sys / n;
        foreach (var p in support)
        {
            double x = p.x - mx, z = p.z - mz, y = p.y - my;
            sxx += x * x; sxz += x * z; szz += z * z; sxv += x * y; szv += z * y;
        }
        double det = sxx * szz - sxz * sxz;
        if (System.Math.Abs(det) < 1e-12) return Quaternion.identity;
        double a = (sxv * szz - szv * sxz) / det, b = (szv * sxx - sxv * sxz) / det;

        // il piano deve essere davvero un piano (scarto piccolo rispetto alla dimensione dell'oggetto)
        double err = 0;
        foreach (var p in support) { double r = (p.y - my) - (a * (p.x - mx) + b * (p.z - mz)); err += r * r; }
        if (System.Math.Sqrt(err / n) > 0.03 * footprint) return Quaternion.identity;

        Vector3 normal = new Vector3((float)-a, 1f, (float)-b).normalized;
        float angle = Vector3.Angle(normal, Vector3.up);
        if (angle < 0.7f || angle > maxDeg) return Quaternion.identity;
        return Quaternion.FromToRotation(normal, Vector3.up);
    }

    // ── Rotazione: rettangolo d'impronta più piccolo ─────────────────

    static float BestYaw(List<Vector3> pts)
    {
        float Area(float deg)
        {
            float r = deg * Mathf.Deg2Rad, cs = Mathf.Cos(r), sn = Mathf.Sin(r);
            float x0 = float.MaxValue, x1 = float.MinValue, z0 = float.MaxValue, z1 = float.MinValue;
            for (int i = 0; i < pts.Count; i++)
            {
                var p = pts[i];
                float x = cs * p.x + sn * p.z, z = -sn * p.x + cs * p.z;   // rotazione attorno a Y di +deg
                if (x < x0) x0 = x; if (x > x1) x1 = x; if (z < z0) z0 = z; if (z > z1) z1 = z;
            }
            return (x1 - x0) * (z1 - z0);
        }

        float a0 = Area(0f), best = 0f, bestA = a0;
        for (float d = -45f; d < 45f; d += 1f) { float a = Area(d); if (a < bestA) { bestA = a; best = d; } }
        for (float d = best - 1f; d <= best + 1f; d += 0.1f) { float a = Area(d); if (a < bestA) { bestA = a; best = d; } }

        // oggetti tondi: l'impronta cambia poco con l'angolo, meglio non toccarli
        if (bestA > a0 * 0.97f) return 0f;
        return best;
    }

    // ── Applicazione ─────────────────────────────────────────────────

    static void ApplyCorrection(GameObject root, List<Vector3> correctedPts, Quaternion corr)
    {
        var t = root.transform;
        // pivot al centro dei bounds originali (la correzione ruota attorno al centro, non all'origine del file)
        Vector3 bmin = Vector3.positiveInfinity, bmax = Vector3.negativeInfinity;
        Quaternion inv = Quaternion.Inverse(corr);
        foreach (var p in correctedPts) { var o = inv * p; bmin = Vector3.Min(bmin, o); bmax = Vector3.Max(bmax, o); }
        Vector3 center = (bmin + bmax) * 0.5f;

        var pivot = new GameObject("Allineamento").transform;
        pivot.SetParent(t, false);
        pivot.localPosition = center;
        pivot.localRotation = Quaternion.identity;
        pivot.localScale = Vector3.one;

        var children = new List<Transform>();
        foreach (Transform c in t) if (c != pivot) children.Add(c);
        foreach (var c in children) c.SetParent(pivot, true);

        pivot.localRotation = corr;
    }
}
