#pragma once


#include "CommonHeaders.h"
#include "Primitives.h"
#include "Shader.h"

namespace Helios
{
	class Scene;
	class Mesh;
	struct Buffer;
	struct BufferDesc;
	struct Shader;
	struct Vertex;
	struct Texture;


		struct GraphicsDeviceDesc
		{
			std::wstring				description = L"";
			uint64_t					videoMemory;
			uint64_t					systemMemory;
			uint32_t					numResolutionModes;
			std::vector<std::string>	resolutionModes;
		};

		class GraphicsAPI
		{
		
		public:
			GraphicsAPI() = default;
			virtual ~GraphicsAPI() {}

			virtual void Init(HWND hWnd, uint32_t width, uint32_t height, bool fullScreen) = 0;
			virtual void EnumerateComponents() = 0;
			virtual void EnumerateDisplayResolutions(uint32_t screenWidth, uint32_t screenHeight, bool fullScreen) = 0;
			virtual void CreateViewport(uint32_t topLeftX, uint32_t topLeftY, uint32_t width, uint32_t height) = 0;
			virtual void CreateTexture() = 0;
			virtual void SetClearColor(float col[4]) = 0;
			virtual void ClearScreen() = 0;
			virtual void PresentToScreen() = 0;
			virtual void CreateVertexShader(Shader* shader, const std::wstring& shaderFileName, bool isCompiled) = 0;
			virtual void CreatePixelShader(Shader* shader, const std::wstring& shaderFileName, bool isCompiled) = 0;
			virtual void CreateBuffer(Buffer* buffer, BufferDesc& desc, uint32_t numElements, const std::vector<Vertex>& vertices = { Vertex(DirectX::XMFLOAT3(0.0f,0.0f,0.0f),  DirectX::XMFLOAT4(0.0f,0.0f,0.0f,0.0f)) }, std::vector<uint32_t> indices = { 0 }) = 0;
			virtual void RenderQuad() = 0;
			virtual void RenderMeshesIndexed(std::vector<Mesh>& meshes, std::vector<Buffer*>& buffers, std::vector<Buffer*>& indexBuffers, std::vector<Shader*>& shaders) = 0;
			virtual void RenderSceneIndexed( Scene* scene) = 0;
			virtual bool CreateSampler() = 0;
			virtual bool CreateTexture(Texture* texture, const std::string& texFileName) = 0;
			virtual bool DrawText(uint32_t posX, uint32_t posY, const std::string& text) = 0;
			virtual void TurnOffZBuffer() = 0;
			virtual void TurnOnZBuffer() = 0;
		
		private:
			
			uint32_t m_screenWidth, m_screenHeight;
			bool	m_fullScreen;
			
		public:
			GraphicsDeviceDesc	m_videoCardInfo;
			inline bool GetFullScreen() const {
				return m_fullScreen;
			}

			inline uint32_t GetScreenWidth() const {
				return m_screenWidth;
			}

			inline uint32_t GetScreenHeight() const {
				return m_screenHeight;
			}

			inline void SetFullScreen(bool fs)
			{
				m_fullScreen = fs;
			}

			inline void SetScreenDimensions(uint32_t w, uint32_t h)
			{
				m_screenHeight = h;
				m_screenWidth = w;
			}
		};
}