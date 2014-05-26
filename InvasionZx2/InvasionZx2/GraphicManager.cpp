#include "GraphicManager.h"

GraphicManager* GraphicManager::m_Instance = new GraphicManager();

GraphicManager::GraphicManager(){}

GraphicManager::~GraphicManager(){}

GraphicManager* GraphicManager::getInstance(){
	return m_Instance;
}

void GraphicManager::initialize(){
	getInstance()->m_Window.create(sf::VideoMode(1200, 900), "InvasionZx2");
}

void GraphicManager::update(){
	getInstance()->m_Window.display();
	getInstance()->m_Window.clear();
}

void GraphicManager::draw(SpriteData* spriteData){
	getInstance()->m_Window.draw(*spriteData->getSprite());
}

sf::RenderWindow* GraphicManager::getWindow(){
	return &m_Instance->m_Window;
}