#pragma once
#include "GameObject.h"
#include "RotateToMouseComponent.h"
#include "SFML/System/Vector2.hpp"
#include "LuaConfig.h"

class Player : public GameObject{
public:
	Player(sf::Vector2f pos, Type type);
	Player(LuaConfig config, Type type);
	virtual ~Player();
	virtual void addCollision(GameObject* obj);
};