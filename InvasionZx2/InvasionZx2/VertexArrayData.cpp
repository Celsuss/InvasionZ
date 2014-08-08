#include "VertexArrayData.h"

VertexArrayData::VertexArrayData(sf::VertexArray* vArray, Layer layer){
	m_vertexArray = vArray;
	m_Name = "VertexData";
	m_Layer = layer;
}

VertexArrayData::~VertexArrayData(){}

sf::VertexArray* VertexArrayData::getVertexArray(){
	return m_vertexArray;
}

VertexArrayData::Layer* VertexArrayData::getLayer(){
	return &m_Layer;
}