#include "CGameEngine.h"
#include <iostream>
#include "CGameState.h"
#include <typeinfo>

CGameEngine::CGameEngine()
{
	window.create(sf::VideoMode(1280, 720), "GameEngine v.001");
}

CGameEngine::~CGameEngine(){
	std::cout << "NISZCZE ENGINE\n";
}

void CGameEngine::addState(CGameState *_state){
	gameStates.push(_state);
}


CGameState * CGameEngine::getState(){
	return gameStates.top();
}

void CGameEngine::delState() {
	if (!gameStates.empty()) {
		delete gameStates.top();
		gameStates.pop();
		std::cout << "DEL: Usuwam stan ze stosu. Aktualna wielkosc stosu: "<<gameStates.size()<<"\n";
	}
}

void CGameEngine::GameLoop(){
	std::cout << "LOOP\n";
		while (window.isOpen()) {
			getState()->input();
			getState()->update();
			getState()->draw();
		}
		delState();
}

