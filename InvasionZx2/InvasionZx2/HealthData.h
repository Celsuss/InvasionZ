#pragma once
#include "Data.h"

class HealthData : public Data{
public:
	HealthData(float health);
	virtual ~HealthData();

	float* getHealth();
	float* getMaxHealth();
private:
	float m_Health;
	float m_MaxHealth;
};