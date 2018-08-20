
#include "XWorldMap.h"



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
	m_entStringLength = length;
	m_q3Entities.ents = new char[length];
	is.read((m_q3Entities.ents), m_entStringLength);
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
	is.seekg(offset, is.beg);
	m_numLeafBrushes = length / sizeof(Q3MapLeafBrush);
	m_q3MapLeafBrushes.reserve(m_numLeafBrushes);
	Q3MapLeafBrush leafBrush;

	for (int i = 0; i < m_numLeafBrushes; ++i)
	{
		is.read((char*)(&leafBrush), sizeof(Q3MapLeafBrush));
		m_q3MapLeafBrushes.push_back(leafBrush);
	}
}

void XWorldMap::ReadModels(std::ifstream & is, int offset, unsigned int length)
{
	is.seekg(offset, is.beg);
	m_numModels = length / sizeof(Q3MapModel);
	m_q3MapModels.reserve(m_numModels);
	Q3MapModel model;

	for (int i = 0; i < m_numModels; ++i)
	{
		is.read((char*)(&model), sizeof(Q3MapModel));
		m_q3MapModels.push_back(model);
	}
}

void XWorldMap::ReadBrushes(std::ifstream & is, int offset, unsigned int length)
{
	is.seekg(offset, is.beg);
	m_numBrushes = length / sizeof(Q3MapBrush);
	m_q3MapBrushes.reserve(m_numBrushes);
	Q3MapBrush brush;

	for (int i = 0; i < m_numBrushes; i++)
	{
		is.read((char*)(&brush), sizeof(Q3MapBrush));
		m_q3MapBrushes.push_back(brush);
	}
}

