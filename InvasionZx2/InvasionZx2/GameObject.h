/*
	Base class for all game objects such as Player, Zombie, Bullet, Floor
	All game objects are built using the Component and Data classes
*/

#pragma once
#include <map>
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <type_traits>

#include "Data.h"
#include "MovementData.h"
#include "PositionData.h"
#include "DrawableData.h"
#include "SpriteData.h"

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
	typedef std::vector<DrawableData*>DrawableDataVector;

	//typedef std::map<std::string, Data*>DataMap;
	//typedef std::map<std::string, Component*>ComponentMap;

	typedef std::map<std::string, std::shared_ptr<Data>>DataMap;
	typedef std::map<std::string, std::shared_ptr<Component>>ComponentMap;

	GameObject();
	virtual ~GameObject();
	virtual void setDrawableData();
	virtual void update();
	virtual void addCollision(GameObject* obj) = 0;
	virtual void kill();

	virtual bool getIsAlive() const;
	virtual Type getType() const;
	
	//Returns a component of the type c and name name
	template<typename c>
	c* getComponent(std::string name){
		Component* component = m_ComponentMap[name].get();
		if (component != nullptr)
			return static_cast<c*>(component);

		m_ComponentMap.erase(name);
		//std::cout << "<Component> " + name + " not found!\n";
		return nullptr;
	}

	//Returns a data of the type c and name name
	template<typename d>
	d* getData(std::string name){
		Data* data = m_DataMap[name].get();
		if (data != nullptr)
			return static_cast<d*>(data);

		m_DataMap.erase(name);
		//std::cout << "<Data> " + name + " not found!\n";
		return nullptr;
	}
	
protected:
	DataMap m_DataMap;
	ComponentMap m_ComponentMap;

	DataVector m_DataVector;
	ComponentVector m_ComponentVector;
	DrawableDataVector m_DrawableDataVector;
	Type m_Type = GameObject::Other;

	bool m_IsAlive = true;
};