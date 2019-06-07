#pragma once
#include "CStateMachine.h"
#include "CResourceManager.h"

class CGameEngine {
private:
	sf::RenderWindow window;
	bool isRunning;
	CStateMachine stateMachine;
	CResourceManager<sf::Font> fontManager;
	CResourceManager<sf::Texture> textureResources;
public:
	CGameEngine();
	~CGameEngine();
	void GameLoop();
	sf::Texture& getTexture(int);
	sf::Font& getFont(int);
	std::shared_ptr<CGameState> getState(int);
	void addState(std::shared_ptr<CGameState>);
	sf::RenderWindow& getWindow();
};

