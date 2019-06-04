#pragma once
#include "CGameState.h"
#include <SFML/Graphics.hpp>
#include <vector>

class CStateMachine;

class CGameMenu : public CGameState {
public:
	CGameMenu(CStateMachine*, sf::RenderWindow *, CResourceManager<sf::Font>*);
	~CGameMenu();
	void input();
	void update();
	void draw();
private:
	sf::Text  mainMenu[2];
};

