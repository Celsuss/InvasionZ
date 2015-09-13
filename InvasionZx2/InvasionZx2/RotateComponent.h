/*
	Component to rotates the game objects sprite
	Data needed: SpriteData, PositionData, MovementData
*/

#pragma once
#include "Component.h"

class SpriteData;
class PositionData;
class MovementData;

class RotateComponent : public Component{
public:
	RotateComponent(SpriteData* spriteData, PositionData* positionData, MovementData* movementData);
	virtual ~RotateComponent();
	virtual void update(GameObject* gameObject);
private:
	void rotateSprite();

	SpriteData* m_SpriteData;
	PositionData* m_PositionData;
	MovementData* m_MovementData;
};