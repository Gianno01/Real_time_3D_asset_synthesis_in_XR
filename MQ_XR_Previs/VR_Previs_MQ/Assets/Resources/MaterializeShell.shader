// MaterializeShell.shader
// Guscio "ologramma" per l'effetto di materializzazione (usato da MaterializeEffect.cs).
// Additivo, senza luci: una banda luminosa sale lungo l'oggetto e lascia dietro di sé un velo a righe con bordo brillante.
// IMPORTANTE: deve stare in una cartella "Resources" (Assets/Resources/MaterializeShell.shader) per finire nella build.
// Funziona con URP e con la pipeline built-in; supporta il rendering stereo del Quest.

Shader "XR/MaterializeShell"
{
    Properties
    {
        _Color ("Colore", Color) = (0.2, 0.9, 1, 1)
        _Reveal ("Quota della banda (mondo, m)", Float) = 0
        _Band ("Spessore della banda (m)", Float) = 0.06
        _Fade ("Intensità", Range(0, 2)) = 1
    }
    SubShader
    {
        Tags { "RenderType"="Transparent" "Queue"="Transparent+5" }

        Pass
        {
            Name "Shell"
            Blend One One
            ZWrite Off
            ZTest LEqual
            Cull Back
            Offset -1, -1

            CGPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            #pragma multi_compile_instancing
            #include "UnityCG.cginc"

            fixed4 _Color;
            float _Reveal;
            float _Band;
            float _Fade;

            struct appdata
            {
                float4 vertex : POSITION;
                float3 normal : NORMAL;
                UNITY_VERTEX_INPUT_INSTANCE_ID
            };

            struct v2f
            {
                float4 pos : SV_POSITION;
                float3 wpos : TEXCOORD0;
                float3 wnrm : TEXCOORD1;
                UNITY_VERTEX_OUTPUT_STEREO
            };

            v2f vert(appdata v)
            {
                v2f o;
                UNITY_SETUP_INSTANCE_ID(v);
                UNITY_INITIALIZE_OUTPUT(v2f, o);
                UNITY_INITIALIZE_VERTEX_OUTPUT_STEREO(o);
                o.pos = UnityObjectToClipPos(v.vertex);
                o.wpos = mul(unity_ObjectToWorld, v.vertex).xyz;
                o.wnrm = UnityObjectToWorldNormal(v.normal);
                return o;
            }

            fixed4 frag(v2f i) : SV_Target
            {
                float below = _Reveal - i.wpos.y;
                clip(below);                                         // sopra la banda: ancora invisibile

                float3 n = normalize(i.wnrm);
                float3 view = normalize(_WorldSpaceCameraPos - i.wpos);
                float rim = pow(1.0 - saturate(dot(n, view)), 2.5);   // bordi più luminosi
                float edge = saturate(1.0 - below / max(_Band, 0.001)); // banda che sale
                float lines = 0.5 + 0.5 * sin(i.wpos.y * 260.0 - _Time.y * 7.0);

                float glow = 0.12 + rim * 0.9 + edge * edge * 2.2 + lines * 0.18;
                return fixed4(_Color.rgb * glow * _Fade, 1);
            }
            ENDCG
        }
    }
}
