
#include "Entity.h"


namespace Helios
{
	

		Entity::Entity()
		{

			AddComponent<TagComponent>(COMPONENT_TYPE::TAG, std::string{ "hello" });
			AddComponent<TransformComponent>(COMPONENT_TYPE::TRANSFORM, m_right, m_up, m_forward);
		}

		XMMATRIX Helios::Entity::CreateRotationMatrixFromForward(const XMVECTOR& forward)
		{
			// Normalize the forward vector
			SetForward(XMVector3Normalize(forward));

			// Define the world's up vector
			XMVECTOR up = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

			// Compute the right vector
			SetRight( XMVector3Cross(up, forward));
			SetRight(XMVector3Normalize(GetRight()));

			// Recompute the up vector
			up = XMVector3Cross(GetForward(), GetRight());

			// Construct the rotation matrix
			XMMATRIX rotationMatrix = XMMatrixIdentity();
			rotationMatrix.r[0] = GetRight();
			rotationMatrix.r[1] = GetUp();
			rotationMatrix.r[2] = GetForward();

			return rotationMatrix;

		}

}