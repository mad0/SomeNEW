#include <iostream>
#include <typeinfo>
#include "CGameEngine.h"
#include "CGameMenu.h"

CGameEngine::CGameEngine() : isRunning(true){
	std::cout << "Class: Engine is starting...\n";
	window.create(sf::VideoMode(1280, 720), "GameEngine v.001");
	window.setFramerateLimit(60);
	stateMachine.addState(std::make_shared<CGameMenu>(&stateMachine, &window, &fontManager ));
}

CGameEngine::~CGameEngine(){
	std::cout << "Class: Engine is ending...\n";
}


void CGameEngine::GameLoop(){
		while (window.isOpen()) {
				stateMachine.input();
				stateMachine.update();
				stateMachine.draw();
		}
}

