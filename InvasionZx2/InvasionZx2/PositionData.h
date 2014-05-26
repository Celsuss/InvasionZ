#pragma once
#include "Data.h"
#include "SFML/System/Vector2.hpp"

class PositionData : public Data{
public:
	PositionData(sf::Vector2f pos);
	virtual ~PositionData();

	sf::Vector2f* getPosition();
private:
	sf::Vector2f* m_Position;
};

