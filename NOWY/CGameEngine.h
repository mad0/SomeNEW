#pragma once
#include "CGameState.h"
#include <memory>
#include <stack>

class CGameEngine
{
private:
	std::stack<CGameState*> gameStates;
	bool isRuning;
public:
	CGameEngine(CGameState*);
	~CGameEngine();
	void addState(CGameState*);
	CGameState* getState();
	void delState();
	void GameLoop();
};

