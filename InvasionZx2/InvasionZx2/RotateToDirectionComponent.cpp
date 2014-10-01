#include "RotateToDirectionComponent.h"
#include "GraphicManager.h"
#include "PositionData.h"
#include "MovementData.h"
#include "SpriteData.h"

RotateToDirectionComponent::RotateToDirectionComponent(SpriteData* spriteData, PositionData* positionData, MovementData* movementData){
	m_SpriteData = spriteData;
	m_PositionData = positionData;
	m_MovementData = movementData;
}

RotateToDirectionComponent::~RotateToDirectionComponent(){}

void RotateToDirectionComponent::update(GameObject* gameObject){
	rotateSprite();
}

void RotateToDirectionComponent::rotateSprite(){
	sf::Vector2f rotation = *m_MovementData->getDirection();

	sf::Vector2f pos1 = m_SpriteData->getSprite()->getPosition();

	sf::Vector2f pos2 = *m_PositionData->getPosition();
	pos2.x += rotation.x;
	pos2.y += rotation.y;

	float angle = std::atan2(pos1.y - pos2.y, pos1.x - pos2.x)*convertToDegrees;

	m_SpriteData->getSprite()->setRotation(angle);
}