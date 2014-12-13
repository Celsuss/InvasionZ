#include "AIStateComponent.h"
#include "VertexArrayData.h"
#include "EntityFactory.h"
#include "PositionData.h"
#include "SpriteData.h"
#include "GameObject.h"
#include "AIState.h"
#include "Player.h"
#include "Shared.h"
#include "Wall.h"

AIStateComponent::AIStateComponent(AIState* startingState, AIState* globalState){
	m_Name = "AIStateComponent";
	m_ActiveState = startingState;
	m_ActiveState->enterState();
	m_GlobalState = globalState;
}

AIStateComponent::~AIStateComponent(){}

void AIStateComponent::update(GameObject* gameObject){
	if (m_ActiveState != nullptr)
		m_ActiveState->update(gameObject, this);
	if (m_GlobalState != nullptr){
		int j = 0;
		m_GlobalState->update(gameObject, this);
	}
}

void AIStateComponent::changeState(AIState* state){
	m_ActiveState->exitState();
	delete m_ActiveState;

	m_ActiveState = state;

	m_ActiveState->enterState();
}

bool AIStateComponent::isInLineOfSight(GameObject* gameObject){
	sf::Vector2f pos1 = *gameObject->getData<PositionData>("PositionData")->getPosition();
	sf::Vector2f pos2 = *EntityFactory::getInstance()->getPlayer()->getData<PositionData>("PositionData")->getPosition();

	float wallCount = EntityFactory::getInstance()->m_Level->getWallCount();

	for (int i = 0; i < wallCount; i++){
		Wall* wall = static_cast<Wall*>(EntityFactory::getInstance()->m_Level->getGameObject(GameObject::Wall, i));
		VertexArrayData* vertexData = wall->getData<VertexArrayData>("VertexArrayData");
		sf::Vector2f wallPos = *wall->getData<PositionData>("PositionData")->getPosition();
		sf::FloatRect wallRect = vertexData->getVertexArray()->getBounds();

		float wallMinX = 0;
		float wallMaxX = 0;
		float wallMinY = 0;
		float wallMaxY = 0;

		float length;
		if (wallRect.width == 0)
			length = wallRect.height;
		else
			length = wallRect.width;

		if (wallPos.x > (wallPos.x - length)){
			wallMaxX = wallPos.x;
			wallMinX = wallPos.x - length;
		}
		else{
			wallMaxX = wallPos.x - length;
			wallMinX = wallPos.x;
		}

		if (wallPos.y > (wallPos.y + length)){
			wallMaxY = wallPos.y;
			wallMaxY = wallPos.y + length;
		}
		else{
			wallMaxY = wallPos.y + length;
			wallMaxY = wallPos.y;
		}

		if (!Shared::isLineOfSight(pos1, pos2, wallMinX, wallMaxX, wallMinY, wallMaxY))
			return false;
	}
	return true;
}