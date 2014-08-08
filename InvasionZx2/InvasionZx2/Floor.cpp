#include "Floor.h"
#include "CollisionData.h"
#include "GraphicManager.h"
#include "SFML/System/Vector2.hpp"

Floor::Floor(std::string texture, Type type){
	m_Type = type;

	m_DataVector.push_back(new SpriteData(texture, SpriteData::Background));
}

Floor::~Floor(){}