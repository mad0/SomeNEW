#pragma once
#include "CGameState.h"

enum class mOPTIONS {BACK, OPTIONS, EXIT, STOP};

class CGameEngine;

class CInGameMenu  {
private:
	sf::RectangleShape bBig;
	sf::RectangleShape bSmall;
	sf::Sprite textMenu[3];
	CGameEngine * engine;
public:
	CInGameMenu(CGameEngine*);
	~CInGameMenu();
	void showMenu();
	mOPTIONS inputMenu(sf::Event&);
};

