#pragma once
#include <SFML/System/Vector2.hpp>
#include "Bullet.h"
#include "Level.h"
#include <string>

class Level;
class Player;

class EntityFactory{
public:
	static EntityFactory* getInstance();
	static void initialize(Level* level);
	
	template<typename o>
	static void createGameObject(o* object){
		getInstance()->m_Level->createGameObject(object);
	}

	template<typename o>
	static void deleteGameObject(o* object){
		getInstance()->m_Level->destroyDeadObjects
	}

	static Player* getPlayer();

	Level* m_Level;
private:
	EntityFactory();
	~EntityFactory();
	static EntityFactory* m_Instance;

	Player* m_PlayerPtr;
};

