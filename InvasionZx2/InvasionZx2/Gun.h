#pragma once
#include "Weapon.h"

class Gun : public Weapon{ 
public:
	Gun();
	virtual ~Gun();

	virtual bool addItem();

	virtual void shoot(GameObject* gameObject);
	virtual void fire(AmmoData* ammoData, int* currentAmmo, const int maxAmmo, sf::Vector2f pos, sf::Vector2f direction);
	virtual void fire(int* currentAmmo, const int maxAmmo, sf::Vector2f pos, sf::Vector2f direction);
};