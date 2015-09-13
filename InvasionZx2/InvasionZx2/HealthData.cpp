/*
	Holds health data
*/

#include "HealthData.h"

HealthData::HealthData(float health){
	m_Health = health;
	m_MaxHealth = health;
	m_Name = "HealthData";
}

HealthData::~HealthData(){}

float* HealthData::getHealth(){
	return &m_Health;
}

float* HealthData::getMaxHealth(){
	return &m_MaxHealth;
}