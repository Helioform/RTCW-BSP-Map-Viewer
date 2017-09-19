#include "stdafx.h"
#include "XWorldMap.h"


XWorldMap::XWorldMap()
{
}


XWorldMap::~XWorldMap()
{
}

bool XWorldMap::ReadHeader(std::ifstream & is, Q3MapHeader & head)
{
	is.read((char*)(&head), sizeof(head));

	if (head.magic[0] != 'I'
		|| head.magic[1] != 'B'
		|| head.magic[2] != 'S'
		|| head.magic[3] != 'P')
		return false;

	return true;
}

void XWorldMap::ReadEntities(std::ifstream & is, int offset, unsigned int length)
{
	is.seekg(offset, is.beg);
	m_numEntities = length;
	m_q3Entities.ents = new char[length];
	is.read((m_q3Entities.ents), m_numEntities);
}

void XWorldMap::ReadTextures(std::ifstream & is, int offset, unsigned int length)
{
	is.seekg(offset, is.beg);
	m_numTextures = length / sizeof(Q3MapTexture);
	Q3MapTexture texture;
	m_q3Textures.reserve(m_numTextures);

	for (int i = 0; i < m_numTextures; ++i)
	{
		is.read((char*)(&texture), sizeof(Q3MapTexture));
		m_q3Textures.push_back(texture);
	}
}

void XWorldMap::ReadPlanes(std::ifstream & is, int offset, unsigned int length)
{
	is.seekg(offset, is.beg);
	m_numPlanes = length / sizeof(Q3MapPlane);
	Q3MapPlane plane;
	m_q3Planes.reserve(m_numPlanes);

	for (int i = 0; i < m_numPlanes; ++i)
	{
		is.read((char*)(&plane), sizeof(Q3MapPlane));
		Swizzle(plane.normal[0], plane.normal[1], plane.normal[2]);
		m_q3Planes.push_back(plane);
	}
}

void XWorldMap::ReadNodes(std::ifstream & is, int offset, unsigned int length)
{
	is.seekg(offset, is.beg);
	m_numNodes = length / sizeof(Q3MapNode);
	m_q3Nodes.reserve(m_numNodes);
	Q3MapNode node;

	for (int i = 0; i < m_numNodes; ++i)
	{
		is.read((char*)(&node), sizeof(Q3MapNode));
		Swizzle(node.mins[0], node.mins[1], node.mins[2]);
		Swizzle(node.maxs[0], node.maxs[1], node.maxs[2]);
		m_q3Nodes.push_back(node);
	}
}

void XWorldMap::ReadLeaves(std::ifstream & is, int offset, unsigned int length)
{
	is.seekg(offset, is.beg);
	m_numLeaves = length / sizeof(Q3MapLeaf);
	m_q3Leaves.reserve(m_numLeaves);
	Q3MapLeaf leaf;

	for (int i = 0; i < m_numLeaves; ++i)
	{
		is.read((char*)(&leaf), sizeof(Q3MapLeaf));
		Swizzle(leaf.mins[0], leaf.mins[1], leaf.mins[2]);
		Swizzle(leaf.maxs[0], leaf.maxs[1], leaf.maxs[2]);
		m_q3Leaves.push_back(leaf);
	}
}

void XWorldMap::ReadLeafFaces(std::ifstream & is, int offset, unsigned int length)
{
	is.seekg(offset, is.beg);
	m_numLeafFaces = length / sizeof(Q3MapLeafFace);
	m_q3LeafFaces.reserve(m_numLeafFaces);
	Q3MapLeafFace leafFace;

	for (int i = 0; i < m_numLeafFaces; ++i)
	{
		is.read((char*)(&leafFace), sizeof(Q3MapLeafFace));
		m_q3LeafFaces.push_back(leafFace);
	}
}

void XWorldMap::ReadLeafBrushes(std::ifstream & is, int offset, unsigned int length)
{
}

void XWorldMap::ReadModels(std::ifstream & is, int offset, unsigned int length)
{
}

