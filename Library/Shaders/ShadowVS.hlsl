

cbuffer MatrixBuffer : register(b1)
{  
    float4x4 WVP;
    float4x4 lightVP;  
    float3 lightPos;
    float padding;
};


struct VertexInputType
{
    float4 position : POSITION;
    float3 normal : NORMAL;
    float2 tex : TEXCOORD0;
    float4 color : COLOR;
};

struct PixelInputType
{
    float4 position : SV_POSITION;
    float2 tex : TEXCOORD0;
    float3 normal : NORMAL;
    float4 lightViewPosition : TEXCOORD1;
    float3 lightPos : TEXCOORD2;
};


PixelInputType main(VertexInputType input)
{
    PixelInputType output;
    input.position.w = 1.0f;		
    output.position = mul(input.position, WVP);
    output.tex = input.tex;
    output.normal = input.normal;

    output.lightViewPosition = mul(input.position, lightVP);
    output.lightPos = lightPos;
    
    return output;
}