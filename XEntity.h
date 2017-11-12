#pragma once
#include "XCamera.h"
#include "HelperFunctions.h"

class XEntity
{
protected:
	std::string m_name;
	D3DXVECTOR3 m_position;
	D3DXVECTOR3 m_direction;
	XCamera*	m_pCamera;
public:
	XEntity();
	XEntity(const std::string& name, const D3DXVECTOR3& position, const D3DXVECTOR3& direction, float screenHeight, float screenWidth, float fov, float nplane, float fplane)
	{
		m_name = name;
		m_position = position;
		m_direction = direction;
		D3DXVECTOR3 right(1.0f, 0.0f, 0.0f);
		m_pCamera = new XCamera(direction, D3DXVECTOR3(0.0f, 1.0f, 0.0f), position, right, screenWidth, screenHeight, fov, nplane, fplane);
	}
	~XEntity() {
		if (m_pCamera) delete m_pCamera;
	}
	void SetName(const std::string& name)
	{
		m_name = name;
	}
	void SetPosition(const D3DXVECTOR3& pos) {
		m_position = pos;
	}

	void SetDirection(const D3DXVECTOR3& dir)
	{
		m_direction = dir;
	}
	void SetCamera(const D3DXVECTOR3& position, const D3DXVECTOR3& direction, float screenHeight, float screenWidth, float fov, float nplane, float fplane)
	{
		D3DXVECTOR3 right(1.0f, 0.0f, 0.0f);
		m_pCamera = new XCamera(direction, D3DXVECTOR3(0.0f, 1.0f, 0.0f), position, right, screenWidth, screenHeight, fov, nplane, fplane);
	}

	XCamera* GetCamera(void) const { return m_pCamera; }
};

