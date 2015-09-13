/*
	Spawn a zombie at the game objects position after a set amount of time
	Data needed: PositionData
*/

#include "SpawnerComponent.h"
#include "EntityFactory.h"
#include "PositionData.h"
#include "GameObject.h"
#include "Zombie.h"

#include "InputManager.h"	//For debug

SpawnerComponent::SpawnerComponent(PositionData* positionData){
	m_Name = "SpawnComponent";
	m_SpawnTime = sf::seconds(5.f);
	m_Clock.restart();

	m_PositionData = positionData;
}

SpawnerComponent::~SpawnerComponent(){
	
}

void SpawnerComponent::update(GameObject* gameObject){
	//if (m_Clock.getElapsedTime().asSeconds() > m_SpawnTime.asSeconds()){
	if (InputManager::isNineKeyPressed()){	//For debug
		EntityFactory::createGameObject(new Zombie(*m_PositionData->getPosition(), GameObject::Zombie));
		m_Clock.restart();
	}
}