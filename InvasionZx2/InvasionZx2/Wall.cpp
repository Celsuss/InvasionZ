#include "Wall.h"
#include "GraphicManager.h"

Wall::Wall(sf::Vector2f pos, float width, float height) :
m_PositionData(pos),
m_SpriteData("Wall", &m_PositionData){
	sf::IntRect* rect = new sf::IntRect(static_cast<sf::Vector2i>(*m_PositionData.getPosition()), sf::Vector2<int>(width, height));
	m_SpriteData.getSprite()->setTextureRect(*rect);
	m_SpriteData.getSprite()->setOrigin(m_SpriteData.getSprite()->getLocalBounds().width / 2, m_SpriteData.getSprite()->getLocalBounds().height / 2);
}

Wall::Wall(float x, float y, float width, float height) :
m_PositionData(sf::Vector2f(x,y)),
m_SpriteData("Wall", &m_PositionData){
	sf::IntRect* rect = new sf::IntRect(static_cast<sf::Vector2i>(*m_PositionData.getPosition()), sf::Vector2<int>(width, height));
	m_SpriteData.getSprite()->setTextureRect(*rect);
	m_SpriteData.getSprite()->setOrigin(m_SpriteData.getSprite()->getLocalBounds().width / 2, m_SpriteData.getSprite()->getLocalBounds().height / 2);
}

Wall::~Wall(){}

void Wall::update(){
	GraphicManager::draw(&m_SpriteData);
}