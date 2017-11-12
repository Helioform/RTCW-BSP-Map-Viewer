#pragma once

#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dx11.lib")
#pragma comment(lib,"d3d10.lib")


#include "HelperFunctions.h"
#include "XShader.h"
#include <iostream>

#define MAX_SHADERS 256

using namespace DirectX;



struct TexVertex
{
	D3DXVECTOR3 pos;
	D3DXVECTOR2 tex0;
	D3DXVECTOR2 lm;
	D3DXVECTOR3 normal;
};

struct FaceData
{
	ID3D11Buffer* pTexVBuffer;
	ID3D11ShaderResourceView* pTexture;
};

struct TextureIndexedFaceData
{
	ID3D11Buffer* pTexVBuffer;
	int textureIndex;
	int lightMapIndex;
	int numVertices;
	int bspFaceIndex;
	int surfaceParams;
};

struct Vertex
{
	D3DXVECTOR3 pos;
	D3DXVECTOR4 color;
	D3DXVECTOR2 tex;
};

class XGeomObject
{
protected:
	ID3D11Device*			m_pD3D;
	ID3D11DeviceContext*	m_pd3dDeviceContext;
	std::vector<FaceData*>	m_Faces;
	D3DXMATRIX				m_world;
	D3DXVECTOR3				m_center;
	ID3D11InputLayout*		m_pLayout;
	XShader*				m_pShaders[MAX_SHADERS];
	XD3DShader*				m_pD3DShaders[MAX_SHADERS];
	int						m_numShaders;
	XTextureManager*		m_pTextureManager;

public:
	XGeomObject();
	XGeomObject(ID3D11DeviceContext* pDevCntxt, ID3D11Device* pD3D, XTextureManager* pTextureManager) {
		m_pTextureManager = pTextureManager;
		m_pD3D = pD3D;
		m_pd3dDeviceContext = pDevCntxt;
	}
	~XGeomObject();

	virtual bool LoadShaders(void);
	int SkipWhites(const std::string& text, int pos);
	int ParseWord(const std::string& text, int pos, std::string& token);
	void ParseShader(const std::string& text);
	int FindShader(const std::string& text, int pos);
	

	XD3DShader* GetD3DShader(int i) {
		return m_pD3DShaders[i];
	}

	XShader* GetShader(int i) {
		return m_pShaders[i];
	}

	XTextureManager* GetTextureManager() {
		return m_pTextureManager;
	}

	std::vector<FaceData*> GetFaceData() { return m_Faces; }
	ID3D11InputLayout* GetInputLayout() { return m_pLayout; }
	D3DXMATRIX& GetWorldMatrix() { return m_world; }
	D3DXVECTOR3 GetCenter() { return m_center; }
	bool CreateFaceData(TexVertex* pVertices, unsigned long* pIndices, unsigned int numVertices, unsigned int numIndices, ID3D11ShaderResourceView** pTextures);
	virtual bool CreateInputLayout();
	virtual bool CreateVertexBuffer(ID3D11Buffer** pVB, TexVertex* pVertices, unsigned int numVertices);
    bool CreateIndexBuffer(ID3D11Buffer** pIB, unsigned long* pIndices, unsigned int numIndices);
    bool CreateTest(void);
	
	void Translate(float dx, float dy, float dz)
	{
		D3DXMATRIX trans;
		D3DXMatrixTranslation(&trans, dx, dy, dz);
		m_world = m_world * trans;
	}
	void RotateX(float r)
	{
		D3DXMATRIX xrot;
		D3DXMatrixRotationX(&xrot, r);
		m_world = m_world * xrot;
	}

	void RotateY(float r)
	{	
		D3DXMATRIX yrot;
		D3DXMatrixRotationY(&yrot, r);
		m_world = m_world * yrot;
	}

	void RotateZ(float r)
	{
		D3DXMATRIX zrot;
		D3DXMatrixRotationX(&zrot, r);
		m_world = m_world * zrot;
	}

	bool BuildCube(float c, const D3DXVECTOR3& center);
	bool BuildSphere(float radius, const D3DXVECTOR3& center, int u, int v);

	bool virtual LoadModel(const std::string& fileName);
};

