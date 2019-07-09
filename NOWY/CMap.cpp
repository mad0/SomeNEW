#include "CMap.h"
#include "CGameEngine.h"
#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

CMap::CMap(CGameEngine *_engine){
	engine = _engine;
	std::cout << "Initialize map...\n";
	

}

CMap::~CMap() {
}

void CMap::drawScene() {
	engine->getWindow().draw(sceneBG);
}

bool CMap::checkCollision(int x, int y, sf::Vector2f pPos) {
	sf::Vector2f nextPos(pPos.x + x, pPos.y + y);
		return true;
	//}
	//else return false;
}

void CMap::loadScene(std::string scene) {
	std::cout << "SCENE LOADING...\n";
	std::ifstream file("scenes/"+scene+".json");
	nlohmann::json j; 
	file >> j;
	std::cout << "scenes/" + scene + ".json" << "\n";
	engine->addTexture(j["bg"]["id"], j["bg"]["file"]);
	sceneBG.setTexture(engine->getTexture(j["bg"]["id"]));
	sceneBG.setScale(3, 3);
	file.close();
}

void CMap::changeScene(int)
{
}
