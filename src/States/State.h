#pragma once

#include "Entity.h"

class State
{
protected:
	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;
	bool quit;

	//Resources
	std::vector<sf::Texture> textures;

	//Functions
	virtual void initKeybinds() = 0; 
public:
	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	virtual ~State();

	const bool& getQuiut() const;

	virtual void cheeckForQuit();
	virtual void endState() = 0;

	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = NULL) = 0;
};

