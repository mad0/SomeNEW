#include <iostream>
#include <typeinfo>
#include "CGameEngine.h"
#include "CGameMenu.h"

CGameEngine::CGameEngine() : isRunning(true), stateMachine(), fontManager(), textureResources() {
	std::cout << "Class: Engine is starting...\n";
	window.create(sf::VideoMode(1920, 1080), "GameEngine v.001", sf::Style::Default);
	window.setFramerateLimit(60);
	fontManager.addResource(1, "fonts/lucon.ttf");
	fontManager.addResource(2, "fonts/CGA.ttf");
	textureResources.addResource(1, "images/bSmall.png");
	textureResources.addResource(2, "images/start1.png");
	textureResources.addResource(3, "images/start2.png");
	textureResources.addResource(4, "images/exit1.png");
	textureResources.addResource(5, "images/exit2.png");
	textureResources.addResource(6, "images/options1.png");
	textureResources.addResource(7, "images/options2.png");
	textureResources.addResource(8, "images/back1.png");
	textureResources.addResource(9, "images/exittomenu.png");
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

sf::Texture & CGameEngine::getTexture(int tInt) {
	return textureResources.getResource(tInt);
}

sf::Font & CGameEngine::getFont(int fInt) {
	return fontManager.getResource(fInt);
}

std::shared_ptr<CGameState> CGameEngine::getState(STATES sType) {
	return stateMachine.getState(sType);
}

void CGameEngine::delState(STATES sType) {
	stateMachine.delState(sType);
}

void CGameEngine::addState(STATES sType, std::shared_ptr<CGameState>_state) {
	stateMachine.addState(sType, _state);
}

sf::RenderWindow & CGameEngine::getWindow() {
	return window;
}

