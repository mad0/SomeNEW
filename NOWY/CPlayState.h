#pragma once
#include "CGameState.h"
#include "CResourceManager.h"
#include "SFML/Graphics.hpp"

class CPlayState : public CGameState {
public:
	CPlayState(CResourceManager <sf::Font>&);
	~CPlayState();
	void input(sf::Event &);
	void update();
	void draw(sf::RenderWindow &);
private:
	sf::Text text;
};

