/*
	Component to rotate the gameobjects sprite to the same direction the gameobject is moving
	Data needed: SpriteData, PositionData, MovementData
*/

#include "RotateComponent.h"
#include "GraphicManager.h"
#include "PositionData.h"
#include "MovementData.h"
#include "SpriteData.h"

RotateComponent::RotateComponent(SpriteData* spriteData, PositionData* positionData, MovementData* movementData){
	m_Name = "RotateToDirectionComponent";
	m_SpriteData = spriteData;
	m_PositionData = positionData;
	m_MovementData = movementData;
}

RotateComponent::~RotateComponent(){}

void RotateComponent::update(GameObject* gameObject){
	rotateSprite();
}

//Rotate the sprite towards the gameobjects direction
void RotateComponent::rotateSprite(){
	sf::Vector2f direction = *m_MovementData->getDirection();

	sf::Vector2f pos1 = m_SpriteData->getSprite()->getPosition();

	sf::Vector2f pos2 = *m_PositionData->getPosition();
	pos2.x += direction.x;
	pos2.y += direction.y;

	float angle = std::atan2(pos1.y - pos2.y, pos1.x - pos2.x)*convertToDegrees;

	m_SpriteData->getSprite()->setRotation(angle);
}