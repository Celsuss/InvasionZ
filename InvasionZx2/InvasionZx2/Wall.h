/*
	Wall gameobject, gameobjects can't through the wall and bullts die when they hit the wall
	Components used: 
	Data used: CollisionData, PositionData, VertexArrayData
*/

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