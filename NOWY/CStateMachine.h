#pragma once
#include <map>
#include <memory>
#include "SFML/Graphics.hpp"

class CGameState;

class CStateMachine {
public:
	CStateMachine();
	~CStateMachine();
	void addState(std::shared_ptr<CGameState>);
	void delState(int);
	void switchState(int);
	CGameState* getState(int);
	void input(sf::Event&);
	void update();
	void draw(sf::RenderWindow&);
private:
	std::shared_ptr<CGameState> curentState;
	std::map <int,std::shared_ptr<CGameState>> mResources;
	int sceneID;
};