void XWorldMap::ReadBrushes(std::ifstream & is, int offset, unsigned int length)
{
}

void XWorldMap::ReadBrushSides(std::ifstream & is, int offset, unsigned int length)
{
}

void XWorldMap::ReadVertices(std::ifstream & is, int offset, unsigned int length)
{
	is.seekg(offset, is.beg);
	m_numVertices = length / sizeof(Q3MapVertex);
	m_q3Vertices.reserve(m_numVertices);
	Q3MapVertex vertex;

	for (int i = 0; i < m_numVertices; ++i)
	{	
		is.read((char*)(&vertex), sizeof(Q3MapVertex));
		Swizzle(vertex.pos[0], vertex.pos[1], vertex.pos[2]);
		Swizzle(vertex.normal[0], vertex.normal[1], vertex.normal[2]);
		m_q3Vertices.push_back(vertex);
	}
}

void XWorldMap::ReadMeshVertices(std::ifstream & is, int offset, unsigned int length)
{
	is.seekg(offset, is.beg);
	m_numMeshVertices = length / sizeof(Q3MapMeshVert);
	m_q3MeshVertices.reserve(m_numMeshVertices);
	Q3MapMeshVert meshVert;

	for (int i = 0; i < m_numMeshVertices; ++i)
	{
		is.read((char*)(&meshVert), sizeof(Q3MapMeshVert));
		m_q3MeshVertices.push_back(meshVert);
	}
}

void XWorldMap::ReadEffects(std::ifstream & is, int offset, unsigned int length)
{
	is.seekg(offset, is.beg);
	m_numEffects = length / sizeof(Q3MapEffect);
	m_q3MapEffects.reserve(m_numEffects);
	Q3MapEffect effect;

	for (int i = 0; i < m_numEffects; ++i)
	{
		is.read((char*)&effect, sizeof(Q3MapEffect));
		m_q3MapEffects.push_back(effect);
	}

}

void XWorldMap::ReadFaces(std::ifstream & is, int offset, unsigned int length)
{
	is.seekg(offset, is.beg);
	m_numFaces = length / sizeof(Q3MapFace);
	m_q3Faces.reserve(m_numFaces);
	Q3MapFace face;

	for (int i = 0; i < m_numFaces; ++i)
	{
		is.read((char*)&face, sizeof(Q3MapFace));
		Swizzle(face.normal[0], face.normal[1], face.normal[2]);
		m_q3Faces.push_back(face);
	}
}

void XWorldMap::ReadLightMaps(std::ifstream & is, int offset, unsigned int length)
{
	is.seekg(offset, is.beg);
	m_numLightMaps = length / sizeof(Q3MapLightMap);
	m_q3LightMaps.reserve(m_numLightMaps);
	Q3MapLightMap lightMap;

	for (int i = 0; i < m_numLightMaps; ++i)
	{
		is.read((char*)(&lightMap), sizeof(Q3MapLightMap));
		m_q3LightMaps.push_back(lightMap);
	}
}

void XWorldMap::ReadVisibilityData(std::ifstream & is, int offset, unsigned int length)
{
	is.seekg(offset, is.beg);
	is.read((char*)&(m_q3VisData.nvectors), sizeof(int));
	is.read((char*)&(m_q3VisData.sizevecs), sizeof(int));
	m_visDataSize = m_q3VisData.nvectors*m_q3VisData.sizevecs;
	m_q3VisData.vecs = new char[m_visDataSize];
	is.read((char*)(m_q3VisData.vecs), m_visDataSize);
}

bool XWorldMap::CreateLightmapShader()
{
	m_pShaders[0] = new XD3DShader(m_pd3dDeviceContext, m_pD3D, m_pTextureManager);

	if (!m_pShaders[0]->LoadAndCompile("Effects/lightmap.vs", "Effects/lightmap.ps"))
	{
		m_pShaders[0]->OutputErrorToFile();
		return false;
	}
	m_pShaders[0]->CreateMatrixBuffer();
//	m_pShaders[0]->CreateLightBuffer();

	return true;
}

