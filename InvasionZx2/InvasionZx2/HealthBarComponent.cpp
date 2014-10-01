#include "HealthBarComponent.h"
#include "SFML/Graphics/Shape.hpp"
#include "GraphicManager.h"
#include "ItemManager.h"
#include "SpriteData.h"
#include "GameObject.h"
#include "HealthData.h"
#include "ShapeData.h"

const int healthBarPosOffset = -30;

HealthBarComponent::HealthBarComponent(HealthData* healthData, PositionData* positionData){
	m_Name = "HealthBarComponent";

	m_HealthData = healthData;
	m_PositionData = positionData;
	//----HealthBarBox
	sf::RectangleShape* healthBarBox = new sf::RectangleShape();

	healthBarBox->setSize(sf::Vector2f(30, 6));
	healthBarBox->setOrigin(healthBarBox->getLocalBounds().width / 2, healthBarBox->getLocalBounds().height / 2);

	sf::Color colorGrey = sf::Color(128, 128, 128);
	healthBarBox->setFillColor(colorGrey);

	healthBarBox->setOutlineThickness(1);
	healthBarBox->setOutlineColor(sf::Color::Black);

	m_HealthBarBoxShape = new ShapeData(healthBarBox, ShapeData::Foreground);
	//----/HealthBarBox

	//----HealthBar
	sf::RectangleShape* healthBox = new sf::RectangleShape();

	healthBox->setSize(sf::Vector2f(30, 6));
	healthBox->setOrigin(0, healthBox->getLocalBounds().height / 2);

	healthBox->setFillColor(sf::Color::Green);

	m_HealthBarShape = new ShapeData(healthBox, ShapeData::Foreground);
	//----/HealthBar
}

HealthBarComponent::~HealthBarComponent(){}

void HealthBarComponent::update(GameObject* gameObject){
	if (!checkIfAlive(gameObject))
		return;
	setPosition(gameObject);
	updateHealthBar(gameObject);
	drawHealthBar(gameObject);
}

bool HealthBarComponent::checkIfAlive(GameObject* gameObject){
	float health = *m_HealthData->getHealth();
	if (health <= 0){
		if (gameObject->getType() == GameObject::Zombie)
			ItemManager::dropItem(*m_PositionData->getPosition());

		gameObject->kill();
		return false;
	}
	return true;
}

void HealthBarComponent::setPosition(GameObject* gameObject){
	sf::Vector2f pos = *m_PositionData->getPosition();
	pos.y += healthBarPosOffset;
	m_HealthBarBoxShape->getShape()->setPosition(pos);

	pos.x -= (m_HealthBarShape->getShape()->getLocalBounds().width / 2);

	m_HealthBarShape->getShape()->setPosition(pos);
}

void HealthBarComponent::updateHealthBar(GameObject* gameObject){
	float health = *m_HealthData->getHealth();
	float maxHealth = *m_HealthData->getMaxHealth();
	float healthPercentages = maxHealth * (health / 100);

	m_HealthBarShape->getShape()->setScale(health*0.01, 1);

	updateHealthBarColor(healthPercentages);
}

void HealthBarComponent::updateHealthBarColor(float healthPercentages){
	if (healthPercentages <= 33)
		m_HealthBarShape->getShape()->setFillColor(sf::Color::Red);
	else if (healthPercentages <= 66)
		m_HealthBarShape->getShape()->setFillColor(sf::Color::Yellow);
	else if (healthPercentages <= 100)
		m_HealthBarShape->getShape()->setFillColor(sf::Color::Green);
}

void HealthBarComponent::drawHealthBar(GameObject* gameObject){
	float health = *m_HealthData->getHealth();
	float maxHealth = *m_HealthData->getMaxHealth();

	//if (health != maxHealth){
		GraphicManager::draw(m_HealthBarBoxShape);
		GraphicManager::draw(m_HealthBarShape);
	//}
}