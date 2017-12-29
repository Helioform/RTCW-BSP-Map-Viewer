#include "stdafx.h"
#include "XD3D.h"


XD3DRenderer::XD3DRenderer()
{
	m_pD3DDevice = nullptr;
	m_pDeviceContext = nullptr;
	m_pSwapChain = nullptr;
	m_pRenderTargetView = nullptr;
	m_pBackBuffer = nullptr;
	m_pDepthStencilBuffer = nullptr;
	m_pDepthStencilView = nullptr;

	m_screenWidth = m_screenHeight = 0;
	m_fullScreen = false;
}

XD3DRenderer::XD3DRenderer(HWND wnd, int screenWidth, int screenHeight, bool fullScreen)
{
	CreateD3DDevice(wnd, screenWidth, screenHeight, fullScreen);
}

XD3DRenderer::~XD3DRenderer()
{
	ShutdownD3D();	
}

bool XD3DRenderer::LoadDriver()
{
	m_XD3DModule = LoadLibrary(L"d3d11.dll");
	
	if(m_XD3DModule == nullptr)
		return false;

	return true;
}

bool XD3DRenderer::CreateD3DDevice(HWND wnd, int screenWidth, int screenHeight, bool fullScreen)
{	
	HRESULT hr;
	m_wnd = wnd;
	m_screenHeight = screenHeight;
	m_screenWidth = screenWidth;
	m_fullScreen = fullScreen;
	IDXGIFactory* factory;
	IDXGIAdapter* adapter;
	IDXGIOutput* adapterOutput;
	unsigned int numModes, i, numerator, denominator, stringLength;
	DXGI_MODE_DESC* displayModeList;
	DXGI_ADAPTER_DESC adapterDesc;
	int error;
	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	D3D_FEATURE_LEVEL featureLevel;

	hr = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&factory);
	if (FAILED(hr))
		return false;


	hr = factory->EnumAdapters(0, &adapter);
	if (FAILED(hr))
		return false;

	hr = adapter->EnumOutputs(0, &adapterOutput);
	if (FAILED(hr))
		return false;

	hr = adapterOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, NULL);
	
	if (FAILED(hr))
		return false;

	displayModeList = new DXGI_MODE_DESC[numModes];
	if (!displayModeList)
		return false;

	hr = adapterOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, displayModeList);
	if (FAILED(hr))
		return false;

	for (i = 0; i<numModes; i++)
	{
		if (displayModeList[i].Width == (unsigned int)screenWidth)
		{
			if (displayModeList[i].Height == (unsigned int)screenHeight)
			{
				numerator = displayModeList[i].RefreshRate.Numerator;
				denominator = displayModeList[i].RefreshRate.Denominator;
			}
		}
	}

	hr = adapter->GetDesc(&adapterDesc);
	if (FAILED(hr))
		return false;

	delete[] displayModeList;
	displayModeList = 0;

	adapterOutput->Release();
	adapterOutput = 0;

	adapter->Release();
	adapter = 0;

	factory->Release();
	factory = 0;

	// Initialize the swap chain description.
	ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));

	// Set to a single back buffer.
	swapChainDesc.BufferCount = 1;
	swapChainDesc.BufferDesc.Width = screenWidth;
	swapChainDesc.BufferDesc.Height = screenHeight;	
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferDesc.RefreshRate.Numerator = numerator;
	swapChainDesc.BufferDesc.RefreshRate.Denominator = denominator;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.OutputWindow = wnd;
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.SampleDesc.Quality = 0;
	swapChainDesc.Windowed = !fullScreen;
	swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	swapChainDesc.Flags = 0;
	featureLevel = D3D_FEATURE_LEVEL_10_0;

	hr = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, 0, &featureLevel, 1,
		D3D11_SDK_VERSION, &swapChainDesc, &m_pSwapChain, &m_pD3DDevice, NULL, &m_pDeviceContext);

	if (FAILED(hr))
		return false;

	return true;
}

void XD3DRenderer::ShutdownD3D(void)
{
	SAFE_RELEASE(m_pD3DDevice);
	SAFE_RELEASE(m_pDeviceContext);
	SAFE_RELEASE(m_pSwapChain);
	SAFE_RELEASE(m_pRenderTargetView);
	SAFE_RELEASE(m_pBackBuffer);
	SAFE_RELEASE(m_pDepthStencilBuffer);
	SAFE_RELEASE(m_pDepthStencilState);
	SAFE_RELEASE(m_pDisabledDepthStencilState);
	SAFE_RELEASE(m_pRasterState);
	SAFE_RELEASE(m_pDepthStencilView);
}

