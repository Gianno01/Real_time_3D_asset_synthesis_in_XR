// ARObjectGenerator.cs
// Compatibile con: MRTK Foundation 2.x + Unity 2022.3 LTS + GLTFast
//
// SETUP:
//   1. Crea cartella Assets/Scripts nel progetto Unity
//   2. Copia questo file in Assets/Scripts/ARObjectGenerator.cs
//   3. Aggiungi il componente al GameObject MixedRealitySceneContent
//   4. Imposta N8nWebhookUrl nell'Inspector con l'IP del tuo PC
//
// DIPENDENZE (installa via Package Manager):
//   - GLTFast: com.unity.cloud.gltfast
//   - Newtonsoft Json: com.unity.nuget.newtonsoft-json

using System;
using System.Collections;
using System.Text;
using UnityEngine;
using UnityEngine.Networking;
using GLTFast;
using Microsoft.MixedReality.Toolkit.Input;
using Microsoft.MixedReality.Toolkit;


public class ARObjectGenerator : MonoBehaviour, IMixedRealitySpeechHandler
{
    [Header("Configurazione n8n")]
    [Tooltip("URL webhook n8n — es. http://10.54.128.33:5678/webhook-test/hololens-generate")]
    public string n8nWebhookUrl = "http://10.54.128.33:5678/webhook-test/hololens-generate";

    [Tooltip("Timeout totale pipeline AI in secondi")]
    public float timeoutSeconds = 120f;

    [Header("Posizionamento oggetto")]
    [Tooltip("Distanza dall'utente in metri")]
    public float placementDistance = 1.5f;

    [Tooltip("Dimensione target dell'oggetto in metri")]
    public float targetObjectSize = 0.3f;

    [Header("Feedback visivo")]
    public AudioClip successSound;
    public AudioClip errorSound;

    // ── Stato interno ─────────────────────────────────────────────────
    private bool _isGenerating = false;
    private AudioSource _audioSource;
    private string _sessionId;

    // ── Unity lifecycle ───────────────────────────────────────────────

    void OnEnable()
    {
        CoreServices.InputSystem?.RegisterHandler<IMixedRealitySpeechHandler>(this);
    }

    void OnDisable()
    {
        CoreServices.InputSystem?.UnregisterHandler<IMixedRealitySpeechHandler>(this);
    }

    void Awake()
    {
        Debug.Log("[ARObjectGenerator] AWAKE chiamato!");
        _audioSource = gameObject.AddComponent<AudioSource>();
        _sessionId = Guid.NewGuid().ToString("N").Substring(0, 8);

        // Auto test — parte dopo 5 secondi
        StartCoroutine(AutoTest());
    }

    private IEnumerator AutoTest()
    {
        yield return new WaitForSeconds(5f);
        Debug.Log("[ARObjectGenerator] AutoTest partito!");
        TriggerGeneration("una sedia medievale in legno");
    }

    void Start()
    {
        //_audioSource = gameObject.AddComponent<AudioSource>();
        //_sessionId = Guid.NewGuid().ToString("N").Substring(0, 8);
        //Debug.Log($"[ARObjectGenerator] Pronto. Webhook: {n8nWebhookUrl}");
        //Debug.Log("[ARObjectGenerator] Premi SPAZIO in Editor per test.");
    }

    void Update()
    {
        // Test rapido in Editor — premi Spazio
        if (Input.GetKeyDown(KeyCode.Space) && !_isGenerating)
        {
            TriggerGeneration("una sedia medievale in legno");
        }
        if (Input.GetMouseButtonDown(0) && !_isGenerating)
        {
            TriggerGeneration("una sedia medievale in legno");
        }
    }

    // ── API pubblica ──────────────────────────────────────────────────

    /// <summary>
    /// Chiamato da SpeechInputHandler MRTK o da altri script.
    /// </summary>
    public void TriggerGeneration(string prompt)
    {
        Debug.Log($"[ARObjectGenerator] TriggerGeneration CHIAMATA con: {prompt}");
        if (_isGenerating)
        {
            Debug.Log("[ARObjectGenerator] Generazione già in corso.");
            return;
        }
        if (string.IsNullOrWhiteSpace(prompt))
        {
            Debug.LogWarning("[ARObjectGenerator] Prompt vuoto.");
            return;
        }
        Debug.Log($"[ARObjectGenerator] Avvio generazione: '{prompt}'");
        StartCoroutine(RunPipeline(prompt));
    }

