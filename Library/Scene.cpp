#include "Scene.h"
#include "Graphics/OBJ_Loader.h"
#include <chrono>
#include "./Graphics/D3DBuffer.h"

Helios::Scene::Scene(HWND hWnd, uint32_t w, uint32_t h, bool fullscreen)
{
	gfxAPI = std::make_unique<Renderer>(new D3D11GraphicsAPI());

	gfxAPI->Initialize(hWnd, w, h, fullscreen);
	float cc[4] = { 0.52f,0.8,0.92f,1.0f }; // sky blue
	gfxAPI->SetClearColor(cc);

	BufferDesc desc;
	// create the constant buffer for transform changes
	desc.type = CONSTANT_BUFFER;
	desc.usage = DYNAMIC;
	desc.cpuAccess = WRITE;
	desc.resType = GPU;
	desc.byteWidth = sizeof(LightSpaceMatrixBuffer); // for lightspace shading
	D3DBuffer* cBuffer = new D3DBuffer();

	gfxAPI->CreateBuffer(cBuffer, desc, 1);
	constantBuffer.push_back(cBuffer); 
		
	// create constant buffer for light
	BufferDesc lightBufferDesc;
	lightBufferDesc.usage = DYNAMIC;
	lightBufferDesc.byteWidth = sizeof(LightBuffer);
	lightBufferDesc.type = CONSTANT_BUFFER;
	lightBufferDesc.cpuAccess = WRITE;
	D3DBuffer* lBuffer = new D3DBuffer();

	// Create the constant buffer pointer so we can access the vertex shader constant buffer from within this class.
	gfxAPI->CreateBuffer(lBuffer, lightBufferDesc, 1);
	constantBuffer.push_back(lBuffer);
	gfxAPI->SetDirectionalLightBuffer(constantBuffer[1], XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(0.5f, 0.5f, 0.5f, 1.0f));

	std::vector<std::wstring> shaderNames{ L"ColorVS.hlsl", L"ColorPS.hlsl" };
	//std::vector<std::wstring> pixelShaderNames{ L"DepthShaderVS.hlsl", L"DepthShaderPS.hlsl" };


	LoadShaders(shaderNames);
	
	camera = std::make_unique<Camera>(PROJECTION_TYPE::PERSPECTIVE, 90.0f, XMFLOAT3(0.0f,1.0f,0.0f), XMFLOAT3(0.0f,0.0f,1.0f), XMFLOAT3(0.0f,1.0f,-2.0f), 0.1f, 1000.0f, w, h);
	

	

	

	
	//Mesh m;
	//m.CreateQuad(DirectX::XMFLOAT3(-2.0, 2.0f, 4.0f), DirectX::XMFLOAT3(2.0, 2.0f, 4.0f), DirectX::XMFLOAT3(2.0, -2.0f, 4.0f), DirectX::XMFLOAT3(-2.0, -2.0f, 4.0f), DirectX::XMFLOAT4(1.0f,1.0f,1.0f,1.0f));
	//meshes.push_back(m);
	//BufferDesc vbdesc;
	//vbdesc.type = VERTEX_BUFFER;
	//vbdesc.cpuAccess = WRITE;
	//vbdesc.usage = DYNAMIC;

	//BufferDesc ibdesc;
	//ibdesc.type = INDEX_BUFFER;
	//ibdesc.cpuAccess = NONE;
	//ibdesc.usage = DEFAULT;
	//vbdesc.byteWidth = sizeof(Vertex) * m.GetNumVertices();
	//ibdesc.byteWidth = sizeof(uint32_t) * m.GetNumIndices();

	//D3DBuffer* d3dvb = new D3DBuffer;

	//// create DIrect3D vertex buffer
	//gfxAPI->CreateBuffer(d3dvb, vbdesc, m.GetNumVertices(), m.GetVertices());
	//buffers.push_back(d3dvb);

	//// create d3d index buffer
	//D3DBuffer* d3dib = new D3DBuffer();
	//gfxAPI->CreateBuffer(d3dib, ibdesc, m.GetNumIndices(), {}, m.GetIndices());
	//indexBuffers.push_back(d3dib);
	D3DTexture* tex1 = new D3DTexture();
	gfxAPI->CreateTexture(tex1, "ShipTexture.jpg");
	textures.push_back(tex1);

	D3DTexture* tex2 = new D3DTexture();
	gfxAPI->CreateTexture(tex2, "TrackTexture.jpg");
	textures.push_back(tex2);
	
	D3DTexture* tex3 = new D3DTexture();
	gfxAPI->CreateTexture(tex3, "GemTexture.jpg");
	textures.push_back(tex3);
	

	LoadMeshes("RacingShip.obj");
	LoadMeshes("Track+Ship+Gems.obj");


	player = new Player();
	player->playerMesh = &meshes[0];
	player->playerCam = camera.get();
	player->playerMesh->SetWorldMatrix(XMMatrixIdentity());

}

void Helios::Scene::Init(HWND hwnd, uint32_t w, uint32_t h, bool fullscreen)
{
	gfxAPI->Initialize(hwnd, w, h, fullscreen);
	
	

}

