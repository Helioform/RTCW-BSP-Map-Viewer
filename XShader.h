#pragma once
#include "HelperFunctions.h"
#include <d3d11.h>
#include <DirectXMath.h>
#include <D3DX10math.h>
#include <D3DX11async.h>
#include "XTextureManager.h"

// shader flags
#define XD3D_SRCBLEND_ZERO                       0x00000001
#define XD3D_SRCBLEND_ONE                        0x00000002
#define XD3D_SRCBLEND_DST_COLOR                  0x00000003
#define XD3D_SRCBLEND_ONE_MINUS_DST_COLOR        0x00000004
#define XD3D_SRCBLEND_SRC_ALPHA                  0x00000005
#define XD3D_SRCBLEND_ONE_MINUS_SRC_ALPHA        0x00000006
#define XD3D_SRCBLEND_DST_ALPHA                  0x00000007
#define XD3D_SRCBLEND_ONE_MINUS_DST_ALPHA        0x00000008
#define XD3D_SRCBLEND_ALPHA_SATURATE             0x00000009
#define XD3D_SRCBLEND_BITS                       0x0000000f

#define XD3D_DSTBLEND_ZERO                       0x00000010
#define XD3D_DSTBLEND_ONE                        0x00000020
#define XD3D_DSTBLEND_SRC_COLOR                  0x00000030
#define XD3D_DSTBLEND_ONE_MINUS_SRC_COLOR        0x00000040
#define XD3D_DSTBLEND_SRC_ALPHA                  0x00000050
#define XD3D_DSTBLEND_ONE_MINUS_SRC_ALPHA        0x00000060
#define XD3D_DSTBLEND_DST_ALPHA                  0x00000070
#define XD3D_DSTBLEND_ONE_MINUS_DST_ALPHA        0x00000080
#define XD3D_DSTBLEND_BITS                       0x000000f0
#define XD3D_DEPTHMASK_TRUE                      0x00000100
#define XD3D_POLYMODE_LINE                       0x00001000
#define XD3D_DEPTHTEST_DISABLE                   0x00010000
#define XD3D_DEPTHFUNC_EQUAL                     0x00020000
#define XD3D_FOG_DISABLE                         0x00020000

class XShader
{
protected:	
	std::string m_name;
	XTextureManager* m_pTextureManager;
public:
	XShader();
	~XShader();
	virtual bool LoadAndCompile() { return true; }
	virtual bool SetParams() { return true; }
};

struct MatrixBufferType
{
	D3DXMATRIX world;
	D3DXMATRIX view;
	D3DXMATRIX projection;
};

struct LightBufferType
{
	D3DXVECTOR4 diffuseColor;
	D3DXVECTOR3 lightDirection;
	float padding;  // Added extra padding so structure is a multiple of 16 for CreateBuffer function requirements.
};

class XD3DShader : public XShader
{
protected:
	ID3D11Device* m_pD3D;
	ID3D11DeviceContext* m_pDeviceContext;
	ID3D11Buffer* m_pMatrixBuffer;
	ID3D11Buffer* m_pLightBuffer;
	D3DXMATRIX m_world;
	ID3D10Blob* m_pErrorMessage;
	ID3D10Blob* m_pVertexShaderBuffer;
	ID3D10Blob* m_pPixelShaderBuffer;
	ID3D11VertexShader* m_pVertexShader;
	ID3D11PixelShader* m_pPixelShader;

public:
	XD3DShader();
	XD3DShader(ID3D11DeviceContext* pDeviceContext, ID3D11Device* pD3D, XTextureManager* pTextureManager) {
		m_pDeviceContext = pDeviceContext;
		m_pD3D = pD3D;
		m_pTextureManager = pTextureManager;
		D3DXMatrixIdentity(&m_world);
	}
	~XD3DShader();

	ID3D11VertexShader* GetVertexShader()
	{
		return m_pVertexShader;
	}

	ID3D11PixelShader* GetPixelShader()
	{
		return m_pPixelShader;
	}

	ID3D10Blob* GetVertexShaderBuffer() {
		return m_pVertexShaderBuffer;
	}

	ID3D10Blob* GetPixelShaderBuffer()
	{
		return m_pPixelShaderBuffer;
	}

	ID3D10Blob* GetErrorMessage() {
		return m_pErrorMessage;
	}

	bool LoadAndCompile(const std::string& vertexShaderFileName, const std::string& pixelShaderFileName);
	bool SetParams(const D3DXMATRIX& view, const D3DXMATRIX& projection, int textureId, int lightmapId = -1);
	bool CreateMatrixBuffer();
	bool CreateLightBuffer();
	void OutputErrorToFile();
};



