/*
	Zombie gameobject, AI controlled and attack the player if seen or walk around the map. Can be killed by bullets
	Components used: HealthBarComponent, MoveComponent, AIStateComponent, RotateComponent
	Data used: MovementData, PositionData, SpriteData, CollisionData, HealthData
*/

#pragma once
#include "GameObject.h"
#include "LuaConfig.h"

class Zombie : public GameObject{
public:
	Zombie(sf::Vector2f pos, Type type);
	Zombie(LuaConfig config, Type type);
	Zombie(float x, float y);
	virtual ~Zombie();
	virtual void addCollision(GameObject* obj);
};