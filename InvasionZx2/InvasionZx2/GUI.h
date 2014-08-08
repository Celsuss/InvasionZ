#pragma once
#include "SFML/System/Vector2.hpp"
#include <map>
#include <vector>

class TextData;
class SpriteData;
class PositionData;

class GUI{
public:
	static GUI* getInstance();

	static void initialize();
	static void update();
private:
	GUI();
	~GUI();
	static GUI* m_Instance;

	static void draw();
	static void updateWeaponSprite();
	static void updateAmmoText(std::string weapon);

	static void initializeWeaponBoxes(sf::Vector2f* pos);
	static void initializeGun(sf::Vector2f* pos);
	static void createSortedVectors();

	std::map<std::string, SpriteData*> m_GUISpriteElementsMap;
	std::map<std::string, TextData*> m_GUITextElementsMap;

	//Allso store SpriteData and TextData so it can drawn in right order
	std::vector<SpriteData*> m_GUISpriteElementsVector;
	std::vector<TextData*> m_GUITextElementsVector;
};