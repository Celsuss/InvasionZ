#pragma once
#include "AIState.h"
#include "SFML/System/Vector2.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/System/Time.hpp"

class HitState : public AIState{
public:
	HitState();
	virtual ~HitState();
	virtual void update(GameObject* gameObject, AIStateComponent* AIState);
	virtual void enterState();
	virtual void exitState();
private:
	void attack(GameObject* gameObject);

	float m_AttackRange;
	float m_AttackDamage;

	sf::Time m_AttackCooldown;
	sf::Clock m_AttackClock;
};