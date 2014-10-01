#include "ItemData.h"
#include "Item.h"

ItemData::ItemData(Item* item){
	m_Name = "ItemData";
	m_Item = item;
}

ItemData::~ItemData(){}

bool ItemData::addItem(){
	return m_Item->addItem();
}