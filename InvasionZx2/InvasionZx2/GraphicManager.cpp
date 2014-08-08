#include "GraphicManager.h"
#include "ParticleEffectData.h"
#include "VertexArrayData.h"
#include "SpriteData.h"
#include "ShapeData.h"
#include "TextData.h"

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
	drawBackGround();
	drawNormalGround();
	drawForeGround();

	getInstance()->m_Window.display();
	getInstance()->m_Window.clear();
}

void GraphicManager::draw(SpriteData* spriteData){
	switch (*spriteData->getLayer()){
	case SpriteData::Background:
		getInstance()->m_Background.push_back(spriteData->getSprite());
		break;
	case SpriteData::Normal:
		getInstance()->m_NormalGround.push_back(spriteData->getSprite());
		break;
	case SpriteData::Foreground:
		getInstance()->m_Foreground.push_back(spriteData->getSprite());
		break;
	}	
}

void GraphicManager::draw(ShapeData* shapeData){
	switch (*shapeData->getLayer()){
	case ShapeData::Background:
		getInstance()->m_Background.push_back(shapeData->getShape());
		break;
	case ShapeData::Normal:
		getInstance()->m_NormalGround.push_back(shapeData->getShape());
		break;
	case ShapeData::Foreground:
		getInstance()->m_Foreground.push_back(shapeData->getShape());
		break;
	}
}

void GraphicManager::draw(VertexArrayData* vertexData){
	switch (*vertexData->getLayer()){
	case VertexArrayData::Background:
		getInstance()->m_Background.push_back(vertexData->getVertexArray());
		break;
	case VertexArrayData::Normal:
		getInstance()->m_NormalGround.push_back(vertexData->getVertexArray());
		break;
	case VertexArrayData::Foreground:
		getInstance()->m_Foreground.push_back(vertexData->getVertexArray());
		break;
	}
}

void GraphicManager::draw(TextData* textData){
	switch (*textData->getLayer()){
	case TextData::Background:
		getInstance()->m_Background.push_back(textData->getText());
		break;
	case TextData::Normal:
		getInstance()->m_NormalGround.push_back(textData->getText());
		break;
	case TextData::Foreground:
		getInstance()->m_Foreground.push_back(textData->getText());
		break;
	}
}

void GraphicManager::draw(ParticleEffectData* particleEffectData){
	switch (*particleEffectData->getLayer()){
	case ParticleEffectData::Background:
		for (int i = 0; i < particleEffectData->getSpriteVector()->size(); i++){
			getInstance()->m_Background.push_back(particleEffectData->getSprite(i));
		}
		break;
	case ParticleEffectData::Normal:
		for (int i = 0; i < particleEffectData->getSpriteVector()->size(); i++){
			getInstance()->m_NormalGround.push_back(particleEffectData->getSprite(i));
		}
		break;
	case ParticleEffectData::Foreground:
		for (int i = 0; i < particleEffectData->getSpriteVector()->size(); i++){
			getInstance()->m_Foreground.push_back(particleEffectData->getSprite(i));
		}
		break;
	}
}

sf::RenderWindow* GraphicManager::getWindow(){
	return &m_Instance->m_Window;
}

void GraphicManager::drawBackGround(){
	for (auto i = getInstance()->m_Background.begin(); i != getInstance()->m_Background.end(); i++){
		getInstance()->m_Window.draw(**i);
	}
	getInstance()->m_Background.clear();
}

void GraphicManager::drawNormalGround(){
	for (auto i = getInstance()->m_NormalGround.begin(); i != getInstance()->m_NormalGround.end(); i++){
		getInstance()->m_Window.draw(**i);
	}
	getInstance()->m_NormalGround.clear();
}

void GraphicManager::drawForeGround(){
	for (auto i = getInstance()->m_Foreground.begin(); i != getInstance()->m_Foreground.end(); i++){
		getInstance()->m_Window.draw(**i);
	}
	getInstance()->m_Foreground.clear();
}