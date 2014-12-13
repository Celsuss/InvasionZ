#include "Spawner.h"
#include "ParticleEffectData.h"
#include "SpawnerComponent.h"
#include "PositionData.h"
#include "SpriteData.h"
#include "Zombie.h"

#include "SFML/System/Time.hpp"

Spawner::Spawner(sf::Vector2f pos, Type type){
	m_Type = type;

	PositionData* positionData = new PositionData(pos);
	//ParticleEffectData* particleEffectData = new ParticleEffectData("GreenFog", positionData);
	SpriteData* spriteData = new SpriteData("GreenFog", positionData);

	m_DataMap[positionData->getName()] = std::shared_ptr<PositionData>(positionData);
	m_DataMap[spriteData->getName()] = std::shared_ptr<SpriteData>(spriteData);

	SpawnerComponenter* spawnerComponent = new SpawnerComponenter(positionData);
	m_ComponentMap[spawnerComponent->getName()] = std::shared_ptr<SpawnerComponenter>(spawnerComponent);

	setDrawableData();
}

Spawner::~Spawner(){}

void Spawner::addCollision(GameObject* obj){}