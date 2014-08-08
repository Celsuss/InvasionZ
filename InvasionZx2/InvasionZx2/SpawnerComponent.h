#pragma once
#include "Component.h"
#include "SFML/System/Time.hpp"
#include "SFML/System/Clock.hpp"

class SpawnerComponenter : public Component{
public:
	SpawnerComponenter(GameObject* gameObject);
	SpawnerComponenter();
	virtual ~SpawnerComponenter();
	void update(GameObject* gameObject);
private:
	GameObject* m_GameObject;
	sf::Time m_SpawnTime;
	sf::Clock m_Clock;
};