#include "EntityFactory.h"
#include "Player.h"
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
}

void EntityFactory::createPlayer(sf::Vector2f pos){
	Player* player = new Player(300, 300);
	getInstance()->m_Level->createGameObject(player);
}

void EntityFactory::createBullet(sf::Vector2f pos, sf::Vector2f direction){
	Bullet* bullet = new Bullet(pos, direction);
	getInstance()->m_Level->createGameObject(bullet);
}

void EntityFactory::createFloor(std::string name){
	Floor* floor = new Floor(name);
	getInstance()->m_Level->createGameObject(floor);
}

void EntityFactory::createWall(sf::Vector2f pos, float width, float height){
	Wall* wall = new Wall(pos, width, height);
	getInstance()->m_Level->createGameObject(wall);
}