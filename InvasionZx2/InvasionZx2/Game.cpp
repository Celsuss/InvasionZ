#include "GraphicManager.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "Level.h"
#include "Game.h"

Game::Game(){}

Game::~Game(){}

void Game::start(){
	update();
}

void Game::update(){
	GraphicManager::initialize();
	Level level;

	while (GraphicManager::getWindow()->isOpen()){
		handleEvents();

		//----
		//Time
		TimeManager::update();
		//User input
		InputManager::update();
		//Update
		level.update();
		//Render
		GraphicManager::update();
		//----
	}
}

void Game::handleEvents(){
	sf::Event event;
	while (GraphicManager::getWindow()->pollEvent(event)){
		if (event.type == sf::Event::Closed)
			GraphicManager::getWindow()->close();
	}
}
