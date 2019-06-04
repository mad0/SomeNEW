#include "CGameMenu.h"
#include <iostream>
#include <typeinfo>
#include "CStateMachine.h"
#include "CPlayState.h"

CGameMenu::CGameMenu(CStateMachine * _stateMachine, sf::RenderWindow* _window, CResourceManager<sf::Font> *_fontManager) {
	window = _window;
	stateMachine = _stateMachine;
	fontManager = _fontManager;
	std::cout << "Class: CGameMenu is starting...\n";
	//CResourceManager<sf::Font> dupa;
	//dupa = new CResourceManager<sf::Font>();
	fontManager->addResource(1, "fonts/lucon.ttf");
	fontManager->addResource(2, "fonts/CGA.ttf");
	//this->engine = _engine;
	//std::cout << &logObj << "\n";;
	//this->font.loadFromFile("fonts/CGA.ttf");
	//showLog(typeid(dynamic_cast<CGameMenu*>(engine->getState())).name());
	//std::string menuText[3] = { "1", "2", "3" };
	//mainMenu[0].setFont(font);
	mainMenu[0].setFont(fontManager->getResource(1));
	mainMenu[0].setString("MENU");
	std::cout << "fontoooooooooo address:"<<&fontManager->getResource(1) << "\n";
	//for (int x = 0; x < 3; x++) {
	//	mainMenu[x].setFont(dupa.getResource(1));
	//	std::cout << typeid(dupa.getResource(1).getInfo()).name();
	//	mainMenu[x].setString(menuText[x]);
	//}
}


CGameMenu::~CGameMenu() {
	std::cout << "Class: CGameMenu is ending...\n";
}

void CGameMenu::input() {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window->close();
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
			std::cout << "ESC in MENU pressed....\n";
		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A) {
			stateMachine->addState(std::make_shared<CPlayState>(stateMachine, fontManager, window));
		}
	}	
}

void CGameMenu::update() {
	//std::cout << "UPDATE\n";
}

void CGameMenu::draw() {
	window->clear();
	window->draw(mainMenu[0]);
	window->display();
}
