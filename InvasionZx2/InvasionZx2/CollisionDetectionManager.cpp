#include "CollisionDetectionManager.h"
#include "VertexArrayData.h"
#include "PositionData.h"
#include "IsWeaponData.h"
#include "IsPlayerData.h"
#include "ItemManager.h"
#include "TimeManager.h"
#include "GameObject.h"
#include "SpriteData.h"
#include "HealthData.h"
#include "DamageData.h"
#include "ItemData.h"
#include "GridNode.h"
#include "Shared.h"
#include "Level.h"
#include "Wall.h"

CollisionDetectionManager* CollisionDetectionManager::m_Instance = new CollisionDetectionManager();

CollisionDetectionManager::CollisionDetectionManager(){}

CollisionDetectionManager::~CollisionDetectionManager(){}

CollisionDetectionManager* CollisionDetectionManager::getInstance(){
	return m_Instance;
}

void CollisionDetectionManager::collisionDetection(Level* level){
	for (auto i = getInstance()->m_MovedGameObjects.begin(); i != getInstance()->m_MovedGameObjects.end(); i++){
		CollisionData* collisionData1 = (*i)->getData<CollisionData>("CollisionData");
		if (collisionData1 != nullptr){
			for (int j = 0; j < level->getGameObjectVectorSize(); j++){
				GameObject* i2 = level->getGameObject(j);
				if (*i != i2){
					CollisionData* collisionData2 = i2->getData<CollisionData>("CollisionData");
					if (collisionData2 != nullptr){
						if (checkType(*i, i2))
							CollisionDetectionManager::checkShapes(*i, i2, collisionData1, collisionData2);
					}
				}
			}
		}
	}
	getInstance()->m_MovedGameObjects.clear();
}

void CollisionDetectionManager::addGameObject(GameObject* obj){
	getInstance()->m_MovedGameObjects.push_back(obj);
}

bool CollisionDetectionManager::getNodeCollideWithWall(GridNode* node, Wall* wall){	
	PositionData* nodePositionData = node->getPositionData();
	PositionData* wallPositionData = wall->getData<PositionData>("PositionData");

	SpriteData* spriteData = node->getSpriteData();
	VertexArrayData* vertexArrayData = wall->getData<VertexArrayData>("VertexArrayData");

	float radius = spriteData->getSprite()->getLocalBounds().width / 2;
	sf::Vector2f nodePos = *node->getPositionData()->getPosition();
	nodePos += sf::Vector2f(radius, -radius);
	sf::Vector2f linePos = *wallPositionData->getPosition();

	sf::Vector2f localLinePos;
	localLinePos.x = vertexArrayData->getVertexArray()->getBounds().width;
	localLinePos.y = vertexArrayData->getVertexArray()->getBounds().height;


	if (localLinePos.x == 0){			//If line got no width
		float deltaX = nodePos.x - linePos.x;
		float deltaY = nodePos.y - linePos.y;
		if (std::abs(deltaX) <= radius && std::abs(deltaY) < localLinePos.y){		//X and Y Collision
			node->setIsWalkable(false);
		}
		if (std::abs(deltaY) <= radius && std::abs(deltaX) < localLinePos.x){
			node->setIsWalkable(false);
		}
	}

	return false;
}

bool CollisionDetectionManager::checkType(GameObject* obj1, GameObject* obj2){
	if (obj1->getType() == GameObject::Bullet && obj2->getType() == GameObject::Bullet)
		return false;
	return true;
}

void CollisionDetectionManager::checkShapes(GameObject* obj1, GameObject* obj2, CollisionData* collisionData1, CollisionData* collisionData2){
	if (*collisionData1->getShape() == CollisionData::Circle && *collisionData2->getShape() == CollisionData::Circle)
		circleCircleCollision(obj1, obj2, collisionData1, collisionData2);
	else if (*collisionData1->getShape() == CollisionData::Circle && *collisionData2->getShape() == CollisionData::Line)
		circleBoxCollision(obj1, obj2, collisionData1, collisionData2);
}

