#include <iostream>
#include "CGameEngine.h"
#include "CGameMenu.h"
#include <iostream>

int main() {
	CGameMenu menu;
	CGameEngine engine(&menu);
	engine.GameLoop();
	return 0;
}