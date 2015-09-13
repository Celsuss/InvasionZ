/*
	Read input, return true if a key is pressed
*/

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

	m_OneKey = new KeyboardKey(sf::Keyboard::Num1);
	m_TwoKey = new KeyboardKey(sf::Keyboard::Num2);
	m_ThreeKey = new KeyboardKey(sf::Keyboard::Num3);
	m_FourKey = new KeyboardKey(sf::Keyboard::Num4);
	m_FiveKey = new KeyboardKey(sf::Keyboard::Num5);
	m_SixKey = new KeyboardKey(sf::Keyboard::Num6);
	m_SevenKey = new KeyboardKey(sf::Keyboard::Num7);
	m_EightKey = new KeyboardKey(sf::Keyboard::Num8);
	m_NineKey = new KeyboardKey(sf::Keyboard::Num9);

	m_KeyVector.push_back(m_ShootKey);
	m_KeyVector.push_back(m_UpKey);
	m_KeyVector.push_back(m_LeftKey);
	m_KeyVector.push_back(m_DownKey);
	m_KeyVector.push_back(m_RightKey);

	m_KeyVector.push_back(m_OneKey);
	m_KeyVector.push_back(m_TwoKey);
	/*m_KeyVector.push_back(m_ThreeKey);
	m_KeyVector.push_back(m_FourKey);
	m_KeyVector.push_back(m_FiveKey);
	m_KeyVector.push_back(m_SixKey);
	m_KeyVector.push_back(m_SevenKey);
	m_KeyVector.push_back(m_EightKey);*/
	m_KeyVector.push_back(m_NineKey);
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

const bool InputManager::isOneKeyPressed(){
	return getInstance()->m_OneKey->isKeyPressed();
}

const bool InputManager::isTwoKeyPressed(){
	return getInstance()->m_TwoKey->isKeyPressed();
}

const bool InputManager::isThreeKeyPressed(){
	return getInstance()->m_ThreeKey->isKeyPressed();
}

const bool InputManager::isFourKeyPressed(){
	return getInstance()->m_FourKey->isKeyPressed();
}

const bool InputManager::isFiveKeyPressed(){
	return getInstance()->m_FiveKey->isKeyPressed();
}

const bool InputManager::isSixKeyPressed(){
	return getInstance()->m_SixKey->isKeyPressed();
}

const bool InputManager::isSevenKeyPressed(){
	return getInstance()->m_SevenKey->isKeyPressed();
}

const bool InputManager::isEightKeyPressed(){
	return getInstance()->m_EightKey->isKeyPressed();
}

const bool InputManager::isNineKeyPressed(){
	return getInstance()->m_NineKey->isKeyPressed();
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