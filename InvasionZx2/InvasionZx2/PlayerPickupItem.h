#pragma once
#include "GameObject.h"

class PlayerPickupItem : public GameObject{
public:
	PlayerPickupItem();
	virtual ~PlayerPickupItem();
	virtual void addCollision(GameObject* obj);
};