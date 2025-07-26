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

		GraphicsAPI* GetAPI() const
		{
			return gfxAPI;
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
		void SetCameraConstantBuffer(const DirectX::XMMATRIX& model, const DirectX::XMMATRIX& view, const DirectX::XMMATRIX& proj, Buffer* cbuffer)const;
		void SetDirectionalLightBuffer(Buffer* cbuffer, const DirectX::XMFLOAT3& direction, const DirectX::XMFLOAT4& color) const;
		void SetDepthShaderLightSpaceMatrixBuffer(Buffer* cbuffer, const DirectX::XMMATRIX& model, const DirectX::XMFLOAT3& position, const DirectX::XMFLOAT3& target, const DirectX::XMFLOAT3& up);
	private:

		inline static GraphicsAPI* gfxAPI = nullptr;
	};

}
