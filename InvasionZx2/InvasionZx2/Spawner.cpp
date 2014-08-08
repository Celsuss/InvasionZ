#include "Spawner.h"
#include "ParticleEffectData.h"
#include "SpawnerComponent.h"
#include "PositionData.h"
#include "Zombie.h"

#include "SFML/System/Time.hpp"

Spawner::Spawner(sf::Vector2f pos, Type type){
	m_Type = type;

	m_DataVector.push_back(new PositionData(pos));
	m_DataVector.push_back(new ParticleEffectData("GreenFog", getData<PositionData>("PositionData")));

	m_ComponentVector.push_back(new SpawnerComponenter());
}

Spawner::~Spawner(){}