#include "AmmoData.h"

AmmoData::AmmoData(){
	m_Name = "AmmoData";
	m_AmmoMap.insert(std::pair<std::string, int>("Gun", 10));
	m_MaxAmmoMap.insert(std::pair<std::string, int>("Gun", 20));

	m_AmmoMap.insert(std::pair<std::string, int>("MachineGun", 10));
	m_MaxAmmoMap.insert(std::pair<std::string, int>("MachineGun", 20));
}

AmmoData::~AmmoData(){}

int* AmmoData::getAmmo(std::string weapon){
	for (auto i = m_AmmoMap.begin(); i != m_AmmoMap.end(); i++){
		if (i->first == weapon){
			return &i->second;
		}
	}
}

int AmmoData::getMaxAmmo(std::string weapon)const{
	for (auto i = m_MaxAmmoMap.begin(); i != m_MaxAmmoMap.end(); i++){
		if (i->first == weapon){
			return i->second;
		}
	}
}