#include "CGameMenu.h"
#include <iostream>
#include "CGameEngine.h"

CGameMenu::CGameMenu(CGameEngine *_engine)
{
	this->engine = _engine;
	font.loadFromFile("fonts/CGA.ttf");
	std::string menuText[3] = { "1", "2", "3" };
	std::cout << "Create: GAME MENU STATE\n";
	for (int x = 0; x < 3; x++) {
		mainMenu[x].setFont(font);
		mainMenu[x].setString(menuText[x]);
	}
}


CGameMenu::~CGameMenu()
{
	std::cout << "Destruct: GAME MENU STATE\n";
}

void CGameMenu::input()
{
	sf::Event event;
	while (engine->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) {
			engine->window.close();
			engine->delState();
		}
			
	}
}

void CGameMenu::update()
{
	std::cout << "UPDATE\n";
}

void CGameMenu::draw()
{
	//engine->window.draw(mainMenu[0]);
	std::cout << "DRAW\n";
}
