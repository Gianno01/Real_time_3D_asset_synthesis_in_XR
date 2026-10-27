// LibraryUI.cs
// Interfaccia della libreria condivisa (AssetLibrary), generata via codice.
//
//  • Cerchietto con il libro sopra il pannello di controllo → pannello "monitor" sopra di esso con due schede:
//      Inventario  filtri per categoria, ricerca a voce, griglia di miniature, Inserisci / Elimina
//      Scene       Salva / Salva come nuova / Nome a voce / Svuota, elenco delle scene con Carica / Elimina
//  • Barra sopra l'oggetto appena rilasciato: Salva (nell'inventario) · Duplica · Elimina (dalla scena)
//  • Finestra "Salva nell'inventario": nome (proposto, modificabile a voce), categoria, stile (anche nuovo, a voce)
//  • Suggerimenti: prima di generare, se l'inventario ha oggetti simili alla richiesta, si apre da solo con
//      fino a 3 proposte (miniatura, misure, somiglianza) → "Usa" oppure "Genera nuovo"
//
// Le eliminazioni chiedono conferma (secondo tocco entro 3 s).
// SETUP: sullo stesso GameObject di AssetLibrary. Richiede TextMeshPro, EventSystem con XR UI Input Module,
//        QuestObjectGenerator e GenerationStatusUI nella scena.

using System;
using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.XR.Interaction.Toolkit.Interactables;
using UnityEngine.XR.Interaction.Toolkit.UI;

public class LibraryUI : MonoBehaviour
{
    [Header("Riferimenti (se vuoti vengono cercati nella scena)")]
    public AssetLibrary library;
    public QuestObjectGenerator generator;
    public GenerationStatusUI statusUI;

    [Header("Classificazione")]
    public string[] categories = { "Personaggio", "Environment", "Decorazione", "Props" };
    public List<string> defaultStyles = new List<string>
        { "Realistico", "Moderno", "Medievale", "Rinascimentale", "Futuristico", "Fantasy", "Cartoon", "Punk" };

    [Header("Posizione rispetto al pannello di controllo")]
    public Vector3 panelOffset = new Vector3(0f, 0.50f, 0.10f);
    [Tooltip("Rotazione del monitor rispetto al pannello di controllo (negativo = più verticale)")]
    public float panelTilt = -30f;
    public Vector3 dockOffset = new Vector3(0.40f, 0f, 0f);

    [Header("Barra sopra l'oggetto")]
    public float toolbarSeconds = 8f;

    // ── Palette ───────────────────────────────────────────────────────

    static readonly Color CardBg   = new Color(0.07f, 0.08f, 0.11f, 0.94f);
    static readonly Color TileBg   = new Color(1f, 1f, 1f, 0.06f);
    static readonly Color TileSel  = new Color(0.40f, 0.64f, 1.00f, 0.35f);
    static readonly Color TextMain = new Color(0.95f, 0.96f, 0.98f);
    static readonly Color TextDim  = new Color(0.60f, 0.64f, 0.72f);
    static readonly Color Accent   = new Color(0.40f, 0.64f, 1.00f);
    static readonly Color Ok       = new Color(0.33f, 0.86f, 0.56f);
    static readonly Color Bad      = new Color(1.00f, 0.43f, 0.41f);
    static readonly Color BtnBg    = new Color(1f, 1f, 1f, 0.10f);

    const int PageSize = 8, ScenesPerPage = 5;
    const float PanelW = 720f, PanelH = 540f;

    enum View { None, Inventory, Scenes, SaveObject, Suggest }
    View _view = View.None;

    Sprite _rounded, _circle;
    Transform _panelRoot;
    GameObject _inventoryView, _scenesView, _saveView, _suggestView;
    TextMeshProUGUI _status, _tabInvLabel, _tabScLabel;
    Image _tabInv, _tabSc;

    // Inventario
    readonly List<Image> _catChips = new List<Image>();
    string _category = "", _query = "";
    TextMeshProUGUI _queryLabel, _pageLabel, _searchLabel, _deleteAssetLabel;
    readonly List<Tile> _tiles = new List<Tile>();
    List<AssetRecord> _items = new List<AssetRecord>();
    int _offset, _total;
    AssetRecord _selected;
    GameObject _insertBtn, _deleteAssetBtn;

    // Scene
    TextMeshProUGUI _currentSceneLabel, _sceneNameLabel, _scenesPageLabel, _sceneVoiceLabel, _clearLabel;
    readonly List<SceneRow> _rows = new List<SceneRow>();
    List<SceneInfo> _scenes = new List<SceneInfo>();
    int _scenesPage;
    string _pendingSceneName = "";

    // Salva oggetto
    SceneObject _saveTarget;
    RawImage _saveThumb;
    TextMeshProUGUI _saveName, _saveInfo, _saveVoiceLabel, _styleVoiceLabel;
    string _saveCategory = "", _saveStyle = "", _saveNameText = "";
    readonly List<Image> _saveCatChips = new List<Image>();
    readonly List<(Image img, TextMeshProUGUI label)> _styleChips = new List<(Image, TextMeshProUGUI)>();
    readonly List<string> _styles = new List<string>();

    // Suggerimenti
    readonly List<SuggestCard> _cards = new List<SuggestCard>();
    TextMeshProUGUI _suggestQuery;

    // Barra oggetto
    Transform _toolbar;
    CanvasGroup _toolbarGroup;
    TextMeshProUGUI _tbSaveLabel, _tbDeleteLabel;
    SceneObject _tbTarget;
    float _tbUntil;

    // Conferme ("Elimina" → "Conferma?")
    readonly Dictionary<string, float> _armed = new Dictionary<string, float>();

    class Tile { public Image bg; public RawImage thumb; public TextMeshProUGUI name, dims; public AssetRecord item; }
    class SuggestCard { public GameObject root; public RawImage thumb; public TextMeshProUGUI name, info; public AssetRecord item; }
    class SceneRow { public GameObject root; public TextMeshProUGUI name, info, deleteLabel; public SceneInfo scene; }

    // ── Avvio ─────────────────────────────────────────────────────────

