#pragma once
#include "Component.h"

class SpriteData;
class PositionData;
class IsPlayerData;
class MovementData;

class MoveComponent : public Component{
public:
	MoveComponent(SpriteData* spriteData, PositionData* positionData, MovementData* movementData, IsPlayerData* isPlayerdata);
	~MoveComponent();
	virtual void update(GameObject* gameObject);
private:
	void checkInput(GameObject* gameObject);
	void movePlayer(GameObject* gameObject, int direction);
	void moveObject(GameObject* gameObject);

	SpriteData* m_SpriteData;
	PositionData* m_PositionData;
	MovementData* m_MovementData;
	IsPlayerData* m_IsPlayerData;
};