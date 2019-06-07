#pragma once
#include "CResourceManager.h"

class CGameEngine;

class CGameState {
public:
	CGameEngine *engine;
	sf::RenderWindow &window;
	virtual void input() =0;
	virtual void draw() = 0;
	virtual void update() = 0;
private:
	
};

