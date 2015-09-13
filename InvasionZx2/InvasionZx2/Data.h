/*
	Data about gameobjects
*/

#pragma once
#include <string>

static const float convertToDegrees = 57.2957795f;
static const float mouseYPosError = 30.f;

class Data{
public:
	Data();
	virtual ~Data();
	std::string getName() const;

	std::string m_Name;
};

