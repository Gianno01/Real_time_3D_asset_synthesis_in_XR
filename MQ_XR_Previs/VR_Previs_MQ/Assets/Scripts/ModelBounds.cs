// ModelBounds.cs
// Ingombro e collisione "su misura" dell'oggetto, calcolati dai vertici reali del modello (non dai bounds dei renderer).
//
// Perché: i bounds di un renderer sono un riquadro allineato agli assi del renderer; dopo l'allineamento (il modello è ruotato
// dentro l'oggetto) e dopo ogni rotazione risultano più grandi del modello vero. Ne uscivano misure, ombra, appoggio e collisione
// "sballati". Qui invece:
//  • si leggono tutti i vertici del modello (nello spazio della radice) e si calcola l'ingombro esatto;
//  • si estrae un piccolo guscio convesso (~150 punti): punti più esterni in ~100 direzioni + i bordi della base e della cima,
//    così il piano di appoggio è piatto e preciso;
//  • il guscio diventa un MeshCollider convesso (collisione precisa, tavolo e bicchiere appoggiano sulle superfici vere);
//    se i vertici non sono leggibili si ripiega su un BoxCollider stretto;
//  • WorldBounds() restituisce l'ingombro attuale dai punti del guscio: preciso con qualsiasi rotazione e mai "in ritardo"
//    come Collider.bounds mentre l'oggetto si muove.
// Lo aggiunge QuestObjectGenerator.PlaceInScene (dopo ModelAlignment).

using System.Collections.Generic;
using UnityEngine;

public class ModelBounds : MonoBehaviour
{
    [HideInInspector] public Vector3[] hull = new Vector3[0];   // punti del guscio, spazio locale della radice
    [HideInInspector] public Vector3 localMin, localMax;          // ingombro esatto nello spazio locale della radice

    const int Directions = 160;
    const int SupportSamples = 40000;
    const int Azimuths = 16;

    public Vector3 LocalSize => localMax - localMin;
    public Vector3 LocalCenter => (localMin + localMax) * 0.5f;
    public bool HasData => hull != null && hull.Length > 0;

    /// <summary>Ingombro attuale nel mondo (riquadro allineato agli assi del mondo), dai punti del guscio.</summary>
    public Bounds WorldBounds()
    {
        var m = transform.localToWorldMatrix;
        if (!HasData) return new Bounds(transform.position, Vector3.zero);
        var b = new Bounds(m.MultiplyPoint3x4(hull[0]), Vector3.zero);
        for (int i = 1; i < hull.Length; i++) b.Encapsulate(m.MultiplyPoint3x4(hull[i]));
        return b;
    }

    /// <summary>
    /// Impronta a terra nel sistema ruotato come l'oggetto (heading = direzione orizzontale di uno dei suoi assi), valida anche
    /// per un oggetto sdraiato. size = lati dell'impronta (m), center = centro dell'impronta nel mondo (x, z).
    /// </summary>
    public void Footprint(out Vector2 size, out Vector2 center, out float heading)
    {
        size = Vector2.one * 0.02f; center = new Vector2(transform.position.x, transform.position.z); heading = 0f;
        if (!HasData) return;
        Quaternion q = transform.rotation;
        Vector3[] axes = { Vector3.right, Vector3.up, Vector3.forward };
        int up = 0; float best = -1f;
        for (int i = 0; i < 3; i++) { float d = Mathf.Abs((q * axes[i]).y); if (d > best) { best = d; up = i; } }
        Vector3 h = q * axes[(up + 1) % 3]; h.y = 0f;
        heading = h.sqrMagnitude > 1e-6f ? Mathf.Atan2(h.x, h.z) * Mathf.Rad2Deg : 0f;

        Quaternion inv = Quaternion.Euler(0f, -heading, 0f);
        Matrix4x4 m = transform.localToWorldMatrix;
        float x0 = float.MaxValue, x1 = float.MinValue, z0 = float.MaxValue, z1 = float.MinValue;
        for (int i = 0; i < hull.Length; i++)
        {
            Vector3 r = inv * m.MultiplyPoint3x4(hull[i]);
            if (r.x < x0) x0 = r.x; if (r.x > x1) x1 = r.x;
            if (r.z < z0) z0 = r.z; if (r.z > z1) z1 = r.z;
        }
        size = new Vector2(x1 - x0, z1 - z0);
        Vector3 c = Quaternion.Euler(0f, heading, 0f) * new Vector3((x0 + x1) * 0.5f, 0f, (z0 + z1) * 0.5f);
        center = new Vector2(c.x, c.z);
    }

