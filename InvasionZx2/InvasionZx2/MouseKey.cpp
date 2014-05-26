#include "MouseKey.h"

MouseKey::MouseKey(sf::Mouse::Button key):
m_Key(key){
	m_KeyPressed = false;
	m_KeyDown = false;
}

MouseKey::~MouseKey(){}

void MouseKey::update(){
	m_KeyPressed = false;

	if (sf::Mouse::isButtonPressed(m_Key)){
		if (!m_KeyDown)
			m_KeyPressed = true;
		m_KeyDown = true;
	}
	else
		m_KeyDown = false;
}