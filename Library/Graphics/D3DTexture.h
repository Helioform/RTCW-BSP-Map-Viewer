#pragma once

#include "Texture.h"
#include <d3d11.h>
#include <wrl.h>

using Microsoft::WRL::ComPtr;

namespace Helios
{
	
		struct D3DTexture : public Texture
		{
		
			ID3D11ShaderResourceView*	m_pShaderResourceView;
	
			D3DTexture() = default;
			~D3DTexture() {}		

		};
	
}

