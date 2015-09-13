/*
	Holds shape data
*/

#pragma once
#include "Data.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Shape.hpp"
#include <string>

class PositionData;
class MovementData;

class ShapeData : public Data{
public:
	enum Layer{
		Background,
		Normal,
		Foreground
	};

	ShapeData(sf::Shape* shape, PositionData* posData, Layer layer = Layer::Normal);
	ShapeData(sf::Shape* shape, Layer layer = Layer::Normal);
	virtual ~ShapeData();

	sf::Shape* getShape();
	Layer* getLayer();
private:
	sf::Shape* m_Shape;
	Layer m_Layer;
};