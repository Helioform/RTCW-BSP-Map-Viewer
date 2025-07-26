
#include "D3D11GraphicsAPI.h"
#include "D3DBuffer.h"
#include "../Scene.h"


namespace Helios
{

		
		D3D11GraphicsAPI::D3D11GraphicsAPI()
		{

		}

		void D3D11GraphicsAPI::Init(HWND hWnd, uint32_t w, uint32_t h, bool fs) 
		{
			HRESULT hr;

			hr = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&m_pDXGIFactory);

			if (FAILED(hr))
			{
				OutputDebugString(L"DXGI Factory Creation Failed.");
				return;
			}

			FindBestFeatureLevel();

			EnumerateComponents();
			EnumerateDisplayResolutions(w, h, fs);
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
				return;
			}

	
				        	
			SetWindowHandle(hWnd);
			CreateSwapChain();
			CreateRenderTargetView();
			CreateDepthStencil();
			CreateViewport(0, 0, GetScreenWidth(), GetScreenHeight());
			CreateRasterizerState();
			CreateSampler();
			CreateBlendState();

		}

		void D3D11GraphicsAPI::Init(ID3D11Device* device, ID3D11DeviceContext* deviceContext, uint32_t w, uint32_t h)
		{
			m_pD3D11Device = device;
			m_pDeviceContext = deviceContext;
			SetScreenDimensions(w, h);

		}

		void D3D11GraphicsAPI::EnumerateFeatureLevels()
		{
		}

		void D3D11GraphicsAPI::FindBestFeatureLevel()
		{
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
				}

			}

		}

		void D3D11GraphicsAPI::EnumerateDisplayResolutions(uint32_t screenWidth, uint32_t screenHeight, bool fullScreen)
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
					OutputDebugString(L"Can't get number of display modes");

				displayModes = new DXGI_MODE_DESC[numModes];
				hr = pOutput->GetDisplayModeList(format, 0, &numModes, displayModes);

				if (FAILED(hr))
					OutputDebugString(L"Can't get list of display modes");

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
			}
		}

		void D3D11GraphicsAPI::CreateSwapChain()
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
						OutputDebugString(L"Swap chain creation failed");
				}
			}

		}

		void D3D11GraphicsAPI::CreateRenderTargetView()
		{
			if (m_pSwapChain != nullptr)
			{
				HRESULT hr = m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&m_pBackBuffer));

				if (FAILED(hr))
				{
					OutputDebugString(L"Cannot get swapchain buffer");
					return;
				}

				if (m_pD3D11Device != nullptr)
					hr = m_pD3D11Device->CreateRenderTargetView(m_pBackBuffer, 0, &m_pRenderTargetView);

				if (FAILED(hr))
					OutputDebugString(L"Cannot create render target view");


			}
		}


		void D3D11GraphicsAPI::CreateDepthStencil()
		{
			D3D11_TEXTURE2D_DESC depthStencilDesc;
			depthStencilDesc.Width = GetScreenWidth();
			depthStencilDesc.Height = GetScreenHeight();
			depthStencilDesc.MipLevels = 1;
			depthStencilDesc.ArraySize = 1;
			depthStencilDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;

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
			depthStencilDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
			depthStencilDesc.CPUAccessFlags = 0;
			depthStencilDesc.MiscFlags = 0;
			ID3D11Texture2D* depthStencilBuffer;

			HRESULT hr = m_pD3D11Device->CreateTexture2D(&depthStencilDesc, 0, &depthStencilBuffer);

			if (FAILED(hr))
				OutputDebugString(L"Cannot create depth stencil buffer");

			hr = m_pD3D11Device->CreateDepthStencilView(depthStencilBuffer, 0, &m_pDepthStencilView);

			if (FAILED(hr))
			{
				OutputDebugString(L"Cannot create depth stencil view");
				return;
			}

			if (m_pDeviceContext != nullptr)
			{
				m_pDeviceContext->OMSetRenderTargets(1, &m_pRenderTargetView, m_pDepthStencilView);
			}
			//m_pDeviceContext->OM
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


		void D3D11GraphicsAPI::CreateRasterizerState()
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
				OutputDebugString(L"Cannot create rasterrizer state\n");

			m_rasterizerStates.push_back(pCullBackRS);

			m_pDeviceContext->RSSetState(m_rasterizerStates[0]);
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

		void D3D11GraphicsAPI::CreateVertexShader( Shader* shader, const std::wstring& shaderFileName, bool isCompiled)
		{
			/*if(!isCompiled)
				CompileShader(shader, shaderFileName, SHADER_TYPE::VERTEX_SHADER);
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
				hr = m_pD3D11Device->CreateInputLayout(inputDescs, 4, shader->GetShaderByteData(), shader->GetSize(), &m_inputLayouts.back());*/

			//}
		}

		void D3D11GraphicsAPI::CreatePixelShader( Helios::Shader* shader, const std::wstring& shaderFileName, bool isCompiled)
		{
			/*if(!isCompiled)
				CompileShader(shader, shaderFileName, SHADER_TYPE::PIXEL_SHADER);
			else
			{
				ID3D11PixelShader* ps = (ID3D11PixelShader*)shader->GetPixelShaderData();
				m_pD3D11Device->CreatePixelShader(reinterpret_cast<const void*>(shader->GetShaderByteData()), shader->GetSize(), nullptr, &ps);
			}*/
		}

		void D3D11GraphicsAPI::CompileShader(ID3D11VertexShader*& vertexShader, ID3D11PixelShader*& pixelShader, const std::wstring& shaderFileName, SHADER_TYPE type)
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

			std::wstring path = GetEXEPath() + L"//" + shaderFileName;

			if (type == SHADER_TYPE::VERTEX_SHADER)
			{
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
					return;
				}
				else
				{
					
					
					HRESULT hr = m_pD3D11Device->CreateVertexShader(shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), nullptr, &vertexShader);

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
					if (errorBlob)
					{
						OutputDebugStringA((char*)errorBlob->GetBufferPointer());
						errorBlob->Release();
					}

					if (shaderBlob)
						shaderBlob->Release();
					return;
				}

				m_pD3D11Device->CreatePixelShader(reinterpret_cast<const void*>(shaderBlob->GetBufferPointer()), shaderBlob->GetBufferSize(), nullptr, &pixelShader);

			}	

		}

		void D3D11GraphicsAPI::RenderQuad()
		{
		}

		void D3D11GraphicsAPI::RenderMeshesIndexed(std::vector<Mesh>& meshes, std::vector<Buffer*>& buffers, std::vector<Buffer*>& indexBuffers, std::vector<Shader>& shaders)
		{		
			m_pDeviceContext->IASetInputLayout(m_inputLayouts[0]);
			m_pDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
			m_pDeviceContext->RSSetState(m_rasterizerStates[0]);

			UINT stride = sizeof(Vertex);
			UINT offset = 0;

			for (auto& m : meshes)
			{
				
				D3DBuffer* pBuffer = (D3DBuffer*)buffers[m.GetVertexBufferID()];
				D3DBuffer* pIndexBuffer = (D3DBuffer*)indexBuffers[m.GetVertexBufferID()];
				Shader pShader = shaders[m.GetShaderID()];

				m_pDeviceContext->IASetVertexBuffers(0, 1, &pBuffer->pD3DBuffer, &stride, &offset);
				m_pDeviceContext->IASetIndexBuffer(pIndexBuffer->pD3DBuffer, DXGI_FORMAT_R32_UINT, offset);
				pShader.Bind();

			//	m_pDeviceContext->PSSetShaderResources(0,1, &m.GetTextures()[0]->m_pShaderResourceView);
				m_pDeviceContext->DrawIndexed(m.GetNumIndices(),0, 0);
			}
		}

		void D3D11GraphicsAPI::RenderSceneIndexed(Scene* scene)
		{
			m_pDeviceContext->IASetInputLayout(m_inputLayouts[0]);
			m_pDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
			m_pDeviceContext->RSSetState(m_rasterizerStates[0]);

			UINT stride = sizeof(Vertex);
			UINT offset = 0;
			m_pDeviceContext->PSSetSamplers(0, 1, &m_sampleState);

			for (auto& m : scene->GetMeshes())
			{
				if (!m.GetIsDestroyed())
				{
					SetCameraConstantBuffer(m.GetWorld(), scene->GetCamera()->GetViewMatrix(), scene->GetCamera()->GetProjectionMatrix(), scene->GetConstantBuffers()[0]);

					D3DBuffer* pBuffer = (D3DBuffer*)scene->GetBuffers()[m.GetVertexBufferID()];
					D3DBuffer* pIndexBuffer = (D3DBuffer*)scene->GetIndexBuffers()[m.GetVertexBufferID()];
					Shader pShader = scene->GetShaders()[m.GetShaderID()];

					m_pDeviceContext->IASetVertexBuffers(0, 1, &pBuffer->pD3DBuffer, &stride, &offset);
					m_pDeviceContext->IASetIndexBuffer(pIndexBuffer->pD3DBuffer, DXGI_FORMAT_R32_UINT, offset);
					pShader.Bind();
					m_pDeviceContext->PSSetShaderResources(0, 1, &m.GetTextures()[0]->m_pShaderResourceView);
					m_pDeviceContext->DrawIndexed(m.GetNumIndices(), 0, 0);
				}

			}

		}

		void D3D11GraphicsAPI::CreateBuffer(Buffer* buffer, BufferDesc& desc, uint32_t numElements, const std::vector<Vertex>& vertices, const std::vector<uint32_t> indices)
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
				hr = m_pD3D11Device->CreateBuffer(&vbd, nullptr, &pBuffer->pD3DBuffer);
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
			}


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
			HRESULT result = m_pD3D11Device->CreateSamplerState(&samplerDesc, &m_sampleState);
			if (FAILED(result))
			{
				return false;
			}


			

			return true;
		}

		bool D3D11GraphicsAPI::CreateTexture(Texture* tex, const std::string& texFileName)
		{
			D3DTexture* texture = static_cast<D3DTexture*>(tex);
			std::wstring path = GetEXEPath();
			uint32_t comps = 1;

			texture->m_name = texFileName;
			std::string textureFilesPath(path.begin(), path.end());

			auto pData = jpgd::decompress_jpeg_image_from_file((textureFilesPath + "/" + texFileName).c_str(),
				reinterpret_cast<int*>(&texture->m_width),
				reinterpret_cast<int*>(&texture->m_height),
				reinterpret_cast<int*>(&comps),
				4); //  request a 32 bit image
			texture->m_pImageData = std::make_unique<uint8_t[]>(texture->m_width * texture->m_height * 4);
			std::memcpy(texture->m_pImageData.get(), pData, texture->m_width * texture->m_height * 4);

			HRESULT hr;
			ID3D11Texture2D* pTex2D = nullptr;
			D3D11_TEXTURE2D_DESC texDesc;
			memset(&texDesc, 0, sizeof(D3D11_TEXTURE2D_DESC));
			texDesc.Width = texture->m_width;
			texDesc.Height = texture->m_height;
			texDesc.MipLevels = 0;
			texDesc.ArraySize = 1;
			texDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
			texDesc.SampleDesc.Count = 1;
			texDesc.SampleDesc.Quality = 0;
			texDesc.Usage = D3D11_USAGE_DEFAULT;
			texDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE | D3D11_BIND_RENDER_TARGET;
			texDesc.CPUAccessFlags = 0;
			texDesc.MiscFlags = D3D11_RESOURCE_MISC_GENERATE_MIPS;

			hr = m_pD3D11Device->CreateTexture2D(&texDesc, nullptr, &pTex2D);

			if (FAILED(hr))
			{
				OutputDebugString(L"Cannot create texture\n");
				return false;
			}

			D3D11_MAPPED_SUBRESOURCE  mappedTex;
			uint32_t rowPitch = (texture->m_width * 4) * sizeof(uint8_t);
			m_pDeviceContext->UpdateSubresource(pTex2D, 0, NULL, pData, rowPitch, 0);
			/*m_pD3D11DeviceContext->Map(pTex2D, 0, D3D11_MAP_READ, 0, &mappedTex);

			UCHAR* pTexels = (UCHAR*)mappedTex.pData;
			int j = 0;
			for (UINT row = 0; row < texDesc.Height; row++)
			{
				UINT rowStart = row * mappedTex.RowPitch;
				for (UINT col = 0; col < texDesc.Width; col++)
				{
					UINT colStart = col * 4;
					pTexels[rowStart + colStart + 0] = m_pImageData[j++];
					pTexels[rowStart + colStart + 1] = m_pImageData[j++];
					pTexels[rowStart + colStart + 2] = m_pImageData[j++];
					pTexels[rowStart + colStart + 3] = m_pImageData[j++];
				}
			}

			m_pD3D11DeviceContext->Unmap(pTex2D, D3D11CalcSubresource(0, 0, 1));*/

			D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
			memset(&srvDesc, 0, sizeof(D3D11_SHADER_RESOURCE_VIEW_DESC));
			srvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
			srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
			srvDesc.Texture2D.MostDetailedMip = 0;
			srvDesc.Texture2D.MipLevels = -1;

			hr = m_pD3D11Device->CreateShaderResourceView(pTex2D, &srvDesc, &texture->m_pShaderResourceView);
			
			if (FAILED(hr))
				return false;

			m_pDeviceContext->GenerateMips(texture->m_pShaderResourceView);
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

		void D3D11GraphicsAPI::SetCameraConstantBuffer(const DirectX::XMMATRIX& model, const DirectX::XMMATRIX& view, const DirectX::XMMATRIX& proj, Buffer* cbuffer)
		{

			D3DBuffer* pCBuffer = (D3DBuffer*)cbuffer;
			D3D11_MAPPED_SUBRESOURCE mappedResource;
			ConstantMatrixBuffer* dataPtr;

			DirectX::XMMATRIX WVP = DirectX::XMMatrixTranspose(model * view * proj);

			HRESULT result = m_pDeviceContext->Map(pCBuffer->pD3DBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);

			if (FAILED(result))
				OutputDebugString(L"Cannot set constant buffer\n");

			dataPtr = (ConstantMatrixBuffer*)mappedResource.pData;

			XMStoreFloat4x4(&dataPtr->WVP, WVP);
			m_pDeviceContext->Unmap(pCBuffer->pD3DBuffer, 0);
			m_pDeviceContext->VSSetConstantBuffers(0, 1, &pCBuffer->pD3DBuffer);
		}

		void D3D11GraphicsAPI::SetDirectionalLightBuffer(Buffer* cbuffer, const XMFLOAT3& direction, const XMFLOAT4& color)
		{
			D3D11_MAPPED_SUBRESOURCE mappedResource;
			unsigned int bufferNumber = 0;

			LightBuffer* dataPtr;
			D3DBuffer* pCBuffer = (D3DBuffer*)(cbuffer);

			m_pDeviceContext->Map(pCBuffer->pD3DBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);

			// Get a pointer to the data in the constant buffer.
			dataPtr = (LightBuffer*)mappedResource.pData;

			// Copy the lighting variables into the constant buffer.
			dataPtr->color = color;
			dataPtr->direction = direction;
			dataPtr->padding = 0.0f;

			// Unlock the constant buffer.
			m_pDeviceContext->Unmap(pCBuffer->pD3DBuffer, 0);

			// Set the position of the light constant buffer in the pixel shader.
			bufferNumber = 0;

			// Finally set the light constant buffer in the pixel shader with the updated values.
			m_pDeviceContext->PSSetConstantBuffers(bufferNumber, 1, &pCBuffer->pD3DBuffer);
		}

		void D3D11GraphicsAPI::SetDepthShaderLightSpaceMatrixBuffer(Buffer* cbuffer, const DirectX::XMMATRIX& model, const DirectX::XMFLOAT3& position, const DirectX::XMFLOAT3& target, const DirectX::XMFLOAT3& up)
		{
			D3DBuffer* pCBuffer = (D3DBuffer*)cbuffer;
			D3D11_MAPPED_SUBRESOURCE mappedResource;
			LightSpaceMatrixBuffer* dataPtr;

			DirectX::XMMATRIX lightSpaceProjection = DirectX::XMMatrixOrthographicLH(10.0f, 10.0f, 1.0f, 10.0f);
			DirectX::XMMATRIX lightView = DirectX::XMMatrixLookAtLH(DirectX::XMLoadFloat3(&position), DirectX::XMLoadFloat3(&target), DirectX::XMLoadFloat3(&up));

			DirectX::XMMATRIX lightMatrix = DirectX::XMMatrixTranspose(lightView * lightSpaceProjection);

			HRESULT result = m_pDeviceContext->Map(pCBuffer->pD3DBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);

			if (FAILED(result))
				OutputDebugString(L"Cannot set constant buffer\n");

			dataPtr = (LightSpaceMatrixBuffer*)mappedResource.pData;

			XMStoreFloat4x4(&dataPtr->lightSpaceMatrix, lightMatrix);
			XMStoreFloat4x4(&dataPtr->modelMatrix, model);
			m_pDeviceContext->Unmap(pCBuffer->pD3DBuffer, 0);
			m_pDeviceContext->VSSetConstantBuffers(0, 1, &pCBuffer->pD3DBuffer);
		}

		void D3D11GraphicsAPI::EnumerateComponents()
		{
			UINT i = 0;

			if (m_pDXGIFactory != nullptr)
			{
				// Get main video card
				m_pDXGIFactory->EnumAdapters(i, &m_pAdapter);

				DXGI_ADAPTER_DESC desc;
				m_pAdapter->GetDesc(&desc);
				std::wstring text = L"Adapter: ";
				text += desc.Description;
				text += L"\n";
				m_videoCardInfo.description += desc.Description;
				OutputDebugString(text.c_str());

			}

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
			ID3D11DeviceContext* pDeviceContext = DeviceContext();

			pDeviceContext->ClearRenderTargetView(m_pRenderTargetView, m_clearColor);
			pDeviceContext->ClearDepthStencilView(m_pDepthStencilView,D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

			
		}
		
		void D3D11GraphicsAPI::PresentToScreen()
		{
			HRESULT hr = SwapChain()->Present(0, 0);
		}
	
}
	
