#include "Gun.h"
#include "Bullet.h"
#include "AmmoData.h"
#include "GameObject.h"
#include "InputManager.h"
#include "EntityFactory.h"

Gun::Gun(){
	m_Name = "Gun";
}

Gun::~Gun(){}

void Gun::shoot(GameObject* gameObject){
	AmmoData* ammoData = gameObject->getData<AmmoData>("AmmoData");
	int maxAmmo = ammoData->getMaxAmmo(m_Name);
	int* currentAmmo = ammoData->getAmmo(m_Name);
	sf::Vector2f position = *gameObject->getData<PositionData>("PositionData")->getPosition();
	sf::Vector2f direction = *gameObject->getData<MovementData>("MovementData")->getDirection();

	if (InputManager::isShootKeyPressed()){
		if (*currentAmmo > 0){
			fire(currentAmmo, maxAmmo, position, direction);
		}
		else{
			reload(ammoData, m_Name);
		}
	}	
}

void Gun::fire(int* currentAmmo, const int maxAmmo, sf::Vector2f pos, sf::Vector2f direction){
	EntityFactory::createBullet(pos, direction);
}