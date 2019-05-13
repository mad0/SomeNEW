#include "CGameEngine.h"
#include "CGameMenu.h"
#include <iostream>

int main() {
	CGameEngine engine;
	engine.addState(new CGameMenu(&engine));
	engine.GameLoop();
return 0;
}