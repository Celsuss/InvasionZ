#pragma once
#include "Data.h"
#include <string>
#include <map>

class AmmoData : public Data{
public:
	AmmoData();
	virtual ~AmmoData();

	int* getAmmo(std::string weapon);
	int getMaxAmmo(std::string weapon)const;
private:
	std::map<std::string, int> m_AmmoMap;
	std::map<std::string, int> m_MagAmmoMap;
	std::map<std::string, int> m_MaxAmmoMap;
};