#include "GraphicManager.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "GameState.h"
#include "Level.h"
#include "Debug.h"
#include "Game.h"

Game::Game(){}

Game::~Game(){}

void Game::start(){
	update();
}

void Game::update(){
	GraphicManager::initialize();
	m_CurrentGameState = new Level();

	while (GraphicManager::getWindow()->isOpen()){
		handleEvents();

		//----
		Debug::clear();
		//Time
		TimeManager::update();
		//User input
		InputManager::update();
		//Update game state
		m_CurrentGameState->update();
		//Render
		Debug::update();
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
