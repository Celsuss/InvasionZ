#include "SpawnerComponent.h"
#include "EntityFactory.h"
#include "PositionData.h"
#include "GameObject.h"
#include "Zombie.h"

SpawnerComponenter::SpawnerComponenter(PositionData* positionData){
	m_Name = "SpawnComponent";
	m_SpawnTime = sf::seconds(5.f);
	m_Clock.restart();

	m_PositionData = positionData;
}

SpawnerComponenter::~SpawnerComponenter(){
	
}

void SpawnerComponenter::update(GameObject* gameObject){
	if (m_Clock.getElapsedTime().asSeconds() > m_SpawnTime.asSeconds()){
		EntityFactory::createGameObject(new Zombie(*m_PositionData->getPosition(), GameObject::Zombie));
		m_Clock.restart();
	}
}