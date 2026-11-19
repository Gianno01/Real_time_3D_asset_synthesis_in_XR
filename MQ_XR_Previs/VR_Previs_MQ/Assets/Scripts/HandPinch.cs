// HandPinch.cs
// Pizzico pollice-indice a mani libere (XR Hands): restituisce il punto toccato (metà tra le due punte) e se una mano sta pizzicando.
// Usato da SceneLighting per i blocchi di occlusione. Richiede "Hand Tracking Subsystem" attivo in OpenXR; senza mani tracciate
// Read() torna tracked=false e si usano i controller come prima.

using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.Hands;

public static class HandPinch
{
    public static float on = 0.02f;    // distanza punte sotto cui il pizzico scatta (m)
    public static float off = 0.035f;  // sopra cui si rilascia (m)

    static XRHandSubsystem _hands;
    static readonly List<XRHandSubsystem> _subs = new List<XRHandSubsystem>();
    static readonly bool[] _pinching = new bool[2];

    /// <param name="space">spazio in cui XR Hands esprime le pose (CameraFloorOffsetObject dell'XR Origin)</param>
    public static bool Read(Transform space, out Vector3 tip, out bool tracked)
    {
        tip = default; tracked = false;
        if (space == null) return false;
        if (_hands == null || !_hands.running)
        {
            _hands = null;
            SubsystemManager.GetSubsystems(_subs);
            foreach (var s in _subs) if (s.running) { _hands = s; break; }
            if (_hands == null) return false;
        }
        bool pinch = false;
        for (int i = 0; i < 2; i++)
        {
            var hand = i == 0 ? _hands.rightHand : _hands.leftHand;
            if (!hand.isTracked) { _pinching[i] = false; continue; }
            if (!hand.GetJoint(XRHandJointID.IndexTip).TryGetPose(out Pose ip) || !hand.GetJoint(XRHandJointID.ThumbTip).TryGetPose(out Pose tp)) { _pinching[i] = false; continue; }
            Vector3 a = space.TransformPoint(ip.position), b = space.TransformPoint(tp.position);
            _pinching[i] = Vector3.Distance(a, b) < (_pinching[i] ? off : on);
            // guida la mano che pizzica; se nessuna pizzica, la prima tracciata (destra per prima)
            if (!tracked || (_pinching[i] && !pinch)) { tip = (a + b) * 0.5f; tracked = true; }
            if (_pinching[i]) pinch = true;
        }
        return pinch;
    }
}
