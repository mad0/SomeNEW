#pragma once
#include "CGameState.h"
#include "CResourceManager.h"
#include "SFML/Graphics.hpp"
#include "CStateMachine.h"
#include "CInGameMenu.h"

class CPlayState : public CGameState {
public:
	CPlayState(CStateMachine*, CResourceManager <sf::Texture>*, sf::RenderWindow*);
	~CPlayState();
	void input();
	void update();
	void draw();
private:
	CInGameMenu menuInGame;
	sf::Text textEsc[3];
	bool game;
	sf::RectangleShape bBig;
	sf::RectangleShape bSmall;
};

