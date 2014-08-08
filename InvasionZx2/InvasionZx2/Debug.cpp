#include "Debug.h"
#include "GraphicManager.h"
#include "VertexArrayData.h"

Debug* Debug::m_Instance = new Debug();

Debug::Debug(){}

Debug::~Debug(){}

Debug* Debug::getInstance(){
	return m_Instance;
}

void Debug::clear(){	
	for (auto i = getInstance()->m_VertexArrayDataVector.end(); i != getInstance()->m_VertexArrayDataVector.begin();)
	{
		i--;
		delete *i;
		i = getInstance()->m_VertexArrayDataVector.erase(i);
	}
	getInstance()->m_VertexArrayDataVector.clear();
}

void Debug::update(){
	for (auto i = getInstance()->m_VertexArrayDataVector.begin(); i != getInstance()->m_VertexArrayDataVector.end(); i++){
		GraphicManager::draw((*i));
	}
}

void Debug::drawLine(sf::Vector2f pos1, sf::Vector2f pos2, sf::Color c){
	sf::VertexArray line(sf::LinesStrip, 2);
	line[0].position = pos1;
	line[0].color = c;
	line[1].position = pos2;
	line[1].color = c;
	
	sf::VertexArray* linePtr = new sf::VertexArray(line);

	VertexArrayData* vertexData = new VertexArrayData(linePtr, VertexArrayData::Foreground);

	getInstance()->m_VertexArrayDataVector.push_back(vertexData);
}