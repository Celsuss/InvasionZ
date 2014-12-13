#pragma once

class GameObject;
class AIStateComponent;

class AIState{
public:
	AIState();
	virtual ~AIState();
	virtual void update(GameObject* gameObject, AIStateComponent* AIState) = 0;
	virtual void enterState() = 0;
	virtual void exitState() = 0;
};