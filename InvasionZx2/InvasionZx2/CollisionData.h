#pragma once
#include "Data.h"
class CollisionData : public Data{
public:
	enum CollisionShape{
		Circle,
		Box
	};

	CollisionData(CollisionShape shape, bool isPhysicalCollider = true);
	virtual ~CollisionData();

	CollisionShape* getShape();
	bool getIsPhysicalCollider();
private:
	CollisionShape m_Shape;
	bool m_IsPhysicalCollider;
};