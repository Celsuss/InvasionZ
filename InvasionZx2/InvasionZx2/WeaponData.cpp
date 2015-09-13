/*
	Holds weapon data
*/

#include "WeaponData.h"
#include "MachineGun.h"
#include "Gun.h"
#include "GUI.h"

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

void WeaponData::changeCurrentWeapon(int index){
	index--;
	if (index < m_WeaponVector.size()){
		m_CurrentWeapon = index;
		GUI::setEquippedWeapon(m_WeaponVector[m_CurrentWeapon]->getName());
	}
}

Weapon* WeaponData::getEquippedWeapon(){
	return m_WeaponVector[m_CurrentWeapon];
}

int WeaponData::getWeaponVectorSize(){
	return m_WeaponVector.size();
}

Weapon* WeaponData::getWeapon(int index){
	return m_WeaponVector[index];
}