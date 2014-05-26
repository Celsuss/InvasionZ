#include "MovementData.h"

MovementData::MovementData(float movementSpeed){
	m_MovementSpeed = movementSpeed;
	m_Direction = sf::Vector2f(0, 0);
	m_Name = "MovementData";
}

MovementData::MovementData(float movementSpeed, sf::Vector2f rotation){
	m_MovementSpeed = movementSpeed;
	m_Direction = rotation;
	m_Name = "MovementData";
}

MovementData::~MovementData(){}

float* MovementData::getMovementSpeed(){
	return &m_MovementSpeed;
}

sf::Vector2f* MovementData::getDirection(){
	return &m_Direction;
}