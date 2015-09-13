/*
	Read player input for the player to shoot with equipped weapon
	Data needed: WeaponData
*/

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

//If shoot key is pressed then shoot with equipped weapon
void ShootComponent::update(GameObject* gameObject){
	if (InputManager::isShootKeyDown())
		m_WeaponData->getEquippedWeapon()->shoot(gameObject);
}