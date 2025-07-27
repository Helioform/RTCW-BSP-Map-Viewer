
#include "D3D11GraphicsAPI.h"
#include "Shader.h"
#include "../Scene.h"

namespace Helios
{

		
		D3D11GraphicsAPI::D3D11GraphicsAPI()
		{

		}

		bool D3D11GraphicsAPI::Init(HWND hWnd, uint32_t w, uint32_t h, bool fs) 
		{
			HRESULT hr;

			hr = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&m_pDXGIFactory);

			if (FAILED(hr))
			{
				OutputDebugString(L"DXGI Factory Creation Failed.");
				return false;
			}

			if (!FindBestFeatureLevel())
				return false;

			if (!EnumerateComponents())
				return false;

			if (!EnumerateDisplayResolutions(w, h, fs))
				return false;

			UINT createDeviceFlags = 0;


#if defined(DEBUG) || defined(_DEBUG)
			createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

			hr = D3D11CreateDevice(nullptr,
				D3D_DRIVER_TYPE_HARDWARE,
				nullptr,
				createDeviceFlags,
				&m_maxSupportedFeatureLevel,
				1,
				D3D11_SDK_VERSION,
				&m_pD3D11Device,
				nullptr,
				&m_pDeviceContext);

			if (FAILED(hr))
			{
				OutputDebugString(L"Direct3D11 Device Creation Failed");
				return false;
			}

			bool success = false;
				        	
			SetWindowHandle(hWnd);
			
			if (!CreateSwapChain())
				return false;
			
			if (!CreateRenderTargetView())
				return false;
			
			if (!CreateDepthStencil())
				return false;
			
			CreateViewport(0, 0, GetScreenWidth(), GetScreenHeight());
			
			if (!CreateRasterizerState())
				return false;
			
			if (!CreateSampler())
				return false;

			if (!CreateBlendState())
				return false;

			if (!CreateShadowTargetView())
				return false;

