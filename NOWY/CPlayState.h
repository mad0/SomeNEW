#pragma once
#include "CGameState.h"
#include "SFML/Graphics.hpp"
#include "CInGameMenu.h"

class CGameEngine;

class CPlayState : public CGameState {
public:
	CPlayState(CGameEngine*);
	~CPlayState();
	void input();
	void update();
	void draw();
private:
	sf::Sprite bg;
	CInGameMenu menuInGame;
	sf::Text textEsc[3];
	bool game;
	sf::RectangleShape bBig;
	sf::RectangleShape bSmall;
};

