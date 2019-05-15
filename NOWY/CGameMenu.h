#pragma once
#include "CGameState.h"
#include <SFML/Graphics.hpp>
#include <vector>

class CGameEngine;

class CGameMenu : public CGameState {
public:
	CGameMenu(CGameEngine *);
	~CGameMenu();
	void input();
	void update();
	void draw();
private:
	
	sf::Text  mainMenu[3];
	sf::Font font;
};

