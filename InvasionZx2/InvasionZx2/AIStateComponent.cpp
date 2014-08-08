#include "AIStateComponent.h"
#include "EntityFactory.h"
#include "PositionData.h"
#include "SpriteData.h"
#include "GameObject.h"
#include "AIState.h"
#include "Player.h"
#include "Shared.h"
#include "Wall.h"

AIStateComponent::AIStateComponent(AIState* startingState){
	m_ActiveState = startingState;
}

AIStateComponent::~AIStateComponent(){}

void AIStateComponent::update(GameObject* gameObject){
	if (m_ActiveState != nullptr)
		m_ActiveState->update(gameObject);
}

void AIStateComponent::changeState(AIState* state){
	m_ActiveState->exitState();

	m_PreviousState = m_ActiveState;
	m_ActiveState = state;

	m_ActiveState->enterState();
}

bool AIStateComponent::isInLineOfSight(GameObject* gameObject){
	sf::Vector2f pos1 = *gameObject->getData<PositionData>("PositionData")->getPosition();
	sf::Vector2f pos2 = *EntityFactory::getInstance()->getPlayer()->getData<PositionData>("PositionData")->getPosition();

	float wallCount = EntityFactory::getInstance()->m_Level->getWallCount();

	for (int i = 0; i < wallCount; i++){
		Wall* wall = static_cast<Wall*>(EntityFactory::getInstance()->m_Level->getGameObject(GameObject::Wall, i));
		SpriteData* spriteData = wall->getData<SpriteData>("SpriteData");
		sf::Sprite* sprite = wall->getData<SpriteData>("SpriteData")->getSprite();
		sf::Vector2f wallPos = wall->getData<SpriteData>("SpriteData")->getSprite()->getPosition();
		sf::FloatRect wallRect = wall->getData<SpriteData>("SpriteData")->getSprite()->getLocalBounds();

		float wallMinX = wallPos.x + (wallRect.height / 2);
		float wallMaxX = wallPos.x - (wallRect.height / 2);
		float wallMinY = wallPos.y + (wallRect.width / 2);
		float wallMaxY = wallPos.y - (wallRect.width / 2);

		if (!Shared::isLineOfSight(pos1, pos2, wallMinX, wallMaxX, wallMinY, wallMaxY))
			return false;
	}
	return true;
}