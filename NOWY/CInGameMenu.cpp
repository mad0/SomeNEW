#include "CInGameMenu.h"
#include "CStateMachine.h"
#include "CGameEngine.h"

CInGameMenu::CInGameMenu(CGameEngine* _engine): engine(_engine) {
	bBig.setSize(sf::Vector2f(engine->getWindow().getSize()));
	bBig.setFillColor(sf::Color(127, 127, 127, 150));
	bBig.setPosition(sf::Vector2f(engine->getWindow().getSize().x/2-bBig.getGlobalBounds().width/2, engine->getWindow().getSize().y/2-bBig.getGlobalBounds().height/2));
	bSmall.setSize(sf::Vector2f(300, 350));
	bSmall.setFillColor(sf::Color(181, 230, 29, 125));
	bSmall.setPosition(sf::Vector2f(engine->getWindow().getSize().x / 2 - bSmall.getGlobalBounds().width / 2, engine->getWindow().getSize().y / 2 - bSmall.getGlobalBounds().height / 2));
	textMenu[0].setTexture(engine->getTexture(8));
	textMenu[0].setPosition(sf::Vector2f(bSmall.getPosition().x+bSmall.getGlobalBounds().width/2-textMenu[0].getGlobalBounds().width/2, bSmall.getPosition().y+50));
	textMenu[1].setTexture(engine->getTexture(10));
	textMenu[1].setPosition(sf::Vector2f(bSmall.getPosition().x + bSmall.getGlobalBounds().width / 2 - textMenu[1].getGlobalBounds().width / 2, bSmall.getPosition().y + 200));
}


CInGameMenu::~CInGameMenu(){
}

void CInGameMenu::showMenu() {
	engine->getWindow().draw(bBig);
	engine->getWindow().draw(bSmall);
	if (textMenu[0].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(engine->getWindow()))))
		textMenu[0].setTexture(engine->getTexture(9));
	else textMenu[0].setTexture(engine->getTexture(8));
	if (textMenu[1].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(engine->getWindow()))))
		textMenu[1].setTexture(engine->getTexture(11));
	else textMenu[1].setTexture(engine->getTexture(10));
	for (auto& t: textMenu)
		engine->getWindow().draw(t);
}


mOPTIONS CInGameMenu::inputMenu(sf::Event& event) {
	if ((textMenu[0].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(engine->getWindow())))) && (event.type == sf::Event::MouseButtonReleased) && (event.key.code == sf::Mouse::Left))
		return mOPTIONS::BACK;
	else if ((textMenu[1].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(engine->getWindow())))) && (event.type == sf::Event::MouseButtonReleased) && (event.key.code == sf::Mouse::Left))
		return mOPTIONS::EXIT;
	else return mOPTIONS::STOP;

}
