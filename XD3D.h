#pragma once

#include <d3d11.h>
#include <DirectXMath.h>
#include "XCamera.h"
#include "Singleton.h"

using namespace DirectX;

#define GPA(d3dModule, func) GetProcAddress(d3dModule, func)

#define SAFE_RELEASE(obj) if(obj) { obj->Release(); obj = nullptr; }

class XD3DRenderer : public Singleton<XD3DRenderer>
{
protected:
	HMODULE						m_XD3DModule;
	ID3D11Device*				m_pD3DDevice;
	ID3D11DeviceContext*		m_pDeviceContext;
	IDXGISwapChain*				m_pSwapChain;
	ID3D11RenderTargetView*		m_pRenderTargetView;
	ID3D11Texture2D*			m_pBackBuffer;
	ID3D11Texture2D*			m_pDepthStencilBuffer;
	ID3D11DepthStencilState*	m_pDepthStencilState;
	ID3D11DepthStencilState*	m_pDisabledDepthStencilState;
	ID3D11RasterizerState*		m_pRasterState;
	ID3D11DepthStencilView*		m_pDepthStencilView;

	HWND						m_wnd;
	int							m_screenWidth, m_screenHeight;
	bool						m_fullScreen;
	D3DXMATRIX					m_world, m_view, m_proj;
	bool						m_lightMapsOn;

public:
	XD3DRenderer();
	XD3DRenderer(HWND wnd, int screenwidth, int screenheight,bool fullscreen);
	~XD3DRenderer();

	ID3D11Device* GetD3DDevice() { return m_pD3DDevice; }
	ID3D11DeviceContext* GetDeviceContext() { return m_pDeviceContext; }

	bool LoadDriver();
	bool CreateD3DDevice(HWND wnd, int screenwidth, int screenheight, bool fullscreen );
	bool InitD3D(HWND wnd, int screenWidth, int screenHeight, bool fullScreen);
	void ShutdownD3D(void);
	bool CreateRenderTargetView();
	bool CreateDepthBuffer();
	bool CreateDepthStencilView();
	bool CreateDisabledDepthStencilState();

	bool Setup();
	bool ClearScene(const D3DXCOLOR& col);
	bool ShowScene();
	void TurnOnZBuffer();
	void TurnOffZBuffer();
};


