#pragma once
#include <string>

//static const float convertToDegrees = 57.2957795f;
//static const float mouseYPosError = 30.f;

class GameObject;

class Component{
public:
	Component();
	virtual ~Component();
	virtual void update(GameObject* gameObject) = 0;
	std::string getName() const;

	std::string m_Name;
};

