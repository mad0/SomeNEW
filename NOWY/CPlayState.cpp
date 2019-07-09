#include "CPlayState.h"
#include <iostream>
#include "CGameEngine.h"

CPlayState::CPlayState(CGameEngine *_engine) : game(true), menuInGame(_engine) {
	engine = _engine;
	map = std::make_unique<CMap>(engine);
	player = std::make_unique<CPlayer>(engine);
	//showLog(typeid(dynamic_cast<CPlayState*>(engine->getState())).name());
	//std::cout << "fontoooooooooooo address:"<<&fontManager.getResource(2) << "\n";
	std::cout << "Class: CPlayState is starting...\n";
	map->loadScene("kitchen");
}


CPlayState::~CPlayState(){
	std::cout << "Class: CPlayState is endinging...\n";
}

void CPlayState::input() {
	sf::Event event;
	while (engine->getWindow().pollEvent(event)) {
		if (event.type == sf::Event::Closed)
					engine->getWindow().close();
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
			std::cout << "ESC in PLAY pressed....\n";
			if (game) game = false;
			 else game = true;
		}	
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::O) {
			
		}
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		//map.checkCollision
	}
	//if (!map.checkCollision(player->getPLayer()))
	//	player->playerInput(event);
	if (!game) {
		switch (menuInGame.inputMenu(event)) {
		case mOPTIONS::BACK:
			game = true;
			break;
		case mOPTIONS::OPTIONS:
			std::cout << "OPTIONS in MENU\n";
			break;
		case mOPTIONS::EXIT:
			engine->delState(STATES::PLAY);
			break;
		case mOPTIONS::STOP:
			game = false;
		}
	}
}

void CPlayState::update() {
	int z = 0;
	if (game) {
		std::cout << z << "\n";
	}
}

void CPlayState::draw(){
	engine->getWindow().clear(sf::Color(191, 206, 114, 255));
	map->drawScene();
	player->playerDraw();
	if (!game)
		menuInGame.showMenu();
	engine->getWindow().display();
}

