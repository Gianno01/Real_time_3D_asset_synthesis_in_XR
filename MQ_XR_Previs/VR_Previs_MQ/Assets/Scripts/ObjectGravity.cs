// ObjectGravity.cs
// Gravità opzionale: quando lasci un oggetto, cade fino a posarsi su un altro oggetto, su un mobile reale (se c'è
// SceneOcclusion) o sul pavimento. Si attiva dalle Impostazioni (QuestObjectGenerator.objectGravity, di default spento).
//
// La caduta è calcolata a mano (gli oggetti restano kinematici, niente simulazione fisica del Quest):
//  • a piccoli passi di 1 cm, così un oggetto sottile non attraversa un piano;
//  • l'appoggio sugli altri oggetti usa ObjectCollision (se la collisione è accesa), il pavimento è sempre un limite;
//  • se riprendi l'oggetto in mano, la caduta si ferma; gli oggetti bloccati non cadono.
// Gli oggetti già a mezz'aria quando accendi la gravità restano lì finché non li sposti.

using System.Collections;
using UnityEngine;
using UnityEngine.XR.Interaction.Toolkit.Interactables;

public class ObjectGravity : MonoBehaviour
{
    public float gravity = 9.81f;
    [Tooltip("Velocità massima di caduta (m/s)")]
    public float maxSpeed = 6f;
    [Tooltip("Attesa dopo il rilascio, per lasciar finire l'aggancio (s)")]
    public float startDelay = 0.2f;

    const float Step = 0.01f;

    XRGrabInteractable _grab;
    SceneObject _so;
    ObjectCollision _coll;
    ObjectPlacementAids _aids;
    Collider _col;
    Coroutine _fall;

    void Start()
    {
        _grab = GetComponent<XRGrabInteractable>();
        _so = GetComponent<SceneObject>();
        _coll = GetComponent<ObjectCollision>();
        _aids = GetComponent<ObjectPlacementAids>();
        _col = GetComponent<Collider>();
        if (_grab != null)
        {
            _grab.selectEntered.AddListener(_ => StopFall());
            _grab.selectExited.AddListener(_ => { if (!_grab.isSelected) Drop(); });
        }
    }

    void OnDisable() { StopFall(); }

    /// <summary>Fa cadere l'oggetto (se la gravità è accesa e l'oggetto non è bloccato).</summary>
    public void Drop()
    {
        if (!isActiveAndEnabled || (_so != null && _so.locked)) return;
        StopFall();
        _fall = StartCoroutine(FallRoutine());
    }

    void StopFall()
    {
        if (_fall != null) { StopCoroutine(_fall); _fall = null; }
    }

    IEnumerator FallRoutine()
    {
        yield return new WaitForSeconds(startDelay);
        float v = 0f;
        while (true)
        {
            if ((_grab != null && _grab.isSelected) || (_so != null && _so.locked)) break;

            v = Mathf.Min(maxSpeed, v + gravity * Time.deltaTime);
            float dy = v * Time.deltaTime;
            int steps = Mathf.Max(1, Mathf.CeilToInt(dy / Step));
            bool landed = false;
            for (int i = 0; i < steps && !landed; i++)
            {
                transform.position += Vector3.down * (dy / steps);
                landed = TryLand();
            }
            if (landed) break;
            yield return null;
        }
        _fall = null;
    }

    // true se l'oggetto ora poggia su qualcosa
    bool TryLand()
    {
        if (_coll != null && _coll.enabled && _coll.Depenetrate(true)) return true;

        if (_col != null)
        {
            Physics.SyncTransforms();
            float floor = _aids != null ? _aids.floorHeight : 0f;
            float bottom = _col.bounds.min.y;
            if (bottom <= floor)
            {
                transform.position += Vector3.up * (floor - bottom);
                return true;
            }
        }
        return false;
    }
}
