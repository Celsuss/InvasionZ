#include "WeaponData.h"
#include "Gun.h"

WeaponData::WeaponData(){
	m_Name = "WeaponData";
	m_CurrentWeapon = 0;
	Gun* gun = new Gun();
	addWeapon(gun);
}

WeaponData::~WeaponData(){}

void WeaponData::addWeapon(Weapon* weapon){
	m_WeaponVector.push_back(weapon);
}

Weapon* WeaponData::getEquippedWeapon(){
	return m_WeaponVector[m_CurrentWeapon];
}