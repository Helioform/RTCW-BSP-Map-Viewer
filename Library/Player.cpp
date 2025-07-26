#include "Player.h"
#include "Utils.h"


void Helios::Player::Move(float dt)
{
	if (playerMesh != nullptr)
	{

		
		
	}
}

void Helios::Player::Yaw(float dt)
{
	if (playerMesh != nullptr)
	{
		// Create a rotation matrix around the up vector
		XMMATRIX rotation = XMMatrixRotationY(dt);

		// Rotate the forward and right vectors
		SetForward(XMVector3TransformNormal(GetForward(), rotation));
		SetRight(XMVector3TransformNormal(GetRight(), rotation));

	}
}
