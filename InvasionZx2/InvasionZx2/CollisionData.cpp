#include "CollisionData.h"

CollisionData::CollisionData(CollisionShape shape){
	m_Name = "CollisionData";
	m_Shape = shape;
}

CollisionData::~CollisionData(){}

CollisionData::CollisionShape* CollisionData::getShape(){
	return &m_Shape;
}