void CollisionDetectionManager::circleCircleCollision(GameObject* obj1, GameObject* obj2, CollisionData* collisionData1, CollisionData* collisionData2){
	PositionData* obj1PositionData = obj1->getData<PositionData>("PositionData");
	SpriteData* obj1SpriteData = obj1->getData<SpriteData>("SpriteData");

	PositionData* obj2PositionData = obj2->getData<PositionData>("PositionData");
	SpriteData* obj2SpriteData = obj2->getData<SpriteData>("SpriteData");

	sf::Vector2f* obj1Pos = obj1PositionData->getPosition();
	sf::Vector2f* obj2Pos = obj2PositionData->getPosition();

	float obj1PosX = obj1Pos->x;
	float obj1PosY = obj1Pos->y;
	float obj2PosX = obj2Pos->x;
	float obj2PosY = obj2Pos->y;
	float deltaX = obj2PosX - obj1PosX;
	float deltaY = obj2PosY - obj1PosY;

	float r1 = obj1SpriteData->getSprite()->getLocalBounds().width / 2;
	float r2 = obj2SpriteData->getSprite()->getLocalBounds().width / 2;

	if ((deltaX * deltaX) + (deltaY * deltaY) > (r1 + r2) * (r1 + r2))	//No collision
		return;

	obj1->addCollision(obj2);
	obj2->addCollision(obj1);

	if (!isPhysicalColliders(collisionData1, collisionData2))
		return;

	sf::Vector2f move(Shared::normalizeVector(sf::Vector2f(deltaX, deltaY)));

	obj1Pos->x = obj1Pos->x - move.x;
	obj1Pos->y = obj1Pos->y - move.y;
	obj2Pos->x = obj2Pos->x + move.x;
	obj2Pos->y = obj2Pos->y + move.y;

	obj1SpriteData->getSprite()->setPosition(*obj1PositionData->getPosition());
	obj2SpriteData->getSprite()->setPosition(*obj2PositionData->getPosition());
}

void CollisionDetectionManager::circleBoxCollision(GameObject* circleObj1, GameObject* rectObj2, CollisionData* collisionData1, CollisionData* collisionData2){
	PositionData* circlePositionData = circleObj1->getData<PositionData>("PositionData");
	PositionData* rectPositionData = rectObj2->getData<PositionData>("PositionData");

	SpriteData* spriteData = circleObj1->getData<SpriteData>("SpriteData");
	VertexArrayData* vertexArrayData = rectObj2->getData<VertexArrayData>("VertexArrayData");

	sf::Vector2f circlePos = *circlePositionData->getPosition();
	sf::Vector2f linePos = *rectPositionData->getPosition();

	sf::Vector2f localLinePos;
	localLinePos.x = vertexArrayData->getVertexArray()->getBounds().width;
	localLinePos.y = vertexArrayData->getVertexArray()->getBounds().height;

	float radius = spriteData->getSprite()->getLocalBounds().width / 2;

	float deltaX = circlePos.x - linePos.x;
	float deltaY = circlePos.y - linePos.y;

	if ((std::abs(deltaX) < radius && std::abs(deltaY) < localLinePos.y) ||
		(std::abs(deltaY) < radius && std::abs(deltaX) < localLinePos.x)){			//Collision
		if (isPhysicalColliders(collisionData1, collisionData2)){
			if (localLinePos.x == 0){
				sf::Vector2f move(radius - std::abs(deltaX), 0);
				if (circlePos.x < linePos.x)
					move.x = -move.x;

				*circlePositionData->getPosition() += move;
			}
			else if (localLinePos.y == 0){
				sf::Vector2f move(0, radius - std::abs(deltaY));
				if (circlePos.y < linePos.y)
					move.y = -move.y;

				*circlePositionData->getPosition() += move;
			}
		}
		else if (circleObj1->getData<IsWeaponData>("IsWeaponData") != nullptr){
			circleObj1->kill();
		}
	}
}

void CollisionDetectionManager::boxBoxCollision(GameObject* obj1, GameObject* obj2, CollisionData* collisionData1, CollisionData* collisionData2){

}

bool CollisionDetectionManager::isPhysicalColliders(CollisionData* collisionData1, CollisionData* collisionData2){
	if (!collisionData1->getIsPhysicalCollider() || !collisionData2->getIsPhysicalCollider())
		return false;
	return true;
}