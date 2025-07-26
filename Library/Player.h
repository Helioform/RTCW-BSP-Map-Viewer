#pragma once

#include "./Graphics/Entity.h"
#include "Graphics/Camera.h"
#include "Mesh.h"

namespace Helios
{
	class Player : public Entity
	{
	public:
		Player()
		{	
			T = R = S = XMMatrixIdentity();
			m_forward = XMFLOAT3(0.0f, 0.0f, 1.0f);
			m_position = XMFLOAT3(0.0f, 0.0f, 0.0f);
		
		}

		Player(const XMFLOAT3& pos)
		{
		
		}
		
		inline void SetSpeed(float s)
		{
			speed = s;
		}

		inline float GetSpeed() const 
		{
			return speed;
		}

		void UpdateWorldMatrix() {


			XMMATRIX invT = XMMatrixInverse(nullptr, T);
			R = CreateRotationMatrixFromForward(GetForward());
			XMMATRIX invR = XMMatrixInverse(nullptr, R);
			R = invT * R * T;
			XMMATRIX invCamPos = XMMatrixInverse(nullptr, XMMatrixTranslation(playerCam->GetPosition3f().x, playerCam->GetPosition3f().y, playerCam->GetPosition3f().z));
			playerCam->SetViewMatrix(invT * invR * invCamPos);

			playerMesh->SetWorldMatrix(T * R);
		}
		
		void UpdatePosition()
		{
			XMVECTOR v = XMVectorAdd(GetPosition(), XMVectorScale(GetForward(), speed));
			// Update translation matrix
		    XMStoreFloat3(&m_position, v);
			T = XMMatrixTranslationFromVector(v);
		}

		void Move(float dt);
		void Yaw(float dt);

		Camera*	playerCam;
		float	movementSpeed;
		float	rotationSpeed;
		Mesh*	playerMesh;
		float speed = 0.001f;
		XMMATRIX T, R, S;
	};
}