    void Start()
    {
        if (library == null) library = GetComponent<AssetLibrary>();
        if (library == null) library = FindAnyObjectByType<AssetLibrary>();
        if (generator == null) generator = FindAnyObjectByType<QuestObjectGenerator>();
        if (statusUI == null) statusUI = FindAnyObjectByType<GenerationStatusUI>();
        if (library == null || generator == null)
        {
            Debug.LogError("[LibraryUI] Servono AssetLibrary e QuestObjectGenerator nella scena.");
            enabled = false;
            return;
        }

        _rounded = MakeRoundedSprite(64, 24);
        _circle = MakeRoundedSprite(64, 32);
        _styles.AddRange(defaultStyles);

        BuildPanel();
        if (statusUI == null) BuildDock();   // con il pannello di controllo si apre dal cerchietto col libro
        BuildToolbar();
        ShowView(View.None);

        SceneObject.Selected += OnObjectSelected;
        library.Changed += OnLibraryChanged;
        generator.StateChanged += OnGeneratorState;
    }

    void OnDestroy()
    {
        SceneObject.Selected -= OnObjectSelected;
        if (library != null) library.Changed -= OnLibraryChanged;
        if (generator != null) generator.StateChanged -= OnGeneratorState;
        if (_toolbar != null) Destroy(_toolbar.gameObject);
    }

    void LateUpdate()
    {
        UpdateToolbar();
        UpdateArmedLabels();
        if (_view == View.None && _panelRoot != null && _panelRoot.gameObject.activeSelf) _panelRoot.gameObject.SetActive(false);
    }

    // ── Viste ─────────────────────────────────────────────────────────

    public bool IsOpen => _view != View.None;
    public void Hide() { if (_view != View.None) ShowView(View.None); }

    void ShowView(View v)
    {
        if (v != View.None && _view == View.None) FindAnyObjectByType<SettingsUI>()?.Hide();   // stesso spazio del pannello Impostazioni
        _view = v;
        _panelRoot.gameObject.SetActive(v != View.None);
        _inventoryView.SetActive(v == View.Inventory);
        _scenesView.SetActive(v == View.Scenes);
        _saveView.SetActive(v == View.SaveObject);
        _suggestView.SetActive(v == View.Suggest);
        _tabInv.color = v == View.Inventory ? TileSel : BtnBg;
        _tabSc.color = v == View.Scenes ? TileSel : BtnBg;

        if (v == View.Inventory) RefreshInventory();
        if (v == View.Scenes) RefreshScenes();
    }

    public void Toggle() => TogglePanel();

    void TogglePanel()
    {
        if (_view != View.None) { ShowView(View.None); return; }
        ShowView(generator.State == PipelineState.Suggesting ? View.Suggest : View.Inventory);
        if (_view == View.Suggest) FillSuggestions();
    }

    void SetStatus(string text, Color? color = null)
    {
        _status.text = text ?? "";
        _status.color = color ?? TextDim;
    }

    void OnLibraryChanged()
    {
        if (_view == View.Inventory) RefreshInventory();
        if (_view == View.Scenes) RefreshScenes();
    }

    // ── Inventario ────────────────────────────────────────────────────

    void RefreshInventory()
    {
        UpdateCategoryChips();
        _queryLabel.text = string.IsNullOrEmpty(_query) ? "<color=#9AA3B5>Tutti gli oggetti</color>" : $"Ricerca: <b>\"{_query}\"</b>";
        SetStatus("Carico l'inventario...");
        StartCoroutine(library.List(_query, _category, "", _offset, PageSize, (r, err) =>
        {
            if (r == null) { SetStatus($"Inventario non disponibile: {err}", Bad); return; }
            _items = r.items ?? new List<AssetRecord>();
            _total = r.total;
            if (_items.Count == 0 && _offset > 0) { _offset = Mathf.Max(0, _offset - PageSize); RefreshInventory(); return; }
            foreach (var s in library.KnownStyles) if (!_styles.Contains(s)) _styles.Add(s);
            _selected = null;
            FillTiles();
            int pages = Mathf.Max(1, Mathf.CeilToInt(_total / (float)PageSize));
            _pageLabel.text = $"{_offset / PageSize + 1} / {pages}";
            SetStatus(_total == 0 ? (string.IsNullOrEmpty(_query) ? "Inventario vuoto: salva un oggetto dalla sua barra" : "Nessun oggetto simile") : $"{_total} oggetti");
        }));
    }

    void FillTiles()
    {
        for (int i = 0; i < _tiles.Count; i++)
        {
            var t = _tiles[i];
            var item = i < _items.Count ? _items[i] : null;
            t.item = item;
            t.bg.gameObject.SetActive(item != null);
            if (item == null) continue;
            t.bg.color = TileBg;
            t.name.text = item.name;
            t.dims.text = item.width_cm > 0 ? $"{Mathf.RoundToInt(item.width_cm)}×{Mathf.RoundToInt(item.depth_cm)} · H {Mathf.RoundToInt(item.height_cm)} cm" : item.category;
            t.thumb.texture = null;
            t.thumb.color = new Color(1f, 1f, 1f, 0f);
            var tile = t;
            string key = item.thumb_key;
            StartCoroutine(library.GetThumbnail(key, tex =>
            {
                if (tile.item == null || tile.item.thumb_key != key || tex == null) return;
                tile.thumb.texture = tex;
                tile.thumb.color = Color.white;
            }));
        }
        UpdateInventoryActions();
    }

    void SelectTile(Tile t)
    {
        if (t.item == null) return;
        _selected = _selected == t.item ? null : t.item;
        foreach (var x in _tiles) x.bg.color = x.item != null && x.item == _selected ? TileSel : TileBg;
        UpdateInventoryActions();
    }

    void UpdateInventoryActions()
    {
        _insertBtn.SetActive(_selected != null);
        _deleteAssetBtn.SetActive(_selected != null);
    }

    void InsertSelected()
    {
        if (_selected == null) return;
        var item = _selected;
        SetStatus($"Inserisco \"{item.name}\"...");
        StartCoroutine(library.SpawnFromInventory(item, (so, err) =>
            SetStatus(so != null ? $"\"{item.name}\" inserito" : $"Non inserito: {err}", so != null ? Ok : Bad)));
    }

