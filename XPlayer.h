#pragma once
#include "XEntity.h"


class XPlayer :
	public XEntity
{
protected:
	
	float m_health;

public:
	XPlayer();
	XPlayer(const std::string& name, D3DXVECTOR3 position, D3DXVECTOR3 direction, float screenHeight, float screenWidth, float fov, float nplane, float fplane) 
		: XEntity(name, position, direction, screenHeight, screenWidth, fov, nplane, fplane)
	{
		m_health = 100.0f;
	}	

	~XPlayer();
	
};

