/*
	A game state, a playable level where the player can control the Player object
*/

#pragma once
#include <vector>
#include "GameState.h"
#include "LuaConfig.h"
#include "GameObject.h"

class Wall;

class Level : public GameState{
public:
	typedef std::vector<GameObject*>GameObjectVector;
	typedef std::vector<Wall*>WallVector;

	Level();
	~Level();
	virtual void update();
	void drawScenery();

	void drawWalls();
	void createGameObject(GameObject* gameObject);
	GameObject* getGameObject(int inedx);
	GameObject* getGameObject(GameObject::Type type, int offset);
	WallVector& getWallVector();
	float getGameObjectVectorSize()const;
	float getWallCount()const;
private:
	void generateLevel(LuaConfig config);
	void spawnObjects();
	void destroyDeadObjects();

	GameObjectVector m_GameObjectVector;
	GameObjectVector m_SceneryVector;
	GameObjectVector m_SpawnVector;
	WallVector m_WallVector;

	//----DEBUG
	int m_GameObjectCound;
	//----/DEBUG
};

