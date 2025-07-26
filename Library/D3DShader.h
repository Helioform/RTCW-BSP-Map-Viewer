#pragma once

#include <string>


class ID3D11VertexShader;
class ID3D11PixelShader;

namespace Helios
{
    class D3D11GraphicsAPI;

    class D3DShader 
    {
    public:
        D3DShader() = default;
        D3DShader(D3D11GraphicsAPI* _gfxAPI) : gfxAPI(_gfxAPI) {}

        void Compile(const std::wstring& vertexShaderName, const std::wstring& pixelShaderName);
        void Bind();
        void CleanUp();

    protected:
        ID3D11VertexShader* m_vertexShader = nullptr;
        ID3D11PixelShader* m_pixelShader = nullptr;
        D3D11GraphicsAPI* gfxAPI;
    };

}

