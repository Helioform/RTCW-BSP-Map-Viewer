
#include "XCamera.h"


XCamera::XCamera()
{
	
}


XCamera::~XCamera()
{
}


void XCamera::ExtractFrustumPlanes()
{
	// calculate view projection matrix
	D3DXMATRIX vp = m_view * m_projection;

	m_frustum.zNear.n[0] = vp(0, 2) + vp(0, 3);
	m_frustum.zNear.n[1] = vp(1, 2) + vp(1, 3);
	m_frustum.zNear.n[2] = vp(2, 2) + vp(2, 3);
	m_frustum.zNear.d = vp(3, 2) + vp(3, 3);

	//float invSqrt = 1.0f / sqrt(m_frustum.zNear.n[0] * m_frustum.zNear.n[0] +
	//	m_frustum.zNear.n[1] * m_frustum.zNear.n[1] +
	//	m_frustum.zNear.n[2] * m_frustum.zNear.n[2]);

	//m_frustum.zNear.n[0] *= invSqrt;
	//m_frustum.zNear.n[1] *= invSqrt;
	//m_frustum.zNear.n[2] *= invSqrt;
	//m_frustum.zNear.d *= invSqrt;

	m_frustum.zFar.n[0] = -vp(0, 2) + vp(0, 3);
	m_frustum.zFar.n[1] = -vp(1, 2) + vp(1, 3);
	m_frustum.zFar.n[2] = -vp(2, 2) + vp(2, 3);
	m_frustum.zFar.d = -vp(3, 2) + vp(3, 3);

	//invSqrt = 1.0f / sqrt(m_frustum.zFar.n[0] * m_frustum.zFar.n[0] +
	//	m_frustum.zFar.n[1] * m_frustum.zFar.n[1] +
	//	m_frustum.zFar.n[2] * m_frustum.zFar.n[2]);

	//m_frustum.zFar.n[0] *= invSqrt;
	//m_frustum.zFar.n[1] *= invSqrt;
	//m_frustum.zFar.n[2] *= invSqrt;
	//m_frustum.zFar.d *= invSqrt;

	m_frustum.bottom.n[0] = vp(0, 1) + vp(0, 3);
	m_frustum.bottom.n[1] = vp(1, 1) + vp(1, 3);
	m_frustum.bottom.n[2] = vp(2, 1) + vp(2, 3);
	m_frustum.bottom.d = vp(3, 1) + vp(3, 3);

	//invSqrt = 1.0f / sqrt(m_frustum.bottom.n[0] * m_frustum.bottom.n[0] +
	//	m_frustum.bottom.n[1] * m_frustum.bottom.n[1] +
	//	m_frustum.bottom.n[2] * m_frustum.bottom.n[2]);

	//m_frustum.bottom.n[0] *= invSqrt;
	//m_frustum.bottom.n[1] *= invSqrt;
	//m_frustum.bottom.n[2] *= invSqrt;
	//m_frustum.bottom.d *= invSqrt;

	m_frustum.top.n[0] = -vp(0, 1) + vp(0, 3);
	m_frustum.top.n[1] = -vp(1, 1) + vp(1, 3);
	m_frustum.top.n[2] = -vp(2, 1) + vp(2, 3);
	m_frustum.top.d = -vp(3, 1) + vp(3, 3);

	//invSqrt = 1.0f / sqrt(m_frustum.top.n[0] * m_frustum.top.n[0] +
	//	m_frustum.top.n[1] * m_frustum.top.n[1] +
	//	m_frustum.top.n[2] * m_frustum.top.n[2]);

	//m_frustum.top.n[0] *= invSqrt;
	//m_frustum.top.n[1] *= invSqrt;
	//m_frustum.top.n[2] *= invSqrt;
	//m_frustum.top.d *= invSqrt;

	m_frustum.left.n[0] = vp(0, 0) + vp(0, 3);
	m_frustum.left.n[1] = vp(1, 0) + vp(1, 3);
	m_frustum.left.n[2] = vp(2, 0) + vp(2, 3);
	m_frustum.left.d = vp(3, 0) + vp(3, 3);

	//invSqrt = 1.0f / sqrt(m_frustum.left.n[0] * m_frustum.left.n[0] +
	//	m_frustum.left.n[1] * m_frustum.left.n[1] +
	//	m_frustum.left.n[2] * m_frustum.left.n[2]);

	//m_frustum.left.n[0] *= invSqrt;
	//m_frustum.left.n[1] *= invSqrt;
	//m_frustum.left.n[2] *= invSqrt;
	//m_frustum.left.d *= invSqrt;

	m_frustum.right.n[0] = -vp(0, 0) + vp(0, 3);
	m_frustum.right.n[1] = -vp(1, 0) + vp(1, 3);
	m_frustum.right.n[2] = -vp(2, 0) + vp(2, 3);
	m_frustum.right.d = -vp(3, 0) + vp(3, 3);

	//invSqrt = 1.0f / sqrt(m_frustum.right.n[0] * m_frustum.right.n[0] +
	//	m_frustum.right.n[1] * m_frustum.right.n[1] +
	//	m_frustum.right.n[2] * m_frustum.right.n[2]);

	//m_frustum.right.n[0] *= invSqrt;
	//m_frustum.right.n[1] *= invSqrt;
	//m_frustum.right.n[2] *= invSqrt;
	//m_frustum.right.d *= invSqrt;
}
