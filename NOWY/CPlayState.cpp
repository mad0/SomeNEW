#include "CPlayState.h"
#include <iostream>

CPlayState::CPlayState(CResourceManager <sf::Font>& font){
	//showLog(typeid(dynamic_cast<CPlayState*>(engine->getState())).name());
	std::cout << "fontoooooooooooo address:"<<&font.getResource(2) << "\n";
	text.setFont(font.getResource(2));
	text.setString("DuPA2");
	std::cout << "Class: CPlayState is starting...\n";
}


CPlayState::~CPlayState(){
	std::cout << "Class: CPlayState is endinging...\n";
}

void CPlayState::input(sf::Event &) {
}

void CPlayState::update()
{
}

//void CPlayState::input(sf::Event &event) {
	//sf::Event event;
	//while (engine->window.pollEvent(event))
	//{
	//	if (event.type == sf::Event::Closed)
	//		engine->window.close();
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	//	engine->delState();
//}


void CPlayState::draw(sf::RenderWindow &window){
	window.clear();
	window.draw(text);
	window.display();
}
