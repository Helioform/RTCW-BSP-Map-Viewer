
#include "XFont.h"

bool XFont::CreateShaders()
{
	m_pD3DShaders[0] = new XD3DShader(m_pD3D, m_pTexManager);

	if (!m_pD3DShaders[0]->LoadAndCompile("Effects/sprite.vs", "Effects/sprite.ps", "SpriteVertexShader", "SpritePixelShader"))
	{
		m_pD3DShaders[0]->OutputErrorToFile();
		return false;
	}

	m_pD3DShaders[0]->CreateMatrixBuffer();
	m_pShaders[0] = new XShader("Font", 0, 0);
	m_pShaders[0]->AttachD3DShader(m_pD3DShaders[0]);
	m_numShaders = 1;

	return true;
}

bool XFont::LoadFontTextureMap(const std::string & fileName)
{
	if (!m_pTexManager->Load(fileName, "Font", false))
		return false;

	unsigned char* pData = nullptr;
	unsigned int w, h;
	unsigned int rowPitch, colStart, rowStart, row, col, _col;
	unsigned int numColBlackPixels = 0;
	unsigned int lastCol = 0;
	float u, v;
	char charact = '!';
	int spaceWidth = 0;

	m_pTexManager->GetTextureData("Font", &pData, w, h, rowPitch);

	for(col = 0; col < w; col++)
	{
		
		if (charact >= '!' + 127) // done reading all chars
			break;	
			
		colStart = 4 * col;
		
		for (row = 0; row < h; row++)
		{
			rowStart = row * rowPitch;
			if ((pData[rowStart + colStart + 0] == 0 &&
				pData[rowStart + colStart + 1] == 0 &&
				pData[rowStart + colStart + 2] == 0)||(pData[rowStart + colStart + 3] == 0))
				numColBlackPixels++;
		}

		if (numColBlackPixels != h) // found a non black column
		{
			numColBlackPixels = 0;
			_col = col;
			lastCol = col;

			// advance to next black column
			while (_col < w)
			{
				colStart = 4 * _col;
				
				for (row = 0; row < h; row++)
				{
					rowStart = row * rowPitch;
					if ((pData[rowStart + colStart + 0] == 0 &&
						pData[rowStart + colStart + 1] == 0 &&
						pData[rowStart + colStart + 2] == 0) || (pData[rowStart + colStart + 3] == 0))
						numColBlackPixels++;
				}
			
				if (numColBlackPixels == h)
				{
							
						// calculate texture coordinates
						TexCoords uv;
						uv.u[0] = static_cast<float>(lastCol) / static_cast<float>(w);
						uv.v[0] = 0.0f;
						uv.u[1] = static_cast<float>(_col) / static_cast<float>(w);
						uv.v[1] = 0.0f;
						uv.u[2] = static_cast<float>(lastCol) / static_cast<float>(w);
						uv.v[2] = 1.0f;
						uv.u[3] = static_cast<float>(_col) / static_cast<float>(w);
						uv.v[3] = 1.0f;

						m_charTextureCoords[charact] = uv;
						charact++;
						numColBlackPixels = 0;
				
						break;
							
				}
				
				_col++;
				numColBlackPixels = 0;		
			}

			col = _col;
		}		
		
		if (numColBlackPixels == h)
		{
			numColBlackPixels = 0;
			// move on to next column
			continue;
		}

		numColBlackPixels = 0;
	}

	delete [] pData;

	if (!CreateShaders())
		return false;

	if (!CreateInputLayout())
		return false;

	return true;
}

bool XFont::CreateInputLayout()
{
	HRESULT hr;
	D3D11_INPUT_ELEMENT_DESC polygonLayout[3];
	unsigned int numElements;

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

	numElements = sizeof(polygonLayout) / sizeof(polygonLayout[0]);

	hr = m_pD3D->GetD3DDevice()->CreateInputLayout(polygonLayout, numElements, m_pD3DShaders[0]->GetVertexShaderBuffer()->GetBufferPointer(),
		m_pD3DShaders[0]->GetVertexShaderBuffer()->GetBufferSize(), &m_pLayout);

	m_pD3DShaders[0]->GetVertexShaderBuffer()->Release();
	m_pD3DShaders[0]->GetPixelShaderBuffer()->Release();

	if (FAILED(hr))
		return false;

	return true;
}

bool XFont::CreateVertexBuffer(Vertex* pVertices, unsigned int numVertices)
{
	HRESULT hr; D3D11_BUFFER_DESC vertexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData;

	vertexBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	vertexBufferDesc.ByteWidth = sizeof(pVertices[0]) * numVertices;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	vertexData.pSysMem = pVertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	hr = m_pD3D->GetD3DDevice()->CreateBuffer(&vertexBufferDesc, &vertexData, &m_pVertexBuffer);

	if (FAILED(hr))
		return false;

	return true;
}


