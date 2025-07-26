#pragma once

#include <memory>
#include <string>
#include "Q3BSPStructs.h"



namespace Helios
{
	
		class BSPMap
		{
			uint32_t										m_playerEntityIndex, m_entStringLength,
				m_numModels, m_numLeafBrushes, m_numBrushSides,
				m_numBrushes, m_numEntities, m_numTextures,
				m_numPlanes, m_numNodes, m_numEffects, m_numFaces,
				m_numVertices, m_numMeshVertices,
				m_numLightMaps, m_numLeaves, m_numLeafFaces, m_visDataSize;
			std::unique_ptr<Q3MapTexture[]>					m_q3Textures;
			Q3MapEntities									m_q3Entities;
			std::unique_ptr<Q3MapVertex[]>					m_q3Vertices;
			std::unique_ptr<Q3MapEffect[]>					m_q3MapEffects;
			std::unique_ptr<Q3MapLeafBrush[]>				m_q3MapLeafBrushes;
			std::unique_ptr<Q3MapBrush[]>					m_q3MapBrushes;
			std::unique_ptr<Q3MapBrushSide[]>				m_q3MapBrushSides;
			std::unique_ptr<Q3MapModel[]>					m_q3MapModels;
			std::unique_ptr<Q3MapFace[]>					m_q3Faces;
			std::unique_ptr<Q3MapMeshVert[]>				m_q3MeshVertices;
			std::unique_ptr<Q3MapPlane[]>					m_q3Planes;
			std::unique_ptr<Q3MapNode[]>					m_q3Nodes;
			std::unique_ptr<Q3MapLeaf[]>					m_q3Leaves;
			std::unique_ptr<Q3MapLeafFace[]>				m_q3LeafFaces;
			std::unique_ptr<Q3MapLightMap[]>				m_q3LightMaps;
			Q3MapVisData								m_q3VisData;

		public:
			BSPMap() = default;
			~BSPMap() {}

			inline void Swizzle(float& x, float& y, float& z)
			{
				float temp = y;
				y = z;
				z = temp;
			}

			inline void Swizzle(int& x, int& y, int& z)
			{
				int temp = y;
				y = z;
				z = temp;
			}

			bool Load(std::string& fileName);

			bool ReadHeader(std::ifstream& is, Q3MapHeader& head);
			void ReadEntities(std::ifstream& is, int32_t offset, uint32_t length);
			void ReadTextures(std::ifstream& is, int32_t offset, uint32_t length);
			void ReadPlanes(std::ifstream& is, int32_t offset, uint32_t length);
			void ReadNodes(std::ifstream& is, int32_t offset, uint32_t length);
			void ReadLeaves(std::ifstream& is, int32_t offset, uint32_t length);
			void ReadLeafFaces(std::ifstream& is, int32_t offset, uint32_t length);
			void ReadLeafBrushes(std::ifstream& is, int32_t offset, uint32_t length);
			void ReadModels(std::ifstream& is, int32_t offset, uint32_t length);
			void ReadBrushes(std::ifstream& is, int32_t offset, uint32_t length);
			void ReadBrushSides(std::ifstream& is, int32_t offset, uint32_t length);
			void ReadVertices(std::ifstream& is, int32_t offset, uint32_t length);
			void ReadMeshVertices(std::ifstream& is, int32_t offset, uint32_t length);
			void ReadEffects(std::ifstream& is, int32_t offset, uint32_t length);
			void ReadFaces(std::ifstream& is, int32_t offset, uint32_t length);
			void ReadLightMaps(std::ifstream& is, int32_t offset, uint32_t length);
			void ReadVisibilityData(std::ifstream& is, int32_t offset, uint32_t length);
			//int32_t FindLeaf(const Vector3& cameraPos) const;
			bool IsClusterVisible(int visCluster, int testCluster) const;

			//void AddSurfacesToDraw(Camera& cam);
		};
}

