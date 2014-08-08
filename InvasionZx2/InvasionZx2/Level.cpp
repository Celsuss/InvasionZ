#include "Level.h"
#include "CollisionDetectionManager.h"
#include "GraphicManager.h"
#include "CollisionData.h"
#include "EntityFactory.h"
#include "TimeManager.h"
#include "Spawner.h"
#include "Shared.h"
#include "Player.h"
#include "Floor.h"
#include "Wall.h"
#include "GUI.h"

#include "Zombie.h"
#include <iostream>

Level::Level(){
	m_WallCount = 0;
	sf::Vector2f pos = sf::Vector2f(300, 300);
	float windowSizeX = GraphicManager::getWindow()->getSize().x;
	float windowSizeY = GraphicManager::getWindow()->getSize().y;

	EntityFactory::initialize(this, pos);
	EntityFactory::createGameObject(new Floor("Floor", GameObject::Other));
	pos = sf::Vector2f(windowSizeX / 2, 50);
	//----Create Walls
	EntityFactory::createGameObject(new Wall(pos, windowSizeX, 100, GameObject::Wall));
	m_WallCount++;
	pos = sf::Vector2f(50, windowSizeY / 2);
	EntityFactory::createGameObject(new Wall(pos, 100, windowSizeY, GameObject::Wall));
	m_WallCount++;
	pos = sf::Vector2f(windowSizeX / 2, windowSizeY - 50);
	EntityFactory::createGameObject(new Wall(pos, windowSizeX, 100, GameObject::Wall));
	m_WallCount++;
	pos = sf::Vector2f(windowSizeX - 50, windowSizeY / 2);
	EntityFactory::createGameObject(new Wall(pos, 100, windowSizeY, GameObject::Wall));
	m_WallCount++;
	//----/Create Walls

	pos = sf::Vector2f(400, 400);
	EntityFactory::createGameObject(new Zombie(pos, GameObject::Zombie));

	pos = sf::Vector2f(500, 400);
	EntityFactory::createGameObject(new Spawner(pos, GameObject::Other));

	GUI::initialize();

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
	collisionDetection();
	GUI::update();

	//----DEBUG
	if (m_GameObjectVector.size() != m_GameObjectCound){
		m_GameObjectCound = m_GameObjectVector.size();
		std::cout << "GameObjects: " << m_GameObjectCound << "\n";
	}
	//----&DEBUG
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
		if ((*i)->m_Type == type){
			if (offsetCount == offset)
				return *i;
			offsetCount++;
		}
	}

	return nullptr;
}

float Level::getWallCount()const{
	return m_WallCount;
}

void Level::spawnObjects(){
	for (auto i = m_SpawnVector.begin(); i != m_SpawnVector.end(); i++){
		m_GameObjectVector.push_back(*i);
	}
	m_SpawnVector.clear();
}

void Level::destroyDeadObjects(){
	for (auto i = m_GameObjectVector.begin(); i != m_GameObjectVector.end(); i++){
		if (!(*i)->m_IsAlive){
			//delete *i;
			m_GameObjectVector.erase(i--);
		}
	}
}

void Level::collisionDetection(){
	for (auto i = m_GameObjectVector.begin(); i != m_GameObjectVector.end(); i++){
		if ((*i)->getData<CollisionData>("CollisionData") != nullptr){
			CollisionData::CollisionShape* shape1 = (*i)->getData<CollisionData>("CollisionData")->getShape();
			for (auto j = m_GameObjectVector.begin(); j != m_GameObjectVector.end(); j++){
				if (i != j){
					if ((*j)->getData<CollisionData>("CollisionData") != nullptr){
						CollisionData::CollisionShape* shape2 = (*j)->getData<CollisionData>("CollisionData")->getShape();

						CollisionDetectionManager::collisionDetection(*i, *j, shape1, shape2);
					}
				}
			}
		}
	}
}