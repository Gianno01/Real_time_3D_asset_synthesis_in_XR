// AssetLibrary.cs
// Libreria condivisa: inventario degli oggetti e scene salvate sul server.
//
//   n8n   POST {libraryUrl}  { action: save_asset | list_assets | delete_asset | save_scene | list_scenes | load_scene | delete_scene, ... }
//   file  GET  {storageUrl}/assets/<id>/model.glb | image.png | thumb.jpg   (nginx in sola lettura davanti a SeaweedFS)
//
// I GLB scaricati restano in cache sul visore (Application.persistentDataPath/xrcache): ogni file si scarica una volta sola.
// Le posizioni delle scene sono salvate rispetto a sceneAnchor (di default l'origine del pavimento dell'XR Origin).
//
// SETUP: GameObject vuoto (es. "Library") con AssetLibrary + LibraryUI. Imposta Library Url e Storage Url con l'IP del PC.

using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Text;
using Unity.XR.CoreUtils;
using UnityEngine;
using UnityEngine.Networking;

[Serializable]
public class AssetRecord
{
    public string id = "", name = "", category = "", style = "";
    public string[] tags;
    public string prompt_it = "", prompt_en = "", object_name = "", model = "";
    public string glb_key = "", image_key = "", thumb_key = "";
    public float width_cm, height_cm, depth_cm;
    public long glb_bytes;
    public string author = "";
    public bool in_inventory;
    public int use_count;
    public string created_at = "";
    public float score;
}

[Serializable]
public class SceneInfo
{
    public string id = "", name = "", author = "";
    public int object_count;
    public string updated_at = "";
}

[Serializable]
public class SceneObjectRecord
{
    public string asset_id = "", name = "", object_name = "", prompt_it = "", prompt_en = "", category = "", style = "";
    public string glb_key = "", image_key = "", thumb_key = "";
    public bool in_inventory;
    public float width_cm, height_cm, depth_cm;
    public float px, py, pz, rx, ry, rz, rw, scale;
    public string placed_by = "";
}

[Serializable]
public class AssetListResult
{
    public bool ok;
    public string mode = "";   // list | text (parole simili) | semantic (Qdrant)
    public List<AssetRecord> items = new List<AssetRecord>();
    public int total;
    public List<string> styles = new List<string>();
}

public class AssetLibrary : MonoBehaviour
{
    [Header("Server")]
    [Tooltip("Webhook n8n della libreria (workflow \"Quest - Libreria\")")]
    public string libraryUrl = "http://192.168.50.133:5678/webhook/quest-library";
    [Tooltip("Storage dei file (nginx davanti a SeaweedFS)")]
    public string storageUrl = "http://192.168.50.133:8090";
    public int timeoutSeconds = 60;

    [Header("Suggerimenti prima di generare")]
    [Tooltip("Somiglianza minima (ricerca semantica, 0-1) per proporre un oggetto già esistente")]
    [Range(0f, 1f)] public float suggestMinScore = 0.65f;
    [Tooltip("Somiglianza minima quando Qdrant non risponde e si usa la ricerca per parole")]
    [Range(0f, 1f)] public float suggestMinTextScore = 0.5f;
    [Range(1, 6)] public int suggestCount = 3;
    [Tooltip("Oltre questo tempo si rinuncia ai suggerimenti e si genera subito")]
    public int suggestTimeoutSeconds = 6;

    [Header("Riferimenti (se vuoti vengono cercati)")]
    public QuestObjectGenerator generator;
    [Tooltip("Le posizioni delle scene sono salvate rispetto a questo transform. Vuoto = XR Origin (pavimento)")]
    public Transform sceneAnchor;
    [Tooltip("Calibrazione a due punti: origine uguale a ogni avvio. Vuoto = viene creata da sola")]
    public RoomCalibration roomCalibration;

    [Header("Autore")]
    [Tooltip("Nome di chi salva. Vuoto = nome del visore")]
    public string authorName = "";

