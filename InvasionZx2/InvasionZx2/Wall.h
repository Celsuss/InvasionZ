#pragma once
#include "GameObject.h"
#include "SpriteData.h"
#include "PositionData.h"
#include "SFML/System/Vector2.hpp"

#include "PositionData.h"
#include "SpriteData.h"

class Wall : public GameObject{
public:
	Wall(sf::Vector2f pos, float width, float height);
	Wall(float x, float y, float width, float height);
	virtual ~Wall();
	virtual void update();
private:
	PositionData m_PositionData;
	SpriteData m_SpriteData;
};