#include "ChangeWeaponComponent.h"
#include "InputManager.h"
#include "WeaponData.h"
#include "Player.h"

ChangeWeaponComponent::ChangeWeaponComponent(WeaponData* weaponData){
	m_Name = "ChangeWeaponComponent";
	m_WeaponData = weaponData;
}

ChangeWeaponComponent::~ChangeWeaponComponent(){}

void ChangeWeaponComponent::update(GameObject* gameObject){
	changeWeapon();
}

void ChangeWeaponComponent::changeWeapon(){
	if (InputManager::isOneKeyPressed()){
		m_WeaponData->changeCurrentWeapon(1);
	}
	else if (InputManager::isTwoKeyPressed()){
		m_WeaponData->changeCurrentWeapon(2);
	}
	else if (InputManager::isThreeKeyPressed()){
		m_WeaponData->changeCurrentWeapon(3);
	}
	else if (InputManager::isFourKeyPressed()){
		m_WeaponData->changeCurrentWeapon(4);
	}
	else if (InputManager::isFiveKeyPressed()){
		m_WeaponData->changeCurrentWeapon(5);
	}
	else if (InputManager::isSixKeyPressed()){
		m_WeaponData->changeCurrentWeapon(6);
	}
	else if (InputManager::isSevenKeyPressed()){
		m_WeaponData->changeCurrentWeapon(7);
	}
	else if (InputManager::isEightKeyPressed()){
		m_WeaponData->changeCurrentWeapon(8);
	}
	else if (InputManager::isNineKeyPressed()){
		m_WeaponData->changeCurrentWeapon(9);
	}
}