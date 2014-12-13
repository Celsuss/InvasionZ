#include "MachineGunItem.h"
#include "CollisionData.h"
#include "PositionData.h"
#include "MachineGun.h"
#include "SpriteData.h"
#include "ItemData.h"

MachineGunItem::MachineGunItem(sf::Vector2f pos){
	m_Type = GameObject::Item;

	PositionData* positionData = new PositionData(pos);
	SpriteData* spriteData = new SpriteData("MachineGun", positionData);
	CollisionData* collisionData = new CollisionData(CollisionData::Circle, false);
	ItemData* itemData = new ItemData(new MachineGun());

	m_DataMap[positionData->getName()] = std::shared_ptr<PositionData>(positionData);
	m_DataMap[spriteData->getName()] = std::shared_ptr<SpriteData>(spriteData);
	m_DataMap[collisionData->getName()] = std::shared_ptr<CollisionData>(collisionData);
	m_DataMap[itemData->getName()] = std::shared_ptr<ItemData>(itemData);

	setDrawableData();
}

MachineGunItem::~MachineGunItem(){}