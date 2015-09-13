/*
	Floor gameobject, only a decorative gameobject
	Components used:
	Data used: SpriteData
*/

#pragma once
#include "GameObject.h"
#include "SpriteData.h"
#include <string>

class Floor : public GameObject{
public:
	Floor(std::string texture, Type type);
	virtual ~Floor();
	virtual void addCollision(GameObject* obj);
};