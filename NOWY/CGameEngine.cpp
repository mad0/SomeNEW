#include <iostream>
#include <typeinfo>
#include "CGameEngine.h"
#include "CGameMenu.h"

CGameEngine::CGameEngine() : isRunning(true){
	std::cout << "Class: Engine is starting...\n";
	window.create(sf::VideoMode(1280, 720), "GameEngine v.001", sf::Style::Default);
	window.setFramerateLimit(60);
	fontManager.addResource(1, "fonts/lucon.ttf");
	fontManager.addResource(2, "fonts/CGA.ttf");
	stateMachine.addState(std::make_shared<CGameMenu>(&stateMachine, &window, &fontManager ));
}

CGameEngine::~CGameEngine(){
	std::cout << "Class: Engine is ending...\n";
}


void CGameEngine::GameLoop() {
	while (window.isOpen()) {
		stateMachine.input();
		stateMachine.update();
		stateMachine.draw();
	}
}

