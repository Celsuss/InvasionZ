/*
	Bullet gameobject, spawns when the player uses a weapon and shoot
	Components used: MoveComponent
	Data used: IsWeaponData, MovementData, PositionData, CollisionData, DamageData
*/

#pragma once
#include "GameObject.h"

class Bullet : public GameObject{
public:
	Bullet(sf::Vector2f pos, sf::Vector2f direction, Type type);
	virtual ~Bullet();
	virtual void addCollision(GameObject* obj);
};