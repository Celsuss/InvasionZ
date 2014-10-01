#pragma once
#include "Component.h"

class WeaponData;
class SpriteData;
class PositionData;
class MovementData;

class ChangeWeaponComponent : public Component{
public:
	ChangeWeaponComponent(WeaponData* weaponData);
	~ChangeWeaponComponent();
	virtual void update(GameObject* gameObject);
private:
	void changeWeapon();

	WeaponData* m_WeaponData;
};