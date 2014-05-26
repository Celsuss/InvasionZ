#pragma once
#include "Component.h"

class GameObject;

class ShootComponent : public Component{
public:
	ShootComponent();
	virtual ~ShootComponent();
	virtual void update(GameObject* gameObject);
};

