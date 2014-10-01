#include "MachineGun.h"
#include "Level.h"
#include "Player.h"
#include "Bullet.h"
#include "AmmoData.h"
#include "GameObject.h"
#include "WeaponData.h"
#include "InputManager.h"
#include "EntityFactory.h"

MachineGun::MachineGun(){
	m_Name = "MachineGun";
	m_ReloadTimeClock.restart();
	m_ReloadTime = sf::seconds(0.2);
}

MachineGun::~MachineGun(){}

bool MachineGun::addItem(){
	Player* player = EntityFactory::getPlayer();

	if (!player->getData<WeaponData>("WeaponData")->getWeapon<MachineGun>("MachineGun")){
		player->getData<WeaponData>("WeaponData")->addWeapon(this);
	}
	return true;
}

void MachineGun::shoot(GameObject* gameObject){
	AmmoData* ammoData = gameObject->getData<AmmoData>("AmmoData");
	int maxAmmo = ammoData->getMaxAmmo(m_Name);
	int* currentAmmo = ammoData->getAmmo(m_Name);
	sf::Vector2f position = *gameObject->getData<PositionData>("PositionData")->getPosition();
	sf::Vector2f direction = *gameObject->getData<MovementData>("MovementData")->getDirection();

	if (m_ReloadTime.asSeconds() < m_ReloadTimeClock.getElapsedTime().asSeconds()){
		m_ReloadTimeClock.restart();
		if (*currentAmmo > 0){
			fire(ammoData, currentAmmo, maxAmmo, position, direction);
		}
		else{
			reload(ammoData, m_Name);
		}
	}
}

void MachineGun::fire(AmmoData* ammoData, int* currentAmmo, const int maxAmmo, sf::Vector2f pos, sf::Vector2f direction){
	EntityFactory::createGameObject(new Bullet(pos, direction, GameObject::Bullet));
	*ammoData->getAmmo(m_Name) -= 1;
}

void MachineGun::fire(int* currentAmmo, const int maxAmmo, sf::Vector2f pos, sf::Vector2f direction){
	EntityFactory::createGameObject(new Bullet(pos, direction, GameObject::Bullet));
}