#pragma once
#include "Component.h"

class AIState;

class AIStateComponent : public Component{
public:
	AIStateComponent(AIState* startingState, AIState* globalState = nullptr);
	virtual ~AIStateComponent();
	virtual void update(GameObject* gameObject);

	void changeState(AIState* state);
	bool isInLineOfSight(GameObject* gameObject);
private:
	AIState* m_GlobalState;
	AIState* m_ActiveState;
	AIState* m_PreviousState;
};