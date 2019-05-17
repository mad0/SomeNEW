#pragma once
#include "CResourceManager.h"

class CGameEngine;

class CGameState {
public:
	virtual void input(sf::Event&) =0;
	virtual void draw(sf::RenderWindow &window) = 0;
	virtual void update() = 0;
};

