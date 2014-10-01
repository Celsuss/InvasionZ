#include "PlayerPickupItem.h"
#include "ItemData.h"

PlayerPickupItem::PlayerPickupItem(){}

PlayerPickupItem::~PlayerPickupItem(){}

void PlayerPickupItem::addCollision(GameObject* obj){
	switch (obj->getType()){
	case GameObject::Player:
		if (this->getData<ItemData>("ItemData")->addItem())
			this->m_IsAlive = false;
		break;
	}
}