#pragma once
#include "HelperFunctions.h"
#include <d3d11.h>
#include <DirectXMath.h>
#include <D3DX10math.h>
#include <D3DX11async.h>
#include "XTextureManager.h"

#define MAX_SHADERS 256

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



// surface flags
#define CONTENTS_SOLID          1       // an eye is never valid in a solid
#define CONTENTS_LIGHTGRID      4   //----(SA)	added
#define CONTENTS_LAVA           8
#define CONTENTS_SLIME          16
#define CONTENTS_WATER          32
#define CONTENTS_FOG            64

//----(SA) added
#define CONTENTS_MISSILECLIP    128 // 0x80
#define CONTENTS_ITEM           256 // 0x100
//----(SA) end
// RF, AI sight/nosight & bullet/nobullet
#define CONTENTS_AI_NOSIGHT     0x1000  // AI cannot see through this
#define CONTENTS_CLIPSHOT       0x2000  // bullets hit this
// RF, end
#define CONTENTS_MOVER          0x4000
#define CONTENTS_AREAPORTAL     0x8000
#define CONTENTS_PLAYERCLIP     0x10000
#define CONTENTS_MONSTERCLIP    0x20000
//bot specific contents types
#define CONTENTS_TELEPORTER     0x40000
#define CONTENTS_JUMPPAD        0x80000
#define CONTENTS_CLUSTERPORTAL  0x100000
#define CONTENTS_DONOTENTER     0x200000
#define CONTENTS_DONOTENTER_LARGE       0x400000
#define CONTENTS_ORIGIN         0x1000000   // removed before bsping an entity
#define CONTENTS_BODY           0x2000000   // should never be on a brush, only in game
#define CONTENTS_CORPSE         0x4000000
#define CONTENTS_DETAIL         0x8000000   // brushes not used for the bsp
#define CONTENTS_STRUCTURAL     0x10000000  // brushes used for the bsp
#define CONTENTS_TRANSLUCENT    0x20000000  // don't consume surface fragments inside
#define CONTENTS_TRIGGER        0x40000000
#define CONTENTS_NODROP         0x80000000  // don't leave bodies or items (death fog, lava)zz


#define SURF_NODAMAGE           0x1     // never give falling damage
#define SURF_SLICK              0x2     // effects game physics
#define SURF_SKY                0x4     // lighting from environment map
#define SURF_LADDER             0x8
#define SURF_NOIMPACT           0x10    // don't make missile explosions
#define SURF_NOMARKS            0x20    // don't leave missile marks
//#define	SURF_FLESH			0x40	// make flesh sounds and effects
#define SURF_CERAMIC            0x40    // out of surf's, so replacing unused 'SURF_FLESH'
#define SURF_NODRAW             0x80    // don't generate a drawsurface at all
#define SURF_HINT               0x100   // make a primary bsp splitter
#define SURF_SKIP               0x200   // completely ignore, allowing non-closed brushes
#define SURF_NOLIGHTMAP         0x400   // surface doesn't need a lightmap
#define SURF_POINTLIGHT         0x800   // generate lighting info at vertexes
#define SURF_METAL              0x1000  // clanking footsteps
#define SURF_NOSTEPS            0x2000  // no footstep sounds
#define SURF_NONSOLID           0x4000  // don't collide against curves with this set
#define SURF_LIGHTFILTER        0x8000  // act as a light filter during q3map -light
#define SURF_ALPHASHADOW        0x10000 // do per-pixel light shadow casting in q3map
#define SURF_NODLIGHT           0x20000 // don't dlight even if solid (solid lava, skies)
#define SURF_WOOD               0x40000
#define SURF_GRASS              0x80000
#define SURF_GRAVEL             0x100000
#define SURF_GLASS              0x200000    // out of surf's, so replacing unused 'SURF_SMGROUP'
#define SURF_SNOW               0x400000
#define SURF_ROOF               0x800000
#define SURF_RUBBLE             0x1000000
#define SURF_CARPET             0x2000000
#define SURF_MONSTERSLICK       0x4000000   // slick surf that only affects ai's
#define SURF_MONSLICK_W         0x8000000
#define SURF_MONSLICK_N         0x10000000
#define SURF_MONSLICK_E         0x20000000
#define SURF_MONSLICK_S         0x40000000

