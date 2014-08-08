#pragma once
#include "AIState.h"
#include "SFML/System/Vector2.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/System/Time.hpp"

class AttackState : public AIState{
public:
	AttackState();
	virtual ~AttackState();
	virtual void update(GameObject* gameObject);
	virtual void enterState();
	virtual void exitState();
private:
	void move(GameObject* gameObject, sf::Vector2f deltaPos);
	void stopMoving(GameObject* gameObject);
	void attack(GameObject* gameObject);

	float m_AttackDamage;

	sf::Time m_AttackCooldown;
	sf::Clock m_AttackClock;
};

