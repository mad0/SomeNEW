#pragma once
#include "CGameState.h"
#include "SFML/Graphics.hpp"
#include "CInGameMenu.h"
#include "CMap.h"
#include "CPlayer.h"

class CGameEngine;

class CPlayState : public CGameState {
public:
	CPlayState(CGameEngine*);
	~CPlayState();
	void input();
	void update();
	void draw();
private:
	std::unique_ptr<CMap> map;
	std::unique_ptr<CPlayer> player;
	CInGameMenu menuInGame;
	sf::Text textEsc[3];
	bool game;
	sf::RectangleShape bBig;
	sf::RectangleShape bSmall;
};

