#pragma once
#include "XEntity.h"

#define PLAYER_HEIGHT 45.0f
#define PLAYER_RADIUS 20.0f
#define PLAYER_VELOCITY 100.0f


class XPlayer :
	public XEntity
{
protected:
	
	float	m_health;
	float	m_height;


public:
	XPlayer();
	XPlayer(const std::string& name, D3DXVECTOR3 position, D3DXVECTOR3 direction, float screenHeight, float screenWidth, float fov, float nplane, float fplane) 
		: XEntity(name, position, direction, screenHeight, screenWidth, fov, nplane, fplane)
	{
		m_health = 100.0f;
		m_height = PLAYER_HEIGHT;
		m_velocity = PLAYER_VELOCITY;
	}

	~XPlayer();
	
	

	AABB& GetBoundingBox() {
		return m_boundingBox;
	}

	Sphere& GetBoundingSphere() {
		return m_boundingSphere;
	}

	void CalculateBoundingBox() {}
	void CalculateBoundingSphere()
	{
		m_boundingSphere.center[0] = GetCamera()->GetPosition()[0];
		m_boundingSphere.center[1] = GetCamera()->GetPosition()[1];
		m_boundingSphere.center[2] = GetCamera()->GetPosition()[2];

		m_boundingSphere.radius = PLAYER_RADIUS;
	}
};

