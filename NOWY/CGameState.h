#pragma once
#include "CResourceManager.h"

class CStateMachine;

class CGameState {
public:
	virtual void input() =0;
	virtual void draw() = 0;
	virtual void update() = 0;
protected:
	CStateMachine * stateMachine;
	sf::RenderWindow * window;
	CResourceManager<sf::Font> * fontManager;
};

