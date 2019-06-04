#include <iostream>
#include <typeinfo>
#include "CGameMenu.h"
#include "CPlayState.h"

CGameMenu::CGameMenu(CStateMachine * _stateMachine, sf::RenderWindow* _window, CResourceManager<sf::Font> *_fontManager) {
	window = _window;
	stateMachine = _stateMachine;
	fontManager = _fontManager;
	std::cout << "Class: CGameMenu is starting...\n";
	fontManager->addResource(1, "fonts/lucon.ttf");
	fontManager->addResource(2, "fonts/CGA.ttf");
	mainMenu[0].setFont(fontManager->getResource(1));
	mainMenu[0].setString("MENU");
	std::cout << "fontoooooooooo address:"<<&fontManager->getResource(1) << "\n";
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
}

void CGameMenu::draw() {
	window->clear();
	window->draw(mainMenu[0]);
	window->display();
}
