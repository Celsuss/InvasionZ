#include "Zombie.h"
#include "RotateToDirectionComponent.h"
#include "HealthBarComponent.h"
#include "AIStateComponent.h"
#include "GraphicManager.h"
#include "CollisionData.h"
#include "MoveComponent.h"
#include "AttackState.h"
#include "HealthData.h"

Zombie::Zombie(sf::Vector2f pos, Type type){
	m_Type = type;

	MovementData* movementData = new MovementData(50);
	PositionData* positionData = new PositionData(pos);
	SpriteData* spriteData = new SpriteData("Zombie", positionData);
	CollisionData* collisionData = new CollisionData(CollisionData::Circle);
	HealthData* healthData = new HealthData(100);

	m_DataVector.push_back(movementData);
	m_DataVector.push_back(positionData);
	m_DataVector.push_back(spriteData);
	m_DataVector.push_back(collisionData);
	m_DataVector.push_back(healthData);

	m_ComponentVector.push_back(new HealthBarComponent(healthData, positionData));
	m_ComponentVector.push_back(new MoveComponent(spriteData, positionData, movementData, nullptr));
	m_ComponentVector.push_back(new AIStateComponent(new AttackState()));
	m_ComponentVector.push_back(new RotateToDirectionComponent(spriteData, positionData, movementData));

	setDrawableData();
}

Zombie::Zombie(float x, float y){}

Zombie::~Zombie(){}

void Zombie::addCollision(GameObject* obj){
	//Send collision to AIStateComponent
	//If AIState = Wander then change direction
}