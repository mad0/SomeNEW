#include "CGameMenu.h"
#include "CGameEngine.h"
#include <iostream>
#include <typeinfo>

CGameMenu::CGameMenu(CResourceManager<sf::Font> &fontManager) {
	std::cout << "Class: CGameMenu is starting...\n";
	//CResourceManager<sf::Font> dupa;
	//dupa = new CResourceManager<sf::Font>();
	fontManager.addResource(1, "fonts/lucon.ttf");
	fontManager.addResource(2, "fonts/CGA.ttf");
	//this->engine = _engine;
	//std::cout << &logObj << "\n";;
	//this->font.loadFromFile("fonts/CGA.ttf");
	//showLog(typeid(dynamic_cast<CGameMenu*>(engine->getState())).name());
	//std::string menuText[3] = { "1", "2", "3" };
	//mainMenu[0].setFont(font);
	mainMenu[0].setFont(fontManager.getResource(1));
	mainMenu[0].setString("dupa");
	std::cout << "fontoooooooooo address:"<<&fontManager.getResource(1) << "\n";
	//for (int x = 0; x < 3; x++) {
	//	mainMenu[x].setFont(dupa.getResource(1));
	//	std::cout << typeid(dupa.getResource(1).getInfo()).name();
	//	mainMenu[x].setString(menuText[x]);
	//}
}


CGameMenu::~CGameMenu() {
	std::cout << "Class: CGameMenu is ending...\n";
}

void CGameMenu::input(sf::Event &_event) {
		if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::N) {
			std::cout << "DZIALA!\n";
		}

}

void CGameMenu::update() {
	//std::cout << "UPDATE\n";
}

void CGameMenu::draw(sf::RenderWindow &_window) {
	_window.clear();
	_window.draw(mainMenu[0]);
	_window.display();
}