    /// <summary>
    /// Versione senza parametri — usabile da UnityEvent / Inspector button.
    /// </summary>
    public void TriggerGenerationDefault()
    {
        Debug.Log("[ARObjectGenerator] TriggerGenerationDefault CHIAMATA!");
        TriggerGeneration("una sedia medievale in legno");
    }

    // ── Pipeline ──────────────────────────────────────────────────────

    private IEnumerator RunPipeline(string prompt)
    {
        _isGenerating = true;
        _sessionId = Guid.NewGuid().ToString("N").Substring(0, 8);

        Debug.Log("[ARObjectGenerator] Pipeline avviata...");

        // 1. Chiama n8n
        string glbUrl = null;
        string objectName = null;
        yield return StartCoroutine(CallN8N(prompt, (url, name) =>
        {
            glbUrl = url;
            objectName = name;
        }));

        if (string.IsNullOrEmpty(glbUrl))
        {
            Debug.LogError("[ARObjectGenerator] Pipeline fallita — nessun URL ricevuto.");
            PlaySound(errorSound);
            _isGenerating = false;
            yield break;
        }

        Debug.Log($"[ARObjectGenerator] GLB URL ricevuto: {glbUrl}");

        // 2. Scarica e carica il .glb
        GameObject loadedObject = null;
        yield return StartCoroutine(LoadGLB(glbUrl, obj => loadedObject = obj));

        if (loadedObject == null)
        {
            Debug.LogError("[ARObjectGenerator] Caricamento .glb fallito.");
            PlaySound(errorSound);
            _isGenerating = false;
            yield break;
        }

        // 3. Posiziona nella scena
        PlaceObject(loadedObject);
        PlaySound(successSound);

        Debug.Log($"[ARObjectGenerator] '{objectName}' piazzato con successo!");
        _isGenerating = false;
    }

    // ── Chiamata n8n ──────────────────────────────────────────────────

    private IEnumerator CallN8N(string prompt, Action<string, string> callback)
    {
        var payload = JsonUtility.ToJson(new N8NRequest
        {
            prompt = prompt,
            session_id = _sessionId
        });

        using var request = new UnityWebRequest(n8nWebhookUrl, "POST");
        request.uploadHandler = new UploadHandlerRaw(Encoding.UTF8.GetBytes(payload));
        request.downloadHandler = new DownloadHandlerBuffer();
        request.SetRequestHeader("Content-Type", "application/json");
        request.timeout = (int)timeoutSeconds;

        Debug.Log($"[ARObjectGenerator] POST → n8n: {payload}");
        yield return request.SendWebRequest();

        if (request.result != UnityWebRequest.Result.Success)
        {
            Debug.LogError($"[ARObjectGenerator] Errore HTTP: {request.error} | Code: {request.responseCode}");
            callback(null, null);
            yield break;
        }

        var responseText = request.downloadHandler.text;
        Debug.Log($"[ARObjectGenerator] Risposta n8n: {responseText}");

        try
        {
            var response = JsonUtility.FromJson<N8NResponse>(responseText);
            if (response != null && response.status == "ready" && !string.IsNullOrEmpty(response.glb_url))
            {
                callback(response.glb_url, response.object_name ?? "oggetto");
            }
            else
            {
                Debug.LogError($"[ARObjectGenerator] Risposta non valida: {responseText}");
                callback(null, null);
            }
        }
        catch (Exception e)
        {
            Debug.LogError($"[ARObjectGenerator] JSON parse fallito: {e.Message} | Raw: {responseText}");
            callback(null, null);
        }
    }

    // ── Caricamento GLB con GLTFast ───────────────────────────────────

