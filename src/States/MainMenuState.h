#pragma once

#include "GameState.h"
#include "Button.h"

class MainMenuState :
    public State
{

private:
	//Variables
	sf::RectangleShape background;
	sf::Font font;

	//Functiuouns

	void initKeybinds();
	void initFonts();

public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	virtual ~MainMenuState();

	//Functions

	void endState();
	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = NULL);
    
};

