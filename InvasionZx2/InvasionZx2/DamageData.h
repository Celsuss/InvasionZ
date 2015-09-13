/*
	Holds damage data
*/

#pragma once
#include "Data.h"

class DamageData : public Data {
public:
	DamageData(float damage);
	virtual ~DamageData();

	float getDamage()const;
private:
	float m_Damage;
};