    public string Author => string.IsNullOrWhiteSpace(authorName) ? SystemInfo.deviceName : authorName;

    /// <summary>Scena caricata o salvata per ultima ("" = scena nuova, mai salvata).</summary>
    public string CurrentSceneId { get; private set; } = "";
    public string CurrentSceneName { get; private set; } = "";
    /// <summary>Stili già usati nell'inventario (aggiornati a ogni List).</summary>
    public List<string> KnownStyles { get; private set; } = new List<string>();
    public bool Busy { get; private set; }

    /// <summary>Inventario o scene cambiati (salvataggio, eliminazione).</summary>
    public event Action Changed;

    readonly Dictionary<string, Texture2D> _thumbCache = new Dictionary<string, Texture2D>();
    string CacheDir => Path.Combine(Application.persistentDataPath, "xrcache");

    // ── Strutture delle richieste/risposte ────────────────────────────

    [Serializable]
    class Req
    {
        public string action = "", author = "";
        public string asset_id = "", name = "", category = "", style = "";
        public string[] tags = new string[0];
        public string prompt_it = "", prompt_en = "", object_name = "", model = "";
        public string source_glb = "", source_image = "", thumb_base64 = "";
        public float width_cm, height_cm, depth_cm, gen_image_s, gen_model_s;
        public bool in_inventory;
        public string q = "";
        public int limit, offset;
        public float min_score;
        public string scene_id = "";
        public List<ObjOut> objects = new List<ObjOut>();
    }
    [Serializable] class ObjOut { public string asset_id = "", placed_by = ""; public float px, py, pz, rx, ry, rz, rw, scale; }
    [Serializable] class AssetResp { public bool ok; public string error; public AssetRecord asset; }
    [Serializable] class OkResp { public bool ok; public string error; }
    [Serializable] class SaveSceneResp { public bool ok; public string error; public string scene_id; public string name; public int saved; }
    [Serializable] class ScenesResp { public bool ok; public List<SceneInfo> scenes = new List<SceneInfo>(); }
    [Serializable] class LoadSceneResp { public bool ok; public string error; public SceneInfo scene; public List<SceneObjectRecord> objects = new List<SceneObjectRecord>(); }
    [Serializable] class N8nError { public string message; }

    // ── Avvio ─────────────────────────────────────────────────────────

    void Awake()
    {
        if (generator == null) generator = FindAnyObjectByType<QuestObjectGenerator>();
        bool customAnchor = sceneAnchor != null;   // ancora scelta a mano nell'Inspector (es. colocation): niente origine automatica
        if (sceneAnchor == null)
        {
            var origin = FindAnyObjectByType<XROrigin>();
            sceneAnchor = origin != null ? origin.transform : null;
        }
        if (roomCalibration == null) roomCalibration = FindAnyObjectByType<RoomCalibration>();
        if (roomCalibration == null)
        {
            roomCalibration = gameObject.AddComponent<RoomCalibration>();
            roomCalibration.library = this;
            if (customAnchor) roomCalibration.required = false;   // ancora scelta a mano: niente calibrazione
        }
        try { Directory.CreateDirectory(CacheDir); } catch (Exception e) { Debug.LogWarning($"[Library] Cache non disponibile: {e.Message}"); }
    }

    // ── Inventario ────────────────────────────────────────────────────

