// LightBeam.shader
// Fascio di luce morbido per i fari di SceneLighting: colore e opacità vengono dai colori dei vertici del cono,
// e l'opacità si spegne verso i bordi visti di profilo (effetto "luce nell'aria", senza spigoli netti).
//
// IMPORTANTE: il file deve stare in una cartella "Resources" (Assets/Resources/LightBeam.shader),
// così Unity lo include nella build per il Quest. Se manca, SceneLighting ripiega su uno shader semplice (più "a strisce").

Shader "XR/LightBeam"
{
    Properties
    {
        _Soft ("Morbidezza bordi", Range(0.5, 4)) = 1.8
    }
    SubShader
    {
        Tags { "RenderType"="Transparent" "Queue"="Transparent" }

        Pass
        {
            Name "Beam"
            ZWrite Off
            Cull Off
            // stesso schema di DimOverlay: l'alpha finale resta quella dichiarata, per il compositore del Quest
            Blend SrcAlpha OneMinusSrcAlpha, One OneMinusSrcAlpha

            CGPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            #pragma multi_compile_instancing
            #include "UnityCG.cginc"

            float _Soft;

            struct appdata
            {
                float4 vertex : POSITION;
                float3 normal : NORMAL;
                fixed4 color  : COLOR;
                UNITY_VERTEX_INPUT_INSTANCE_ID
            };

            struct v2f
            {
                float4 pos   : SV_POSITION;
                fixed4 color : COLOR;
                float3 wn    : TEXCOORD0;
                float3 wv    : TEXCOORD1;
                UNITY_VERTEX_OUTPUT_STEREO
            };

            v2f vert(appdata v)
            {
                v2f o;
                UNITY_SETUP_INSTANCE_ID(v);
                UNITY_INITIALIZE_OUTPUT(v2f, o);
                UNITY_INITIALIZE_VERTEX_OUTPUT_STEREO(o);
                o.pos = UnityObjectToClipPos(v.vertex);
                o.wn = UnityObjectToWorldNormal(v.normal);
                float3 wp = mul(unity_ObjectToWorld, v.vertex).xyz;
                o.wv = UnityWorldSpaceViewDir(wp);
                o.color = v.color;
                return o;
            }

            fixed4 frag(v2f i) : SV_Target
            {
                float f = abs(dot(normalize(i.wn), normalize(i.wv)));   // 1 = faccia al centro, 0 = bordo visto di profilo
                f = 0.06 + 0.94 * pow(saturate(f), _Soft);
                fixed4 c = i.color;
                c.a *= f;
                return c;
            }
            ENDCG
        }
    }
}
