#include "KeyboardKey.h"

KeyboardKey::KeyboardKey(sf::Keyboard::Key key) :
m_Key(key){
	m_KeyPressed = false;
	m_KeyDown = false;
}

KeyboardKey::~KeyboardKey(){}

void KeyboardKey::update(){
	m_KeyPressed = false;

	if (sf::Keyboard::isKeyPressed(m_Key)){
		if (!m_KeyDown)
			m_KeyPressed = true;
		m_KeyDown = true;
	}
	else
		m_KeyDown = false;
}