#include "Trail.h"
#include "KillAfterTimeComponent.h"
#include "GraphicManager.h"
#include "PositionData.h"
#include "SpriteData.h"
#include "Component.h"

Trail::Trail(sf::Vector2f pos, Type type){
	m_Type = type;

	m_DataVector.push_back(new PositionData(pos));
	m_DataVector.push_back(new SpriteData("Trail", getData<PositionData>("PositionData"), SpriteData::Background));

	m_ComponentVector.push_back(new KillAfterTimeComponent(sf::seconds(1.5)));

	setDrawableData();
}

Trail::~Trail(){}

void Trail::addCollision(GameObject* obj){}