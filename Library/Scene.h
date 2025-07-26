#pragma once

#include "../Library/Graphics/D3D11GraphicsAPI.h"
#include "../Library/Mesh.h"
#include "Graphics/Camera.h"
#include "../Library/D3DShader.h"
#include "Player.h"
#include "Light.h"

namespace Helios
{
	struct D3DBuffer;
	class D3D11GraphicsAPI;

	struct MousePosition
	{
		uint32_t x, y;
	};

	class Scene
	{
		


	public:
		Scene() = default;
		Scene(HWND hwnd, uint32_t w, uint32_t h, bool fullscreen);
		void Init(HWND hwnd, uint32_t w, uint32_t h, bool fullscreen);
		void LoadShader(const std::wstring& shaderName, SHADER_TYPE type);
		void Update(float dt);
		void SetCameraConstantBufferParams();
		bool LoadMeshes(const std::string& filename);
		void CheckForCollisions(const Player& player); // naive approach that checks each object in relation with the player


		void SetLightBuffer();

		inline Camera* GetCamera() {
			return camera.get();
		}

		inline D3D11GraphicsAPI* GetGFXAPI() {
			return gfxAPI.get();
		}

		inline void SetMousePos(uint32_t x, uint32_t y)
		{
			mousePos.x = x;
			mousePos.y = y;
		}

		inline void SetLastMousePos(uint32_t x, uint32_t y)
		{
			lastMouse.x = x;
			lastMouse.y = y;
		}

		inline MousePosition CalculateMouseDelta()
		{
			return MousePosition{mousePos.x - lastMouse.x, mousePos.y - lastMouse.y
		};
		}

		inline std::vector<Buffer*>& GetBuffers() {
			return buffers;
		}

		inline std::vector<Buffer*>& GetIndexBuffers()
		{
			return indexBuffers;
		}

		inline std::unordered_map<std::wstring, std::shared_ptr<Shader>>& GetShaders() {
			return shaders;
		}

		inline void YawCamera(float dt)
		{
			camera->Yaw(dt);
		}

		Player* GetPlayer()
		{	
			return player;
		}

		inline std::vector<Mesh>& GetMeshes() {
			return meshes;
		}

		void MovePlayer(float dt)
		{
			player->Move(dt);
		}
		
		void RotatePlayer(float dt);
		
	private:
		std::unique_ptr<Camera> camera;
		std::vector<Mesh> meshes;
		std::unordered_map<std::wstring, std::shared_ptr<Shader>> shaders;
		std::vector<Buffer*> buffers;
		std::vector<Buffer*> indexBuffers;
		std::vector<Buffer*> constantBuffer; 
		std::unique_ptr<D3D11GraphicsAPI> gfxAPI;
		D3DTexture* texture;
		Player*			player;
		MousePosition mousePos;
		MousePosition lastMouse;
		LightBuffer lightBuffer;
		std::vector<D3DTexture*> textures;
	};
}