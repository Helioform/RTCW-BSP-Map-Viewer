#include "Scene.h"
#include "Graphics/OBJ_Loader.h"
#include <chrono>

Helios::Scene::Scene(HWND hWnd, uint32_t w, uint32_t h, bool fullscreen)
{

}

bool Helios::Scene::Init(HWND hwnd, uint32_t w, uint32_t h, bool fullscreen)
{
	gfxAPI = std::make_unique<D3D11GraphicsAPI>();

	
	if (!gfxAPI->Init(hwnd, w, h, fullscreen))
	{
		
		return false;
	}

	float cc[4] = { 0.52f,0.8,0.92f,1.0f }; // sky blue
	gfxAPI->SetClearColor(cc);

	BufferDesc desc;
	// create the constant buffer for transform changes
	desc.type = CONSTANT_BUFFER;
	desc.usage = DYNAMIC;
	desc.cpuAccess = WRITE;
	desc.resType = GPU;
	desc.byteWidth = sizeof(LightSpaceMatrixBuffer);
	D3DBuffer* cBuffer = new D3DBuffer();

	if (!gfxAPI->CreateBuffer(cBuffer, desc, 1))
	{
		
		return false;
	}

	constantBuffer.push_back(cBuffer); 
		
	// create constant buffer for light
	BufferDesc lightBufferDesc;
	lightBufferDesc.usage = DYNAMIC;
	lightBufferDesc.byteWidth = sizeof(ShadowMatrixBuffer);
	lightBufferDesc.type = CONSTANT_BUFFER;
	lightBufferDesc.cpuAccess = WRITE;
	D3DBuffer* lBuffer = new D3DBuffer();

	// Create the constant buffer pointer so we can access the vertex shader constant buffer from within this class.
	if(!gfxAPI->CreateBuffer(lBuffer, lightBufferDesc, 1))
	{
		
		return false;
	}

	constantBuffer.push_back(lBuffer);

	std::vector<std::wstring> shaderNames{ L"LightSpaceDepthVS.hlsl", L"ShadowVS.hlsl", L"ShadowPS.hlsl" };

	if (!LoadShader(shaderNames[0], SHADER_TYPE::VERTEX_SHADER) || !LoadShader(shaderNames[1], SHADER_TYPE::VERTEX_SHADER) || !LoadShader(shaderNames[2], SHADER_TYPE::PIXEL_SHADER))
	{	
		
		return false;
	}


	camera = std::make_unique<Camera>(PROJECTION_TYPE::PERSPECTIVE, 90.0f, XMFLOAT3(0.0f,1.0f,0.0f), XMFLOAT3(0.0f,0.0f,1.0f), XMFLOAT3(0.0f,1.0f,-2.0f), 0.1f, 1000.0f, w, h);
	
	SetLightBuffer();
	SetCameraConstantBufferParams();
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

	textures.push_back(new D3DTexture());
	textures[0]->Register(gfxAPI->D3DDevice(), gfxAPI->DeviceContext());
	textures.push_back(new D3DTexture());
	textures[0]->CreateFromJPGFile("ShipTexture.jpg");
	
	textures[1]->Register(gfxAPI->D3DDevice(), gfxAPI->DeviceContext());
	textures[1]->CreateFromJPGFile("TrackTexture.jpg");

	textures.push_back(new D3DTexture());
	textures[2]->Register(gfxAPI->D3DDevice(), gfxAPI->DeviceContext());
	textures[2]->CreateFromJPGFile("GemTexture.jpg");

	LoadMeshes("TestScene.obj");
	//LoadMeshes("Track+Ship+Gems.obj");



	player = new Player();
	/*player->playerMesh = &meshes[0];*/
	player->playerCam = camera.get();
	//player->playerMesh->SetWorldMatrix(XMMatrixIdentity());

	return true;
}

bool Helios::Scene::LoadShader(const std::wstring& shaderName, SHADER_TYPE type)
{
	std::shared_ptr<D3DShader> sh = std::make_shared<D3DShader>();
	bool success = false;
	if (type == SHADER_TYPE::PIXEL_SHADER)
		success = gfxAPI->CreatePixelShader(sh.get(), shaderName, false);
	else if (type == SHADER_TYPE::VERTEX_SHADER)
		success = gfxAPI->CreateVertexShader(sh.get(), shaderName, false);
	
	if (!success)
		return false;
	shaders.emplace(shaderName, sh);
	
	return true;
}