bool XWorldMap::CreateInputLayout()
{
	HRESULT hr;
	D3D11_INPUT_ELEMENT_DESC polygonLayout[4];
	unsigned int numElements;
	D3D11_BUFFER_DESC matrixBufferDesc;

	// Now setup the layout of the data that goes into the shader.
	polygonLayout[0].SemanticName = "POSITION";
	polygonLayout[0].SemanticIndex = 0;
	polygonLayout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	polygonLayout[0].InputSlot = 0;
	polygonLayout[0].AlignedByteOffset = 0;
	polygonLayout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	polygonLayout[0].InstanceDataStepRate = 0;

	polygonLayout[1].SemanticName = "TEXCOORD";
	polygonLayout[1].SemanticIndex = 0;
	polygonLayout[1].Format = DXGI_FORMAT_R32G32_FLOAT;
	polygonLayout[1].InputSlot = 0;
	polygonLayout[1].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	polygonLayout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	polygonLayout[1].InstanceDataStepRate = 0;
	
	polygonLayout[2].SemanticName = "TEXCOORD";
	polygonLayout[2].SemanticIndex = 1;
	polygonLayout[2].Format = DXGI_FORMAT_R32G32_FLOAT;
	polygonLayout[2].InputSlot = 0;
	polygonLayout[2].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	polygonLayout[2].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	polygonLayout[2].InstanceDataStepRate = 0;

	polygonLayout[3].SemanticName = "NORMAL";
	polygonLayout[3].SemanticIndex = 0;
	polygonLayout[3].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	polygonLayout[3].InputSlot = 0;
	polygonLayout[3].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	polygonLayout[3].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	polygonLayout[3].InstanceDataStepRate = 0;

	// Get a count of the elements in the layout.
	numElements = sizeof(polygonLayout) / sizeof(polygonLayout[0]);
	// Create the vertex input layout.
	hr = m_pD3D->CreateInputLayout(polygonLayout, numElements, m_pShaders[0]->GetVertexShaderBuffer()->GetBufferPointer(),
		m_pShaders[0]->GetVertexShaderBuffer()->GetBufferSize(), &m_pLayout);

	m_pShaders[0]->GetVertexShaderBuffer()->Release();
	m_pShaders[0]->GetPixelShaderBuffer()->Release();

	if (FAILED(hr))
		return false;

	return true;
}

bool XWorldMap::Load(std::string fileName)
{
	std::ifstream mapFile;

	mapFile.open(fileName.c_str(), std::ios::binary);

	if (!mapFile.is_open())
		return false;
	else
	{
		Q3MapHeader head;
		ReadHeader(mapFile, head);
		ReadEntities(mapFile, head.direntries[0].offset, head.direntries[0].length);
		ReadTextures(mapFile, head.direntries[1].offset, head.direntries[1].length);
		ReadPlanes(mapFile, head.direntries[2].offset, head.direntries[2].length);
		ReadNodes(mapFile, head.direntries[3].offset, head.direntries[3].length);
		ReadLeaves(mapFile, head.direntries[4].offset, head.direntries[4].length);
		ReadLeafFaces(mapFile, head.direntries[5].offset, head.direntries[5].length);
		ReadVertices(mapFile, head.direntries[10].offset, head.direntries[10].length);
		ReadMeshVertices(mapFile, head.direntries[11].offset, head.direntries[11].length);
		ReadEffects(mapFile, head.direntries[12].offset, head.direntries[12].length);
		ReadFaces(mapFile, head.direntries[13].offset, head.direntries[13].length);
		ReadLightMaps(mapFile, head.direntries[14].offset, head.direntries[14].length);
		ReadVisibilityData(mapFile, head.direntries[16].offset, head.direntries[16].length);
	}

	mapFile.close();
	if (!CreateTextures())
		return false;
	if (!CreateLightmaps())
		return false;		
	if (!CreatePolygons())
		return false;

	OutputEntitiesToFile("Entities.txt");
	OutputShadersToFile("Shaders.txt");
	return true;
}

