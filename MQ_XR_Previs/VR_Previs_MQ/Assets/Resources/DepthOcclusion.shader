// DepthOcclusion.shader
// Shader "fantasma": scrive solo la profondità, nessun colore.
// Gli oggetti virtuali che stanno dietro a una superficie con questo materiale NON vengono disegnati,
// e al loro posto resta visibile il passthrough (la stanza vera). La superficie stessa è invisibile.
//
// IMPORTANTE: il file deve stare in una cartella "Resources" (Assets/Resources/DepthOcclusion.shader),
// così Unity lo include nella build per il Quest (altrimenti in build il materiale sarebbe rosa/assente).
// Funziona sia con URP sia con la pipeline built-in; supporta il rendering stereo del Quest.

Shader "XR/DepthOcclusion"
{
    SubShader
    {
        // Geometry-10: disegnato prima degli oggetti normali (queue 2000), così la profondità c'è già quando arrivano loro
        Tags { "RenderType"="Opaque" "Queue"="Geometry-10" }

        Pass
        {
            Name "DepthOnly"
            ZWrite On
            ZTest LEqual
            ColorMask 0
            Cull Off

            CGPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            #pragma multi_compile_instancing
            #include "UnityCG.cginc"

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
                o.pos = UnityObjectToClipPos(v.vertex);
                return o;
            }

            fixed4 frag(v2f i) : SV_Target
            {
                return 0;
            }
            ENDCG
        }
    }
}
