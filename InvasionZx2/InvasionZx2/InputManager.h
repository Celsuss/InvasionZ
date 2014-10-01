#pragma once
#include <vector>

class Key;
class MouseKey;
class KeyboardKey;

class InputManager{
public:
	typedef std::vector<Key*>KeyVector;

	~InputManager();
	static InputManager* getInstance();
	static void update();

	static const bool isUpKeyPressed();
	static const bool isLeftKeyPressed();
	static const bool isDownKeyPressed();
	static const bool isRightKeyPressed();
	static const bool isShootKeyPressed();

	static const bool isOneKeyPressed();
	static const bool isTwoKeyPressed();
	static const bool isThreeKeyPressed();
	static const bool isFourKeyPressed();
	static const bool isFiveKeyPressed();
	static const bool isSixKeyPressed();
	static const bool isSevenKeyPressed();
	static const bool isEightKeyPressed();
	static const bool isNineKeyPressed();

	static const bool isUpKeyDown();
	static const bool isLeftKeyDown();
	static const bool isDownKeyDown();
	static const bool isRightKeyDown();
	static const bool isShootKeyDown();
private:
	InputManager();
	static InputManager* m_Instance;
	
	KeyVector m_KeyVector;
	MouseKey* m_ShootKey;

	KeyboardKey* m_UpKey;
	KeyboardKey* m_LeftKey;
	KeyboardKey* m_DownKey;
	KeyboardKey* m_RightKey;

	KeyboardKey* m_OneKey;
	KeyboardKey* m_TwoKey;
	KeyboardKey* m_ThreeKey;
	KeyboardKey* m_FourKey;
	KeyboardKey* m_FiveKey;
	KeyboardKey* m_SixKey;
	KeyboardKey* m_SevenKey;
	KeyboardKey* m_EightKey;
	KeyboardKey* m_NineKey;
};