/*
	Holds all the textures used in the game
*/

#include "TextureManager.h"

TextureManager* TextureManager::m_Instance = new TextureManager();

TextureManager::TextureManager(){}

TextureManager::~TextureManager(){}

TextureManager* TextureManager::getInstance(){
	return m_Instance;
}

void TextureManager::addTexture(std::string name, sf::Texture* texture){
	getInstance()->m_Textures.insert(std::pair<std::string, sf::Texture*>(name, texture));
}

sf::Texture* TextureManager::getTexture(std::string name){
	for (auto i = getInstance()->m_Textures.begin(); i != getInstance()->m_Textures.end(); i++){
		if (i->first == name)
			return i->second;
	}
	return nullptr;
}