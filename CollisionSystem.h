#pragma once

#include "XWorldMap.h"
#include "Primitives.h"


class CollisionSystem
{
private:
	XWorldMap*	m_pMap;
public:
	CollisionSystem() { }
	CollisionSystem(XWorldMap* map) {
		m_pMap = map;
	}

	~CollisionSystem() {}
	
	static int SpherePlaneIntersect(const Plane& p, const Sphere& s);
	static int AABBPlaneIntersect(const Plane& p, const AABB& b);
	void HandlePlayerCollisions();
	void HandleEntityCollisions();
};

