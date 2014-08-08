#include "SpawnTrailComponent.h"
#include "EntityFactory.h"
#include "Level.h"
#include "Trail.h"

SpawnTrailComponent::SpawnTrailComponent(){
	m_Name = "ShootComponent";
	m_SpawnTime = sf::seconds(0.5);
}

SpawnTrailComponent::~SpawnTrailComponent(){}

void SpawnTrailComponent::update(GameObject* gameobject){
	if (m_Clock.getElapsedTime().asSeconds() > m_SpawnTime.asSeconds()){
		sf::Vector2f pos = *gameobject->getData<PositionData>("PositionData")->getPosition();
		EntityFactory::createGameObject(new Trail(pos, GameObject::Other));
		m_Clock.restart();
	}
}