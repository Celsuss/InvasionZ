#pragma once

class GameState;

class Game{
public:
	Game();
	~Game();
	void start();
private:
	void update();
	void handleEvents();

	GameState* m_CurrentGameState;
};

