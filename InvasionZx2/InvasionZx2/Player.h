#pragma once
#include "GameObject.h"
#include "RotateToMouseComponent.h"
#include "SFML/System/Vector2.hpp"

class Player : public GameObject{
public:
	Player(sf::Vector2f pos, Type type);
	virtual ~Player();
	virtual void addCollision(GameObject* obj);
};