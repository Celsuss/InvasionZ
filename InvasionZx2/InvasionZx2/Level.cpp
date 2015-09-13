/*
	A game state, a playable level where the player can control the Player object
*/

#include "Level.h"
#include "CollisionDetectionManager.h"
#include "GraphicManager.h"
#include "CollisionData.h"
#include "EntityFactory.h"
#include "TimeManager.h"
#include "ItemManager.h"
#include "GridManager.h"
#include "LuaConfig.h"
#include "Spawner.h"
#include "Shared.h"
#include "Player.h"
#include "Floor.h"
#include "Wall.h"
#include "GUI.h"

#include "Zombie.h"
#include <iostream>

Level::Level(){
	float windowSizeX = GraphicManager::getWindow()->getSize().x;
	float windowSizeY = GraphicManager::getWindow()->getSize().y;

	//GridManager::initialize(LuaConfig("Grid"));
	EntityFactory::initialize(this);
	EntityFactory::createGameObject(new Floor("Floor", GameObject::Other));
	generateLevel(LuaConfig("LevelOne"));
	GridManager::initialize(LuaConfig("Grid"), this);

	sf::Vector2f pos = sf::Vector2f(400, 400);
	//EntityFactory::createGameObject(new Zombie(pos, GameObject::Zombie));

	pos = sf::Vector2f(500, 400);
	EntityFactory::createGameObject(new Spawner(pos, GameObject::Other));

	GUI::initialize();
	ItemManager::initialize();

	//----DEBUG
	m_GameObjectCound = 0;
	//----&DEBUG
}

Level::~Level(){}

void Level::update(){
	destroyDeadObjects();
	spawnObjects();
	for (auto i = m_GameObjectVector.begin(); i != m_GameObjectVector.end(); i++){
		(*i)->update();
	}
	CollisionDetectionManager::collisionDetection(this);

	drawScenery();
	drawWalls();
	GridManager::update();
	GUI::update();

	//----DEBUG
	if (m_GameObjectVector.size() != m_GameObjectCound){
		m_GameObjectCound = m_GameObjectVector.size();
		std::cout << "GameObjects: " << m_GameObjectCound << "\n";
	}
	//----&DEBUG
}

void Level::drawScenery(){
	for (auto i = m_SceneryVector.begin(); i != m_SceneryVector.end(); i++){
		//(*i)->update();
	}
}

void Level::drawWalls(){
	for (auto i = m_WallVector.begin(); i != m_WallVector.end(); i++){
		(*i)->drawWall();
	}
}

void Level::createGameObject(GameObject* gameObject){
	m_SpawnVector.push_back(gameObject);
}

GameObject* Level::getGameObject(int index){
	return m_GameObjectVector[index];
}

//Find the type object nr offset
GameObject* Level::getGameObject(GameObject::Type type, int offset){
	int offsetCount = 0;
	for (auto i = m_GameObjectVector.begin(); i != m_GameObjectVector.end(); i++){
		if ((*i)->getType() == type){
			if (offsetCount == offset)
				return *i;
			offsetCount++;
		}
	}

	return nullptr;
}

Level::WallVector& Level::getWallVector(){
	return m_WallVector;
}

float Level::getGameObjectVectorSize()const{
	return m_GameObjectVector.size();
}

float Level::getWallCount()const{
	return m_WallVector.size();
}

void Level::generateLevel(LuaConfig config){
	for (int i = 0; i < config.getInt("WALLCOUNT"); i++){
		m_WallVector.push_back(new Wall(LuaConfig(config.getString("WALLNAMES", i)), GameObject::Wall));
		m_GameObjectVector.push_back(m_WallVector.back());
	}
}

void Level::spawnObjects(){
	for (auto i = m_SpawnVector.begin(); i != m_SpawnVector.end(); i++){
		m_GameObjectVector.push_back(*i);
	}
	m_SpawnVector.clear();
}

void Level::destroyDeadObjects(){
	for (auto i = m_GameObjectVector.begin(); i != m_GameObjectVector.end(); ){
		if (!(*i)->getIsAlive()){
			delete *i;
			i = m_GameObjectVector.erase(i);
		}
		else
			i++;
	}
}