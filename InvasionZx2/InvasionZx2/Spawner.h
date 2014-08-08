#pragma once
#include "GameObject.h"

class Spawner : public GameObject{
public:
	Spawner(sf::Vector2f pos, Type type);
	virtual ~Spawner();
};