void XWorldMap::ReadBrushSides(std::ifstream & is, int offset, unsigned int length)
{
	is.seekg(offset, is.beg);
	m_numBrushSides = length / sizeof(Q3MapBrushSide);
	m_q3MapBrushSides.reserve(m_numBrushSides);
	Q3MapBrushSide brushSide;

	for (int i = 0; i < m_numBrushSides; i++)
	{
		is.read((char*)(&brushSide), sizeof(Q3MapBrushSide));
		m_q3MapBrushSides.push_back(brushSide);
	}
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

bool XWorldMap::LoadLightmapShader()
{
	m_pD3DShaders[0] = new XD3DShader(m_pD3D, m_pTextureManager);

	if (!m_pD3DShaders[0]->LoadAndCompile("Effects/lightmap.vs", "Effects/lightmap.ps", "LightMapVertexShader", "LightMapPixelShader"))
	{
		m_pD3DShaders[0]->OutputErrorToFile();
		return false;
	}
	m_pD3DShaders[0]->CreateMatrixBuffer();
	//m_pShaders[0] = new XShader("lightmap", 0, 0, m_pD3DShaders[0]);
	m_numShaders=0;
	//	m_pShaders[0]->CreateLightBuffer();

	return true;
}



bool XWorldMap::LoadShaders()
{
	std::string shaderName;
	int type = 0;
	std::string shaderScriptFilePath = MapPath + "scripts\\*";
	std::vector<std::string> fileNames;

	GetFileNames(shaderScriptFilePath, fileNames);

	std::string scriptData = "";
	// open all script files for reading
	for (int i = 0; i < fileNames.size(); ++i)
	{
		std::ifstream scriptFile;
		scriptFile.open(MapPath + "scripts/" + fileNames[i]);

		if (!scriptFile.is_open())
			return false;

		// aggregate all script file data
		std::string presentFileData;

		while (std::getline(scriptFile, presentFileData))
			scriptData += presentFileData+"\n";

		scriptFile.close();
	}

	int shaderSurfParams=0;
	XShaderParser shaderParser(&scriptData);
	std::string token;
	int shaderPos = 0;

	shaderParser.ParseShaderFile();
	XShader sh;

	for (int i = 0; i < m_q3Textures.size(); ++i)
	{
		shaderName = m_q3Textures[i].name;

		if (shaderParser.FindShader(shaderName, &sh))
		{			
			// create our new shader and add it to the list
			XShader* pShader = new XShader(sh);
			pShader->SetName(shaderName);
			pShader->AttachD3DShader(m_pD3DShaders[0]);		
			m_pShaders[m_numShaders] = pShader;
			m_numShaders++;
		}
		else // create default shader
		{
			XShader* pShader = new XShader(shaderName, 0, 0);
			pShader->AttachD3DShader(m_pD3DShaders[0]);
			m_pShaders[m_numShaders] = pShader;
			m_numShaders++;
		}
	}

	return true;
}

bool XWorldMap::LoadEntities()
{
	m_numEntities = 0;
	std::string ents = std::string(m_q3Entities.ents);

	int pos;
	std::istringstream entStream(ents);
	std::string line;
	bool playerPosFound = false;
	int entDataPos = 0;
	std::string entClassName, entName;
	int x = 0, y = 0, z = 0;

	while (std::getline(entStream, line))
	{
		if (line == "{")
		{
			while (line != "}")
			{
				std::getline(entStream, line);

				if ((entDataPos = line.find("\"classname\"")) != std::string::npos)
				{
					entName = line.substr(std::string("\"classname\" ").length() + 1, line.length() - 1);
				}
				else if ((entDataPos = line.find("\"origin\"")) != std::string::npos)
				{
					std::string entPosLine = line.substr(std::string("\"origin\" ").length() + 1, line.length() - 1);

					std::stringstream entPos(entPosLine);
					entPos >> x;
					entPos >> y;
					entPos >> z;
				}
				else if ((entDataPos = line.find("\"model\"")) != std::string::npos)
				{

				}
			}
		}

		if (entName == "info_player_start\"" || entName == "info_player_deathmatch\"")
		{
			m_playerEntityIndex = m_numEntities;
			m_mapEntities.push_back(new XPlayer(entName, D3DXVECTOR3(x, z+PLAYER_HEIGHT, y), D3DXVECTOR3(0, 0, 1), SCREEN_WIDTH, SCREEN_HEIGHT, 90, 0.1, 10000));
		}
		else
		{
			m_mapEntities.push_back(new XEntity(entName, D3DXVECTOR3(x, z, y), D3DXVECTOR3(0, 0, 1), SCREEN_WIDTH, SCREEN_HEIGHT, 90, 0.1, 10000));
		}

		m_numEntities++;
	}

	return playerPosFound;
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

	numElements = sizeof(polygonLayout) / sizeof(polygonLayout[0]);

	hr = m_pD3D->GetD3DDevice()->CreateInputLayout(polygonLayout, numElements, m_pD3DShaders[0]->GetVertexShaderBuffer()->GetBufferPointer(),
		m_pD3DShaders[0]->GetVertexShaderBuffer()->GetBufferSize(), &m_pLayout);

	m_pD3DShaders[0]->GetVertexShaderBuffer()->Release();
	m_pD3DShaders[0]->GetPixelShaderBuffer()->Release();

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
		ReadLeafBrushes(mapFile, head.direntries[6].offset, head.direntries[6].length);
		ReadModels(mapFile, head.direntries[7].offset, head.direntries[7].length);
		ReadBrushes(mapFile, head.direntries[8].offset, head.direntries[8].length);
		ReadBrushSides(mapFile, head.direntries[9].offset, head.direntries[9].length);
		ReadVertices(mapFile, head.direntries[10].offset, head.direntries[10].length);
		ReadMeshVertices(mapFile, head.direntries[11].offset, head.direntries[11].length);
		ReadEffects(mapFile, head.direntries[12].offset, head.direntries[12].length);
		ReadFaces(mapFile, head.direntries[13].offset, head.direntries[13].length);
		ReadLightMaps(mapFile, head.direntries[14].offset, head.direntries[14].length);
		ReadVisibilityData(mapFile, head.direntries[16].offset, head.direntries[16].length);
	}

	mapFile.close();

	if (!LoadShaders())
		return false;
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
	for (int i = 0; i < m_numShaders; ++i)
	{
		if (m_pShaders[i]->GetNumStages())
		{
			for (int j = 0; j < m_pShaders[i]->GetNumStages(); ++j)
			{
				TextureStage ts = m_pShaders[i]->GetTextureStages()[j];

				if (ts.animated)
				{
					for (int k = 0; k < ts.numAnimTextures; ++k)
					{
						std::string name = ts.animTexturesNames[k];

						if (!StrCaseCmp(name.c_str(), "$lightmap"))
							continue;

						std::string textureFileName = MapPath + name;
						TGAImage tgaFile;

						if (tgaFile.Load(textureFileName))
						{
							if (!m_pTextureManager->CreateTexture(tgaFile.GetImageData(), name, tgaFile.GetHeight(), tgaFile.GetWidth(), false))
								return false;
						}
						else
						{
							std::string jpgTextureFileName;
							jpgTextureFileName += MapPath;
							jpgTextureFileName += name.substr(0, name.length() - 3);
							jpgTextureFileName += "jpg";

							if (!m_pTextureManager->Load(jpgTextureFileName, name, false))
							{
								m_pTextureManager->CreateWhiteTexture(128, 128, false);
							}
						}
					}
				}
				else
				{
					std::string name = ts.textureName;

					if (!StrCaseCmp(name.c_str(), "$lightmap"))
						continue;

					std::string textureFileName = MapPath + name;
					TGAImage tgaFile;

					if (tgaFile.Load(textureFileName))
					{
						if (!m_pTextureManager->CreateTexture(tgaFile.GetImageData(), name, tgaFile.GetHeight(), tgaFile.GetWidth(), false))
							return false;
					}
					else
					{
						std::string jpgTextureFileName;
						jpgTextureFileName += MapPath;
						jpgTextureFileName += name.substr(0, name.length() - 3);
						jpgTextureFileName += "jpg";

						if (!m_pTextureManager->Load(jpgTextureFileName, name, false))
						{
							m_pTextureManager->CreateWhiteTexture(128, 128, false);
						}
					}

				}
			}
		}
		else // no shader just try an image file
		{
			std::string jpgTextureFileName;
			jpgTextureFileName += MapPath;
			jpgTextureFileName += m_pShaders[i]->GetName();
			jpgTextureFileName += ".jpg";

			if (!m_pTextureManager->Load(jpgTextureFileName, m_pShaders[i]->GetName(), false))
			{
				TGAImage tgaFile;
				std::string tgaTextureFileName;
				tgaTextureFileName += MapPath;
				tgaTextureFileName += m_pShaders[i]->GetName();
				tgaTextureFileName += ".tga";
				if (tgaFile.Load(tgaTextureFileName))
				{
					if (!m_pTextureManager->CreateTexture(tgaFile.GetImageData(), m_pShaders[i]->GetName()+".tga", tgaFile.GetHeight(), tgaFile.GetWidth(), false))
						return false;
				}
				else
					m_pTextureManager->CreateWhiteTexture(128, 128, false);
			}
		}
	}

	return true;
}

