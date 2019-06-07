#pragma once
#include "CGameState.h"
#include "CResourceManager.h"

class CInGameMenu  {
private:
	sf::RectangleShape bBig;
	sf::RectangleShape bSmall;
	sf::Sprite textMenu[3];
	sf::RenderWindow *window;
public:
	CInGameMenu(CResourceManager<sf::Texture>*, sf::RenderWindow*);
	~CInGameMenu();
	void showMenu();
	bool inputMenu(sf::Event*, CStateMachine*);
};

