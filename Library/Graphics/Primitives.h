#pragma once

#include "../Math/Inc/DirectXMath.h"

#include <memory>


namespace Helios
{

		struct Vertex
		{
			DirectX::XMFLOAT3 Pos;
			DirectX::XMFLOAT3 Normal;
			DirectX::XMFLOAT2 TexCoords;
			DirectX::XMFLOAT4 Color;
		
			Vertex() = default;
			Vertex(const DirectX::XMFLOAT3& pos, const DirectX::XMFLOAT4& color)
			{
				Pos = pos;
				Color = color;
			}

			Vertex(const DirectX::XMFLOAT3 pos, const DirectX::XMFLOAT3& normal, const DirectX::XMFLOAT2& tex, const DirectX::XMFLOAT4& color)
			{
				Pos = pos;
				Normal = normal;
				TexCoords = tex;
				Color = color;
			}
		};		

		struct AABB
		{
			DirectX::XMFLOAT3 extend;
			DirectX::XMFLOAT3 center;

			inline bool CollidesWith(const AABB& other)
			{
				bool collisionX = center.x + extend.x >= other.center.x &&
					other.center.x + other.extend.x >= center.x;
				// collision y-axis?
				bool collisionY = center.y + extend.y >= other.center.y &&
					other.center.y + other.extend.y >= center.y;
				
				bool collisionZ = center.z + extend.z >= other.center.z &&
					other.center.z + other.extend.z >= center.z;

				// collision only if on 3 axes
				return collisionX && collisionY && collisionZ;
			}
		};


		struct Plane
		{
			
		public:

			Plane() = default;
			Plane(DirectX::XMFLOAT3 center, float_t width, float_t height, DirectX::XMFLOAT4 color);
		
		private:
			DirectX::XMFLOAT3 m_normal;
			DirectX::XMFLOAT3 m_center;
			float m_width, m_height;
		};
}