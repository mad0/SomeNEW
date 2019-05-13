#pragma once
#include <memory>
#include <stack>
#include "SFML/Graphics.hpp"

class CGameState;

class CGameEngine {
private:
	std::stack<CGameState*> gameStates;
public:
	sf::RenderWindow window;
	CGameEngine();
	~CGameEngine();
	void addState(CGameState*);
	CGameState* getState();
	void delState();
	void GameLoop();
};

