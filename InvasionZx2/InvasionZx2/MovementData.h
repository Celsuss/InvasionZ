#pragma once
#include "Data.h"
#include "SFML/System/Vector2.hpp"

class MovementData : public Data{
public:
	MovementData(float movementSpeed);
	MovementData(float movementSpeed, sf::Vector2f rotation);
	virtual ~MovementData();

	float* getMovementSpeed();
	sf::Vector2f* getDirection();
private:
	float m_MovementSpeed;
	sf::Vector2f m_Direction;
};