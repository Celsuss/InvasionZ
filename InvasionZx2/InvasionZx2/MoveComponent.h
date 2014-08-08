#pragma once
#include "Component.h"

class SpriteData;
class PositionData;
class MovementSpeedData;

class MoveComponent : public Component{
public:
	MoveComponent();
	~MoveComponent();
	virtual void update(GameObject* gameObject);
private:
	void checkInput(GameObject* gameObject);
	void movePlayer(GameObject* gameObject, int direction);
	void moveObject(GameObject* gameObject);
};

