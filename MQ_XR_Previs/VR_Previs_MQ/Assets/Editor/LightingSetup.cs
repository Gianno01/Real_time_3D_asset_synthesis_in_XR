// LightingSetup.cs  (cartella Assets/Editor)
// Menu  XR → Attiva luci aggiuntive (URP)
// Se le luci virtuali non illuminano gli oggetti, quasi sempre è perché nell'asset URP "Additional Lights" è su Disabled:
// in quel caso Unity toglie dalla build le varianti degli shader che servono, e nessuna luce oltre alla principale funziona.
// Questo comando imposta Additional Lights = Per Pixel (limite 4 per oggetto) su tutti gli asset URP del progetto
// (quello predefinito e quelli dei livelli di Quality). Poi rifai la build.

#if UNITY_EDITOR
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;
using UnityEngine.Rendering;

static class LightingSetup
{
    [MenuItem("XR/Attiva luci aggiuntive (URP)")]
    static void EnableAdditionalLights()
    {
        var seen = new HashSet<RenderPipelineAsset>();
        int changed = 0, found = 0;

        void Fix(RenderPipelineAsset a)
        {
            if (a == null || !seen.Add(a)) return;
            var so = new SerializedObject(a);
            var mode = so.FindProperty("m_AdditionalLightsRenderingMode");   // 0 = Disabled, 1 = Per Pixel, 2 = Per Vertex
            var limit = so.FindProperty("m_AdditionalLightsPerObjectLimit");
            if (mode == null) return;   // non è un asset URP
            found++;
            bool ch = false;
            if (mode.intValue != 1) { mode.intValue = 1; ch = true; }
            if (limit != null && limit.intValue < 4) { limit.intValue = 4; ch = true; }
            if (ch)
            {
                so.ApplyModifiedPropertiesWithoutUndo();
                EditorUtility.SetDirty(a);
                changed++;
                Debug.Log($"[LightingSetup] {a.name}: Additional Lights = Per Pixel.", a);
            }
        }

        Fix(GraphicsSettings.defaultRenderPipeline);
        for (int i = 0; i < QualitySettings.names.Length; i++) Fix(QualitySettings.GetRenderPipelineAssetAt(i));
        AssetDatabase.SaveAssets();

        string msg = found == 0
            ? "Nessun asset URP trovato: il progetto non usa URP? (controlla Project Settings → Graphics)."
            : changed == 0 ? $"Già a posto: {found} asset URP con Additional Lights attivo." : $"Aggiornati {changed} asset URP su {found}. Rifai la build.";
        Debug.Log("[LightingSetup] " + msg);
        EditorUtility.DisplayDialog("Luci aggiuntive (URP)", msg, "OK");
    }
}
#endif
