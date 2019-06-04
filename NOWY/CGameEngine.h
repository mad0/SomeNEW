#pragma once
#include "CStateMachine.h"
#include "CResourceManager.h"

class CGameEngine {
private:
	bool isRunning;
	CStateMachine stateMachine;
	CResourceManager<sf::Font> fontManager;
public:
	sf::RenderWindow window;
	CGameEngine();
	~CGameEngine();
	void GameLoop();
};

