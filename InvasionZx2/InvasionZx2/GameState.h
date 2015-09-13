/*
	Base class for all the diferent game states.
*/

#pragma once

class GameState{
public:
	GameState();
	virtual ~GameState();
	virtual void update() = 0;
};