// UiIcons.cs
// Icone disegnate via codice (bianche su trasparente): il font di TextMeshPro non ha i simboli ⚙ e 📖,
// e così non servono immagini da importare. Si colorano con RawImage.color.

using System;
using UnityEngine;

public static class UiIcons
{
    const int Size = 96;
    static Texture2D s_minimize, s_gear, s_book;

    /// <summary>"_" : riduci a icona.</summary>
    public static Texture2D Minimize => s_minimize ??= Make((x, y) => RoundRect(x, y, 0.22f, 0.20f, 0.78f, 0.31f, 0.055f));

    /// <summary>Ingranaggio: impostazioni.</summary>
    public static Texture2D Gear => s_gear ??= Make((x, y) =>
    {
        float dx = x - 0.5f, dy = y - 0.5f;
        float r = Mathf.Sqrt(dx * dx + dy * dy);
        if (r < 0.14f) return false;                                  // foro centrale
        float a = Mathf.Atan2(dy, dx);
        float wave = 0.5f + 0.5f * Mathf.Cos(a * 8f);                  // 8 denti
        float tooth = Mathf.Clamp01((wave - 0.38f) / 0.22f);
        return r < 0.32f + 0.13f * tooth;
    });

    /// <summary>Libro aperto: libreria.</summary>
    public static Texture2D Book => s_book ??= Make((x, y) =>
    {
        // due pagine leggermente inclinate, separate dalla costola centrale
        bool left = InQuad(x, y, new Vector2(0.08f, 0.24f), new Vector2(0.47f, 0.17f), new Vector2(0.47f, 0.80f), new Vector2(0.08f, 0.86f));
        bool right = InQuad(x, y, new Vector2(0.53f, 0.17f), new Vector2(0.92f, 0.24f), new Vector2(0.92f, 0.86f), new Vector2(0.53f, 0.80f));
        if (!left && !right) return false;
        // righe di testo ritagliate nelle pagine
        float side = left ? 0.47f - x : x - 0.53f;                     // distanza dalla costola
        if (side < 0.06f || side > 0.33f) return true;
        float slope = 0.07f / 0.39f;                                   // inclinazione delle pagine
        float yy = y + side * slope;                                   // righe parallele al bordo
        foreach (float line in new[] { 0.40f, 0.52f, 0.64f })
            if (Mathf.Abs(yy - line - 0.07f) < 0.022f) return false;
        return true;
    });

    // ── Disegno ──────────────────────────────────────────────────────

    // y verso l'alto (0 = basso): 4×4 campioni per pixel per bordi morbidi
    static Texture2D Make(Func<float, float, bool> inside)
    {
        var tex = new Texture2D(Size, Size, TextureFormat.RGBA32, true) { wrapMode = TextureWrapMode.Clamp, filterMode = FilterMode.Trilinear };
        var px = new Color32[Size * Size];
        const int S = 4;
        for (int py = 0; py < Size; py++)
        for (int pxl = 0; pxl < Size; pxl++)
        {
            int hits = 0;
            for (int sy = 0; sy < S; sy++)
            for (int sx = 0; sx < S; sx++)
                if (inside((pxl + (sx + 0.5f) / S) / Size, (py + (sy + 0.5f) / S) / Size)) hits++;
            px[py * Size + pxl] = new Color32(255, 255, 255, (byte)(hits * 255 / (S * S)));
        }
        tex.SetPixels32(px);
        tex.Apply(true, true);
        return tex;
    }

    static bool RoundRect(float x, float y, float x0, float y0, float x1, float y1, float r)
    {
        float cx = Mathf.Clamp(x, x0 + r, x1 - r), cy = Mathf.Clamp(y, y0 + r, y1 - r);
        float dx = x - cx, dy = y - cy;
        return x >= x0 && x <= x1 && y >= y0 && y <= y1 && dx * dx + dy * dy <= r * r;
    }

    static bool InQuad(float x, float y, Vector2 a, Vector2 b, Vector2 c, Vector2 d)
    {
        // quadrilatero convesso, vertici in senso antiorario
        return Cross(a, b, x, y) >= 0f && Cross(b, c, x, y) >= 0f && Cross(c, d, x, y) >= 0f && Cross(d, a, x, y) >= 0f;
    }

    static float Cross(Vector2 p, Vector2 q, float x, float y) => (q.x - p.x) * (y - p.y) - (q.y - p.y) * (x - p.x);
}
