#include "Floor.h"
#include "GraphicManager.h"
#include "SFML/System/Vector2.hpp"

Floor::Floor(std::string texture) :
m_SpriteData(texture){}

Floor::~Floor(){}

void Floor::update(){
	GraphicManager::draw(&m_SpriteData);
}