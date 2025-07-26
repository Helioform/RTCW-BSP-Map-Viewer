#pragma once


#include <variant>
#include <string>
#include "../D3DShader.h"

class D3DShader;
class OpenGLShader;


namespace Helios
{
	using ShaderVariant = std::variant<D3DShader>;

		enum class SHADER_TYPE : uint8_t
		{
			VERTEX_SHADER = 1,
			HULL_SHADER = 2,
			DOMAIN_SHADER = 3,
			GEOMETRY_SHADER = 4,
			PIXEL_SHADER = 5,
			COMPUTE_SHADER = 6
		};


		class Shader
		{	
		public:
			Shader() = default;
			Shader(const D3DShader& d3dShader);
			
			void Compile(const std::wstring& vertexSource, const std::wstring& pixelSource) {
				std::visit([&](auto&& shaderInstance) {
					shaderInstance.Compile(vertexSource, pixelSource);
					}, m_shader);
			}

			void Bind() {
				std::visit([](auto&& shaderInstance) {
					shaderInstance.Bind();
					}, m_shader);
			}

			void CleanUp() {
				std::visit([](auto&& shaderInstance) {
					shaderInstance.CleanUp();
					}, m_shader);
			}
		private:
			ShaderVariant m_shader;

		};
}