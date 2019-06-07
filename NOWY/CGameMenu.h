#pragma once
#include "CGameState.h"
#include <SFML/Graphics.hpp>
#include <vector>

class CGameEngine;

class CGameMenu : public CGameState {
public:
	CGameMenu(CGameEngine*);
	~CGameMenu();
	void input();
	void update();
	void draw();
private:
	sf::Sprite mainMenu[3];
};

