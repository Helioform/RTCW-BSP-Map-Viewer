
#include "XD3D.h"

XD3DRenderer* Singleton<class XD3DRenderer>::ms_singleton = new XD3DRenderer();

XD3DRenderer::XD3DRenderer()
{
	m_pD3DDevice = nullptr;
	m_pDeviceContext = nullptr;
	m_pSwapChain = nullptr;
	m_pRenderTargetView = nullptr;
	m_pBackBuffer = nullptr;
	m_pDepthStencilBuffer = nullptr;
	m_pDepthStencilView = nullptr;

	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			m_pEnableBlendingState[i][j] = nullptr;

	m_pDisableBlendingState = nullptr;

	m_screenWidth = m_screenHeight = 0;
	m_fullScreen = false;
}

XD3DRenderer::XD3DRenderer(HWND wnd, int screenWidth, int screenHeight, bool fullScreen)
{
	InitD3D(wnd, screenWidth, screenHeight, fullScreen);
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

	ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));

	
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

	UINT createDeviceFlags = 0;

#if defined(DEBUG) || defined(_DEBUG)
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	hr = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, &featureLevel, 1,
		D3D11_SDK_VERSION, &swapChainDesc, &m_pSwapChain, &m_pD3DDevice, NULL, &m_pDeviceContext);

	if (FAILED(hr))
		return false;

	return true;
}

bool XD3DRenderer::InitD3D(HWND wnd, int screenWidth, int screenHeight, bool fullScreen)
{
	if (!CreateD3DDevice(wnd, screenWidth, screenHeight, fullScreen))
		return false;

	if (!CreateDepthBuffer())
		return false;

	if (!CreateRenderTargetView())
		return false;

	if (!CreateDepthStencilView())
		return false;

	if (!CreateDisabledDepthStencilState())
		return false;

	if (!CreateDisabledBlendingState())
		return false;

	if (!CreateBlendState(D3D11_BLEND_ZERO, D3D11_BLEND_ONE, D3D11_BLEND_OP_ADD))
		return false;

	if (!CreateBlendState(D3D11_BLEND_ONE, D3D11_BLEND_INV_SRC_ALPHA, D3D11_BLEND_OP_ADD))
		return false;

	if (!CreateBlendState(D3D11_BLEND_ONE, D3D11_BLEND_ZERO, D3D11_BLEND_OP_ADD))
		return false;

	if (!CreateBlendState(D3D11_BLEND_ONE, D3D11_BLEND_ONE, D3D11_BLEND_OP_ADD))
		return false;

	if (!CreateBlendState(D3D11_BLEND_SRC_ALPHA, D3D11_BLEND_INV_SRC_ALPHA, D3D11_BLEND_OP_ADD))
		return false;
	
	if (!CreateBlendState(D3D11_BLEND_DEST_COLOR, D3D11_BLEND_ZERO, D3D11_BLEND_OP_ADD))
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
	for (D3D11_BLEND i = D3D11_BLEND_ZERO; i < 7; ((int&)i)++)
		for (D3D11_BLEND j = D3D11_BLEND_ZERO; j < 7; ((int&)j)++)
			SAFE_RELEASE(m_pEnableBlendingState[i][j]);

	SAFE_RELEASE(m_pDisableBlendingState);
}

bool XD3DRenderer::CreateRenderTargetView()
{
	HRESULT hr;

	hr = m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&m_pBackBuffer);
	
	if (FAILED(hr))
		return false;

	
	hr = m_pD3DDevice->CreateRenderTargetView(m_pBackBuffer, NULL, &m_pRenderTargetView);
	
	if (FAILED(hr))
		return false;

	m_pBackBuffer->Release();
	m_pBackBuffer = 0;

	return true;
}

bool XD3DRenderer::CreateDepthBuffer()
{
	HRESULT hr;
	D3D11_TEXTURE2D_DESC depthBufferDesc;

		
	ZeroMemory(&depthBufferDesc, sizeof(depthBufferDesc));

	
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

	
	ZeroMemory(&depthStencilDesc, sizeof(depthStencilDesc));

	
	depthStencilDesc.DepthEnable = true;
	depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
	depthStencilDesc.DepthFunc = D3D11_COMPARISON_LESS;

	depthStencilDesc.StencilEnable = true;
	depthStencilDesc.StencilReadMask = 0xFF;
	depthStencilDesc.StencilWriteMask = 0xFF;

	
	depthStencilDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
	depthStencilDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	depthStencilDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
	depthStencilDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	
	hr = m_pD3DDevice->CreateDepthStencilState(&depthStencilDesc, &m_pDepthStencilState);
	
	if (FAILED(hr))
		return false;

	
	m_pDeviceContext->OMSetDepthStencilState(m_pDepthStencilState, 1);

	
	ZeroMemory(&depthStencilViewDesc, sizeof(depthStencilViewDesc));

	
	depthStencilViewDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	depthStencilViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
	depthStencilViewDesc.Texture2D.MipSlice = 0;

	
	hr = m_pD3DDevice->CreateDepthStencilView(m_pDepthStencilBuffer, &depthStencilViewDesc, &m_pDepthStencilView);
	
	if (FAILED(hr))
		return false;

	
	m_pDeviceContext->OMSetRenderTargets(1, &m_pRenderTargetView, m_pDepthStencilView);

	
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

	
	hr = m_pD3DDevice->CreateRasterizerState(&rasterDesc, &m_pRasterState);

	if (FAILED(hr))
		return false;

	m_pDeviceContext->RSSetState(m_pRasterState);

	viewport.Width = (float)m_screenWidth;
	viewport.Height = (float)m_screenHeight;
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;
	viewport.TopLeftX = 0.0f;
	viewport.TopLeftY = 0.0f;

	m_pDeviceContext->RSSetViewports(1, &viewport);

	return true;
}

