#pragma once
#include "XGeomObject.h"
#include "TGAImage.h"
#include "XTextureManager.h"
#include "XCamera.h"

#define LIGHTMAP_SIZE 128

#pragma pack(1)
struct Q3MapDirEntry
{
	int offset;
	int length;
};

struct Q3MapHeader
{
	char magic[4];
	int version;
	Q3MapDirEntry direntries[17];
};


struct Q3MapEntities
{
	char* ents; // size of lump big
};

struct Q3MapTexture
{
	char name[64];
	int flags;
	int contents;
};

struct Q3MapPlane
{
	float normal[3];
	float dist;
};

struct Q3MapNode
{
	int plane;
	int children[2];
	int mins[3];
	int maxs[3];
};

struct Q3MapLeaf
{
	int cluster;
	int area;
	int mins[3];
	int maxs[3];
	int leafface;
	int nleaffaces;
	int leafbrush;
	int nleafbrushes;
};

struct Q3MapLeafFace
{
	int face;
};

struct Q3MapLeafBrush
{
	int brush;
};

struct Q3MapModel
{
	float mins[3];
	float maxs[3];
	int face;
	int nfaces;
	int brush;
	int nbrushes;
};

struct Q3MapBrush
{
	int brushside;
	int nbrushsides;
	int texture;
};

struct Q3MapBrushSide
{
	int  plane;
	int texture;
};

struct Q3MapVertex
{
	float pos[3];
	float texcoord[2][2];
	float normal[3];
	char color[4];
};

struct Q3MapMeshVert
{
	int offset;
};

struct Q3MapEffect
{
	char name[64];
	int brush;
	int unknown;
};

struct Q3MapFace
{
	int texture;
	int effect;
	int type;
	int vertex;
	int nvertices;
	int meshvert;
	int nmmeshverts;
	int lmindex;
	int lmstart[2];
	int lmsize[2];
	float lmorigin[3];
	float lmvecs[2][3];
	float normal[3];
	int size[2];
};

struct Q3MapLightMap
{
	unsigned char map[LIGHTMAP_SIZE*LIGHTMAP_SIZE*3];
};

struct Q3MapLightVol
{
	char ambient[3];
	char directional[3];
	char dir[2];
};

struct Q3MapVisData
{
	int nvectors;
	int sizevecs;
	char* vecs; // nevectors*sizevecs big
};
#pragma pack()

class XBezierPatch
{
private:
	int m_level;
	std::vector<TexVertex> m_vertices;
	std::vector<unsigned int> m_indices;
	std::vector<int> m_trianglesPerRow;

	std::vector<float> m_controlPoints;

public:
	XBezierPatch();
	XBezierPatch(int level, std::vector<float> controlPoints);
	~XBezierPatch();

	std::vector<TexVertex> GetVertices() { return m_vertices; }
	std::vector<unsigned int> GetIndices() { return m_indices; }

	int GetLevel() { return m_level; }
	void Tesselate(void);
};

