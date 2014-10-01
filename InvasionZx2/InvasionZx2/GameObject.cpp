#include "GameObject.h"
#include "ParticleEffectData.h"
#include "VertexArrayData.h"
#include "GraphicManager.h"
#include "Component.h"
#include "Data.h"

GameObject::GameObject(){}

GameObject::~GameObject(){}

void GameObject::setDrawableData(){
	SpriteData* spriteData = getData<SpriteData>("SpriteData");
	if (spriteData != nullptr){
		m_DrawableData = spriteData;
		return;
	}

	VertexArrayData* vertexArrayData = getData<VertexArrayData>("VertexArrayData");
	if (vertexArrayData != nullptr){
		m_DrawableData = vertexArrayData;
		return;
	}
}

void GameObject::update(){
	for (auto i = m_ComponentVector.begin(); i != m_ComponentVector.end(); i++){
		(*i)->update(this);
	}

	if (m_IsAlive)
		m_DrawableData->draw();
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