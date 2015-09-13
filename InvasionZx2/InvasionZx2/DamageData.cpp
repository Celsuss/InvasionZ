/*
	Holds damage data
*/

#include "DamageData.h"

DamageData::DamageData(float damage){
	m_Name = "DamageData";
	m_Damage = damage;
}

DamageData::~DamageData(){}

float DamageData::getDamage()const{
	return m_Damage;
}