bool XWorldMap::OutputEntitiesToFile(const std::string& fileName)
{
	std::ofstream outputFile;

	outputFile.open(fileName.c_str());

	if(outputFile.is_open())
		outputFile << m_q3Entities.ents;

	outputFile.close();

	return true;
}

bool XWorldMap::OutputShadersToFile(const std::string & fileName)
{
	std::ofstream outputFile;

	outputFile.open(fileName.c_str());

	if (outputFile.is_open())
	{
		for (int i = 0; i < m_numTextures; i++)
		{
			outputFile << m_q3Textures[i].name << std::endl;
		}
	}

	outputFile.close();

	return true;
}

bool XWorldMap::CreateTextures()
{
	// load textures and create texture buffers
	for (int i = 0; i < m_q3Textures.size(); ++i)
	{
		std::string jpgTextureFileName;
		jpgTextureFileName += "WorldMaps/";
		jpgTextureFileName += m_q3Textures[i].name;
		jpgTextureFileName += ".jpg";

		if (!m_pTextureManager->Load(jpgTextureFileName, false))
		{
			TGAImage tgaFile;
			std::string tgaTextureFileName;
			tgaTextureFileName += "WorldMaps/";
			tgaTextureFileName += m_q3Textures[i].name;
			tgaTextureFileName += ".tga";
			if (tgaFile.Load(tgaTextureFileName))
			{
				if (!m_pTextureManager->CreateTexture(tgaFile.GetImageData(), tgaFile.GetHeight(), tgaFile.GetWidth(), false))
					return false;
			}
			else
				m_pTextureManager->CreateWhiteTexture(128, 128, false);
		}
	}

	return true;
}