			return true;
		}

		bool D3D11GraphicsAPI::Init(ID3D11Device* device, ID3D11DeviceContext* deviceContext, uint32_t w, uint32_t h)
		{
			m_pD3D11Device = device;
			m_pDeviceContext = deviceContext;
			SetScreenDimensions(w, h);
			return true;
		}

		bool D3D11GraphicsAPI::EnumerateFeatureLevels()
		{
			return true;
		}

		bool D3D11GraphicsAPI::FindBestFeatureLevel()
		{
			
				HRESULT hr = E_FAIL;
				const D3D_FEATURE_LEVEL featureLevels[] = {
					D3D_FEATURE_LEVEL_11_1,
					D3D_FEATURE_LEVEL_11_0,
					D3D_FEATURE_LEVEL_10_1,
					D3D_FEATURE_LEVEL_10_0,
					D3D_FEATURE_LEVEL_9_3,
					D3D_FEATURE_LEVEL_9_2,
					D3D_FEATURE_LEVEL_9_1
				};

				hr = D3D11CreateDevice(
					NULL,
					D3D_DRIVER_TYPE_HARDWARE,
					NULL,
					0,
					featureLevels,
					ARRAYSIZE(featureLevels),
					D3D11_SDK_VERSION,
					NULL,
					&m_maxSupportedFeatureLevel,
					NULL
				);

				if (FAILED(hr))
				{
					OutputDebugString(L"Could not determine feature level");
					return false;
				}

			
				return true;

		}

		bool D3D11GraphicsAPI::EnumerateDisplayResolutions(uint32_t screenWidth, uint32_t screenHeight, bool fullScreen)
		{
			SetFullScreen(fullScreen);

			if (m_pAdapter != nullptr)
			{
				IDXGIOutput* pOutput = nullptr;
				HRESULT hr;

				hr = m_pAdapter->EnumOutputs(0, &pOutput);
				UINT numModes = 0;
				DXGI_MODE_DESC* displayModes = nullptr;
				DXGI_FORMAT format = DXGI_FORMAT_R32G32B32A32_FLOAT;

				// Get the number of elements
				hr = pOutput->GetDisplayModeList(format, 0, &numModes, nullptr);

				if (FAILED(hr))
				{
					OutputDebugString(L"Can't get number of display modes");
					return false;
				}

				displayModes = new DXGI_MODE_DESC[numModes];
				hr = pOutput->GetDisplayModeList(format, 0, &numModes, displayModes);

				if (FAILED(hr))
				{
					OutputDebugString(L"Can't get list of display modes");
					return false;
				}

				m_videoCardInfo.numResolutionModes = numModes;

				for (auto i = 0; i < numModes; ++i)
				{
					m_videoCardInfo.resolutionModes.push_back(std::to_string(displayModes[i].Width) + "x" + std::to_string(displayModes[i].Height));
				}

				// choose the highest display mode if in fullscreen
				if (GetFullScreen())
				{
					SetScreenDimensions(displayModes[numModes - 1].Width, displayModes[numModes - 1].Height);
				}
				else
				{
					SetScreenDimensions(screenWidth, screenHeight);
				}

				delete[] displayModes;

				return true;
			}

			return false;
		}

		bool D3D11GraphicsAPI::CreateSwapChain()
		{
			if (m_pD3D11Device != nullptr)
			{
				if (m_pDXGIFactory != nullptr)
				{
					DXGI_SWAP_CHAIN_DESC swapChainDesc;
					SecureZeroMemory(&swapChainDesc, sizeof(swapChainDesc));

					swapChainDesc.BufferDesc.Width = GetScreenWidth();
					swapChainDesc.BufferDesc.Height = GetScreenHeight();
					swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
					swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
					swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
					swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
					swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

					// No MSAA
					swapChainDesc.SampleDesc.Count = 1;
					swapChainDesc.SampleDesc.Quality = 0;

					swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT | DXGI_USAGE_SHADER_INPUT;;
					swapChainDesc.BufferCount = 1;
					swapChainDesc.OutputWindow = m_hWnd;
					swapChainDesc.Windowed = !GetFullScreen();
					swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
					swapChainDesc.Flags = 0;

					HRESULT hr = m_pDXGIFactory->CreateSwapChain(m_pD3D11Device, &swapChainDesc, &m_pSwapChain);

					if (FAILED(hr))
					{
						OutputDebugString(L"Swap chain creation failed");
						return false;
					}

					return true;
				}
			}

			return false;
		}

		bool D3D11GraphicsAPI::CreateRenderTargetView()
		{
			if (m_pSwapChain != nullptr)
			{
				HRESULT hr = m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&m_pBackBuffer));

				if (FAILED(hr))
				{
					OutputDebugString(L"Cannot get swapchain buffer");
					return false;
				}

				if (m_pD3D11Device != nullptr)
					hr = m_pD3D11Device->CreateRenderTargetView(m_pBackBuffer, 0, &m_pRenderTargetView);

				if (FAILED(hr))
				{
					OutputDebugString(L"Cannot create render target view");
					return false;
				}

				return true;
			}

			return false;
		}


		bool D3D11GraphicsAPI::CreateDepthStencil()
		{
			D3D11_TEXTURE2D_DESC depthStencilDesc;
			depthStencilDesc.Width = GetScreenWidth();
			depthStencilDesc.Height = GetScreenHeight();
			depthStencilDesc.MipLevels = 1;
			depthStencilDesc.ArraySize = 1;
			depthStencilDesc.Format = DXGI_FORMAT_R24G8_TYPELESS;

			/*
			// Use 4X MSAA? --must match swap chain MSAA values.
			if (mEnable4xMsaa)
			{
				depthStencilDesc.SampleDesc.Count = 4;
				depthStencilDesc.SampleDesc.Quality = m4xMsaaQuality - 1;
			}
			*/

			depthStencilDesc.SampleDesc.Count = 1;
			depthStencilDesc.SampleDesc.Quality = 0;
			depthStencilDesc.Usage = D3D11_USAGE_DEFAULT;
			depthStencilDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL | D3D11_BIND_SHADER_RESOURCE;
			depthStencilDesc.CPUAccessFlags = 0;
			depthStencilDesc.MiscFlags = 0;
			ID3D11Texture2D* depthStencilBuffer;

			HRESULT hr = m_pD3D11Device->CreateTexture2D(&depthStencilDesc, 0, &depthStencilBuffer);

			if (FAILED(hr))
			{
				OutputDebugString(L"Cannot create depth stencil buffer");
				return false;
			}

			D3D11_DEPTH_STENCIL_VIEW_DESC dsvDesc = {};
			dsvDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
			dsvDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;

			hr = m_pD3D11Device->CreateDepthStencilView(depthStencilBuffer, &dsvDesc, &m_pDepthStencilView);

			if (FAILED(hr))
			{
				OutputDebugString(L"Cannot create depth stencil view");
				return false;
			}

			D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
			srvDesc.Format = DXGI_FORMAT_R24_UNORM_X8_TYPELESS;
			srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
			srvDesc.Texture2D.MostDetailedMip = 0;
			srvDesc.Texture2D.MipLevels = 1;
			hr = m_pD3D11Device->CreateShaderResourceView(depthStencilBuffer, &srvDesc, &m_shadowSRV);

			if (hr != S_OK)
				return false;

			if (m_pDeviceContext != nullptr)
			{
				m_pDeviceContext->OMSetRenderTargets(1, &m_pRenderTargetView, m_pDepthStencilView);
			}

			return true;
		}

		void D3D11GraphicsAPI::CreateViewport(uint32_t topLeftX, uint32_t topLeftY, uint32_t width, uint32_t height)
		{
			D3D11_VIEWPORT viewport;
			viewport.TopLeftX = topLeftX;
			viewport.TopLeftY = topLeftY;
			viewport.Width = static_cast<float>(width);
			viewport.Height = static_cast<float>(height);
			viewport.MinDepth = 0.0f;
			viewport.MaxDepth = 1.0f;

			m_pDeviceContext->RSSetViewports(1, &viewport);
		}


		bool D3D11GraphicsAPI::CreateRasterizerState()
		{
			D3D11_RASTERIZER_DESC rsDesc;
			ZeroMemory(&rsDesc, sizeof(D3D11_RASTERIZER_DESC));
			rsDesc.DepthBias = 0;
			rsDesc.DepthBiasClamp = 0.0f;
			rsDesc.FillMode = D3D11_FILL_SOLID;
			rsDesc.CullMode = D3D11_CULL_BACK;
			rsDesc.FrontCounterClockwise = false;
			rsDesc.DepthClipEnable = true;
			rsDesc.MultisampleEnable = false;
			rsDesc.ScissorEnable = false;
			rsDesc.SlopeScaledDepthBias = 0.0f;
			rsDesc.AntialiasedLineEnable = false;
			ID3D11RasterizerState* pCullBackRS;

			HRESULT hr = m_pD3D11Device->CreateRasterizerState(&rsDesc, &pCullBackRS);

			if (FAILED(hr))
			{
				OutputDebugString(L"Cannot create rasterrizer state\n");
				return false;
			}

			m_rasterizerStates.push_back(pCullBackRS);

			m_pDeviceContext->RSSetState(m_rasterizerStates[0]);
			return true;
		}

		void D3D11GraphicsAPI::SetClearColor(float col[4])
		{
			m_clearColor[0] = col[0];
			m_clearColor[1] = col[1];
			m_clearColor[2] = col[2];
			m_clearColor[3] = col[3];
		}

		

		/*void D3D11GraphicsAPI::CreateInputLayout(const Shader& shader)
		{
			HRESULT hr;

			hr = m_pD3D11Device->CreateInputLayout(descColor,sizeof(descColor)/7, shader.pByteData, shader.dataSize, pInputLayout);

			if (FAILED(hr))
				OutputDebugString(L"Cannot create input layout\n");
		}*/

		void D3D11GraphicsAPI::CreateTexture()
		{
		}

		bool D3D11GraphicsAPI::CreateTexture(Texture* texture, const std::string& texFileName)
		{
			return true;
		}

		bool D3D11GraphicsAPI::CreateVertexShader( Shader* shader, const std::wstring& shaderFileName, bool isCompiled)
		{
			if(!isCompiled)
				return CompileShader(shader, shaderFileName, SHADER_TYPE::VERTEX_SHADER);
			else
			{
				ID3D11VertexShader* vs = (ID3D11VertexShader*)shader->GetVertexShaderData();
				
				shader->LoadFromFile(shaderFileName);
				uint64_t s = shader->GetSize();

				HRESULT hr = m_pD3D11Device->CreateVertexShader(shader->GetShaderByteData(),shader->GetSize(), nullptr, &vs);

				D3D11_INPUT_ELEMENT_DESC inputDescs[] = {	{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0 , D3D11_INPUT_PER_VERTEX_DATA, 0},
															{"NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},
															{"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT,  D3D11_INPUT_PER_VERTEX_DATA, 0},
															{"COLOR", 0,DXGI_FORMAT_R32G32B32A32_FLOAT, 0 ,D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0}
													};

				m_inputLayouts.push_back(nullptr);
				hr = m_pD3D11Device->CreateInputLayout(inputDescs, 4, shader->GetShaderByteData(), shader->GetSize(), &m_inputLayouts.back());

				if (hr != S_OK)
					return false;
			}

			return true;
		}

		bool D3D11GraphicsAPI::CreatePixelShader( Shader* shader, const std::wstring& shaderFileName, bool isCompiled)
		{
			if(!isCompiled)
				return CompileShader(shader, shaderFileName, SHADER_TYPE::PIXEL_SHADER);
			else
			{
				ID3D11PixelShader* ps = (ID3D11PixelShader*)shader->GetPixelShaderData();
				HRESULT hr = m_pD3D11Device->CreatePixelShader(reinterpret_cast<const void*>(shader->GetShaderByteData()), shader->GetSize(), nullptr, &ps);
			
				if (hr != S_OK)
					return false;
			}

			return true;
		}

		bool D3D11GraphicsAPI::CompileShader(Shader* shader, const std::wstring& shaderFileName, SHADER_TYPE type)
		{
			UINT flags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined( DEBUG ) || defined( _DEBUG )
			flags |= D3DCOMPILE_DEBUG;
#endif
			LPCSTR profile = "vs_5_0";

				if (m_maxSupportedFeatureLevel == D3D_FEATURE_LEVEL_11_1)
				{
					profile = "vs_5_0";

					if (type == SHADER_TYPE::PIXEL_SHADER)
						profile = "ps_5_0";
				}

			
			ID3DBlob* shaderBlob = nullptr;
			ID3DBlob* errorBlob = nullptr;

			HRESULT hr;

			std::wstring path = L".\\Library\\Shaders\\" + shaderFileName;

			if (type == SHADER_TYPE::VERTEX_SHADER)
			{
				//hr = D3DReadFileToBlob(L"ColorVS.cso", &shaderBlob);
				hr = D3DCompileFromFile( path.c_str(), nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE,
					"main", profile,
					flags, 0, &shaderBlob, &errorBlob);
				
				if (hr != S_OK)
				{

					path = GetEXEPath() + L"\\" + shaderFileName;
					// try current working directory
					hr = D3DCompileFromFile(path.c_str(), nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE,
						"main", profile,
						flags, 0, &shaderBlob, &errorBlob);

					if (hr != S_OK)
					{

						if (errorBlob)
						{
							OutputDebugStringA((char*)errorBlob->GetBufferPointer());
							errorBlob->Release();
						}

						if (shaderBlob)
							shaderBlob->Release();
						return false;
					}

					D3DShader* d3dShader = (D3DShader*)shader;

					HRESULT hr = m_pD3D11Device->CreateVertexShader(shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), nullptr, &d3dShader->m_vertexShader);

					D3D11_INPUT_ELEMENT_DESC inputDescs[] = { {"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0 , D3D11_INPUT_PER_VERTEX_DATA, 0},
															{"NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},
															{"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT,  D3D11_INPUT_PER_VERTEX_DATA, 0},
															{"COLOR", 0,DXGI_FORMAT_R32G32B32A32_FLOAT, 0 ,D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0}
					};

					m_inputLayouts.push_back(nullptr);
					hr = m_pD3D11Device->CreateInputLayout(inputDescs, 4, shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), &m_inputLayouts.back());

				}
				else
				{
					D3DShader* d3dShader = (D3DShader*)shader;
					
					HRESULT hr = m_pD3D11Device->CreateVertexShader(shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), nullptr, &d3dShader->m_vertexShader);

					D3D11_INPUT_ELEMENT_DESC inputDescs[] = { {"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0 , D3D11_INPUT_PER_VERTEX_DATA, 0},
															{"NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},
															{"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT,  D3D11_INPUT_PER_VERTEX_DATA, 0},
															{"COLOR", 0,DXGI_FORMAT_R32G32B32A32_FLOAT, 0 ,D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0}
					};

					m_inputLayouts.push_back(nullptr);
					hr = m_pD3D11Device->CreateInputLayout(inputDescs, 4, shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), &m_inputLayouts.back());

				}

				
			}
			else if (type == SHADER_TYPE::PIXEL_SHADER)
			{
				hr = D3DCompileFromFile(path.c_str(), nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE,
					"main", profile,
					flags, 0, &shaderBlob, &errorBlob);

				if (hr != S_OK)
				{
					path = GetEXEPath() + L"\\" + shaderFileName;

					hr = D3DCompileFromFile(path.c_str(), nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE,
						"main", profile,
						flags, 0, &shaderBlob, &errorBlob);

					if (hr != S_OK)
					{
						if (errorBlob)
						{
							OutputDebugStringA((char*)errorBlob->GetBufferPointer());
							errorBlob->Release();
						}

						if (shaderBlob)
							shaderBlob->Release();
						return false;
					}

					D3DShader* d3dShader = (D3DShader*)shader;

					m_pD3D11Device->CreatePixelShader(reinterpret_cast<const void*>(shaderBlob->GetBufferPointer()), shaderBlob->GetBufferSize(), nullptr, &d3dShader->m_pixelShader);

				}
				else
				{
					D3DShader* d3dShader = (D3DShader*)shader;
					m_pD3D11Device->CreatePixelShader(reinterpret_cast<const void*>(shaderBlob->GetBufferPointer()), shaderBlob->GetBufferSize(), nullptr, &d3dShader->m_pixelShader);
				}
			}	

			return true;
		
		}

		void D3D11GraphicsAPI::RenderQuad()
		{
		}

		void D3D11GraphicsAPI::RenderMeshesIndexed(std::vector<Mesh>& meshes, std::vector<Buffer*>& buffers, std::vector<Buffer*>& indexBuffers, std::vector<Shader*>& shaders)
		{		
			//m_pDeviceContext->IASetInputLayout(m_inputLayouts[0]);
			//m_pDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
			//m_pDeviceContext->RSSetState(m_rasterizerStates[0]);

			//UINT stride = sizeof(Vertex);
			//UINT offset = 0;

			//for (auto& m : meshes)
			//{
			//	
			//	D3DBuffer* pBuffer = (D3DBuffer*)buffers[m.GetVertexBufferID()];
			//	D3DBuffer* pIndexBuffer = (D3DBuffer*)indexBuffers[m.GetVertexBufferID()];
			//	D3DShader* pShader = (D3DShader*)shaders[m.GetShaderID()];

			//	m_pDeviceContext->IASetVertexBuffers(0, 1, &pBuffer->pD3DBuffer, &stride, &offset);
			//	m_pDeviceContext->IASetIndexBuffer(pIndexBuffer->pD3DBuffer, DXGI_FORMAT_R32_UINT, offset);
			//	m_pDeviceContext->VSSetShader(pShader->m_vertexShader, nullptr, 0);
			//	m_pDeviceContext->PSSetShader(pShader->m_pixelShader, nullptr, 0);
			////	m_pDeviceContext->PSSetShaderResources(0,1, &m.GetTextures()[0]->m_pShaderResourceView);
			//	m_pDeviceContext->DrawIndexed(m.GetNumIndices(),0, 0);
			//}
		}

		void D3D11GraphicsAPI::RenderSceneIndexed(Scene* scene)
		{
			m_pDeviceContext->OMSetRenderTargets(0, nullptr, m_shadowDSV);
			m_pDeviceContext->ClearDepthStencilView(m_shadowDSV, D3D11_CLEAR_DEPTH, 1.0f, 0);
			scene->SetLightBuffer();

			// render the depth from light point fo view first

			if (m_inputLayouts.size() > 0)
				m_pDeviceContext->IASetInputLayout(m_inputLayouts[0]);
			else
				return;
			
			m_pDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
			m_pDeviceContext->RSSetState(m_rasterizerStates[0]);

			UINT stride = sizeof(Vertex);
			UINT offset = 0;
			m_pDeviceContext->PSSetSamplers(0, 1, &m_sampleStateClamp);
			m_pDeviceContext->PSSetSamplers(1, 1, &m_sampleStateWrap);

			for (auto& m : scene->GetMeshes())
			{
				if (!m.GetIsDestroyed())
				{
					D3DBuffer* pBuffer = (D3DBuffer*)scene->GetBuffers()[m.GetVertexBufferID()];
					D3DBuffer* pIndexBuffer = (D3DBuffer*)scene->GetIndexBuffers()[m.GetVertexBufferID()];
					D3DShader* pShader = (D3DShader*)scene->GetShaders()[L"LightSpaceDepthVS.hlsl"].get();

					m_pDeviceContext->IASetVertexBuffers(0, 1, &pBuffer->pD3DBuffer, &stride, &offset);
					m_pDeviceContext->IASetIndexBuffer(pIndexBuffer->pD3DBuffer, DXGI_FORMAT_R32_UINT, offset);
					m_pDeviceContext->VSSetShader(pShader->m_vertexShader, nullptr, 0);
					m_pDeviceContext->DrawIndexed(m.GetNumIndices(), 0, 0);
				}

			}

			// second pass, render all geomtry with shadows
			m_clearColor[0] = 0.0f;
			m_clearColor[1] = 0.0f;
			m_clearColor[2] = 0.0f;
			m_clearColor[3] = 1.0f;

			m_pDeviceContext->OMSetRenderTargets(1, &m_pRenderTargetView, m_pDepthStencilView);
			m_pDeviceContext->ClearRenderTargetView(m_pRenderTargetView, m_clearColor);
			m_pDeviceContext->ClearDepthStencilView(m_pDepthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);

			scene->SetCameraConstantBufferParams();

			for (auto& m : scene->GetMeshes())
			{
				if (!m.GetIsDestroyed())
				{
					

					D3DBuffer* pBuffer = (D3DBuffer*)scene->GetBuffers()[m.GetVertexBufferID()];
					D3DBuffer* pIndexBuffer = (D3DBuffer*)scene->GetIndexBuffers()[m.GetVertexBufferID()];
					D3DShader* pVShader = (D3DShader*)scene->GetShaders()[L"ShadowVS.hlsl"].get();
					D3DShader* pPShader = (D3DShader*)scene->GetShaders()[L"ShadowPS.hlsl"].get();


					m_pDeviceContext->IASetVertexBuffers(0, 1, &pBuffer->pD3DBuffer, &stride, &offset);
					m_pDeviceContext->IASetIndexBuffer(pIndexBuffer->pD3DBuffer, DXGI_FORMAT_R32_UINT, offset);
					m_pDeviceContext->VSSetShader(pVShader->m_vertexShader, nullptr, 0);
					m_pDeviceContext->PSSetShader(pPShader->m_pixelShader, nullptr, 0);
					m_pDeviceContext->PSSetShaderResources(0, 1, &m.GetTextures()[0]->m_pShaderResourceView);
					m_pDeviceContext->PSSetShaderResources(1, 1, &m_shadowSRV);
					m_pDeviceContext->DrawIndexed(m.GetNumIndices(), 0, 0);
				}
			}

		}

		bool D3D11GraphicsAPI::CreateBuffer(Buffer* buffer, BufferDesc& desc, uint32_t numElements, const std::vector<Vertex>& vertices, const std::vector<uint32_t> indices)
		{
			D3D11_BUFFER_DESC vbd;
			vbd.Usage = static_cast<D3D11_USAGE>(desc.usage);
			vbd.ByteWidth = desc.byteWidth;

			if (desc.type == VERTEX_BUFFER)
				vbd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
			else if (desc.type == INDEX_BUFFER)
				vbd.BindFlags = D3D11_BIND_INDEX_BUFFER;
			else if (desc.type == CONSTANT_BUFFER)
				vbd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
			else
				vbd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

			if (desc.cpuAccess == 0)
				vbd.CPUAccessFlags = 0;
			else
				vbd.CPUAccessFlags = static_cast<D3D11_CPU_ACCESS_FLAG>(desc.cpuAccess);
			vbd.MiscFlags = 0;
			vbd.StructureByteStride = 0;

			HRESULT hr;

			D3DBuffer* pBuffer = (D3DBuffer*)buffer;

			if (desc.type == CONSTANT_BUFFER)
			{
				hr = m_pD3D11Device->CreateBuffer(&vbd, nullptr, &pBuffer->pD3DBuffer);
				if (hr != S_OK)
					return false;
			}
			else
			{
				D3D11_SUBRESOURCE_DATA vinitData;
				
				if (desc.type == INDEX_BUFFER)
				{
					vinitData.pSysMem = indices.data();
					vinitData.SysMemPitch = 0;
					vinitData.SysMemSlicePitch = 0;
				}
				else
				{
					
					vinitData.pSysMem = vertices.data();
					vinitData.SysMemPitch = 0;
					vinitData.SysMemSlicePitch = 0;
				}

				hr = m_pD3D11Device->CreateBuffer(&vbd, &vinitData, &pBuffer->pD3DBuffer);

				if (hr != S_OK)
					return false;
			}

			return true;
		}

		bool D3D11GraphicsAPI::CreateSampler()
		{
			D3D11_SAMPLER_DESC samplerDesc;

			samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
			samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
			samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
			samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
			samplerDesc.MipLODBias = 0.0f;
			samplerDesc.MaxAnisotropy = 1;
			samplerDesc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
			samplerDesc.BorderColor[0] = 0;
			samplerDesc.BorderColor[1] = 0;
			samplerDesc.BorderColor[2] = 0;
			samplerDesc.BorderColor[3] = 0;
			samplerDesc.MinLOD = 0;
			samplerDesc.MaxLOD = D3D11_FLOAT32_MAX;

			// Create the texture sampler state.
			HRESULT result = m_pD3D11Device->CreateSamplerState(&samplerDesc, &m_sampleStateWrap);
			if (FAILED(result))
			{
				return false;
			}

			samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
			samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
			samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
			samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
			samplerDesc.MipLODBias = 0.0f;
			samplerDesc.MaxAnisotropy = 1;
			samplerDesc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
			samplerDesc.BorderColor[0] = 0;
			samplerDesc.BorderColor[1] = 0;
			samplerDesc.BorderColor[2] = 0;
			samplerDesc.BorderColor[3] = 0;
			samplerDesc.MinLOD = 0;
			samplerDesc.MaxLOD = D3D11_FLOAT32_MAX;

			// Create the clamp texture sampler state.
			result = m_pD3D11Device->CreateSamplerState(&samplerDesc, &m_sampleStateClamp);
			
			if (FAILED(result))
				return false;
			
			return true;
		}

		bool D3D11GraphicsAPI::CreateBlendState()
		{
			D3D11_BLEND_DESC blendStateDescription;

			ZeroMemory(&blendStateDescription, sizeof(D3D11_BLEND_DESC));
			
			blendStateDescription.RenderTarget[0].BlendEnable = TRUE;
			blendStateDescription.RenderTarget[0].SrcBlend = D3D11_BLEND_ONE;
			blendStateDescription.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
			blendStateDescription.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
			blendStateDescription.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
			blendStateDescription.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
			blendStateDescription.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
			blendStateDescription.RenderTarget[0].RenderTargetWriteMask = 0x0f;
			
			HRESULT	result = m_pD3D11Device->CreateBlendState(&blendStateDescription, &m_alphaEnableBlendingState);
			
			if (FAILED(result))
			{
				return false;
			}
					
			blendStateDescription.RenderTarget[0].BlendEnable = FALSE;
				
			result = m_pD3D11Device->CreateBlendState(&blendStateDescription, &m_alphaDisableBlendingState);
		
			if (FAILED(result))
			{
				return false;
			}

			return true;
		}

		void D3D11GraphicsAPI::TurnOffZBuffer()
		{
			m_pDeviceContext->OMSetDepthStencilState(m_depthDisabledStencilState, 1);
		}

		void D3D11GraphicsAPI::TurnOnZBuffer()
		{
			m_pDeviceContext->OMSetDepthStencilState(m_depthStencilState, 1);
		}

		bool D3D11GraphicsAPI::DrawText(uint32_t posX, uint32_t posY, const std::string& text)
		{
			return false;

		}

		bool D3D11GraphicsAPI::CreateShadowTargetView()
		{
			HRESULT hr;
			D3D11_SHADER_RESOURCE_VIEW_DESC shaderResourceViewDesc = {};
			D3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc = {};
			D3D11_TEXTURE2D_DESC texDesc;
			
			memset(&texDesc, 0, sizeof(D3D11_TEXTURE2D_DESC));
			texDesc.Width =	1024;
			texDesc.Height = 1024; 
			texDesc.MipLevels = 1;
			texDesc.ArraySize = 1;
			texDesc.Format = DXGI_FORMAT_R24G8_TYPELESS;
			texDesc.SampleDesc.Count = 1;
			texDesc.SampleDesc.Quality = 0;
			texDesc.Usage = D3D11_USAGE_DEFAULT;
			texDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE | D3D11_BIND_DEPTH_STENCIL;
			//texDesc.MiscFlags = D3D11_RESOURCE_MISC_GENERATE_MIPS;

			hr = m_pD3D11Device->CreateTexture2D(&texDesc, nullptr, &m_shadowMap);

			if (FAILED(hr))
			{
				OutputDebugString(L"Cannot create shadow map\n");
				return false;
			}

			
			shaderResourceViewDesc.Format = DXGI_FORMAT_R24_UNORM_X8_TYPELESS;
			shaderResourceViewDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
			shaderResourceViewDesc.Texture2D.MostDetailedMip = 0;
			shaderResourceViewDesc.Texture2D.MipLevels = 1;

			// Create the shader resource view.
			hr = m_pD3D11Device->CreateShaderResourceView(m_shadowMap, &shaderResourceViewDesc, &m_shadowSRV);
			
			if (FAILED(hr))
			{
				OutputDebugString(L"Cannot create shader resource view\n");
				return false;
			} 

			// Set up the depth stencil view description.
			depthStencilViewDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
			depthStencilViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
			

			// Create the depth stencil view.
			hr = m_pD3D11Device->CreateDepthStencilView(m_shadowMap, &depthStencilViewDesc, &m_shadowDSV);
			if (FAILED(hr))
			{
				OutputDebugString(L"Cannot create depth stencil view\n");
				return false;
			}

			return true;
			//m_pDeviceContext->OMSetRenderTargets(0, nullptr, m_shadowDSV);
		}

		bool D3D11GraphicsAPI::EnumerateComponents()
		{
			UINT i = 0;

			if (m_pDXGIFactory != nullptr)
			{
				// Get main video card
				HRESULT hr = m_pDXGIFactory->EnumAdapters(i, &m_pAdapter);

				if (hr != S_OK)
					return false;
				DXGI_ADAPTER_DESC desc;
				m_pAdapter->GetDesc(&desc);
				std::wstring text = L"Adapter: ";
				text += desc.Description;
				text += L"\n";
				m_videoCardInfo.description += desc.Description;
				OutputDebugString(text.c_str());

				return true;
			}

			return false;
		}


		bool D3D11GraphicsAPI::CreateShaderResource(ID3D11Device* device, uint32_t width, uint32_t height)
		{
			//D3D11_TEXTURE2D_DESC textureDesc;
			//HRESULT result;
			//D3D11_RENDER_TARGET_VIEW_DESC renderTargetViewDesc;
			//D3D11_SHADER_RESOURCE_VIEW_DESC shaderResourceViewDesc;
			//ID3D11RenderTargetView* renderTargetView;
			//// Initialize the render target texture description.
			//ZeroMemory(&textureDesc, sizeof(textureDesc));

			////// Setup the render target texture description.
			//textureDesc.Width = width;
			//textureDesc.Height = height;
			//textureDesc.MipLevels = 1;
			//textureDesc.ArraySize = 1;
			//textureDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
			//textureDesc.SampleDesc.Count = 1;
			//textureDesc.Usage = D3D11_USAGE_DEFAULT;
			//textureDesc.BindFlags = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;
			//textureDesc.CPUAccessFlags = 0;
			//textureDesc.MiscFlags = 0;

			////// Create the render target texture.
			//if(device != nullptr)
			//	result = device->CreateTexture2D(&textureDesc, NULL, &m_pRenderTargetTexture);
			//else
			//	result = m_pD3D11Device->CreateTexture2D(&textureDesc, NULL, &m_pRenderTargetTexture);
			//
			//if (FAILED(result))
			//{
			//	return false;
			//}

			////// Setup the description of the render target view.
			//renderTargetViewDesc.Format = textureDesc.Format;
			//renderTargetViewDesc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
			//renderTargetViewDesc.Texture2D.MipSlice = 0;

			////// Create the render target view.
			//if(device != nullptr)
			//	result = device->CreateRenderTargetView(m_pRenderTargetTexture, &renderTargetViewDesc, &m_pRenderTV);
			//else
			//	result = m_pD3D11Device->CreateRenderTargetView(m_pRenderTargetTexture, &renderTargetViewDesc, &m_pRenderTV);
			//
			//if (FAILED(result))
			//{
			//	return false;
			//}

			//// Setup the description of the shader resource view.
			//shaderResourceViewDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
			//shaderResourceViewDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
			//shaderResourceViewDesc.Texture2D.MostDetailedMip = 0;
			//shaderResourceViewDesc.Texture2D.MipLevels = 1;

			//// Create the shader resource view.
			//if(device != nullptr)
			//	result = device->CreateShaderResourceView(m_pRenderTargetTexture, &shaderResourceViewDesc, &m_shaderResourceView);
			//else
			//	result = m_pD3D11Device->CreateShaderResourceView(m_pRenderTargetTexture, &shaderResourceViewDesc, &m_shaderResourceView);

			//if (FAILED(result))
			//	return false;
			

			return true;
		}


		void D3D11GraphicsAPI::ClearScreen()
		{
			
			
			//pDeviceContext->ClearDepthStencilView(m_pDepthStencilView,D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

			/*m_clearColor[0] = 1.0f;
			m_clearColor[1] = 0.0f;
			m_clearColor[2] = 0.0f;
			m_clearColor[3] = 1.0f;


			pDeviceContext->ClearRenderTargetView(m_shadowTargetView, m_clearColor);
			pDeviceContext->ClearDepthStencilView(m_shadowDSV, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);*/

		}
		
		void D3D11GraphicsAPI::PresentToScreen()
		{
			HRESULT hr = SwapChain()->Present(0, 0);
		}
	
}
	
