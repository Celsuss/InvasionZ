/*
	Components for gameobjects
*/

#include "Component.h"

Component::Component(){}

Component::~Component(){}

std::string Component::getName() const{
	return m_Name;
}
