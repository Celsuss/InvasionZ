#include "Spawner.h"
#include "ParticleEffectData.h"
#include "SpawnerComponent.h"
#include "PositionData.h"
#include "Zombie.h"

#include "SFML/System/Time.hpp"

Spawner::Spawner(sf::Vector2f pos, Type type){
	m_Type = type;

	PositionData* positionData = new PositionData(pos);
	ParticleEffectData* particleEffectData = new ParticleEffectData("GreenFog", positionData);

	m_DataVector.push_back(positionData);
	m_DataVector.push_back(particleEffectData);

	m_ComponentVector.push_back(new SpawnerComponenter(positionData));

	setDrawableData();
}

Spawner::~Spawner(){}

void Spawner::addCollision(GameObject* obj){}