#pragma once
#include "HelperFunctions.h"

struct Plane
{
	float n[3];
	float d;

	Plane() { }
	Plane(const float _n[3], const float _d)
	{
		n[0] = _n[0];
		n[1] = _n[1];
		n[2] = _n[2]; 
		d = _d;
	}

	void Normalize(void)
	{
		float invRootL = 1.0f / sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
		n[0] *= invRootL;
		n[1] *= invRootL;
		n[2] *= invRootL;
		d *= invRootL;
	}

	// Projected vector U = V - (V dot N)N
	float* OrthoProjectedVector(float x, float y, float z)
	{
		float u[3];
		float vDotN = n[0] * x + n[1] * y + n[2] * z;
		float vN[3] = { vDotN * n[0], vDotN * n[1], vDotN * n[2] };
		u[0] = x - vN[0];
		u[1] = y - vN[1];
		u[2] = z - vN[2];

		return u;
	}
};

struct Sphere
{
	float radius;
	float center[3];

	Sphere() { }
	Sphere(float r, const float c[3])
	{
		center[0] = c[0];
		center[1] = c[1];
		center[2] = c[2];
		radius = r;
	}
};

struct AABB
{
	float min[3];
	float max[3];

	AABB() { }
	AABB(float _min[3], float _max[3])
	{
		memcpy(min, _min, 3*sizeof(float));
		memcpy(max, _max, 3*sizeof(float));
	}
};