struct SkyParams
{
	float cloudHeight;

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
	float		padding;  // Added extra padding so structure is a multiple of 16 for CreateBuffer function requirements.
};

class XD3DShader
{
protected:
	XTextureManager*		m_pTextureManager;
	ID3D11Device*			m_pD3D;
	ID3D11DeviceContext*	m_pDeviceContext;
	ID3D11Buffer*			m_pMatrixBuffer;
	ID3D11Buffer*			m_pLightBuffer;
	D3DXMATRIX				m_world;
	ID3D10Blob*				m_pErrorMessage;
	ID3D10Blob*				m_pVertexShaderBuffer;
	ID3D10Blob*				m_pPixelShaderBuffer;
	ID3D11VertexShader*		m_pVertexShader;
	ID3D11PixelShader*		m_pPixelShader;
	ID3D11BlendState*		m_blendStates[8];

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
	void BindVertexShader() {
		m_pDeviceContext->VSSetShader(m_pVertexShader, nullptr, 0);
	}	
	void BindPixelShader() {
		m_pDeviceContext->PSSetShader(m_pPixelShader, nullptr, 0);
	}

	bool CreateMatrixBuffer();
	bool CreateLightBuffer();
	void OutputErrorToFile();
};


class XShader
{
protected:	
	std::string				m_name;
	std::string				m_textureNames[8];
	int						m_numTextures;
	unsigned int			m_textureBlends[8];
	int						m_lightmapIndex;
	int						m_numStates;
	int						m_numD3DShaders;
	int						m_currentState;
	int						m_textureID;
	std::vector<XD3DShader*>m_pD3DShaders;
	int						m_shaderType;
	int						m_surfaceFlags;
	int						m_contentFlags;
	bool					m_isSky;
	SkyParams				m_sky;
	bool					m_polygonOffset;
	bool					m_noPicMip;
public:
	XShader() : m_name(""), m_numTextures(0), m_lightmapIndex(0), m_numStates(0), m_numD3DShaders(0), m_currentState(0),
		m_textureID(0), m_shaderType(0), m_surfaceFlags(0), m_contentFlags(0), m_isSky(false), m_noPicMip(true) {}

	XShader(const std::string name, const std::string* textureNames, int numTextures, int type, int surfParams)
	{
		m_name = name;  m_shaderType = type; m_surfaceFlags = surfParams; m_numD3DShaders = 0;
		memcpy(m_textureNames, textureNames, numTextures);
	}

	~XShader();
	
	void	SetName(const std::string name) { m_name = name; }
	void	SetSurfaceFlags(int surfParam) { m_surfaceFlags = surfParam; }
	void	SetTextureName(int i, const std::string name) { m_textureNames[i] = name; m_numTextures++; }
	void	SetBlendState(int i, unsigned int blendFactor) { m_textureBlends[i] = blendFactor; }
	void	SetShaderType(int type) { m_shaderType = type;}

	std::string  GetName() { return m_name; }
	int			 GetSurfaceFlags() { return m_surfaceFlags; }
	std::string  GetTextureName(int i) { return m_textureNames[i]; }
	unsigned int GetBlendState(int i) { return m_textureBlends[i]; }
	int			GetShaderType() { return m_shaderType; }
	
	XD3DShader* GetD3DShader(int i)
	{
		if (i > m_numD3DShaders) return nullptr;
		return m_pD3DShaders[i];
	}
	
	bool AttachD3DShader(XD3DShader* pD3DShader)
	{ 
		m_pD3DShaders.push_back(pD3DShader);
		m_numD3DShaders++;
		return true;
	}
};
