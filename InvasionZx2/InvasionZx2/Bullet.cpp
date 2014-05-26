#include "Bullet.h"
#include "GraphicManager.h"
#include "MoveComponent.h"

Bullet::Bullet(sf::Vector2f pos, sf::Vector2f direction){
	m_DataVector.push_back(new MovementData(300, direction));
	m_DataVector.push_back(new PositionData(pos));
	m_DataVector.push_back(new SpriteData("Bullet", getData<PositionData>("PositionData")));

	m_ComponentVector.push_back(new MoveComponent());
}

Bullet::~Bullet(){}

void Bullet::update(){
	for (auto i = m_ComponentVector.begin(); i != m_ComponentVector.end(); i++){
		(*i)->update(this);
	}
	GraphicManager::draw(getData<SpriteData>("SpriteData"));
}