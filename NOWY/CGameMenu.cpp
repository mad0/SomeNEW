#include <iostream>
#include <typeinfo>
#include "CGameMenu.h"
#include "CPlayState.h"
#include "CGameEngine.h"

CGameMenu::CGameMenu(CGameEngine *_engine) {
	engine = _engine;
	std::cout << "Class: CGameMenu is starting...\n";
	mainMenu[0].setTexture(engine->getTexture(2));
	mainMenu[0].setPosition(sf::Vector2f(engine->getWindow().getSize().x / 2 - mainMenu[0].getGlobalBounds().width / 2, engine->getWindow().getSize().y / 2 - mainMenu[0].getGlobalBounds().height - 50));
	mainMenu[1].setTexture(engine->getTexture(6));
	mainMenu[1].setPosition(sf::Vector2f(engine->getWindow().getSize().x / 2 - mainMenu[1].getGlobalBounds().width / 2, engine->getWindow().getSize().y / 2 - mainMenu[1].getGlobalBounds().height + 100));
	mainMenu[2].setTexture(engine->getTexture(4));
	mainMenu[2].setPosition(sf::Vector2f(engine->getWindow().getSize().x / 2 - mainMenu[2].getGlobalBounds().width / 2, engine->getWindow().getSize().y / 2 - mainMenu[2].getGlobalBounds().height +250));
}


CGameMenu::~CGameMenu() {
	std::cout << "Class: CGameMenu is ending...\n";
}

void CGameMenu::input() {
	sf::Event event;
	sf::Vector2f mouse (sf::Mouse::getPosition(engine->getWindow()));
	while (engine->getWindow().pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			engine->getWindow().close();
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
			std::cout << "ESC in MENU pressed....\n";
			engine->getWindow().close();
		}
		if ((mainMenu[0].getGlobalBounds().contains(mouse)) && (event.type == sf::Event::MouseButtonReleased) && (event.key.code == sf::Mouse::Left)) {
			engine->addState(STATES::PLAY, std::make_shared<CPlayState>(engine));
		}
		if ((mainMenu[2].getGlobalBounds().contains(mouse)) && (event.type == sf::Event::MouseButtonReleased) && (event.key.code == sf::Mouse::Left)) {
			engine->getWindow().close();
		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) {
		}
	}

		if (mainMenu[0].getGlobalBounds().contains(mouse))
			mainMenu[0].setTexture(engine->getTexture(3));
		else mainMenu[0].setTexture(engine->getTexture(2));

		if (mainMenu[1].getGlobalBounds().contains(mouse))
			mainMenu[1].setTexture(engine->getTexture(7));
		else mainMenu[1].setTexture(engine->getTexture(6));

		if (mainMenu[2].getGlobalBounds().contains(mouse))
			mainMenu[2].setTexture(engine->getTexture(5));
		else mainMenu[2].setTexture(engine->getTexture(4));

	
}

void CGameMenu::update() {
}

void CGameMenu::draw() {
	engine->getWindow().clear(sf::Color(159, 159, 159 , 255));
	for (auto& t: mainMenu)
		engine->getWindow().draw(t);
	engine->getWindow().display();
}
