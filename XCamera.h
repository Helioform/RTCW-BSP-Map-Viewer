#pragma once

#pragma comment(lib,"d3dx10.lib")

#include <DirectXMath.h>
#include <D3DX10.h>

using namespace DirectX;

#define PI 3.14159265359

struct Frustum
{
	D3DXVECTOR3 origin;
	float topSlope, bottomSlope, rightSLope, leftSlope, zNear, zFar;
};

class XCamera
{
protected:
	Frustum m_frustum;
	D3DXMATRIX m_view, m_projection;
	D3DXVECTOR3 m_at, m_up, m_eye, m_right;

	float	m_height, m_width, m_aspectRatio;
	float	m_fov;
	float	m_nearPlane, m_farPlane;
	float	m_totalPhi, m_totalTheta;
	bool	m_isOrtho;
	bool    m_isPerspective;
public:
	XCamera();
	XCamera(const D3DXVECTOR3& at, const D3DXVECTOR3& up, const D3DXVECTOR3& eye, const D3DXVECTOR3& right, float width, float height, float fov, float nearPlane, float farPlane)
	{
		m_at = at;
		m_eye = eye;
		m_up = up;
		m_right = right;
		m_width = width;
		m_height = height;
		m_aspectRatio = width / height;
		m_fov = fov;
		m_nearPlane = nearPlane;
		m_farPlane = farPlane;
		UpdateViewMatrix();
		D3DXMatrixPerspectiveFovLH(&m_projection, PI*m_fov / 180.0f, m_aspectRatio, m_nearPlane, m_farPlane);
		m_frustum.zNear = eye.z + m_nearPlane;
		m_frustum.zFar = eye.z + m_farPlane;;

	}

	XCamera(const D3DXVECTOR3& at, const D3DXVECTOR3& up, const D3DXVECTOR3& eye, float width, float height, float nearPlane, float farPlane)
	{
		m_at = at - eye;
		m_up = up;
		m_eye = eye;
		m_width = width;
		m_height = height;
		m_aspectRatio = width / height;
		m_nearPlane = nearPlane;
		m_farPlane = farPlane;
		D3DXMatrixLookAtLH(&m_view, &m_eye, &m_at, &m_up);
		SetOrthographicMatrix(width, height, nearPlane, farPlane);
	}

	~XCamera();

	float& Width() { return m_width; }
	float& Height() { return m_height; }
	float& FOV() { return m_fov; }
	float& FarPlane() { return m_farPlane; }
	float& NearPlane() { return m_nearPlane; }

	D3DXVECTOR3 & At(void)  { return m_at; }
	D3DXVECTOR3 & Up(void)  { return m_up; }
    D3DXVECTOR3 & Eye(void)  { return m_eye; }
	D3DXMATRIX & ViewMatrix(void) { return m_view; }
	D3DXMATRIX & ProjectionMatrix(void) { return m_projection; }

	void UpdateViewMatrix()
	{
		//D3DXMatrixLookAtLH(&m_view, &m_eye, &m_at, &m_up);
		//
		// Orthonormalize the right, up and look vectors.
		//
		// Make look vector unit length.
		D3DXVECTOR3 L, U, R;
		L = m_at;
		U = m_up;
		R = m_right;
		D3DXVec3Normalize(&L, &L);
		// Compute a new corrected "up" vector and normalize it.	
		D3DXVec3Cross(&U, &L, &R);
		D3DXVec3Normalize(&U, &U);
		// Compute a new corrected "right" vector. U and L are
		// already ortho-normal, so no need to normalize cross product.
		// ||up × look|| = ||up|| ||look|| sin90° = 1
		D3DXVec3Cross(&R, &U, &L);

		m_right = R;
		m_up = U;
		m_at = L;

		//
		// Fill in the view matrix entries.
		//
		float x = -D3DXVec3Dot(&m_eye, &m_right);
		float y = -D3DXVec3Dot(&m_eye, &m_up);
		float z = -D3DXVec3Dot(&m_eye, &m_at);

		m_view(0, 0) = m_right.x;
		m_view(1, 0) = m_right.y;
		m_view(2, 0) = m_right.z;
		m_view(3, 0) = x;
		m_view(0, 1) = m_up.x;
		m_view(1, 1) = m_up.y;
		m_view(2, 1) = m_up.z;
		m_view(3, 1) = y;
		m_view(0, 2) = m_at.x;
		m_view(1, 2) = m_at.y;
		m_view(2, 2) = m_at.z;
		m_view(3, 2) = z;
		m_view(0, 3) = 0.0f;
		m_view(1, 3) = 0.0f;
		m_view(2, 3) = 0.0f;
		m_view(3, 3) = 1.0f;
	}

	void SetOrthographicMatrix(float width, float height, float zNear, float zFar)
	{
		D3DXMatrixOrthoLH(&m_projection, width, height, zNear, zFar);
	}

	void UpdateProjectionMatrix()
	{
		D3DXMatrixPerspectiveFovLH(&m_projection, PI*m_fov / 180.0f, m_aspectRatio, m_nearPlane, m_farPlane);
	}

	void OrientAt(float phi, float theta)
	{
		m_totalPhi += phi;
		m_totalTheta += theta;

		m_at.x = sin(m_totalPhi)*cos(m_totalTheta);
		m_at.z = sin(m_totalPhi)*sin(m_totalTheta);
		m_at.y = cos(m_totalPhi);
	}

	void Move(float delta) 
	{
		m_eye += delta * m_at;
	}

	void Pitch(float angle) 
	{
		D3DXMATRIX R;
		D3DXMatrixRotationAxis(&R, &m_right, angle);
		D3DXVec3TransformNormal(&m_up, &m_up, &R);
		D3DXVec3TransformNormal(&m_at, &m_at, &R);
	}

	void Strafe(float delta) 
	{
		m_eye += delta * m_right;
	}

	void RotateAtAroundY(float rad) 
	{
		D3DXMATRIX R;
		D3DXMatrixRotationY(&R, rad);
		D3DXVec3TransformNormal(&m_right, &m_right, &R);
		D3DXVec3TransformNormal(&m_up, &m_up, &R);
		D3DXVec3TransformNormal(&m_at, &m_at, &R);
	}

	bool IsInFrustum(int* mins, int* maxs) 
	{
		//if (mins[2] >= m_frustum.zNear && mins[2] <= m_frustum.zFar)
		//		return true;


		return true;
	}
};

