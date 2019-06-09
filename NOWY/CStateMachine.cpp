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

void CStateMachine::addState(STATES stateType, std::shared_ptr<CGameState> _state) {
	//std::cout << typeid(_state).name() << "\n";
	std::cout << "Scenes beffore add: " << mResources.size() << "\n";
	mResources.insert(std::make_pair(stateType, _state));
	std::cout << "Scenes after added: " << mResources.size() << "\n";
	curentState = _state;
}

void CStateMachine::changeState(STATES sType) {
	for (auto itr = mResources.find(sType); itr != mResources.end(); itr++)
		curentState= itr->second;
}

std::shared_ptr<CGameState> CStateMachine::getState(STATES sType) {
	return nullptr;
}

void CStateMachine::delState(){
	std::cout << "Resources size before delete:" << mResources.size() << "\n";
	//mResources.pop_back();
	std::cout <<"Resources size after delete:"<< mResources.size() << "\n";
	//curentState = mResources.back();
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
