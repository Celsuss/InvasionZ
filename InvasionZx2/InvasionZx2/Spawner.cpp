/*
	Spawner gameobject, spawns zombies at it's location after set amount of time
	Components used: SpawnerComponent
	Data used: PositionData, SpriteData
*/

#include "Spawner.h"
#include "SFML/System/Time.hpp"
#include "ParticleEffectData.h"
#include "SpawnerComponent.h"
#include "PositionData.h"
#include "SpriteData.h"
#include "Zombie.h"

Spawner::Spawner(sf::Vector2f pos, Type type){
	m_Type = type;

	PositionData* positionData = new PositionData(pos);
	//ParticleEffectData* particleEffectData = new ParticleEffectData("GreenFog", positionData);
	SpriteData* spriteData = new SpriteData("GreenFog", positionData);

	m_DataMap[positionData->getName()] = std::shared_ptr<PositionData>(positionData);
	m_DataMap[spriteData->getName()] = std::shared_ptr<SpriteData>(spriteData);

	SpawnerComponent* spawnerComponent = new SpawnerComponent(positionData);
	m_ComponentMap[spawnerComponent->getName()] = std::shared_ptr<SpawnerComponent>(spawnerComponent);

	setDrawableData();
}

Spawner::~Spawner(){}

void Spawner::addCollision(GameObject* obj){}