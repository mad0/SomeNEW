#include "CGameEngine.h"
#include <iostream>
#include "CGameState.h"

CGameEngine::CGameEngine()
{
	isRuning = true;
	window.create(sf::VideoMode(1280, 720), "GameEngine v.001");
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
	std::cout << "LOOP\n";
	while (isRuning) {
		while (window.isOpen()) {
			getState()->input();
			getState()->update();
			window.clear();
			getState()->draw();
			window.display();
		}
	}
}

