#pragma once
#include "CGameState.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "CStateMachine.h"

class CGameMenu : public CGameState {
public:
	CGameMenu(CResourceManager<sf::Font>&);

	~CGameMenu();
	void input(sf::Event&);
	void update();
	void draw(sf::RenderWindow&);
private:
	sf::Text  mainMenu[3];
};