void Helios::Scene::Update(float dt)
{

	//CheckForCollisions(*player);
	
	player->UpdateWorldMatrix();
	gfxAPI->RenderSceneIndexed(this);
	
}

void Helios::Scene::SetCameraConstantBufferParams()
{
	ID3D11DeviceContext* pDeviceContext = gfxAPI->DeviceContext();

	D3DBuffer* pCBuffer = (D3DBuffer*) (constantBuffer[1]);
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	ShadowMatrixBuffer* dataPtr;


	DirectX::XMFLOAT3 e(-2.0f, 0.0f, 1.0f);
	DirectX::XMFLOAT3 f(0.0f, 0.0f, 0.0f);
	DirectX::XMFLOAT3 u(0.0f, 1.0f, 0.0f);
	XMVECTOR EyePos = DirectX::XMLoadFloat3(&e);
	XMVECTOR Up = DirectX::XMLoadFloat3(&u);
	XMVECTOR Focus = DirectX::XMLoadFloat3(&f);

	DirectX::XMMATRIX LV = XMMatrixLookAtLH(EyePos, Focus, Up );
	//camera->GetViewMatrix();
	DirectX::XMMATRIX LP = XMMatrixOrthographicLH(10.0f, 10.0f, 1.0f, 10.0f);//camera->GetProjectionMatrix();

	DirectX::XMMATRIX LVP = DirectX::XMMatrixTranspose( LV * LP);

	DirectX::XMMATRIX WVP = DirectX::XMMatrixTranspose(camera->GetViewMatrix()*camera->GetProjectionMatrix());

	HRESULT result = pDeviceContext->Map(pCBuffer->pD3DBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);

	if (FAILED(result))
		OutputDebugString(L"Cannot set constant buffer\n");

	dataPtr = (ShadowMatrixBuffer*)mappedResource.pData;

	DirectX::XMStoreFloat4x4(&dataPtr->lightVP, LVP);
	DirectX::XMStoreFloat4x4(&dataPtr->WVP, WVP);
	DirectX::XMStoreFloat3(&dataPtr->lightPos, EyePos);

	pDeviceContext->Unmap(pCBuffer->pD3DBuffer, 0);
	pDeviceContext->VSSetConstantBuffers(1, 1, &pCBuffer->pD3DBuffer);
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

void Helios::Scene::SetLightBuffer()
{
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	unsigned int bufferNumber = 0;

	LightSpaceMatrixBuffer* dataPtr;
	D3DBuffer* pCBuffer = (D3DBuffer*)(constantBuffer[0]);

	gfxAPI->DeviceContext()->Map(pCBuffer->pD3DBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);

	// Get a pointer to the data in the constant buffer.
	dataPtr = (LightSpaceMatrixBuffer*)mappedResource.pData;

	DirectX::XMFLOAT3 e(-2.0f, 0.0f, 1.0f);
	DirectX::XMFLOAT3 f(0.0f, 0.0f, 0.0f);
	DirectX::XMFLOAT3 u(0.0f, 1.0f, 0.0f);
	XMVECTOR EyePos = DirectX::XMLoadFloat3(&e);
	XMVECTOR Up = DirectX::XMLoadFloat3(&u);
	XMVECTOR Focus = DirectX::XMLoadFloat3(&f);

	DirectX::XMMATRIX LV = XMMatrixLookAtLH(EyePos, Focus, Up);
	//camera->GetViewMatrix();
	DirectX::XMMATRIX LP = XMMatrixOrthographicLH(10.0f, 10.0f, 1.0f, 10.0f);//camera->GetProjectionMatrix();

	DirectX::XMMATRIX LVP = DirectX::XMMatrixTranspose(LV * LP);

	DirectX::XMStoreFloat4x4(&dataPtr->lightVP, LVP);
	
	// Unlock the constant buffer.
	gfxAPI->DeviceContext()->Unmap(pCBuffer->pD3DBuffer, 0);

	bufferNumber = 0;

	gfxAPI->DeviceContext()->VSSetConstantBuffers(bufferNumber, 1, &pCBuffer->pD3DBuffer);
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
