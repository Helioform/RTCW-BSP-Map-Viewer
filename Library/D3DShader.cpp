#include "D3DShader.h"

#include "./Graphics/D3D11GraphicsAPI.h"


void Helios::D3DShader::Compile(const std::wstring& vertexShaderName, const std::wstring& pixelShaderName)
{
	gfxAPI->CompileShader(m_vertexShader, m_pixelShader, vertexShaderName, SHADER_TYPE::VERTEX_SHADER);
	gfxAPI->CompileShader(m_vertexShader, m_pixelShader, pixelShaderName, SHADER_TYPE::PIXEL_SHADER);	
}

void Helios::D3DShader::Bind()
{	
	gfxAPI->SetVSShader(m_vertexShader);
	gfxAPI->SetPSShader(m_pixelShader);
}


void Helios::D3DShader::CleanUp()
{
	if (m_vertexShader)
		m_vertexShader->Release();
	if (m_pixelShader)
		m_pixelShader->Release();
}
