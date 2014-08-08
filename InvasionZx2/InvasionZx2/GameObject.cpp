#include "GameObject.h"
#include "ParticleEffectData.h"
#include "GraphicManager.h"
#include "Component.h"
#include "Data.h"

GameObject::GameObject(){}

GameObject::~GameObject(){}

void GameObject::update(){
	for (auto i = m_ComponentVector.begin(); i != m_ComponentVector.end(); i++){
		(*i)->update(this);
	}

	//Draw GameObjects with Sprites
	SpriteData* spriteData = getData<SpriteData>("SpriteData");
	if (spriteData != nullptr)
		spriteData->draw();
	//Draw GameObjects with Particle effect
	ParticleEffectData* particleData = getData<ParticleEffectData>("ParticleEffectData");
	if (particleData != nullptr)
		particleData->draw();
}