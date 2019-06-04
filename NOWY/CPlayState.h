#pragma once
#include "CGameState.h"
#include "CResourceManager.h"
#include "SFML/Graphics.hpp"
#include "CStateMachine.h"


class CPlayState : public CGameState {
public:
	CPlayState(CStateMachine * stateMachine, CResourceManager <sf::Font>*, sf::RenderWindow*);
	~CPlayState();
	void input();
	void update();
	void draw();
private:
	sf::Text text;
};

