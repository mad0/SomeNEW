#include "CGameEngine.h"
#include "CGameMenu.h"
#include <iostream>
#include "CGameState.h"
#include <typeinfo>

CGameEngine::CGameEngine() : isRunning(true){
	std::cout << "Class: Engine is starting...\n";
	window.create(sf::VideoMode(1280, 720), "GameEngine v.001");
	window.setFramerateLimit(60);
	stateMachine.addState(new CGameMenu(fontManager));
}

CGameEngine::~CGameEngine(){
	std::cout << "Class: Engine is ending...\n";
	//usuwa ostatni wskaznik ze stosu
	//std::cout << &(*getState()) << "\n";
	stateMachine.delState(1);
}


void CGameEngine::GameLoop(){
		while (window.isOpen()) {
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					window.close();
				stateMachine.input(event);
			}	
			stateMachine.update();
			stateMachine.draw(window);
		}
}