bool XWorldMap::CreatePolygons()
{
//	m_visibleFaces.reserve(100);

	// create face vertices and faces
	for (int i = 0; i < m_q3Faces.size(); ++i)
	{
		if (m_q3Faces[i].type == 1) // we have a polygon
		{
			std::vector<TexVertex> vertices;
			for (int j = 0; j < m_q3Faces[i].nmmeshverts; ++j)
			{
				int index = m_q3Faces[i].meshvert + j;
				int offset = m_q3Faces[i].vertex + m_q3MeshVertices[index].offset;
				TexVertex vert;
				vert.pos = D3DXVECTOR3(m_q3Vertices[offset].pos[0], m_q3Vertices[offset].pos[1], m_q3Vertices[offset].pos[2]);
				vert.tex0 = D3DXVECTOR2(m_q3Vertices[offset].texcoord[0][0], m_q3Vertices[offset].texcoord[0][1]);
				vert.lm = D3DXVECTOR2(m_q3Vertices[offset].texcoord[1][0], m_q3Vertices[offset].texcoord[1][1]);
				vert.normal = D3DXVECTOR3(m_q3Vertices[offset].normal[0], m_q3Vertices[offset].normal[1], m_q3Vertices[offset].normal[2]);
				vertices.push_back(vert);
			}

			TextureIndexedFaceData* newFace = new TextureIndexedFaceData();
			newFace->numVertices = m_q3Faces[i].nmmeshverts;
			newFace->textureIndex = m_q3Faces[i].texture;
			newFace->lightMapIndex = m_q3Faces[i].lmindex;
			newFace->bspFaceIndex = i;
			if (!CreateVertexBuffer(&newFace->pTexVBuffer, vertices.data(), m_q3Faces[i].nmmeshverts))
				return false;
			m_faceData.push_back(newFace);
		}
		else if (m_q3Faces[i].type == 2) // we have a bezier patch
		{
			std::vector<float> controlPoints;
			controlPoints.reserve(3*m_q3Faces[i].nvertices);
			int k = 0;

			for (int j = 0; j < m_q3Faces[i].nvertices; ++j)
			{
				int offset = m_q3Faces[i].vertex + j;

				controlPoints.push_back(m_q3Vertices[offset].pos[0]);
				controlPoints.push_back(m_q3Vertices[offset].pos[1]);
				controlPoints.push_back(m_q3Vertices[offset].pos[2]);
			}

			XBezierPatch bezierPatch(10, controlPoints);
			bezierPatch.Tesselate();
			std::vector<TexVertex> bezierVertices = bezierPatch.GetVertices();
			TextureIndexedFaceData* newFace = new TextureIndexedFaceData();
			newFace->numVertices = m_q3Faces[i].nvertices;
			newFace->textureIndex = m_q3Faces[i].texture;
			newFace->lightMapIndex = m_q3Faces[i].lmindex;
			newFace->bspFaceIndex = i;
			if (!CreateVertexBuffer( &newFace->pTexVBuffer, bezierVertices.data(), m_q3Faces[i].nvertices))
				return false;
			m_faceData.push_back(newFace);
		}
		else if (m_q3Faces[i].type == 3) // we have a mesh
		{	
			std::vector<TexVertex> vertices;
			for (int j = 0; j < m_q3Faces[i].nmmeshverts; ++j)
			{		
				int index = m_q3Faces[i].meshvert + j;
				int offset = m_q3Faces[i].vertex + m_q3MeshVertices[index].offset;
				TexVertex vert;
				vert.pos = D3DXVECTOR3(m_q3Vertices[offset].pos[0], m_q3Vertices[offset].pos[1], m_q3Vertices[offset].pos[2]);
				vert.tex0 = D3DXVECTOR2(m_q3Vertices[offset].texcoord[0][0], m_q3Vertices[offset].texcoord[0][1]);
				vert.lm = D3DXVECTOR2(m_q3Vertices[offset].texcoord[1][0], m_q3Vertices[offset].texcoord[1][1]);
				vert.normal = D3DXVECTOR3(m_q3Vertices[offset].normal[0], m_q3Vertices[offset].normal[1], m_q3Vertices[offset].normal[2]);
				vertices.push_back(vert);
			}

			TextureIndexedFaceData* newFace = new TextureIndexedFaceData();
			newFace->numVertices = m_q3Faces[i].nmmeshverts;
			newFace->textureIndex = m_q3Faces[i].texture;
			newFace->lightMapIndex = m_q3Faces[i].lmindex;
			newFace->bspFaceIndex = i;
			if (!CreateVertexBuffer( &newFace->pTexVBuffer, vertices.data(), m_q3Faces[i].nmmeshverts))
				return false;
			m_faceData.push_back(newFace);
		}
		else if (m_q3Faces[i].type == 4) // we have a billboard
		{
			std::vector<TexVertex> vertices;
			TexVertex vert[6];
			int offset = m_q3Faces[i].vertex;
			vert[0].pos = D3DXVECTOR3(m_q3Vertices[offset].pos[0], m_q3Vertices[offset].pos[1], m_q3Vertices[offset].pos[2]);
			vert[0].tex0 = D3DXVECTOR2(m_q3Vertices[offset].texcoord[0][0], m_q3Vertices[offset].texcoord[0][1]);
			vert[0].lm = D3DXVECTOR2(m_q3Vertices[offset].texcoord[1][0], m_q3Vertices[offset].texcoord[1][1]);
			vert[0].normal = D3DXVECTOR3(m_q3Vertices[offset].normal[0], m_q3Vertices[offset].normal[1], m_q3Vertices[offset].normal[2]);
			vert[1].pos = D3DXVECTOR3(m_q3Vertices[offset].pos[0], m_q3Vertices[offset].pos[1], m_q3Vertices[offset].pos[2]);
			vert[1].tex0 = D3DXVECTOR2(m_q3Vertices[offset].texcoord[0][0], m_q3Vertices[offset].texcoord[0][1]);
			vert[1].lm = D3DXVECTOR2(m_q3Vertices[offset].texcoord[1][0], m_q3Vertices[offset].texcoord[1][1]);
			vert[1].normal = D3DXVECTOR3(m_q3Vertices[offset].normal[0], m_q3Vertices[offset].normal[1], m_q3Vertices[offset].normal[2]);
			vert[2].pos = D3DXVECTOR3(m_q3Vertices[offset].pos[0], m_q3Vertices[offset].pos[1], m_q3Vertices[offset].pos[2]);
			vert[2].tex0 = D3DXVECTOR2(m_q3Vertices[offset].texcoord[0][0], m_q3Vertices[offset].texcoord[0][1]);
			vert[2].lm = D3DXVECTOR2(m_q3Vertices[offset].texcoord[1][0], m_q3Vertices[offset].texcoord[1][1]);
			vert[2].normal = D3DXVECTOR3(m_q3Vertices[offset].normal[0], m_q3Vertices[offset].normal[1], m_q3Vertices[offset].normal[2]);
			vert[3].pos = D3DXVECTOR3(m_q3Vertices[offset].pos[0], m_q3Vertices[offset].pos[1], m_q3Vertices[offset].pos[2]);
			vert[3].tex0 = D3DXVECTOR2(m_q3Vertices[offset].texcoord[0][0], m_q3Vertices[offset].texcoord[0][1]);
			vert[3].lm = D3DXVECTOR2(m_q3Vertices[offset].texcoord[1][0], m_q3Vertices[offset].texcoord[1][1]);
			vert[3].normal = D3DXVECTOR3(m_q3Vertices[offset].normal[0], m_q3Vertices[offset].normal[1], m_q3Vertices[offset].normal[2]);
			vert[4].pos = D3DXVECTOR3(m_q3Vertices[offset].pos[0], m_q3Vertices[offset].pos[1], m_q3Vertices[offset].pos[2]);
			vert[4].tex0 = D3DXVECTOR2(m_q3Vertices[offset].texcoord[0][0], m_q3Vertices[offset].texcoord[0][1]);
			vert[4].lm = D3DXVECTOR2(m_q3Vertices[offset].texcoord[1][0], m_q3Vertices[offset].texcoord[1][1]);
			vert[4].normal = D3DXVECTOR3(m_q3Vertices[offset].normal[0], m_q3Vertices[offset].normal[1], m_q3Vertices[offset].normal[2]);
			vert[5].pos = D3DXVECTOR3(m_q3Vertices[offset].pos[0], m_q3Vertices[offset].pos[1], m_q3Vertices[offset].pos[2]);
			vert[5].tex0 = D3DXVECTOR2(m_q3Vertices[offset].texcoord[0][0], m_q3Vertices[offset].texcoord[0][1]);
			vert[5].lm = D3DXVECTOR2(m_q3Vertices[offset].texcoord[1][0], m_q3Vertices[offset].texcoord[1][1]);
			vert[5].normal = D3DXVECTOR3(m_q3Vertices[offset].normal[0], m_q3Vertices[offset].normal[1], m_q3Vertices[offset].normal[2]);

			vertices.push_back(vert[0]);
			vertices.push_back(vert[1]);
			vertices.push_back(vert[2]);
			vertices.push_back(vert[3]);
			vertices.push_back(vert[4]);
			vertices.push_back(vert[5]);

			TextureIndexedFaceData* newFace = new TextureIndexedFaceData();
			newFace->numVertices = 6;
			newFace->textureIndex = m_q3Faces[i].texture;
			newFace->lightMapIndex =  m_q3Faces[i].lmindex;
			newFace->bspFaceIndex = i;
			if (!CreateVertexBuffer(&newFace->pTexVBuffer, vertices.data(), 6))
				return false;
			m_faceData.push_back(newFace);
		}
	}

	return true;
}

