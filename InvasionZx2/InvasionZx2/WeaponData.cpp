#include "WeaponData.h"
#include "Gun.h"
#include "MachineGun.h"

WeaponData::WeaponData(){
	m_Name = "WeaponData";
	m_CurrentWeapon = 0;

	Gun* gun = new Gun();
	addWeapon(gun);

	//MachineGun* machineGun = new MachineGun();
	//addWeapon(machineGun);
}

WeaponData::~WeaponData(){}

void WeaponData::addWeapon(Weapon* weapon){
	m_WeaponVector.push_back(weapon);
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