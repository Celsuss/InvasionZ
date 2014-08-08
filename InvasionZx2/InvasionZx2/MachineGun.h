#pragma once
#include "Weapon.h"

class MachineGun : public Weapon{
public:
	MachineGun();
	virtual ~MachineGun();
	virtual void shoot(GameObject* gameObject);
	virtual void fire(AmmoData* ammoData, int* currentAmmo, const int maxAmmo, sf::Vector2f pos, sf::Vector2f direction);
	virtual void fire(int* currentAmmo, const int maxAmmo, sf::Vector2f pos, sf::Vector2f direction);
};

