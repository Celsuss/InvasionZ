#pragma once
#include "Data.h"
class CollisionData : public Data{
public:
	enum CollisionShape{
		Circle,
		Box
	};

	CollisionData(CollisionShape shape);
	virtual ~CollisionData();

	CollisionShape* getShape();
private:
	CollisionShape m_Shape;
};