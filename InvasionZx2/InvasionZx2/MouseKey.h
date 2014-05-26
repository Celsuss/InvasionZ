#pragma once
#include "SFML/Window/Mouse.hpp"
#include "Key.h"

class MouseKey : public Key{
public:
	MouseKey(sf::Mouse::Button key);
	~MouseKey();
	virtual void update();
private:
	sf::Mouse::Button m_Key;
};