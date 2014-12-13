#pragma once
#include "LuaConfig.h"
#include "GameObject.h"
#include "SpriteData.h"
#include "PositionData.h"
#include "SFML/System/Vector2.hpp"

#include "PositionData.h"
#include "SpriteData.h"

class Wall : public GameObject{
public:
	Wall(LuaConfig config, Type type);
	virtual ~Wall();

	virtual void addCollision(GameObject* obj);
	void drawWall();
};