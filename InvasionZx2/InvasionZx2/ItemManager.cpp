#include "ItemManager.h"
#include "GameObject.h"
#include "EntityFactory.h"
#include "MachineGunItem.h"
#include "HealthPotionItem.h"

ItemManager* ItemManager::m_Instance = new ItemManager();

ItemManager::ItemManager(){}

ItemManager::~ItemManager(){}

ItemManager* ItemManager::getInstance(){
	return m_Instance;
}

void ItemManager::initialize(){
	getInstance()->m_KillsToWeaponDrop = 1;
	getInstance()->m_WeaponDropQue.push(new MachineGunItem(sf::Vector2f(0, 0)));
}

void ItemManager::dropItem(sf::Vector2f pos){
	getInstance()->m_KillsToWeaponDrop--;
	if (!dropWeapon(pos))
		dropNonWeaponItem(pos);
}

bool ItemManager::dropWeapon(sf::Vector2f pos){
	if (getInstance()->m_KillsToWeaponDrop <= 0 && !getInstance()->m_WeaponDropQue.empty()){
		//Update position and sprite position
		*getInstance()->m_WeaponDropQue.front()->getData<PositionData>("PositionData")->getPosition() = pos;
		getInstance()->m_WeaponDropQue.front()->getData<SpriteData>("SpriteData")->getSprite()->setPosition(pos);

		EntityFactory::createGameObject(getInstance()->m_WeaponDropQue.front());
		getInstance()->m_WeaponDropQue.pop();
		getInstance()->m_KillsToWeaponDrop = 1;
		
		return true;
	}
	return false;
}

void ItemManager::dropNonWeaponItem(sf::Vector2f pos){
	int randomNr = rand() % 100 + 1;
	if (randomNr < 1000){
		dropHealthPotion(pos);
	}
}

void ItemManager::dropHealthPotion(sf::Vector2f pos){
	EntityFactory::createGameObject(new HealthPotionItem(pos));
}