class XWorldMap :
	public XGeomObject
{

protected:
	unsigned int	m_numEntities, m_numTextures, m_numPlanes, m_numNodes, m_numEffects, m_numFaces, m_numVertices, m_numMeshVertices,
		m_numLightMaps, m_numLeaves, m_numLeafFaces, m_visDataSize;
	bool m_lightMapsOn;
	std::vector<TextureIndexedFaceData*> m_faceData;
	std::vector<TextureIndexedFaceData*> m_visibleFaces;
	std::vector<ID3D11ShaderResourceView*> m_textures;
	std::vector<ID3D11ShaderResourceView*> m_lightMaps;
	std::vector<Q3MapTexture> m_q3Textures;
	Q3MapEntities m_q3Entities;
	std::vector<Q3MapVertex> m_q3Vertices;
	std::vector<Q3MapEffect> m_q3MapEffects;
	std::vector<Q3MapLeafBrush> m_q3MapLeafBrushes;
	std::vector<Q3MapBrush> m_q3MapBrushes;
	std::vector<Q3MapBrushSide> m_q3MapBrushSides;
	std::vector<Q3MapModel> m_q3MapModels;
	std::vector<Q3MapFace> m_q3Faces;
	std::vector<Q3MapMeshVert> m_q3MeshVertices;
	std::vector<Q3MapPlane> m_q3Planes;
	std::vector<Q3MapNode> m_q3Nodes;
	std::vector<Q3MapLeaf> m_q3Leaves;
	std::vector<Q3MapLeafFace> m_q3LeafFaces;
	std::vector<Q3MapLightMap> m_q3LightMaps;
	Q3MapVisData m_q3VisData;
public:
	XWorldMap();
	XWorldMap(ID3D11DeviceContext* pDevCntxt, ID3D11Device* pD3D, XTextureManager* pTextureManager) {
		m_pD3D = pD3D;
		m_pd3dDeviceContext = pDevCntxt;
		m_pTextureManager = pTextureManager;
		m_numShaders = 1;
	}
	~XWorldMap();

	std::vector<TextureIndexedFaceData*> GetFaceData() { return m_faceData; }
	std::vector<TextureIndexedFaceData*> GetVisibleFaces() {
		return m_visibleFaces;
	}
	const Q3MapEntities& GetEntities() const {
		return m_q3Entities;
	}
	std::vector<ID3D11ShaderResourceView*> GetTextures() { return m_textures; }
	std::vector<ID3D11ShaderResourceView*> GetLightMaps() { return m_lightMaps; }
	std::vector<Q3MapFace> GetFaces() { return m_q3Faces; }
	std::vector<Q3MapPlane> GetPlanes() { return m_q3Planes; }
	std::vector<Q3MapNode> GetNodes() { return m_q3Nodes; }
	std::vector<Q3MapLeaf> GetLeaves() { return m_q3Leaves; }
	std::vector<Q3MapLeafFace> GetLeafFaces() { return m_q3LeafFaces; }
	Q3MapVisData & GetVisibilityData() { return m_q3VisData; }
	int GetNumLeaves() const { return m_numLeaves; }
	// converts q3 coordinate system to D3D system
	void Swizzle(float& x, float& y, float& z)
	{
		float temp = y;
		y = z;
		z = temp;
	}

	void Swizzle(int& x, int& y, int& z)
	{
		int temp = y;
		y = z;
		z = temp;
	}

	bool IsAlreadyVisible(TextureIndexedFaceData* pFace)
	{
		if (std::find(m_visibleFaces.begin(), m_visibleFaces.end(), pFace) == m_visibleFaces.end())
			return false;
		else
			return true;
	}

	bool ReadHeader(std::ifstream& is, Q3MapHeader& head);
	void ReadEntities(std::ifstream& is, int offset, unsigned int length);
	void ReadTextures(std::ifstream& is, int offset, unsigned int length);
	void ReadPlanes(std::ifstream& is, int offset, unsigned int length);
	void ReadNodes(std::ifstream& is, int offset, unsigned int length);
	void ReadLeaves(std::ifstream& is, int offset, unsigned int length);
	void ReadLeafFaces(std::ifstream& is, int offset, unsigned int length);
	void ReadLeafBrushes(std::ifstream& is, int offset, unsigned int length);
	void ReadModels(std::ifstream& is, int offset, unsigned int length);
	void ReadBrushes(std::ifstream& is, int offset, unsigned int length);
	void ReadBrushSides(std::ifstream& is, int offset, unsigned int length);
	void ReadVertices(std::ifstream& is, int offset, unsigned int length);
	void ReadMeshVertices(std::ifstream& is, int offset, unsigned int length);
	void ReadEffects(std::ifstream& is, int offset, unsigned int length);
	void ReadFaces(std::ifstream& is, int offset, unsigned int length);
	void ReadLightMaps(std::ifstream& is, int offset, unsigned int length);
	void ReadVisibilityData(std::ifstream& is, int offset, unsigned int length);

	bool CreateLightmapShader();
	bool CreateInputLayout();
	bool Load(std::string fileName);
	bool OutputEntitiesToFile(const std::string& fileName);
	bool OutputShadersToFile(const std::string& fileName);
	bool CreateTextures();
	bool CreatePolygons();
	bool CreateLightmaps();
	int FindLeaf(const D3DXVECTOR3& cameraPos) const;
	bool IsClusterVisible(int visCluster, int testCluster) const;
	void AddSurfacesToDraw(XCamera& cam);
};

