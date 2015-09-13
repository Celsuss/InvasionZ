/*
	Read player input to change player weapon
	Data needed: WeaponData
*/

#pragma once
#include "Component.h"

class WeaponData;

class ChangeWeaponComponent : public Component{
public:
	ChangeWeaponComponent(WeaponData* weaponData);
	~ChangeWeaponComponent();
	virtual void update(GameObject* gameObject);
private:
	void changeWeapon();

	WeaponData* m_WeaponData;
};