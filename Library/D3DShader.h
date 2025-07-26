#pragma once
#include "../Library/Graphics/Shader.h"

class ID3D11VertexShader;
class ID3D11PixelShader;

namespace Helios
{
    struct D3DShader :
        public Shader
    {
  
        D3DShader() = default;
        D3DShader(const std::wstring& name) : Shader(name) {}

        virtual void* GetVertexShaderData() override {
            return (void*)m_vertexShader;
        }

        virtual void* GetPixelShaderData() override {
            return (void*)m_pixelShader;
        }
   
        ID3D11VertexShader* m_vertexShader = nullptr;
        ID3D11PixelShader* m_pixelShader = nullptr;


    };

}

