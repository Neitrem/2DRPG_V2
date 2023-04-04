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
	void updateSFMLEvents();
	void update();
	void render();
	void run();
	void updateDt();
	
};

