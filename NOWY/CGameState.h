#pragma once
#include "CGameEngine.h"
#include <SFML/Graphics.hpp>

class CGameState {
private:
	sf::Font font;
public:
	CGameState();
	virtual void input() =0;
	virtual void draw() = 0;
	virtual void update() = 0;
	void showLog(const std::string&);
	virtual ~CGameState() = 0;
protected:
	CGameEngine *engine;
	sf::Text logObj;
};

