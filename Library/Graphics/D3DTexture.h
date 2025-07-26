#pragma once

#include "Texture.h"
#include <d3d11.h>
#include <wrl.h>

using Microsoft::WRL::ComPtr;

namespace Helios
{
	
		struct D3DTexture : public Texture
		{
			ID3D11ShaderResourceView* m_pShaderResourceView;
			ID3D11Device* m_pD3D11Device;
			ID3D11DeviceContext* m_pD3D11DeviceContext;


			inline void Register(ID3D11Device* pDevice, ID3D11DeviceContext* pDeviceContext)
			{
				m_pD3D11Device = pDevice;
				m_pD3D11DeviceContext = pDeviceContext;
			}
	
			D3DTexture() = default;
			~D3DTexture() {}		
			void CreateFromJPGFile(const std::string& fileName);
		};
	
}

