/*
Rotate the gameobjects moving direction and sprite towards the mouse cursor
Data needed: SpriteData MovementData
*/

#pragma once
#include "Component.h"

class SpriteData;
class MovementData;

class RotateToMouseComponent : public Component{
public:
	RotateToMouseComponent(SpriteData* spriteData, MovementData* movementData);
	virtual ~RotateToMouseComponent();
	virtual void update(GameObject* gameObject);
private:
	void rotateSprite();
	void rotateMovement();

	SpriteData* m_SpriteData;
	MovementData* m_MovementData;
};