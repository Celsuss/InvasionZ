#include "ShapeData.h"
#include "PositionData.h"
#include "MovementData.h"
#include "GraphicManager.h"

ShapeData::ShapeData(sf::Shape* shape, PositionData* posData, Layer layer){
	m_Shape = shape;
	m_Name = "ShapeData";
	m_Layer = layer;
}

ShapeData::ShapeData(sf::Shape* shape, Layer layer){
	m_Shape = shape;
	m_Name = "ShapeData";
	m_Layer = layer;
}

ShapeData::~ShapeData(){}

sf::Shape* ShapeData::getShape(){
	return m_Shape;
}

ShapeData::Layer* ShapeData::getLayer(){
	return &m_Layer;
}