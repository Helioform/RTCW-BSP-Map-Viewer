#include "BSPMap.h"
#include <fstream>

namespace Helios
{
	
		bool BSPMap::Load(std::string& fileName)
		{
			std::ifstream mapFile;

			mapFile.open(fileName.c_str(), std::ios::binary);

			if (!mapFile.is_open())
				return false;
			else
			{
				Q3MapHeader head;
				if (!ReadHeader(mapFile, head))
				{
					mapFile.close();
					return false;
				}

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
			return true;
		}
		bool BSPMap::ReadHeader(std::ifstream& is, Q3MapHeader& head)
		{
			is.read((char*)(&head), sizeof(head));

			if (head.magic[0] != 'I'
				|| head.magic[1] != 'B'
				|| head.magic[2] != 'S'
				|| head.magic[3] != 'P')
				return false;

			return true;
		}

		void BSPMap::ReadEntities(std::ifstream& is, int32_t offset, uint32_t length)
		{
			is.seekg(offset, is.beg);
			m_entStringLength = length;
			m_q3Entities.ents = new char[length];
			is.read((m_q3Entities.ents), m_entStringLength);
		}
		void BSPMap::ReadTextures(std::ifstream& is, int32_t offset, uint32_t length)
		{
			is.seekg(offset, is.beg);
			m_numTextures = length / sizeof(Q3MapTexture);
			Q3MapTexture texture;
			m_q3Textures = std::make_unique<Q3MapTexture[]>(m_numTextures);

			for (uint32_t i = 0; i < m_numTextures; ++i)
			{
				is.read((char*)(&texture), sizeof(Q3MapTexture));
				m_q3Textures[i] = texture;
			}
		}
		void BSPMap::ReadPlanes(std::ifstream& is, int32_t offset, uint32_t length)
		{
			is.seekg(offset, is.beg);
			m_numPlanes = length / sizeof(Q3MapPlane);
			Q3MapPlane plane;
			m_q3Planes = std::make_unique<Q3MapPlane[]>(m_numPlanes);

			for (uint32_t i = 0; i < m_numPlanes; ++i)
			{
				is.read((char*)(&plane), sizeof(Q3MapPlane));
				Swizzle(plane.normal[0], plane.normal[1], plane.normal[2]);
				m_q3Planes[i] = plane;
			}
		}

		void BSPMap::ReadNodes(std::ifstream& is, int32_t offset, uint32_t length)
		{
			is.seekg(offset, is.beg);
			m_numNodes = length / sizeof(Q3MapNode);
			m_q3Nodes = std::make_unique<Q3MapNode[]>(m_numNodes);
			Q3MapNode node;

			for (uint32_t i = 0; i < m_numNodes; ++i)
			{
				is.read((char*)(&node), sizeof(Q3MapNode));
				Swizzle(node.mins[0], node.mins[1], node.mins[2]);
				Swizzle(node.maxs[0], node.maxs[1], node.maxs[2]);
				m_q3Nodes[i] = node;
			}
		}

		void BSPMap::ReadLeaves(std::ifstream& is, int32_t offset, uint32_t length)
		{
			is.seekg(offset, is.beg);
			m_numLeaves = length / sizeof(Q3MapLeaf);
			m_q3Leaves = std::make_unique<Q3MapLeaf[]>(m_numLeaves);
			Q3MapLeaf leaf;

			for (uint32_t i = 0; i < m_numLeaves; ++i)
			{
				is.read((char*)(&leaf), sizeof(Q3MapLeaf));
				Swizzle(leaf.mins[0], leaf.mins[1], leaf.mins[2]);
				Swizzle(leaf.maxs[0], leaf.maxs[1], leaf.maxs[2]);
				m_q3Leaves[i] = leaf;
			}
		}

		void BSPMap::ReadLeafFaces(std::ifstream& is, int32_t offset, uint32_t length)
		{
			is.seekg(offset, is.beg);
			m_numLeafFaces = length / sizeof(Q3MapLeafFace);
			m_q3LeafFaces = std::make_unique<Q3MapLeafFace[]>(m_numLeafFaces);
			Q3MapLeafFace leafFace;

			for (uint32_t i = 0; i < m_numLeafFaces; ++i)
			{
				is.read((char*)(&leafFace), sizeof(Q3MapLeafFace));
				m_q3LeafFaces[i] = leafFace;
			}
		}
		void BSPMap::ReadLeafBrushes(std::ifstream& is, int32_t offset, uint32_t length)
		{
			is.seekg(offset, is.beg);
			m_numLeafBrushes = length / sizeof(Q3MapLeafBrush);
			m_q3MapLeafBrushes = std::make_unique<Q3MapLeafBrush[]>(m_numLeafBrushes);
			Q3MapLeafBrush leafBrush;

			for (uint32_t i = 0; i < m_numLeafBrushes; ++i)
			{
				is.read((char*)(&leafBrush), sizeof(Q3MapLeafBrush));
				m_q3MapLeafBrushes[i] = leafBrush;
			}
		}

		void BSPMap::ReadModels(std::ifstream& is, int32_t offset, uint32_t length)
		{
			is.seekg(offset, is.beg);
			m_numModels = length / sizeof(Q3MapModel);
			m_q3MapModels = std::make_unique<Q3MapModel[]>(m_numModels);
			Q3MapModel model;

			for (uint32_t i = 0; i < m_numModels; ++i)
			{
				is.read((char*)(&model), sizeof(Q3MapModel));
				m_q3MapModels[i] = model;
			}
		}

		void BSPMap::ReadBrushes(std::ifstream& is, int32_t offset, uint32_t length)
		{
			is.seekg(offset, is.beg);
			m_numBrushes = length / sizeof(Q3MapBrush);
			m_q3MapBrushes = std::make_unique<Q3MapBrush[]>(m_numBrushes);
			Q3MapBrush brush;

			for (uint32_t i = 0; i < m_numBrushes; i++)
			{
				is.read((char*)(&brush), sizeof(Q3MapBrush));
				m_q3MapBrushes[i] = brush;
			}
		}

		void BSPMap::ReadBrushSides(std::ifstream& is, int32_t offset, uint32_t length)
		{
			is.seekg(offset, is.beg);
			m_numBrushSides = length / sizeof(Q3MapBrushSide);
			m_q3MapBrushSides = std::make_unique<Q3MapBrushSide[]>(m_numBrushSides);
			Q3MapBrushSide brushSide;

			for (uint32_t i = 0; i < m_numBrushSides; i++)
			{
				is.read((char*)(&brushSide), sizeof(Q3MapBrushSide));
				m_q3MapBrushSides[i] = brushSide;
			}
		}

		void BSPMap::ReadVertices(std::ifstream& is, int32_t offset, uint32_t length)
		{
			is.seekg(offset, is.beg);
			m_numVertices = length / sizeof(Q3MapVertex);
			m_q3Vertices = std::make_unique<Q3MapVertex[]>(m_numVertices);
			Q3MapVertex vertex;

			for (uint32_t i = 0; i < m_numVertices; ++i)
			{
				is.read((char*)(&vertex), sizeof(Q3MapVertex));
				Swizzle(vertex.pos[0], vertex.pos[1], vertex.pos[2]);
				Swizzle(vertex.normal[0], vertex.normal[1], vertex.normal[2]);
				m_q3Vertices[i] = vertex;
			}
		}

		void BSPMap::ReadMeshVertices(std::ifstream& is, int32_t offset, uint32_t length)
		{
			is.seekg(offset, is.beg);
			m_numMeshVertices = length / sizeof(Q3MapMeshVert);
			m_q3MeshVertices = std::make_unique<Q3MapMeshVert[]>(m_numMeshVertices);
			Q3MapMeshVert meshVert;

			for (uint32_t i = 0; i < m_numMeshVertices; ++i)
			{
				is.read((char*)(&meshVert), sizeof(Q3MapMeshVert));
				m_q3MeshVertices[i] = meshVert;
			}
		}

		void BSPMap::ReadEffects(std::ifstream& is, int32_t offset, uint32_t length)
		{
			is.seekg(offset, is.beg);
			m_numEffects = length / sizeof(Q3MapEffect);
			m_q3MapEffects = std::make_unique<Q3MapEffect[]>(m_numEffects);
			Q3MapEffect effect;

			for (uint32_t i = 0; i < m_numEffects; ++i)
			{
				is.read((char*)&effect, sizeof(Q3MapEffect));
				m_q3MapEffects[i] = effect;
			}

		}
		void BSPMap::ReadFaces(std::ifstream& is, int32_t offset, uint32_t length)
		{
			is.seekg(offset, is.beg);
			m_numFaces = length / sizeof(Q3MapFace);
			m_q3Faces = std::make_unique<Q3MapFace[]>(m_numFaces);
			Q3MapFace face;

			for (uint32_t i = 0; i < m_numFaces; ++i)
			{
				is.read((char*)&face, sizeof(Q3MapFace));
				Swizzle(face.normal[0], face.normal[1], face.normal[2]);
				m_q3Faces[i] = face;
			}
		}


		void BSPMap::ReadLightMaps(std::ifstream& is, int32_t offset, uint32_t length)
		{
			is.seekg(offset, is.beg);
			m_numLightMaps = length / sizeof(Q3MapLightMap);
			m_q3LightMaps = std::make_unique <Q3MapLightMap[]>(m_numLightMaps);
			Q3MapLightMap lightMap;

			for (uint32_t i = 0; i < m_numLightMaps; ++i)
			{
				is.read((char*)(&lightMap), sizeof(Q3MapLightMap));
				m_q3LightMaps[i] = lightMap;
			}
		}

		void BSPMap::ReadVisibilityData(std::ifstream& is, int32_t offset, uint32_t length)
		{
			is.seekg(offset, is.beg);
			is.read((char*)&(m_q3VisData.nvectors), sizeof(int));
			is.read((char*)&(m_q3VisData.sizevecs), sizeof(int));
			m_visDataSize = m_q3VisData.nvectors * m_q3VisData.sizevecs;
			m_q3VisData.vecs = new char[m_visDataSize];
			is.read((char*)(m_q3VisData.vecs), m_visDataSize);
		}

		//int32_t BSPMap::FindLeaf(const Vector3& cameraPos) const
		//{
		//	int32_t index = 0;

		//	while (index >= 0)
		//	{
		//		const Q3MapNode& node = m_q3Nodes[index];
		//		const Q3MapPlane& plane = m_q3Planes[node.plane];
		//		Vector3 planeNormal = Vector3(plane.normal[0], plane.normal[1], plane.normal[2]);
		//		// Distance from point to a plane
		//		const double distance = planeNormal.DotProduct(cameraPos) - plane.dist;

		//		if (distance >= 0)
		//			index = node.children[0];
		//		else
		//			index = node.children[1];
		//	}

		//	return -index - 1;
		//}

		bool BSPMap::IsClusterVisible(int visCluster, int testCluster) const
		{
			if ((m_q3VisData.vecs == nullptr) || (visCluster < 0))
				return true;

			int32_t i = (visCluster * m_q3VisData.sizevecs) + (testCluster >> 3);
			unsigned char visSet = m_q3VisData.vecs[i];

			return (visSet & (1 << (testCluster & 7))) != 0;
		}

		//void BSPMap::AddSurfacesToDraw(Camera& cam)
		//{
		//	// find the cluster the camera is in
		//	const int l = 0;// FindLeaf(cam.Position());
		//	const int camCluster = m_q3Leaves[l].cluster;

		//	// iterate through all leaves and find the ones visible from camera	
		//	for (int i = 0; i < m_numLeaves; ++i)
		//	{
		//		if (!IsClusterVisible(camCluster, m_q3Leaves[i].cluster))
		//			continue;

		//		if (!cam.IsInFrustum(m_q3Leaves[i].mins, m_q3Leaves[i].maxs))
		//			continue;

		//		for (int j = 0; j < m_q3Leaves[i].nleaffaces; ++j)
		//		{
		//			const int f = j + m_q3Leaves[i].leafface;
		//			//	if (m_faceData[m_q3LeafFaces[f].face] == nullptr)
		//			//		continue;

		//			//	TextureIndexedFaceData* pFace = m_faceData[m_q3LeafFaces[f].face];
		//				//	if (IsAlreadyVisible(pFace))
		//				//		continue;

		//			//	m_visibleFaces.push_back(pFace);
		//		}
		//	}
		//}
}