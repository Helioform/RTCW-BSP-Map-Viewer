#include "D3DTexture.h"


namespace Helios
{

	void D3DTexture::CreateFromJPGFile(const std::string& fileName)
	{
		std::wstring path = GetEXEPath();
		uint32_t comps = 1;

		m_name = fileName;
		std::string textureFilesPath(path.begin(), path.end());

		auto pData = jpgd::decompress_jpeg_image_from_file((textureFilesPath + "/" + fileName).c_str(),
			reinterpret_cast<int*>(&m_width),
			reinterpret_cast<int*>(&m_height),
			reinterpret_cast<int*>(&comps),
			4); //  request a 32 bit image
		m_pImageData = std::make_unique<uint8_t[]>(m_width * m_height * 4);
		std::memcpy(m_pImageData.get(), pData, m_width * m_height * 4);

		if (m_pD3D11Device == nullptr || m_pD3D11DeviceContext == nullptr)
			return;

		HRESULT hr;
		ID3D11Texture2D* pTex2D = nullptr;
		D3D11_TEXTURE2D_DESC texDesc;
		memset(&texDesc, 0, sizeof(D3D11_TEXTURE2D_DESC));
		texDesc.Width = m_width;
		texDesc.Height = m_height;
		texDesc.MipLevels = 0;
		texDesc.ArraySize = 1;
		texDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		texDesc.SampleDesc.Count = 1;
		texDesc.SampleDesc.Quality = 0;
		texDesc.Usage = D3D11_USAGE_DEFAULT;
		texDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE | D3D11_BIND_RENDER_TARGET;
		texDesc.CPUAccessFlags = 0;
		texDesc.MiscFlags = D3D11_RESOURCE_MISC_GENERATE_MIPS;

		hr = m_pD3D11Device->CreateTexture2D(&texDesc, nullptr, &pTex2D);

		if (FAILED(hr))
		{
			OutputDebugString(L"Cannot create texture\n");
			return;
		}

		D3D11_MAPPED_SUBRESOURCE  mappedTex;
		uint32_t rowPitch = (m_width * 4) * sizeof(uint8_t);
		m_pD3D11DeviceContext->UpdateSubresource(pTex2D, 0, NULL, pData, rowPitch, 0);
		/*m_pD3D11DeviceContext->Map(pTex2D, 0, D3D11_MAP_READ, 0, &mappedTex);

		UCHAR* pTexels = (UCHAR*)mappedTex.pData;
		int j = 0;
		for (UINT row = 0; row < texDesc.Height; row++)
		{
			UINT rowStart = row * mappedTex.RowPitch;
			for (UINT col = 0; col < texDesc.Width; col++)
			{
				UINT colStart = col * 4;
				pTexels[rowStart + colStart + 0] = m_pImageData[j++];
				pTexels[rowStart + colStart + 1] = m_pImageData[j++];
				pTexels[rowStart + colStart + 2] = m_pImageData[j++];
				pTexels[rowStart + colStart + 3] = m_pImageData[j++];
			}
		}

		m_pD3D11DeviceContext->Unmap(pTex2D, D3D11CalcSubresource(0, 0, 1));*/

		D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
		memset(&srvDesc, 0, sizeof(D3D11_SHADER_RESOURCE_VIEW_DESC));
		srvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
		srvDesc.Texture2D.MostDetailedMip = 0;
		srvDesc.Texture2D.MipLevels = -1;

		hr = m_pD3D11Device->CreateShaderResourceView(pTex2D, &srvDesc, &m_pShaderResourceView);


		m_pD3D11DeviceContext->GenerateMips(m_pShaderResourceView);


		if (FAILED(hr))
			OutputDebugString(L"Cannot create shader resource view\n");
	}
}