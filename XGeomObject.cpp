
#include <string>

#include "XGeomObject.h"


XGeomObject::XGeomObject()
{
	m_pLayout = nullptr;
	D3DXMatrixIdentity(&m_world);
}

XGeomObject::~XGeomObject()
{
	
}


bool XGeomObject::LoadShaders(void)
{
	return true;
}



bool XGeomObject::CreateFaceData(TexVertex* pVertices, unsigned long* pIndices, unsigned int numVertices, unsigned int numIndices, ID3D11ShaderResourceView** pTextures)
{
	m_Faces.reserve(numIndices / 3);
	TexVertex* _pVertices = new TexVertex[3];
	
	int j = 0;

	for (int i = 0; i < numIndices; i+=3)
	{
		FaceData* pNewFace = new FaceData();
		pNewFace->pTexture = pTextures[j++];
		
		_pVertices[0] = pVertices[pIndices[i]];
		_pVertices[1] = pVertices[pIndices[i+1]];
		_pVertices[2] = pVertices[pIndices[i+2]];

		if (!CreateVertexBuffer(&pNewFace->pTexVBuffer, _pVertices, 3))
			return false;	
		m_Faces.push_back(pNewFace);
	}
	
	delete [] _pVertices;

	return true;
}

bool XGeomObject::CreateInputLayout()
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
	// = m_pD3D->CreateInputLayout(polygonLayout, numElements, m_pVertexShaderBuffer->GetBufferPointer(),
	//	m_pVertexShaderBuffer->GetBufferSize(), &m_pLayout);

	//m_pVertexShaderBuffer->Release();
	//m_pPixelShaderBuffer->Release();

	//if (FAILED(hr))
	//	return false;

	return true;
}

bool XGeomObject::CreateVertexBuffer(ID3D11Buffer** pVB, TexVertex* pVertices, unsigned int numVertices)
{
	HRESULT hr; D3D11_BUFFER_DESC vertexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData;

	// Set up the description of the static vertex buffer.
	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vertexBufferDesc.ByteWidth = sizeof(pVertices[0]) * numVertices;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = 0;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	// Give the subresource structure a pointer to the vertex data.
	vertexData.pSysMem = pVertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	// Now create the vertex buffer.
	hr = m_pD3D->GetD3DDevice()->CreateBuffer(&vertexBufferDesc, &vertexData, pVB);
	
	if (FAILED(hr))
		return false;

	return true;
}

bool XGeomObject::CreateIndexBuffer(ID3D11Buffer** pIB, unsigned long* pIndices, unsigned int numIndices)
{
	HRESULT hr;
	D3D11_BUFFER_DESC indexBufferDesc;
	D3D11_SUBRESOURCE_DATA indexData;

	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDesc.ByteWidth = sizeof(unsigned long) * numIndices;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	// Give the subresource structure a pointer to the index data.
	indexData.pSysMem = pIndices;
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	// Create the index buffer.
	hr = m_pD3D->GetD3DDevice()->CreateBuffer(&indexBufferDesc, &indexData, pIB);
	
	if (FAILED(hr))
		return false;

	return true;
}

bool XGeomObject::CreateTest(void)
{	
	HRESULT hr;
	unsigned int numVertices = 3;
	unsigned int numIndices = 3;
	unsigned long* pIndices = new unsigned long[numIndices];
	TexVertex* pVertices = new TexVertex[numVertices];

	// define raw vertex data
	pVertices[0].pos = D3DXVECTOR3(-1.0f, 1.0f, 5.0f);
	pVertices[1].pos = D3DXVECTOR3(1.0f, 1.0f, 5.0f);
	pVertices[2].pos = D3DXVECTOR3(0.0f, -1.0f, 5.0f);
	pVertices[0].tex0 = D3DXVECTOR2(0.0f, 0.0f);
	pVertices[1].tex0 = D3DXVECTOR2(0.5f, 0.0f);
	pVertices[2].tex0 = D3DXVECTOR2(1.0f, 1.0f);
	pVertices[0].normal= D3DXVECTOR3(0.0f, 0.0f, -1.0f);
	pVertices[1].normal = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
	pVertices[2].normal = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
	
	// tri indices
	pIndices[0] = 0;
	pIndices[1] = 1;
	pIndices[2] = 2;


	delete[] pVertices;
	delete[] pIndices;

	return true;
}

bool XGeomObject::BuildCube(float c, const D3DXVECTOR3& center)
{

	return true;
}

bool XGeomObject::BuildSphere(float radius, const D3DXVECTOR3& center, int u, int v)
{
	
	return true;
}

