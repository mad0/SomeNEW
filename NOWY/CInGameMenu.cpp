#include "CInGameMenu.h"

CInGameMenu::CInGameMenu(CResourceManager<sf::Font>& fontManager)  {
	bBig.setSize(sf::Vector2f(1280, 720));
	bBig.setFillColor(sf::Color(127, 127, 127, 150));
	bSmall.setSize(sf::Vector2f(300, 350));
	bSmall.setFillColor(sf::Color(181, 230, 29, 125));
	bSmall.setPosition(sf::Vector2f(bBig.getGlobalBounds().width/2-bSmall.getGlobalBounds().width/2, bBig.getGlobalBounds().height/2-bSmall.getGlobalBounds().height/2));
	std::string mOptions[3] = { "BACK TO GAME", "OPTIONS", "MAIN MENU" };
	for (int x = 0; x < 3; x++) {
		textMenu[x].setFont(fontManager.getResource(1));
		textMenu[x].setString(mOptions[x]);
		textMenu[x].setPosition(sf::Vector2f(bSmall.getGlobalBounds().left+bSmall.getGlobalBounds().width/2-textMenu[x].getGlobalBounds().width/2, bSmall.getGlobalBounds().top + bSmall.getGlobalBounds().height / 2 - textMenu[x].getGlobalBounds().height / 2-x*100));
	}
	
}


CInGameMenu::~CInGameMenu(){
}

void CInGameMenu::showMenu(sf::RenderWindow * window) {
	window->draw(bBig);
	window->draw(bSmall);
	for (auto& m : textMenu) {
		if (m.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window))))
			m.setFillColor(sf::Color::Red);
		else
			m.setFillColor(sf::Color::White);
	}
	for (auto& t: textMenu)
		window->draw(t);
}

void CInGameMenu::update() {
	
}
