#pragma once
#include <vector>
#include <string>
#include <iostream>

#include "Data.h"
#include "MovementData.h"
#include "PositionData.h"
#include "DrawableData.h"
#include "SpriteData.h"
#include <type_traits>

class Data;
class Component;

class GameObject{
public:
	enum Type{
		Player,
		Zombie,
		Bullet,
		Object,
		Wall,
		Item,
		Other
	};

	typedef std::vector<Data*>DataVector;
	typedef std::vector<Component*>ComponentVector;

	GameObject();
	virtual ~GameObject();
	virtual void setDrawableData();
	virtual void update();
	virtual void addCollision(GameObject* obj) = 0;
	virtual void kill();

	virtual bool getIsAlive() const;
	virtual Type getType() const;
	
	template<typename c>
	c* getComponent(std::string name){
		for (auto i = m_ComponentVector.begin(); i != m_ComponentVector.end(); i++){
			if ((*i)->getName() == name){
				return static_cast<c*>(*i);
			}
		}
		//std::cout << "ERROR: " + name + " not found!\n";
		return nullptr;
	}

	template<typename d>
	d* getData(std::string name){
		for (auto i = m_DataVector.begin(); i != m_DataVector.end(); i++){
			if ((*i)->getName() == name){
				return static_cast<d*>(*i);
			}
		}
		//std::cout << "ERROR: " + name + " not found!\n";
		return nullptr;
	}
	
	ComponentVector m_ComponentVector;
	DataVector m_DataVector;
protected:
	DrawableData* m_DrawableData;
	Type m_Type = GameObject::Other;
	bool m_IsAlive = true;
};