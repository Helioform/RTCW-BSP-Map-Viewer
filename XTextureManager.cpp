#include "stdafx.h"
#include "XTextureManager.h"


XTextureManager::XTextureManager()
{
}


XTextureManager::~XTextureManager()
{
}

bool XTextureManager::CreateTexture(std::vector<unsigned char> imgData, unsigned int height, unsigned int width, bool isLightmap)
{

	HRESULT hr;
	ID3D11Texture2D *pTex2D = nullptr;
	D3D11_TEXTURE2D_DESC texDesc;
	memset(&texDesc, 0, sizeof(D3D11_TEXTURE2D_DESC));
	texDesc.Width = width;
	texDesc.Height = height;
	texDesc.MipLevels = texDesc.ArraySize = 1;
	texDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	texDesc.SampleDesc.Count = 1;
	texDesc.SampleDesc.Quality = 0;
	texDesc.Usage = D3D11_USAGE_DYNAMIC;
	texDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
	texDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	texDesc.MiscFlags = 0;

	hr = m_pD3D->CreateTexture2D(&texDesc, nullptr, &pTex2D);

	if (FAILED(hr))
		return false;

	D3D11_MAPPED_SUBRESOURCE  mappedTex;
	m_pd3dDeviceContext->Map(pTex2D, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedTex);

	UCHAR* pTexels = (UCHAR*)mappedTex.pData;
	int j = 0;
	for (UINT row = 0; row < texDesc.Height; row++)
	{
		UINT rowStart = row * mappedTex.RowPitch;
		for (UINT col = 0; col < texDesc.Width; col++)
		{
			UINT colStart = col * 4;
			pTexels[rowStart + colStart + 0] = imgData[j++];
			pTexels[rowStart + colStart + 1] = imgData[j++];
			pTexels[rowStart + colStart + 2] = imgData[j++];
			pTexels[rowStart + colStart + 3] = imgData[j++];
		}
	}

	m_pd3dDeviceContext->Unmap(pTex2D, D3D11CalcSubresource(0, 0, 1));

	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
	memset(&srvDesc, 0, sizeof(D3D11_SHADER_RESOURCE_VIEW_DESC));
	srvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	srvDesc.Texture2D.MipLevels = 1;
	XTextureContainer* texture= new XTextureContainer();
	hr = m_pD3D->CreateShaderResourceView(pTex2D, &srvDesc, &texture->pTexture);
	
	if (FAILED(hr))
		return false;
	
	if (!isLightmap)
	{
		m_textures.push_back(texture);
		m_numTextures++;
	}
	else
	{
		m_lightmaps.push_back(texture);
		m_numLightmaps++;
	}

	return true;
}

bool XTextureManager::CreateWhiteTexture(int width, int height, bool isLightMap)
{
	HRESULT hr;
	ID3D11Texture2D *pTex2D = nullptr;
	D3D11_TEXTURE2D_DESC texDesc;
	memset(&texDesc, 0, sizeof(D3D11_TEXTURE2D_DESC));
	texDesc.Width = width;
	texDesc.Height = height;
	texDesc.MipLevels = texDesc.ArraySize = 1;
	texDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	texDesc.SampleDesc.Count = 1;
	texDesc.SampleDesc.Quality = 0;
	texDesc.Usage = D3D11_USAGE_DYNAMIC;
	texDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
	texDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	texDesc.MiscFlags = 0;

	hr = m_pD3D->CreateTexture2D(&texDesc, nullptr, &pTex2D);

	if (FAILED(hr))
		return false;

	D3D11_MAPPED_SUBRESOURCE  mappedTex;
	m_pd3dDeviceContext->Map(pTex2D, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedTex);

	UCHAR* pTexels = (UCHAR*)mappedTex.pData;
	int j = 0;
	for (UINT row = 0; row < texDesc.Height; row++)
	{
		UINT rowStart = row * mappedTex.RowPitch;
		for (UINT col = 0; col < texDesc.Width; col++)
		{
			UINT colStart = col * 4;
			pTexels[rowStart + colStart + 0] = 255;
			pTexels[rowStart + colStart + 1] = 255;
			pTexels[rowStart + colStart + 2] = 255;
			pTexels[rowStart + colStart + 3] = 255;
		}
	}

	m_pd3dDeviceContext->Unmap(pTex2D, D3D11CalcSubresource(0, 0, 1));

	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
	memset(&srvDesc, 0, sizeof(D3D11_SHADER_RESOURCE_VIEW_DESC));
	srvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	srvDesc.Texture2D.MipLevels = 1;
	XTextureContainer* texture = new XTextureContainer();
	hr = m_pD3D->CreateShaderResourceView(pTex2D, &srvDesc, &texture->pTexture);

	if (FAILED(hr))
		return false;

	if (!isLightMap)
	{
		m_textures.push_back(texture);
		m_numTextures++;
	}
	else
	{
		m_lightmaps.push_back(texture);
		m_numLightmaps++;
	}

	return true;
}

bool XTextureManager::Load(const std::string & filePath, bool isLightmap)
{
	HRESULT hr;
	std::wstring wideFileName = std::wstring(filePath.begin(), filePath.end());
	XTextureContainer* pTex = new XTextureContainer();

	hr = D3DX11CreateShaderResourceViewFromFile(m_pD3D, wideFileName.c_str(), NULL, NULL, &pTex->pTexture, NULL);
	
	if (FAILED(hr))
		return false;
	
	if (!isLightmap)
	{
		m_textures.push_back(pTex);
		m_numTextures++;
	}
	else
	{
		m_lightmaps.push_back(pTex);
		m_numLightmaps++;
	}

	return true;
}


bool XTextureManager::Save(const std::string & filePath)
{
	return true;
}

bool XTextureManager::CreateSamplerState()
{
	HRESULT hr;
	D3D11_SAMPLER_DESC samplerDesc;
	// Create a texture sampler state description.
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
	hr = m_pD3D->CreateSamplerState(&samplerDesc, &m_pSampleState);
	if (FAILED(hr))
		return false;

	return true;
}
