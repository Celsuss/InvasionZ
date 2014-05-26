#include "RotateToMouseComponent.h"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Mouse.hpp"
#include "MovementData.h"
#include "GraphicManager.h"
#include "SpriteData.h"
#include "Player.h"
#include <iostream>

RotateToMouseComponent::RotateToMouseComponent(){
	m_Name = "RotateToMouseComponent";
}

RotateToMouseComponent::~RotateToMouseComponent(){}

void RotateToMouseComponent::update(GameObject* gameObject){
	rotateSprite(gameObject->getData<SpriteData>("SpriteData"));
	rotateMovement(gameObject->getData<SpriteData>("SpriteData"), gameObject->getData<MovementData>("MovementData"));
}

void RotateToMouseComponent::rotateSprite(SpriteData* spriteData){
	sf::Vector2f pos1 = spriteData->getSprite()->getPosition();

	sf::Vector2f pos2;
	pos2.x = sf::Mouse::getPosition().x - GraphicManager::getWindow()->getPosition().x;
	pos2.y = sf::Mouse::getPosition().y - GraphicManager::getWindow()->getPosition().y - mouseYPosError;

	float angle = std::atan2(pos1.y - pos2.y, pos1.x - pos2.x)*convertToDegrees;


	spriteData->getSprite()->setRotation(angle);
}

void RotateToMouseComponent::rotateMovement(SpriteData* spriteData, MovementData* movementData){
	sf::Vector2f pos1 = spriteData->getSprite()->getPosition();
	sf::Vector2f pos2 = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*GraphicManager::getWindow()));

	sf::Vector2f deltaPos = pos2 - pos1;

	float deltaDist = std::sqrt(deltaPos.x * deltaPos.x + deltaPos.y * deltaPos.y);
	deltaPos.x = deltaPos.x * (1 / deltaDist);
	deltaPos.y = deltaPos.y * (1 / deltaDist);

	*movementData->getDirection() = deltaPos;
}