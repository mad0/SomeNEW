#include "CPlayState.h"
#include <iostream>

CPlayState::CPlayState(CStateMachine * _stateMachine, 
						CResourceManager <sf::Texture>* _textureResources, 
						sf::RenderWindow *_window) 
		: game(true), menuInGame(_textureResources, _window) {
	window = _window;
	textureResources = _textureResources;
	window = _window;
	stateMachine = _stateMachine;
	//showLog(typeid(dynamic_cast<CPlayState*>(engine->getState())).name());
	//std::cout << "fontoooooooooooo address:"<<&fontManager.getResource(2) << "\n";
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
			if (game) {
				game = false;
			}
			 else game = true;
		}
		if (!game)
			if (menuInGame.inputMenu(&event, stateMachine))
				stateMachine->changeState(0);
	}
}

void CPlayState::update(){
	int z = 0;
	if (game) {
		//std::cout << z << "\n";
	}
}

void CPlayState::draw(){
	window->clear(sf::Color(191, 206, 114, 255));
	if (!game)
		menuInGame.showMenu();
	window->display();
}

