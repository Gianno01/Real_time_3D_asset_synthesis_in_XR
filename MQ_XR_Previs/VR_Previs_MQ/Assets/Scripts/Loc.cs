// Loc.cs
// Lingua dell'interfaccia: INGLESE di default, italiano a scelta (Impostazioni → INTERFACCIA → Lingua).
//
// COME FUNZIONA: il codice continua a scrivere i testi in italiano. Un componente invisibile (LocRunner, creato da solo all'avvio)
// controlla i testi TextMeshPro della scena e li sostituisce con la traduzione quando la lingua è l'inglese. Il testo originale
// viene ricordato, quindi cambiando lingua dalle Impostazioni tutto si aggiorna subito, senza riavviare.
//
// COME AGGIUNGERE UNA TRADUZIONE: una riga A("testo italiano", "English text") qui sotto. I testi con markup (<b>…</b>, <size=…>) e a più
// righe vengono tradotti pezzo per pezzo, quindi basta tradurre il pezzo di testo semplice. Le frasi con numeri si traducono con una
// regola R("regex", "sostituzione") (vedi in fondo). Ciò che non è nel dizionario resta com'è (nomi di oggetti, prompt, errori tecnici).
//
// SETUP: nessuno.

using System.Collections.Generic;
using System.Text;
using System.Text.RegularExpressions;
using TMPro;
using UnityEngine;

public static class Loc
{
    public const string PrefKey = "ui_language";
    public static event System.Action Changed;

    static int _lang = -1;   // 0 = inglese, 1 = italiano

    /// <summary>0 = inglese (predefinita), 1 = italiano.</summary>
    public static int Language
    {
        get
        {
            if (_lang < 0) _lang = PlayerPrefs.GetInt(PrefKey, 0) == 1 ? 1 : 0;
            return _lang;
        }
        set
        {
            int v = value == 1 ? 1 : 0;
            if (v == Language) return;
            _lang = v;
            PlayerPrefs.SetInt(PrefKey, v);
            PlayerPrefs.Save();
            Changed?.Invoke();
        }
    }

    public static bool English => Language == 0;

    // ── Traduzione ────────────────────────────────────────────────────

    static readonly Dictionary<string, string> Dict = new Dictionary<string, string>();
    static readonly List<(Regex re, string rep)> Rules = new List<(Regex, string)>();
    static readonly Dictionary<string, string> Cache = new Dictionary<string, string>();
    static readonly Regex TagRe = new Regex("(<[^>]*>)", RegexOptions.Compiled);
    static bool _built;

    /// <summary>Traduce un testo italiano nella lingua corrente (con markup e più righe).</summary>
    public static string T(string it)
    {
        if (string.IsNullOrEmpty(it) || Language == 1) return it;
        if (Cache.TryGetValue(it, out var hit)) return hit;
        Build();

        var sb = new StringBuilder(it.Length + 16);
        foreach (var part in TagRe.Split(it))
        {
            if (part.Length == 0) continue;
            if (part[0] == '<' && part[part.Length - 1] == '>') { sb.Append(part); continue; }
            var lines = part.Split('\n');
            for (int i = 0; i < lines.Length; i++)
            {
                if (i > 0) sb.Append('\n');
                sb.Append(TranslateLine(lines[i]));
            }
        }
        string res = sb.ToString();
        if (Cache.Count > 4000) Cache.Clear();
        Cache[it] = res;
        return res;
    }

    static string TranslateLine(string line)
    {
        string core = line.Trim();
        if (core.Length == 0) return line;
        int lead = line.IndexOf(core[0]);
        string pre = line.Substring(0, lead);
        string post = line.Substring(lead + core.Length);

        if (Dict.TryGetValue(core, out var exact)) return pre + exact + post;
        string r = core;
        foreach (var (re, rep) in Rules) r = re.Replace(r, rep);
        return pre + r + post;
    }

    static void A(string it, string en) { Dict[it] = en; }
    static void R(string pattern, string rep) { Rules.Add((new Regex(pattern, RegexOptions.Compiled), rep)); }

