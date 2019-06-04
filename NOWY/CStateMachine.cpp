#include <iostream>
#include <typeinfo>
#include "CStateMachine.h"
#include "CGameState.h"


CStateMachine::CStateMachine() : mResources(), curentState() { 
	std::cout << "Class: stateMachine is starting...\n"; 
}


CStateMachine::~CStateMachine() { 
	std::cout << "Class: stateMachine is ending...\n"; 
}

void CStateMachine::addState(std::shared_ptr<CGameState> _state) {
	std::cout << "Scenes beffore add: " << mResources.size() << "\n";
	mResources.emplace_back( _state);
	std::cout << "Scenes number: "<<mResources.size() << "\n";
	curentState = _state;
}

void CStateMachine::changeState(int _stateID) {
	curentState = mResources[_stateID - 1];
}


std::shared_ptr<CGameState> CStateMachine::getState(int) const {
	return nullptr;
}

void CStateMachine::input() {
	curentState->input();
}

void CStateMachine::draw() {
	curentState->draw();
}

void CStateMachine::update() {
	curentState->update();
}
