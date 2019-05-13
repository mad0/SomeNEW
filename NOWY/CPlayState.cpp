#include "CPlayState.h"
#include <iostream>

CPlayState::CPlayState(CGameEngine *_engine){
	
	this->engine = _engine;
	showLog(typeid(dynamic_cast<CPlayState*>(engine->getState())).name());
}


CPlayState::~CPlayState(){
	std::cout << "Zniszczylem PlayState\n";
}

void CPlayState::input() {
	sf::Event event;
	while (engine->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			engine->window.close();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		engine->delState();
}

void CPlayState::update(){
}

void CPlayState::draw(){
	engine->window.clear();
	engine->window.draw(logObj);
	engine->window.display();
}
