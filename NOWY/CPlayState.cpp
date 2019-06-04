#include "CPlayState.h"
#include <iostream>

CPlayState::CPlayState(CStateMachine * _stateMachine, CResourceManager <sf::Font>* font, sf::RenderWindow *_window) : game(true), menuInGame(*font) {
	window = _window;
	fontManager = font;
	stateMachine = _stateMachine;
	//showLog(typeid(dynamic_cast<CPlayState*>(engine->getState())).name());
	std::cout << "fontoooooooooooo address:"<<&fontManager->getResource(2) << "\n";
	text.setFont(fontManager->getResource(2));
	text.setString("IM IN GAME NOW!!!");
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
			if (game) game = false;
			 else game = true;
		}
	}
}

void CPlayState::update(){
	int z = 0;
	if (game) {
		std::cout << z << "\n";
	}
}

void CPlayState::draw(){
	
	window->clear();
	window->draw(text);
	if (!game)
		menuInGame.showMenu(window);
	window->display();
}

