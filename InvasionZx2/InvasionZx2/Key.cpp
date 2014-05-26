#include "Key.h"

Key::Key(){}

Key::~Key(){}

/*void Key::update(){
	m_KeyPressed = false;

	if (sf::Keyboard::isKeyPressed(m_Key))
		m_KeyDown = true;
	else{
		if (m_KeyDown){
			m_KeyDown = false;
			m_KeyPressed = true;
		}
	}
}*/

bool Key::isKeyPressed(){
	return m_KeyPressed;
}

bool Key::isKeyDown(){
	return m_KeyDown;
}