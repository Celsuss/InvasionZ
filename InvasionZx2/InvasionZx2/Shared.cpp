#include "Shared.h"
#include <iostream>
#include <math.h>

Shared* Shared::m_Instance = new Shared();

Shared::Shared(){
	m_Font = new sf::Font();
	if (!m_Font->loadFromFile("./Assets/Graphics/arial.ttf")){
		std::cout << "Failed to load font.\n";
	}
}

Shared::~Shared(){}

Shared* Shared::getInstance(){
	return m_Instance;
}

sf::Vector2f Shared::normalizeVector(sf::Vector2f vec){
	float magnitude = sqrt((vec.x*vec.x) + (vec.y*vec.y));
	vec.x /= magnitude;
	vec.y /= magnitude;
	return vec;
}

bool Shared::isLineOfSight(sf::Vector2f pos1, sf::Vector2f pos2, float wallMinX, float wallMaxX, float wallMinY, float wallMaxY){
	float intersepts = 2;

	//Find min and max
	float minX = pos1.x;
	float maxX = pos2.x;
	if (pos1.x > pos2.x){
		minX = pos2.x;
		maxX = pos1.x;
	}

	float minY = pos1.y;
	float maxY = pos2.y;

	if (minY > maxY){
		minY = pos2.y;
		maxY = pos1.y;
	}

	//----Find intersepts
	if (maxX > wallMaxX)
		maxX = wallMaxX;

	if (minX < wallMinX)
		minX = wallMinX;

	if (minX > maxX)		 // If not intercept
		intersepts--;

	if (maxY > wallMaxY)
		maxY = wallMaxY;

	if (minY < wallMinY)
		minY = wallMinY;

	if (minY > maxY)		 // If not intercept
		intersepts--;

	//----/Find intersepts

	if (intersepts > 1)
		return false;
	else
		return true;
}

const sf::Font* Shared::getFont(){
	return getInstance()->m_Font;
}