bool XWorldMap::CreatePolygons()
{
	m_visibleFaces.reserve(1000);

	// create face vertices and faces
	for (int i = 0; i < m_q3Faces.size(); ++i)
	{	
		
		if ((m_pShaders[m_q3Faces[i].texture]->GetSurfaceFlags() & CONTENTS_FOG) ||
			(m_pShaders[m_q3Faces[i].texture]->GetSurfaceFlags() & SURF_NODRAW)) // don't create no draw surface
		{
			m_faceData.push_back(nullptr);
			continue;
		}

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
	unsigned char* lightMapData = new unsigned char[4*LIGHTMAP_SIZE*LIGHTMAP_SIZE];
	
	for (int i = 0; i < m_q3LightMaps.size(); ++i)
	{
		unsigned char* buffer = m_q3LightMaps[i].map;
		int k = 0;
	
		for (int j = 0; j < LIGHTMAP_SIZE * LIGHTMAP_SIZE; ++j)
		{	
			ColorShiftLightingBytes(&buffer[j * 3], &lightMapData[j * 4]);
			lightMapData[j * 4 + 3] = 255;
		}

		if (!m_pTextureManager->CreateTexture(lightMapData, "lightmap", LIGHTMAP_SIZE, LIGHTMAP_SIZE, true))
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
//	const int l = FindLeaf(cam.GetPosition());
	const int camCluster = m_q3Leaves[m_currentLeafPosition].cluster;

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
			if (m_faceData[m_q3LeafFaces[f].face] == nullptr)
				continue;

			TextureIndexedFaceData* pFace = m_faceData[m_q3LeafFaces[f].face];
		//	if (IsAlreadyVisible(pFace))
		//		continue;
			
			m_visibleFaces.push_back(pFace);
		}
	}

}


