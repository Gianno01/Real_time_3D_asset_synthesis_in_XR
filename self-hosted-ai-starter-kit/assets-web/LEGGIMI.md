# Libreria XR — inventario, ricerca semantica e scene condivise

## Cosa c'è
```
server/
  docker-compose.override.yml   SeaweedFS (storage file) + nginx (porta 8090: file, pannello web, caricamenti)
  assets-web/nginx.conf
  assets-web/admin/             pannello web di gestione (index.html, app.js, glb.js, style.css: nessuna libreria esterna)
  library_schema.sql            tabelle Postgres: xr.assets, xr.scenes, xr.scene_objects
  n8n_quest_library.json        workflow n8n "Quest - Libreria" (webhook quest-library): Postgres + SeaweedFS + Qdrant
unity/
  AssetLibrary.cs               client della libreria + suggerimenti + cache dei GLB sul visore + salva/carica scene
                                (gli oggetti dell'inventario tornano alla loro altezza reale salvata)
  LibraryUI.cs                  pannello Inventario / Scene / Suggerimenti, finestra "Salva", barra Salva·Duplica·Elimina
  SceneObject.cs                dati di ogni oggetto in scena
  QuestObjectGenerator.cs       aggiornato: stato Suggesting (propone oggetti simili prima di generare)
  GenerationStatusUI.cs         aggiornato: messaggio "Esiste già qualcosa di simile"
  ObjectPlacementAids.cs        invariato (griglia, misure, aggancio)
```

