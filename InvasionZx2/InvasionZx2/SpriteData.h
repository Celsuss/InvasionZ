/*
	Holds sprite data
*/

#pragma once
#include "DrawableData.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

class PositionData;
class MovementData;

class SpriteData : public DrawableData{
public:
	enum Layer{
		Background,
		Normal,
		Foreground
	};

	SpriteData(std::string texture, PositionData* posData, MovementData* movementData, Layer layer = Layer::Normal);
	SpriteData(std::string texture, PositionData* posData, Layer layer = Layer::Normal);
	SpriteData(std::string texture, sf::Vector2f pos, Layer layer = Layer::Normal);
	SpriteData(std::string texture, Layer layer = Layer::Normal);
	virtual ~SpriteData();

	virtual void draw();
	sf::Sprite* getSprite();
	Layer* getLayer();
private:
	sf::Sprite* m_Sprite;
	sf::Texture* m_Texture;
	Layer m_Layer;
};