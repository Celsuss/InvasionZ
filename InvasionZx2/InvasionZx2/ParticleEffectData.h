#pragma once
#include "Data.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

class PositionData;

class ParticleEffectData : public Data{
public:
	enum Layer{
		Background,
		Normal,
		Foreground
	};

	typedef std::vector<sf::Sprite*>SpriteVector;

	ParticleEffectData(std::string texture, PositionData* posData, Layer layer = Layer::Normal);
	virtual ~ParticleEffectData();

	void draw();
	void spawnParticle(sf::Vector2f pos);
	SpriteVector* getSpriteVector();
	sf::Sprite* getSprite(int index);
	Layer* getLayer();
private:
	SpriteVector m_SpriteVector;
	sf::Texture* m_Texture;
	Layer m_Layer;
};