void Helios::Scene::LoadShaders(const std::vector<std::wstring>& shaderNames)
{
	for (auto it = shaderNames.begin(); it != shaderNames.end(); ++++it) {
	
		D3DShader sh((D3D11GraphicsAPI*)gfxAPI->GetAPI());
		sh.Compile(it->c_str(), std::next(it)->c_str());
		shaders.push_back(sh);
	}
}


void Helios::Scene::Update(float dt)
{

	CheckForCollisions(*player);
	player->UpdatePosition();
	player->UpdateWorldMatrix();
	gfxAPI->RenderSceneIndexed(this);
}


bool Helios::Scene::LoadMeshes(const std::string& filename)
{
	std::wstring path = GetEXEPath() + L"/";
	std::string str = std::string(path.begin(), path.end());
	objl::Loader l;
	bool success = l.LoadFile(str + filename);

	if (success)
	{	
		BufferDesc vbdesc;
		vbdesc.type = VERTEX_BUFFER;
		vbdesc.cpuAccess = WRITE;
		vbdesc.usage = DYNAMIC;

		BufferDesc ibdesc;
		ibdesc.type = INDEX_BUFFER;
		ibdesc.cpuAccess = WRITE;
		ibdesc.usage = DYNAMIC;

		uint32_t meshIndex = 0;

		// go through each mesh in the obj file
		for (auto& objMesh : l.LoadedMeshes)
		{
			uint32_t nv = objMesh.Vertices.size();
			uint32_t ni = objMesh.Indices.size();

			vbdesc.byteWidth = sizeof(Vertex) * nv;
			ibdesc.byteWidth = sizeof(uint32_t) * ni;
						
			Mesh m;
			m.ReserveVertexSpace(objMesh.Vertices.size());
			m.ReserveIndexSpace(objMesh.Indices.size());
			
			// copy vertices
			for (auto& v : objMesh.Vertices)
			{
				Vertex v1;
				v1.Pos.x = v.Position.X; 
				v1.Pos.y = v.Position.Y;// swap z and y because blender has z up and y front
				v1.Pos.z = v.Position.Z;
				v1.Normal.x = v.Normal.X;
				v1.Normal.y = v.Normal.Y;
				v1.Normal.z = v.Normal.Z;
				v1.TexCoords.x =  v.TextureCoordinate.X;
				v1.TexCoords.y = v.TextureCoordinate.Y; 


				if (objMesh.MeshName.find("Ship") != std::string::npos)
				{
					v1.Color = DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
					m.SetTAG("Ship");
					
					m.GetTextures().push_back(textures[0]);
					m.SetTextureID(0);
				}
				else if (objMesh.MeshName.find("Diamond") != std::string::npos)
				{
					v1.Color = DirectX::XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);
					m.SetTAG("Diamond");
					m.GetTextures().push_back(textures[2]);
				}
				else if (objMesh.MeshName.find("Track") != std::string::npos)
				{
					v1.Color = DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
					m.SetTAG("Track");
					m.SetTextureID(1);
					m.GetTextures().push_back(textures[1]);
				}
				else
				{
					v1.Color = DirectX::XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f);
					m.SetTAG("Unknown");
					m.GetTextures().push_back(textures[1]);
				}

				m.GetVertices().push_back(v1);
			}

			// copy indices
			for (auto& i : objMesh.Indices)
			{
				m.GetIndices().push_back(i);
			}

			D3DBuffer* d3dvb = new D3DBuffer;

			// create DIrect3D vertex buffer
			gfxAPI->CreateBuffer(d3dvb, vbdesc, nv, m.GetVertices());
			buffers.push_back(d3dvb);

			// create d3d index buffer
			D3DBuffer* d3dib = new D3DBuffer();
			gfxAPI->CreateBuffer(d3dib, ibdesc, ni, {}, m.GetIndices());
			indexBuffers.push_back(d3dib);

			m.SetShaderID(0);
			m.SetVertexBufferID(meshes.size());
			m.SetNumVertices(nv);
			m.SetNumberIndices(ni);
			m.CalculateAABB();
			meshIndex++;
			meshes.push_back(m);			
		}
	}
	else
		return false;
}


void Helios::Scene::RotatePlayer(float dt)
{
	player->Yaw(dt);
}

void Helios::Scene::CheckForCollisions(const Player& player)
{
	for (auto& obj : meshes)
	{		
		if ((obj.GetTAG() != "Track") && (obj.GetTAG() != "Ship")&& (!obj.GetIsDestroyed()))
		{
			if ((player.GetPosition3f().x >= obj.GetBoundingBox().center.x - 1.0f )&&
				(player.GetPosition3f().x <= obj.GetBoundingBox().center.x + 1.0f)&&
				(player.GetPosition3f().z <= obj.GetBoundingBox().center.z + 1.0f)&&
				(player.GetPosition3f().z >= obj.GetBoundingBox().center.z - 1.0f))
			{
				uint32_t meshID = obj.GetVertexBufferID();

				obj.SetDestroyed(true);
				
			}
		}
	}

}
