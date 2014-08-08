#pragma once
#include "GameObject.h"
#include "SFML/System/Vector2.hpp"

class Trail : public GameObject{
public:
	Trail(sf::Vector2f pos, Type type);
	virtual ~Trail();
};

