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

void GameObject::setDrawableData(){
	SpriteData* spriteData = getData<SpriteData>("SpriteData");
	if (spriteData != nullptr){
		//m_DrawableData = spriteData;
		m_DrawableDataVector.push_back(spriteData);
		return;
	}

	VertexArrayData* vertexArrayData = getData<VertexArrayData>("VertexArrayData");
	if (vertexArrayData != nullptr){
		m_DrawableDataVector.push_back(vertexArrayData);
		return;
	}
}

void GameObject::update(){
	//for (auto i = m_ComponentVector.begin(); i != m_ComponentVector.end(); i++){
	for (auto i = m_ComponentMap.begin(); i != m_ComponentMap.end(); i++){
		//(*i)->update(this);
		i->second->update(this);
	}

	if (m_IsAlive){
		for (auto i = m_DrawableDataVector.begin(); i != m_DrawableDataVector.end(); i++){
			(*i)->draw();
		}
	}
}

void GameObject::kill(){
	m_IsAlive = false;
}

bool GameObject::getIsAlive() const{
	return m_IsAlive;
}

GameObject::Type GameObject::getType() const{
	return m_Type;
}