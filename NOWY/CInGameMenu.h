#pragma once
#include "CGameState.h"
#include "CResourceManager.h"

class CInGameMenu  {
private:
	sf::RectangleShape bBig;
	sf::RectangleShape bSmall;
	sf::Text textMenu[3];
public:
	CInGameMenu(CResourceManager<sf::Font>&);
	~CInGameMenu();
	void showMenu(sf::RenderWindow *);
	void update();
};

