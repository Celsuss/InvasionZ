#include "HealthPotion.h"
#include "EntityFactory.h"
#include "HealthData.h"
#include "Player.h"

HealthPotion::HealthPotion(){
	m_HealHealth = 20;
}

HealthPotion::~HealthPotion(){}

bool HealthPotion::addItem(){
	Player* player = EntityFactory::getPlayer();
	HealthData* healthData = player->getData<HealthData>("HealthData");

	if (*healthData->getHealth() < *healthData->getMaxHealth()){
		*healthData->getHealth() += m_HealHealth;

		if (*healthData->getHealth() > *healthData->getMaxHealth())
			*healthData->getHealth() = *healthData->getMaxHealth();
		return true;
	}
	return false;
}