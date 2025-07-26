#pragma once
#include "Graphics/CommonHeaders.h"
#include "Graphics/Primitives.h"
#include "Math/Inc/DirectXMath.h"
#include "../Library/Graphics/D3DTexture.h"


namespace Helios
{
	class Mesh
	{
	public:

		Mesh() { world = DirectX::XMMatrixIdentity(); }
		Mesh(std::string& fileName);
		void CreateQuad(const DirectX::XMFLOAT3& v1, const DirectX::XMFLOAT3& v2, const DirectX::XMFLOAT3& v3, const DirectX::XMFLOAT3& v4, const DirectX::XMFLOAT4& color);
		void CalculateAABB();
		
		inline void ReserveVertexSpace(uint32_t numVertices)
		{
			vertices.reserve(numVertices);
		}

		inline void ReserveIndexSpace(uint32_t numIndices)
		{
			indices.reserve(numIndices);
		}

		inline std::vector<Vertex>& GetVertices() {
			return vertices;
		}

		inline std::vector<uint32_t>& GetIndices() {
			return indices;
		}

		inline void SetVertex(const Vertex& v, uint32_t index)  
		{
			vertices[index] = v;
		}

		inline void SetIndex(uint32_t i, uint32_t index)
		{
			indices[index] = i;
		}

		inline uint32_t GetNumIndices() {
			return numIndices;
		}

		inline uint32_t GetNumVertices() const {
			return numVertices;
		}

		inline void SetNumVertices(uint32_t n) {
			numVertices = n;
		}

		inline uint32_t GetVertexBufferID() {
			return vertexBufferID;
		}

		inline uint32_t GetShaderID() {
			return shaderIndex;
		}
		
		inline void SetVertexBufferID(uint32_t i)
		{
			vertexBufferID = i;
		}

		inline void SetShaderID(uint32_t i)
		{
			shaderIndex = i;
		}

		inline void SetNumberIndices(uint32_t i)
		{
			numIndices = i;
		}
		
		std::vector<D3DTexture*>& GetTextures() {
			return textures;
		}

		AABB GetBoundingBox() const
		{
			return boundingBox;
		}

		inline DirectX::XMMATRIX GetWorld() 
		{
			return world;
		}

		inline void SetWorldMatrix(DirectX::XMMATRIX m)
		{
			world = m;
		}

		inline void SetTAG(const std::string& tag)
		{
			TAG = tag;

		}

		inline std::string GetTAG() const {
			return TAG;
		}

		inline void SetDestroyed(bool v)
		{
			isDestroyed = v;
		}

		inline bool GetIsDestroyed() {
			return isDestroyed;
		}

		inline uint32_t GetTextureID()
		{
			return textureID;
		}

		inline void SetTextureID(uint32_t id)
		{
			textureID = id;
		}
	private:
		std::vector<D3DTexture*> textures;
		uint32_t textureID;	
		uint32_t numVertices;
		std::vector<Vertex> vertices;
		std::vector<uint32_t> indices;
		uint64_t				shaderIndex;
		uint64_t				vertexBufferID;
		uint64_t				numIndices;
		AABB					boundingBox;
		std::string				TAG;
		DirectX::XMMATRIX				world;
		bool					isDestroyed=false;
	};

}