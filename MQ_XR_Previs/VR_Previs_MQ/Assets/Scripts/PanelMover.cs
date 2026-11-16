// PanelMover.cs
// Rende spostabile un pannello a mezz'aria (tastiera, pannello luci…) come l'interfaccia principale:
// una maniglia sotto il pannello, si afferra col controller e si lascia dove si vuole. Il pannello resta lì finché non lo si chiude
// e lo si riapre lontano (oltre 'reopenBeyond' dal viso torna davanti a te). Durante la presa la distanza dal viso è limitata
// tra minDistance e maxDistance, così non si può spingere all'infinito.

using UnityEngine;
using UnityEngine.UI;
using UnityEngine.XR.Interaction.Toolkit.Interactables;

public class PanelMover : MonoBehaviour
{
    public Transform head;
    public float minDistance = 0.3f;
    public float maxDistance = 1.5f;
    /// <summary>Se alla riapertura il pannello è più lontano di così, torna davanti al viso.</summary>
    public float reopenBeyond = 2.5f;

    public bool Grabbed { get; private set; }
    public bool Pinned { get; private set; }

    RectTransform _rt;
    Image _handle;
    XRGrabInteractable _grab;
    Transform _col;
    float _handleY;
    static Sprite s_rounded;

    /// <summary>Aggiunge la maniglia al pannello (canvas world-space con pivot al centro, 1 unità locale = 1 pixel).</summary>
    public static PanelMover Attach(RectTransform panel, Transform head, float maxDistance = 1.5f)
    {
        var m = panel.gameObject.GetComponent<PanelMover>();
        if (m == null) m = panel.gameObject.AddComponent<PanelMover>();
        m.head = head; m.maxDistance = maxDistance;
        m.Build(panel);
        return m;
    }

    void Build(RectTransform panel)
    {
        if (_rt != null) return;
        _rt = panel;
        _handleY = -(panel.sizeDelta.y / 2f + 24f);

        var go = new GameObject("MoveHandle", typeof(RectTransform), typeof(Image));
        go.transform.SetParent(_rt, false);
        _handle = go.GetComponent<Image>();
        _handle.sprite = Rounded();
        _handle.type = Image.Type.Sliced;
        _handle.color = new Color(1f, 1f, 1f, 0.35f);
        _handle.raycastTarget = false;
        var hrt = _handle.rectTransform;
        hrt.sizeDelta = new Vector2(150, 12);
        hrt.anchoredPosition = new Vector2(0, _handleY);

        var rb = gameObject.GetComponent<Rigidbody>();
        if (rb == null) rb = gameObject.AddComponent<Rigidbody>();
        rb.isKinematic = true; rb.useGravity = false;

        var colGo = new GameObject("MoveHandleCollider");
        colGo.transform.SetParent(_rt, false);
        colGo.transform.localPosition = new Vector3(0f, _handleY, 0f);
        colGo.AddComponent<BoxCollider>().size = new Vector3(300f, 70f, 40f);
        _col = colGo.transform;

        _grab = gameObject.AddComponent<XRGrabInteractable>();
        _grab.movementType = XRBaseInteractable.MovementType.Instantaneous;
        _grab.trackRotation = false;   // la rotazione (verso il viso) la gestiamo noi
        _grab.throwOnDetach = false;
        _grab.useDynamicAttach = true;
        _grab.selectEntered.AddListener(_ => Grabbed = true);
        _grab.selectExited.AddListener(_ => { Grabbed = false; Pinned = true; });
    }

    /// <summary>true se, alla riapertura, il pannello va rimesso davanti al viso (mai spostato a mano, o ora troppo lontano).</summary>
    public bool NeedsPlacement()
    {
        if (!Pinned || head == null) return true;
        return Vector3.Distance(transform.position, head.position) > reopenBeyond;
    }

    /// <summary>Dimentica lo spostamento manuale: alla prossima apertura va davanti al viso.</summary>
    public void ResetPin() { Pinned = false; Grabbed = false; }

    void LateUpdate()
    {
        if (head == null || _rt == null) return;
        if (Grabbed || Pinned)
        {
            Vector3 off = transform.position - head.position;
            float d = off.magnitude;
            if (Grabbed && d > 0.001f)
            {
                float c = Mathf.Clamp(d, minDistance, maxDistance);
                if (!Mathf.Approximately(c, d)) transform.position = head.position + off / d * c;
            }
            if (off.sqrMagnitude > 0.0001f)
            {
                Quaternion r = Quaternion.LookRotation(off.normalized, Vector3.up);
                transform.rotation = Quaternion.Slerp(transform.rotation, r, 1f - Mathf.Exp(-10f * Time.unscaledDeltaTime));
            }
        }
        bool active = _grab != null && (_grab.isHovered || Grabbed);
        var col = _handle.color;
        col.a = Mathf.MoveTowards(col.a, active ? 0.9f : 0.35f, Time.unscaledDeltaTime * 4f);
        _handle.color = col;
        _handle.rectTransform.localScale = Vector3.Lerp(_handle.rectTransform.localScale, Vector3.one * (active ? 1.25f : 1f), Time.unscaledDeltaTime * 10f);
    }

    static Sprite Rounded()
    {
        if (s_rounded != null) return s_rounded;
        const int n = 32; const float r = 10f;
        var tex = new Texture2D(n, n, TextureFormat.RGBA32, false) { filterMode = FilterMode.Bilinear };
        for (int y = 0; y < n; y++)
            for (int x = 0; x < n; x++)
            {
                float cx = Mathf.Clamp(x + 0.5f, r, n - r), cy = Mathf.Clamp(y + 0.5f, r, n - r);
                float d = Mathf.Sqrt((x + 0.5f - cx) * (x + 0.5f - cx) + (y + 0.5f - cy) * (y + 0.5f - cy));
                tex.SetPixel(x, y, new Color(1f, 1f, 1f, Mathf.Clamp01(r - d + 0.5f)));
            }
        tex.Apply();
        s_rounded = Sprite.Create(tex, new Rect(0, 0, n, n), new Vector2(0.5f, 0.5f), 100f, 0, SpriteMeshType.FullRect, new Vector4(r, r, r, r));
        return s_rounded;
    }
}
