#pragma once


#include "jpgd.h"
#include "CommonHeaders.h"

namespace Helios
{

		struct Texture
		{	
			std::unique_ptr<uint8_t[]>	m_pImageData;
			uint32_t					m_width;
			uint32_t					m_height;
			std::string					m_name;

			Texture() {}
			~Texture() {}
		};
	
}

