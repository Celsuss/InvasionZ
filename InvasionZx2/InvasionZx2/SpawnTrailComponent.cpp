/*
	Spawn a trail gameobject at the gameobjects position after a set amount of time
	Data needed: PositionData
*/

#include "SpawnTrailComponent.h"
#include "EntityFactory.h"
#include "Level.h"
#include "Trail.h"

SpawnTrailComponent::SpawnTrailComponent(PositionData* positionData){
	m_Name = "ShootComponent";
	m_SpawnTime = sf::seconds(0.5);

	m_PositionData = positionData;
}

SpawnTrailComponent::~SpawnTrailComponent(){}

void SpawnTrailComponent::update(GameObject* gameobject){
	if (m_Clock.getElapsedTime().asSeconds() > m_SpawnTime.asSeconds()){
		sf::Vector2f pos = *m_PositionData->getPosition();
		EntityFactory::createGameObject(new Trail(pos, GameObject::Other));
		m_Clock.restart();
	}
}