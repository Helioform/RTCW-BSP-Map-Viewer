#pragma once
#include "XEntity.h"
class XLight :
	public XEntity
{
protected:
	D3DXVECTOR3 m_origin;
	D3DXVECTOR4 m_color;
	float		m_radius;
public:
	XLight();
	~XLight();
};

