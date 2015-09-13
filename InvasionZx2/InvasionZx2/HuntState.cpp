#include "HuntState.h"
#include "EntityFactory.h"
#include "PatrolState.h"
#include "GameObject.h"
#include "Pathfinder.h"
#include "Player.h"
#include "Shared.h"
#include "Debug.h"

#include "AIStateComponent.h"

HuntState::HuntState(bool aggressive){
	m_IsAggressive = aggressive;
	//m_TargetNode = nullptr;
}

HuntState::~HuntState(){}

void HuntState::update(GameObject* gameObject, AIStateComponent* AIState){
	sf::Vector2f pos1 = *gameObject->getData<PositionData>("PositionData")->getPosition();
	sf::Vector2f pos2 = *EntityFactory::getPlayer()->getData<PositionData>("PositionData")->getPosition();
	move(gameObject);
	changeState(AIState);

	Debug::drawLine(pos1, pos2, sf::Color::Red);
}

void HuntState::enterState(){}

void HuntState::exitState(){}

void HuntState::move(GameObject* gameObject){
	sf::Vector2f pos1 = *gameObject->getData<PositionData>("PositionData")->getPosition();
	sf::Vector2f pos2 = *EntityFactory::getPlayer()->getData<PositionData>("PositionData")->getPosition();
	m_TargetPos = *Pathfinder::findPath(pos1, pos2).back();

	sf::Vector2f move = Shared::normalizeVector(m_TargetPos - pos1);

	*gameObject->getData<MovementData>("MovementData")->getDirection() = sf::Vector2f(move);
}

void HuntState::changeState(AIStateComponent* AIState){
	/*if (m_IsAggressive)
		return;

	if (!AIState->isInLineOfSight(EntityFactory::getPlayer())){
		AIState->changeState(new PatrolState());
	}*/
}