bool XD3DRenderer::CreateRenderTargetView()
{
	HRESULT hr;

	// Get the pointer to the back buffer.
	hr = m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&m_pBackBuffer);
	
	if (FAILED(hr))
		return false;

	// Create the render target view with the back buffer pointer.
	hr = m_pD3DDevice->CreateRenderTargetView(m_pBackBuffer, NULL, &m_pRenderTargetView);
	
	if (FAILED(hr))
		return false;

	// Release pointer to the back buffer as we no longer need it.
	m_pBackBuffer->Release();
	m_pBackBuffer = 0;

	return true;
}

bool XD3DRenderer::CreateDepthBuffer()
{
	HRESULT hr;
	D3D11_TEXTURE2D_DESC depthBufferDesc;

		// Initialize the description of the depth buffer.
	ZeroMemory(&depthBufferDesc, sizeof(depthBufferDesc));

	// Set up the description of the depth buffer.
	depthBufferDesc.Width = m_screenWidth;
	depthBufferDesc.Height = m_screenHeight;
	depthBufferDesc.MipLevels = 1;
	depthBufferDesc.ArraySize = 1;
	depthBufferDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	depthBufferDesc.SampleDesc.Count = 1;
	depthBufferDesc.SampleDesc.Quality = 0;
	depthBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	depthBufferDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	depthBufferDesc.CPUAccessFlags = 0;
	depthBufferDesc.MiscFlags = 0;

	// Create the texture for the depth buffer using the filled out description.
	hr = m_pD3DDevice->CreateTexture2D(&depthBufferDesc, NULL, &m_pDepthStencilBuffer);
	
	if(FAILED(hr))
		return false;
	
	
	return true;
}

bool XD3DRenderer::CreateDepthStencilView()
{
	HRESULT hr;
	D3D11_DEPTH_STENCIL_DESC depthStencilDesc;
	D3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc;
	D3D11_RASTERIZER_DESC rasterDesc;
	D3D11_VIEWPORT viewport;

	// Initialize the description of the stencil state.
	ZeroMemory(&depthStencilDesc, sizeof(depthStencilDesc));

	// Set up the description of the stencil state.
	depthStencilDesc.DepthEnable = true;
	depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
	depthStencilDesc.DepthFunc = D3D11_COMPARISON_LESS;

	depthStencilDesc.StencilEnable = true;
	depthStencilDesc.StencilReadMask = 0xFF;
	depthStencilDesc.StencilWriteMask = 0xFF;

	// Stencil operations if pixel is front-facing.
	depthStencilDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
	depthStencilDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	// Stencil operations if pixel is back-facing.
	depthStencilDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
	depthStencilDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	// Create the depth stencil state.
	hr = m_pD3DDevice->CreateDepthStencilState(&depthStencilDesc, &m_pDepthStencilState);
	
	if (FAILED(hr))
		return false;

	// Set the depth stencil state.
	m_pDeviceContext->OMSetDepthStencilState(m_pDepthStencilState, 1);

	// Initialize the depth stencil view.
	ZeroMemory(&depthStencilViewDesc, sizeof(depthStencilViewDesc));

	// Set up the depth stencil view description.
	depthStencilViewDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	depthStencilViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
	depthStencilViewDesc.Texture2D.MipSlice = 0;

	// Create the depth stencil view.
	hr = m_pD3DDevice->CreateDepthStencilView(m_pDepthStencilBuffer, &depthStencilViewDesc, &m_pDepthStencilView);
	
	if (FAILED(hr))
		return false;

	// Bind the render target view and depth stencil buffer to the output render pipeline.
	m_pDeviceContext->OMSetRenderTargets(1, &m_pRenderTargetView, m_pDepthStencilView);

	// Setup the raster description which will determine how and what polygons will be drawn.
	rasterDesc.AntialiasedLineEnable = false;
	rasterDesc.CullMode = D3D11_CULL_BACK;
	rasterDesc.DepthBias = 0;
	rasterDesc.DepthBiasClamp = 0.0f;
	rasterDesc.DepthClipEnable = true;
	rasterDesc.FillMode = D3D11_FILL_SOLID;
	rasterDesc.FrontCounterClockwise = false;
	rasterDesc.MultisampleEnable = false;
	rasterDesc.ScissorEnable = false;
	rasterDesc.SlopeScaledDepthBias = 0.0f;

	// Create the rasterizer state from the description we just filled out.
	hr = m_pD3DDevice->CreateRasterizerState(&rasterDesc, &m_pRasterState);

	if (FAILED(hr))
		return false;

	// Now set the rasterizer state.
	m_pDeviceContext->RSSetState(m_pRasterState);

	// Setup the viewport for rendering.
	viewport.Width = (float)m_screenWidth;
	viewport.Height = (float)m_screenHeight;
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;
	viewport.TopLeftX = 0.0f;
	viewport.TopLeftY = 0.0f;

	// Create the viewport.
	m_pDeviceContext->RSSetViewports(1, &viewport);

	return true;
}

