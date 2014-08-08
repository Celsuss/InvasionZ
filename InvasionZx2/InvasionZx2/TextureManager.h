#pragma once
#include "SFML/Graphics/Texture.hpp"
#include <map>

//Manage so there is no duplicate textures

class TextureManager{
public:
	static TextureManager* getInstance();

	static void addTexture(std::string name, sf::Texture* texture);
	static sf::Texture* getTexture(std::string name);
private:
	TextureManager();
	~TextureManager();
	static TextureManager* m_Instance;

	std::map<std::string, sf::Texture*> m_Textures;
};

