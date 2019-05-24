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

void CStateMachine::addState(std::shared_ptr<CGameState> _state) {
	std::cout << "Scenes beffore add: " << mResources.size() << "\n";
	sceneID++;
	mResources.insert(std::make_pair(sceneID, _state));
	std::cout << "Scenes number: "<<mResources.size() << "\n";
	curentState = _state;
}

void CStateMachine::delState(int _stateID) {
	//std::map <int, std::shared_ptr<CGameState>>::iterator _temp;
	std::cout << "Deleter was runned.\n";
	//auto _temp = mResources.find(_stateID);
	mResources.erase(mResources.find(_stateID));
	//std::cout << typeid(mResources.find(_stateID)->second).name() << "\n";
	std::cout << "Scenes after delete: " << mResources.size() << "\n";
	curentState = nullptr;
}

void CStateMachine::switchState(int _stateID) {
	//auto _find = mResources.find(_stateID);
	//curentState = _find->second;
}

CGameState * CStateMachine::getState(int) {
	return nullptr;
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
