// SyncAvatar.cs
// Testa e controller dell'altra persona (host, co-host) disegnati come sfere: il naso sulla testa indica dove guarda.
// Le pose arrivano nello spazio dell'ancora di scena (x,y,z,qx,qy,qz,qw), come in SyncProtocol.

using UnityEngine;

public class SyncAvatar
{
    readonly GameObject _root, _head, _handL, _handR;
    readonly Material[] _mats;
    float[] _hp = new float[0], _lp = new float[0], _rp = new float[0];
    bool _online;

    public SyncAvatar(string name, Color headColor, Color leftColor, Color rightColor)
    {
        var sh = Shader.Find("Sprites/Default");   // sempre incluso nella build, senza luci
        Material Mat(Color c) => new Material(sh) { color = c };
        _mats = new[] { Mat(headColor), Mat(Color.white), Mat(leftColor), Mat(rightColor) };

        _root = new GameObject(name);
        _head = Part(PrimitiveType.Sphere, _mats[0], 0.18f, _root.transform);
        var nose = Part(PrimitiveType.Cube, _mats[1], 0.05f, _head.transform);
        nose.transform.localPosition = new Vector3(0f, 0f, 0.6f);
        nose.transform.localScale = new Vector3(0.25f, 0.25f, 0.5f);
        _handL = Part(PrimitiveType.Sphere, _mats[2], 0.07f, _root.transform);
        _handR = Part(PrimitiveType.Sphere, _mats[3], 0.07f, _root.transform);
        _root.SetActive(false);
    }

    static GameObject Part(PrimitiveType type, Material m, float size, Transform parent)
    {
        var go = GameObject.CreatePrimitive(type);
        Object.Destroy(go.GetComponent<Collider>());
        go.GetComponent<Renderer>().sharedMaterial = m;
        go.transform.SetParent(parent, false);
        go.transform.localScale = Vector3.one * size;
        return go;
    }

    public void SetOnline(bool online) { _online = online; Refresh(); }

    public void SetPose(float[] hp, float[] lp, float[] rp)
    {
        _hp = hp ?? new float[0]; _lp = lp ?? new float[0]; _rp = rp ?? new float[0];
        Refresh();
    }

    void Refresh() { if (_root != null) _root.SetActive(_online && _hp.Length >= 7); }

    /// <summary>Muove l'avatar verso la posa ricevuta (k = 1 - exp(-v*dt)). anchor = ancora di scena, o null.</summary>
    public void Tick(float k, Transform anchor)
    {
        if (_root == null || !_root.activeSelf) return;
        Move(_head.transform, _hp, k, anchor);
        _handL.SetActive(_lp.Length >= 7); if (_lp.Length >= 7) Move(_handL.transform, _lp, k, anchor);
        _handR.SetActive(_rp.Length >= 7); if (_rp.Length >= 7) Move(_handR.transform, _rp, k, anchor);
    }

    static void Move(Transform t, float[] p, float k, Transform a)
    {
        Vector3 lp = new Vector3(p[0], p[1], p[2]);
        Quaternion lr = new Quaternion(p[3], p[4], p[5], p[6]);
        Vector3 wp = a != null ? a.TransformPoint(lp) : lp;
        Quaternion wr = a != null ? a.rotation * lr : lr;
        t.SetPositionAndRotation(Vector3.Lerp(t.position, wp, k), Quaternion.Slerp(t.rotation, wr, k));
    }

    public void Destroy()
    {
        if (_root != null) Object.Destroy(_root);
        foreach (var m in _mats) if (m != null) Object.Destroy(m);
    }
}
