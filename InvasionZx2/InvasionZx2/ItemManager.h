#pragma once
#include "SFML/System/Vector2.hpp"
#include <queue>

class GameObject;

class ItemManager{
public:
	static ItemManager* getInstance();

	static void initialize();
	static void dropItem(sf::Vector2f pos);
private:
	ItemManager();
	~ItemManager();
	static ItemManager* m_Instance;

	static bool dropWeapon(sf::Vector2f pos);
	static void dropNonWeaponItem(sf::Vector2f pos);

	static void dropHealthPotion(sf::Vector2f pos);

	std::queue<GameObject*> m_WeaponDropQue;
	int m_KillsToWeaponDrop;
};