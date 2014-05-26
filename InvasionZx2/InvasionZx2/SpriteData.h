#pragma once
#include "Data.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <string>

class PositionData;
class MovementData;

class SpriteData : public Data{
public:
	SpriteData(std::string texture, PositionData* posData, MovementData* movementData);
	SpriteData(std::string texture, PositionData* posData);
	SpriteData(std::string texture);
	virtual ~SpriteData();
	sf::Sprite* getSprite();
private:
	sf::Sprite m_Sprite;
	sf::Texture m_Texture;
};