    static void Build()
    {
        if (_built) return;
        _built = true;

        // ── Barra di stato / card ─────────────────────────────────────
        A("Premi lo stick destro", "Press the right stick");
        A("e di' il nome di un oggetto", "and say the name of an object");
        A("Tocca la", "Tap the");
        A("tastiera", "keyboard");
        A("per scrivere il nome di un oggetto, o il", "to type the name of an object, or the");
        A("microfono", "microphone");
        A("per dettarlo", "to dictate it");
        A("Di'", "Say");
        A("\"Genera...\"", "\"Generate...\"");
        A("seguito dall'oggetto, ad esempio", "followed by the object, for example");
        A("\"Genera una sedia di legno\"", "\"Generate a wooden chair\"");
        A("\"genera...\"", "\"generate...\"");
        A("seguito da cosa cambiare", "followed by what to change");
        A("Premi", "Press");
        A("Correggi", "Edit");
        A("(o lo stick) e di' cosa cambiare", "(or the stick) and say what to change");
        A("Voce", "Voice");
        A("Immagine", "Image");
        A("Modello 3D", "3D model");
        A("Caricamento", "Loading");
        A("Ti ascolto...", "Listening...");
        A("Ti ascolto:", "Listening:");
        A("di' cosa cambiare...", "say what to change...");
        A("PARLA ORA", "SPEAK NOW");
        A("Pronuncia il nome di un oggetto: l'invio parte da solo dopo una breve pausa.", "Say the name of an object: it is sent automatically after a short pause.");
        A("Richiesta inviata", "Request sent");
        A("AUDIO INVIATO", "AUDIO SENT");
        A("Esiste già qualcosa di simile", "Something similar already exists");
        A("HAI CHIESTO", "YOU ASKED");
        A("Creo una nuova immagine", "Creating a new image");
        A("Creo l'immagine", "Creating the image");
        A("Ti piace?", "Do you like it?");
        A("immagine", "image");
        A("Sto creando il modello 3D", "Creating the 3D model");
        A("Quasi pronto...", "Almost ready...");
        A("Inserito", "Inserted");
        A("Creato", "Created");
        A("Qualcosa è andato storto", "Something went wrong");
        A("ERRORE", "ERROR");
        A("Richiesta annullata", "Request cancelled");
        A("ANNULLATA", "CANCELLED");
        A("Nessuna richiesta inviata", "No request sent");
        A("in ascolto", "listening");
        A("trascrizione in corso", "transcribing");
        A("scegli nella Libreria: Usa o Genera nuovo", "choose in the Library: Use or Generate new");
        A("prima generazione: stima in corso", "first generation: estimating time");
        A("manca poco...", "almost there...");
        A("download e caricamento", "downloading and loading");
        A("completato", "completed");
        A("riprova quando vuoi", "try again whenever you like");
        A("annullata", "cancelled");
        A("scegli come continuare", "choose how to continue");
        A("Ascolto...", "Listening...");
        A("A", "A");
        A("riduci a icona", "minimize");
        A("Annulla", "Cancel");
        A("Ripeti", "Retry");
        A("Prosegui", "Continue");
        A("Anteprima non disponibile", "Preview not available");
        A("PROMPT", "PROMPT");

        // ── Messaggi della pipeline ───────────────────────────────────
        A("Dimmi quale oggetto vuoi generare", "Tell me which object you want to generate");
        A("Parla ora: l'invio parte dopo 1,5 s di silenzio", "Speak now: it is sent after 1.5 s of silence");
        A("Non ho capito: riprova", "I didn't understand: try again");
        A("Non ho capito l'oggetto: riprova", "I didn't catch the object: try again");
        A("Non ho sentito nulla: riprova", "I didn't hear anything: try again");
        A("Registrazione troppo corta: riprova", "Recording too short: try again");
        A("Permesso microfono mancante", "Microphone permission missing");
        A("Generazione dell'immagine fallita", "Image generation failed");
        A("Generazione 3D fallita", "3D generation failed");
        A("Caricamento del modello fallito", "Model loading failed");
        A("Caricamento dall'inventario non riuscito", "Loading from the inventory failed");
        A("Dall'inventario", "From the inventory");
        A("Cosa vuoi generare?", "What do you want to generate?");
        A("Cosa vuoi cambiare nell'immagine?", "What do you want to change in the image?");
        A("Cosa cerchi nell'inventario?", "What are you looking for in the inventory?");
        A("Nome della scena", "Scene name");
        A("Nome dell'oggetto", "Object name");
        A("Nome del nuovo stile", "New style name");
        A("permesso NEGATO: premi Richiedi", "permission DENIED: press Request");
        A("nessun microfono trovato", "no microphone found");
        A("in attesa del permesso microfono", "waiting for microphone permission");
        A("avvio del microfono...", "starting the microphone...");
        A("il sistema non fornisce audio dal microfono", "the system is not delivering microphone audio");
        A("Risposta n8n senza immagine di anteprima", "n8n response without a preview image");
        A("Risposta n8n senza glb_url valido", "n8n response without a valid glb_url");
        A("Non ho capito: nessun testo trascritto", "I didn't understand: no text transcribed");
        A("Prima calibra la stanza: segui le istruzioni davanti a te (tocca due punti fissi con il controller destro), poi riprova.", "Calibrate the room first: follow the instructions in front of you (touch two fixed points with the right controller), then try again.");
        A("Operazione in corso", "Operation in progress");
        A("Oggetto non valido", "Invalid object");
        A("Manca il file dell'oggetto", "The object file is missing");
        A("Salvataggio non confermato", "Save not confirmed");
        A("Risposta non valida", "Invalid response");
        A("Scena non trovata", "Scene not found");
        A("Eliminazione non confermata", "Deletion not confirmed");
        A("Salvataggio della scena non confermato", "Scene save not confirmed");
        A("GLB non disponibile", "GLB not available");
        A("GLB non valido", "Invalid GLB");
        A("Percorso del file mancante", "File path missing");
        A("Salvo la scena...", "Saving the scene...");

        // ── Tastiera ──────────────────────────────────────────────────
        A("Scrivi", "Type");
        A("Il microfono detta dentro il testo", "The microphone dictates into the text");
        A("Parla ora: la dettatura finisce con una pausa", "Speak now: dictation ends with a pause");
        A("Aggiunto: puoi correggere con la tastiera", "Added: you can fix it with the keyboard");
        A("Ascolto", "Listening");
        A("Detta", "Dictate");
        A("Svuota", "Clear");
        A("Maiusc", "Shift");
        A("MAIUSC", "SHIFT");
        A("Canc", "Del");
        A("spazio", "space");
        A("Invia", "Send");

        // ── Impostazioni ──────────────────────────────────────────────
        A("Impostazioni", "Settings");
        A("Salvate su questo visore. «Ripristina» torna ai valori dell'Inspector.", "Saved on this headset. “Reset” restores the Inspector values.");
        A("Ripristina", "Reset");
        A("VOCE", "VOICE");
        A("GENERAZIONE", "GENERATION");
        A("OGGETTI", "OBJECTS");
        A("POSIZIONAMENTO", "PLACEMENT");
        A("OMBRA", "SHADOW");
        A("STANZA", "ROOM");
        A("MULTIPLAYER", "MULTIPLAYER");
        A("INTERFACCIA", "INTERFACE");
        A("Lingua", "Language");
        A("Tastiera al posto della voce", "Keyboard instead of voice");
        A("Solo tastiera (ascolto spento)", "Keyboard only (listening off)");
        A("Mani libere (\"genera...\")", "Hands-free (\"generate...\")");
        A("Prosegui a voce", "Continue by voice");
        A("Sensibilità microfono", "Microphone sensitivity");
        A("Bassa", "Low");
        A("Medio-bassa", "Medium-low");
        A("Media", "Medium");
        A("Alta", "High");
        A("Molto alta", "Very high");
        A("Microfono", "Microphone");
        A("Richiedi", "Request");
        A("Anteprima dell'immagine", "Image preview");
        A("Proponi oggetti simili", "Suggest similar objects");
        A("Somiglianza minima", "Minimum similarity");
        A("Predefinito", "Default");
        A("Modalità 3D", "3D mode");
        A("Rapido", "Fast");
        A("Dettagliato", "Detailed");
        A("Multivista", "Multiview");
        A("FRONTE", "FRONT");
        A("DESTRA", "RIGHT");
        A("RETRO", "BACK");
        A("Raddrizza i modelli", "Straighten models");
        A("Dimensione iniziale", "Initial size");
        A("Allinea all'asse più vicino", "Snap to nearest axis");
        A("Collisione tra oggetti", "Object collisions");
        A("Gravità", "Gravity");
        A("Griglia e misure", "Grid and measurements");
        A("Aggancio al rilascio", "Snap on release");
        A("Passo della griglia", "Grid step");
        A("Passo della rotazione", "Rotation step");
        A("Libero", "Free");
        A("Libera", "Free");
        A("Ombra sotto gli oggetti", "Shadow under objects");
        A("Intensità dell'ombra", "Shadow intensity");
        A("Calibrazione", "Calibration");
        A("Calibra", "Calibrate");
        A("Occlusione stanza", "Room occlusion");
        A("Appoggia sui mobili", "Rest on furniture");
        A("Mostra occlusori (prova)", "Show occluders (test)");
        A("Luci e oscuramento", "Lights and dimming");
        A("Apri", "Open");
        A("Questo dispositivo", "This device");
        A("Spento", "Off");
        A("Spettatore", "Viewer");
        A("Collegamento visori", "Headset link");
        A("Rete", "Network");
        A("Riconnetti", "Reconnect");
        A("Vibrazione dei controller", "Controller vibration");
        A("Attivo", "On");
        A("Conferma?", "Confirm?");
        A("Calibrazione: in corso", "Calibration: in progress");
        A("Calibrazione: ok", "Calibration: ok");
        A("Calibrazione: no", "Calibration: no");

        // ── Libreria ──────────────────────────────────────────────────
        A("Libreria", "Library");
        A("Inventario", "Inventory");
        A("Scene", "Scenes");
        A("Tutte", "All");
        A("Tutti", "All");
        A("Personaggio", "Character");
        A("Decorazione", "Decoration");
        A("Realistico", "Realistic");
        A("Moderno", "Modern");
        A("Medievale", "Medieval");
        A("Rinascimentale", "Renaissance");
        A("Futuristico", "Futuristic");
        A("Cerca a voce", "Voice search");
        A("Cerca", "Search");
        A("Nome a voce", "Name by voice");
        A("Nome", "Name");
        A("A voce", "By voice");
        A("Nuovo stile a voce", "New style by voice");
        A("Nuovo stile", "New style");
        A("Scrivi...", "Typing...");
        A("Tutti gli oggetti", "All objects");
        A("Ricerca:", "Search:");
        A("Carico l'inventario...", "Loading the inventory...");
        A("Inventario vuoto: salva un oggetto dalla sua barra", "Inventory empty: save an object from its toolbar");
        A("Nessun oggetto simile", "No similar object");
        A("Inserisci", "Insert");
        A("Elimina", "Delete");
        A("Elimina luce", "Delete light");
        A("Usa", "Use");
        A("Genera nuovo", "Generate new");
        A("Nessuno va bene? Genera un oggetto nuovo.", "None fits? Generate a new object.");
        A("Carico le scene...", "Loading the scenes...");
        A("Nessuna scena salvata", "No saved scenes");
        A("Scena corrente:", "Current scene:");
        A("nuova", "new");
        A("(non salvata)", "(not saved)");
        A("corrente", "current");
        A("Carica", "Load");
        A("Salva", "Save");
        A("Salva come nuova", "Save as new");
        A("Sblocca", "Unlock");
        A("Blocca", "Lock");
        A("Duplica", "Duplicate");
        A("La scena è vuota: inserisci almeno un oggetto", "The scene is empty: insert at least one object");
        A("La scena attuale verrà sostituita: tocca di nuovo \"Carica\" per confermare", "The current scene will be replaced: tap \"Load\" again to confirm");
        A("Scena svuotata", "Scene cleared");
        A("Salva nell'inventario", "Save to the inventory");
        A("NOME", "NAME");
        A("CATEGORIA", "CATEGORY");
        A("STILE", "STYLE");
        A("Oggetto", "Object");
        A("Già nell'inventario: puoi cambiarne nome, categoria e stile", "Already in the inventory: you can change its name, category and style");
        A("Scegli una categoria", "Choose a category");
        A("Salvo nell'inventario...", "Saving to the inventory...");
        A("somiglianza", "similarity");

        // ── Luci e occlusione ─────────────────────────────────────────
        A("Luci e occlusione", "Lights and occlusion");
        A("Oscuramento", "Dimming");
        A("+ Luce", "+ Light");
        A("+ Faro (spot)", "+ Spotlight");
        A("+ Blocco", "+ Block");
        A("Blocco da 4 punti", "Block from 4 points");
        A("Cilindro da 4 punti", "Cylinder from 4 points");
        A("Rifai a 4 punti", "Redo with 4 points");
        A("Temperatura", "Temperature");
        A("Candela", "Candle");
        A("Calda", "Warm");
        A("Neutra", "Neutral");
        A("Giorno", "Daylight");
        A("Cielo", "Sky");
        A("Intensità", "Intensity");
        A("Raggio", "Range");
        A("Apertura faro", "Spot angle");
        A("solo faro", "spotlight only");
        A("Larghezza", "Width");
        A("Altezza", "Height");
        A("Profondità", "Depth");
        A("Rotazione", "Rotation");
        A("Cilindro", "Cylinder");
        A("Blocco", "Block");
        A("Luce", "Light");
        A("faro", "spotlight");
        A("puntiforme", "point");
        A("Prendi una luce o un blocco col controller", "Grab a light or a block with the controller");
        A("Luci: attive", "Lights: on");
        A("Luci: spente", "Lights: off");
        A("Blocchi: attivi", "Blocks: on");
        A("Blocchi: spenti", "Blocks: off");
        A("Forma: cilindro", "Shape: cylinder");
        A("Forma: scatola", "Shape: box");
        A("Anteprima: sì", "Preview: yes");
        A("Anteprima: no", "Preview: no");
        A("Luci e blocchi si salvano con la scena (Libreria, Salva scena). In modifica i blocchi sono trasparenti.", "Lights and blocks are saved with the scene (Library, Save scene). While editing, blocks are transparent.");
        A("Poggia la punta del controller destro su un angolo", "Place the tip of the right controller on a corner");
        A("(in ordine, partendo da uno spigolo) e premi il", "(in order, starting from an edge) and press the");
        A("A = annulla l'ultimo punto - B = esci", "A = undo the last point - B = exit");
        A("ATTENZIONE: nell'asset URP \"Additional Lights\" è Disabled, quindi le luci non illuminano gli oggetti. In Unity: menu XR, Attiva luci aggiuntive (URP), poi rifai la build.", "WARNING: in the URP asset \"Additional Lights\" is Disabled, so lights do not illuminate objects. In Unity: XR menu, Enable additional lights (URP), then rebuild.");
        A("e premi il", "and press the");
        A("grilletto", "trigger");
        A("verso l'alto", "upwards");
        A("verso il basso", "downwards");

        // ── Calibrazione ──────────────────────────────────────────────
        A("Calibrazione 1/2", "Calibration 1/2");
        A("Calibrazione 2/2", "Calibration 2/2");
        A("Poggia la punta del controller destro sul", "Place the tip of the right controller on");
        A("PUNTO A", "POINT A");
        A("PUNTO B", "POINT B");
        A("(es. un angolo della scrivania) e premi il", "(e.g. a corner of the desk) and press the");
        A("Obbligatoria per usare l'app - B = ricomincia", "Required to use the app - B = restart");
        A("B = annulla", "B = cancel");
        A("controller non rilevato", "controller not detected");
        A("Ora sul", "Now on");
        A(", lontano da A (meglio oltre 1 m)", ", far from A (ideally over 1 m)");
        A("e premi il", "and press the");
        A("Stanza calibrata", "Room calibrated");
        A("Ora puoi salvare e caricare le scene.", "You can now save and load scenes.");
        A("Calibrazione annullata", "Calibration cancelled");

        // ── Multiplayer ───────────────────────────────────────────────
        A("Rete: spenta", "Network: off");
        A("Rete: avvio...", "Network: starting...");
        A("Rete: connessione...", "Network: connecting...");
        A("Rete: non connesso", "Network: not connected");
        A("Rete: server non raggiungibile", "Network: server unreachable");
        A("Rete: avvio host...", "Network: starting host...");
        A("Netcode: avvio non riuscito", "Netcode: start failed");
        A("Netcode non installato · uso il relay", "Netcode not installed · using the relay");
        A("Co-host · host non connesso", "Co-host · host not connected");
        A("Spettatore · host non connesso", "Viewer · host not connected");
        A("C'è già un host: entra come co-host o spettatore", "There is already a host: join as co-host or viewer");
        A("C'è già un co-host: entra come spettatore", "There is already a co-host: join as viewer");
        A("Ruolo rifiutato dal server", "Role rejected by the server");
        A("host senza indirizzo", "host without address");
        A("host non connesso", "host not connected");
        A("server non raggiungibile", "server unreachable");

        // ── Regole per frasi con numeri e testi variabili ─────────────
        R(@"\bcirca (\S+) rimanenti\b", "about $1 remaining");
        R(@"\b(\d+) oggetti simili\b", "$1 similar objects");
        R(@"\b1 oggetti\b", "1 object");
        R(@"\b(\d+) oggetti\b", "$1 objects");
        R(@"\b(\d+) scene\b", "$1 scenes");
        R(@"\b(\d+) luci, (\d+) blocchi\b", "$1 lights, $2 blocks");
        R(@"^Oscurato (\d+)%", "Dimmed $1%");
        R(@"^Scena (\d{2}/\d{2} \d{2}:\d{2})$", "Scene $1");
        R(@"^Inserisco ""(.*)""\.\.\.$", "Inserting \"$1\"...");
        R(@"^""(.*)"" inserito$", "\"$1\" inserted");
        R(@"^""(.*)"" eliminato dall'inventario$", "\"$1\" deleted from the inventory");
        R(@"^""(.*)"" salvato nell'inventario$", "\"$1\" saved to the inventory");
        R(@"^Scena ""(.*)"" salvata$", "Scene \"$1\" saved");
        R(@"^Scena ""(.*)"" caricata$", "Scene \"$1\" loaded");
        R(@"^Scena ""(.*)"" eliminata$", "Scene \"$1\" deleted");
        R(@"^Non inserito: ", "Not inserted: ");
        R(@"^Non eliminato: ", "Not deleted: ");
        R(@"^Non eliminata: ", "Not deleted: ");
        R(@"^Non salvata: ", "Not saved: ");
        R(@"^Non salvato: ", "Not saved: ");
        R(@"^Caricata con problemi: ", "Loaded with problems: ");
        R(@"^Inventario non disponibile: ", "Inventory not available: ");
        R(@"^Scene non disponibili: ", "Scenes not available: ");
        R(@"^Hai chiesto ", "You asked ");
        R(@"^: nell'inventario c'è già qualcosa di simile\.$", ": the inventory already has something similar.");
        R(@"^Oggetto ""(.*)"": ", "Object \"$1\": ");
        R(@"^Salvo gli oggetti nuovi \((\d+)/(\d+)\)\.\.\.$", "Saving new objects ($1/$2)...");
        R(@"^Carico gli oggetti \((\d+)/(\d+)\)\.\.\.$", "Loading objects ($1/$2)...");
        R(@"^(\d+) oggetti non caricati$", "$1 objects not loaded");
        R(@"^Totale ", "Total ");
        R(@"\s+immagine (\d+(?:\.\d+)?) s\b", " image $1 s");
        R(@"\bdownload (\d+) s\b", "download $1 s");
        R(@"^(\d+(?:[.,]\d+)?) s di audio inviati a Whisper$", "$1 s of audio sent to Whisper");
        R(@"^Co-host · con (.*)$", "Co-host · with $1");
        R(@"^Spettatore · (\d+) oggetti$", "Viewer · $1 objects");
        R(@"^Host · (.*) visori · (.*) browser$", "Host · $1 headsets · $2 browsers");
        R(@"^Host · (\d+) spettatori$", "Host · $1 viewers");
        R(@"· co-host presente", "· co-host present");
        R(@"\(web non raggiungibile\)", "(web unreachable)");
        R(@"· cerco l'host \((.*)\)$", "· looking for the host ($1)");
        R(@"· cerco l'host\.\.\.$", "· looking for the host...");
        R(@"(\d+) gradi", "$1 degrees");
        R(@"^Cilindro: angolo (\d+) di 4$", "Cylinder: corner $1 of 4");
        R(@"^Blocco: angolo (\d+) di 4$", "Block: corner $1 of 4");
        R(@"^Cilindro: altezza$", "Cylinder: height");
        R(@"^Blocco: altezza$", "Block: height");
        R(@"\bverso l'alto\b", "upwards");
        R(@"\bverso il basso\b", "downwards");
        R(@"^A = usa (\d+) cm", "A = use $1 cm");
        R(@"B = esci", "B = exit");
        R(@"B = annulla", "B = cancel");
        R(@"B = ricomincia", "B = restart");
        R(@"Tocca un punto", "Touch a point");
        R(@"più in alto o più in basso", "higher or lower");
        R(@"della base \(es\. il pavimento sotto i piedi del tavolo\) e premi il", "than the base (e.g. the floor under the table legs) and press the");
        R(@"distanza da A: ", "distance from A: ");
        R(@"servono almeno ", "at least ");
        R(@"distanza da A", "distance from A");
        R(@"^Luce (\d+) \((.*)\)$", "Light $1 ($2)");
    }
}

