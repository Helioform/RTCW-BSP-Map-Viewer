#include "stdafx.h"
#include "XSprite.h"


XSprite::XSprite()
{
}


XSprite::~XSprite()
{
}

bool XSprite::CreateInputLayout()
{
	HRESULT hr;
	D3D11_INPUT_ELEMENT_DESC polygonLayout[3];
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

	polygonLayout[2].SemanticName = "COLOR";
	polygonLayout[2].SemanticIndex = 0;
	polygonLayout[2].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	polygonLayout[2].InputSlot = 0;
	polygonLayout[2].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	polygonLayout[2].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	polygonLayout[2].InstanceDataStepRate = 0;

	// Get a count of the elements in the layout.
	numElements = sizeof(polygonLayout) / sizeof(polygonLayout[0]);
	// Create the vertex input layout.
	hr = m_pD3D->CreateInputLayout(polygonLayout, numElements, m_pShader->GetD3DShader(0)->GetVertexShaderBuffer()->GetBufferPointer(),
		m_pShader->GetD3DShader(0)->GetVertexShaderBuffer()->GetBufferSize(), &m_pLayout);

	m_pShader->GetD3DShader(0)->GetVertexShaderBuffer()->Release();
	m_pShader->GetD3DShader(0)->GetPixelShaderBuffer()->Release();

	if (FAILED(hr))
		return false;

	return true;
}

bool XSprite::CreateVertexBuffer()
{
	HRESULT hr; D3D11_BUFFER_DESC vertexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData;

	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vertexBufferDesc.ByteWidth = sizeof(m_vertices[0]) * 4;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = 0;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	vertexData.pSysMem = m_vertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	hr = m_pD3D->CreateBuffer(&vertexBufferDesc, &vertexData, &m_pVertexBuffer);

	if (FAILED(hr))
		return false;

	return true;
}

bool XSprite::CreateIndexBuffer(void)
{
	HRESULT hr;
	D3D11_BUFFER_DESC indexBufferDesc;
	D3D11_SUBRESOURCE_DATA indexData;

	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDesc.ByteWidth = sizeof(unsigned long) * 6;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	// Give the subresource structure a pointer to the index data.
	indexData.pSysMem = m_indices;
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	// Create the index buffer.
	hr = m_pD3D->CreateBuffer(&indexBufferDesc, &indexData, &m_pIndexBuffer);

	if (FAILED(hr))
		return false;

	return true;
}

bool XSprite::Load(const std::string& fileName)
{
	if (!m_pTextureManager)
		return false;

	m_pShader = new XShader(fileName, nullptr, 0, 0, 0);
	LoadD3DShader("Sprite.vs", "Sprite.ps");

	const std::string ext = fileName.substr(fileName.find("."), fileName.length());

	if (ext == "jpg")
	{
		if (!m_pTextureManager->Load(fileName, false))
			return false;
	}
	else if (ext == "tga")
	{
		TGAImage tgaImg;

		if (!tgaImg.Load(fileName))
			return false;

		if (!m_pTextureManager->CreateTexture(tgaImg.GetImageData().data(), tgaImg.GetHeight(), tgaImg.GetWidth(), false))
			return false;
	}

	return true;
}

