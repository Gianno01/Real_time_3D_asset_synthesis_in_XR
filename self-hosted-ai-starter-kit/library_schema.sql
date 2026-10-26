-- library_schema.sql — Libreria XR: oggetti (assets), scene e posizioni.
-- Esecuzione (dalla cartella del docker-compose):
--   docker compose exec -T postgres psql -U <POSTGRES_USER> -d <POSTGRES_DB> < library_schema.sql
-- È idempotente: si può rieseguire senza perdere dati.

CREATE EXTENSION IF NOT EXISTS pg_trgm;       -- ricerca per somiglianza del testo ("seggiola" ~ "sedia")
CREATE SCHEMA IF NOT EXISTS xr;

-- Un oggetto salvato sul server. in_inventory = visibile nell'inventario;
-- false = salvato solo perché usato in una scena (non compare nell'inventario).
CREATE TABLE IF NOT EXISTS xr.assets (
    id            uuid PRIMARY KEY,
    name          text        NOT NULL,
    category      text        NOT NULL DEFAULT '',
    style         text        NOT NULL DEFAULT '',
    tags          text[]      NOT NULL DEFAULT '{}',
    prompt_it     text        NOT NULL DEFAULT '',   -- richiesta a voce (con le correzioni)
    prompt_en     text        NOT NULL DEFAULT '',   -- prompt dell'LLM per l'immagine
    object_name   text        NOT NULL DEFAULT '',
    model         text        NOT NULL DEFAULT '',   -- es. pixal3d, hunyuan
    glb_key       text        NOT NULL,              -- percorso nello storage: assets/<id>/model.glb
    image_key     text        NOT NULL DEFAULT '',
    thumb_key     text        NOT NULL DEFAULT '',
    width_cm      real        NOT NULL DEFAULT 0,
    height_cm     real        NOT NULL DEFAULT 0,
    depth_cm      real        NOT NULL DEFAULT 0,
    glb_bytes     bigint      NOT NULL DEFAULT 0,
    gen_image_s   real        NOT NULL DEFAULT 0,
    gen_model_s   real        NOT NULL DEFAULT 0,
    author        text        NOT NULL DEFAULT '',
    in_inventory  boolean     NOT NULL DEFAULT false,
    use_count     integer     NOT NULL DEFAULT 0,
    created_at    timestamptz NOT NULL DEFAULT now(),
    updated_at    timestamptz NOT NULL DEFAULT now(),
    deleted_at    timestamptz
);

CREATE INDEX IF NOT EXISTS assets_inventory_idx ON xr.assets (created_at DESC)
    WHERE in_inventory AND deleted_at IS NULL;
CREATE INDEX IF NOT EXISTS assets_text_trgm_idx ON xr.assets
    USING gin ((name || ' ' || prompt_it || ' ' || object_name) gin_trgm_ops);

CREATE TABLE IF NOT EXISTS xr.scenes (
    id            uuid PRIMARY KEY,
    name          text        NOT NULL,
    author        text        NOT NULL DEFAULT '',
    object_count  integer     NOT NULL DEFAULT 0,
    created_at    timestamptz NOT NULL DEFAULT now(),
    updated_at    timestamptz NOT NULL DEFAULT now(),
    deleted_at    timestamptz
);

-- Posizioni: nello spazio dell'ancora di scena (oggi l'origine del pavimento dell'XR Origin;
-- con la colocation diventerà un'ancora spaziale condivisa).
CREATE TABLE IF NOT EXISTS xr.scene_objects (
    id         bigserial   PRIMARY KEY,
    scene_id   uuid        NOT NULL REFERENCES xr.scenes(id) ON DELETE CASCADE,
    asset_id   uuid        NOT NULL REFERENCES xr.assets(id),
    px real NOT NULL, py real NOT NULL, pz real NOT NULL,
    rx real NOT NULL, ry real NOT NULL, rz real NOT NULL, rw real NOT NULL,
    scale      real        NOT NULL DEFAULT 1,
    placed_by  text        NOT NULL DEFAULT '',
    created_at timestamptz NOT NULL DEFAULT now()
);
CREATE INDEX IF NOT EXISTS scene_objects_scene_idx ON xr.scene_objects (scene_id);
CREATE INDEX IF NOT EXISTS scene_objects_asset_idx ON xr.scene_objects (asset_id);
