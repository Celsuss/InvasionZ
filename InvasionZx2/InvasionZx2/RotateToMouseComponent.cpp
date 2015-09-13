/*
	Rotate the gameobjects moving direction and sprite towards the mouse cursor
	Data needed: SpriteData MovementData
*/

#include "RotateToMouseComponent.h"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Mouse.hpp"
#include "MovementData.h"
#include "GraphicManager.h"
#include "SpriteData.h"
#include "Player.h"
#include <iostream>

RotateToMouseComponent::RotateToMouseComponent(SpriteData* spriteData, MovementData* movementData){
	m_Name = "RotateToMouseComponent";

	m_SpriteData = spriteData;
	m_MovementData = movementData;
}

RotateToMouseComponent::~RotateToMouseComponent(){}

void RotateToMouseComponent::update(GameObject* gameObject){
	rotateSprite();
	rotateMovement();
}

//Rotate the sprite towards the gameobjects direction
void RotateToMouseComponent::rotateSprite(){
	sf::Vector2f pos1 = m_SpriteData->getSprite()->getPosition();

	sf::Vector2f pos2;
	pos2.x = sf::Mouse::getPosition().x - GraphicManager::getWindow()->getPosition().x;
	pos2.y = sf::Mouse::getPosition().y - GraphicManager::getWindow()->getPosition().y - mouseYPosError;

	float angle = std::atan2(pos1.y - pos2.y, pos1.x - pos2.x)*convertToDegrees;

	m_SpriteData->getSprite()->setRotation(angle);
}

//Rotate the gameobjects moving direction
void RotateToMouseComponent::rotateMovement(){
	sf::Vector2f pos1 = m_SpriteData->getSprite()->getPosition();
	sf::Vector2f pos2 = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*GraphicManager::getWindow()));

	sf::Vector2f deltaPos = pos2 - pos1;

	float deltaDist = std::sqrt(deltaPos.x * deltaPos.x + deltaPos.y * deltaPos.y);
	deltaPos.x = deltaPos.x * (1 / deltaDist);
	deltaPos.y = deltaPos.y * (1 / deltaDist);

	*m_MovementData->getDirection() = deltaPos;
}