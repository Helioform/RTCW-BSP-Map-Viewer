#pragma once
#include "XGeomObject.h"
#include "TGAImage.h"

#define MAX_SPRITE_D3DSHADERS 8

class XSprite
{
	Vertex				m_vertices[4];
	int					m_indices[6];
	float m_width,		m_height;
	ID3D11Buffer*		m_pVertexBuffer;
	ID3D11Buffer*		m_pIndexBuffer;
	D3DXVECTOR3			m_center;
	ID3D11InputLayout*	m_pLayout;
	XD3DRenderer*		m_pD3D;
	XShader*			m_pShader;
	XD3DShader*			m_pD3DShaders[MAX_SPRITE_D3DSHADERS];
	XTextureManager*	m_pTextureManager;
	D3DXCOLOR			m_backGroundColor;
	D3DXCOLOR			m_foreGroundColor;
	float				m_alpha;
	int					m_numD3DShaders;
public:
	XSprite();

	XSprite(XD3DRenderer* pD3D, XShader* pShader, XTextureManager* pTextureManager, int width, int height, const D3DXVECTOR3& center) {
		m_pD3D = pD3D;
		m_pShader = pShader;
		m_pTextureManager = pTextureManager;
		m_width = width;
		m_height = height;
		m_center = center;
		m_backGroundColor = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);
		m_foreGroundColor = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		m_numD3DShaders = 0;

	}

	~XSprite();
	ID3D11Buffer* GetVertexBuffer(void) { return m_pVertexBuffer; }
	ID3D11Buffer* GetIndexBuffer(void) { return m_pIndexBuffer; }
	ID3D11InputLayout* GetInputLayout() {
		return m_pLayout;
	}

	bool CreateVertexBuffer(void);
	bool CreateIndexBuffer(void);
	bool CreateInputLayout(void);
	void LoadD3DShader(const std::string& vertexShaderFileName, const std::string& pixelShaderFileName)
	{
	//	if (m_numD3DShaders == 8) return;
	//	m_pD3DShaders[m_numD3DShaders] = new XD3DShader(m_pD3D, m_pTextureManager);
	//	m_pD3DShaders[m_numD3DShaders]->LoadAndCompile(vertexShaderFileName, pixelShaderFileName);
	//	m_numD3DShaders++;
	}
	bool Load(const std::string& fileName);

};

