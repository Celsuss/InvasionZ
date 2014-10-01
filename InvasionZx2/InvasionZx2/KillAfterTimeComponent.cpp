#include "KillAfterTimeComponent.h"
#include "GameObject.h"

KillAfterTimeComponent::KillAfterTimeComponent(sf::Time lifeTime){
	m_Name = "KillAfterTimeComponent";
	m_LifeTime = lifeTime;
}

KillAfterTimeComponent::~KillAfterTimeComponent(){}

void KillAfterTimeComponent::update(GameObject* gameObject){
	if (m_Clock.getElapsedTime().asSeconds() > m_LifeTime.asSeconds()){
		gameObject->kill();
	}
}