#include "HitState.h"
#include "Player.h"
#include "GameObject.h"
#include "HealthData.h"
#include "PositionData.h"
#include "EntityFactory.h"

HitState::HitState(){
	m_AttackClock.restart();
	m_AttackCooldown = sf::seconds(1);
	m_AttackDamage = 10;
	m_AttackRange = 32;
}

HitState::~HitState(){}

void HitState::update(GameObject* gameObject, AIStateComponent* AIState){
	sf::Vector2f pos1 = *gameObject->getData<PositionData>("PositionData")->getPosition();
	sf::Vector2f pos2 = *EntityFactory::getInstance()->getPlayer()->getData<PositionData>("PositionData")->getPosition();
	sf::Vector2f deltaPos = pos2 - pos1;
	float length = std::sqrt((deltaPos.x * deltaPos.x) + (deltaPos.y * deltaPos.y));

	if (length <= m_AttackRange)
		attack(gameObject);
}

void HitState::enterState(){}

void HitState::exitState(){}

void HitState::attack(GameObject* gameObject){
	if (m_AttackClock.getElapsedTime().asSeconds() > m_AttackCooldown.asSeconds()){
		m_AttackClock.restart();

		float* playerHealth = EntityFactory::getInstance()->getPlayer()->getData<HealthData>("HealthData")->getHealth();
		*playerHealth -= m_AttackDamage;
	}
}