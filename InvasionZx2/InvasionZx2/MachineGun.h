#pragma once
#include "Weapon.h"
#include "SFML/System/Time.hpp"
#include "SFML/System/Clock.hpp"

class MachineGun : public Weapon{
public:
	MachineGun();
	virtual ~MachineGun();

	virtual bool addItem();

	virtual void shoot(GameObject* gameObject);
	virtual void fire(AmmoData* ammoData, int* currentAmmo, const int maxAmmo, sf::Vector2f pos, sf::Vector2f direction);
	virtual void fire(int* currentAmmo, const int maxAmmo, sf::Vector2f pos, sf::Vector2f direction);
private:
	sf::Clock m_ReloadTimeClock;
	sf::Time m_ReloadTime;
};

