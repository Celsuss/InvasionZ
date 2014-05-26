#include "TimeManager.h"

TimeManager* TimeManager::m_Instance = new TimeManager();

TimeManager::TimeManager(){
	m_Clock.restart();
	m_LastTime = m_Clock.getElapsedTime();
}

TimeManager::~TimeManager(){}

TimeManager* TimeManager::getInstance(){
	return m_Instance;
}

void TimeManager::update(){
	sf::Time nowTime = m_Instance->m_Clock.getElapsedTime();
	//m_Instance->m_DeltaTime = nowTime.asMilliseconds() - m_Instance->m_LastTime.asMilliseconds();
	m_Instance->m_DeltaTime = nowTime.asSeconds() - m_Instance->m_LastTime.asSeconds();
	m_Instance->m_LastTime = nowTime;
}

float TimeManager::getDeltaTime(){
	return m_Instance->m_DeltaTime;
}