bool XWorldMap::CreateLightmaps()
{
	for (int i = 0; i < m_q3LightMaps.size(); ++i)
	{
		std::vector<unsigned char> lightMapData;
		lightMapData.reserve(4*128*128);
		int intensity = 0;
		int sumIntensity = 0;
		int maxIntensity = 0;
		float out[3];
		unsigned char* buffer = m_q3LightMaps[i].map;
		int k = 0;
		float rgba[4], r, g, b;
		char srgba[4];
		float gamma = 2.5f;

		for (int j = 0; j < LIGHTMAP_SIZE * LIGHTMAP_SIZE; ++j)
		{
			r = buffer[j * 3 + 0];
			g = buffer[j * 3 + 1];
			b = buffer[j * 3 + 2];
		/*
			float intensity;
			float out[3];

			intensity = 0.33f * r + 0.685f * g + 0.063f * b;

			if (intensity > 255)
				intensity = 1.0f;
			else
				intensity /= 255.0f;

			if (intensity > maxIntensity)
				maxIntensity = intensity;

			HSVtoRGB(intensity, 1.00, 0.50, out);
			sumIntensity += intensity;
				//	ColorShiftLightingBytes(&buf_p[j * 3], &image[j * 4]);
				//	image[j * 4 + 3] = 255;
				//
			*/
			//fill data back in
			lightMapData.push_back(r);
			lightMapData.push_back(g);
			lightMapData.push_back(b);
			lightMapData.push_back(255);
			
		}
		if (!m_pTextureManager->CreateTexture(lightMapData, 128, 128, true))
			return false;
	}

	return true;
}

