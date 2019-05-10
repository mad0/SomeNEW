#pragma once
#include "CGameState.h"

class CGameMenu : public CGameState
{
public:
	CGameMenu();
	~CGameMenu();
	void input();
	void update();
	void draw();
};

