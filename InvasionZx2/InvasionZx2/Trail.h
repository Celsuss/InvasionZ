/*
	Trail gameobject, a trail for the zombie AI to help find the player. Despawns after a set amount of time
	Components used: KillAfterTimeComponent
	Data used: PositionData, SpriteData
*/

#pragma once
#include "GameObject.h"
#include "SFML/System/Vector2.hpp"

class Trail : public GameObject{
public:
	Trail(sf::Vector2f pos, Type type);
	virtual ~Trail();
	virtual void addCollision(GameObject* obj);
};