int XWorldMap::FindLeaf(const D3DXVECTOR3 & cameraPos) const
{
	int index = 0;

	while (index >= 0)
	{
		const Q3MapNode& node = m_q3Nodes[index];
		const Q3MapPlane& plane = m_q3Planes[node.plane];
		const D3DXVECTOR3 planeNormal = D3DXVECTOR3(plane.normal[0], plane.normal[1], plane.normal[2]);
		// Distance from point to a plane
		const double distance = D3DXVec3Dot(&planeNormal, &cameraPos) - plane.dist;

		if (distance >= 0)
			index = node.children[0];
		else
			index = node.children[1];
	}

	return -index - 1;
}

bool XWorldMap::IsClusterVisible(int visCluster, int testCluster) const
{
	if ((m_q3VisData.vecs == nullptr) || (visCluster < 0))
		return true;

	int i = (visCluster * m_q3VisData.sizevecs) + (testCluster >> 3);
	unsigned char visSet = m_q3VisData.vecs[i];

	return (visSet & (1 << (testCluster & 7))) != 0;
}

void XWorldMap::AddSurfacesToDraw(XCamera& cam)
{
	m_visibleFaces.clear();

	// find the cluster the camera is in
	int l = FindLeaf(cam.Eye());
	int camCluster = m_q3Leaves[l].cluster;

	// iterate through all leaves and find the ones visible from camera	
	for (int i = 0; i < GetNumLeaves(); ++i)
	{
		if (!IsClusterVisible(camCluster, m_q3Leaves[i].cluster))
			continue;

		if (!cam.IsInFrustum(m_q3Leaves[i].mins, m_q3Leaves[i].maxs))
			continue;

		for (int j = 0; j < m_q3Leaves[i].nleaffaces; ++j)
		{
			const int f = j + m_q3Leaves[i].leafface;

			TextureIndexedFaceData* pFace = m_faceData[m_q3LeafFaces[f].face];
		//	if(!IsAlreadyVisible(pFace)) 
				m_visibleFaces.push_back(pFace);
		}
	}

}

XBezierPatch::XBezierPatch()
{
	m_level = 0;
}

XBezierPatch::XBezierPatch(int level, std::vector<float> controlPoints)
{
	m_level = level;
	m_controlPoints = controlPoints;
}

XBezierPatch::~XBezierPatch()
{

}

void XBezierPatch::Tesselate(void)
{
	int j = 0;

	for (int i = 0; i < m_controlPoints.size()/3; i++)
	{
		TexVertex v;
		v.pos.x = m_controlPoints[j++];
		v.pos.y = m_controlPoints[j++];
		v.pos.z = m_controlPoints[j++];
		m_vertices.push_back(v);
	}
}