    /// <summary>Calcola ingombro e guscio dai vertici dei modelli sotto l'oggetto. Restituisce null se non ci sono vertici leggibili.</summary>
    public static ModelBounds Build(GameObject root)
    {
        var meshes = new List<(Mesh mesh, Matrix4x4 m)>();
        Matrix4x4 toRoot = root.transform.worldToLocalMatrix;
        int total = 0;
        foreach (var mf in root.GetComponentsInChildren<MeshFilter>())
        {
            var mesh = mf.sharedMesh;
            if (mesh == null || !mesh.isReadable || mf.name.EndsWith("_Shadow")) continue;
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
        if (total < 4) return null;

        // ingombro esatto su tutti i vertici + campione per la ricerca dei punti più esterni
        Vector3 mn = Vector3.positiveInfinity, mx = Vector3.negativeInfinity;
        int step = Mathf.Max(1, total / SupportSamples);
        var sample = new List<Vector3>(Mathf.Min(total, SupportSamples) + 16);
        int counter = 0;
        foreach (var (mesh, m) in meshes)
        {
            var v = mesh.vertices;
            for (int i = 0; i < v.Length; i++)
            {
                Vector3 p = m.MultiplyPoint3x4(v[i]);
                mn = Vector3.Min(mn, p); mx = Vector3.Max(mx, p);
                if (counter++ % step == 0) sample.Add(p);
            }
        }

        var hullPts = ExtremePoints(sample, mn, mx);

        var mb = root.GetComponent<ModelBounds>();
        if (mb == null) mb = root.AddComponent<ModelBounds>();
        mb.hull = hullPts.ToArray();
        mb.localMin = mn; mb.localMax = mx;
        return mb;
    }

    /// <summary>
    /// Pochi punti (~150) che racchiudono la forma: i più esterni in ~100 direzioni più i bordi della base e della cima.
    /// mn/mx = ingombro esatto dell'insieme di punti.
    /// </summary>
    public static List<Vector3> ExtremePoints(List<Vector3> sample, Vector3 mn, Vector3 mx)
    {
        if (sample.Count > SupportSamples)
        {
            int st = sample.Count / SupportSamples + 1;
            var reduced = new List<Vector3>(SupportSamples + 8);
            for (int i = 0; i < sample.Count; i += st) reduced.Add(sample[i]);
            sample = reduced;
        }
        var hullPts = new List<Vector3>(160);
        void AddPoint(Vector3 p)
        {
            foreach (var q in hullPts) if ((q - p).sqrMagnitude < 1e-10f) return;
            hullPts.Add(p);
        }

        // punti più esterni in direzioni ~uniformi sulla sfera (spirale di Fibonacci) + i 6 assi
        var dirs = new List<Vector3>(Directions + 6)
        {
            Vector3.right, Vector3.left, Vector3.up, Vector3.down, Vector3.forward, Vector3.back
        };
        float golden = Mathf.PI * (3f - Mathf.Sqrt(5f));
        for (int i = 0; i < Directions; i++)
        {
            float y = 1f - 2f * (i + 0.5f) / Directions;
            float r = Mathf.Sqrt(Mathf.Max(0f, 1f - y * y));
            float a = golden * i;
            dirs.Add(new Vector3(Mathf.Cos(a) * r, y, Mathf.Sin(a) * r));
        }
        foreach (var d in dirs)
        {
            float best = float.NegativeInfinity; Vector3 bp = default;
            foreach (var p in sample) { float s = Vector3.Dot(p, d); if (s > best) { best = s; bp = p; } }
            AddPoint(bp);
        }

        // base e cima: bordi della fascia più bassa e più alta, così il piano di appoggio è piatto e preciso
        float h = Mathf.Max(mx.y - mn.y, 1e-4f);
        for (int slab = 0; slab < 2; slab++)
        {
            bool bottom = slab == 0;
            float limit = bottom ? mn.y + 0.03f * h : mx.y - 0.03f * h;
            for (int k = 0; k < Azimuths; k++)
            {
                float a = k * Mathf.PI * 2f / Azimuths;
                var d = new Vector3(Mathf.Cos(a), 0f, Mathf.Sin(a));
                float best = float.NegativeInfinity; Vector3 bp = default; bool found = false;
                foreach (var p in sample)
                {
                    if (bottom ? p.y > limit : p.y < limit) continue;
                    float s = Vector3.Dot(p, d);
                    if (s > best) { best = s; bp = p; found = true; }
                }
                if (found) AddPoint(bp);
            }
        }
        return hullPts;
    }

    /// <summary>Aggiunge all'oggetto il collider: guscio convesso preciso, o box stretto come ripiego. Sostituisce i collider creati prima da qui.</summary>
    public Collider AddCollider()
    {
        foreach (var old in GetComponents<Collider>()) DestroyImmediate(old);   // subito: così GetComponent<Collider>() trova già il nuovo

        if (hull.Length >= 8)
        {
            var mesh = new Mesh { name = "ColliderHull" };
            mesh.vertices = hull;
            var idx = new int[(hull.Length - 2) * 3];   // la forma convessa dipende solo dai punti: i triangoli servono solo a rendere valida la mesh
            for (int i = 0; i < hull.Length - 2; i++) { idx[i * 3] = 0; idx[i * 3 + 1] = i + 1; idx[i * 3 + 2] = i + 2; }
            mesh.triangles = idx;
            var mc = gameObject.AddComponent<MeshCollider>();
            mc.sharedMesh = mesh;
            mc.convex = true;
            return mc;
        }

        var box = gameObject.AddComponent<BoxCollider>();
        box.center = LocalCenter;
        box.size = LocalSize;
        return box;
    }
}
