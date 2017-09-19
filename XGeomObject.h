#pragma once

#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dx11.lib")
#pragma comment(lib,"d3d10.lib")


#include "HelperFunctions.h"
#include "XShader.h"
#include <iostream>

#define MAX_SHADERS 256

using namespace DirectX;

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
	ID3D11Device* m_pD3D;
	ID3D11DeviceContext* m_pd3dDeviceContext;
	std::vector<FaceData*> m_Faces;
	D3DXMATRIX m_world;
	D3DXVECTOR3 m_center;
	ID3D11InputLayout* m_pLayout;
	XD3DShader* m_pShaders[MAX_SHADERS];
	int m_numShaders;
	XTextureManager* m_pTextureManager;

public:
	XGeomObject();
	XGeomObject(ID3D11DeviceContext* pDevCntxt, ID3D11Device* pD3D, XTextureManager* pTextureManager) {
		m_pTextureManager = pTextureManager;
		m_pD3D = pD3D;
		m_pd3dDeviceContext = pDevCntxt;
	}
	~XGeomObject();
	XD3DShader* GetShader(int i) {
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

