#pragma once

#include "Graphics/GraphicsAPI.h"

namespace Helios
{
	class Renderer
	{
	public:
		Renderer() = default;
		Renderer(GraphicsAPI* api)
		{
			gfxAPI = api;
		}

		void Initialize(HWND hWnd, uint32_t w, uint32_t h, bool fullScreen) const;
		void RenderSceneIndexed(Scene* scene) const;
		void SetClearColor(float col[4]) const;
		void ClearScreen() const;
		void PresentToScreen() const;
		void CreateBuffer(Buffer* buffer, BufferDesc& desc, uint32_t numElements, const std::vector<Vertex>& vertices = { Vertex(DirectX::XMFLOAT3(0.0f,0.0f,0.0f),  DirectX::XMFLOAT4(0.0f,0.0f,0.0f,0.0f)) }, std::vector<uint32_t> indices = { 0 })const;
		void CreateVertexShader(Shader* shader, const std::wstring& shaderFileName, bool isCompiled) const;
	    void CreatePixelShader(Shader* shader, const std::wstring& shaderFileName, bool isCompiled) const;
		void CreateTexture(Texture* tex, const std::string& texFileName) const;
		
	private:

		inline static GraphicsAPI* gfxAPI = nullptr;
	};

}
