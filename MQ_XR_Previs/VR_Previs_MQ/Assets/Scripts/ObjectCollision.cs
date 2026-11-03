// ObjectCollision.cs
// Collisione tra gli oggetti della scena mentre ne tieni uno in mano (aggiunto da QuestObjectGenerator).
//
// Gli oggetti hanno un Rigidbody kinematico che segue la mano: da soli si attraverserebbero. Qui, finché l'oggetto è afferrato,
// ogni frame (dopo che la presa lo ha spostato) si controlla se il suo collider entra in quello di un altro oggetto
// (o di un mobile reale, se c'è SceneOcclusion) e lo si sposta fuori. Dove c'è un piano su cui appoggiarsi
// (altezza da salire <= stepUp) l'oggetto viene SOLLEVATO e resta appoggiato sopra, invece di essere respinto di lato:
// una penna premuta sul tavolino si ferma sul piano.
//
// Note:
//  • il collider di ogni oggetto è un unico box che avvolge tutta la sagoma (lo crea QuestObjectGenerator):
//    quindi un tavolo è un blocco pieno e sotto il piano non si può infilare un altro oggetto;
//  • gli oggetti bloccati (SceneObject.locked) restano ostacoli, ma non vengono mai spostati;
//  • si attiva/disattiva dalle Impostazioni (QuestObjectGenerator.objectCollisions, di default acceso).

using Unity.XR.CoreUtils;
using UnityEngine;
using UnityEngine.XR.Interaction.Toolkit.Interactables;

public class ObjectCollision : MonoBehaviour
{
    [Tooltip("Quante volte si ripete la correzione per frame (serve quando si tocca più di un oggetto)")]
    public int iterations = 4;
    [Tooltip("Distanza lasciata tra due oggetti a contatto (m)")]
    public float skin = 0.001f;
    [Tooltip("Se per uscire dall'altro oggetto basta salire di meno di questo (m), l'oggetto si appoggia sopra invece di essere spinto di lato")]
    public float stepUp = 0.15f;

    static readonly Collider[] s_buf = new Collider[48];

    XRGrabInteractable _grab;
    SceneObject _so;
    Collider _col;

    void Start()
    {
        _grab = GetComponent<XRGrabInteractable>();
        _so = GetComponent<SceneObject>();
        _col = GetComponent<Collider>();
        Application.onBeforeRender += OnBeforeRender;   // la presa sposta l'oggetto anche qui: si corregge dopo di lei
    }

    void OnDestroy() { Application.onBeforeRender -= OnBeforeRender; }

    void LateUpdate() { if (IsHeld) ResolveHeld(); }

    void OnBeforeRender() { if (IsHeld) ResolveHeld(); }

    bool IsHeld => enabled && _grab != null && _grab.isSelected;

    void ResolveHeld()
    {
        if (_so == null) _so = GetComponent<SceneObject>();
        if (_so != null && _so.locked) return;
        Depenetrate(true);
    }

    /// <summary>Porta fuori l'oggetto da ciò che sta attraversando (usato anche dopo l'aggancio al rilascio).</summary>
    public void ResolveNow() { if (enabled) Depenetrate(true); }

    /// <summary>
    /// Sposta l'oggetto fuori dai collider che attraversa. Con preferUp, se basta salire di meno di stepUp lo appoggia sopra.
    /// Restituisce true se è stato sollevato (= ora poggia su qualcosa).
    /// </summary>
    public bool Depenetrate(bool preferUp)
    {
        if (_col == null) _col = GetComponent<Collider>();
        if (_col == null || !_col.enabled) return false;

        var tr = transform;
        bool pushedUp = false;
        for (int it = 0; it < Mathf.Max(1, iterations); it++)
        {
            Physics.SyncTransforms();
            Bounds mb = _col.bounds;
            int n = Physics.OverlapBoxNonAlloc(mb.center, mb.extents + Vector3.one * 0.002f, s_buf, Quaternion.identity, ~0, QueryTriggerInteraction.Ignore);
            bool any = false;
            for (int i = 0; i < n; i++)
            {
                var oc = s_buf[i];
                if (oc == null || oc == _col || !oc.enabled || oc.transform.IsChildOf(tr)) continue;
                if (oc is MeshCollider mc && !mc.convex) continue;          // ComputePenetration non lo supporta
                if (oc.GetComponentInParent<XROrigin>() != null) continue;   // mani, controller, rig

                if (!Physics.ComputePenetration(_col, tr.position, tr.rotation,
                                                oc, oc.transform.position, oc.transform.rotation,
                                                out Vector3 dir, out float dist)) continue;

                Vector3 push = dir * (dist + skin);
                if (preferUp)
                {
                    float lift = oc.bounds.max.y - _col.bounds.min.y;
                    if (lift > 0f && lift <= stepUp) push = Vector3.up * (lift + skin);   // appoggio sul piano
                }
                tr.position += push;
                Physics.SyncTransforms();
                any = true;
                if (push.y > 0f && push.y >= new Vector2(push.x, push.z).magnitude) pushedUp = true;
            }
            if (!any) break;
        }
        return pushedUp;
    }
}
