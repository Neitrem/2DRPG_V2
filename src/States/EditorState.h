#pragma once
#include "State.h"


class EditorState :
    public State
{
private:
	//Variables
	sf::Font font;

	std::map<std::string, Button*> buttons;

	//Functiuouns
	void initBackground();
	void initVariables();
	void initKeybinds();
	void initFonts();
	void initButtons();

public:
	EditorState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~EditorState();

	//Functions
	void updateInput(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = NULL);
};

