#pragma once
#include <memory>
#include "SFML/Graphics.hpp"
#include <map>

enum STATES {MENU, PLAY};

class CGameState;

class CStateMachine {
public:
	CStateMachine();
	~CStateMachine();
	void addState(STATES, std::shared_ptr<CGameState>);
	void changeState(STATES);
	std::shared_ptr<CGameState> getState(STATES);
	void delState();
	void input();
	void update();
	void draw();
	STATES sType;
private:
	std::shared_ptr<CGameState> curentState;
	std::map<STATES, std::shared_ptr<CGameState>> mResources;
};