    void DeleteSelected()
    {
        if (_selected == null) return;
        if (!Confirm("asset:" + _selected.id)) return;
        var item = _selected;
        StartCoroutine(library.DeleteAsset(item.id, (ok, err) =>
            SetStatus(ok ? $"\"{item.name}\" eliminato dall'inventario" : $"Non eliminato: {err}", ok ? Ok : Bad)));
    }

    void SetCategory(string c)
    {
        _category = c;
        _offset = 0;
        RefreshInventory();
    }

    void UpdateCategoryChips()
    {
        for (int i = 0; i < _catChips.Count; i++)
        {
            string c = i == 0 ? "" : categories[i - 1];
            _catChips[i].color = c == _category ? TileSel : BtnBg;
        }
    }

    void VoiceSearch()
    {
        _searchLabel.text = "Ascolto...";
        StartCoroutine(generator.Dictate(text =>
        {
            _searchLabel.text = "Cerca a voce";
            if (string.IsNullOrEmpty(text)) { SetStatus("Non ho capito: riprova", Bad); return; }
            _query = text;
            _offset = 0;
            RefreshInventory();
        }));
    }

    void ClearSearch()
    {
        _query = "";
        _offset = 0;
        RefreshInventory();
    }

    void Page(int dir)
    {
        int next = _offset + dir * PageSize;
        if (next < 0 || next >= Mathf.Max(_total, 1)) return;
        _offset = next;
        RefreshInventory();
    }

    // ── Suggerimenti prima di generare ────────────────────────────────

    void OnGeneratorState(PipelineState state, string detail)
    {
        if (state == PipelineState.Suggesting)
        {
            ShowView(View.Suggest);
            FillSuggestions();
        }
        else if (_view == View.Suggest) ShowView(View.None);
    }

    void FillSuggestions()
    {
        var list = generator.Suggestions ?? new List<AssetRecord>();
        _suggestQuery.text = $"Hai chiesto <b>\"{generator.LastTranscript}\"</b>: nell'inventario c'è già qualcosa di simile.";
        for (int i = 0; i < _cards.Count; i++)
        {
            var c = _cards[i];
            var item = i < list.Count ? list[i] : null;
            c.item = item;
            c.root.SetActive(item != null);
            if (item == null) continue;
            c.name.text = item.name;
            string dims = item.width_cm > 0 ? $"{Mathf.RoundToInt(item.width_cm)}×{Mathf.RoundToInt(item.depth_cm)} · H {Mathf.RoundToInt(item.height_cm)} cm" : item.category;
            c.info.text = $"{dims}\n<color=#55DB8F>somiglianza {Mathf.RoundToInt(Mathf.Clamp01(item.score) * 100f)}%</color>" +
                          (string.IsNullOrEmpty(item.style) ? "" : $" · {item.style}");
            c.thumb.texture = null;
            c.thumb.color = new Color(1f, 1f, 1f, 0f);
            var card = c;
            string key = item.thumb_key;
            StartCoroutine(library.GetThumbnail(key, tex =>
            {
                if (card.item == null || card.item.thumb_key != key || tex == null) return;
                card.thumb.texture = tex;
                card.thumb.color = Color.white;
            }));
        }
        SetStatus($"{list.Count} oggetti simili", Ok);
    }

    void UseSuggestion(SuggestCard c)
    {
        if (c.item == null || generator.State != PipelineState.Suggesting) return;
        generator.ChooseSuggestion(c.item);
        ShowView(View.None);
    }

    void GenerateNew()
    {
        generator.GenerateAnyway();
        ShowView(View.None);
    }

    // ── Scene ─────────────────────────────────────────────────────────

    void RefreshScenes()
    {
        UpdateCurrentSceneLabel();
        SetStatus("Carico le scene...");
        StartCoroutine(library.ListScenes((list, err) =>
        {
            if (list == null) { SetStatus($"Scene non disponibili: {err}", Bad); return; }
            _scenes = list;
            _scenesPage = Mathf.Clamp(_scenesPage, 0, Mathf.Max(0, (_scenes.Count - 1) / ScenesPerPage));
            FillSceneRows();
            SetStatus(_scenes.Count == 0 ? "Nessuna scena salvata" : $"{_scenes.Count} scene");
        }));
    }

    void UpdateCurrentSceneLabel()
    {
        int n = SceneObject.All.Count;
        _currentSceneLabel.text = string.IsNullOrEmpty(library.CurrentSceneId)
            ? $"Scena corrente: <b>nuova</b> (non salvata) · {n} oggetti"
            : $"Scena corrente: <b>{library.CurrentSceneName}</b> · {n} oggetti";
        string name = !string.IsNullOrEmpty(_pendingSceneName) ? _pendingSceneName
                    : !string.IsNullOrEmpty(library.CurrentSceneName) ? library.CurrentSceneName : AssetLibrary.DefaultSceneName();
        _sceneNameLabel.text = $"Nome: <b>{name}</b>";
    }

    void FillSceneRows()
    {
        int start = _scenesPage * ScenesPerPage;
        for (int i = 0; i < _rows.Count; i++)
        {
            var row = _rows[i];
            var s = start + i < _scenes.Count ? _scenes[start + i] : null;
            row.scene = s;
            row.root.SetActive(s != null);
            if (s == null) continue;
            bool current = s.id == library.CurrentSceneId;
            row.name.text = current ? $"{s.name}  <size=70%><color=#55DB8F>· corrente</color></size>" : s.name;
            row.info.text = $"{s.object_count} oggetti · {s.author} · {FormatDate(s.updated_at)}";
            row.deleteLabel.text = "Elimina";
        }
        int pages = Mathf.Max(1, Mathf.CeilToInt(_scenes.Count / (float)ScenesPerPage));
        _scenesPageLabel.text = $"{_scenesPage + 1} / {pages}";
    }

