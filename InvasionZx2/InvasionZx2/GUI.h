#pragma once
#include "SFML/System/Vector2.hpp"
#include "SFML/System/Clock.hpp"
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
	static void setequippedWeapon(std::string name);
private:
	GUI();
	~GUI();
	static GUI* m_Instance;

	static void draw();
	static void updateWeaponSprite();
	static void updateAmmoText(std::string weapon);

	static void initializeWeaponBoxes(sf::Vector2f* pos);
	static void initializeGun(std::string name);
	static void initializeBoxBoarder();

	static void createSortedVectors();

	static void addSpriteBox(std::string boxName, std::string stringName, sf::Vector2f pos = sf::Vector2f(0, 0));
	static void addSprite(std::string name, sf::Vector2f pos = sf::Vector2f(0, 0));
	static void addText(std::string name, sf::Vector2f pos = sf::Vector2f(0,0));

	static void setSpritePosition(std::string name, sf::Vector2f pos);
	static void setSpritePosition(std::string name, float x, float y);

	static void centerSpriteOrigin(std::string name);
	static void centerSpriteOriginX(std::string name);
	static void centerSpriteOriginY(std::string name);

	std::map<std::string, SpriteData*> m_GUIBoxSpriteElementsMap;
	std::map<std::string, SpriteData*> m_GUISpriteElementsMap;
	std::map<std::string, TextData*> m_GUITextElementsMap;

	//Allso store SpriteData and TextData so it can drawn in right order
	std::vector<SpriteData*> m_GUISpriteElementsVector;
	std::vector<TextData*> m_GUITextElementsVector;

	SpriteData* m_EquippedWeaponBoarder;

	//FPS
	static void showFPS();

	sf::Clock m_FPSClock;
	sf::Clock m_FPSTickClock;
	float m_FPS;
	float m_Tick;

	TextData* m_FPSText;
};