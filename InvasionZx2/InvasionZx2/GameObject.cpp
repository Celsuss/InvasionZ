/*
	Base class for all game objects such as Player, Zombie, Bullet, Floor
	All game objects are built using the Component and Data classes
*/

#include "GameObject.h"
#include "ParticleEffectData.h"
#include "VertexArrayData.h"
#include "GraphicManager.h"
#include "Component.h"
#include "Data.h"

GameObject::GameObject(){}

GameObject::~GameObject(){
	/*for (auto i = m_ComponentMap.begin(); i != m_ComponentMap.end(); i++){
		delete i->second;
	}
	for (auto i = m_DataMap.begin(); i != m_DataMap.end(); i++){
		delete i->second;
	}
	for (auto i = m_DrawableDataVector.begin(); i != m_DrawableDataVector.end(); i++){
		delete *i;
		//i = m_DrawableDataVector.erase(i);
	}
	m_ComponentMap.clear();
	m_DataMap.clear();
	m_DrawableDataVector.clear();*/
}

// Add all subclasses of DrawableData to the m_drawableData vector
void GameObject::setDrawableData(){
	SpriteData* spriteData = getData<SpriteData>("SpriteData");
	if (spriteData != nullptr){
		m_DrawableDataVector.push_back(spriteData);
		return;
	}

	VertexArrayData* vertexArrayData = getData<VertexArrayData>("VertexArrayData");
	if (vertexArrayData != nullptr){
		m_DrawableDataVector.push_back(vertexArrayData);
		return;
	}
}

// Calls update on all the gameobjects components and draw all the DrawableData
void GameObject::update(){
	for (auto i = m_ComponentMap.begin(); i != m_ComponentMap.end(); i++){
		i->second->update(this);
	}

	if (m_IsAlive){
		for (auto i = m_DrawableDataVector.begin(); i != m_DrawableDataVector.end(); i++){
			(*i)->draw();
		}
	}
}

// Flag a dead gameobject to be removed
void GameObject::kill(){
	m_IsAlive = false;
}

// Returns true if object is flaged to be removed
bool GameObject::getIsAlive() const{
	return m_IsAlive;
}

// Returns the type of the object
GameObject::Type GameObject::getType() const{
	return m_Type;
}