/// <summary>Controlla i testi TextMeshPro e li traduce nella lingua corrente. Si crea da solo all'avvio.</summary>
public class LocRunner : MonoBehaviour
{
    class Entry { public string raw; public string shown; }

    readonly Dictionary<TMP_Text, Entry> _map = new Dictionary<TMP_Text, Entry>();
    readonly List<TMP_Text> _list = new List<TMP_Text>();
    float _nextScan;
    bool _relang;

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.AfterSceneLoad)]
    static void Create()
    {
        if (FindAnyObjectByType<LocRunner>() != null) return;
        var go = new GameObject("LocRunner");
        DontDestroyOnLoad(go);
        go.AddComponent<LocRunner>();
    }

    void OnEnable() { Loc.Changed += OnLang; }
    void OnDisable() { Loc.Changed -= OnLang; }
    void OnLang() { _relang = true; }

    void Scan()
    {
        foreach (var t in FindObjectsByType<TextMeshProUGUI>(FindObjectsInactive.Include, FindObjectsSortMode.None))
            if (!_map.ContainsKey(t)) { _map[t] = new Entry(); _list.Add(t); }
    }

    void LateUpdate()
    {
        if (Time.unscaledTime >= _nextScan) { _nextScan = Time.unscaledTime + 0.2f; Scan(); }

        for (int i = _list.Count - 1; i >= 0; i--)
        {
            var t = _list[i];
            if (t == null) { _map.Remove(t); _list.RemoveAt(i); continue; }
            var e = _map[t];
            string cur = t.text;

            if (e.shown != null && (object)cur == (object)e.shown && !_relang) continue;
            if (e.shown != null && cur == e.shown && !_relang) continue;

            if (e.shown == null || cur != e.shown) e.raw = cur;   // il codice ha scritto un nuovo testo (italiano)
            string tr = Loc.T(e.raw);
            if (tr != cur) t.text = tr;
            e.shown = tr;
        }
        _relang = false;
    }
}
