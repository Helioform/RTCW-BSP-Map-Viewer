#include "Mesh.h"
#include <fstream>

Helios::Mesh::Mesh(std::string& fileName) : numVertices{ 0 }
{

	world = DirectX::XMMatrixIdentity();
}

void Helios::Mesh::CreateQuad(const DirectX::XMFLOAT3& v1, const DirectX::XMFLOAT3& v2, const DirectX::XMFLOAT3& v3, const DirectX::XMFLOAT3& v4, const DirectX::XMFLOAT4& color)
{
	Vertex p1, p2, p3, p4;
	p1.Pos = v1;
	p1.Color = color;
	p2.Pos = v2;
	p2.Color = color;
	p3.Pos = v3;
	p3.Color = color;
	p4.Pos = v4;
	p4.Color = color;

	vertices.push_back(p1);
	vertices.push_back(p2);
	vertices.push_back(p3);
	vertices.push_back(p4);

	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);
	indices.push_back(0);
	indices.push_back(2);
	indices.push_back(3);

	numVertices = 4;
	numIndices = 6;
}

void Helios::Mesh::CalculateAABB()
{
	DirectX::XMFLOAT3 min, max;
	
	min.x = 999999999.0f;
	min.y = 999999999.0f,
	min.z = 999999999.0f;
	max.x = -999999999.0f;
	max.y = -999999999.0f;
	max.z = -999999999.0f;

	for (auto& i : vertices)
	{
		if (i.Pos.x < min.x) min.x = i.Pos.x;
		if (i.Pos.y < min.y) min.y = i.Pos.y;
		if (i.Pos.z < min.z) min.z = i.Pos.z;

		if (i.Pos.x > max.x) max.x = i.Pos.x;
		if (i.Pos.y > max.y) max.y = i.Pos.y;
		if (i.Pos.z > max.z) max.z = i.Pos.z;
	
	}

	boundingBox.center.x = (max.x + min.x) / 2.0f;
	boundingBox.center.y = (max.y + min.y) / 2.0f;
	boundingBox.center.z = (max.z + min.z) / 2.0f;

	boundingBox.extend.x = max.x - boundingBox.center.x;
	boundingBox.extend.y = max.y - boundingBox.center.y;
	boundingBox.extend.z = max.z - boundingBox.center.z;

}


