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

	m_DataVector.push_back(isWeaponData);
	m_DataVector.push_back(movementData);
	m_DataVector.push_back(positionData);
	m_DataVector.push_back(spriteData);
	m_DataVector.push_back(collisionData);
	m_DataVector.push_back(damageData);
	
	m_ComponentVector.push_back(new MoveComponent(spriteData, positionData, movementData, nullptr));

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