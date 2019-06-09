#pragma once
#include "CResourceManager.h"

class CGameEngine;

class CGameState {
public:
	CGameEngine *engine;
	virtual void input() =0;
	virtual void draw() = 0;
	virtual void update() = 0;
};

