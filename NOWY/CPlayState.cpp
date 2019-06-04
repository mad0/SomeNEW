#include "CPlayState.h"
#include <iostream>

CPlayState::CPlayState(CStateMachine * _stateMachine, CResourceManager <sf::Font>* font, sf::RenderWindow *_window){
	window = _window;
	fontManager = font;
	stateMachine = _stateMachine;
	//showLog(typeid(dynamic_cast<CPlayState*>(engine->getState())).name());
	std::cout << "fontoooooooooooo address:"<<&fontManager->getResource(2) << "\n";
	text.setFont(fontManager->getResource(2));
	text.setString("PLAY");
	std::cout << "Class: CPlayState is starting...\n";
}

CPlayState::~CPlayState(){
	std::cout << "Class: CPlayState is endinging...\n";
}

void CPlayState::input() {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed)
					window->close();
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
			std::cout << "ESC in PLAY pressed....\n";
			stateMachine->changeState(1);
		}
	}
	
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


void CPlayState::draw(){
	window->clear();
	window->draw(text);
	window->display();
}
