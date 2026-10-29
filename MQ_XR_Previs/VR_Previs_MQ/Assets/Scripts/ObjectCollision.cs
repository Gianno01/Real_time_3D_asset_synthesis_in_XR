// ObjectCollision.cs
// Collisione tra gli oggetti della scena mentre ne tieni uno in mano (aggiunto da QuestObjectGenerator).
//
// Gli oggetti hanno un Rigidbody kinematico che segue la mano: da soli si attraverserebbero. Qui, finché l'oggetto è afferrato,
// ogni frame (dopo che la presa lo ha spostato) si controlla se il suo collider entra in quello di un altro oggetto
// e lo si spinge fuori lungo il percorso più breve (Physics.ComputePenetration). Risultato: un bicchiere spinto verso il basso
// si ferma sul piano del tavolo, spinto di lato scivola lungo il bordo; non serve allinearli a mano.
//
// Note:
//  • il collider di ogni oggetto è un unico box che avvolge tutta la sagoma (lo crea QuestObjectGenerator):
//    quindi un tavolo è un blocco pieno e sotto il piano non si può infilare un altro oggetto;
//  • gli oggetti bloccati (SceneObject.locked) restano ostacoli, ma non vengono mai spostati;
//  • si attiva/disattiva dalle Impostazioni (QuestObjectGenerator.objectCollisions, di default acceso).

using UnityEngine;
using UnityEngine.XR.Interaction.Toolkit.Interactables;

public class ObjectCollision : MonoBehaviour
{
    [Tooltip("Quante volte si ripete la correzione per frame (serve quando si tocca più di un oggetto)")]
    public int iterations = 4;
    [Tooltip("Distanza lasciata tra due oggetti a contatto (m)")]
    public float skin = 0.001f;

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

    void LateUpdate() { if (IsHeld) Resolve(); }

    void OnBeforeRender() { if (IsHeld) Resolve(); }

    bool IsHeld => enabled && _grab != null && _grab.isSelected;

    /// <summary>Spinge fuori l'oggetto da quelli che sta attraversando (usato anche dopo l'aggancio al rilascio).</summary>
    public void ResolveNow() { if (enabled) Resolve(); }

    void Resolve()
    {
        if (_col == null) _col = GetComponent<Collider>();
        if (_col == null || !_col.enabled) return;
        if (_so == null) _so = GetComponent<SceneObject>();
        if (_so != null && _so.locked) return;

        var tr = transform;
        for (int it = 0; it < Mathf.Max(1, iterations); it++)
        {
            bool any = false;
            var all = SceneObject.All;
            for (int i = 0; i < all.Count; i++)
            {
                var other = all[i];
                if (other == null || other.gameObject == gameObject) continue;
                var oc = other.GetComponent<Collider>();
                if (oc == null || !oc.enabled || !oc.gameObject.activeInHierarchy) continue;

                if (Physics.ComputePenetration(_col, tr.position, tr.rotation,
                                               oc, oc.transform.position, oc.transform.rotation,
                                               out Vector3 dir, out float dist))
                {
                    tr.position += dir * (dist + skin);
                    any = true;
                }
            }
            if (!any) break;
        }
    }
}
