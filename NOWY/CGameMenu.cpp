#include "CGameMenu.h"
#include "CGameEngine.h"
#include "CPlayState.h"
#include <iostream>
#include <typeinfo>
#include "CResourceManager.h"

CGameMenu::CGameMenu(CGameEngine *_engine) {
	CResourceManager<sf::Font> dupa;
	dupa.addResource(1, "fonts/lucon.ttf");
	this->engine = _engine;
	std::cout << &logObj << "\n";;
	//this->font.loadFromFile("fonts/CGA.ttf");
	showLog(typeid(dynamic_cast<CGameMenu*>(engine->getState())).name());
	std::string menuText[3] = { "1", "2", "3" };
	std::cout << "Create: GAME MENU STATE\n";
	mainMenu[0].setFont(dupa.getResource(1));
	mainMenu[0].setString("dupa");
	//for (int x = 0; x < 3; x++) {
	//	mainMenu[x].setFont(dupa.getResource(1));
	//	std::cout << typeid(dupa.getResource(1).getInfo()).name();
	//	mainMenu[x].setString(menuText[x]);
	//}
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
	engine->window.draw(mainMenu[0]);
	engine->window.draw(logObj);
	engine->window.display();
}
