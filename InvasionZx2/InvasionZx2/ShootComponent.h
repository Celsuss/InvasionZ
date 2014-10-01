#pragma once
#include "Component.h"

class GameObject;
class WeaponData;

class ShootComponent : public Component{
public:
	ShootComponent(WeaponData* weaponData);
	virtual ~ShootComponent();
	virtual void update(GameObject* gameObject);
private:
	WeaponData* m_WeaponData;
};