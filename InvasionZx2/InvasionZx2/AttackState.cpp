#include "AttackState.h"
#include "AIStateComponent.h"
#include "EntityFactory.h"
#include "PositionData.h"
#include "GameObject.h"
#include "HealthData.h"
#include "Player.h"
#include "Shared.h"
#include "Debug.h"

const float CONTACT = 31;

AttackState::AttackState(){}

AttackState::~AttackState(){}

void AttackState::update(GameObject* gameObject, AIStateComponent* AIState){
	sf::Vector2f pos1 = *gameObject->getData<PositionData>("PositionData")->getPosition();
	//sf::Vector2f pos2 = *EntityFactory::getInstance()->m_PlayerPtr->getData<PositionData>("PositionData")->getPosition();
	sf::Vector2f pos2 = *EntityFactory::getInstance()->getPlayer()->getData<PositionData>("PositionData")->getPosition();
	sf::Vector2f deltaPos = pos2 - pos1;
	float length = std::sqrt((deltaPos.x * deltaPos.x) + (deltaPos.y * deltaPos.y));

	if (length > CONTACT)
		move(gameObject, deltaPos);
	else{
		stopMoving(gameObject);
	}

	Debug::drawLine(pos1, pos2, sf::Color::Red);
}

void AttackState::enterState(){}

void AttackState::exitState(){}

void AttackState::move(GameObject* gameObject, sf::Vector2f deltaPos){
	deltaPos = Shared::normalizeVector(deltaPos);
	*gameObject->getData<MovementData>("MovementData")->getDirection() = sf::Vector2f(deltaPos);
}

void AttackState::stopMoving(GameObject* gameObject){
	*gameObject->getData<MovementData>("MovementData")->getDirection() = sf::Vector2f(0,0);
}