/*
	Player gameobject, controlled by player input
	Components used: RotateToMouseComponent, MoveComponent, ShootComponent, HealthBarComponent, ChangeWeaponComponent, SpawnTrailComponent
	Data used: MovementData, PositionData, SpriteData, IsPlayerData, WeaponData, AmmoData, CollisionData, HealthDatas
*/

#pragma once
#include "GameObject.h"
#include "RotateToMouseComponent.h"
#include "SFML/System/Vector2.hpp"
#include "LuaConfig.h"

class Player : public GameObject{
public:
	Player(sf::Vector2f pos, Type type);
	Player(LuaConfig config, Type type);
	virtual ~Player();
	virtual void addCollision(GameObject* obj);
};