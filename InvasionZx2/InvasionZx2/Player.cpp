/*
	Player object, controlled by player input
	Components used: RotateToMouseComponent, MoveComponent, ShootComponent, HealthBarComponent, ChangeWeaponComponent, SpawnTrailComponent
	Data used: MovementData, PositionData, SpriteData, IsPlayerData, WeaponData, AmmoData, CollisionData, HealthDatas
*/

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

Player::Player(LuaConfig config, Type type){
	m_Type = type;

	sf::Vector2f pos;
	pos.x = config.getInt("START_POSITION_X");
	pos.y = config.getInt("START_POSITION_Y");

	MovementData* movementData = new MovementData(config.getInt("MOVEMENT_SPEED"));
	PositionData* positionData = new PositionData(pos);
	SpriteData* spriteData = new SpriteData(config.getString("SPRITE"), positionData);
	IsPlayerData* isPlayerData = new IsPlayerData();
	WeaponData* weaponData = new WeaponData();
	AmmoData* ammoData = new AmmoData();
	CollisionData* collisionData = new CollisionData(CollisionData::Circle);
	HealthData* healthData = new HealthData(config.getInt("HEALTH"));

	m_DataMap[movementData->getName()] = std::shared_ptr<MovementData>(movementData);
	m_DataMap[positionData->getName()] = std::shared_ptr<PositionData>(positionData);
	m_DataMap[spriteData->getName()] = std::shared_ptr<SpriteData>(spriteData);
	m_DataMap[isPlayerData->getName()] = std::shared_ptr<IsPlayerData>(isPlayerData);
	m_DataMap[weaponData->getName()] = std::shared_ptr<WeaponData>(weaponData);
	m_DataMap[ammoData->getName()] = std::shared_ptr<AmmoData>(ammoData);
	m_DataMap[collisionData->getName()] = std::shared_ptr<CollisionData>(collisionData);
	m_DataMap[healthData->getName()] = std::shared_ptr<HealthData>(healthData);

	RotateToMouseComponent* rotateToMouseComponent = new RotateToMouseComponent(spriteData, movementData);
	MoveComponent* moveComponent = new MoveComponent(spriteData, positionData, movementData, isPlayerData);
	ShootComponent* shootComponent = new ShootComponent(weaponData);
	HealthBarComponent* healthBarComponent = new HealthBarComponent(healthData, positionData);
	ChangeWeaponComponent* changeWeaponComponent = new ChangeWeaponComponent(weaponData);

	m_ComponentMap[rotateToMouseComponent->getName()] = std::shared_ptr<RotateToMouseComponent>(rotateToMouseComponent);
	m_ComponentMap[moveComponent->getName()] = std::shared_ptr<MoveComponent>(moveComponent);
	m_ComponentMap[shootComponent->getName()] = std::shared_ptr<ShootComponent>(shootComponent);
	m_ComponentMap[healthBarComponent->getName()] = std::shared_ptr<HealthBarComponent>(healthBarComponent);
	m_ComponentMap[changeWeaponComponent->getName()] = std::shared_ptr<ChangeWeaponComponent>(changeWeaponComponent);

	setDrawableData();
}

Player::~Player(){}

void Player::addCollision(GameObject* obj){}