    void SaveScene(bool asNew)
    {
        if (SceneObject.All.Count == 0) { SetStatus("La scena è vuota: inserisci almeno un oggetto", Bad); return; }
        if (library.Busy) return;
        string name = _pendingSceneName;
        StartCoroutine(library.SaveScene(name, asNew, (ok, err) =>
        {
            if (ok) _pendingSceneName = "";
            SetStatus(ok ? $"Scena \"{library.CurrentSceneName}\" salvata" : $"Non salvata: {err}", ok ? Ok : Bad);
            RefreshScenes();
        }, msg => SetStatus(msg)));
    }

    void LoadScene(SceneRow row)
    {
        if (row.scene == null || library.Busy) return;
        // se ci sono oggetti non salvati, il caricamento li rimuove: chiede conferma
        if (SceneObject.All.Count > 0 && !Confirm("load:" + row.scene.id))
        {
            SetStatus("La scena attuale verrà sostituita: tocca di nuovo \"Carica\" per confermare", Accent);
            return;
        }
        var s = row.scene;
        StartCoroutine(library.LoadScene(s.id, true, (ok, err) =>
        {
            SetStatus(ok ? $"Scena \"{s.name}\" caricata" : $"Caricata con problemi: {err}", ok ? Ok : Bad);
            UpdateCurrentSceneLabel();
            FillSceneRows();
        }, msg => SetStatus(msg)));
    }

    void DeleteScene(SceneRow row)
    {
        if (row.scene == null) return;
        if (!Confirm("scene:" + row.scene.id)) return;
        var s = row.scene;
        StartCoroutine(library.DeleteScene(s.id, (ok, err) =>
            SetStatus(ok ? $"Scena \"{s.name}\" eliminata" : $"Non eliminata: {err}", ok ? Ok : Bad)));
    }

    void ClearScene()
    {
        if (SceneObject.All.Count == 0) return;
        if (!Confirm("clear")) return;
        library.ClearScene();
        _pendingSceneName = "";
        SetStatus("Scena svuotata", Ok);
        UpdateCurrentSceneLabel();
        FillSceneRows();
    }

    void VoiceSceneName()
    {
        _sceneVoiceLabel.text = "Ascolto...";
        StartCoroutine(generator.Dictate(text =>
        {
            _sceneVoiceLabel.text = "Nome a voce";
            if (string.IsNullOrEmpty(text)) { SetStatus("Non ho capito: riprova", Bad); return; }
            _pendingSceneName = Capitalize(text);
            UpdateCurrentSceneLabel();
        }));
    }

    void ScenesPage(int dir)
    {
        int pages = Mathf.Max(1, Mathf.CeilToInt(_scenes.Count / (float)ScenesPerPage));
        _scenesPage = Mathf.Clamp(_scenesPage + dir, 0, pages - 1);
        FillSceneRows();
    }

    // ── Salva oggetto nell'inventario ─────────────────────────────────

    void OpenSaveDialog(SceneObject o)
    {
        if (o == null) return;
        _saveTarget = o;
        _saveNameText = string.IsNullOrEmpty(o.displayName) ? "Oggetto" : o.displayName;
        _saveCategory = string.IsNullOrEmpty(o.category) ? "" : o.category;
        _saveStyle = string.IsNullOrEmpty(o.style) ? "" : o.style;
        if (!string.IsNullOrEmpty(_saveStyle) && !_styles.Contains(_saveStyle)) _styles.Add(_saveStyle);

        _saveName.text = _saveNameText;
        Vector3 size = o.SizeMeters * 100f;
        _saveInfo.text = $"{Mathf.RoundToInt(size.x)} × {Mathf.RoundToInt(size.z)} cm · H {Mathf.RoundToInt(size.y)} cm" +
                         (string.IsNullOrEmpty(o.promptIt) ? "" : $"\n<i>\"{o.promptIt}\"</i>");

        _saveThumb.texture = o.thumbnail;
        _saveThumb.color = o.thumbnail != null ? Color.white : new Color(1f, 1f, 1f, 0f);
        if (o.thumbnail == null && !string.IsNullOrEmpty(o.thumbKey))
            StartCoroutine(library.GetThumbnail(o.thumbKey, tex => { if (_saveTarget == o && tex != null) { _saveThumb.texture = tex; _saveThumb.color = Color.white; } }));

        UpdateSaveChips();
        ShowView(View.SaveObject);
        SetStatus(o.inInventory ? "Già nell'inventario: puoi cambiarne nome, categoria e stile" : "");
    }

    void UpdateSaveChips()
    {
        for (int i = 0; i < _saveCatChips.Count; i++) _saveCatChips[i].color = categories[i] == _saveCategory ? TileSel : BtnBg;
        for (int i = 0; i < _styleChips.Count; i++)
        {
            bool has = i < _styles.Count;
            _styleChips[i].img.gameObject.SetActive(has);
            if (!has) continue;
            _styleChips[i].label.text = _styles[i];
            _styleChips[i].img.color = _styles[i] == _saveStyle ? TileSel : BtnBg;
        }
    }

    void VoiceObjectName()
    {
        _saveVoiceLabel.text = "Ascolto...";
        StartCoroutine(generator.Dictate(text =>
        {
            _saveVoiceLabel.text = "A voce";
            if (string.IsNullOrEmpty(text)) { SetStatus("Non ho capito: riprova", Bad); return; }
            _saveNameText = Capitalize(text);
            _saveName.text = _saveNameText;
        }));
    }

    void VoiceNewStyle()
    {
        _styleVoiceLabel.text = "Ascolto...";
        StartCoroutine(generator.Dictate(text =>
        {
            _styleVoiceLabel.text = "Nuovo stile a voce";
            if (string.IsNullOrEmpty(text)) { SetStatus("Non ho capito: riprova", Bad); return; }
            string st = Capitalize(text);
            if (!_styles.Contains(st)) _styles.Insert(0, st);
            if (_styles.Count > _styleChips.Count) _styles.RemoveAt(_styles.Count - 1);
            _saveStyle = st;
            UpdateSaveChips();
        }));
    }

