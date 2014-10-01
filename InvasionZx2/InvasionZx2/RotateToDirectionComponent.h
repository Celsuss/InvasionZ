#pragma once
#include "Component.h"

class SpriteData;
class PositionData;
class MovementData;

class RotateToDirectionComponent : public Component{
public:
	RotateToDirectionComponent(SpriteData* spriteData, PositionData* positionData, MovementData* movementData);
	virtual ~RotateToDirectionComponent();
	virtual void update(GameObject* gameObject);
private:
	void rotateSprite();

	SpriteData* m_SpriteData;
	PositionData* m_PositionData;
	MovementData* m_MovementData;
};