    /// <summary>Salva un oggetto della scena. toInventory = visibile nell'inventario; false = solo per le scene.</summary>
    public IEnumerator SaveObject(SceneObject obj, bool toInventory, string name, string category, string style, Action<bool, string> done)
    {
        if (obj == null) { done(false, "Oggetto non valido"); yield break; }

        var req = new Req
        {
            action = "save_asset", author = Author, in_inventory = toInventory,
            name = string.IsNullOrWhiteSpace(name) ? obj.displayName : name.Trim(),
            category = category ?? obj.category, style = style ?? obj.style,
        };

        bool wasSaved = obj.IsSaved;
        string srcPath = obj.sourceGlbPath;
        if (wasSaved)
        {
            req.asset_id = obj.assetId;   // già sul server: aggiorna dati / inventario
        }
        else
        {
            if (string.IsNullOrEmpty(obj.sourceGlbPath)) { done(false, "Manca il file dell'oggetto"); yield break; }
            Vector3 size = obj.SizeMeters;
            req.prompt_it = obj.promptIt; req.prompt_en = obj.promptEn; req.object_name = obj.objectName; req.model = obj.model;
            req.source_glb = obj.sourceGlbPath; req.source_image = obj.sourceImagePath;
            req.width_cm = size.x * 100f; req.height_cm = size.y * 100f; req.depth_cm = size.z * 100f;
            req.gen_image_s = obj.genImageSeconds; req.gen_model_s = obj.genModelSeconds;
            if (obj.thumbnail != null)
            {
                try { req.thumb_base64 = Convert.ToBase64String(obj.thumbnail.EncodeToJPG(80)); }
                catch (Exception e) { Debug.LogWarning($"[Library] Miniatura non codificata: {e.Message}"); }
            }
        }

        string body = null, error = null;
        yield return StartCoroutine(Post(req, (b, e) => { body = b; error = e; }));
        var r = Parse<AssetResp>(body);
        if (error != null || r == null || !r.ok || r.asset == null) { done(false, error ?? r?.error ?? "Salvataggio non confermato"); yield break; }

        // l'oggetto e tutte le sue copie (stesso id, oppure duplicati non ancora salvati dello stesso GLB)
        ApplyRecord(obj, r.asset);
        foreach (var o in SceneObject.All.ToArray())
        {
            bool sameAsset = o.assetId == r.asset.id;
            bool unsavedCopy = !wasSaved && !o.IsSaved && !string.IsNullOrEmpty(srcPath) && o.sourceGlbPath == srcPath;
            if (o != obj && (sameAsset || unsavedCopy)) ApplyRecord(o, r.asset);
        }
        Changed?.Invoke();
        done(true, null);
    }

    public IEnumerator List(string q, string category, string style, int offset, int limit, Action<AssetListResult, string> done)
    {
        var req = new Req { action = "list_assets", q = q ?? "", category = category ?? "", style = style ?? "", offset = offset, limit = limit };
        string body = null, error = null;
        yield return StartCoroutine(Post(req, (b, e) => { body = b; error = e; }));
        var r = Parse<AssetListResult>(body);
        if (error != null || r == null || !r.ok) { done(null, error ?? "Risposta non valida"); yield break; }
        KnownStyles = r.styles ?? new List<string>();
        done(r, null);
    }

    /// <summary>Oggetti dell'inventario simili alla richiesta (vuoto se nessuno o se il server non risponde in tempo).</summary>
    public IEnumerator Suggest(string prompt, Action<List<AssetRecord>> done)
    {
        var found = new List<AssetRecord>();
        if (string.IsNullOrWhiteSpace(prompt)) { done(found); yield break; }

        var req = new Req { action = "list_assets", q = prompt.Trim(), limit = suggestCount, min_score = suggestMinScore };
        string body = null, error = null;
        yield return StartCoroutine(Post(req, (b, e) => { body = b; error = e; }, suggestTimeoutSeconds));
        var r = Parse<AssetListResult>(body);
        if (error != null || r == null || !r.ok || r.items == null)
        {
            if (error != null) Debug.LogWarning($"[Library] Suggerimenti non disponibili: {error}");
            done(found); yield break;
        }
        float min = r.mode == "semantic" ? suggestMinScore : suggestMinTextScore;
        foreach (var a in r.items)
            if (a != null && a.score >= min && !string.IsNullOrEmpty(a.glb_key) && found.Count < suggestCount) found.Add(a);
        done(found);
    }