bool XD3DRenderer::CreateDisabledDepthStencilState()
{
	HRESULT hr;
	D3D11_DEPTH_STENCIL_DESC depthStencilDesc;

	// Initialize the description of the stencil state.
	ZeroMemory(&depthStencilDesc, sizeof(depthStencilDesc));

	// Set up the description of the stencil state.
	depthStencilDesc.DepthEnable = false;
	depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
	depthStencilDesc.DepthFunc = D3D11_COMPARISON_LESS;

	depthStencilDesc.StencilEnable = true;
	depthStencilDesc.StencilReadMask = 0xFF;
	depthStencilDesc.StencilWriteMask = 0xFF;

	// Stencil operations if pixel is front-facing.
	depthStencilDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
	depthStencilDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	// Stencil operations if pixel is back-facing.
	depthStencilDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
	depthStencilDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	// Create the depth stencil state.
	hr = m_pD3DDevice->CreateDepthStencilState(&depthStencilDesc, &m_pDisabledDepthStencilState);

	if (FAILED(hr))
		return false;

	return true;
}


bool XD3DRenderer::Setup()
{	
	HRESULT hr;

	return true;
}

bool XD3DRenderer::ClearScene(const D3DXCOLOR& col)
{
	// Clear the back buffer.
    m_pDeviceContext->ClearRenderTargetView(m_pRenderTargetView, col);

	// Clear the depth buffer.
    m_pDeviceContext->ClearDepthStencilView(m_pDepthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
	return true;
}

bool XD3DRenderer::Render(XGeomObject* pGeom, XCamera* pCam)
{	
	HRESULT hr;
	unsigned int stride;
	unsigned int offset;

	// Set vertex buffer stride and offset.
	stride = sizeof(TexVertex);
	offset = 0;
	
	

	return true;
}

bool XD3DRenderer::Render(XWorldMap* pMap, XCamera* cam)
{
	HRESULT hr;
	unsigned int stride;
	unsigned int offset;

	// Set vertex buffer stride and offset.
	stride = sizeof(TexVertex);
	offset = 0;

	XD3DShader* pShader = pMap->GetD3DShader(0);
//	XD3DShader* pShader = pXShader->GetD3DShader();

	std::vector<TextureIndexedFaceData*> visibleFaces = pMap->GetVisibleFaces();
	
	for (int i = 0; i < visibleFaces.size(); ++i)
	{
		// Set the vertex buffer to active in the input assembler so it can be rendered.
		ID3D11Buffer* pVB = visibleFaces[i]->pTexVBuffer;
		m_pDeviceContext->IASetVertexBuffers(0, 1, &pVB, &stride, &offset);

		// Set the type of primitive that should be rendered from this vertex buffer, in this case triangles.
		m_pDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

		// Set the vertex input layout.
		m_pDeviceContext->IASetInputLayout(pMap->GetInputLayout());
	
		if(visibleFaces[i]->lightMapIndex < 0)
			pShader->SetParams(cam->ViewMatrix(), cam->ProjectionMatrix(), visibleFaces[i]->textureIndex);
		else
			pShader->SetParams(cam->ViewMatrix(), cam->ProjectionMatrix(), visibleFaces[i]->textureIndex, visibleFaces[i]->lightMapIndex);
				
		// Set the vertex and pixel shaders that will be used to render these faces
		pShader->BindVertexShader();
		pShader->BindPixelShader();

		ID3D11SamplerState* pSampleState = pMap->GetTextureManager()->GetSamplerState();
		m_pDeviceContext->PSSetSamplers(0, 1, &pSampleState);

		// Render the faces
		m_pDeviceContext->Draw(visibleFaces[i]->numVertices, 0);
	}

	return true;
}


bool XD3DRenderer::ShowScene()
{	
	HRESULT hr;

	hr = m_pSwapChain->Present(0, 0);

	if (FAILED(hr))
		return false;

	return true;
}

void XD3DRenderer::TurnOnZBuffer()
{
	m_pDeviceContext->OMSetDepthStencilState(m_pDepthStencilState, 1);
}

void XD3DRenderer::TurnOffZBuffer()
{
	m_pDeviceContext->OMSetDepthStencilState(m_pDisabledDepthStencilState, 1);
}
