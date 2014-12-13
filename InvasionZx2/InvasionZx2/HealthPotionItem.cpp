#include "HealthPotionItem.h"
#include "CollisionDetectionManager.h"
#include "HealthPotion.h"
#include "ItemData.h"

HealthPotionItem::HealthPotionItem(sf::Vector2f pos){
	m_Type = GameObject::Item;

	PositionData* positionData = new PositionData(pos);
	SpriteData* spriteData = new SpriteData("HealthPotion", positionData);
	CollisionData* collisionData = new CollisionData(CollisionData::Circle, false);
	ItemData* itemData = new ItemData(new HealthPotion());

	m_DataMap[positionData->getName()] = std::shared_ptr<PositionData>(positionData);
	m_DataMap[spriteData->getName()] = std::shared_ptr<SpriteData>(spriteData);
	m_DataMap[collisionData->getName()] = std::shared_ptr<CollisionData>(collisionData);
	m_DataMap[itemData->getName()] = std::shared_ptr<ItemData>(itemData);

	setDrawableData();
}

HealthPotionItem::~HealthPotionItem(){}