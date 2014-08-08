#include "SpriteData.h"
#include "PositionData.h"
#include "MovementData.h"
#include "GraphicManager.h"
#include "TextureManager.h"
#include <iostream>

SpriteData::SpriteData(std::string texture, PositionData* posData, MovementData* movementData, Layer layer){
	m_Sprite = new sf::Sprite;
	m_Texture = TextureManager::getTexture(texture);

	if (m_Texture == nullptr){
		m_Texture = new sf::Texture;
		if (m_Texture->loadFromFile("./Assets/Graphics/" + texture + ".png")){
			TextureManager::addTexture(texture, m_Texture);
		}
		else
			std::cout << "Fail to load asset " + texture + "\n";
	}
	
	m_Sprite->setTexture(*m_Texture);
	m_Sprite->setOrigin(m_Sprite->getLocalBounds().width / 2, m_Sprite->getLocalBounds().height / 2);
	m_Sprite->setPosition(*posData->getPosition());

	sf::Vector2f rotation = *movementData->getDirection();
	float angle = std::atan2(rotation.y, rotation.x)*convertToDegrees;
	m_Sprite->setRotation(angle);
	m_Layer = layer;
	m_Name = "SpriteData";
}

SpriteData::SpriteData(std::string texture, PositionData* posData, Layer layer){
	m_Sprite = new sf::Sprite;
	m_Texture = TextureManager::getTexture(texture);

	if (m_Texture == nullptr){
		m_Texture = new sf::Texture;
		if (m_Texture->loadFromFile("./Assets/Graphics/" + texture + ".png")){
			TextureManager::addTexture(texture, m_Texture);
		}
		else
			std::cout << "Fail to load asset " + texture + "\n";
	}

	m_Sprite->setTexture(*m_Texture);
	m_Sprite->setOrigin(m_Sprite->getLocalBounds().width / 2, m_Sprite->getLocalBounds().height / 2);
	m_Sprite->setPosition(*posData->getPosition());
	m_Layer = layer;
	m_Name = "SpriteData";
}

SpriteData::SpriteData(std::string texture, sf::Vector2f pos, Layer layer){
	m_Sprite = new sf::Sprite;
	m_Texture = TextureManager::getTexture(texture);

	if (m_Texture == nullptr){
		m_Texture = new sf::Texture;
		if (m_Texture->loadFromFile("./Assets/Graphics/" + texture + ".png")){
			TextureManager::addTexture(texture, m_Texture);
		}
		else
			std::cout << "Fail to load asset " + texture + "\n";
	}
	m_Sprite->setTexture(*m_Texture);
	m_Sprite->setPosition(pos);

	m_Layer = layer;
	m_Name = "SpriteData";
}

SpriteData::SpriteData(std::string texture, Layer layer){
	m_Sprite = new sf::Sprite;
	m_Texture = TextureManager::getTexture(texture);

	if (m_Texture == nullptr){
		m_Texture = new sf::Texture;
		if (m_Texture->loadFromFile("./Assets/Graphics/" + texture + ".png")){
			TextureManager::addTexture(texture, m_Texture);
		}
		else
			std::cout << "Fail to load asset " + texture + "\n";
	}
	
	m_Sprite->setTexture(*m_Texture);
	m_Sprite->setTextureRect(sf::IntRect(0, 0, GraphicManager::getWindow()->getSize().x, GraphicManager::getWindow()->getSize().y));
	m_Sprite->setPosition(sf::Vector2f(0, 0));
	m_Layer = layer;
	m_Name = "SpriteData";
}

SpriteData::~SpriteData(){}

void SpriteData::draw(){
	GraphicManager::draw(this);
}

sf::Sprite* SpriteData::getSprite(){
	return m_Sprite;
}

SpriteData::Layer* SpriteData::getLayer(){
	return &m_Layer;
}