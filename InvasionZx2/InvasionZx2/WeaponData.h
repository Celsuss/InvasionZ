/*
	Holds weapon data
*/

#pragma once
#include "Data.h"
#include "Weapon.h"
#include <string>
#include <vector>

class WeaponData : public Data{
public:
	typedef std::vector<Weapon*>WeaponVector;

	WeaponData();
	virtual ~WeaponData();
	void addWeapon(Weapon* weapon);
	void changeCurrentWeapon(int index);
	Weapon* getEquippedWeapon();
	int getWeaponVectorSize();

	Weapon* getWeapon(int index);

	template<typename w>
	w* getWeapon(std::string name){
		for (auto i = m_WeaponVector.begin(); i != m_WeaponVector.end(); i++){
			if ((*i)->getName() == name){
				return static_cast<w*>(*i);
			}
		}
		//std::cout << "ERROR: " + name + " not found!";
		return nullptr;
	}
private:
	WeaponVector m_WeaponVector;
	int m_CurrentWeapon;
};