/*
	Floor object, only a decorative gameobject
	Components used:
	Data used: SpriteData
*/

#include "Floor.h"
#include "CollisionData.h"
#include "GraphicManager.h"
#include "SFML/System/Vector2.hpp"

Floor::Floor(std::string texture, Type type){
	m_Type = type;

	SpriteData* spriteData = new SpriteData(texture, SpriteData::Background);
	m_DataMap[spriteData->getName()] = std::shared_ptr<SpriteData>(spriteData);

	setDrawableData();
}

Floor::~Floor(){}

void Floor::addCollision(GameObject* obj){}