    void ConfirmSave()
    {
        var o = _saveTarget;
        if (o == null) { ShowView(View.None); return; }
        if (string.IsNullOrEmpty(_saveCategory)) { SetStatus("Scegli una categoria", Bad); return; }
        SetStatus("Salvo nell'inventario...");
        StartCoroutine(library.SaveObject(o, true, _saveNameText, _saveCategory, _saveStyle, (ok, err) =>
        {
            if (ok)
            {
                SetStatus($"\"{_saveNameText}\" salvato nell'inventario", Ok);
                ShowView(View.Inventory);
            }
            else SetStatus($"Non salvato: {err}", Bad);
        }));
    }

    // ── Barra sopra l'oggetto ─────────────────────────────────────────

    void OnObjectSelected(SceneObject o)
    {
        _tbTarget = o;
        _tbUntil = Time.time + toolbarSeconds;
        _tbSaveLabel.text = o.inInventory ? "Modifica" : "Salva";
        _tbDeleteLabel.text = "Elimina";
        _armed.Remove("obj");
    }

    void UpdateToolbar()
    {
        bool show = _tbTarget != null && Time.time < _tbUntil;
        if (show)
        {
            var grab = _tbTarget.GetComponent<XRGrabInteractable>();
            if (grab != null && grab.isSelected) show = false;   // mentre lo tieni in mano
        }
        _toolbarGroup.alpha = Mathf.MoveTowards(_toolbarGroup.alpha, show ? 1f : 0f, Time.deltaTime * 6f);
        bool interactive = show && _toolbarGroup.alpha > 0.5f;
        _toolbarGroup.interactable = interactive;
        _toolbarGroup.blocksRaycasts = interactive;
        if (_tbTarget == null || _toolbarGroup.alpha <= 0f) return;

        Bounds b = WorldBounds(_tbTarget.gameObject);
        _toolbar.position = new Vector3(b.center.x, b.max.y + 0.15f, b.center.z);
        var head = generator.Head;
        if (head != null)
        {
            Vector3 look = _toolbar.position - head.position;
            if (look.sqrMagnitude > 0.0001f) _toolbar.rotation = Quaternion.LookRotation(look, Vector3.up);
        }
    }

    void ToolbarSave()
    {
        if (_tbTarget == null) return;
        OpenSaveDialog(_tbTarget);
        _tbUntil = 0f;
    }

    void ToolbarDuplicate()
    {
        if (_tbTarget == null) return;
        var copy = library.Duplicate(_tbTarget);
        if (copy != null) OnObjectSelected(copy);
    }

    void ToolbarDelete()
    {
        if (_tbTarget == null) return;
        if (!Confirm("obj")) { _tbUntil = Time.time + toolbarSeconds; return; }
        library.DeleteObject(_tbTarget);
        _tbTarget = null;
        if (_view == View.Scenes) UpdateCurrentSceneLabel();
    }

    // ── Conferme ──────────────────────────────────────────────────────

    // Primo tocco: "Conferma?" per 3 s. Secondo tocco entro 3 s: true.
    bool Confirm(string key)
    {
        if (_armed.TryGetValue(key, out float until) && Time.time < until)
        {
            _armed.Remove(key);
            return true;
        }
        _armed[key] = Time.time + 3f;
        return false;
    }

    void UpdateArmedLabels()
    {
        bool Armed(string k) => _armed.TryGetValue(k, out float t) && Time.time < t;
        if (_tbDeleteLabel != null) _tbDeleteLabel.text = Armed("obj") ? "Conferma?" : "Elimina";
        if (_clearLabel != null) _clearLabel.text = Armed("clear") ? "Conferma?" : "Svuota";
        if (_deleteAssetLabel != null) _deleteAssetLabel.text = _selected != null && Armed("asset:" + _selected.id) ? "Conferma?" : "Elimina";
        foreach (var r in _rows)
            if (r.scene != null) r.deleteLabel.text = Armed("scene:" + r.scene.id) ? "Conferma?" : "Elimina";
    }

    // ── Costruzione UI ────────────────────────────────────────────────

    void BuildPanel()
    {
        var root = NewCanvas("LibraryPanel", PanelW, PanelH, out _panelRoot);
        if (statusUI != null)
        {
            _panelRoot.SetParent(statusUI.transform, false);
            _panelRoot.localPosition = panelOffset;
            _panelRoot.localRotation = Quaternion.Euler(panelTilt, 0f, 0f);
        }
        else
        {
            _panelRoot.SetParent(transform, false);
            var head = generator.Head;
            if (head != null)
            {
                Vector3 fwd = Vector3.ProjectOnPlane(head.forward, Vector3.up).normalized;
                _panelRoot.position = head.position + fwd * 1.0f;
                _panelRoot.rotation = Quaternion.LookRotation(fwd, Vector3.up);
            }
        }

        var bg = Img(root, "Background", _rounded, CardBg, true, 1f);
        Stretch(bg.rectTransform);

        // Intestazione
        _tabInv = MakeButton(root, "TabInventory", "Inventario", 24, 16, 150, 40, () => ShowView(View.Inventory), out _tabInvLabel);
        _tabSc = MakeButton(root, "TabScenes", "Scene", 184, 16, 150, 40, () => ShowView(View.Scenes), out _tabScLabel);
        _status = Txt(root, "Status", 16, FontStyles.Normal, TextDim, TextAlignmentOptions.MidlineRight);
        Place(_status.rectTransform, 344, 16, 308, 40);
        MakeRoundButton(root, "Close", "×", 664, 18, 36, () => ShowView(View.None));

        BuildInventoryView(root);
        BuildScenesView(root);
        BuildSaveView(root);
        BuildSuggestView(root);
    }

