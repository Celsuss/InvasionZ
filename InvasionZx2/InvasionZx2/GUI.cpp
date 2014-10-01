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
#include <ostream>

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

	getInstance()->m_FPSText = new TextData(sf::Vector2f(150, 0));
	getInstance()->m_Tick = 0;
}

void GUI::update(){
	updateWeaponSprite();
	draw();
	showFPS();
}

void GUI::setequippedWeapon(std::string name){
	sf::Vector2f pos;
	pos = getInstance()->m_GUIBoxSpriteElementsMap.find(name + "Box")->second->getSprite()->getPosition();
	getInstance()->m_EquippedWeaponBoarder->getSprite()->setPosition(pos);
}

void GUI::showFPS(){
	getInstance()->m_Tick++;
	float currentTime = getInstance()->m_FPSClock.getElapsedTime().asSeconds();
	if (getInstance()->m_FPSTickClock.getElapsedTime().asSeconds() > 1){
		getInstance()->m_FPSTickClock.restart();
		getInstance()->m_FPS = getInstance()->m_Tick;
		getInstance()->m_Tick = 0;

		std::ostringstream converter;
		converter << getInstance()->m_FPS;
		std::string text = converter.str();
		getInstance()->m_FPSText->getText()->setString(text);
	}
	GraphicManager::draw(getInstance()->m_FPSText);
}

void GUI::draw(){
	WeaponData* weaponData = EntityFactory::getPlayer()->getData<WeaponData>("WeaponData");

	for (auto i = getInstance()->m_GUIBoxSpriteElementsMap.begin(); i != getInstance()->m_GUIBoxSpriteElementsMap.end(); i++){
		GraphicManager::draw(i->second);
	}
	for (int i = 0; i < weaponData->getWeaponVectorSize(); i++){
		GraphicManager::draw(getInstance()->m_GUISpriteElementsVector[i]);
	}
	for (int i = 0; i < weaponData->getWeaponVectorSize(); i++){
		GraphicManager::draw(getInstance()->m_GUITextElementsVector[i]);
	}
	GraphicManager::draw(getInstance()->m_EquippedWeaponBoarder);
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

	TextData* textData = getInstance()->m_GUITextElementsMap.find(weapon+"Ammo")->second;
	textData->getText()->setString(text);
	textData->getText()->setOrigin(textData->getText()->getLocalBounds().width / 2, 0);
}

void GUI::initializeWeaponBoxes(sf::Vector2f* pos){
	//Create gun box
	addSpriteBox("GunBox", "GreyBox", *pos);
	initializeGun("Gun");

	initializeBoxBoarder();

	//Create machine gun box
	pos->x = 0;
	pos->y = 0;
	pos->x += getInstance()->m_GUIBoxSpriteElementsMap.find("GunBox")->second->getSprite()->getLocalBounds().width;

	addSpriteBox("MachineGunBox", "GreyBox", *pos);
	initializeGun("MachineGun");
	//initializeMachineGun();
}

void GUI::initializeGun(std::string name){
	//Create weapon icon
	sf::Vector2f poos = sf::Vector2f(0, 0);
	poos.x = getInstance()->m_GUIBoxSpriteElementsMap.find(name+"Box")->second->getSprite()->getPosition().x;
	poos.x += getInstance()->m_GUIBoxSpriteElementsMap.find(name+"Box")->second->getSprite()->getLocalBounds().width / 2;

	addSprite(name);
	centerSpriteOriginX(name);
	setSpritePosition(name, poos.x, 6);

	//Create ammo text
	poos.y += getInstance()->m_GUISpriteElementsMap.find(name)->second->getSprite()->getLocalBounds().height + 4;
	addText(name+"Ammo", poos);
}

void GUI::initializeBoxBoarder(){
	sf::Vector2f pos;
	pos = getInstance()->m_GUIBoxSpriteElementsMap.begin()->second->getSprite()->getPosition();
	getInstance()->m_EquippedWeaponBoarder = new SpriteData("YellowBoxLine", pos, SpriteData::Foreground);
	getInstance()->m_EquippedWeaponBoarder->getSprite()->setPosition(pos);
}

void GUI::createSortedVectors(){
	//----Store all elements in order in a vector
	//Store weapons
	getInstance()->m_GUISpriteElementsVector.push_back(getInstance()->m_GUISpriteElementsMap.find("Gun")->second);
	getInstance()->m_GUISpriteElementsVector.push_back(getInstance()->m_GUISpriteElementsMap.find("MachineGun")->second);

	//Store ammo
	getInstance()->m_GUITextElementsVector.push_back(getInstance()->m_GUITextElementsMap.find("GunAmmo")->second);
	getInstance()->m_GUITextElementsVector.push_back(getInstance()->m_GUITextElementsMap.find("MachineGunAmmo")->second);
	//----/Store all elements in order in a vector
}

void GUI::addSpriteBox(std::string boxName, std::string stringName, sf::Vector2f pos){
	getInstance()->m_GUIBoxSpriteElementsMap.insert(
		std::pair<std::string, SpriteData*>(boxName, new SpriteData(stringName, pos, SpriteData::Foreground)));
}

void GUI::addSprite(std::string name, sf::Vector2f pos){
	getInstance()->m_GUISpriteElementsMap.insert(
		std::pair<std::string, SpriteData*>(name, new SpriteData(name, pos, SpriteData::Foreground)));
}

void GUI::addText(std::string name, sf::Vector2f pos){
	getInstance()->m_GUITextElementsMap.insert(
		std::pair<std::string, TextData*>(name, new TextData(pos, TextData::Foreground)));
}

void GUI::setSpritePosition(std::string name, sf::Vector2f pos){
	getInstance()->m_GUISpriteElementsMap.find(name)->second->getSprite()->setPosition(pos);
}

void GUI::setSpritePosition(std::string name, float x, float y){
	getInstance()->m_GUISpriteElementsMap.find(name)->second->getSprite()->setPosition(x,y);
}

void GUI::centerSpriteOrigin(std::string name){
	getInstance()->m_GUISpriteElementsMap.find(name)->second->getSprite()->setOrigin(
		getInstance()->m_GUISpriteElementsMap.find(name)->second->getSprite()->getLocalBounds().width / 2,
		getInstance()->m_GUISpriteElementsMap.find(name)->second->getSprite()->getLocalBounds().height / 2);
}

void GUI::centerSpriteOriginX(std::string name){
	getInstance()->m_GUISpriteElementsMap.find(name)->second->getSprite()->setOrigin(
		getInstance()->m_GUISpriteElementsMap.find(name)->second->getSprite()->getLocalBounds().width / 2,
		0);
}

void GUI::centerSpriteOriginY(std::string name){
	getInstance()->m_GUISpriteElementsMap.find(name)->second->getSprite()->setOrigin(
		0,
		getInstance()->m_GUISpriteElementsMap.find(name)->second->getSprite()->getLocalBounds().height / 2);
}