#pragma once

#include "State.h"

class GameState : public State
{
private:
	Player* player;

	//Initialisers functiuouns
	void initKeybinds();
	void initTextures();
	void initPlayer();

public:
	//Constructors / Destructors
	GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	~GameState();

	//Functions
	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = NULL);
};

