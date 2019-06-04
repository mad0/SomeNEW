#pragma once
#include "CGameState.h"
#include "CResourceManager.h"
#include "SFML/Graphics.hpp"
#include "CStateMachine.h"
#include "CInGameMenu.h"

class CPlayState : public CGameState {
public:
	CPlayState(CStateMachine * stateMachine, CResourceManager <sf::Font>*, sf::RenderWindow*);
	~CPlayState();
	void input();
	void update();
	void draw();
private:
	CInGameMenu menuInGame;
	sf::Text text;
	bool game;
};

