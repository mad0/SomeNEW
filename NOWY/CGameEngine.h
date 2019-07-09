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
	std::shared_ptr<CGameState> getState(STATES);
	void delState(STATES);
	void addState(STATES, std::shared_ptr<CGameState>);
	void addTexture(int, const std::string&);

	sf::RenderWindow& getWindow();
};

