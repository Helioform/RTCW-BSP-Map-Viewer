#pragma once
#include "Buffer.h"
#include <d3d11.h>
#include <wrl.h>


namespace Helios
{

	struct D3DBufferAccess : public BufferAccess
	{
		
		virtual void* GetData() override;
	};

		struct D3DBuffer : public Buffer
		{
			ID3D11Buffer* pD3DBuffer = nullptr;
		
			D3DBuffer() = default;
			
			inline void* GetBuffer()  override { return (void*) pD3DBuffer; }
			
		};

	
}
