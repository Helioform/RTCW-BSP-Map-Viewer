#pragma once
#include "XGeomObject.h"
#include "TGAImage.h"

class XSprite
{
	Vertex				m_vertices[6];
	float m_width,		m_height;
	ID3D11Buffer*		m_pVertexBuffer;
	D3DXVECTOR3			m_center;
	ID3D11InputLayout*	m_pLayout;


public:
	XSprite();
	~XSprite();
	ID3D11Buffer* GetVertexBuffer() { return m_pVertexBuffer; }
	bool CreateInputLayout(ID3D11Device* pd3d);
	bool Load(std::string fileName);

};

