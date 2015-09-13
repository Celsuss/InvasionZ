/*
	Spawn a zombie at the game objects position after a set amount of time

	Data needed: PositionData
*/

#pragma once
#include "Component.h"
#include "SFML/System/Time.hpp"
#include "SFML/System/Clock.hpp"

class PositionData;

class SpawnerComponent : public Component{
public:
	SpawnerComponent(PositionData* positionData);
	virtual ~SpawnerComponent();
	void update(GameObject* gameObject);
private:
	GameObject* m_GameObject;
	sf::Time m_SpawnTime;
	sf::Clock m_Clock;

	PositionData* m_PositionData;
};