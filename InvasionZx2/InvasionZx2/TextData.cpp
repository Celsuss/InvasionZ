/*
	Holds text data
*/

#include "TextData.h"
#include "GraphicManager.h"
#include "Shared.h"

TextData::TextData(sf::Vector2f pos, Layer layer){
	m_Text = new sf::Text();
	m_Text->setFont(*Shared::getFont());
	m_Text->setCharacterSize(14);
	m_Text->setColor(sf::Color::Black);
	m_Text->setStyle(sf::Text::Regular);
	m_Text->setPosition(pos);
	m_Layer = layer;
	m_Name = "TextData";
}

TextData::TextData(sf::Vector2f pos, bool centerOrigin, Layer layer){
	m_Text = new sf::Text();
	m_Text->setFont(*Shared::getFont());
	m_Text->setCharacterSize(14);
	m_Text->setColor(sf::Color::Black);
	m_Text->setStyle(sf::Text::Regular);
	m_Text->setPosition(pos);
	m_Layer = layer;
	m_Name = "TextData";
}

TextData::~TextData(){}

void TextData::draw(){
	GraphicManager::draw(this);
}

sf::Text* TextData::getText(){
	return m_Text;
}

TextData::Layer* TextData::getLayer(){
	return &m_Layer;
}