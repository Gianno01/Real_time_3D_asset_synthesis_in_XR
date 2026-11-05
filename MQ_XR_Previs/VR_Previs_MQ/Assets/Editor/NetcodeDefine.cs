// NetcodeDefine.cs  (cartella Assets/Editor)
// Aggiunge/toglie da solo il simbolo NETCODE_ENABLED in base alla presenza del pacchetto Netcode for GameObjects,
// così NetcodeLink.cs si compila solo quando il pacchetto è installato (altrimenti il progetto non darebbe errori).

#if UNITY_EDITOR
using System;
using System.Collections.Generic;
using System.Linq;
using UnityEditor;
using UnityEditor.Build;

[InitializeOnLoad]
static class NetcodeDefine
{
    const string Symbol = "NETCODE_ENABLED";

    static NetcodeDefine()
    {
        bool has = AppDomain.CurrentDomain.GetAssemblies().Any(a => a.GetName().Name == "Unity.Netcode.Runtime");
        Apply(NamedBuildTarget.Standalone, has);
        Apply(NamedBuildTarget.Android, has);
    }

    static void Apply(NamedBuildTarget target, bool on)
    {
        PlayerSettings.GetScriptingDefineSymbols(target, out string[] defines);
        var list = new List<string>(defines);
        if (list.Contains(Symbol) == on) return;
        if (on) list.Add(Symbol); else list.Remove(Symbol);
        PlayerSettings.SetScriptingDefineSymbols(target, list.ToArray());
    }
}
#endif
