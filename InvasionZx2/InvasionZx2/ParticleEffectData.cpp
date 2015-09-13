/*
	Holds particle effect data
*/

#include "ParticleEffectData.h"
#include "GraphicManager.h"
#include "PositionData.h"
#include <iostream>

ParticleEffectData::ParticleEffectData(std::string texture, PositionData* posData, Layer layer){
	m_Texture = new sf::Texture;
	if (m_Texture->loadFromFile("./Assets/Graphics/" + texture + ".png")){
		m_SpriteVector.push_back(new sf::Sprite(*m_Texture));
		m_SpriteVector.back()->setPosition(*posData->getPosition());
	}
	else
		std::cout << "Fail to load asset " + texture + "\n";
	m_Layer = layer;
	m_Name = "ParticleEffectData";
}

ParticleEffectData::~ParticleEffectData(){}

void ParticleEffectData::draw(){
	GraphicManager::draw(this);
}

void ParticleEffectData::spawnParticle(sf::Vector2f pos){
	m_SpriteVector.push_back(new sf::Sprite(*m_Texture));
	m_SpriteVector.back()->setPosition(pos);
}

ParticleEffectData::SpriteVector* ParticleEffectData::getSpriteVector(){
	return &m_SpriteVector;
}

sf::Sprite* ParticleEffectData::getSprite(int index){
	return m_SpriteVector[index];
}

ParticleEffectData::Layer* ParticleEffectData::getLayer(){
	return &m_Layer;
}