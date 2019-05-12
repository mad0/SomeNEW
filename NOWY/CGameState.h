#pragma once
#include "CGameEngine.h"

class CGameState
{
public:
	virtual void input() =0;
	virtual void draw() = 0;
	virtual void update() = 0;
protected:
	CGameEngine *engine;
};

