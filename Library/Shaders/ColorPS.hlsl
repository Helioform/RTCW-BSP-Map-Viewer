


struct VertexInputType
{
    float4 position : POSITION;
    float4 color : COLOR;
};

struct PixelInputType
{
    float4 position : SV_POSITION;
    float4 color : COLOR;
};


float4 main(PixelInputType input) : COLOR
{
    
    return input.color;
}