/*
	Kills the gameobject after a set amount of time
	Data needed:
*/

#pragma once
#include "Component.h"
#include "SFML/System/Clock.hpp"

class GmaeObject;

class KillAfterTimeComponent : public Component{
public:
	KillAfterTimeComponent(sf::Time lifeTime);
	virtual ~KillAfterTimeComponent();
	virtual void update(GameObject* gameObject);
private:
	sf::Clock m_Clock;
	sf::Time m_LifeTime;
};