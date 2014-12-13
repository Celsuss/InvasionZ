#include "Wall.h"
#include "CollisionData.h"
#include "GraphicManager.h"
#include "VertexArrayData.h"

Wall::Wall(LuaConfig config, Type type){
	m_Type = type;

	int posX = config.getInt("POSITION_X");
	int posY = config.getInt("POSITION_Y");
	int width = config.getInt("WIDTH");
	int height = config.getInt("HEIGHT");
	int thickness = config.getInt("THICKNESS");

	sf::Vector2f pos(posX, posY);

	sf::VertexArray line(sf::LinesStrip, 2);

	sf::Vector2f tmpPos(pos);
	for (int i = 0; i < 2; i++){
		line[i].position = tmpPos;
		line[i].color = sf::Color::Black;
		tmpPos.y += height;
		tmpPos.x += width;
	}


	sf::VertexArray* wall = new sf::VertexArray(line);

	CollisionData* collisionData = new CollisionData(CollisionData::Line);
	PositionData* positionData = new PositionData(pos);
	VertexArrayData* vertexArrayData = new VertexArrayData(wall);

	m_DataMap[collisionData->getName()] = std::shared_ptr<CollisionData>(collisionData);
	m_DataMap[positionData->getName()] = std::shared_ptr<PositionData>(positionData);
	m_DataMap[vertexArrayData->getName()] = std::shared_ptr<VertexArrayData>(vertexArrayData);

	setDrawableData();
}

Wall::~Wall(){}

void Wall::addCollision(GameObject* obj){}

void Wall::drawWall(){
	GraphicManager::draw(getData<VertexArrayData>("VertexArrayData"));
}