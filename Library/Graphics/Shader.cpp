
#include "Shader.h"

namespace Helios
{

		//void Shader::LoadFromFile(const std::wstring& shaderName)
		//{
		//	std::ifstream file;
		//	std::wstring path = GetEXEPath();

		//	file.open(path + L"/" + shaderName, std::ios_base::binary | std::ios_base::in | std::ios_base::ate);
		//	if (!file.is_open())
		//		return;

		//	// find out how big this file is
		//	 shaderBytesSize = file.tellg();
		//	 
		//	 shaderBytes = new uint8_t[shaderBytesSize];
		//	 file.seekg(0, file.beg);

		//	 file.read(reinterpret_cast<char*>(shaderBytes), shaderBytesSize);
		//	 


		//	 file.close();
		//}
	

	Shader::Shader(const D3DShader& d3dShader) : m_shader(d3dShader)
	{
	}

}