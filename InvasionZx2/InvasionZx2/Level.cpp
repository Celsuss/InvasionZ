#include "Level.h"
#include "GraphicManager.h"
#include "EntityFactory.h"
#include "GameObject.h"
#include "Player.h"
#include "Floor.h"
#include "Wall.h"

Level::Level(){
	float windowSizeX = GraphicManager::getWindow()->getSize().x;
	float windowSizeY = GraphicManager::getWindow()->getSize().y;
	EntityFactory::initialize(this);
	EntityFactory::createFloor("Floor");
	EntityFactory::createWall(sf::Vector2f(windowSizeX / 2, 50), windowSizeX, 100);
	EntityFactory::createWall(sf::Vector2f(50, windowSizeY / 2), 100, windowSizeY);
	EntityFactory::createWall(sf::Vector2f(windowSizeX / 2, windowSizeY - 50), windowSizeX, 100);
	EntityFactory::createWall(sf::Vector2f(windowSizeX - 50, windowSizeY / 2), 100, windowSizeY);
	EntityFactory::createPlayer(sf::Vector2f(300, 300));
}

Level::~Level(){}

void Level::update(){
	spawnObjects();
	for (auto i = m_GameObjectVector.begin(); i != m_GameObjectVector.end(); i++){
		(*i)->update();
	}
	CollisionDetection();
}

void Level::createGameObject(GameObject* gameObject){
	m_SpawnVector.push_back(gameObject);
}

void Level::CollisionDetection(){
	for (auto i = m_GameObjectVector.begin(); i != m_GameObjectVector.end(); i++){
		for (auto j = m_GameObjectVector.begin(); j != m_GameObjectVector.end(); j++){
			
		}
	}
}

void Level::spawnObjects(){
	for (auto i = m_SpawnVector.begin(); i != m_SpawnVector.end(); i++){
		m_GameObjectVector.push_back(*i);
	}
	m_SpawnVector.clear();
}