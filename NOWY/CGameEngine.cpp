#include "CGameEngine.h"
#include <iostream>


CGameEngine::CGameEngine(CGameState *_state)
{
	isRuning = true;
	gameStates.push(_state);
}

CGameEngine::~CGameEngine()
{
	//usuwa ostatni wskaznik ze stosu
	//std::cout << &(*getState()) << "\n";
	//delState();
	std::cout << "jdjdjd\n";
}

void CGameEngine::addState(CGameState *_state)
{
	gameStates.push(_state);
}


CGameState * CGameEngine::getState()
{
	return gameStates.top();
}

void CGameEngine::delState()
{
	if (!gameStates.empty())
		gameStates.pop();
	//delete gameStates.top();
}

void CGameEngine::GameLoop()
{
	while (isRuning) {
		getState()->input();
		getState()->update();
		getState()->draw();
	}
}

