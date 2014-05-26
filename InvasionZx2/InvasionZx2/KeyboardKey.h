#pragma once
#include "SFML/Window/Keyboard.hpp"
#include "Key.h"

class KeyboardKey : public Key{
public:
	KeyboardKey(sf::Keyboard::Key key);
	~KeyboardKey();
	virtual void update();
private:
	sf::Keyboard::Key m_Key;
};