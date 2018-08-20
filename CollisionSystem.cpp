#include "CollisionSystem.h"


int CollisionSystem::SpherePlaneIntersect(const Plane& p, const Sphere& s) 
{
	// Plane needs to be normalized
	const float dist = s.center[0]*p.n[0] + s.center[1]*p.n[1] + s.center[2]*p.n[2] - p.d;
	// If sphere center within +/-radius from plane, plane intersects sphere
	return abs(dist) <= s.radius;
}


int CollisionSystem::AABBPlaneIntersect(const Plane& p, const AABB& b)
{
	const float c[3] = { (b.max[0] + b.min[0]) * 0.5f, (b.max[1] + b.min[1]) * 0.5f, (b.max[2] + b.min[2]) * 0.5f }; 
	const float e[3] = { b.max[0] - c[0], b.max[1] - c[1], b.max[2] - c[2] }; // Compute positive extents

	// Compute the projection interval radius of b onto L(t) = b.c + t * p.n
	const float r = e[0] * abs(p.n[0]) + e[1] * abs(p.n[1]) + e[2] * abs(p.n[2]);
	// Compute distance of box center from plane
	const float s = p.n[0]*c[0] + p.n[1]*c[1] + p.n[2]*c[2] - p.d;
	// Intersection occurs when distance s falls within [-r,+r] interval
	return abs(s) <= r;
}

void CollisionSystem::HandlePlayerCollisions()
{
	const float nextPos[3] = {	m_pMap->GetPlayer()->GetPosition().x + m_pMap->GetPlayer()->GetWalkVelocity().x,
								m_pMap->GetPlayer()->GetPosition().y + m_pMap->GetPlayer()->GetWalkVelocity().y,
								m_pMap->GetPlayer()->GetPosition().z + m_pMap->GetPlayer()->GetWalkVelocity().z };
	const Sphere s = Sphere(PLAYER_RADIUS, nextPos);
	const std::vector<Q3MapPlane> planes = m_pMap->GetPlanes();
	const std::vector<Q3MapLeaf> leaves = m_pMap->GetLeaves();
	const std::vector<Q3MapBrush> brushes = m_pMap->GetBrushes();
	const std::vector<Q3MapLeafBrush> leafBrushes = m_pMap->GetLeafBrushes();
	const std::vector<Q3MapBrushSide> brushSides = m_pMap->GetBrushSides();
	int l = m_pMap->GetCurrentLeafPosition();

	if (l < 0)
		return;

	for (int i = 0; i < leaves[l].nleafbrushes; ++i)
	{
		const int f = i + leaves[l].leafbrush;

		for (int k = 0; k < brushes[leafBrushes[f].brush].nbrushsides; k++)
		{
			
			Plane p = Plane(planes[k + brushSides[brushes[leafBrushes[f].brush].brushside].plane].normal, planes[k + brushSides[brushes[leafBrushes[f].brush].brushside].plane].dist);
			p.Normalize();

			if (CollisionSystem::SpherePlaneIntersect(p, s))
			{
			//	float* newSpeed = p.OrthoProjectedVector(m_pMap->GetPlayer()->GetWalkVelocity().x, m_pMap->GetPlayer()->GetWalkVelocity().y, m_pMap->GetPlayer()->GetWalkVelocity().z);				
				m_pMap->GetPlayer()->SetWalkVelocity(-m_pMap->GetPlayer()->GetWalkVelocity().x, -m_pMap->GetPlayer()->GetWalkVelocity().z);
			}		
		}
	}
}