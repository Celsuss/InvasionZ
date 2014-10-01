#include "HealthPotionItem.h"
#include "CollisionDetectionManager.h"
#include "HealthPotion.h"
#include "ItemData.h"

HealthPotionItem::HealthPotionItem(sf::Vector2f pos){
	m_Type = GameObject::Item;

	m_DataVector.push_back(new PositionData(pos));
	m_DataVector.push_back(new SpriteData("HealthPotion", getData<PositionData>("PositionData")));
	m_DataVector.push_back(new CollisionData(CollisionData::Circle, false));
	m_DataVector.push_back(new ItemData(new HealthPotion()));

	setDrawableData();
}

HealthPotionItem::~HealthPotionItem(){}