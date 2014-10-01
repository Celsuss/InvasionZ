#include "VertexArrayData.h"
#include "GraphicManager.h"

VertexArrayData::VertexArrayData(sf::VertexArray* vArray, Layer layer){
	m_vertexArray = vArray;
	m_Name = "VertexArrayData";
	m_Layer = layer;
}

VertexArrayData::~VertexArrayData(){}

void VertexArrayData::draw(){
	GraphicManager::draw(this);
}

sf::VertexArray* VertexArrayData::getVertexArray(){
	return m_vertexArray;
}

VertexArrayData::Layer* VertexArrayData::getLayer(){
	return &m_Layer;
}