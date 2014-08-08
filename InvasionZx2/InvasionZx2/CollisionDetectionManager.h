#pragma once
#include "CollisionData.h"

class GameObject;

class CollisionDetectionManager{
public:
	static CollisionDetectionManager* getInstance();

	static void collisionDetection(GameObject* obj1, GameObject* obj2, CollisionData::CollisionShape* shape1, CollisionData::CollisionShape* shape2);
private:
	CollisionDetectionManager();
	~CollisionDetectionManager();
	static CollisionDetectionManager* m_Instance;

	static void circleCircleCollision(GameObject* obj1, GameObject* obj2);
	static void circleBoxCollision(GameObject* circleObj1, GameObject* rectObj2);
	static void boxBoxCollision(GameObject* obj1, GameObject* obj2);

	static bool weaponCollision(GameObject* obj1, GameObject* obj2);
};

