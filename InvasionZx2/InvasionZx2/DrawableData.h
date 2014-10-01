#pragma once
#include "Data.h"

class DrawableData : public Data{
public:
	DrawableData();
	virtual ~DrawableData();
	virtual void draw() = 0;
};