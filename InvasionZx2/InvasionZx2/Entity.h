#pragma once
#include "GameObject.h"

class Entity : public GameObject{
public:
	Entity();
	virtual ~Entity();
	virtual void update() = 0;
};

