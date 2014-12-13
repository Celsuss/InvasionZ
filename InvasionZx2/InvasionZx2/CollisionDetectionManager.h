#pragma once
#include "CollisionData.h"
#include <vector>

class Wall;
class Level;
class GridNode;
class GameObject;

class CollisionDetectionManager{
public:
	typedef std::vector<GameObject*>GameObjectCollisionVector;

	static CollisionDetectionManager* getInstance();

	static void collisionDetection(Level* level);
	static void addGameObject(GameObject* obj);
	static bool getNodeCollideWithWall(GridNode* node, Wall* wall);
private:
	CollisionDetectionManager();
	~CollisionDetectionManager();
	static CollisionDetectionManager* m_Instance;

	static void checkShapes(GameObject* obj1, GameObject* obj2, CollisionData* collisionData1, CollisionData* collisionData2);
	static bool checkType(GameObject* obj1, GameObject* obj2);

	static void circleCircleCollision(GameObject* obj1, GameObject* obj2, CollisionData* collisionData1, CollisionData* collisionData2);
	static void circleBoxCollision(GameObject* circleObj1, GameObject* rectObj2, CollisionData* collisionData1, CollisionData* collisionData2);
	static void boxBoxCollision(GameObject* obj1, GameObject* obj2, CollisionData* collisionData1, CollisionData* collisionData2);

	static bool isPhysicalColliders(CollisionData* collisionData1, CollisionData* collisionData2);

	GameObjectCollisionVector m_MovedGameObjects;
};