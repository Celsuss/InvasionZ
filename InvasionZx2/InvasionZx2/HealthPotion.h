#pragma once
#include "Item.h"

class HealthPotion : public Item{
public:
	HealthPotion();
	virtual ~HealthPotion();
	virtual bool addItem();
private:
	float m_HealHealth;
};