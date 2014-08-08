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

Player::Player(sf::Vector2f pos, Type type){
	m_Type = type;

	m_DataVector.push_back(new MovementData(100));
	m_DataVector.push_back(new PositionData(pos));
	m_DataVector.push_back(new SpriteData("Player", getData<PositionData>("PositionData")));
	m_DataVector.push_back(new IsPlayerData());
	m_DataVector.push_back(new WeaponData());
	m_DataVector.push_back(new AmmoData());
	m_DataVector.push_back(new CollisionData(CollisionData::Circle));
	m_DataVector.push_back(new HealthData(100));

	m_ComponentVector.push_back(new RotateToMouseComponent());
	m_ComponentVector.push_back(new MoveComponent());
	m_ComponentVector.push_back(new ShootComponent());
	m_ComponentVector.push_back(new HealthBarComponent());
	//m_ComponentVector.push_back(new SpawnTrailComponent());
}

Player::~Player(){}