bool XFont::UpdateVertexBuffer(Vertex * pVertices, unsigned int numVertices)
{
	HRESULT hr;
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	Vertex* pVertexPtr;
	hr = m_pD3D->GetDeviceContext()->Map(m_pVertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);

	if (FAILED(hr))
		return false;

	pVertexPtr = (Vertex*)mappedResource.pData;

	memcpy(pVertexPtr, (void*)pVertices, (sizeof(Vertex) * numVertices));

	m_pD3D->GetDeviceContext()->Unmap(m_pVertexBuffer, 0);
	return true;
}


bool XFont::WriteText(int x, int y, const std::string & text, const D3DXVECTOR4& col,  XCamera* pCam)
{
	if (text != m_screenText)
	{
		m_screenText = text;

		Vertex* pVerts = new Vertex[text.length() * 6];
		int k = 0, l = 0;
		float sx = 0, sy = 0;

		for (int charac = 0; charac < text.length(); charac++)
		{
			if (text[charac] == ' ')
			{
				x += m_spacing;
				continue;
			}

			char ch = m_screenText[charac];
			float width = abs(m_charTextureCoords[ch].u[1] - m_charTextureCoords[ch].u[0]);
			width *= m_charWidth;

			// top left corner
			pCam->MapToScreen(&sx, &sy, x, y);
			pVerts[k].color = col;
			pVerts[k].pos = D3DXVECTOR3(sx, sy, 0.0f);
			pVerts[k++].tex = D3DXVECTOR2(m_charTextureCoords[ch].u[0], m_charTextureCoords[ch].v[0]);
			// top right corner
			pCam->MapToScreen(&sx, &sy, x + width, y);
			pVerts[k].color = col;
			pVerts[k].pos = D3DXVECTOR3(sx, sy, 0.0f);
			pVerts[k++].tex = D3DXVECTOR2(m_charTextureCoords[ch].u[1], m_charTextureCoords[ch].v[1]);
			// bottom left corner
			pCam->MapToScreen(&sx, &sy, x, y + m_charHeight);
			pVerts[k].color = col;
			pVerts[k].pos = D3DXVECTOR3(sx, sy, 0.0f);
			pVerts[k++].tex = D3DXVECTOR2(m_charTextureCoords[ch].u[2], m_charTextureCoords[ch].v[2]);
			// bottom left corner
			pCam->MapToScreen(&sx, &sy, x, y + m_charHeight);
			pVerts[k].color = col;
			pVerts[k].pos = D3DXVECTOR3(sx, sy, 0.0f);
			pVerts[k++].tex = D3DXVECTOR2(m_charTextureCoords[ch].u[2], m_charTextureCoords[ch].v[2]);
			// top right corner
			pCam->MapToScreen(&sx, &sy, x + width, y);
			pVerts[k].color = col;
			pVerts[k].pos = D3DXVECTOR3(sx, sy, 0.0f);
			pVerts[k++].tex = D3DXVECTOR2(m_charTextureCoords[ch].u[1], m_charTextureCoords[ch].v[1]);
			// bottom right corner
			pCam->MapToScreen(&sx, &sy, x + width, y + m_charHeight);
			pVerts[k].color = col;
			pVerts[k].pos = D3DXVECTOR3(sx, sy, 0.0f);
			pVerts[k++].tex = D3DXVECTOR2(m_charTextureCoords[ch].u[3], m_charTextureCoords[ch].v[3]);

			x += width + 2;
		}

		if (m_pVertexBuffer == nullptr)
		{
			if (!CreateVertexBuffer(pVerts, m_screenText.length() * 6))
				return false;
		}
		else
		{
			if (!UpdateVertexBuffer(pVerts, m_screenText.length() * 6))
				return false;
		}

		delete[] pVerts;
	}

	HRESULT hr;
	unsigned int stride;
	unsigned int offset;

	stride = sizeof(Vertex);
	offset = 0;

	m_pD3D->GetDeviceContext()->IASetVertexBuffers(0, 1, &m_pVertexBuffer, &stride, &offset);
	m_pD3D->GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	m_pD3D->GetDeviceContext()->IASetInputLayout(m_pLayout);

	XShader* pShader = m_pShaders[0];
	XD3DShader* pD3DShader = m_pD3DShaders[0];

	pD3DShader->SetParams(pCam->ViewMatrix(), pCam->ProjectionMatrix(), "Font");
	
	pD3DShader->BindVertexShader();
	pD3DShader->BindPixelShader();

	ID3D11SamplerState* pSampleState = m_pTexManager->GetSamplerState();
	m_pD3D->GetDeviceContext()->PSSetSamplers(0, 1, &pSampleState);
	
	m_pD3D->TurnOnBlending(D3D11_BLEND_SRC_ALPHA, D3D11_BLEND_INV_SRC_ALPHA);
	m_pD3D->GetDeviceContext()->Draw(m_screenText.length() * 6, 0);
	m_pD3D->TurnOffBlending();

	return true;
}
