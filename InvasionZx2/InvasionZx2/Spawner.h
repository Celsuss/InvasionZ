/*
	Spawner gameobject, spawns zombies at it's location after set amount of time
	Components used: SpawnerComponent
	Data used: PositionData, SpriteData
*/

#pragma once
#include "GameObject.h"

class Spawner : public GameObject{
public:
	Spawner(sf::Vector2f pos, Type type);
	virtual ~Spawner();
	virtual void addCollision(GameObject* obj);
};