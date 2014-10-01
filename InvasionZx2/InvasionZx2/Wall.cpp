#include "Wall.h"
#include "CollisionData.h"
#include "GraphicManager.h"
#include "VertexArrayData.h"

Wall::Wall(sf::Vector2f pos, float width, float height, Type type){
	m_Type = type;

	/*sf::IntRect* rect = new sf::IntRect(static_cast<sf::Vector2i>(*m_PositionData.getPosition()), sf::Vector2<int>(width, height));
	m_SpriteData.getSprite()->setTextureRect(*rect);
	m_SpriteData.getSprite()->setOrigin(m_SpriteData.getSprite()->getLocalBounds().width / 2, m_SpriteData.getSprite()->getLocalBounds().height / 2);

	m_DataVector.push_back(new CollisionData(CollisionData::Box));
	m_DataVector.push_back(&m_SpriteData);*/

	//Create a copy of pos for PositionData
	sf::Vector2f positionDataPos = pos;

	sf::VertexArray line(sf::LinesStrip, 2);
	line[0].position = pos;
	
	if (width == 0)
		pos.y += height;
	else
		pos.x += width;

	line[1].position = pos;
	line[0].color = sf::Color::Black;
	line[1].color = sf::Color::Black;

	sf::VertexArray* wall = new sf::VertexArray(line);

	m_DataVector.push_back(new CollisionData(CollisionData::Box));
	m_DataVector.push_back(new PositionData(positionDataPos));
	m_DataVector.push_back(new VertexArrayData(wall));

	setDrawableData();
}

Wall::~Wall(){}

void Wall::addCollision(GameObject* obj){}

void Wall::drawWall(){
	GraphicManager::draw(getData<VertexArrayData>("VertexArrayData"));
}