
#include "Camera.h"

namespace Helios
{

	
		Camera::Camera(PROJECTION_TYPE type, float fovY, const XMFLOAT3& up, const XMFLOAT3& forward, const XMFLOAT3& position, float zNear, float zFar, uint32_t screenWidth, uint32_t screenHeight) :
			m_fovY{ fovY },
				m_projectionType{ type },
				m_screenWidth{ screenWidth },
				m_screenHeight{ screenHeight },
				m_zNear{ zNear },
				m_zFar{ zFar },
				m_aspectRatio{ static_cast<float>(screenWidth) / screenHeight }
		{
			m_fovY = 90.0f*PI / 180.0f;
			m_forward = forward;
			m_position = position;
			m_up = up;
			m_right = XMFLOAT3(1.0f, 0.0f, 0.0f);
			XMStoreFloat4x4(&m_projectionMatrix, XMMatrixIdentity());
			//XMStoreFloat4x4(&m_projectionMatrix, XMMatrixPerspectiveFovLH(fovY *  , m_aspectRatio, zNear, zFar));
	
			float h, w, Q;
			w = 1.0f / tan(m_fovY * 0.5f);
			h = 1.0f / tan(m_fovY * 0.5f);
			Q = zFar / (zFar - zNear);
			m_projectionMatrix(0, 0) = w;
			m_projectionMatrix(1, 1) = h;
			m_projectionMatrix(2, 2) = Q;
			m_projectionMatrix(3, 2) = -Q*zNear;
			m_projectionMatrix(2, 3) = 1;



			m_viewDirty = true;
			UpdateViewMatrix();
		}
	
		void Camera::Walk(float d)
		{
			// m_position += d*m_forward
			XMVECTOR s = XMVectorReplicate(d);
			XMVECTOR l = XMLoadFloat3(&m_forward);
			XMVECTOR p = XMLoadFloat3(&m_position);
			XMStoreFloat3(&m_position, XMVectorMultiplyAdd(s, l,p));
			m_viewDirty = true;
			UpdateViewMatrix();
		}

		void Camera::Strafe(float d)
		{
			// m_position += d*m_right
			XMVECTOR s = XMVectorReplicate(d);
			XMVECTOR r = XMLoadFloat3(&m_right);
			XMVECTOR p = XMLoadFloat3(&m_position);
			XMStoreFloat3(&m_position, XMVectorMultiplyAdd(s, r,
				p));
		}

		void Camera::Pitch(float angle)
		{
			// Rotate up and look vector about the right vector.
			XMMATRIX R = XMMatrixRotationAxis(XMLoadFloat3(&m_right), angle);
			XMStoreFloat3(&m_up, XMVector3TransformNormal(XMLoadFloat3(&m_up), R));
			XMStoreFloat3(&m_forward, XMVector3TransformNormal(XMLoadFloat3(&m_forward), R));
		}

		void Camera::Yaw(float angle)
		{
			// Rotate the basis vectors about the world y-axis.
			XMMATRIX R = XMMatrixRotationY(angle);
			XMStoreFloat3(&m_right, XMVector3TransformNormal(XMLoadFloat3(&m_right),R));
			XMStoreFloat3(&m_up, XMVector3TransformNormal(XMLoadFloat3(&m_up), R));
			XMStoreFloat3(&m_forward, XMVector3TransformNormal(XMLoadFloat3(&m_forward), R));
			m_viewDirty = true;
			UpdateViewMatrix();
			
		}

		void Camera::UpdateViewMatrix()
		{
		//	XMStoreFloat4x4(&m_viewMatrix, XMMatrixLookToLH(XMLoadFloat3 (&m_position), XMLoadFloat3(&m_forward), XMLoadFloat3(&m_up)));
			

			if (m_viewDirty)
			{
				XMVECTOR R = XMLoadFloat3(&m_right);
				XMVECTOR U = XMLoadFloat3(&m_up);
				XMVECTOR L = XMLoadFloat3(&m_forward);
				XMVECTOR P = XMLoadFloat3(&m_position);
				// Keep camera’s axes orthogonal to each other and
				//of unit length.
				L = XMVector3Normalize(L);
				U = XMVector3Normalize(XMVector3Cross(L, R));
				// U, L already ortho-normal, so no need to
				//normalize cross product.
				R = XMVector3Cross(U, L);
				// Fill in the view matrix entries.
				float x = -XMVectorGetX(XMVector3Dot(P, R));
				float y = -XMVectorGetX(XMVector3Dot(P, U));
				float z = -XMVectorGetX(XMVector3Dot(P, L));
				XMStoreFloat3(&m_right, R);
				XMStoreFloat3(&m_up, U);
				XMStoreFloat3(&m_forward, L);
				m_viewMatrix(0, 0) = m_right.x;
				m_viewMatrix(1, 0) = m_right.y;
				m_viewMatrix(2, 0) = m_right.z;
				m_viewMatrix(3, 0) = x;
				m_viewMatrix(0, 1) = m_up.x;
				m_viewMatrix(1, 1) = m_up.y;
				m_viewMatrix(2, 1) = m_up.z;
				m_viewMatrix(3, 1) = y;
				m_viewMatrix(0, 2) = m_forward.x;
				m_viewMatrix(1, 2) = m_forward.y;
				m_viewMatrix(2, 2) = m_forward.z;
				m_viewMatrix(3, 2) = z;
				m_viewMatrix(0, 3) = 0.0f;
				m_viewMatrix(1, 3) = 0.0f;
				m_viewMatrix(2, 3) = 0.0f;
				m_viewMatrix(3, 3) = 1.0f;
				m_viewDirty = false;
			}
		}

}