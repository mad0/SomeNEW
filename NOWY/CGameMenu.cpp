#include "CGameMenu.h"
#include <iostream>


CGameMenu::CGameMenu()
{
	std::cout << "Create: GAME MENU STATE\n";
}


CGameMenu::~CGameMenu()
{
	std::cout << "Destruct: GAME MENU STATE\n";
}

void CGameMenu::input()
{
	
}

void CGameMenu::update()
{
	std::cout << "UPDATE\n";
}

void CGameMenu::draw()
{
	std::cout << "DRAW\n";
}
