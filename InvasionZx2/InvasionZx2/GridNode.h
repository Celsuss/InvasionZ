#pragma once
#include "SFML/System/Vector2.hpp"

class SpriteData;
class PositionData;

class GridNode{
public:
	GridNode(sf::Vector2f pos, sf::Vector2f gridPos);
	~GridNode();
	void draw();
	SpriteData* getSpriteData();
	PositionData* getPositionData();

	GridNode* getParentNode();
	sf::Vector2f* getGridPosition();
	float getGCost();
	float getHCost();
	float getFCost();
	bool isWalkable();
	void setIsWalkable(bool walkable);
	void setGCost(float g);
	void setHCost(float h);
	void setParentNode(GridNode* parent);
	void clearValues();
private:
	SpriteData* m_SpriteData;
	PositionData* m_PositionData;

	sf::Vector2f* m_GridPos;
	GridNode* m_ParentNode;
	bool m_IsWalkable;
	float m_GCost;
	float m_HCost;
	float m_FCost;

	SpriteData* m_TmpSpriteData;
};