    void BuildSuggestView(RectTransform root)
    {
        var v = Group(root, "SuggestView");
        _suggestView = v.gameObject;

        var title = Txt(v, "Title", 24, FontStyles.Bold, TextMain, TextAlignmentOptions.MidlineLeft);
        Place(title.rectTransform, 24, 68, 672, 36);
        title.text = "Esiste già qualcosa di simile";
        _suggestQuery = Txt(v, "Query", 17, FontStyles.Normal, TextDim, TextAlignmentOptions.TopLeft);
        Place(_suggestQuery.rectTransform, 24, 104, 672, 48);

        for (int i = 0; i < 3; i++)
        {
            var c = new SuggestCard();
            float x = 24 + i * 228;
            var bg = Img(v, $"Card{i}", _rounded, TileBg, true, 2f);
            Place(bg.rectTransform, x, 156, 216, 316);
            c.root = bg.gameObject;
            var frame = Img(bg.rectTransform, "Frame", _rounded, new Color(1f, 1f, 1f, 0.05f), true, 2f);
            Place(frame.rectTransform, 8, 8, 200, 160);
            var tg = new GameObject("Thumb", typeof(RectTransform), typeof(RawImage));
            tg.transform.SetParent(frame.rectTransform, false);
            c.thumb = tg.GetComponent<RawImage>();
            c.thumb.raycastTarget = false;
            Stretch(c.thumb.rectTransform);
            c.name = Txt(bg.rectTransform, "Name", 18, FontStyles.Bold, TextMain, TextAlignmentOptions.TopLeft);
            Place(c.name.rectTransform, 10, 174, 196, 26);
            c.info = Txt(bg.rectTransform, "Info", 14, FontStyles.Normal, TextDim, TextAlignmentOptions.TopLeft);
            Place(c.info.rectTransform, 10, 202, 196, 44);
            var card = c;
            var use = MakeButton(bg.rectTransform, "Use", "Usa", 10, 260, 196, 44, () => UseSuggestion(card), out _);
            use.color = new Color(Ok.r, Ok.g, Ok.b, 0.5f);
            _cards.Add(c);
        }

        var hint = Txt(v, "Hint", 15, FontStyles.Normal, TextDim, TextAlignmentOptions.MidlineLeft);
        Place(hint.rectTransform, 24, 484, 400, 40);
        hint.text = "Nessuno va bene? Genera un oggetto nuovo.";
        var gen = MakeButton(v, "GenerateNew", "Genera nuovo", 476, 484, 220, 40, GenerateNew, out _);
        gen.color = new Color(Accent.r, Accent.g, Accent.b, 0.45f);
    }

    void BuildInventoryView(RectTransform root)
    {
        var v = Group(root, "InventoryView");
        _inventoryView = v.gameObject;

        for (int i = 0; i <= categories.Length && i < 5; i++)
        {
            string c = i == 0 ? "" : categories[i - 1];
            _catChips.Add(MakeButton(v, $"Cat{i}", i == 0 ? "Tutte" : c, 24 + i * 136, 72, 128, 34, () => SetCategory(c), out _));
        }

        MakeButton(v, "VoiceSearch", "Cerca a voce", 24, 116, 160, 36, VoiceSearch, out _searchLabel);
        _queryLabel = Txt(v, "Query", 18, FontStyles.Normal, TextMain, TextAlignmentOptions.MidlineLeft);
        Place(_queryLabel.rectTransform, 196, 116, 420, 36);
        MakeButton(v, "ClearSearch", "Tutti", 616, 116, 80, 36, ClearSearch, out _);

        for (int r = 0; r < 2; r++)
        for (int c = 0; c < 4; c++)
        {
            var t = new Tile();
            float x = 24 + c * 170, y = 164 + r * 158;
            t.bg = MakeButton(v, $"Tile{r}{c}", "", x, y, 162, 150, null, out _);
            var tile = t;
            t.bg.GetComponent<Button>().onClick.AddListener(() => SelectTile(tile));
            var frame = Img(t.bg.rectTransform, "Frame", _rounded, new Color(1f, 1f, 1f, 0.05f), true, 2f);
            Place(frame.rectTransform, 6, 6, 150, 94);
            var thumbGo = new GameObject("Thumb", typeof(RectTransform), typeof(RawImage));
            thumbGo.transform.SetParent(frame.rectTransform, false);
            t.thumb = thumbGo.GetComponent<RawImage>();
            t.thumb.raycastTarget = false;
            Stretch(t.thumb.rectTransform);
            t.name = Txt(t.bg.rectTransform, "Name", 16, FontStyles.Bold, TextMain, TextAlignmentOptions.TopLeft);
            Place(t.name.rectTransform, 8, 104, 148, 22);
            t.dims = Txt(t.bg.rectTransform, "Dims", 13, FontStyles.Normal, TextDim, TextAlignmentOptions.TopLeft);
            Place(t.dims.rectTransform, 8, 126, 148, 20);
            _tiles.Add(t);
        }

        MakeButton(v, "Prev", "<", 24, 484, 52, 40, () => Page(-1), out _);
        _pageLabel = Txt(v, "Page", 18, FontStyles.Normal, TextDim, TextAlignmentOptions.Center);
        Place(_pageLabel.rectTransform, 80, 484, 100, 40);
        MakeButton(v, "Next", ">", 184, 484, 52, 40, () => Page(1), out _);

        _insertBtn = MakeButton(v, "Insert", "Inserisci", 420, 484, 136, 40, InsertSelected, out _).gameObject;
        _insertBtn.GetComponent<Image>().color = new Color(Ok.r, Ok.g, Ok.b, 0.5f);
        _deleteAssetBtn = MakeButton(v, "DeleteAsset", "Elimina", 564, 484, 132, 40, DeleteSelected, out _deleteAssetLabel).gameObject;
    }

