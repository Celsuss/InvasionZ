/*
	Holds vertex array data
*/

#pragma once
#include "DrawableData.h"
#include "SFML/Graphics/VertexArray.hpp"

class VertexArrayData : public DrawableData{
public:
	enum Layer{
		Background,
		Normal,
		Foreground
	};
	VertexArrayData(sf::VertexArray* vaAray, Layer layer = Layer::Normal);
	virtual ~VertexArrayData();

	virtual void draw();

	sf::VertexArray* getVertexArray();
	Layer* getLayer();
private:
	sf::VertexArray* m_vertexArray;
	Layer m_Layer;
};

