#pragma once
#include "Data.h"
#include "SFML/Graphics/VertexArray.hpp"

class VertexArrayData : public Data {
public:
	enum Layer{
		Background,
		Normal,
		Foreground
	};
	VertexArrayData(sf::VertexArray* vaAray, Layer layer = Layer::Normal);
	virtual ~VertexArrayData();

	sf::VertexArray* getVertexArray();
	Layer* getLayer();
private:
	sf::VertexArray* m_vertexArray;
	Layer m_Layer;
};