    public IEnumerator DeleteAsset(string assetId, Action<bool, string> done)
    {
        string body = null, error = null;
        yield return StartCoroutine(Post(new Req { action = "delete_asset", asset_id = assetId }, (b, e) => { body = b; error = e; }));
        var r = Parse<OkResp>(body);
        bool ok = error == null && r != null && r.ok;
        if (ok)
        {
            foreach (var o in SceneObject.All) if (o.assetId == assetId) o.inInventory = false;
            Changed?.Invoke();
        }
        done(ok, ok ? null : error ?? r?.error ?? "Eliminazione non confermata");
    }

    /// <summary>Inserisce davanti all'utente un oggetto dell'inventario.</summary>
    public IEnumerator SpawnFromInventory(AssetRecord a, Action<SceneObject, string> done)
    {
        GameObject go = null; string error = null;
        yield return StartCoroutine(LoadAssetObject(a.glb_key, a.name, g => go = g, e => error = e));
        if (go == null) { done(null, error); yield break; }

        generator.PrepareObject(go);   // davanti all'utente, afferrabile, griglia/misure/aggancio
        ApplyStoredSize(go, a);        // PrepareObject porta tutto a ~30 cm: si torna alla misura salvata
        var so = go.GetComponent<SceneObject>();
        if (so == null) so = go.AddComponent<SceneObject>();
        ApplyRecord(so, a);
        so.placedBy = Author;
        done(so, null);
    }

    // ── Scena ─────────────────────────────────────────────────────────

    /// <summary>Elimina un oggetto dalla scena (non dall'inventario).</summary>
    public void DeleteObject(SceneObject o)
    {
        if (o != null) Destroy(o.gameObject);
    }

    /// <summary>Duplica un oggetto accanto all'originale.</summary>
    public SceneObject Duplicate(SceneObject o)
    {
        if (o == null) return null;
        Vector3 offset = Vector3.right * Mathf.Max(0.1f, o.SizeMeters.x * 1.1f);
        if (generator != null && generator.Head != null)
            offset = Vector3.ProjectOnPlane(generator.Head.right, Vector3.up).normalized * Mathf.Max(0.1f, o.SizeMeters.x * 1.1f);

        var copy = Instantiate(o.gameObject, o.transform.position + offset, o.transform.rotation);
        copy.name = o.gameObject.name + "_copia";
        var so = copy.GetComponent<SceneObject>();
        so.CopyFrom(o);
        so.placedBy = Author;
        return so;
    }

    /// <summary>Rimuove tutti gli oggetti dalla scena e inizia una scena nuova.</summary>
    public void ClearScene()
    {
        foreach (var o in SceneObject.All.ToArray()) Destroy(o.gameObject);
        CurrentSceneId = "";
        CurrentSceneName = "";
    }

    /// <summary>Salvare/caricare scene richiede la stanza calibrata (altrimenti le posizioni sarebbero sbagliate): se manca, parte la procedura.</summary>
    bool OriginReady(out string why)
    {
        why = null;
        if (roomCalibration == null || !roomCalibration.required || roomCalibration.IsCalibrated) return true;
        roomCalibration.Begin();
        why = "Prima calibra la stanza: segui le istruzioni davanti a te (tocca due punti fissi con il controller destro), poi riprova.";
        return false;
    }

