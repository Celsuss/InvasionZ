#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Mouse.hpp"
#include "InputManager.h"
#include "KeyboardKey.h"
#include "MouseKey.h"
#include "Key.h"

InputManager* InputManager::m_Instance = new InputManager();

InputManager::InputManager(){
	m_ShootKey = new MouseKey(sf::Mouse::Left);
	m_UpKey = new KeyboardKey(sf::Keyboard::W);
	m_LeftKey = new KeyboardKey(sf::Keyboard::A);
	m_DownKey = new KeyboardKey(sf::Keyboard::S);
	m_RightKey = new KeyboardKey(sf::Keyboard::D);

	m_KeyVector.push_back(m_ShootKey);
	m_KeyVector.push_back(m_UpKey);
	m_KeyVector.push_back(m_LeftKey);
	m_KeyVector.push_back(m_DownKey);
	m_KeyVector.push_back(m_RightKey);
}

InputManager::~InputManager(){}

InputManager* InputManager::getInstance(){
	return m_Instance;
}

void InputManager::update(){
	for (auto i = getInstance()->m_KeyVector.begin(); i != getInstance()->m_KeyVector.end(); i++){
		(*i)->update();
	}
}

const bool InputManager::isUpKeyPressed(){
	return getInstance()->m_UpKey->isKeyPressed();
}

const bool InputManager::isLeftKeyPressed(){
	return getInstance()->m_LeftKey->isKeyPressed();
}

const bool InputManager::isDownKeyPressed(){
	return getInstance()->m_DownKey->isKeyPressed();
}

const bool InputManager::isRightKeyPressed(){
	return getInstance()->m_RightKey->isKeyPressed();
}

const bool InputManager::isShootKeyPressed(){
	return getInstance()->m_ShootKey->isKeyPressed();
}

const bool InputManager::isUpKeyDown(){
	return getInstance()->m_UpKey->isKeyDown();
}

const bool InputManager::isLeftKeyDown(){
	return getInstance()->m_LeftKey->isKeyDown();
}

const bool InputManager::isDownKeyDown(){
	return getInstance()->m_DownKey->isKeyDown();
}

const bool InputManager::isRightKeyDown(){
	return getInstance()->m_RightKey->isKeyDown();
}

const bool InputManager::isShootKeyDown(){
	return getInstance()->m_ShootKey->isKeyDown();
}