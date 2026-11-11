// Lit URP semplice con colori di vertice: per le mesh da splat (IDOL) che hanno solo COLOR_0 e materiale unlit.
// Luce principale + luci aggiuntive (vertex/pixel), ombre ricevute e proiettate. Niente texture.
Shader "Libreria/VertexColorLit"
{
    Properties { _Tint ("Tint", Color) = (1,1,1,1) }
    SubShader
    {
        Tags { "RenderType"="Opaque" "RenderPipeline"="UniversalPipeline" "Queue"="Geometry" }
        Pass
        {
            Name "ForwardLit"
            Tags { "LightMode"="UniversalForward" }
            Cull Back
            HLSLPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            #pragma multi_compile _ _MAIN_LIGHT_SHADOWS _MAIN_LIGHT_SHADOWS_CASCADE
            #pragma multi_compile _ _ADDITIONAL_LIGHTS
            #pragma multi_compile_instancing
            #include "Packages/com.unity.render-pipelines.universal/ShaderLibrary/Core.hlsl"
            #include "Packages/com.unity.render-pipelines.universal/ShaderLibrary/Lighting.hlsl"
            CBUFFER_START(UnityPerMaterial)
                half4 _Tint;
            CBUFFER_END
            struct A { float4 pos:POSITION; float3 nrm:NORMAL; half4 col:COLOR; UNITY_VERTEX_INPUT_INSTANCE_ID };
            struct V { float4 cs:SV_POSITION; float3 ws:TEXCOORD0; half3 n:TEXCOORD1; half4 col:COLOR; UNITY_VERTEX_OUTPUT_STEREO };
            V vert(A i)
            {
                V o; UNITY_SETUP_INSTANCE_ID(i); UNITY_INITIALIZE_VERTEX_OUTPUT_STEREO(o);
                o.ws = TransformObjectToWorld(i.pos.xyz);
                o.cs = TransformWorldToHClip(o.ws);
                o.n = TransformObjectToWorldNormal(i.nrm);
                o.col = i.col; return o;
            }
            half4 frag(V i) : SV_Target
            {
                half3 n = normalize(i.n);
                half3 albedo = i.col.rgb * _Tint.rgb;
                float4 sc = TransformWorldToShadowCoord(i.ws);
                Light l = GetMainLight(sc);
                half3 lit = SampleSH(n) + l.color * l.distanceAttenuation * l.shadowAttenuation * saturate(dot(n, l.direction));
                #ifdef _ADDITIONAL_LIGHTS
                uint c = GetAdditionalLightsCount();
                for (uint k = 0u; k < c; k++)
                {
                    Light a = GetAdditionalLight(k, i.ws);
                    lit += a.color * a.distanceAttenuation * a.shadowAttenuation * saturate(dot(n, a.direction));
                }
                #endif
                return half4(albedo * lit, 1);
            }
            ENDHLSL
        }
        Pass
        {
            Name "ShadowCaster"
            Tags { "LightMode"="ShadowCaster" }
            ColorMask 0
            HLSLPROGRAM
            #pragma vertex vs
            #pragma fragment fs
            #include "Packages/com.unity.render-pipelines.universal/ShaderLibrary/Core.hlsl"
            #include "Packages/com.unity.render-pipelines.universal/ShaderLibrary/Shadows.hlsl"
            float3 _LightDirection;
            struct A { float4 pos:POSITION; float3 nrm:NORMAL; };
            float4 vs(A i) : SV_POSITION
            {
                float3 ws = TransformObjectToWorld(i.pos.xyz);
                float3 n = TransformObjectToWorldNormal(i.nrm);
                float4 cs = TransformWorldToHClip(ApplyShadowBias(ws, n, _LightDirection));
                #if UNITY_REVERSED_Z
                cs.z = min(cs.z, UNITY_NEAR_CLIP_VALUE * cs.w);
                #else
                cs.z = max(cs.z, UNITY_NEAR_CLIP_VALUE * cs.w);
                #endif
                return cs;
            }
            half4 fs() : SV_Target { return 0; }
            ENDHLSL
        }
    }
}
