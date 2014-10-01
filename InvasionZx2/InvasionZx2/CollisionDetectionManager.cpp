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
#include "Shared.h"
#include "Level.h"

CollisionDetectionManager* CollisionDetectionManager::m_Instance = new CollisionDetectionManager();

CollisionDetectionManager::CollisionDetectionManager(){}

CollisionDetectionManager::~CollisionDetectionManager(){}

CollisionDetectionManager* CollisionDetectionManager::getInstance(){
	return m_Instance;
}

void CollisionDetectionManager::collisionDetection(Level* level){
	for (auto i = getInstance()->m_GameObjectVector.begin(); i != getInstance()->m_GameObjectVector.end(); i++){
		if ((*i)->getData<CollisionData>("CollisionData") != nullptr){
			CollisionData* collisionData1 = (*i)->getData<CollisionData>("CollisionData");
			for (int j = 0; j < level->getGameObjectVectorSize(); j++){
				GameObject* i2 = level->getGameObject(j);
				if (*i != i2){
					if (i2->getData<CollisionData>("CollisionData") != nullptr){
						CollisionData* collisionData2 = i2->getData<CollisionData>("CollisionData");

						if (checkType(*i, i2))
							CollisionDetectionManager::checkShapes(*i, i2, collisionData1, collisionData2);
					}
				}
			}
		}
	}
	getInstance()->m_GameObjectVector.clear();
}

void CollisionDetectionManager::addGameObject(GameObject* obj){
	getInstance()->m_GameObjectVector.push_back(obj);
}

bool CollisionDetectionManager::checkType(GameObject* obj1, GameObject* obj2){
	if (obj1->getType() == GameObject::Bullet && obj2->getType() == GameObject::Bullet)
		return false;
	return true;
}

void CollisionDetectionManager::checkShapes(GameObject* obj1, GameObject* obj2, CollisionData* collisionData1, CollisionData* collisionData2){
	if (*collisionData1->getShape() == CollisionData::Circle && *collisionData2->getShape() == CollisionData::Circle)
		circleCircleCollision(obj1, obj2, collisionData1, collisionData2);
	else if (*collisionData1->getShape() == CollisionData::Circle && *collisionData2->getShape() == CollisionData::Box)
		circleBoxCollision(obj1, obj2, collisionData1, collisionData2);
	else if (*collisionData1->getShape() == CollisionData::Box && *collisionData2->getShape() == CollisionData::Box)
		boxBoxCollision(obj1, obj2, collisionData1, collisionData2);
}

void CollisionDetectionManager::circleCircleCollision(GameObject* obj1, GameObject* obj2, CollisionData* collisionData1, CollisionData* collisionData2){
	PositionData* obj1PositionData = obj1->getData<PositionData>("PositionData");
	MovementData* obj1Movementdata = obj1->getData<MovementData>("MovementData");
	SpriteData* obj1SpriteData = obj1->getData<SpriteData>("SpriteData");

	PositionData* obj2PositionData = obj2->getData<PositionData>("PositionData");
	MovementData* obj2Movementdata = obj2->getData<MovementData>("MovementData");
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

	float deltaTime = TimeManager::getDeltaTime();

	float moveX1 = Shared::normalizeVector(sf::Vector2f(deltaX, deltaY)).x * *obj1Movementdata->getMovementSpeed() * deltaTime;
	float moveY1 = Shared::normalizeVector(sf::Vector2f(deltaX, deltaY)).y * *obj1Movementdata->getMovementSpeed() * deltaTime;
	float moveX2 = Shared::normalizeVector(sf::Vector2f(deltaX, deltaY)).x * *obj2Movementdata->getMovementSpeed() * deltaTime;
	float moveY2 = Shared::normalizeVector(sf::Vector2f(deltaX, deltaY)).y * *obj2Movementdata->getMovementSpeed() * deltaTime;

	obj1Pos->x = obj1Pos->x - moveX1;
	obj1Pos->y = obj1Pos->y - moveY1;
	obj2Pos->x = obj2Pos->x + moveX2;
	obj2Pos->y = obj2Pos->y + moveY2;

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

	sf::Vector2f localCirclePos = circlePos - linePos;
	sf::Vector2f localLinePos;
	localLinePos.x = vertexArrayData->getVertexArray()->getBounds().width;
	localLinePos.y = vertexArrayData->getVertexArray()->getBounds().height;

	float localCirclePosXLinePos = (localCirclePos.x * localLinePos.x) + (localCirclePos.y * localLinePos.y);
	float localLinePosX2 = (localLinePos.x * localLinePos.x) + (localLinePos.y * localLinePos.y);

	sf::Vector2f projection = (localCirclePosXLinePos / localLinePosX2) * localLinePos;
	float radius = spriteData->getSprite()->getLocalBounds().width / 2;

	if (!isPhysicalColliders(collisionData1, collisionData2))
		return;

	if (localLinePos.x == 0){
		float deltaX = circlePos.x - linePos.x;
		if (deltaX < radius && (projection.x - localCirclePos.x) < radius){			//Collision
			
			sf::Vector2f move(radius - std::abs(deltaX), 0);
			if (circlePos.x < linePos.x)
				move.x = -move.x;

			*circlePositionData->getPosition() += move;
		}
	}
	else if (localLinePos.y == 0){
		float deltaY = circlePos.y - linePos.y;
		if (deltaY < radius && (projection.y - localCirclePos.y) < radius){			//Collision

			sf::Vector2f move(0, radius - std::abs(deltaY));
			if (circlePos.y < linePos.y)
				move.y = -move.y;

			*circlePositionData->getPosition() += move;
		}
	}

	/*sf::Vector2f delta(projection.x, projection.y);
	if (radius > std::sqrt((delta.x * delta.x) + (delta.y * delta.y))){
	std::cout << "\nWall collision";
	}*/
}

void CollisionDetectionManager::boxBoxCollision(GameObject* obj1, GameObject* obj2, CollisionData* collisionData1, CollisionData* collisionData2){

}

bool CollisionDetectionManager::isPhysicalColliders(CollisionData* collisionData1, CollisionData* collisionData2){
	if (!collisionData1->getIsPhysicalCollider() || !collisionData2->getIsPhysicalCollider())
		return false;
	return true;
}