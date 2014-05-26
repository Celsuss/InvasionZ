#pragma once
#include "SFML\Graphics.hpp"
#include "SpriteData.h"

class GraphicManager{
public:
	static GraphicManager* getInstance();
	static void initialize();
	static void update();

	static void draw(SpriteData* spriteData);
	static sf::RenderWindow* getWindow();
private:
	GraphicManager();
	~GraphicManager();
	static GraphicManager* m_Instance;

	sf::RenderWindow m_Window;
};