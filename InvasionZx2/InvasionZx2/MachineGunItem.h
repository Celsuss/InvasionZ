#pragma once
#include "PlayerPickupItem.h"

class MachineGunItem : public PlayerPickupItem{
public:
	MachineGunItem(sf::Vector2f pos);
	virtual ~MachineGunItem();
};