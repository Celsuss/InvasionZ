#include "GUI.h"
#include "Player.h"
#include "AmmoData.h"
#include "TextData.h"
#include "WeaponData.h"
#include "SpriteData.h"
#include "EntityFactory.h"
#include "GraphicManager.h"
#include <string>
#include <sstream>

GUI* GUI::m_Instance = new GUI();

GUI::GUI(){}

GUI::~GUI(){}

GUI* GUI::getInstance(){
	return m_Instance;
}

void GUI::initialize(){
	sf::Vector2f pos = sf::Vector2f(0, 0);
	initializeWeaponBoxes(&pos);
	createSortedVectors();
}

void GUI::update(){
	updateWeaponSprite();
	draw();
}

void GUI::draw(){
	for (auto i = getInstance()->m_GUISpriteElementsVector.begin(); i != getInstance()->m_GUISpriteElementsVector.end(); i++){
		GraphicManager::draw(*i);
	}
	for (auto i = getInstance()->m_GUITextElementsVector.begin(); i != getInstance()->m_GUITextElementsVector.end(); i++){
		GraphicManager::draw(*i);
	}
}

void GUI::updateWeaponSprite(){
	WeaponData* weaponData = EntityFactory::getPlayer()->getData<WeaponData>("WeaponData");

	for (int i = 0; i < weaponData->getWeaponVectorSize(); i++){
		std::string name = weaponData->getWeapon(i)->getName();
		updateAmmoText(name);
	}
}

void GUI::updateAmmoText(std::string weapon){
	AmmoData* ammoData = EntityFactory::getPlayer()->getData<AmmoData>("AmmoData");
	int ammo = *ammoData->getAmmo(weapon);
	int maxAmmo = ammoData->getMaxAmmo(weapon);
	std::string text;
	std::ostringstream convertAmmo;
	std::ostringstream convertMaxAmmo;

	convertAmmo << ammo;
	convertMaxAmmo << maxAmmo;
	text = convertAmmo.str() + "/" + convertMaxAmmo.str();

	TextData* textData = getInstance()->m_GUITextElementsMap.find("Ammo")->second;
	textData->getText()->setString(text);
	textData->getText()->setOrigin(textData->getText()->getLocalBounds().width / 2, 0);
}

void GUI::initializeWeaponBoxes(sf::Vector2f* pos){
	//Create gun box
	getInstance()->m_GUISpriteElementsMap.insert(
		std::pair<std::string, SpriteData*>("GunBox", new SpriteData("GreyBox", *pos, SpriteData::Foreground)));
	initializeGun(pos);

	//Create machine gun box
	pos->x = 0;
	pos->y = 0;
	pos->x += getInstance()->m_GUISpriteElementsMap.find("GunBox")->second->getSprite()->getLocalBounds().width;

	getInstance()->m_GUISpriteElementsMap.insert(
		std::pair<std::string, SpriteData*>("MachineGunBox", new SpriteData("GreyBox", *pos, SpriteData::Foreground)));
}

void GUI::initializeGun(sf::Vector2f* pos){
	//Create gun icon
	pos->x = getInstance()->m_GUISpriteElementsMap.begin()->second->getSprite()->getLocalBounds().width / 2;

	getInstance()->m_GUISpriteElementsMap.insert(
		std::pair<std::string, SpriteData*>("Weapon", new SpriteData("Gun", sf::Vector2f(0, 0), SpriteData::Foreground)));

	getInstance()->m_GUISpriteElementsMap.find("Weapon")->second->getSprite()->setOrigin(
		getInstance()->m_GUISpriteElementsMap.find("Weapon")->second->getSprite()->getLocalBounds().width / 2,
		0);
	getInstance()->m_GUISpriteElementsMap.find("Weapon")->second->getSprite()->setPosition(pos->x, 6);

	//Create ammo text
	pos->y += getInstance()->m_GUISpriteElementsMap.find("Weapon")->second->getSprite()->getLocalBounds().height + 4;

	getInstance()->m_GUITextElementsMap.insert(
		std::pair<std::string, TextData*>("Ammo", new TextData(*pos, TextData::Foreground)));
}

void GUI::createSortedVectors(){
	//Store all elements in order in a vector
	getInstance()->m_GUISpriteElementsVector.push_back(getInstance()->m_GUISpriteElementsMap.find("GunBox")->second);
	getInstance()->m_GUISpriteElementsVector.push_back(getInstance()->m_GUISpriteElementsMap.find("MachineGunBox")->second);
	getInstance()->m_GUISpriteElementsVector.push_back(getInstance()->m_GUISpriteElementsMap.find("Weapon")->second);

	getInstance()->m_GUITextElementsVector.push_back(getInstance()->m_GUITextElementsMap.find("Ammo")->second);
}