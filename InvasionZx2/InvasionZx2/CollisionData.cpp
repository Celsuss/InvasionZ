/*
	Holds collision data
*/

#include "CollisionData.h"

CollisionData::CollisionData(CollisionShape shape, bool isPhysicalCollider){
	m_Name = "CollisionData";
	m_IsPhysicalCollider = isPhysicalCollider;
	m_Shape = shape;
}

CollisionData::~CollisionData(){}

CollisionData::CollisionShape* CollisionData::getShape(){
	return &m_Shape;
}

bool CollisionData::getIsPhysicalCollider(){
	return m_IsPhysicalCollider;
}