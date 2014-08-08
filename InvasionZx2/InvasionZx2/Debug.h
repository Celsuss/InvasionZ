#pragma once
#include "SFML/Graphics/Vertex.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/System/Vector2.hpp"
#include <vector>
#include <map>

class GameObject;
class VertexArrayData;

class Debug {
public:
	typedef std::vector<VertexArrayData*> VertexArrayDataVector;

	static Debug* getInstance();
	static void clear();
	static void update();
	
	static void drawLine(sf::Vector2f pos1, sf::Vector2f pos2, sf::Color c);
private:
	Debug();
	~Debug();
	static Debug* m_Instance;
	VertexArrayDataVector m_VertexArrayDataVector;
};

