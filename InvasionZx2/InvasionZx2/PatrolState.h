#pragma once
#include "AIState.h"
#include "SFML/System/Vector2.hpp"
#include <vector>

class HealthData;
class PositionData;
class MovementData;

class PatrolState : public AIState{
public:
	PatrolState(HealthData* healthData, PositionData* positionData, MovementData* movementData);
	~PatrolState();
	virtual void update(GameObject* gameObject, AIStateComponent* AIState);
	virtual void enterState();
	virtual void exitState();
private:
	void move(GameObject* gameObject, sf::Vector2f deltaPos);
	void setTargetPosition();
	bool isDamaged(GameObject* gameObject);

	sf::Vector2f m_TargetPosition;
	std::vector<sf::Vector2f*> m_Path;

	HealthData* m_HealthData;
	PositionData* m_PositionData;
	MovementData* m_MovementData;
};