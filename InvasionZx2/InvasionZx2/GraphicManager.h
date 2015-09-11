#pragma once
#include "SFML/Graphics.hpp"

class TextData;
class ShapeData;
class SpriteData;
class VertexArrayData;
class ParticleEffectData;

class GraphicManager{
public:
	typedef std::vector<sf::Drawable*>DrawableList;

	static GraphicManager* getInstance();
	static void initialize();
	static void update();

	static void draw(SpriteData* spriteData);
	static void draw(ShapeData* shapeData);
	static void draw(VertexArrayData* vertexData);
	static void draw(TextData* textData);
	static void draw(ParticleEffectData* particleEffectData);
	static sf::RenderWindow* getWindow();
private:
	GraphicManager();
	~GraphicManager();
	static GraphicManager* m_Instance;

	static void drawBackGround();
	static void drawNormalGround();
	static void drawForeGround();

	sf::RenderWindow m_Window;
	DrawableList m_Background;
	DrawableList m_NormalGround;
	DrawableList m_Foreground;
};