    void BuildScenesView(RectTransform root)
    {
        var v = Group(root, "ScenesView");
        _scenesView = v.gameObject;

        _currentSceneLabel = Txt(v, "Current", 18, FontStyles.Normal, TextMain, TextAlignmentOptions.MidlineLeft);
        Place(_currentSceneLabel.rectTransform, 24, 70, 672, 34);

        var save = MakeButton(v, "Save", "Salva", 24, 110, 140, 40, () => SaveScene(false), out _);
        save.color = new Color(Ok.r, Ok.g, Ok.b, 0.5f);
        MakeButton(v, "SaveAsNew", "Salva come nuova", 172, 110, 196, 40, () => SaveScene(true), out _);
        MakeButton(v, "VoiceName", "Nome a voce", 376, 110, 160, 40, VoiceSceneName, out _sceneVoiceLabel);
        MakeButton(v, "Clear", "Svuota", 544, 110, 152, 40, ClearScene, out _clearLabel);

        _sceneNameLabel = Txt(v, "SceneName", 16, FontStyles.Normal, TextDim, TextAlignmentOptions.MidlineLeft);
        Place(_sceneNameLabel.rectTransform, 24, 154, 672, 28);

        for (int i = 0; i < ScenesPerPage; i++)
        {
            var row = new SceneRow();
            float y = 188 + i * 58;
            var bg = Img(v, $"Row{i}", _rounded, TileBg, true, 2f);
            Place(bg.rectTransform, 24, y, 672, 52);
            row.root = bg.gameObject;
            row.name = Txt(bg.rectTransform, "Name", 18, FontStyles.Bold, TextMain, TextAlignmentOptions.TopLeft);
            Place(row.name.rectTransform, 12, 4, 400, 24);
            row.info = Txt(bg.rectTransform, "Info", 13, FontStyles.Normal, TextDim, TextAlignmentOptions.TopLeft);
            Place(row.info.rectTransform, 12, 28, 400, 20);
            var r = row;
            MakeButton(bg.rectTransform, "Load", "Carica", 428, 8, 112, 36, () => LoadScene(r), out _);
            MakeButton(bg.rectTransform, "Delete", "Elimina", 548, 8, 112, 36, () => DeleteScene(r), out row.deleteLabel);
            _rows.Add(row);
        }

        MakeButton(v, "Prev", "<", 24, 484, 52, 40, () => ScenesPage(-1), out _);
        _scenesPageLabel = Txt(v, "Page", 18, FontStyles.Normal, TextDim, TextAlignmentOptions.Center);
        Place(_scenesPageLabel.rectTransform, 80, 484, 100, 40);
        MakeButton(v, "Next", ">", 184, 484, 52, 40, () => ScenesPage(1), out _);
    }

    void BuildSaveView(RectTransform root)
    {
        var v = Group(root, "SaveView");
        _saveView = v.gameObject;

        var title = Txt(v, "Title", 24, FontStyles.Bold, TextMain, TextAlignmentOptions.MidlineLeft);
        Place(title.rectTransform, 24, 68, 500, 36);
        title.text = "Salva nell'inventario";

        var frame = Img(v, "ThumbFrame", _rounded, new Color(1f, 1f, 1f, 0.06f), true, 2f);
        Place(frame.rectTransform, 24, 112, 160, 160);
        var tg = new GameObject("Thumb", typeof(RectTransform), typeof(RawImage));
        tg.transform.SetParent(frame.rectTransform, false);
        _saveThumb = tg.GetComponent<RawImage>();
        _saveThumb.raycastTarget = false;
        Stretch(_saveThumb.rectTransform);

        Label(v, "NOME", 200, 112);
        _saveName = Txt(v, "Name", 24, FontStyles.Bold, TextMain, TextAlignmentOptions.MidlineLeft);
        Place(_saveName.rectTransform, 200, 134, 380, 40);
        MakeButton(v, "VoiceName", "A voce", 588, 136, 108, 36, VoiceObjectName, out _saveVoiceLabel);

        Label(v, "CATEGORIA", 200, 184);
        for (int i = 0; i < categories.Length && i < 4; i++)
        {
            string c = categories[i];
            _saveCatChips.Add(MakeButton(v, $"SaveCat{i}", c, 200 + i * 126, 206, 118, 34, () => { _saveCategory = c; UpdateSaveChips(); }, out _));
        }

        Label(v, "STILE", 200, 252);
        for (int i = 0; i < 10; i++)
        {
            int idx = i;
            var img = MakeButton(v, $"Style{i}", "", 200 + (i % 5) * 100, 274 + (i / 5) * 40, 94, 32, () =>
            {
                if (idx < _styles.Count) { _saveStyle = _saveStyle == _styles[idx] ? "" : _styles[idx]; UpdateSaveChips(); }
            }, out var lbl);
            lbl.fontSize = 14;
            _styleChips.Add((img, lbl));
        }
        MakeButton(v, "VoiceStyle", "Nuovo stile a voce", 24, 282, 160, 36, VoiceNewStyle, out _styleVoiceLabel).GetComponentInChildren<TextMeshProUGUI>().fontSize = 15;

        _saveInfo = Txt(v, "Info", 16, FontStyles.Normal, TextDim, TextAlignmentOptions.TopLeft);
        Place(_saveInfo.rectTransform, 24, 362, 672, 100);

        MakeButton(v, "Cancel", "Annulla", 420, 484, 136, 40, () => ShowView(View.Inventory), out _);
        var ok = MakeButton(v, "Confirm", "Salva", 564, 484, 132, 40, ConfirmSave, out _);
        ok.color = new Color(Ok.r, Ok.g, Ok.b, 0.55f);
    }

    void BuildDock()
    {
        var root = NewCanvas("LibraryDock", 150, 56, out var t);
        if (statusUI != null)
        {
            t.SetParent(statusUI.transform, false);
            t.localPosition = dockOffset;
            t.localRotation = Quaternion.identity;
        }
        else t.SetParent(transform, false);
        var b = MakeButton(root, "Library", "Libreria", 0, 0, 150, 56, TogglePanel, out var lbl);
        b.color = new Color(0.07f, 0.08f, 0.11f, 0.85f);
        lbl.fontSize = 22;
    }

    void BuildToolbar()
    {
        var root = NewCanvas("ObjectToolbar", 312, 56, out _toolbar);
        _toolbar.SetParent(null, false);
        _toolbarGroup = root.gameObject.AddComponent<CanvasGroup>();
        _toolbarGroup.alpha = 0f;
        var bg = Img(root, "Bg", _rounded, CardBg, true, 1.5f);
        Stretch(bg.rectTransform);
        MakeButton(root, "Save", "Salva", 8, 8, 94, 40, ToolbarSave, out _tbSaveLabel);
        MakeButton(root, "Duplicate", "Duplica", 109, 8, 94, 40, ToolbarDuplicate, out _);
        var del = MakeButton(root, "Delete", "Elimina", 210, 8, 94, 40, ToolbarDelete, out _tbDeleteLabel);
        del.color = new Color(Bad.r, Bad.g, Bad.b, 0.35f);
    }

