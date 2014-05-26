#pragma once
#include "GameObject.h"

class Bullet : public GameObject{
public:
	Bullet(sf::Vector2f pos, sf::Vector2f direction);
	virtual ~Bullet();
	virtual void update();
};