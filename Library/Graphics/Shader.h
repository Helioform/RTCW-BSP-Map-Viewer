#pragma once
#include <stdint.h>
#include <memory.h>
#include <string>
#include <algorithm>
#include "GraphicsAPI.h"

namespace Helios
{


		enum class SHADER_TYPE : uint8_t
		{
			VERTEX_SHADER = 1,
			HULL_SHADER = 2,
			DOMAIN_SHADER = 3,
			GEOMETRY_SHADER = 4,
			PIXEL_SHADER = 5,
			COMPUTE_SHADER = 6
		};


		struct Shader
		{
		
			Shader() = default;
			Shader(const std::wstring& shaderName);
			virtual ~Shader()
			{
				if (shaderBytes)
					delete [] shaderBytes;
			}

			virtual void* GetVertexShaderData() = 0;
			virtual void* GetPixelShaderData() = 0;
			inline uint8_t* GetShaderByteData() const
			{
				return shaderBytes;
			}

			void LoadFromFile(const std::wstring& name);
			uint64_t GetSize() const {
				return shaderBytesSize;
			}

			uint64_t GetInputLayoutIndex() const { return inputLayoutIndex; }

		private:
			
		
			uint8_t* shaderBytes {nullptr};
		
			uint64_t shaderBytesSize;
			uint64_t ID;
			std::wstring name;
			uint64_t inputLayoutIndex;
		};
}