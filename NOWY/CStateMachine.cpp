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
	std::cout << "Scenes beffore add: " << mResources.size() << "\n";
		//std::map<STATES, std::shared_ptr<CGameState>>::iterator itr;
		//itr = mResources.find(stateType);
		//if (itr == mResources.end()) {
			mResources.emplace(std::make_pair(stateType, _state));
			curentState = _state;
	//}
		//else {
		//	curentState = _state;
		//}
		
		//if (itr != mResources.end()) {
		//	curentState = _state;
			std::cout << "Scenes after added: " << mResources.size() << "\n";
		//}
	//}
}

void CStateMachine::changeState(STATES sType) {

	std::map<STATES, std::shared_ptr<CGameState>>::iterator itr;
	itr = mResources.find(sType);
	if (itr != mResources.end()){
			std::cout << itr->first << "\n";
			curentState = itr->second;
		}
}

std::shared_ptr<CGameState> CStateMachine::getState(STATES sType) {
	return nullptr;
}

void CStateMachine::delState(STATES sType) {
	std::map<STATES, std::shared_ptr<CGameState>>::iterator itr;
	std::cout << "Resources size before delete:" << mResources.size() << "\n";
	itr = mResources.find(sType);
	if (itr != mResources.end()) {
		curentState = mResources.at(STATES::MENU);
		mResources.erase(itr);
		std::cout << "Resources size after delete:" << mResources.size() << "\n";
	}
	
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
