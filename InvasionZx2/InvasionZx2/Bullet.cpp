#include "Bullet.h"
#include "GraphicManager.h"
#include "MoveComponent.h"
#include "CollisionData.h"
#include "IsWeaponData.h"
#include "DamageData.h"

Bullet::Bullet(sf::Vector2f pos, sf::Vector2f direction, Type type){
	m_Type = type;

	m_DataVector.push_back(new IsWeaponData());
	m_DataVector.push_back(new MovementData(300, direction));
	m_DataVector.push_back(new PositionData(pos));
	m_DataVector.push_back(new SpriteData("Bullet", getData<PositionData>("PositionData")));
	m_DataVector.push_back(new CollisionData(CollisionData::Circle));
	m_DataVector.push_back(new DamageData(10));
	

	m_ComponentVector.push_back(new MoveComponent());
}

Bullet::~Bullet(){}