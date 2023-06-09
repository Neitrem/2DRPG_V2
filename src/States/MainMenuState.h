#pragma once

#include "GameState.h"
#include "EditorState.h"

class MainMenuState :
    public State
{

private:
	//Variables
	sf::Texture bgTexture;
	sf::RectangleShape background;
	sf::Font font;

	std::map<std::string, Button*> buttons;

	//Functiuouns
	void initBackground();
	void initVariables();
	void initKeybinds();
	void initFonts();
	void initButtons();

public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~MainMenuState();

	//Functions
	void updateInput(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = NULL);
    
};

