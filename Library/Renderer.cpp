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










