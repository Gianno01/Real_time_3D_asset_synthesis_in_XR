// DimOverlay.shader
// Vela nera su tutto lo schermo che oscura il passthrough (la stanza vera). Serve per "spegnere" la stanza
// e illuminarla con le luci virtuali (SceneLighting).
//
// Ordine di disegno (Queue): questa vela è la PRIMA cosa disegnata (Geometry-20), ignorando la profondità;
// poi i blocchi di occlusione (Geometry-10, solo profondità), poi gli oggetti virtuali (Geometry).
// Risultato: gli oggetti virtuali restano luminosi (sono illuminati dalle luci), e dietro a un blocco
// di occlusione si vede la stanza oscurata, non quella chiara.
//
// IMPORTANTE: il file deve stare in una cartella "Resources" (Assets/Resources/DimOverlay.shader),
// così Unity lo include nella build per il Quest.

Shader "XR/DimOverlay"
{
    Properties
    {
        _Dim ("Oscuramento", Range(0, 1)) = 0.85
    }
    SubShader
    {
        Tags { "RenderType"="Transparent" "Queue"="Geometry-20" }

        Pass
        {
            Name "Dim"
            ZWrite Off
            ZTest Always
            Cull Off
            // colore: nero con alpha; alpha finale = alpha (non alpha al quadrato) per il compositore del Quest
            Blend SrcAlpha OneMinusSrcAlpha, One OneMinusSrcAlpha

            CGPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            #pragma multi_compile_instancing
            #include "UnityCG.cginc"

            fixed _Dim;

            struct appdata
            {
                float4 vertex : POSITION;
                UNITY_VERTEX_INPUT_INSTANCE_ID
            };

            struct v2f
            {
                float4 pos : SV_POSITION;
                UNITY_VERTEX_OUTPUT_STEREO
            };

            v2f vert(appdata v)
            {
                v2f o;
                UNITY_SETUP_INSTANCE_ID(v);
                UNITY_INITIALIZE_OUTPUT(v2f, o);
                UNITY_INITIALIZE_VERTEX_OUTPUT_STEREO(o);
                // quad con vertici a ±0.5 → copre tutto lo schermo di ciascun occhio, qualunque sia la camera
                o.pos = float4(v.vertex.x * 2.0, v.vertex.y * 2.0, UNITY_NEAR_CLIP_VALUE, 1.0);
                return o;
            }

            fixed4 frag(v2f i) : SV_Target
            {
                return fixed4(0, 0, 0, _Dim);
            }
            ENDCG
        }
    }
}
