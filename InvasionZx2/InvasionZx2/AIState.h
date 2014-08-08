#pragma once

class GameObject;

class AIState{
public:
	AIState();
	virtual ~AIState();
	virtual void update(GameObject* gameObject) = 0;
	virtual void enterState() = 0;
	virtual void exitState() = 0;
};