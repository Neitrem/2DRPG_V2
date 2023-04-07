#pragma once

#include "GameState.h"

class Game
{
private:
	//Variables
	sf::RenderWindow* window;
	sf::Event sfEvent;

	//Delta time
	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	//Initialization
	void initWindow();
	void initStates();

public:
	//Cunstructors/Destructors
	Game();
	virtual ~Game();

	//Functions

	//Regular
	void endApplication();

	//Update
	void updateDt();
	void updateSFMLEvents();
	void update();

	//Render
	void render();

	//Core
	void run();
	
	
};

