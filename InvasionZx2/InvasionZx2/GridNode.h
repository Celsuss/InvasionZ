#pragma once
#include "SFML/System/Vector2.hpp"

class SpriteData;

class GridNode{
public:
	GridNode(sf::Vector2f pos);
	~GridNode();
	void draw();
	SpriteData* getSpriteData();
private:
	SpriteData* m_SpriteData;
};