    private IEnumerator LoadGLB(string url, Action<GameObject> callback)
    {
        Debug.Log($"[ARObjectGenerator] Download .glb da: {url}");

        using var request = UnityWebRequest.Get(url);
        request.timeout = 30;
        yield return request.SendWebRequest();

        if (request.result != UnityWebRequest.Result.Success)
        {
            Debug.LogError($"[ARObjectGenerator] Download fallito: {request.error}");
            callback(null);
            yield break;
        }

        byte[] glbData = request.downloadHandler.data;
        Debug.Log($"[ARObjectGenerator] .glb scaricato: {glbData.Length / 1024}KB");

        var gltf = new GltfImport();
        var loadTask = gltf.LoadGltfBinary(glbData, new Uri(url));
        while (!loadTask.IsCompleted)
            yield return null;

        if (!loadTask.Result)
        {
            Debug.LogError("[ARObjectGenerator] GLTFast load fallito.");
            callback(null);
            yield break;
        }

        var container = new GameObject($"AR_{_sessionId}");
        var instantiateTask = gltf.InstantiateMainSceneAsync(container.transform);
        while (!instantiateTask.IsCompleted)
            yield return null;

        if (!instantiateTask.Result)
        {
            Debug.LogError("[ARObjectGenerator] GLTFast instantiate fallito.");
            Destroy(container);
            callback(null);
            yield break;
        }

        callback(container);
    }

    // ── Posizionamento ────────────────────────────────────────────────

    private void PlaceObject(GameObject obj)
    {
        Camera cam = Camera.main;
        if (cam == null)
        {
            obj.transform.position = Vector3.forward * placementDistance;
            return;
        }

        Vector3 origin = cam.transform.position;
        Vector3 direction = cam.transform.forward;

        if (Physics.Raycast(origin, direction, out RaycastHit hit, placementDistance * 2f))
        {
            obj.transform.position = hit.point;
            Vector3 lookDir = origin - obj.transform.position;
            lookDir.y = 0;
            if (lookDir != Vector3.zero)
                obj.transform.rotation = Quaternion.LookRotation(lookDir);
        }
        else
        {
            obj.transform.position = origin + direction * placementDistance;
            obj.transform.LookAt(cam.transform);
            obj.transform.Rotate(0, 180f, 0);
        }

        NormalizeScale(obj);
        ApplyDefaultMaterial(obj);

        Debug.Log($"[ARObjectGenerator] Posizione: {obj.transform.position}");
    }

    private void NormalizeScale(GameObject obj)
    {
        var renderers = obj.GetComponentsInChildren<Renderer>();
        if (renderers.Length == 0) return;

        Bounds bounds = renderers[0].bounds;
        foreach (var r in renderers)
            bounds.Encapsulate(r.bounds);

        float maxDim = Mathf.Max(bounds.size.x, bounds.size.y, bounds.size.z);
        if (maxDim > 0.001f)
            obj.transform.localScale = Vector3.one * (targetObjectSize / maxDim);
    }

    // AGGIUNTA MATERIALE
    private void ApplyDefaultMaterial(GameObject obj)
    {
        // Crea un materiale Standard grigio chiaro
        Material defaultMat = new Material(Shader.Find("Standard"));
        defaultMat.color = new Color(0.8f, 0.8f, 0.8f, 1f);
        defaultMat.SetFloat("_Metallic", 0f);
        defaultMat.SetFloat("_Glossiness", 0.3f);

        var renderers = obj.GetComponentsInChildren<Renderer>();
        foreach (var r in renderers)
        {
            // Applica solo se il materiale è il magenta di default (mancante)
            var mats = r.materials;
            for (int i = 0; i < mats.Length; i++)
            {
                if (mats[i] == null || mats[i].name.Contains("Default-Material")
                    || mats[i].shader.name == "Hidden/InternalErrorShader")
                {
                    mats[i] = defaultMat;
                }
            }
            r.materials = mats;
        }
    }

    public void OnSpeechKeywordRecognized(SpeechEventData eventData)
    {
        Debug.Log($"[ARObjectGenerator] Parola riconosciuta: {eventData.Command.Keyword}");
        switch (eventData.Command.Keyword.ToLower())
        {
            case "create":
                TriggerGenerationDefault();
                break;
            case "close":
                Application.Quit();
                break;
        }
    }

    // ── Audio ─────────────────────────────────────────────────────────

    private void PlaySound(AudioClip clip)
    {
        if (clip != null && _audioSource != null)
            _audioSource.PlayOneShot(clip);
    }

    // ── Strutture JSON ────────────────────────────────────────────────

    [Serializable]
    private class N8NRequest
    {
        public string prompt;
        public string session_id;
    }

    [Serializable]
    private class N8NResponse
    {
        public string status;
        public string glb_url;
        public string object_name;
        public string session_id;
    }
}
