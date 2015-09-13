/*
	Create and holds all the game objects
	Singelton pattern
*/

#include "EntityFactory.h"
#include "LuaConfig.h"
#include "Player.h"
#include "Zombie.h"
#include "Bullet.h"
#include "Floor.h"
#include "Level.h"
#include "Wall.h"

// Singelton variable, the object instance
EntityFactory* EntityFactory::m_Instance = new EntityFactory();

EntityFactory::EntityFactory(){}

EntityFactory::~EntityFactory(){}

// Singelton method, returns the object instance
EntityFactory* EntityFactory::getInstance(){
	return m_Instance;
}

// Initialize the object for a level
void EntityFactory::initialize(Level* level){
	getInstance()->m_Level = level;
	getInstance()->m_PlayerPtr = new Player(LuaConfig("Player"), GameObject::Player);
	getInstance()->createGameObject(getInstance()->m_PlayerPtr);
}

// Create the player gameobject
Player* EntityFactory::getPlayer(){
	return getInstance()->m_PlayerPtr;
}