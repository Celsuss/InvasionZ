#pragma once
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Font.hpp"

class Shared{
public:
	~Shared();
	static Shared* getInstance();
	static sf::Vector2f normalizeVector(sf::Vector2f vec);
	static bool isLineOfSight(sf::Vector2f pos1, sf::Vector2f pos2, float wallMinX, float wallMaxX, float wallMinY, float wallMaxY);
	static const sf::Font* getFont();
private:
	Shared();
	static Shared* m_Instance;

	sf::Font* m_Font;
};