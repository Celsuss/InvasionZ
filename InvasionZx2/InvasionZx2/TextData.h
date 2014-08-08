#pragma once
#include "Data.h"
#include "SFML/Graphics/Text.hpp"

class TextData : public Data{
public:
	enum Layer{
		Background,
		Normal,
		Foreground
	};

	TextData(sf::Vector2f pos, Layer layer = Layer::Normal);
	TextData(sf::Vector2f pos, bool centerOrigin, Layer layer = Layer::Normal);
	virtual ~TextData();

	void draw();
	sf::Text* getText();
	Layer* getLayer();
private:
	sf::Text* m_Text;
	Layer m_Layer;
};