
#include "../Renderer.h"
//#include "../Core/heDLLExport.h"

namespace Helios
{
	
		

	//	void D3D11Renderer::Init(uint32_t screenWidth, uint32_t screenHeight, bool fullScreen)
	//	{
	//		m_pGraphicsDevice = std::make_unique<Graphics::D3D11GraphicsAPI>();
	//		m_pGraphicsDevice->FindBestFeatureLevel();
	//		m_pGraphicsDevice->CreateFactory2();

	//		m_pGraphicsDevice->EnumerateComponents();
	//		m_pGraphicsDevice->EnumerateDisplayResolutions(screenWidth, screenHeight, fullScreen);
	//		m_pGraphicsDevice->CreateD3DDevice();





	//	}

	//	void D3D11Renderer::CreateRenderObjects()
	//	{
	//		m_pGraphicsDevice->CreateSwapChain();
	//		m_pGraphicsDevice->CreateRenderTargetView();
	//		m_pGraphicsDevice->CreateDepthStencil();
	//		m_pGraphicsDevice->CreateViewport();
	//		m_pGraphicsDevice->CreateRasterizerState();
	//	}


	//	static float r = 0.01f;
	//	void D3D11Renderer::RenderMesh()
	//	{
	//		/*	m_objects[0].RotateAroundYAxis(r);
	//			SetConstantBufferParameters(0, 0);

	//			m_pGraphicsDevice->SetRasterizerState(0);

	//			ID3D11DeviceContext* pDeviceContext = m_pGraphicsDevice->DeviceContext();

	//			pDeviceContext->IASetInputLayout(pMaterial->InputLayouts()[0].Get());
	//			pDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	//			ID3D11Buffer* pBuffer = m_objects[0]->ColoredBuffers()[0].Buffer();
	//			UINT stride = sizeof(ColoredVertex);
	//			UINT offset = 0;
	//			pDeviceContext->IASetVertexBuffers(0, 1, &pBuffer, &stride, &offset);
	//		//	pDeviceContext->VSSetShader(pMaterial->VertexShaders()[0].pD3DVertexShader.Get(), nullptr, 0);
	//		//	pDeviceContext->PSSetShader(pMaterial->PixelShaders()[0].pD3DPixelShader.Get(), nullptr, 0);
	//		//	pDeviceContext->Draw(m_objects[0]->NumberVertices(), 0);*/
	//	}

	//	void D3D11Renderer::Render()
	//	{
	//		ID3D11DeviceContext* pDeviceContext = m_pGraphicsDevice->DeviceContext();
	//		ID3D11Device* pD3DDevice = m_pGraphicsDevice->D3DDevice();

	//		ClearScreen();


	//		pDeviceContext->Draw(4, 0);
	//	}

	//	void D3D11Renderer::ClearScreen()
	//	{
	//		ID3D11DeviceContext* pDeviceContext = m_pGraphicsDevice->DeviceContext();

	//		const float col[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
	//		pDeviceContext->ClearRenderTargetView(m_pGraphicsDevice->RenderTargetView(), col);

	//		pDeviceContext->ClearDepthStencilView(m_pGraphicsDevice->DepthStencilView(),
	//			D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);


	//	}

	//	void D3D11Renderer::PresentToScreen()
	//	{
	//		HRESULT hr = m_pGraphicsDevice->SwapChain()->Present(0, 0);
	//	}

	//	void D3D11Renderer::SetConstantBufferParameters(uint32_t meshID, uint32_t cameraID)
	//	{
	//		ID3D11DeviceContext* pDeviceContext = m_pGraphicsDevice->DeviceContext();

	//		HRESULT result;
	//		D3D11_MAPPED_SUBRESOURCE mappedResource;
	//		//	ConstantMatrixBuffer* dataPtr;
	//		//	auto WVP = m_objects[meshID]->WorldMatrix() * m_cameras[cameraID].ViewMatrix() * m_cameras[cameraID].ProjectionMatrix();
	//		//	result = pDeviceContext->Map(m_objects[meshID]->MatrixBuffer().Buffer(), 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);

	//		//	if (FAILED(result))
	//		//		OutputDebugString(L"Cannot set constant buffer\n");

	//		//	dataPtr = (ConstantMatrixBuffer*)mappedResource.pData;
	//		//	dataPtr->WVP = WVP;

	//		//	pDeviceContext->Unmap(m_objects[meshID]->MatrixBuffer().Buffer(), 0);

	//		//	ID3D11Buffer* pBuffer = m_objects[meshID]->MatrixBuffer().Buffer();
	//		//	pDeviceContext->VSSetConstantBuffers(0, 1, &pBuffer);
	//	}

	//	

	//	void D3D11Renderer::ClearScreen(ID3D11DeviceContext* pDeviceCtx, ID3D11RenderTargetView* pRenderTargetView, ID3D11DepthStencilView* pDepthStencilView)
	//	{
	//		const float col[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
	//		pDeviceCtx->ClearRenderTargetView(pRenderTargetView, col);

	//			pDeviceCtx->ClearDepthStencilView(pDepthStencilView,
	//				D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
	//	}
	//	void D3D11Renderer::RenderQuad(ID3D11DeviceContext* pDeviceCtx, ID3D11RenderTargetView* pRenderTargetView, ID3D11DepthStencilView* pDepthStencilView)
	//	{
	//	}
	
}

//extern "C"
//{
//	DllExport Helios::D3D11Renderer* CreateRenderer()
//	{
//	//	return new Helios::Graphics::D3D11Renderer();
//			return nullptr;
//	}
//}