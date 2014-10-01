#pragma once
#include "SFML/System/Vector2.hpp"
#include <vector>

class GridNode;

class GridManager{
public:
	typedef std::vector<GridNode*>GridNodeVector;
	typedef std::vector<GridNodeVector>GridNodeMatrix;

	static GridManager* getInstance();
	static void initialize(sf::Vector2f startPos, sf::Vector2f endPos);
	static void update();

private:
	GridManager();
	~GridManager();
	static GridManager* m_Instance;

	static void draw();

	GridNodeMatrix m_GridTileMatrix;
};