    // ── Utilità UI ────────────────────────────────────────────────────

    RectTransform NewCanvas(string name, float w, float h, out Transform t)
    {
        var go = new GameObject(name, typeof(RectTransform), typeof(Canvas), typeof(TrackedDeviceGraphicRaycaster));
        go.GetComponent<Canvas>().renderMode = RenderMode.WorldSpace;
        var rt = (RectTransform)go.transform;
        rt.sizeDelta = new Vector2(w, h);
        rt.localScale = Vector3.one * 0.001f;
        t = rt;
        return rt;
    }

    static RectTransform Group(RectTransform parent, string name)
    {
        var go = new GameObject(name, typeof(RectTransform));
        go.transform.SetParent(parent, false);
        var rt = (RectTransform)go.transform;
        Stretch(rt);
        return rt;
    }

    void Label(RectTransform parent, string text, float x, float y)
    {
        var l = Txt(parent, text, 14, FontStyles.Bold, TextDim, TextAlignmentOptions.TopLeft);
        l.characterSpacing = 8f;
        Place(l.rectTransform, x, y, 300, 20);
        l.text = text;
    }

    Image MakeButton(RectTransform parent, string name, string label, float x, float y, float w, float h, Action onClick, out TextMeshProUGUI text)
    {
        var img = Img(parent, name, _rounded, BtnBg, true, 24f / Mathf.Max(10f, Mathf.Min(h, 24f) * 0.75f));
        img.raycastTarget = true;
        Place(img.rectTransform, x, y, w, h);
        var btn = img.gameObject.AddComponent<Button>();
        var colors = btn.colors;
        colors.normalColor = Color.white;
        colors.highlightedColor = new Color(1.6f, 1.6f, 1.6f, 1f);
        colors.pressedColor = new Color(2.2f, 2.2f, 2.2f, 1f);
        colors.colorMultiplier = 2f;
        btn.colors = colors;
        btn.targetGraphic = img;
        if (onClick != null) btn.onClick.AddListener(() => onClick());

        text = Txt(img.rectTransform, "Label", 18, FontStyles.Bold, TextMain, TextAlignmentOptions.Center);
        Stretch(text.rectTransform);
        text.text = label;
        return img;
    }

    void MakeRoundButton(RectTransform parent, string name, string glyph, float x, float y, float size, Action onClick)
    {
        var img = Img(parent, name, _circle, BtnBg, false);
        img.raycastTarget = true;
        Place(img.rectTransform, x, y, size, size);
        var btn = img.gameObject.AddComponent<Button>();
        btn.targetGraphic = img;
        btn.onClick.AddListener(() => onClick());
        var t = Txt(img.rectTransform, "Glyph", 26, FontStyles.Bold, TextMain, TextAlignmentOptions.Center);
        Stretch(t.rectTransform);
        t.text = glyph;
    }

    static Image Img(RectTransform parent, string name, Sprite sprite, Color color, bool sliced, float cornerMul = 1f)
    {
        var go = new GameObject(name, typeof(RectTransform), typeof(Image));
        go.transform.SetParent(parent, false);
        var img = go.GetComponent<Image>();
        img.sprite = sprite;
        img.type = sliced ? Image.Type.Sliced : Image.Type.Simple;
        img.pixelsPerUnitMultiplier = cornerMul;
        img.color = color;
        img.raycastTarget = false;
        return img;
    }

    static TextMeshProUGUI Txt(RectTransform parent, string name, float size, FontStyles style, Color color, TextAlignmentOptions align)
    {
        var go = new GameObject(name, typeof(RectTransform), typeof(TextMeshProUGUI));
        go.transform.SetParent(parent, false);
        var t = go.GetComponent<TextMeshProUGUI>();
        t.fontSize = size;
        t.fontStyle = style;
        t.color = color;
        t.alignment = align;
        t.textWrappingMode = TextWrappingModes.Normal;
        t.overflowMode = TextOverflowModes.Ellipsis;
        t.richText = true;
        t.raycastTarget = false;
        return t;
    }

    static void Place(RectTransform rt, float x, float y, float w, float h)
    {
        rt.anchorMin = rt.anchorMax = new Vector2(0f, 1f);
        rt.pivot = new Vector2(0f, 1f);
        rt.anchoredPosition = new Vector2(x, -y);
        rt.sizeDelta = new Vector2(w, h);
    }

    static void Stretch(RectTransform rt)
    {
        rt.anchorMin = Vector2.zero;
        rt.anchorMax = Vector2.one;
        rt.offsetMin = Vector2.zero;
        rt.offsetMax = Vector2.zero;
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

    static string Capitalize(string s)
    {
        s = (s ?? "").Trim().Trim('.', '!', '?');
        return s.Length == 0 ? s : char.ToUpper(s[0]) + s.Substring(1);
    }

    static string FormatDate(string iso)
    {
        return DateTime.TryParse(iso, out var d) ? d.ToString("dd/MM HH:mm") : iso;
    }

    static Sprite MakeRoundedSprite(int size, int radius)
    {
        var tex = new Texture2D(size, size, TextureFormat.RGBA32, false) { wrapMode = TextureWrapMode.Clamp, filterMode = FilterMode.Bilinear };
        var px = new Color32[size * size];
        for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
        {
            float fx = x + 0.5f, fy = y + 0.5f;
            float dx = Mathf.Max(radius - fx, fx - (size - radius), 0f);
            float dy = Mathf.Max(radius - fy, fy - (size - radius), 0f);
            float d = Mathf.Sqrt(dx * dx + dy * dy);
            px[y * size + x] = new Color32(255, 255, 255, (byte)(Mathf.Clamp01(radius - d + 0.5f) * 255f));
        }
        tex.SetPixels32(px);
        tex.Apply(false, true);
        return Sprite.Create(tex, new Rect(0, 0, size, size), new Vector2(0.5f, 0.5f), 100f, 0,
                             SpriteMeshType.FullRect, new Vector4(radius, radius, radius, radius));
    }
}
