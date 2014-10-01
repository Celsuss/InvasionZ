#pragma once

class Item{
public:
	Item();
	virtual ~Item();
	virtual bool addItem() = 0;
};