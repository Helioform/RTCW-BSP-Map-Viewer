
#include "XShader.h"


XD3DShader::XD3DShader()
{
	m_pD3D = nullptr;
	m_pErrorMessage = nullptr;
	m_pVertexShaderBuffer = nullptr;
	m_pPixelShaderBuffer = nullptr;
	m_pPixelShader = nullptr;
	m_pVertexShader = nullptr;
	m_pLightBuffer = nullptr;
	m_pMatrixBuffer = nullptr;
	D3DXMatrixIdentity(&m_world);
}

XD3DShader::~XD3DShader()
{
	if (m_pPixelShader != nullptr)
		m_pPixelShader->Release();
	if (m_pVertexShader != nullptr)
		m_pVertexShader->Release();
	if (m_pLightBuffer != nullptr)
		m_pLightBuffer->Release();
	if (m_pMatrixBuffer != nullptr)
		m_pMatrixBuffer->Release();
}

bool XD3DShader::LoadAndCompile(const std::string & vertexShaderFileName, const std::string & pixelShaderFileName, const std::string& vsFunctionName, const std::string& psFunctionName)
{
	HRESULT hr;
	std::wstring wideVertexFileName = std::wstring(vertexShaderFileName.begin(), vertexShaderFileName.end());
	std::wstring widePixelFileName = std::wstring(pixelShaderFileName.begin(), pixelShaderFileName.end());

	unsigned int shaderParams = D3D10_SHADER_ENABLE_STRICTNESS;

#if defined(DEBUG) || defined(_DEBUG)
	shaderParams |= D3D10_SHADER_DEBUG;
#endif

#
	hr = D3DX11CompileFromFile(wideVertexFileName.c_str(), NULL, NULL, vsFunctionName.c_str(), "vs_4_0", shaderParams , 0, NULL,
	&m_pVertexShaderBuffer, &m_pErrorMessage, NULL);

	
	if (FAILED(hr))
		return false;

	hr = D3DX11CompileFromFile(widePixelFileName.c_str(), NULL, NULL, psFunctionName.c_str(), "ps_4_0", shaderParams, 0, NULL,
		&m_pPixelShaderBuffer, &m_pErrorMessage, NULL);


	if (FAILED(hr))
		return false;

	// Create the vertex shader from the buffer.
	hr = m_pD3D->GetD3DDevice()->CreateVertexShader(m_pVertexShaderBuffer->GetBufferPointer(), m_pVertexShaderBuffer->GetBufferSize(), NULL, &m_pVertexShader);
	if (FAILED(hr))
		return false;

	// Create the pixel shader from the buffer.
	hr = m_pD3D->GetD3DDevice()->CreatePixelShader(m_pPixelShaderBuffer->GetBufferPointer(), m_pPixelShaderBuffer->GetBufferSize(), NULL, &m_pPixelShader);

	if (FAILED(hr))
		return false;


	return true;
}


bool XD3DShader::SetParams(const D3DXMATRIX & view, const D3DXMATRIX & projection, const std::string & textureName, int lightmapId)
{
	HRESULT hr;
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	MatrixBufferType* dataPtr;
	unsigned int bufferNumber;

	// Transpose the matrices to prepare them for the shader.
	D3DXMATRIX worldTranspose, viewTranspose, projectionTranspose;
	D3DXMatrixTranspose(&worldTranspose, &m_world);
	D3DXMatrixTranspose(&viewTranspose, &view);
	D3DXMatrixTranspose(&projectionTranspose, &projection);


	hr = m_pD3D->GetDeviceContext()->Map(m_pMatrixBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);

	if (FAILED(hr))
		return false;


	dataPtr = (MatrixBufferType*)mappedResource.pData;


	dataPtr->world = worldTranspose;
	dataPtr->view = viewTranspose;
	dataPtr->projection = projectionTranspose;


	m_pD3D->GetDeviceContext()->Unmap(m_pMatrixBuffer, 0);

	bufferNumber = 0;

	m_pD3D->GetDeviceContext()->VSSetConstantBuffers(bufferNumber, 1, &m_pMatrixBuffer);


	// set the texture resource
	if (lightmapId == -1)
	{
		ID3D11ShaderResourceView* pTexture = m_pTextureManager->GetTexture(textureName);
		m_pD3D->GetDeviceContext()->PSSetShaderResources(0, 1, &pTexture);
	}
	else
	{
		ID3D11ShaderResourceView* pTexture = m_pTextureManager->GetTexture(textureName);
		ID3D11ShaderResourceView* pLightmap = m_pTextureManager->GetLightmap(lightmapId);
		ID3D11ShaderResourceView* pTextureResources[2];
		pTextureResources[0] = pTexture;
		pTextureResources[1] = pLightmap;;
		m_pD3D->GetDeviceContext()->PSSetShaderResources(0, 2, pTextureResources);
	}

	return true;
}



bool XD3DShader::CreateMatrixBuffer()
{
	HRESULT hr;
	D3D11_BUFFER_DESC matrixBufferDesc;
	matrixBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	matrixBufferDesc.ByteWidth = sizeof(MatrixBufferType);
	matrixBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	matrixBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	matrixBufferDesc.MiscFlags = 0;
	matrixBufferDesc.StructureByteStride = 0;

	hr = m_pD3D->GetD3DDevice()->CreateBuffer(&matrixBufferDesc, NULL, &m_pMatrixBuffer);

	if (FAILED(hr))
		return false;

	return true;
}

bool XD3DShader::CreateLightBuffer()
{
	HRESULT hr;
	D3D11_BUFFER_DESC lightBufferDesc;
	lightBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	lightBufferDesc.ByteWidth = sizeof(LightBufferType);
	lightBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	lightBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	lightBufferDesc.MiscFlags = 0;
	lightBufferDesc.StructureByteStride = 0;

	hr = m_pD3D->GetD3DDevice()->CreateBuffer(&lightBufferDesc, NULL, &m_pLightBuffer);
	if (FAILED(hr))
		return false;

	return true;
}



void XD3DShader::OutputErrorToFile()
{
	std::ofstream outputFile;

	outputFile.open("ShaderError.txt");

	if (outputFile.is_open())
		outputFile << (char*)m_pErrorMessage->GetBufferPointer();

	outputFile.close();
}


XShader::~XShader()
{
}
