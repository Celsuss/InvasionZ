#pragma once
#include "SFML/Window/Keyboard.hpp"

class Key{
public:
	Key();
	virtual ~Key();
	virtual void update() = 0;
	virtual bool isKeyPressed();
	virtual bool isKeyDown();
protected:
	bool m_KeyPressed;
	bool m_KeyDown;
};