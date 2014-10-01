#include "MachineGunItem.h"
#include "CollisionData.h"
#include "PositionData.h"
#include "MachineGun.h"
#include "SpriteData.h"
#include "ItemData.h"

MachineGunItem::MachineGunItem(sf::Vector2f pos){
	m_Type = GameObject::Item;

	m_DataVector.push_back(new PositionData(pos));
	m_DataVector.push_back(new SpriteData("MachineGun", getData<PositionData>("PositionData")));
	m_DataVector.push_back(new CollisionData(CollisionData::Circle, false));
	m_DataVector.push_back(new ItemData(new MachineGun()));

	setDrawableData();
}

MachineGunItem::~MachineGunItem(){}