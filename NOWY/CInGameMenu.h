#pragma once
#include "CGameState.h"

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
	bool inputMenu(sf::Event&);
};

