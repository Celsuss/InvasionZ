/*
	Spawn a trail gameobject at the gameobjects position after a set amount of time
	Data needed: PositionData
*/

#pragma once
#include "Component.h"
#include "SFML/System/Clock.hpp"

class PositionData;

class SpawnTrailComponent : public Component{
public:
	SpawnTrailComponent(PositionData* positionData);
	virtual ~SpawnTrailComponent();
	virtual void update(GameObject* gameObject);
private:
	sf::Clock m_Clock;
	sf::Time m_SpawnTime;

	PositionData* m_PositionData;
};