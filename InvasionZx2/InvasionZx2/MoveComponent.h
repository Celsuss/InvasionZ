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
	void movePlayer(GameObject* gameObject);
	void moveObject(GameObject* gameObject);
};

