#pragma once
#include "GameObject.h"
#include "RotateToMouseComponent.h"
#include "SFML/System/Vector2.hpp"

class Player : public GameObject{
public:
	Player(sf::Vector2f pos);
	Player(float x, float y);
	virtual ~Player();
	virtual void update();
private:
	
};