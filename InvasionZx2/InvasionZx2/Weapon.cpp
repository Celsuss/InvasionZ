#include "Weapon.h"
#include "AmmoData.h"
#include <string>

Weapon::Weapon(){}

Weapon::~Weapon(){}

void Weapon::reload(AmmoData* ammoData, std::string name){
	int* ammo = ammoData->getAmmo(name);
	int maxAmmo = ammoData->getMaxAmmo(name);

	*ammo = maxAmmo;
}

std::string Weapon::getName() const{
	return m_Name;
}