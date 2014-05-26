#include "ShootComponent.h"
#include "WeaponData.h"
#include "Player.h"
#include "Weapon.h"

ShootComponent::ShootComponent(){
	m_Name = "ShootComponent";
}

ShootComponent::~ShootComponent(){}

void ShootComponent::update(GameObject* gameObject){
	WeaponData* weaponData = gameObject->getData<WeaponData>("WeaponData");
	Weapon* weapon = weaponData->getEquippedWeapon();
	weapon->shoot(gameObject);
}