#pragma once



#define WIN32_LEAN_AND_MEAN             

#include "GraphicsAPI.h"
#include <wrl.h>
#include <d3d11.h>
#include <d3d11_1.h>
#include <dxgi.h>
#include <dxgi1_4.h>
#include <d3dcommon.h>
#include <d3dcompiler.h>
#include "D3DBuffer.h"
#include "../D3DShader.h"

namespace Helios
{
		class GraphicsAPI;
		class Scene;

		class  D3D11GraphicsAPI : public GraphicsAPI
		{	

		public:

			D3D11GraphicsAPI();

			virtual ~D3D11GraphicsAPI()
			{
				if (m_pD3D11Device != nullptr)
					m_pD3D11Device->Release();
				if (m_pDeviceContext != nullptr)
					m_pDeviceContext->Release();

			}

			void Init(HWND hWnd, uint32_t w, uint32_t h, bool fs);
			void Init(ID3D11Device* device, ID3D11DeviceContext* deviceContext, uint32_t w, uint32_t h);
			inline void SetWindowHandle(HWND hwnd) { m_hWnd = hwnd; }
			inline  ID3D11Device* D3DDevice() const { return m_pD3D11Device; }
			inline  ID3D11DeviceContext* DeviceContext() const { return m_pDeviceContext; }
			inline  IDXGISwapChain* SwapChain() const { return m_pSwapChain; }
			inline  ID3D11RenderTargetView* const RenderTargetView() { return m_pRenderTargetView; }
			inline  ID3D11DepthStencilView* DepthStencilView() const { return m_pDepthStencilView; }
			inline  ID3D11ShaderResourceView* ShaderResourceView() const {
				return m_shaderResourceView;
			}
			inline void SetRasterizerState(uint32_t rasterID)
			{
				m_pDeviceContext->RSSetState(m_rasterizerStates[rasterID]);

			}

			void EnumerateFeatureLevels();
		    void FindBestFeatureLevel();
			virtual void EnumerateComponents() override;
			virtual void EnumerateDisplayResolutions(uint32_t screenWidth, uint32_t screenHeight, bool fullScreen) override;

			void CreateSwapChain();
			void CreateRenderTargetView();
		    bool CreateShaderResource(ID3D11Device* device, uint32_t width, uint32_t height);
			void CreateDepthStencil();
			void CreateDepthStencil(ID3D11Device* device, ID3D11DeviceContext* deviceContext, uint16_t w, uint16_t h);
			void CreateViewport(uint32_t topLeftX, uint32_t topLeftY, uint32_t width, uint32_t height) override;
			void CreateRasterizerState();
			void SetClearColor(float col[4]);
			void ClearScreen(ID3D11DeviceContext* deviceContext);
			void ClearScreen();
			void PresentToScreen();
		
		//	void CreateInputLayout(const Shader& shader);
			void CreateTexture() override;
			bool CreateTexture(Texture* texture, const std::string& texFileName) override;
			virtual void CreateVertexShader(Shader* shader, const std::wstring& shaderFileName, bool isCompiled) override;
			virtual void CreatePixelShader(Shader* shader, const std::wstring& shaderFileName, bool isCompiled)  override;
			void CompileShader(Shader* shader, const std::wstring& shaderFileName, SHADER_TYPE type);
			virtual void RenderQuad() override;
			virtual void RenderMeshesIndexed(std::vector<Mesh>& meshes, std::vector<Buffer*>& buffers, std::vector<Buffer*>& indexBuffers, std::vector<Shader*>& shaders) override;
			virtual void RenderSceneIndexed( Scene* scene) override;
			virtual void CreateBuffer(Buffer* buffer, BufferDesc& desc, uint32_t numElements, const std::vector<Vertex>& vertices = { Vertex(DirectX::XMFLOAT3(0.0f,0.0f,0.0f),  DirectX::XMFLOAT4(0.0f,0.0f,0.0f,0.0f)) }, const std::vector<uint32_t> indices = { 0 }) override;
			virtual bool CreateSampler() override;
		    bool CreateBlendState();
			virtual void TurnOffZBuffer() override;
			virtual void TurnOnZBuffer() override;
			virtual bool DrawText(uint32_t posX, uint32_t posY, const std::string& text) override;
			void CreateShadowTargetView();

protected:
		 ID3D11Device* m_pD3D11Device = nullptr;
		ID3D11Device1* m_pD3D11Device1 = nullptr;
		ID3D11DeviceContext* m_pDeviceContext = nullptr;
		IDXGIFactory* m_pFactory = nullptr;
		IDXGIFactory2* m_pFactory2 = nullptr;
		IDXGISwapChain* m_pSwapChain = nullptr;
		ID3D11Texture2D* m_pDepthStencilBuffer = nullptr;
		ID3D11Texture2D* m_pBackBuffer = nullptr;
		ID3D11Texture2D* m_pRenderTargetTexture = nullptr;

		ID3D11DepthStencilView* m_pDepthStencilView;
		ID3D11RenderTargetView* m_pRenderTargetView = nullptr;
		
		ID3D11ShaderResourceView* m_shaderResourceView = nullptr;
		std::vector<ID3D11RasterizerState*>	m_rasterizerStates;
		IDXGIFactory2* m_pDXGIFactory = nullptr;
		IDXGIAdapter* m_pAdapter = nullptr;
		std::vector<ID3D11InputLayout*> m_inputLayouts;
		ID3D11SamplerState* m_sampleStateClamp;
		ID3D11SamplerState* m_sampleStateWrap;
		ID3D11DepthStencilState* m_depthStencilState;
		ID3D11DepthStencilState* m_depthDisabledStencilState;
		ID3D11BlendState* m_alphaEnableBlendingState;
		ID3D11BlendState* m_alphaDisableBlendingState;

		float m_clearColor[4];

		HWND								m_hWnd;
		D3D_FEATURE_LEVEL					m_maxSupportedFeatureLevel;
		ID3D11RenderTargetView*				m_shadowTargetView;
		ID3D11Texture2D*					m_shadowMap;
		ID3D11ShaderResourceView*			m_shadowSRV;
		ID3D11DepthStencilView*				m_shadowDSV;
		ID3D11Texture2D* m_shadowDSB;

		};

}