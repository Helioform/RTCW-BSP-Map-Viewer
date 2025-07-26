#include "Renderer.h"

void Helios::Renderer::Initialize(HWND hWnd, uint32_t w, uint32_t h, bool fullScreen) const
{ 
	gfxAPI->Init(hWnd, w, h, fullScreen);

}

void Helios::Renderer::RenderSceneIndexed(Scene* scene) const
{

	gfxAPI->RenderSceneIndexed(scene);
}

void Helios::Renderer::SetClearColor(float col[4]) const
{
	gfxAPI->SetClearColor(col);
}

void Helios::Renderer::ClearScreen() const
{
	gfxAPI->ClearScreen();
}

void Helios::Renderer::PresentToScreen() const
{
	gfxAPI->PresentToScreen();
}

void Helios::Renderer::CreateBuffer(Buffer* buffer, BufferDesc& desc, uint32_t numElements, const std::vector<Vertex>& vertices, std::vector<uint32_t> indices)const
{
	gfxAPI->CreateBuffer(buffer, desc, numElements, vertices, indices);
}

void Helios::Renderer::CreateVertexShader(Shader* shader, const std::wstring& shaderFileName, bool isCompiled) const
{
	gfxAPI->CreateVertexShader(shader, shaderFileName, isCompiled);
}

void Helios::Renderer::CreatePixelShader(Shader* shader, const std::wstring& shaderFileName, bool isCompiled) const
{
	gfxAPI->CreatePixelShader(shader, shaderFileName, isCompiled);
}

void Helios::Renderer::CreateTexture(Texture* tex, const std::string& texFileName) const
{
	gfxAPI->CreateTexture(tex, texFileName);
}

void Helios::Renderer::SetCameraConstantBuffer(const DirectX::XMMATRIX& model, const DirectX::XMMATRIX& view, const DirectX::XMMATRIX& proj, Buffer* cbuffer) const
{
	gfxAPI->SetCameraConstantBuffer(model, view, proj, cbuffer);
}



void Helios::Renderer::SetDirectionalLightBuffer(Buffer* cbuffer, const DirectX::XMFLOAT3& direction, const DirectX::XMFLOAT4& color) const
{
	gfxAPI->SetDirectionalLightBuffer(cbuffer, direction, color);

}

void Helios::Renderer::SetDepthShaderLightSpaceMatrixBuffer(Buffer* cbuffer, const DirectX::XMMATRIX& model, const DirectX::XMFLOAT3& position, const DirectX::XMFLOAT3& target, const DirectX::XMFLOAT3& up)
{
	gfxAPI->SetDepthShaderLightSpaceMatrixBuffer(cbuffer, model, position, target, up);
}