    /// <summary>Salva la scena: prima gli oggetti non ancora sul server (solo per la scena), poi le posizioni.</summary>
    public IEnumerator SaveScene(string name, bool asNew, Action<bool, string> done, Action<string> progress = null)
    {
        if (Busy) { done(false, "Operazione in corso"); yield break; }
        Busy = true;
        try
        {
            if (!OriginReady(out string originErr)) { done(false, originErr); yield break; }

            var objects = new List<SceneObject>(SceneObject.All);

            // 1) oggetti mai salvati → sul server (non compaiono nell'inventario)
            var pending = objects.FindAll(o => !o.IsSaved);
            for (int i = 0; i < pending.Count; i++)
            {
                if (pending[i] == null || pending[i].IsSaved) continue;   // salvato insieme a una sua copia
                progress?.Invoke($"Salvo gli oggetti nuovi ({i + 1}/{pending.Count})...");
                bool ok = false; string err = null;
                yield return StartCoroutine(SaveObject(pending[i], false, pending[i].displayName, pending[i].category, pending[i].style, (s, e) => { ok = s; err = e; }));
                if (!ok) { done(false, $"Oggetto \"{pending[i].displayName}\": {err}"); yield break; }
            }

            // 2) posizioni rispetto all'ancora
            progress?.Invoke("Salvo la scena...");
            var req = new Req
            {
                action = "save_scene", author = Author,
                scene_id = asNew ? "" : CurrentSceneId,
                name = string.IsNullOrWhiteSpace(name) ? (asNew || string.IsNullOrEmpty(CurrentSceneName) ? DefaultSceneName() : CurrentSceneName) : name.Trim(),
            };
            foreach (var o in objects)
            {
                if (o == null || !o.IsSaved) continue;
                Vector3 p = sceneAnchor != null ? sceneAnchor.InverseTransformPoint(o.transform.position) : o.transform.position;
                Quaternion q = sceneAnchor != null ? Quaternion.Inverse(sceneAnchor.rotation) * o.transform.rotation : o.transform.rotation;
                req.objects.Add(new ObjOut
                {
                    asset_id = o.assetId, placed_by = string.IsNullOrEmpty(o.placedBy) ? Author : o.placedBy,
                    px = p.x, py = p.y, pz = p.z, rx = q.x, ry = q.y, rz = q.z, rw = q.w,
                    scale = o.transform.localScale.x
                });
            }

            string body = null, error = null;
            yield return StartCoroutine(Post(req, (b, e) => { body = b; error = e; }));
            var r = Parse<SaveSceneResp>(body);
            if (error != null || r == null || !r.ok) { done(false, error ?? r?.error ?? "Salvataggio della scena non confermato"); yield break; }

            CurrentSceneId = r.scene_id;
            CurrentSceneName = r.name;
            Changed?.Invoke();
            done(true, null);
        }
        finally { Busy = false; }
    }

    public IEnumerator ListScenes(Action<List<SceneInfo>, string> done)
    {
        string body = null, error = null;
        yield return StartCoroutine(Post(new Req { action = "list_scenes" }, (b, e) => { body = b; error = e; }));
        var r = Parse<ScenesResp>(body);
        if (error != null || r == null || !r.ok) { done(null, error ?? "Risposta non valida"); yield break; }
        done(r.scenes, null);
    }

