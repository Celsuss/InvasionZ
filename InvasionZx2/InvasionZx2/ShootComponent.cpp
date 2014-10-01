#include "ShootComponent.h"
#include "InputManager.h"
#include "WeaponData.h"
#include "AmmoData.h"
#include "Player.h"
#include "Weapon.h"

ShootComponent::ShootComponent(WeaponData* weaponData){
	m_Name = "ShootComponent";

	m_WeaponData = weaponData;
}

ShootComponent::~ShootComponent(){}

void ShootComponent::update(GameObject* gameObject){
	if (InputManager::isShootKeyDown())
		m_WeaponData->getEquippedWeapon()->shoot(gameObject);
}