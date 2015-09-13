/*
	Zombie gameobject, AI controlled and attack the player if seen or walk around the map. Can be killed by bullets
	Components used: HealthBarComponent, MoveComponent, AIStateComponent, RotateComponent
	Data used: MovementData, PositionData, SpriteData, CollisionData, HealthData
*/

#include "Zombie.h"
#include "RotateComponent.h"
#include "HealthBarComponent.h"
#include "AIStateComponent.h"
#include "GraphicManager.h"
#include "CollisionData.h"
#include "MoveComponent.h"
#include "AttackState.h"
#include "PatrolState.h"
#include "HealthData.h"
#include "HuntState.h"
#include "HitState.h"

Zombie::Zombie(sf::Vector2f pos, Type type){
	m_Type = type;

	MovementData* movementData = new MovementData(50);
	PositionData* positionData = new PositionData(pos);
	SpriteData* spriteData = new SpriteData("Zombie", positionData);
	CollisionData* collisionData = new CollisionData(CollisionData::Circle);
	HealthData* healthData = new HealthData(100);

	m_DataMap[movementData->getName()] = std::shared_ptr<MovementData>(movementData);
	m_DataMap[positionData->getName()] = std::shared_ptr<PositionData>(positionData);
	m_DataMap[spriteData->getName()] = std::shared_ptr<SpriteData>(spriteData);
	m_DataMap[collisionData->getName()] = std::shared_ptr<CollisionData>(collisionData);
	m_DataMap[healthData->getName()] = std::shared_ptr<HealthData>(healthData);

	HealthBarComponent* healthBarComponent = new HealthBarComponent(healthData, positionData);
	MoveComponent* moveComponent = new MoveComponent(spriteData, positionData, movementData, nullptr);
	AIStateComponent* aiStateComponent = new AIStateComponent(new PatrolState(healthData, positionData, movementData), new HitState());
	RotateComponent* rotateComponent = new RotateComponent(spriteData, positionData, movementData);

	m_ComponentMap[healthBarComponent->getName()] = std::shared_ptr<HealthBarComponent>(healthBarComponent);
	m_ComponentMap[moveComponent->getName()] = std::shared_ptr<MoveComponent>(moveComponent);
	m_ComponentMap[aiStateComponent->getName()] = std::shared_ptr<AIStateComponent>(aiStateComponent);
	m_ComponentMap[rotateComponent->getName()] = std::shared_ptr<RotateComponent>(rotateComponent);

	setDrawableData();
}

Zombie::Zombie(LuaConfig config, Type type){
	m_Type = type;
	//int posX = config.getInt("POSITION_X");
}

Zombie::Zombie(float x, float y){}

Zombie::~Zombie(){}

void Zombie::addCollision(GameObject* obj){
	//Send collision to AIStateComponent
	//If AIState = Wander then change direction
}