    /// <summary>Carica una scena. replace = rimuove prima gli oggetti presenti.</summary>
    public IEnumerator LoadScene(string sceneId, bool replace, Action<bool, string> done, Action<string> progress = null)
    {
        if (Busy) { done(false, "Operazione in corso"); yield break; }
        Busy = true;
        try
        {
            if (!OriginReady(out string originErr)) { done(false, originErr); yield break; }

            string body = null, error = null;
            yield return StartCoroutine(Post(new Req { action = "load_scene", scene_id = sceneId }, (b, e) => { body = b; error = e; }));
            var r = Parse<LoadSceneResp>(body);
            if (error != null || r == null || !r.ok) { done(false, error ?? r?.error ?? "Scena non trovata"); yield break; }

            if (replace) ClearScene();
            int failed = 0;
            for (int i = 0; i < r.objects.Count; i++)
            {
                var rec = r.objects[i];
                progress?.Invoke($"Carico gli oggetti ({i + 1}/{r.objects.Count})...");
                GameObject go = null;
                yield return StartCoroutine(LoadAssetObject(rec.glb_key, rec.name, g => go = g, e => Debug.LogWarning($"[Library] {rec.name}: {e}")));
                if (go == null) { failed++; continue; }

                generator.PrepareObject(go);   // collider, presa, griglia/misure/aggancio (poi la posa salvata)
                var q = new Quaternion(rec.rx, rec.ry, rec.rz, rec.rw);
                if (q.x == 0f && q.y == 0f && q.z == 0f && q.w == 0f) q = Quaternion.identity;
                go.transform.localScale = Vector3.one * (rec.scale > 0f ? rec.scale : 1f);
                if (sceneAnchor != null)
                    go.transform.SetPositionAndRotation(sceneAnchor.TransformPoint(new Vector3(rec.px, rec.py, rec.pz)), sceneAnchor.rotation * q);
                else
                    go.transform.SetPositionAndRotation(new Vector3(rec.px, rec.py, rec.pz), q);

                var so = go.GetComponent<SceneObject>();
                if (so == null) so = go.AddComponent<SceneObject>();
                so.assetId = rec.asset_id; so.inInventory = rec.in_inventory; so.glbKey = rec.glb_key; so.thumbKey = rec.thumb_key;
                so.displayName = rec.name; so.objectName = rec.object_name; so.promptIt = rec.prompt_it; so.promptEn = rec.prompt_en;
                so.category = rec.category; so.style = rec.style; so.placedBy = rec.placed_by;
            }

            CurrentSceneId = r.scene.id;
            CurrentSceneName = r.scene.name;
            done(failed == 0, failed == 0 ? null : $"{failed} oggetti non caricati");
        }
        finally { Busy = false; }
    }

    public IEnumerator DeleteScene(string sceneId, Action<bool, string> done)
    {
        string body = null, error = null;
        yield return StartCoroutine(Post(new Req { action = "delete_scene", scene_id = sceneId }, (b, e) => { body = b; error = e; }));
        var r = Parse<OkResp>(body);
        bool ok = error == null && r != null && r.ok;
        if (ok && sceneId == CurrentSceneId) { CurrentSceneId = ""; CurrentSceneName = ""; }
        if (ok) Changed?.Invoke();
        done(ok, ok ? null : error ?? "Eliminazione non confermata");
    }

    public static string DefaultSceneName() => $"Scena {DateTime.Now:dd/MM HH:mm}";

    // ── File: GLB con cache sul visore, miniature in memoria ─────────

    IEnumerator LoadAssetObject(string glbKey, string name, Action<GameObject> ok, Action<string> fail)
    {
        byte[] data = null; string error = null;
        yield return StartCoroutine(GetGlb(glbKey, (d, e) => { data = d; error = e; }));
        if (data == null) { fail(error ?? "GLB non disponibile"); yield break; }

        GameObject go = null;
        yield return StartCoroutine(generator.InstantiateGlb(data, StorageUrl(glbKey), $"LIB_{name}", (g, e) => { go = g; error = e; }));
        if (go == null) { fail(error ?? "GLB non valido"); yield break; }
        ok(go);
    }

    public IEnumerator GetGlb(string key, Action<byte[], string> done)
    {
        if (string.IsNullOrEmpty(key)) { done(null, "Percorso del file mancante"); yield break; }
        string path = Path.Combine(CacheDir, key.Replace('/', '_'));
        if (File.Exists(path))
        {
            byte[] cached = null;
            try { cached = File.ReadAllBytes(path); } catch (Exception e) { Debug.LogWarning($"[Library] Cache illeggibile: {e.Message}"); }
            if (cached != null && cached.Length > 0) { done(cached, null); yield break; }
        }

        using var r = UnityWebRequest.Get(StorageUrl(key));
        r.timeout = timeoutSeconds;
        yield return r.SendWebRequest();
        if (r.result != UnityWebRequest.Result.Success) { done(null, $"Download: {r.error} (HTTP {r.responseCode})"); yield break; }

        byte[] data = r.downloadHandler.data;
        try { File.WriteAllBytes(path, data); } catch (Exception e) { Debug.LogWarning($"[Library] Cache non scritta: {e.Message}"); }
        done(data, null);
    }

