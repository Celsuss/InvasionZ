#include "Trail.h"
#include "KillAfterTimeComponent.h"
#include "GraphicManager.h"
#include "PositionData.h"
#include "SpriteData.h"
#include "Component.h"

Trail::Trail(sf::Vector2f pos, Type type){
	m_Type = type;

	PositionData* positionData = new PositionData(pos);
	SpriteData* spriteData = new SpriteData("Trail", getData<PositionData>("PositionData"), SpriteData::Background);

	m_DataMap[positionData->getName()] = std::shared_ptr<PositionData>(positionData);
	m_DataMap[spriteData->getName()] = std::shared_ptr<SpriteData>(spriteData);

	KillAfterTimeComponent* killAfterTimeComponent = new KillAfterTimeComponent(sf::seconds(1.5));

	m_ComponentMap[killAfterTimeComponent->getName()] = std::shared_ptr<KillAfterTimeComponent>(killAfterTimeComponent);

	setDrawableData();
}

Trail::~Trail(){}

void Trail::addCollision(GameObject* obj){}