#pragma once
#include <SFML/System/Vector2.hpp>
#include <string>

class Level;

class EntityFactory{
public:
	static EntityFactory* getInstance();
	static void initialize(Level* level);
	static void createPlayer(sf::Vector2f pos);
	static void createBullet(sf::Vector2f pos, sf::Vector2f direction);
	static void createFloor(std::string name);
	static void createWall(sf::Vector2f pos, float width, float height);
private:
	EntityFactory();
	~EntityFactory();
	static EntityFactory* m_Instance;

	Level* m_Level;
};

