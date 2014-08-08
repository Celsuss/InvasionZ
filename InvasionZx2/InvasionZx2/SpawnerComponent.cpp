#include "SpawnerComponent.h"
#include "EntityFactory.h"
#include "PositionData.h"
#include "GameObject.h"
#include "Zombie.h"

SpawnerComponenter::SpawnerComponenter(GameObject* gameObject){
	m_Name = "SpawnComponent";
	m_SpawnTime = sf::seconds(5.f);
	m_Clock.restart();
}

SpawnerComponenter::SpawnerComponenter(){
	m_Name = "SpawnComponent";
	m_SpawnTime = sf::seconds(5.f);
	
	m_Clock.restart();
}

SpawnerComponenter::~SpawnerComponenter(){
	
}

void SpawnerComponenter::update(GameObject* gameObject){
	if (m_Clock.getElapsedTime().asSeconds() > m_SpawnTime.asSeconds()){
		EntityFactory::createGameObject(new Zombie(*gameObject->getData<PositionData>("PositionData")->getPosition(), GameObject::Zombie));
		m_Clock.restart();
	}
}