#include "CInGameMenu.h"
#include "CStateMachine.h"

CInGameMenu::CInGameMenu( CResourceManager<sf::Texture>* textureResources ,sf::RenderWindow* _window) : window(_window) {
	bBig.setSize(sf::Vector2f(window->getSize()));
	bBig.setFillColor(sf::Color(127, 127, 127, 150));
	bBig.setPosition(sf::Vector2f(window->getSize().x/2-bBig.getGlobalBounds().width/2, window->getSize().y/2-bBig.getGlobalBounds().height/2));
	bSmall.setSize(sf::Vector2f(300, 350));
	bSmall.setFillColor(sf::Color(181, 230, 29, 125));
	bSmall.setPosition(sf::Vector2f(window->getSize().x / 2 - bSmall.getGlobalBounds().width / 2, window->getSize().y / 2 - bSmall.getGlobalBounds().height / 2));
	textMenu[0].setTexture(textureResources->getResource(8));
	textMenu[0].setPosition(sf::Vector2f(bSmall.getPosition().x+bSmall.getGlobalBounds().width/2-textMenu[0].getGlobalBounds().width/2, bSmall.getPosition().y+50));
	textMenu[1].setTexture(textureResources->getResource(9));
	textMenu[1].setPosition(sf::Vector2f(bSmall.getPosition().x + bSmall.getGlobalBounds().width / 2 - textMenu[1].getGlobalBounds().width / 2, bSmall.getPosition().y + 200));

}


CInGameMenu::~CInGameMenu(){
}

void CInGameMenu::showMenu() {
	window->draw(bBig);
	window->draw(bSmall);
	for (auto& m : textMenu) {
		if (m.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window)))) {
			//m.setFillColor(sf::Color::Red);
		}
		else {
			//m.setFillColor(sf::Color::White);
		}
			
	}
	for (auto& t: textMenu)
		window->draw(t);
}


bool CInGameMenu::inputMenu(sf::Event * event, CStateMachine* _stateMachine) {
	if ((textMenu[1].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window)))) && (event->type == sf::Event::MouseButtonReleased) && (event->key.code == sf::Mouse::Left))
		return true;
	else return false;
}
