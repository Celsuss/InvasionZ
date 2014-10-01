#include "GridNode.h"
#include "SpriteData.h"
#include "GraphicManager.h"

GridNode::GridNode(sf::Vector2f pos){
	m_SpriteData = new SpriteData("Grid_G", pos, SpriteData::Background);
}

GridNode::~GridNode(){}

void GridNode::draw(){
	GraphicManager::draw(m_SpriteData);
}

SpriteData* GridNode::getSpriteData(){
	return m_SpriteData;
}