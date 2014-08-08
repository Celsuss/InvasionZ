#pragma once

class GameState{
public:
	GameState();
	virtual ~GameState();
	virtual void update() = 0;
};