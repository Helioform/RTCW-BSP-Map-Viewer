#pragma once
#include "XCamera.h"
#include "HelperFunctions.h"
#include "Model.h"

class XEntity
{
protected:
	std::string m_name;
	D3DXVECTOR3 m_position;
	D3DXVECTOR3 m_direction;
	XCamera*	m_pCamera;
	AABB		m_boundingBox;
	Sphere		m_boundingSphere;
	float		m_velocity;
	float		m_acceleration[3];
	float		m_friction[3];
	D3DXVECTOR3 m_walkVelocity;

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

	void SetName(const std::string& name) { m_name = name; }
	void SetPosition(const D3DXVECTOR3& pos) { m_position = pos; }
	void SetDirection(const D3DXVECTOR3& dir) { m_direction = dir; }
	void SetVelocity(float v)
	{ 
		m_velocity = v;
		SetWalkVelocity(v, v);
	}

	float GetVelocity() { return m_velocity; }
	D3DXVECTOR3& GetPosition() { return m_position; }

	void SetWalkVelocity(float x, float z)
	{
		m_walkVelocity.x = x * m_pCamera->At().x;
		m_walkVelocity.y = 0.0f;
		m_walkVelocity.z = z * m_pCamera->At().z;
	}

	D3DXVECTOR3& GetWalkVelocity(void) {
		return m_walkVelocity;
	}

	void WalkForward()
	{
		m_pCamera->Walk(m_walkVelocity);
		m_position = m_pCamera->Eye();
	}

	void WalkBackward()
	{
		m_pCamera->Walk(-m_walkVelocity);
		m_position = m_pCamera->Eye();
	}

	void MoveForward()
	{
		m_pCamera->Move(m_velocity);
		m_position = m_pCamera->Eye();
	}

	void MoveBackward()
	{
		m_pCamera->Move(-m_velocity);
		m_position = m_pCamera->Eye();
	}

	void SetCamera(const D3DXVECTOR3& position, const D3DXVECTOR3& direction, float screenHeight, float screenWidth, float fov, float nplane, float fplane)
	{
		D3DXVECTOR3 right(1.0f, 0.0f, 0.0f);
		m_pCamera = new XCamera(direction, D3DXVECTOR3(0.0f, 1.0f, 0.0f), position, right, screenWidth, screenHeight, fov, nplane, fplane);
	}

	virtual XCamera* GetCamera(void) const { return m_pCamera; }

	AABB& GetBoundingBox() {
		return m_boundingBox;
	}

	Sphere& GetBoundingSphere() {
		return m_boundingSphere;
	}

	virtual void CalculateBoundingBox() { }
	virtual void CalculateBoundingSphere() { }
	
};

