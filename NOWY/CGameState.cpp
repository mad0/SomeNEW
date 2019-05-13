#include "CGameState.h"
#include <iostream>

CGameState::CGameState() {
	font.loadFromFile("fonts/lucon.ttf");
	logObj.setPosition(sf::Vector2f(10, 700));
	logObj.setCharacterSize(13);
	std::cout << &logObj << "\n";
	logObj.setFont(font);
}

CGameState::~CGameState() {

}

void CGameState::showLog(const std::string& _log) {
	logObj.setString(_log);
}
