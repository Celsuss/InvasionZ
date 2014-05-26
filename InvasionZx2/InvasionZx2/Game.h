#pragma once

class Game{
public:
	Game();
	~Game();
	void start();
private:
	void update();
	void handleEvents();
};

