#pragma once
#include <memory>
#include "SFML/Graphics.hpp"

class CGameState;

class CStateMachine {
public:
	CStateMachine();
	~CStateMachine();
	void addState(std::shared_ptr<CGameState>);
	void changeState(int);
	std::shared_ptr<CGameState> getState(int);
	void delState();
	void input();
	void update();
	void draw();
private:
	std::shared_ptr<CGameState> curentState;
	std::vector <std::shared_ptr<CGameState>> mResources;
};

