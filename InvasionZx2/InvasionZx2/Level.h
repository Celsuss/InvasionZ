#pragma once
#include <vector>
#include "GameState.h"
#include "GameObject.h"

class Level : public GameState{
public:
	typedef std::vector<GameObject*>GameObjectVector;

	Level();
	~Level();
	virtual void update();

	void createGameObject(GameObject* gameObject);
	GameObject* getGameObject(int inedx);
	GameObject* getGameObject(GameObject::Type type, int offset);
	float getWallCount()const;
private:
	void spawnObjects();
	void destroyDeadObjects();

	void collisionDetection();

	GameObjectVector m_GameObjectVector;
	GameObjectVector m_SpawnVector;

	float m_WallCount;

	//----DEBUG
	int m_GameObjectCound;
	//----/DEBUG
};

