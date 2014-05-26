#include "MovementData.h"
#include "MoveComponent.h"
#include "PositionData.h"
#include "InputManager.h"
#include "IsPlayerData.h"
#include "TimeManager.h"
#include "SpriteData.h"
#include "Player.h"
#include <iostream>

MoveComponent::MoveComponent(){
	m_Name = "MoveComponent";
}

MoveComponent::~MoveComponent(){}

void MoveComponent::update(GameObject* gameObject){
	if (gameObject->getData<IsPlayerData>("IsPlayerData") != nullptr)
		movePlayer(gameObject);
	else
		moveObject(gameObject);
}

void MoveComponent::movePlayer(GameObject* gameObject){
	if (InputManager::isUpKeyDown()){
		moveObject(gameObject);
	}
}

void MoveComponent::moveObject(GameObject* gameObject){
	PositionData* posData = gameObject->getData<PositionData>("PositionData");
	MovementData* speedData = gameObject->getData<MovementData>("MovementData");
	SpriteData* spriteData = gameObject->getData<SpriteData>("SpriteData");

	sf::Vector2f* pos = posData->getPosition();
	sf::Vector2f* rotation = speedData->getDirection();
	float* speed = speedData->getMovementSpeed();
	float deltaTime = TimeManager::getDeltaTime();

	pos->x += *speed * rotation->x * deltaTime;
	pos->y += *speed * rotation->y * deltaTime;

	spriteData->getSprite()->setPosition(*pos);
}