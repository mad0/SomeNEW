#include "CGameMenu.h"
#include "CGameEngine.h"
#include "CPlayState.h"
#include <iostream>
#include <typeinfo>

CGameMenu::CGameMenu(CGameEngine *_engine) {
	this->engine = _engine;
	std::cout << &logObj << "\n";;
	this->font.loadFromFile("fonts/CGA.ttf");
	showLog(typeid(dynamic_cast<CGameMenu*>(engine->getState())).name());
	std::string menuText[3] = { "1", "2", "3" };
	std::cout << "Create: GAME MENU STATE\n";
	for (int x = 0; x < 3; x++) {
		mainMenu[x].setFont(font);
		mainMenu[x].setString(menuText[x]);
	}
}


CGameMenu::~CGameMenu() {
	std::cout << "Destruct: GAME MENU STATE\n";
}

void CGameMenu::input() {
	sf::Event event;
	while (engine->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) 
			engine->window.close();
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::N) {
			engine->addState(new CPlayState(engine));
		}
	}
}

void CGameMenu::update() {
	//std::cout << "UPDATE\n";
}

void CGameMenu::draw() {
	engine->window.clear();
	engine->window.draw(mainMenu[2]);
	engine->window.draw(logObj);
	engine->window.display();
}
