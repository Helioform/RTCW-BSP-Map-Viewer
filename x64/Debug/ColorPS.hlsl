Texture2D shaderTexture : register(t0);
Texture2D depthTexture : register(t1);
SamplerState SampleType : register(s0);

cbuffer LightBuffer
{
   float4 diffuse_color;
   float3 direction;
   float padding;
};

struct PixelInputType
{
    float4 position : SV_POSITION;
    float3 normal : NORMAL;
    float2 tex : TEXCOORD0;
    float4 color : COLOR;
};



float4 main(PixelInputType input) : SV_TARGET
{
    //float3 lightDir = -direction;
    //float intensity = saturate(dot(input.normal, lightDir));
    //float4 color = saturate(diffuse_color*intensity);
    //float4 textureColor = ]
    float4 t = shaderTexture.Sample(SampleType, input.tex);
    //float4 d = depthTexture.Sample(SampleType, input.position.xy);
    //float3 projCoords = input.position.z / input.position.w;
    return t;
    
}