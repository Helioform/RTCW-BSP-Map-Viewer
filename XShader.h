#pragma once
#include "HelperFunctions.h"
#include <d3d11.h>
#include <DirectXMath.h>
#include <D3DX10math.h>
#include <D3DX11async.h>
#include "XTextureManager.h"

#define MAX_SHADERS 256
#define MAX_TEXTURE_BLENDS 8
#define MAX_TEXTURE_STAGES 8
#define MAX_TEXTURE_ANIMS 8

// shader flags
#define XD3D_BLEND_ZERO                       0x00000001
#define XD3D_BLEND_ONE                        0x00000002
#define XD3D_BLEND_SRC_COLOR				  0x00000003
#define XD3D_BLEND_DST_COLOR                  0x00000004
#define XD3D_BLEND_ONE_MINUS_DST_COLOR        0x00000005
#define XD3D_BLEND_SRC_ALPHA                  0x00000006
#define XD3D_BLEND_ONE_MINUS_SRC_ALPHA        0x00000007
#define XD3D_BLEND_DST_ALPHA                  0x00000008
#define XD3D_BLEND_ONE_MINUS_DST_ALPHA        0x00000009
#define XD3D_BLEND_ALPHA_SATURATE             0x0000000A
#define XD3D_BLEND_BITS                       0x0000000B



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

enum tcModFunc
{
	sinWave,
	triWave,
	squareWave,
	sawTooth,
	inverseSawTooth
};

struct tcModScale
{
	float sScale, tScale;
};

struct tcModScroll
{
	float sSpeed, tSpeed;
};

struct tcModRotate
{
	float degreesPerSecond;
};

struct tcModStretch
{
	tcModFunc func;
	float	base;
	float	amplitude;
	float	phase;
	float   frequency;
};

struct tcModTransform
{


};

struct tcModTurb
{
	float	base;
	float	amplitude;
	float	phase;
	float	frequency;
};

struct tcMod
{
	tcModScale		scale;
	tcModScroll		scroll;
	tcModRotate		rotate;
	tcModStretch	stretch;
	tcModTransform	transform;
	tcModTurb		turbulence;
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
	XD3DRenderer*			m_pD3D;
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
	XD3DShader(XD3DRenderer* pD3D, XTextureManager* pTextureManager) {	
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
	bool SetParams(const D3DXMATRIX& view, const D3DXMATRIX& projection, const std::string& textureName, int lightmapId = -1);
	void BindVertexShader() {
		m_pD3D->GetDeviceContext()->VSSetShader(m_pVertexShader, nullptr, 0);
	}	
	void BindPixelShader() {
		m_pD3D->GetDeviceContext()->PSSetShader(m_pPixelShader, nullptr, 0);
	}

	bool CreateMatrixBuffer();
	bool CreateLightBuffer();
	void OutputErrorToFile();
};


struct TextureStage
{
	std::string				textureName;
	std::string				animTexturesNames[MAX_TEXTURE_ANIMS];
	bool					animated;
	float					animFrequency;
	int						numAnimTextures;
	unsigned int			srcBlend;
	unsigned int			destBlend;
	tcMod					tcMod;
};

class XShader
{
protected:	
	std::string				m_name;
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
	TextureStage			m_textureStages[MAX_TEXTURE_STAGES];
	int						m_numStages;
	int						m_currentFrame;
	float					m_clampTime;
	float					m_timeOffset;
public:
	XShader() :m_clampTime(0), m_timeOffset(0),m_currentFrame(0), m_name(""), m_numStages(0), m_lightmapIndex(0), m_numStates(0), m_numD3DShaders(0), m_currentState(0),
		m_textureID(0), m_shaderType(0), m_surfaceFlags(0), m_contentFlags(0), m_isSky(false), m_noPicMip(true) {}

	XShader(const std::string name, int type, int surfParams)
	{
		m_name = name;  m_shaderType = type; m_surfaceFlags = surfParams; m_numD3DShaders = 0;
		m_numStages = m_currentFrame = 0;
	}

	~XShader();
	
	int GetCurrentFrame() {
		return m_currentFrame;
	}

	void AdvanceFrame(void) {
		m_currentFrame++;
	}

	void	SetName(const std::string name) { m_name = name; }
	void	SetSurfaceFlags(int surfParam) { m_surfaceFlags = surfParam; }
	void	SetShaderType(int type) { m_shaderType = type;}
	
	void SetTextureStage(const TextureStage& stage)
	{
		assert(m_numStages <= MAX_TEXTURE_STAGES);
		m_textureStages[m_numStages++] = stage;
	}

	TextureStage* GetTextureStages()
	{
		return m_textureStages;
	}

	void SetDestBlend(int i, unsigned int destBlend) {
		assert(i < MAX_TEXTURE_STAGES); m_textureStages[i].destBlend = destBlend;
	}

	void SetSrcBlend(int i, unsigned int srcBlend) {
		assert(i < MAX_TEXTURE_STAGES); m_textureStages[i].srcBlend = srcBlend;
	}

	unsigned int GetDestBlend(int i) {
		assert(i < MAX_TEXTURE_STAGES); return m_textureStages[i].destBlend;
	}

	unsigned int GetSrcBlend(int i) {
		assert(i < MAX_TEXTURE_STAGES); return m_textureStages[i].srcBlend;
	}

	void SetTCMod(int i, const tcMod& t)
	{
		assert(i < MAX_TEXTURE_STAGES);
		m_textureStages[i].tcMod = t;
	}

	tcMod& GetTCMod(int i) {
		assert(i < MAX_TEXTURE_STAGES);
		return m_textureStages[i].tcMod;
	}

	int			GetNumStages(void) {
		return m_numStages;
	}
	std::string  GetName() { return m_name; }
	int			 GetSurfaceFlags() { return m_surfaceFlags; }
	int			GetShaderType() { return m_shaderType; }
	XD3DShader* GetD3DShader(int i)
	{
		assert(i < MAX_SHADERS);
		return m_pD3DShaders[i];
	}
	
	bool AttachD3DShader(XD3DShader* pD3DShader)
	{ 
		m_pD3DShaders.push_back(pD3DShader);
		m_numD3DShaders++;
		return true;
	}
};
