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
	std::unordered_map<std::string, XTextureContainer*> m_textures;
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
			i.second->pTexture->Release();

		for (auto i : m_lightmaps)
			i->pTexture->Release();

		m_numTextures = m_numLightmaps = 0;
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

	ID3D11ShaderResourceView* GetTexture(const std::string& name) {
	//	assert(m_textures[name]);
		if (m_textures[name] == nullptr)
			return nullptr;

		return m_textures[name]->pTexture;
	}
	
	ID3D11ShaderResourceView* GetLightmap(int id) {
		assert(m_lightmaps[id]);
		return m_lightmaps[id]->pTexture;
	}

	ID3D11SamplerState* GetSamplerState() {
		return m_pSampleState;
	}

	bool CreateTexture(unsigned char* imgData, const std::string& name, unsigned int height, unsigned int width, bool isLightmap);
	bool CreateWhiteTexture(int, int, bool);
	bool Load(const std::string& filePath, const std::string& name, bool isLightmap);
	bool Save(const std::string& filePath, const std::string& name);
	bool CreateSamplerState();
};

