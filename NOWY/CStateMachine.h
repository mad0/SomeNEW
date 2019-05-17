#pragma once
#include <map>
#include <memory>
#include "SFML/Graphics.hpp"

class CGameState;

class CStateMachine {
public:
	CStateMachine();
	~CStateMachine();
	void addState(CGameState *);
	void delState(int);
	void switchState(int);
	CGameState* getState(int);
	void input(sf::Event&);
	void update();
	void draw(sf::RenderWindow&);
private:
	CGameState *curentState;
	std::map <int,CGameState*> mResources;
	int sceneID;
};

