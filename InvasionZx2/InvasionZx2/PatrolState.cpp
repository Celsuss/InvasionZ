#include "PatrolState.h"
#include "AIStateComponent.h"
#include "PositionData.h"
#include "GridManager.h"
#include "AttackState.h"
#include "Pathfinder.h"
#include "GameObject.h"
#include "PositionData.h"
#include "MovementData.h"
#include "HealthData.h"
#include "GridNode.h"
#include "Shared.h"
#include "Debug.h"

#include "HuntState.h"

const float CONTACT = 31;

PatrolState::PatrolState(HealthData* healthData, PositionData* positionData, MovementData* movementData):
m_HealthData(healthData),
m_PositionData(positionData),
m_MovementData(movementData){}

PatrolState::~PatrolState(){}

void PatrolState::update(GameObject* gameObject, AIStateComponent* AIState){
	/*if (isDamaged(gameObject)){
		AIState->changeState(new HuntState(true));
		return;
	}*/

	sf::Vector2f pos = *m_PositionData->getPosition();
	sf::Vector2f deltaPos = m_TargetPosition - pos;
	float length = std::sqrt((deltaPos.x * deltaPos.x) + (deltaPos.y * deltaPos.y));

	if (length > CONTACT){
		deltaPos = m_NextStepPosition - pos;
		length = std::sqrt((deltaPos.x * deltaPos.x) + (deltaPos.y * deltaPos.y));
		if (length > CONTACT)
			move(gameObject, deltaPos);
		else
			m_NextStepPosition = Pathfinder::findPath(*m_PositionData->getPosition(), m_TargetPosition);
	}
	else
		setTargetPosition();

	Debug::drawLine(pos, m_TargetPosition, sf::Color::Green);
}

void PatrolState::enterState(){
	setTargetPosition();
}

void PatrolState::exitState(){}

void PatrolState::move(GameObject* gameObject, sf::Vector2f deltaPos){
	sf::Vector2f pos = *m_PositionData->getPosition();
	sf::Vector2f move = Shared::normalizeVector(m_NextStepPosition - pos);

	*m_MovementData->getDirection() = sf::Vector2f(move);
}

void PatrolState::setTargetPosition(){
	m_TargetPosition = *GridManager::getRandomNodeWithinRange(*m_PositionData->getPosition(), 9)->getPositionData()->getPosition();
	m_NextStepPosition = Pathfinder::findPath(*m_PositionData->getPosition(), m_TargetPosition);
}

bool PatrolState::isDamaged(GameObject* gameObject){
	if (*m_HealthData->getMaxHealth() > *m_HealthData->getHealth())
		return true;
	
	return false;
}