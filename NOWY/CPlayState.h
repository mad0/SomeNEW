#pragma once
#include "CGameState.h"

class CPlayState : public CGameState {
public:
	CPlayState(CGameEngine *_engine);
	~CPlayState();
	void input();
	void update();
	void draw();
};

