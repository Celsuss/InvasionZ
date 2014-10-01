#include "Player.h"
#include "AmmoData.h"
#include "HealthData.h"
#include "SpriteData.h"
#include "WeaponData.h"
#include "PositionData.h"
#include "IsPlayerData.h"
#include "MoveComponent.h"
#include "CollisionData.h"
#include "GraphicManager.h"
#include "ShootComponent.h"
#include "HealthBarComponent.h"
#include "SpawnTrailComponent.h"
#include "ChangeWeaponComponent.h"

Player::Player(sf::Vector2f pos, Type type){
	m_Type = type;

	MovementData* movementData = new MovementData(100);
	PositionData* positionData = new PositionData(pos);
	SpriteData* spriteData = new SpriteData("player", positionData);
	IsPlayerData* isPlayerData = new IsPlayerData();
	WeaponData* weaponData = new WeaponData();
	AmmoData* ammoData = new AmmoData();
	CollisionData* collisionData = new CollisionData(CollisionData::Circle);
	HealthData* healthData = new HealthData(100);

	m_DataVector.push_back(movementData);
	m_DataVector.push_back(positionData);
	m_DataVector.push_back(spriteData);
	m_DataVector.push_back(isPlayerData);
	m_DataVector.push_back(weaponData);
	m_DataVector.push_back(ammoData);
	m_DataVector.push_back(collisionData);
	m_DataVector.push_back(healthData);

	m_ComponentVector.push_back(new RotateToMouseComponent(spriteData, movementData));
	m_ComponentVector.push_back(new MoveComponent(spriteData, positionData, movementData, isPlayerData));
	m_ComponentVector.push_back(new ShootComponent(weaponData));
	m_ComponentVector.push_back(new HealthBarComponent(healthData, positionData));
	m_ComponentVector.push_back(new ChangeWeaponComponent(weaponData));
	//m_ComponentVector.push_back(new SpawnTrailComponent(positionData));

	setDrawableData();
}

Player::~Player(){}

void Player::addCollision(GameObject* obj){}