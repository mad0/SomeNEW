#include "CPlayer.h"
#include "CGameEngine.h"


CPlayer::CPlayer(CGameEngine *_engine) : engine(_engine) {
	player.setTexture(engine->getTexture(22));
	
	player.setScale(2, 2);
	player.setPosition(795, 657);
	Idle();
}

CPlayer::~CPlayer() {
}

void CPlayer::playerInput(sf::Event & event) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		mLeft();
		player.move(-7, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		mRight();
		player.move(+7, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		mDown();
		player.move(0, +7);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		mUp();
		player.move(0, -7);
	}

	//if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
	//	mLeft();
	//	player.move(-10, 0);
	//}
		
	//if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
	//	mRight();
	//	player.move(+10, 0);
	//}
		
}

void CPlayer::playerUpdate() {
}

void CPlayer::playerDraw() {
	engine->getWindow().draw(player);
}

sf::Sprite & CPlayer::getPLayer() {
	return player;
}

void CPlayer::mLeft() {
	player.setTextureRect(sf::IntRect(112, 4, 27, 45));
}

void CPlayer::mRight() {
	player.setTextureRect(sf::IntRect(60, 4, 28, 45));
}

void CPlayer::mDown() {
	player.setTextureRect(sf::IntRect(9, 4, 38, 48));
}

void CPlayer::mUp() {
	player.setTextureRect(sf::IntRect(160, 4, 30, 45));
}

void CPlayer::Idle() {
	player.setTextureRect(sf::IntRect(9, 4, 38, 48));
}