void XWorldMap::Render(XCamera* pCam)
{
	HRESULT hr;
	unsigned int stride;
	unsigned int offset;

	stride = sizeof(TexVertex);
	offset = 0;

	XD3DShader* pShader = GetD3DShader(0);

	std::vector<TextureIndexedFaceData*> visibleFaces = GetVisibleFaces();

	for (int i = 0; i < visibleFaces.size(); ++i)
	{
		ID3D11Buffer* pVB = visibleFaces[i]->pTexVBuffer;
		m_pD3D->GetDeviceContext()->IASetVertexBuffers(0, 1, &pVB, &stride, &offset);

		m_pD3D->GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

		m_pD3D->GetDeviceContext()->IASetInputLayout(GetInputLayout());

		XShader* pSh = m_pShaders[visibleFaces[i]->textureIndex];

		if (!pSh->GetNumStages())
		{
			if (visibleFaces[i]->lightMapIndex < 0)
				pShader->SetParams(pCam->ViewMatrix(), pCam->ProjectionMatrix(), pSh->GetName());
			else
				pShader->SetParams(pCam->ViewMatrix(), pCam->ProjectionMatrix(), pSh->GetName(), visibleFaces[i]->lightMapIndex);
		}
		else
		{
			for (int j = 0; j < pSh->GetNumStages(); j++)
			{

				if (!StrCaseCmp(pSh->GetTextureStages()[j].textureName.c_str(), "$lightmap"))
					continue;
				
				m_pD3D->TurnOnBlending((D3D11_BLEND)pSh->GetTextureStages()[j].srcBlend, (D3D11_BLEND)pSh->GetTextureStages()[j].destBlend);
				
				if (pSh->GetTextureStages()[j].animated)
				{
					if (visibleFaces[i]->lightMapIndex < 0)
						pShader->SetParams(pCam->ViewMatrix(), pCam->ProjectionMatrix(), pSh->GetTextureStages()[j].animTexturesNames[0]);
					else
						pShader->SetParams(pCam->ViewMatrix(), pCam->ProjectionMatrix(), pSh->GetTextureStages()[j].animTexturesNames[0], visibleFaces[i]->lightMapIndex);

				}
				else
				{
					if (visibleFaces[i]->lightMapIndex < 0)
						pShader->SetParams(pCam->ViewMatrix(), pCam->ProjectionMatrix(), pSh->GetTextureStages()[j].textureName);
					else
						pShader->SetParams(pCam->ViewMatrix(), pCam->ProjectionMatrix(), pSh->GetTextureStages()[j].textureName, visibleFaces[i]->lightMapIndex);
	
				}

			}
		}

		pShader->BindVertexShader();
		pShader->BindPixelShader();

		ID3D11SamplerState* pSampleState = GetTextureManager()->GetSamplerState();
		m_pD3D->GetDeviceContext()->PSSetSamplers(0, 1, &pSampleState);

		m_pD3D->GetDeviceContext()->Draw(visibleFaces[i]->numVertices, 0);

		m_pD3D->TurnOffBlending();
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
