#pragma once
#include <SFML/Graphics.hpp>

class CGameEngine;

class CPlayer {
private:
	void mLeft();
	void mRight();
	void mDown();
	void mUp();
	void Idle();
	sf::Sprite player;
	CGameEngine *engine;
public:
	CPlayer(CGameEngine *);
	~CPlayer();
	void playerInput(sf::Event&);
	void playerUpdate();
	void playerDraw();
	sf::Sprite& getPLayer();
};

