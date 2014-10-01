#include "Level.h"
#include "CollisionDetectionManager.h"
#include "GraphicManager.h"
#include "CollisionData.h"
#include "EntityFactory.h"
#include "TimeManager.h"
#include "ItemManager.h"
#include "GridManager.h"
#include "Spawner.h"
#include "Shared.h"
#include "Player.h"
#include "Floor.h"
#include "Wall.h"
#include "GUI.h"

#include "Zombie.h"
#include <iostream>

Level::Level(){
	sf::Vector2f pos = sf::Vector2f(300, 300);
	sf::Vector2f gridStartPos = sf::Vector2f(0, 0);
	sf::Vector2f gridEndPos = sf::Vector2f(0, 0);
	float windowSizeX = GraphicManager::getWindow()->getSize().x;
	float windowSizeY = GraphicManager::getWindow()->getSize().y;
	float wallHeight = 100;
	float wallWidth = 100;

	EntityFactory::initialize(this, pos);
	EntityFactory::createGameObject(new Floor("Floor", GameObject::Other));
	//----Create Walls
	/*gridStartPos.y = pos.y*2;
	EntityFactory::createGameObject(new Wall(pos, windowSizeX, wallHeight, GameObject::Wall));

	pos = sf::Vector2f(50, windowSizeY / 2);
	gridStartPos.x = pos.x*2;
	EntityFactory::createGameObject(new Wall(pos, wallWidth, windowSizeY, GameObject::Wall));

	pos = sf::Vector2f(windowSizeX / 2, windowSizeY - 50);
	gridEndPos.y = pos.y - (wallHeight/2);
	EntityFactory::createGameObject(new Wall(pos, windowSizeX, wallHeight, GameObject::Wall));

	pos = sf::Vector2f(windowSizeX - 50, windowSizeY / 2);
	gridEndPos.x = pos.x - (wallWidth/2);
	EntityFactory::createGameObject(new Wall(pos, wallWidth, windowSizeY, GameObject::Wall));*/

	float width = windowSizeX - 300;
	float height = windowSizeY - 300;

	pos = sf::Vector2f(150, 150);
	m_WallVector.push_back(new Wall(pos, width, 0, GameObject::Wall));
	m_GameObjectVector.push_back(m_WallVector.back());
	gridStartPos = pos;

	pos = sf::Vector2f(150 + width, 150);
	m_WallVector.push_back(new Wall(pos, 0, height, GameObject::Wall));
	m_GameObjectVector.push_back(m_WallVector.back());
	gridEndPos.x = pos.x;

	pos = sf::Vector2f(150, 150 + height);
	m_WallVector.push_back(new Wall(pos, width, 0, GameObject::Wall));
	m_GameObjectVector.push_back(m_WallVector.back());
	gridEndPos.y = pos.y;

	pos = sf::Vector2f(150, 150);
	m_WallVector.push_back(new Wall(pos, 0, height, GameObject::Wall));
	m_GameObjectVector.push_back(m_WallVector.back());

	//----/Create Walls

	pos = sf::Vector2f(400, 400);
	//EntityFactory::createGameObject(new Zombie(pos, GameObject::Zombie));

	pos = sf::Vector2f(500, 400);
	//EntityFactory::createGameObject(new Spawner(pos, GameObject::Other));

	GUI::initialize();
	ItemManager::initialize();
	GridManager::initialize(gridStartPos, gridEndPos);

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

float Level::getGameObjectVectorSize()const{
	return m_GameObjectVector.size();
}

float Level::getWallCount()const{
	return m_GameObjectVector.size();
}

void Level::spawnObjects(){
	for (auto i = m_SpawnVector.begin(); i != m_SpawnVector.end(); i++){
		m_GameObjectVector.push_back(*i);
	}
	m_SpawnVector.clear();
}

void Level::destroyDeadObjects(){
	for (auto i = m_GameObjectVector.begin(); i != m_GameObjectVector.end(); i++){
		if (!(*i)->getIsAlive()){
			//delete *i;
			m_GameObjectVector.erase(i--);
		}
	}
}