**Da eliminare** (versione precedente dell'inventario): in Unity `InventoryClient.cs` e `InventoryUI.cs`
(non compilano più); in n8n il vecchio workflow dell'inventario (*Quest - Inventario*), se l'avevi importato.

## Architettura
| Pezzo | Ruolo | Dove |
|---|---|---|
| **Postgres** | fonte di verità: oggetti, scene, posizioni | già nel compose |
| **Qdrant** | indice vettoriale per la ricerca *per significato* ("sgabello" trova "sedia alta") | già nel compose (porta 6333) |
| **Ollama · bge-m3** | trasforma i testi in vettori (1024 dimensioni, multilingue), su CPU per non togliere VRAM a ComfyUI | già nel compose |
| **SeaweedFS + nginx** | file GLB / immagini / miniature, letti dai visori in sola lettura | override (porta 8090) |
| **Pannello web** | gestione da PC: carica GLB, modifica, elimina, scene | `http://<IP_PC>:8090/admin/` |

Qdrant contiene solo `id → vettore` (+ categoria, stile, in_inventory per i filtri): se si perde, si ricostruisce
da Postgres con l'azione `reindex`. Se Qdrant o Ollama non rispondono, la ricerca ripiega da sola sulla ricerca
per parole simili di Postgres.

## 1. Server (dalla cartella del docker-compose.yml)
1. Copia `docker-compose.override.yml` e la cartella `assets-web/` accanto al `docker-compose.yml`.
2. `docker compose up -d`, poi verifica dal browser del PC o del visore: `http://<IP_PC>:8090/health` deve rispondere `ok`.
3. Firewall Windows (PowerShell da amministratore):
   `New-NetFirewallRule -DisplayName "XR - Storage" -Direction Inbound -Protocol TCP -LocalPort 8090 -Action Allow -Profile Any`
4. Database:
   `docker compose exec -T postgres psql -U <POSTGRES_USER> -d <POSTGRES_DB> < library_schema.sql`
   (utente e database sono quelli del file `.env`; il comando si può rieseguire senza perdere dati)

5. Modello per gli embedding (una volta sola, ~1,2 GB):
   `docker exec -it ollama ollama pull bge-m3`
6. Verifica Qdrant: `http://<IP_PC>:6333/dashboard` dal browser del PC.

## 2. n8n
1. *Credentials → Add → Postgres*: Host `postgres`, Port `5432`, Database = `POSTGRES_DB`, User/Password = quelli del `.env`. SSL disattivato.
2. *Import from file* → `n8n_quest_library.json`.
3. Apri il nodo **Database** e seleziona la credenziale appena creata (è l'unico nodo che la usa).
4. **Publish**.
5. Prova dal Prompt dei comandi:
   `curl.exe -X POST http://<IP_PC>:5678/webhook/quest-library -H "Content-Type: application/json" -d "{\"action\":\"list_assets\"}"`
   → `{"ok":true,"mode":"list","items":[],"total":0,"styles":[]}`
6. Crea l'indice di Qdrant (una volta, e ogni volta che vuoi ricostruirlo da Postgres):
   `curl.exe -X POST http://<IP_PC>:5678/webhook/quest-library -H "Content-Type: application/json" -d "{\"action\":\"reindex\"}"`
   → `{"ok":true,"indexed":0,"total":0,"error":null}` (crea la collezione `xr_assets` e indicizza tutto l'inventario).
   Da qui in poi ogni *Salva* / *Modifica* / *Elimina* aggiorna l'indice da solo.

## 3. Pannello web (gestione da PC)
Dopo i passi 1 e 2 apri **`http://<IP_PC>:8090/admin/`** (dal PC anche `http://localhost:8090/admin/`). Nessuna installazione:
nginx serve la cartella `assets-web/admin` e inoltra le richieste al workflow n8n, quindi non servono altre porte.
Se avevi già avviato lo stack, aggiorna nginx con `docker compose up -d assets-web` (il pannello è montato come nuova cartella).

- **Inventario**: griglia con miniature, ricerca per significato, filtri per categoria/stile, scheda *Solo nelle scene*
  (oggetti salvati solo dentro una scena: da qui puoi aggiungerli all'inventario). Clic su un oggetto → anteprima 3D girevole,
  modifica di nome / categoria / stile / descrizione / tag / **altezza reale**, *Scarica GLB*, *Elimina* (secondo clic per confermare).
- **Carica**: trascina uno o più `.glb` → anteprima 3D, misure e miniatura calcolate nel browser. Completa categoria (obbligatoria),
  stile, descrizione e altezza reale, poi *Salva nell'inventario* o *Salva tutti*. Gli oggetti caricati compaiono subito nei visori
  e nella ricerca semantica.
- **Scene**: elenco, pianta vista dall'alto con le posizioni, *Rinomina*, *Elimina*.
- **Strumenti**: stato dei servizi (storage, n8n + Postgres, ricerca semantica), *Reindicizza*, nome dell'autore.

Note:
- **Misure**: i GLB sono in metri; se un file è in centimetri (succede con modelli da Blender/Sketchfab) il pannello lo segnala
  e chiede l'altezza reale. Nel visore l'oggetto inserito dall'inventario prende quell'altezza.
- **Descrizione**: è il testo più utile per la ricerca a voce. Scrivila come la diresti al visore ("sgabello alto da bar in metallo").
- Limite 300 MB per file. Anteprima e miniatura non disponibili per GLB compressi con Draco/Meshopt (si caricano comunque;
  il visore li apre solo se glTFast ha il relativo pacchetto).
- Se modifichi l'altezza di un oggetto, le scene già salvate non cambiano (conservano la scala con cui erano state salvate).

## 4. Unity
1. Sostituisci/aggiungi gli script della cartella `unity/` in `Assets/Scripts`.
2. In Hierarchy crea un GameObject vuoto **Library** e aggiungi **Asset Library** e **Library UI**.
3. Su *Asset Library*: **Library Url** = `http://<IP_PC>:5678/webhook/quest-library`, **Storage Url** = `http://<IP_PC>:8090`.
   Sul *Quest Object Generator* il campo **Library** si collega da solo (lascia attivo **Suggest From Library**).
4. Salva la scena e fai la build.

## 5. Uso nel visore
- **Libreria**: pulsante a destra del pannello di controllo → monitor con le schede *Inventario* e *Scene*.
- **Barra dell'oggetto**: rilascia un oggetto → sopra compaiono *Salva* · *Duplica* · *Elimina* (Elimina chiede conferma).
- **Salva nell'inventario**: nome proposto dalla richiesta (modificabile *a voce*), categoria (obbligatoria), stile (o *nuovo stile a voce*).
- **Inventario**: filtri per categoria, *Cerca a voce* (ricerca per significato: "qualcosa per sedersi" → "Sedia di legno"), *Inserisci*, *Elimina*.
- **Suggerimenti**: dopo la richiesta vocale, se nell'inventario c'è qualcosa di simile la Libreria si apre da sola
  con fino a 3 proposte (miniatura, misure, % di somiglianza): **Usa** lo inserisce subito (niente GPU),
  **Genera nuovo** prosegue con l'immagine. *Annulla* sul pannello di controllo funziona anche qui.
  Se il server non risponde entro 6 s si genera direttamente.
- **Scene**: *Salva* (sovrascrive la scena corrente), *Salva come nuova*, *Nome a voce*, *Svuota*; ogni scena: *Carica* (sostituisce quella attuale, chiede conferma) ed *Elimina*.

## Come funziona
- Gli oggetti finiscono nell'inventario **solo con "Salva"**. Salvando una scena, gli oggetti mai salvati vengono copiati sul server
  *solo per la scena* (non compaiono nell'inventario ma la scena li ricarica).
- **Eliminare dall'inventario** non rompe le scene: l'oggetto sparisce dall'inventario ma resta disponibile per le scene che lo usano.
- I file (GLB, immagine 1024 px, miniatura 256 px) vengono copiati da ComfyUI a **SeaweedFS** e scaricati dai visori tramite nginx
  in sola lettura. Ogni GLB si scarica **una volta sola per visore** (cache in `persistentDataPath/xrcache`).
- Le posizioni sono salvate rispetto all'origine del pavimento dell'XR Origin. Con la colocation (esperienza condivisa)
  diventeranno relative a un'ancora spaziale comune: basterà assegnare **Scene Anchor** su *Asset Library*.

## Tarare le soglie
I punteggi di bge-m3 dipendono dal tipo di frasi: prova con 10-20 oggetti salvati e regola.
- **Suggerimenti** (*Asset Library*): `Suggest Min Score` 0.65 (semantica), `Suggest Min Text Score` 0.5 (ripiego per parole).
  Troppe proposte sbagliate → alza; non propone mai nulla → abbassa.
- **Ricerca dall'inventario**: soglia 0.45 nel nodo *Corpo ricerca* del workflow (`threshold`).
- Il punteggio di ogni risultato è nel campo `score` della risposta: per vederlo
  `curl.exe -X POST http://<IP_PC>:5678/webhook/quest-library -H "Content-Type: application/json" -d "{\"action\":\"list_assets\",\"q\":\"sgabello\",\"min_score\":0.1}"`

## Problemi comuni
- `"mode":"text"` invece di `"semantic"` → Qdrant o Ollama non rispondono, oppure manca `bge-m3`, oppure non hai mai lanciato `reindex`.
  Guarda l'esecuzione in n8n: i nodi *Embedding ricerca* / *Cerca in Qdrant* mostrano l'errore.
- La prima ricerca dopo un riavvio è lenta (bge-m3 si carica in RAM); resta caricato 30 minuti.
- Qdrant vuoto dopo aver ricreato i volumi → rilancia `reindex` (anche dal pannello: Strumenti → Reindicizza).
- Pannello web: "Webhook non trovato" → il workflow *Quest - Libreria* non è pubblicato. `assets-web` non parte → controlla
  `docker compose logs assets-web` (nginx richiede che i servizi `n8n` e `seaweedfs` esistano) e `docker compose exec assets-web nginx -t`.

## Sicurezza (rete di laboratorio)
I webhook non hanno autenticazione: chiunque sia sulla rete del router può leggere, salvare ed eliminare.
Lo storage si legge da `/assets/` e si scrive solo da n8n o dal pannello web (`/upload/`, solo nei percorsi `assets/<id>/...`).
Il pannello web non ha password: chiunque sulla rete del router può caricare ed eliminare. Per proteggerlo segui le istruzioni
in testa a `assets-web/nginx.conf` (file `.htpasswd` + 3 righe da scommentare): il visore non ne è influenzato.
La porta 6333 di Qdrant è pubblicata solo per la dashboard: se non ti serve, togli `ports` dal servizio `qdrant`
(n8n lo raggiunge comunque dalla rete docker).
