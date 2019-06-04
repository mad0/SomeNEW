#include <iostream>
#include <typeinfo>
#include "CGameMenu.h"
#include "CPlayState.h"

CGameMenu::CGameMenu(CStateMachine * _stateMachine, sf::RenderWindow* _window, CResourceManager<sf::Font> *_fontManager) {
	window = _window;
	stateMachine = _stateMachine;
	fontManager = _fontManager;
	std::cout << "Class: CGameMenu is starting...\n";
	std::string textMenu[2] = { "START GAME", "QUIT GAME" };
	for (int x = 0; x < 2; x++) {
		mainMenu[x].setFont(fontManager->getResource(1));
		mainMenu[x].setString(textMenu[x]);
		mainMenu[x].setPosition(sf::Vector2f(window->getSize().x/2-mainMenu[x].getGlobalBounds().width/2, window->getSize().y/2-mainMenu[x].getGlobalBounds().height-50+(x*100)));
		std::cout << "fontoooooooooo address:" << &fontManager->getResource(1) << "\n";
	}
}


CGameMenu::~CGameMenu() {
	std::cout << "Class: CGameMenu is ending...\n";
}

void CGameMenu::input() {
	sf::Event event;
	sf::Vector2f mouse (sf::Mouse::getPosition(*window));
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window->close();
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
			std::cout << "ESC in MENU pressed....\n";
			window->close();
		}
		if ((mainMenu[0].getGlobalBounds().contains(mouse)) && (event.type == sf::Event::MouseButtonReleased) && (event.key.code == sf::Mouse::Left)) {
			stateMachine->addState(std::make_shared<CPlayState>(stateMachine, fontManager, window));
		}
		if ((mainMenu[1].getGlobalBounds().contains(mouse)) && (event.type == sf::Event::MouseButtonReleased) && (event.key.code == sf::Mouse::Left)) {
			window->close();
		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) {
		}
	}
	for (auto& m : mainMenu) {
		if (m.getGlobalBounds().contains(mouse))
			m.setFillColor(sf::Color::Red);
		else
			m.setFillColor(sf::Color::White);
	}
	
}

void CGameMenu::update() {
}

void CGameMenu::draw() {
	window->clear();
	for (auto& t: mainMenu)
		window->draw(t);
	window->display();
}
