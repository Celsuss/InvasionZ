#include "Zombie.h"
#include "HealthBarComponent.h"
#include "AIStateComponent.h"
#include "GraphicManager.h"
#include "CollisionData.h"
#include "MoveComponent.h"
#include "AttackState.h"
#include "HealthData.h"

Zombie::Zombie(sf::Vector2f pos, Type type){
	m_Type = type;

	m_DataVector.push_back(new MovementData(50));
	m_DataVector.push_back(new PositionData(pos));
	m_DataVector.push_back(new SpriteData("Zombie", getData<PositionData>("PositionData")));
	m_DataVector.push_back(new CollisionData(CollisionData::Circle));
	m_DataVector.push_back(new HealthData(100));

	m_ComponentVector.push_back(new HealthBarComponent());
	m_ComponentVector.push_back(new MoveComponent());
	m_ComponentVector.push_back(new AIStateComponent(new AttackState()));
}

Zombie::Zombie(float x, float y){}

Zombie::~Zombie(){}