#pragma once
#include "PlayerPickupItem.h"

class HealthPotionItem : public PlayerPickupItem{
public:
	HealthPotionItem(sf::Vector2f pos);
	virtual ~HealthPotionItem();
};