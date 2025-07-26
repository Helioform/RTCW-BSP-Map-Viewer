#pragma once

#include "Entity.h"
#include "Primitives.h"

namespace Helios
{
		struct ConstantMatrixBuffer
		{
			XMFLOAT4X4 WVP;		
		};

		struct LightSpaceMatrixBuffer
		{
			XMFLOAT4X4 lightSpaceMatrix;
			XMFLOAT4X4 modelMatrix;
		};


		struct Frustum
		{
			Plane top, bottom, right, left, zNear, zFar;
		};

		enum class PROJECTION_TYPE
		{
			ORTHOGRAPHIC,
			PERSPECTIVE
		};

		class Camera : public Entity
		{


		public:
			Camera() = default;

			Camera(PROJECTION_TYPE type, float fovY, const XMFLOAT3& up, const XMFLOAT3& forward,
				const XMFLOAT3& position, float zNear, float zFar, uint32_t screenWidth, uint32_t screenHeight);


			inline void MapToScreen(float& screenX, float& screenY, float x, float y)
			{
				screenX = static_cast<float>((m_viewportWidth / 2) * -1) + static_cast<float>(x);
				screenY = static_cast<float>(m_viewportHeight / 2) - static_cast<float>(y);
			}

			void Pan(float panScaleX, float panScaleY)
			{
				//Vector3 panX = m_right * panScaleX;
				//Vector3 panY = m_up * panScaleY;
				//m_position = m_position + panX;
				//char msgbuf[100];
				//sprintf_s(msgbuf, "Position: %f %f %f\n", m_position.x, m_position.y, m_position.z);

				////OutputDebugStringA(msgbuf);
				//sprintf_s(msgbuf, "Forward: %f %f %f\n", m_forward.x, m_forward.y, m_forward.z);
				////	OutputDebugStringA(msgbuf);

				//sprintf_s(msgbuf, "Pan : %f %f %f\n", panX.x, panX.y, panX.z);

				////	OutputDebugStringA(msgbuf);
				//UpdateViewMatrix();
			}

			void Walk(float d);
			void Strafe(float d);
			void Pitch(float angle);
			void Yaw(float angle);

			void UpdateViewMatrix();
			ConstantMatrixBuffer& GetConstantBuffer() {
				return m_buffer;
			}
			
			XMMATRIX GetViewMatrix() const {
				return XMLoadFloat4x4(&m_viewMatrix);
			}
		
			void SetViewMatrix(XMMATRIX m)
			{
				XMStoreFloat4x4(&m_viewMatrix, m);
			}

			XMMATRIX GetProjectionMatrix() const {
				return XMLoadFloat4x4(&m_projectionMatrix);	
			}

			void SetForward(XMFLOAT3 f)
			{
				m_forward = f;
			}
		private:
			PROJECTION_TYPE		m_projectionType{ PROJECTION_TYPE::PERSPECTIVE };
			Frustum				m_viewFrustum;
			float				m_viewportWidth{ 0.0f }, m_viewportHeight{ 0.0f };
			uint32_t			m_screenWidth{ 0 }, m_screenHeight{ 0 };
			float				m_aspectRatio{ 1.0f };
			float				m_zNear, m_zFar;
			XMFLOAT4X4			m_viewMatrix;
			XMFLOAT4X4			m_projectionMatrix;
			float				m_fovY;
			bool				m_viewDirty = true;
			ConstantMatrixBuffer m_buffer;
		};
}

