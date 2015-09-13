/*
	Draws gameobjects health bars
	Data needed: HealthData, PositionData
*/

#pragma once
#include "Component.h"
#include "SFML/Graphics/RectangleShape.hpp"

class ShapeData;
class HealthData;
class PositionData;

class HealthBarComponent : public Component{
public:
	HealthBarComponent(HealthData* healthData, PositionData* positionData);
	virtual ~HealthBarComponent();
	virtual void update(GameObject* gameObject);
private:
	bool checkIfAlive(GameObject* gameObject);
	void setPosition(GameObject* gameObject);
	void updateHealthBar(GameObject* gameObject);
	void updateHealthBarColor(float healthPercentages);
	void drawHealthBar(GameObject* gameObject);

	ShapeData* m_HealthBarBoxShape;
	ShapeData* m_HealthBarShape;

	HealthData* m_HealthData;
	PositionData* m_PositionData;
};