#pragma once
#include "Graphics/Primitives.h"

namespace Helios
{
	struct LightBuffer
	{
		DirectX::XMFLOAT4 color;
		DirectX::XMFLOAT3 direction;
		float padding;
	};
}

