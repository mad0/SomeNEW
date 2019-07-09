#pragma once
#include "SFML/Graphics.hpp"

class CGameEngine;
enum SCENES {ROOM1, ROOM2};
class CMap {
private:
	CGameEngine *engine;
	sf::Sprite sceneBG;
	//std::unique_ptr<sf::Sprite> sceneBG;
public:
	CMap(CGameEngine*);
	~CMap();
	void loadScene(std::string);
	void changeScene(int);
	bool checkCollision(int, int, sf::Vector2f);
	void drawScene();
};

