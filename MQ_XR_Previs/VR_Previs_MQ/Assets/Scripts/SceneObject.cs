// SceneObject.cs
// Dati di un oggetto presente nella scena (aggiunto da QuestObjectGenerator e da AssetLibrary).
// Serve a salvarlo nell'inventario, a ricordarne la posizione nelle scene e a eliminarlo/duplicarlo.

using System;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.Interaction.Toolkit.Interactables;

public class SceneObject : MonoBehaviour
{
    /// <summary>Tutti gli oggetti attualmente nella scena.</summary>
    public static readonly List<SceneObject> All = new List<SceneObject>();
    /// <summary>Un oggetto è stato rilasciato dopo essere stato preso (→ barra Salva / Duplica / Elimina).</summary>
    public static event Action<SceneObject> Selected;

    [Header("Server")]
    [Tooltip("Id sul server. Vuoto = oggetto appena generato, non ancora salvato")]
    public string assetId = "";
    public bool inInventory;
    public string glbKey = "";     // percorso nello storage (oggetti già salvati)
    public string thumbKey = "";

    [Header("Origine (oggetti appena generati)")]
    public string sourceGlbPath = "";    // ComfyUI: /view?filename=...
    public string sourceImagePath = "";

    [Header("Descrizione")]
    public string displayName = "";
    public string objectName = "";
    public string promptIt = "";
    public string promptEn = "";
    public string category = "";
    public string style = "";
    public string model = "";
    public string placedBy = "";
    public float genImageSeconds, genModelSeconds;

    [NonSerialized] public Texture2D thumbnail;   // miniatura 256 px (solo oggetti generati in questa sessione)

    public bool IsSaved => !string.IsNullOrEmpty(assetId);

    /// <summary>Dimensioni reali attuali (m): larghezza, altezza, profondità.</summary>
    public Vector3 SizeMeters
    {
        get
        {
            var aids = GetComponent<ObjectPlacementAids>();
            return aids != null ? aids.CurrentSize() : Vector3.zero;
        }
    }

    XRGrabInteractable _grab;

    void OnEnable() { if (!All.Contains(this)) All.Add(this); }
    void OnDisable() { All.Remove(this); }

    void Start()
    {
        _grab = GetComponent<XRGrabInteractable>();
        if (_grab != null)
            _grab.selectExited.AddListener(_ => { if (!_grab.isSelected) Selected?.Invoke(this); });
    }

    /// <summary>Copia i dati descrittivi da un altro oggetto (usato da Duplica).</summary>
    public void CopyFrom(SceneObject o)
    {
        assetId = o.assetId; inInventory = o.inInventory; glbKey = o.glbKey; thumbKey = o.thumbKey;
        sourceGlbPath = o.sourceGlbPath; sourceImagePath = o.sourceImagePath;
        displayName = o.displayName; objectName = o.objectName; promptIt = o.promptIt; promptEn = o.promptEn;
        category = o.category; style = o.style; model = o.model; placedBy = o.placedBy;
        genImageSeconds = o.genImageSeconds; genModelSeconds = o.genModelSeconds;
        thumbnail = o.thumbnail;
    }
}
