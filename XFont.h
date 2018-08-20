#pragma once
#include "HelperFunctions.h"
#include "XGeomObject.h"

struct TexCoords
{
	float u[4], v[4];
};

class XFont
{
	std::string					m_screenText;
	std::unordered_map<char, TexCoords>	m_charTextureCoords;
//	TexCoords					m_charTextureCoords[128];
	XD3DRenderer*				m_pD3D;
	XTextureManager*			m_pTexManager;
	ID3D11InputLayout*			m_pLayout;
	XShader*					m_pShaders[MAX_SHADERS];
	XD3DShader*					m_pD3DShaders[MAX_SHADERS];
	int							m_numShaders;
	int							m_numD3DShaders;
	ID3D11Buffer*				m_pVertexBuffer;
	int							m_spacing;
	int							m_charWidth, m_charHeight;
public:
	XFont() : m_pD3D(nullptr), m_pTexManager(nullptr), m_pLayout(nullptr), m_numShaders(0), m_numD3DShaders(0), m_pVertexBuffer(nullptr),m_spacing(0), m_charWidth(0), m_charHeight(0) { }
	XFont(XD3DRenderer* pD3D, XTextureManager* pTexManager, int spacing, int charWidth, int charHeight) : m_pD3D(pD3D), m_pTexManager(pTexManager), m_pLayout(nullptr), 
		m_pVertexBuffer(nullptr), m_spacing(spacing), m_charWidth(charWidth), m_charHeight(charHeight)
	{
		
	}

	~XFont()
	{ 
		if (m_pVertexBuffer)
			SAFE_RELEASE(m_pVertexBuffer);
		
		if (m_pLayout)
			SAFE_RELEASE(m_pLayout);

		for (int i = 0; i < m_numShaders; i++)
			delete m_pShaders[i];

		for(int i = 0; i < m_numD3DShaders; i++)
			delete m_pD3DShaders[i];
	}

	bool CreateShaders();
	bool LoadFontTextureMap(const std::string& fileName);
	bool CreateInputLayout();
	bool CreateVertexBuffer(Vertex* pVertices, unsigned int numVertices);
	bool UpdateVertexBuffer(Vertex* pVertices, unsigned int numVertices);
	bool WriteText(int x, int y, const std::string& text, const D3DXVECTOR4& col, XCamera* pCam);

};

