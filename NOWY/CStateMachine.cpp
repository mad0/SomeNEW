#include "CStateMachine.h"
#include <iostream>
#include "CGameState.h"
#include <typeinfo>

CStateMachine::CStateMachine() : mResources(), sceneID(), curentState() { 
	std::cout << "Class: stateMachine is starting...\n"; 
}


CStateMachine::~CStateMachine() { 
	std::cout << "Class: stateMachine is ending...\n"; 
}

void CStateMachine::addState(CGameState * _state) {
	sceneID++;
	mResources.insert(std::make_pair(sceneID, _state));
	std::cout << "Scenes number: "<<mResources.size() << "\n";
	curentState = _state;
}

void CStateMachine::delState(int _stateID) {
	auto _temp = mResources.find(_stateID);
	delete _temp->second;
	mResources.erase(1);

}

void CStateMachine::switchState(int _stateID) {
	auto _find = mResources.find(_stateID);
	curentState = _find->second;
}

CGameState * CStateMachine::getState(int) {
	return curentState;
}

void CStateMachine::input(sf::Event &_event) {
	curentState->input(_event);
}

void CStateMachine::draw(sf::RenderWindow &_window) {
	curentState->draw(_window);
}

void CStateMachine::update() {
	curentState->update();
}
