#pragma once
#include "Item.h"
#include <string>
#include <SFML/System/Vector2.hpp>

class GameObject;
class AmmoData;

class Weapon : public Item{
public:
	Weapon();
	virtual ~Weapon();

	virtual bool addItem() = 0;

	virtual void shoot(GameObject* gameObject) = 0;
	virtual void fire(AmmoData* ammoData, int* currentAmmo, const int maxAmmo, sf::Vector2f pos, sf::Vector2f direction) = 0;
	virtual void fire(int* currentAmmo, const int maxAmmo, sf::Vector2f pos, sf::Vector2f direction) = 0;
	void reload(AmmoData* ammoData, std::string);

	std::string getName() const;
	std::string m_Name;
};