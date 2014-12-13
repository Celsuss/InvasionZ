#pragma once
#include "AIState.h"
#include "SFML/System/Vector2.hpp"

class GridNode;

class HuntState : public AIState{
public:
	HuntState(bool aggressive = false);
	~HuntState();
	virtual void update(GameObject* gameObject, AIStateComponent* AIState);
	virtual void enterState();
	virtual void exitState();
private:
	void move(GameObject* gameObject);
	void changeState(AIStateComponent* AIState);

	sf::Vector2f m_TargetPos;
	bool m_IsAggressive;
};