#include "Player.h"
#include "AmmoData.h"
#include "SpriteData.h"
#include "WeaponData.h"
#include "PositionData.h"
#include "IsPlayerData.h"
#include "MoveComponent.h"
#include "GraphicManager.h"
#include "ShootComponent.h"

#include <iostream>

Player::Player(sf::Vector2f pos){
	m_DataVector.push_back(new MovementData(100));
	m_DataVector.push_back(new PositionData(pos));
	m_DataVector.push_back(new SpriteData("Player", getData<PositionData>("PositionData")));
	m_DataVector.push_back(new IsPlayerData());
	m_DataVector.push_back(new WeaponData());
	m_DataVector.push_back(new AmmoData());

	m_ComponentVector.push_back(new RotateToMouseComponent());
	m_ComponentVector.push_back(new MoveComponent());
	m_ComponentVector.push_back(new ShootComponent());
}

Player::Player(float x, float y){
	m_DataVector.push_back(new MovementData(100));
	m_DataVector.push_back(new PositionData(sf::Vector2f(x,y)));
	m_DataVector.push_back(new SpriteData("Player", getData<PositionData>("PositionData")));
	m_DataVector.push_back(new IsPlayerData());
	m_DataVector.push_back(new WeaponData());
	m_DataVector.push_back(new AmmoData());

	m_ComponentVector.push_back(new RotateToMouseComponent());
	m_ComponentVector.push_back(new MoveComponent());
	m_ComponentVector.push_back(new ShootComponent());
}

Player::~Player(){}

void Player::update(){
	for (auto i = m_ComponentVector.begin(); i != m_ComponentVector.end(); i++){
		(*i)->update(this);
	}
	GraphicManager::draw(getData<SpriteData>("SpriteData"));
}