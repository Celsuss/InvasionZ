#pragma once
#include "Component.h"

class SpriteData;
class MovementData;

class RotateToMouseComponent : public Component{
public:
	RotateToMouseComponent();
	virtual ~RotateToMouseComponent();
	virtual void update(GameObject* gameObject);
private:
	void rotateSprite(SpriteData* spriteData);
	void rotateMovement(SpriteData* spriteData, MovementData* movementData);
};

