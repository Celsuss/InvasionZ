#pragma once
#include "GameObject.h"
#include "SpriteData.h"
#include <string>

class Floor : public GameObject{
public:
	Floor(std::string texture);
	virtual ~Floor();
	virtual void update();
private:
	SpriteData m_SpriteData;
};