#include "EntityFactory.h"
#include "LuaConfig.h"
#include "Player.h"
#include "Zombie.h"
#include "Bullet.h"
#include "Floor.h"
#include "Level.h"
#include "Wall.h"

EntityFactory* EntityFactory::m_Instance = new EntityFactory();

EntityFactory::EntityFactory(){}

EntityFactory::~EntityFactory(){}

EntityFactory* EntityFactory::getInstance(){
	return m_Instance;
}

void EntityFactory::initialize(Level* level){
	getInstance()->m_Level = level;
	getInstance()->m_PlayerPtr = new Player(LuaConfig("Player"), GameObject::Player);
	getInstance()->createGameObject(getInstance()->m_PlayerPtr);
}

Player* EntityFactory::getPlayer(){
	return getInstance()->m_PlayerPtr;
}