    public IEnumerator GetThumbnail(string key, Action<Texture2D> done)
    {
        if (string.IsNullOrEmpty(key)) { done(null); yield break; }
        if (_thumbCache.TryGetValue(key, out var cached) && cached != null) { done(cached); yield break; }

        using var r = UnityWebRequestTexture.GetTexture(StorageUrl(key));
        r.timeout = 20;
        yield return r.SendWebRequest();
        if (r.result != UnityWebRequest.Result.Success) { done(null); yield break; }
        var tex = DownloadHandlerTexture.GetContent(r);
        _thumbCache[key] = tex;
        done(tex);
    }

    /// <summary>Riporta l'oggetto all'altezza registrata nell'inventario (salvata dal visore o impostata dal pannello web).</summary>
    static void ApplyStoredSize(GameObject go, AssetRecord a)
    {
        if (a.height_cm <= 0.5f) return;
        Bounds before = WorldBounds(go);
        if (before.size.y < 0.0001f) return;
        float k = (a.height_cm / 100f) / before.size.y;   // l'altezza non cambia ruotando l'oggetto attorno a Y
        if (Mathf.Abs(k - 1f) < 0.01f) return;
        go.transform.localScale *= k;
        Bounds after = WorldBounds(go);
        go.transform.position += before.center - after.center;   // resta centrato dove era stato messo
    }

    static Bounds WorldBounds(GameObject go)
    {
        var rs = go.GetComponentsInChildren<Renderer>();
        bool has = false;
        var b = new Bounds(go.transform.position, Vector3.zero);
        foreach (var r in rs)
        {
            if (r.bounds.size.sqrMagnitude <= 0f) continue;
            if (!has) { b = r.bounds; has = true; } else b.Encapsulate(r.bounds);
        }
        return b;
    }

    public string StorageUrl(string key) => storageUrl.TrimEnd('/') + "/" + key.TrimStart('/');

    static void ApplyRecord(SceneObject o, AssetRecord a)
    {
        o.assetId = a.id; o.inInventory = a.in_inventory; o.glbKey = a.glb_key; o.thumbKey = a.thumb_key;
        if (!string.IsNullOrEmpty(a.name)) o.displayName = a.name;
        if (!string.IsNullOrEmpty(a.category)) o.category = a.category;
        if (!string.IsNullOrEmpty(a.style)) o.style = a.style;
        if (!string.IsNullOrEmpty(a.object_name)) o.objectName = a.object_name;
        if (!string.IsNullOrEmpty(a.prompt_it)) o.promptIt = a.prompt_it;
        if (!string.IsNullOrEmpty(a.prompt_en)) o.promptEn = a.prompt_en;
    }

    // ── HTTP ──────────────────────────────────────────────────────────

    IEnumerator Post(Req req, Action<string, string> done, int timeout = 0)
    {
        if (string.IsNullOrEmpty(req.author)) req.author = Author;
        string json = JsonUtility.ToJson(req);
        using var r = new UnityWebRequest(libraryUrl, "POST");
        r.uploadHandler = new UploadHandlerRaw(Encoding.UTF8.GetBytes(json));
        r.downloadHandler = new DownloadHandlerBuffer();
        r.SetRequestHeader("Content-Type", "application/json");
        r.timeout = timeout > 0 ? timeout : timeoutSeconds;
        yield return r.SendWebRequest();

        string body = r.downloadHandler?.text ?? "";
        if (r.result != UnityWebRequest.Result.Success)
        {
            string msg = Parse<N8nError>(body)?.message;
            done(null, $"{(string.IsNullOrEmpty(msg) ? r.error : msg)} (HTTP {r.responseCode})");
        }
        else done(body, null);
    }

    static T Parse<T>(string json) where T : class
    {
        if (string.IsNullOrEmpty(json)) return null;
        try { return JsonUtility.FromJson<T>(json); }
        catch (Exception e) { Debug.LogWarning($"[Library] JSON non valido: {e.Message}"); return null; }
    }
}
