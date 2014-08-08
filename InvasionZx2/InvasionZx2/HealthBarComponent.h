#pragma once
#include "Component.h"
#include "SFML/Graphics/RectangleShape.hpp"

class ShapeData;

class HealthBarComponent : public Component{
public:
	HealthBarComponent();
	virtual ~HealthBarComponent();
	virtual void update(GameObject* gameObject);
private:
	void setPosition(GameObject* gameObject);
	void updateHealthBar(GameObject* gameObject);
	void updateHealthBarColor(float healthPercentages);
	void drawHealthBar(GameObject* gameObject);

	ShapeData* m_HealthBarBoxShape;
	ShapeData* m_HealthBarShape;
};