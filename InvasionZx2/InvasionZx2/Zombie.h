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