bool XGeomObject::LoadModel(const std::string& fileName)
{
	std::ifstream objFile;
	std::ofstream test;
	objFile.open(fileName);
	unsigned long numObjVerts = 0;
	unsigned long numObjFaces = 0;

	std::string first;
	unsigned int numVertices;
	TexVertex* pVertices;
	unsigned int numIndices;
	unsigned long* pIndices;


	struct xy
	{
		float x, y;
		xy(float fx, float fy)
		{
			x = fx;
			y = fy;
		}
	};

	struct xyz
	{
		float x, y, z;
		xyz(float fx, float fy, float fz)
		{
			x = fx;
			y = fy;
			z = fz;
		}
	};

	struct face
	{
		int a, b, c, d, vna, vnb, vnc, vnd, tx1, tx2, tx3, tx4;
		int numind;

		face(int i1, int i2, int i3, int i4, int vn1, int vn2, int vn3, int vn4, int t1, int t2, int t3, int t4, int num)
		{
			a = i1;
			b = i2;
			c = i3;
			d = i4;
			vna = vn1;
			vnb = vn2;
			vnc = vn3;
			vnd = vn4;
			tx1 = t1;
			tx2 = t2;
			tx3 = t3;
			tx4 = t4;
			numind = num;
		}
	};

	std::vector<xyz> verts;
	std::vector<xyz> normals;
	std::vector<face> faces;
	std::vector<xy> texverts;

	if (objFile.is_open())
	{
		for (std::string line; getline(objFile, line); )   //read stream line by line
		{
			std::istringstream in(line);

			std::string type;
			in >> type;

			if (type == "v")
			{
				float x, y, z;
				in >> x >> y >> z;
				verts.push_back(xyz(x, y, z));
			}
			else if (type == "vn")
			{
				float x, y, z;
				in >> x >> y >> z;
				normals.push_back(xyz(x, y, z));
			}
			else if (type == "vt")
			{
				float x, y;
				in >> x >> y;
				texverts.push_back(xy(x, y));
			}
			else if (type == "f")
			{
				std::string f1, f2, f3, f4;
				std::string a, b, c, d;
				std::string nv1, nv2, nv3, nv4;
				std::string tx1, tx2, tx3, tx4;
				int p1, p2, p3, p4;
				int n1, n2, n3, n4;
				int tex1, tex2, tex3, tex4;

				// read in first face index + separator
				in >> f1 >> f2 >> f3 >> f4;
				// read in first face index
				char c1 = f1[0];
				int i = 0;

				// check if we have // or / to see what kind of face data
				while (c1 != '/')
				{
					a += c1;
					c1 = f1[++i];
				}

				// now read in normals if there are any
				i++;
				c1 = f1[i];
				// if next char is / there are only vertx normals
				if (c1 == '/')
				{
					// parse normal index
					while (c1 != '\0')
					{
						i++;
						c1 = f1[i];
						nv1 += c1;
					}
				}
				else // vertx/texture/normal format
				{
					// parse texture index
					while (c1 != '/')
					{
						tx1 += c1;
						i++;
						c1 = f1[i];
					}

					// now read in normals index
					while (c1 != '\0')
					{
						i++;
						c1 = f1[i];
						nv1 += c1;
					}
				}

				// next face
				c1 = f2[0];
				i = 0;

				// check if we have // or / to see what kind of face data
				while (c1 != '/')
				{
					b += c1;
					c1 = f2[++i];
				}

				i++;
				c1 = f2[i];
				// next char is / so there are only vertx normals
				if (c1 == '/')
				{
					// parse normal index
					while (c1 != '\0')
					{
						i++;
						c1 = f2[i];
						nv2 += c1;
					}
				}
				else // vertx/texture/normal format
				{
					// parse texture index
					while (c1 != '/')
					{
						tx2 += c1;
						i++;
						c1 = f2[i];
					}

					// now read in normals index
					while (c1 != '\0')
					{
						i++;
						c1 = f2[i];
						nv2 += c1;
					}
				}


				c1 = f3[0];
				i = 0;
				// third face
				while (c1 != '/')
				{
					c += c1;
					c1 = f3[++i];
				}

				i++;
				c1 = f3[i];
				// next char is / so there are only vertx normals
				if (c1 == '/')
				{
					// parse normal index
					while (c1 != '\0')
					{
						i++;
						c1 = f3[i];
						nv3 += c1;
					}
				}
				else // vertx/texture/normal format
				{
					// parse texture index
					while (c1 != '/')
					{
						tx3 += c1;
						i++;
						c1 = f3[i];
					}

					// now read in normals index
					while (c1 != '\0')
					{
						i++;
						c1 = f3[i];
						nv3 += c1;
					}
				}

				c1 = f4[0];
				i = 0;
				// check if we have a 4 sided face
				if (f4 != "")
				{
					while (c1 != '/')
					{
						d += c1;
						c1 = f4[++i];
					}

					i++;
					c1 = f4[i];

					if (c1 == '/')
					{
						// parse normal index
						while (c1 != '\0')
						{
							i++;
							c1 = f4[i];
							nv4 += c1;
						}
					}
					else // vertx/texture/normal format
					{
						// parse texture index
						while (c1 != '/')
						{
							tx4 += c1;
							i++;
							c1 = f4[i];
						}

						// now read in normals index
						while (c1 != '\0')
						{
							i++;
							c1 = f4[i];
							nv4 += c1;
						}
					}
				}

				// convert strings to int
				if (f4 == "")
				{
					p1 = stoi(a);
					p2 = stoi(b);
					p3 = stoi(c);
					n1 = stoi(nv1);
					n2 = stoi(nv2);
					n3 = stoi(nv3);

					if (tx1 != "")
						tex1 = stoi(tx1);
					else
						tex1 = 1;
					if (tx2 != "")
						tex2 = stoi(tx2);
					else
						tex2 = 1;
					if (tx3 != "")
						tex3 = stoi(tx3);
					else
						tex3 = 1;

					faces.push_back(face(p1, p2, p3, 0, n1, n2, n3, 0, tex1, tex2, tex3, 0, 3));
				}
				else
				{
					p1 = stoi(a);
					p2 = stoi(b);
					p3 = stoi(c);
					p4 = stoi(d);
					n1 = stoi(nv1);
					n2 = stoi(nv2);
					n3 = stoi(nv3);
					n4 = stoi(nv4);

					if (tx1 != "")
						tex1 = stoi(tx1);
					else
						tex1 = 1;
					if (tx2 != "")
						tex2 = stoi(tx2);
					else
						tex2 = 1;
					if (tx3 != "")
						tex3 = stoi(tx3);
					else
						tex3 = 1;
					if (tx4 != "")
						tex4 = stoi(tx4);
					else
						tex4 = 1;

					faces.push_back(face(p1, p2, p3, p4, n1, n2, n3, n4, tex1, tex2, tex3, tex4, 4));

				}
			}
		}

		objFile.close();
	}
	else
		return false;

	// create vertices for the case of triangles
	if (faces[0].numind == 3)
	{
		numVertices = verts.size();
		pVertices = new TexVertex[numVertices];
		numIndices = 3 * faces.size();
		pIndices = new unsigned long[numIndices];

		// copy vertices 
		for (int i = 0; i < verts.size(); i++)
		{
			pVertices[i].pos.x = verts[i].x;
			pVertices[i].pos.y = verts[i].y;
			pVertices[i].pos.z = verts[i].z;
		}

		// copy vertex normals and textures
		for (int i = 0; i < faces.size(); i++)
		{
			pVertices[faces[i].a - 1].normal.x = normals[faces[i].vna - 1].x;
			pVertices[faces[i].a - 1].normal.y = normals[faces[i].vna - 1].y;
			pVertices[faces[i].a - 1].normal.z = normals[faces[i].vna - 1].z;

			pVertices[faces[i].b - 1].normal.x = normals[faces[i].vnb - 1].x;
			pVertices[faces[i].b - 1].normal.y = normals[faces[i].vnb - 1].y;
			pVertices[faces[i].b - 1].normal.z = normals[faces[i].vnb - 1].z;

			pVertices[faces[i].c - 1].normal.x = normals[faces[i].vnc - 1].x;
			pVertices[faces[i].c - 1].normal.y = normals[faces[i].vnc - 1].y;
			pVertices[faces[i].c - 1].normal.z = normals[faces[i].vnc - 1].z;

			pVertices[faces[i].a - 1].tex0.x = texverts[faces[i].tx1 - 1].x;
			pVertices[faces[i].a - 1].tex0.y = texverts[faces[i].tx1 - 1].y;

			pVertices[faces[i].b - 1].tex0.x = texverts[faces[i].tx2 - 1].x;
			pVertices[faces[i].b - 1].tex0.y = texverts[faces[i].tx2 - 1].y;

			pVertices[faces[i].c - 1].tex0.x = texverts[faces[i].tx3 - 1].x;
			pVertices[faces[i].c - 1].tex0.y = texverts[faces[i].tx3 - 1].y;
		}
		// copy vertex indices
		int j = 0;

		for (int i = 0; i < faces.size(); i++)
		{
			pIndices[j++] = faces[i].a - 1;
			pIndices[j++] = faces[i].b - 1;
			pIndices[j++] = faces[i].c - 1;
		}
	}
	// otherwise we have quads to triangulate
	else if (faces[0].numind == 4)
	{
		numVertices = verts.size();
		pVertices = new TexVertex[numVertices];
		numIndices = 3 * faces.size();
		pIndices = new unsigned long[numIndices];

	}

	if(!CreateFaceData(pVertices, pIndices, numVertices, numIndices, nullptr))
		return false;

	delete[] pVertices;
	delete[] pIndices;
	return true;
}