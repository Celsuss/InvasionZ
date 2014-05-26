#include "PositionData.h"

PositionData::PositionData(sf::Vector2f pos){
	m_Position = new sf::Vector2f(pos);
	m_Name = "PositionData";
}

PositionData::~PositionData(){}

sf::Vector2f* PositionData::getPosition(){
	return m_Position;
}