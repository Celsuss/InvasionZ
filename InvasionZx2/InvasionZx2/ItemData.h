/*
	Holds item data
*/

#pragma once
#include "Data.h"

class Item;

class ItemData : public Data{
public:
	ItemData(Item* item);
	virtual ~ItemData();

	bool addItem();
private:
	Item* m_Item;
};