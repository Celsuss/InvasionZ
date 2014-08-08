#include "CollisionDetectionManager.h"
#include "PositionData.h"
#include "IsWeaponData.h"
#include "IsPlayerData.h"
#include "TimeManager.h"
#include "GameObject.h"
#include "SpriteData.h"
#include "HealthData.h"
#include "DamageData.h"
#include "Shared.h"

CollisionDetectionManager* CollisionDetectionManager::m_Instance = new CollisionDetectionManager();

CollisionDetectionManager::CollisionDetectionManager(){}

CollisionDetectionManager::~CollisionDetectionManager(){}

void CollisionDetectionManager::collisionDetection(GameObject* obj1, GameObject* obj2, CollisionData::CollisionShape* shape1, CollisionData::CollisionShape* shape2){
	if (*shape1 == CollisionData::Circle && *shape2 == CollisionData::Circle)
		circleCircleCollision(obj1, obj2);
	else if (*shape1 == CollisionData::Circle && *shape2 == CollisionData::Box)
		circleBoxCollision(obj1, obj2);
	else if (*shape2 == CollisionData::Box && *shape2 == CollisionData::Box)
		boxBoxCollision(obj1, obj2);
}

void CollisionDetectionManager::circleCircleCollision(GameObject* obj1, GameObject* obj2){
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

	if (weaponCollision(obj1, obj2))	//Bullet collision
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

void CollisionDetectionManager::circleBoxCollision(GameObject* circleObj1, GameObject* rectObj2){
	float circleObj1PosX = circleObj1->getData<SpriteData>("SpriteData")->getSprite()->getPosition().x;
	float circleObj1PosY = circleObj1->getData<SpriteData>("SpriteData")->getSprite()->getPosition().y;
	float rectObj2PosX = rectObj2->getData<SpriteData>("SpriteData")->getSprite()->getPosition().x;
	float rectObj2PosY = rectObj2->getData<SpriteData>("SpriteData")->getSprite()->getPosition().y;

	float radius = circleObj1->getData<SpriteData>("SpriteData")->getSprite()->getLocalBounds().width / 2;
	float width = rectObj2->getData<SpriteData>("SpriteData")->getSprite()->getLocalBounds().width;
	float height = rectObj2->getData<SpriteData>("SpriteData")->getSprite()->getLocalBounds().height;

	float deltaX = rectObj2PosX - circleObj1PosX;
	float deltaY = rectObj2PosY - circleObj1PosY;

	if (std::abs(deltaX) > (width / 2 + radius))	//No collision
		return;
	if (std::abs(deltaY) > (height / 2 + radius))	//No collision
		return;

	if (circleObj1->getData<IsWeaponData>("IsWeaponData") != nullptr){	//Bullet collide with wall
		circleObj1->m_IsAlive = false;
		return;
	}

	float obj1Bottom = circleObj1PosY + radius;
	float obj1Right = circleObj1PosX + radius;
	float obj2Bottom = rectObj2PosY + (height / 2);
	float obj2Right = rectObj2PosX + (width / 2);

	float topCollision = std::abs(obj1Bottom - (rectObj2PosY - (height / 2)));
	float rightCollision = std::abs(obj2Right - (circleObj1PosX - radius));
	float bottomCollision = std::abs(obj2Bottom - (circleObj1PosY - radius));
	float leftCollision = std::abs(obj1Right - (rectObj2PosX - (width / 2)));

	if (topCollision < bottomCollision && topCollision < leftCollision && topCollision < rightCollision){
		//Top collision
		float move = deltaY - (height / 2) - radius;
		circleObj1->getData<PositionData>("PositionData")->getPosition()->y += move;
	}
	else if (rightCollision < bottomCollision && rightCollision < leftCollision && rightCollision < topCollision){
		//Right collision
		float move = deltaX + (width / 2) + radius;
		circleObj1->getData<PositionData>("PositionData")->getPosition()->x += move;
	}
	else if (bottomCollision < topCollision && bottomCollision < leftCollision && bottomCollision < rightCollision){
		//Bottom collision
		float move = deltaY + (height / 2) + radius;
		circleObj1->getData<PositionData>("PositionData")->getPosition()->y += move;
	}
	else if (leftCollision < topCollision && leftCollision < bottomCollision && leftCollision < rightCollision){
		//Left collision
		float move = deltaX - (width / 2) - radius;
		circleObj1->getData<PositionData>("PositionData")->getPosition()->x += move;
	}
}

void CollisionDetectionManager::boxBoxCollision(GameObject* obj1, GameObject* obj2){

}

bool CollisionDetectionManager::weaponCollision(GameObject* obj1, GameObject* obj2){
	//No weapon collision so return false
	if (obj1->m_Type == GameObject::Player && obj2->m_Type == GameObject::Zombie)
		return false;
	if (obj2->m_Type == GameObject::Zombie && obj1->m_Type == GameObject::Player)
		return false;

	//Player dont collide with bullet so return true
	if (obj1->m_Type == GameObject::Player || obj2->m_Type == GameObject::Player)
		return true;

	IsWeaponData* obj1IsWeaponData = obj1->getData<IsWeaponData>("IsWeaponData");
	IsWeaponData* obj2IsWeaponData = obj2->getData<IsWeaponData>("IsWeaponData");

	if (obj1IsWeaponData != nullptr && obj2IsWeaponData != nullptr)		//Dont collide two IsWeaponData
		return false;

	if (obj1IsWeaponData != nullptr){
		float* health = obj2->getData<HealthData>("HealthData")->getHealth();
		float damage = obj1->getData<DamageData>("DamageData")->getDamage();
		*health = *health - damage;

		if (*health <= 0)
			obj2->m_IsAlive = false;
		obj1->m_IsAlive = false;
		return true;
	}
	if (obj2IsWeaponData != nullptr){
		float* health = obj1->getData<HealthData>("HealthData")->getHealth();
		float damage = obj2->getData<DamageData>("DamageData")->getDamage();
		*health = *health - damage;
		obj2->m_IsAlive = false;
		return true;
	}

	return false;
}