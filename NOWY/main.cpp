//#include "vld.h"
#include <iostream>
#include "CGameEngine.h"
#include "CGameMenu.h"
#include "CPlayState.h"

int main() {
	CGameEngine engine;
	engine.addState(STATES::MENU, std::make_shared<CGameMenu>(&engine));
	engine.GameLoop();
return 0;
}