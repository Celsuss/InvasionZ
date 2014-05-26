#pragma once
#include "SFML/System/Time.hpp"
#include "SFML/System/Clock.hpp"

class TimeManager{
public:
	~TimeManager();
	static TimeManager* getInstance();
	static void update();
	static float getDeltaTime();
private:
	TimeManager();
	static TimeManager* m_Instance;
	sf::Clock m_Clock;
	sf::Time m_LastTime;
	float m_DeltaTime;
};

