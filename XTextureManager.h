#pragma once
#include "HelperFunctions.h"
#include <d3d11.h>
#include <DirectXMath.h>
#include <D3DX10math.h>
#include <D3DX11async.h>

struct XTextureContainer
{
	ID3D11ShaderResourceView* pTexture;
	bool isLightmap;
};

class XTextureManager
{
protected:
	std::vector<XTextureContainer*> m_textures;
	std::vector<XTextureContainer*> m_lightmaps;
	ID3D11SamplerState*  m_pSampleState;
	ID3D11Device* m_pD3D;
	ID3D11DeviceContext* m_pd3dDeviceContext;
	int m_numTextures;
	int m_numLightmaps;

public:
	XTextureManager();
	XTextureManager(ID3D11Device* pD3D, ID3D11DeviceContext* pd3dDeviceContext)
	{
		m_pD3D = pD3D;
		m_pd3dDeviceContext = pd3dDeviceContext;
		m_numTextures = 0;
		m_numLightmaps = 0;
	}

	~XTextureManager();
	int GetNumTextures() {
		return m_numTextures;
	}

	int GetNumLightmaps() {
		return m_numLightmaps;
	}

	ID3D11ShaderResourceView* GetTexture(int id) {
		return (m_textures[id]==nullptr)?nullptr:m_textures[id]->pTexture;
	}
	
	ID3D11ShaderResourceView* GetLightmap(int id) {
		return (m_lightmaps[id]==nullptr)?nullptr:m_lightmaps[id]->pTexture;
	}

	ID3D11SamplerState* GetSamplerState() {
		return m_pSampleState;
	}

	bool CreateTexture(std::vector<unsigned char> imgData, unsigned int height, unsigned int width, bool isLightmap);
	bool CreateWhiteTexture(int, int, bool);
	bool Load(const std::string& filePath, bool isLightmap);
	bool Save(const std::string& filePath);
	bool CreateSamplerState();
};

