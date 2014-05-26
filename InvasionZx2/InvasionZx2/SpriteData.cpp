#include "SpriteData.h"
#include "PositionData.h"
#include "MovementData.h"
#include "GraphicManager.h"
#include <iostream>

SpriteData::SpriteData(std::string texture, PositionData* posData, MovementData* movementData){
	if (m_Texture.loadFromFile("./Assets/Graphics/" + texture + ".png")){
		m_Sprite.setTexture(m_Texture);
		m_Sprite.setOrigin(m_Sprite.getLocalBounds().width / 2, m_Sprite.getLocalBounds().height / 2);
		m_Sprite.setPosition(*posData->getPosition());

		sf::Vector2f rotation = *movementData->getDirection();
		float angle = std::atan2(rotation.y, rotation.x)*convertToDegrees;
		m_Sprite.setRotation(angle);
	}
	else
		std::cout << "Fail to load asset " + texture + "\n";
	m_Name = "SpriteData";
}

SpriteData::SpriteData(std::string texture, PositionData* posData){
	if (m_Texture.loadFromFile("./Assets/Graphics/" + texture + ".png")){
		m_Sprite.setTexture(m_Texture);
		m_Sprite.setOrigin(m_Sprite.getLocalBounds().width / 2, m_Sprite.getLocalBounds().height / 2);
		m_Sprite.setPosition(*posData->getPosition());
	}
	else
		std::cout << "Fail to load asset " + texture + "\n";
	m_Name = "SpriteData";
}

SpriteData::SpriteData(std::string texture){
	if (m_Texture.loadFromFile("./Assets/Graphics/" + texture + ".png")){
		m_Sprite.setTexture(m_Texture);
		m_Sprite.setTextureRect(sf::IntRect(0, 0, GraphicManager::getWindow()->getSize().x, GraphicManager::getWindow()->getSize().y));
		m_Sprite.setPosition(sf::Vector2f(0,0));
	}
	else
		std::cout << "Fail to load asset " + texture + "\n";
	m_Name = "SpriteData";
}

SpriteData::~SpriteData(){}

sf::Sprite* SpriteData::getSprite(){
	return &m_Sprite;
}