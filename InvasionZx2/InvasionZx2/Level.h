#pragma once
#include <vector>

class GameObject;

class Level{
public:
	typedef std::vector<GameObject*>GameObjectVector;
	Level();
	~Level();
	void update();
	void createGameObject(GameObject* gameObject);
private:
	void spawnObjects();

	GameObjectVector m_GameObjectVector;
	GameObjectVector m_SpawnVector;

	void CollisionDetection();
};

