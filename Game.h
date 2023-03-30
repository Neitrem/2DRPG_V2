#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <cstdlib>
#include <ctime>

class Game
{
private:
	//Variables
	sf::RenderWindow* window;
	sf::Event sfEvent;

	//Initialization
	void initWindow();

public:
	//Cunstructors/Destructors
	Game();
	virtual ~Game();

	//Functions
	void updateSFMLEvents();
	void update();
	void render();
	void run();
};

