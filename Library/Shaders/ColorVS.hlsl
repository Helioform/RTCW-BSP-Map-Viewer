

cbuffer MatrixBuffer : register(b0)
{
    matrix worldMatrix;
    matrix viewMatrix;
    matrix projectionMatrix;
};


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


PixelInputType main(VertexInputType input)
{
    PixelInputType output;
    
	// Change the position vector to be 4 units for proper matrix calculations.
    input.position.w = 1.0f;
    matrix wvp = worldMatrix*viewMatrix*projectionMatrix;

	// Calculate the position of the vertex against the world, view, and projection matrices.
    output.position = mul(input.position, wvp);
	// Store the input color for the pixel shader to use.
    output.color = input.color;
    
    return output;
}