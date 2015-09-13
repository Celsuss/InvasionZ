/*
	Component that moves the GameObject
	Data needed: SpriteData, PositionData, MovementData, IsPlayerData
*/

#include "MovementData.h"
#include "CollisionDetectionManager.h"
#include "MoveComponent.h"
#include "PositionData.h"
#include "InputManager.h"
#include "IsPlayerData.h"
#include "TimeManager.h"
#include "SpriteData.h"
#include "Player.h"
#include <iostream>

MoveComponent::MoveComponent(SpriteData* spriteData, PositionData* positionData, MovementData* movementData, IsPlayerData* isPlayerdata){
	m_Name = "MoveComponent";

	m_SpriteData = spriteData;
	m_PositionData = positionData;
	m_MovementData = movementData;
	m_IsPlayerData = isPlayerdata;
}

MoveComponent::~MoveComponent(){}

void MoveComponent::update(GameObject* gameObject){
	if (m_IsPlayerData != nullptr)
		checkInput(gameObject);
	else
		moveObject(gameObject);

	//Add to collision detection vector
	CollisionDetectionManager::addGameObject(gameObject);
}

//Check input to see if the player wants to move forward or backwards
void MoveComponent::checkInput(GameObject* gameObject){
	if (InputManager::isUpKeyDown())
		movePlayer(gameObject, 1);
	else if (InputManager::isDownKeyDown())
		movePlayer(gameObject, -1);
}

//Moves the player object
void MoveComponent::movePlayer(GameObject* gameObject, int direction){
	sf::Vector2f* pos = m_PositionData->getPosition();
	sf::Vector2f* rotation = m_MovementData->getDirection();
	float* speed = m_MovementData->getMovementSpeed();
	float deltaTime = TimeManager::getDeltaTime();

	pos->x += (*speed * rotation->x * deltaTime) * direction;
	pos->y += (*speed * rotation->y * deltaTime) * direction;

	m_SpriteData->getSprite()->setPosition(*pos);
}

//Moves all non player objects
void MoveComponent::moveObject(GameObject* gameObject){
	sf::Vector2f* pos = m_PositionData->getPosition();
	sf::Vector2f* rotation = m_MovementData->getDirection();
	float* speed = m_MovementData->getMovementSpeed();
	float deltaTime = TimeManager::getDeltaTime();

	pos->x += *speed * rotation->x * deltaTime;
	pos->y += *speed * rotation->y * deltaTime;

	m_SpriteData->getSprite()->setPosition(*pos);
}