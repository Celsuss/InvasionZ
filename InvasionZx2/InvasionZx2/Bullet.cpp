/*
	Bullet object, spawns when the player uses a weapon and shoot
	Components used: MoveComponent
	Data used: IsWeaponData, MovementData, PositionData, CollisionData, DamageData
*/

#include "Bullet.h"
#include "GraphicManager.h"
#include "MoveComponent.h"
#include "CollisionData.h"
#include "IsWeaponData.h"
#include "HealthData.h"
#include "DamageData.h"

Bullet::Bullet(sf::Vector2f pos, sf::Vector2f direction, Type type){
	m_Type = type;

	IsWeaponData* isWeaponData = new IsWeaponData();
	MovementData* movementData = new MovementData(300, direction);
	PositionData* positionData = new PositionData(pos);
	SpriteData* spriteData = new SpriteData("Bullet", positionData);
	CollisionData* collisionData = new CollisionData(CollisionData::Circle, false);
	DamageData* damageData = new DamageData(10);

	m_DataMap[isWeaponData->getName()] = std::shared_ptr<IsWeaponData>(isWeaponData);
	m_DataMap[movementData->getName()] = std::shared_ptr<MovementData>(movementData);
	m_DataMap[positionData->getName()] = std::shared_ptr<PositionData>(positionData);
	m_DataMap[spriteData->getName()] = std::shared_ptr<SpriteData>(spriteData);
	m_DataMap[collisionData->getName()] = std::shared_ptr<CollisionData>(collisionData);
	m_DataMap[damageData->getName()] = std::shared_ptr<DamageData>(damageData);

	MoveComponent* moveComponent = new MoveComponent(spriteData, positionData, movementData, nullptr);

	m_ComponentMap[moveComponent->getName()] = std::shared_ptr<MoveComponent>(moveComponent);

	setDrawableData();
}

Bullet::~Bullet(){}

void Bullet::addCollision(GameObject* obj){
	switch (obj->getType()){
	case GameObject::Zombie:
		float* health = obj->getData<HealthData>("HealthData")->getHealth();
		float damage = this->getData<DamageData>("DamageData")->getDamage();
		*health = *health - damage;
		this->m_IsAlive = false;
		break;
	}
}