bool XD3DRenderer::CreateDisabledDepthStencilState()
{
	HRESULT hr;
	D3D11_DEPTH_STENCIL_DESC depthStencilDesc;

	ZeroMemory(&depthStencilDesc, sizeof(depthStencilDesc));

	depthStencilDesc.DepthEnable = false;
	depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
	depthStencilDesc.DepthFunc = D3D11_COMPARISON_LESS;

	depthStencilDesc.StencilEnable = true;
	depthStencilDesc.StencilReadMask = 0xFF;
	depthStencilDesc.StencilWriteMask = 0xFF;

	depthStencilDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
	depthStencilDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	depthStencilDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
	depthStencilDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	hr = m_pD3DDevice->CreateDepthStencilState(&depthStencilDesc, &m_pDisabledDepthStencilState);

	if (FAILED(hr))
		return false;

	return true;
}

bool XD3DRenderer::CreateBlendState(D3D11_BLEND srcFactor, D3D11_BLEND destFactor, D3D11_BLEND_OP blendOp)
{
	D3D11_BLEND_DESC blendStateDescription;
	HRESULT hr;

	ZeroMemory(&blendStateDescription, sizeof(D3D11_BLEND_DESC));

	blendStateDescription.RenderTarget[0].BlendEnable = TRUE;
	blendStateDescription.RenderTarget[0].SrcBlend = srcFactor;
	blendStateDescription.RenderTarget[0].DestBlend = destFactor;
	blendStateDescription.RenderTarget[0].BlendOp = blendOp;
	blendStateDescription.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
	blendStateDescription.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
	blendStateDescription.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
	blendStateDescription.RenderTarget[0].RenderTargetWriteMask = 0x0f;

	hr = m_pD3DDevice->CreateBlendState(&blendStateDescription, &m_pEnableBlendingState[srcFactor][destFactor]);

	if (FAILED(hr))
		return false;

//	TurnOnBlending(D3D11_BLEND_ONE, D3D11_BLEND_INV_SRC_ALPHA);
//	TurnOnBlending(D3D11_BLEND_SRC_ALPHA, D3D11_BLEND_INV_SRC_ALPHA);
	
	return true;
}

bool XD3DRenderer::CreateDisabledBlendingState()
{

	D3D11_BLEND_DESC blendStateDescription;
	HRESULT hr;

	ZeroMemory(&blendStateDescription, sizeof(D3D11_BLEND_DESC));

	blendStateDescription.RenderTarget[0].BlendEnable = FALSE;
	blendStateDescription.RenderTarget[0].SrcBlend = D3D11_BLEND_ONE;
	blendStateDescription.RenderTarget[0].DestBlend = D3D11_BLEND_ZERO;
	blendStateDescription.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
	blendStateDescription.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
	blendStateDescription.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
	blendStateDescription.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
	blendStateDescription.RenderTarget[0].RenderTargetWriteMask = 0x0f;

	hr = m_pD3DDevice->CreateBlendState(&blendStateDescription, &m_pDisableBlendingState);

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
    m_pDeviceContext->ClearRenderTargetView(m_pRenderTargetView, col);

    m_pDeviceContext->ClearDepthStencilView(m_pDepthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
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

void XD3DRenderer::TurnOnBlending(D3D11_BLEND srcFactor, D3D11_BLEND destFactor)
{
	float blendFactor[4];

	blendFactor[0] = 0.0f;
	blendFactor[1] = 0.0f;
	blendFactor[2] = 0.0f;
	blendFactor[3] = 0.0f;

	m_pDeviceContext->OMSetBlendState(m_pEnableBlendingState[srcFactor][destFactor], blendFactor, 0xffffffff);
}

void XD3DRenderer::TurnOffBlending()
{
	float blendFactor[4];

	blendFactor[0] = 0.0f;
	blendFactor[1] = 0.0f;
	blendFactor[2] = 0.0f;
	blendFactor[3] = 0.0f;

	m_pDeviceContext->OMSetBlendState( m_pDisableBlendingState, blendFactor, 0xffffffff);
}

void XD3DRenderer::ScreenFadeIn(XCamera & cam)
{

}

