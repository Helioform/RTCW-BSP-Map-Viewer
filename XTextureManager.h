#pragma once
#include "HelperFunctions.h"
#include "XD3D.h"
#include "Singleton.h"
#include <d3d11.h>
#include <DirectXMath.h>
#include <D3DX10math.h>
#include <D3DX11async.h>

struct XTextureContainer
{
	ID3D11ShaderResourceView* pTexture;
	bool isLightmap;
};

class XTextureManager : public Singleton<XTextureManager>
{
protected:
	std::vector<XTextureContainer*> m_textures;
	std::vector<XTextureContainer*> m_lightmaps;
	ID3D11SamplerState*				m_pSampleState;
	XD3DRenderer*					m_pD3D;
	int								m_numTextures;
	int								m_numLightmaps;

public:
	XTextureManager() { }
	XTextureManager(XD3DRenderer* pD3D)
	{
		m_pD3D = pD3D;
		m_numTextures = 0;
		m_numLightmaps = 0;
	}

	void UnloadTextures(void)
	{
		for (auto i : m_textures)
			i->pTexture->Release();

		for (auto i : m_lightmaps)
			i->pTexture->Release();

		m_numTextures = m_numLightmaps  = 0;
	}

	~XTextureManager()
	{
		UnloadTextures();
	}

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

	bool CreateTexture(unsigned char* imgData, unsigned int height, unsigned int width, bool isLightmap);
	bool CreateWhiteTexture(int, int, bool);
	bool Load(const std::string& filePath, bool isLightmap);
	bool Save(const std::string& filePath);
	bool CreateSamplerState();
};

