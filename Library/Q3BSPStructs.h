#pragma once

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
	unsigned char map[128*128 * 3];
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


