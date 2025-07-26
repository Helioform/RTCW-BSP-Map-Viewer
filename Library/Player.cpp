#include "Player.h"
#include "Utils.h"


void Helios::Player::Move(float dt)
{
	XMFLOAT3 f;
	XMVECTOR p = XMLoadFloat3(&m_position);
	p += GetForward() * dt;
	XMStoreFloat3(&m_position, p);
	T = XMMatrixTranslation(m_position.x, m_position.y, m_position.z);
}

void Helios::Player::Yaw(float dt)
{
	
		// Create a rotation matrix around the up vector
		XMMATRIX rotation = XMMatrixRotationY(dt);

		// Rotate the forward and right vectors
		SetForward(XMVector3TransformNormal(GetForward(), rotation));
		SetRight(XMVector3TransformNormal(GetRight(), rotation));

	
}
