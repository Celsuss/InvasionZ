#include "GridManager.h"
#include "SpriteData.h"
#include "GridNode.h"

GridManager* GridManager::m_Instance = new GridManager();

GridManager::GridManager(){}

GridManager::~GridManager(){}

GridManager* GridManager::getInstance(){
	return m_Instance;
}

void GridManager::initialize(sf::Vector2f startPos, sf::Vector2f endPos){
	GridNode* gridNode = new GridNode(startPos);
	float gridNodeRadie = gridNode->getSpriteData()->getSprite()->getLocalBounds().height;
	float matrixRows = (endPos.y - startPos.y) / gridNodeRadie;
	float matrixColumms = (endPos.x - startPos.x) / gridNodeRadie;
	delete gridNode;

	getInstance()->m_GridTileMatrix.resize(matrixRows);

	sf::Vector2f pos = startPos;
	for (int i = 0; i < getInstance()->m_GridTileMatrix.size(); i++){
		for (int j = 0; j < matrixColumms; j++){
			getInstance()->m_GridTileMatrix[i].push_back(new GridNode(pos));
			pos.x += gridNodeRadie;
		}
		pos.y += gridNodeRadie;
		pos.x = startPos.x;
	}
}

void GridManager::update(){
	draw();
}

void GridManager::draw(){
	for (int i = 0; i < getInstance()->m_GridTileMatrix.size(); i++){
		for (int j = 0; j < getInstance()->m_GridTileMatrix[i].size(); j++){
			getInstance()->m_GridTileMatrix[i][j]->draw();
		}
	}
}