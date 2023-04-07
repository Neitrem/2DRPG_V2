#include "State.h"


State::State(sf::RenderWindow* window)
{
	this->window = window;
	this->quit = false;
}

State::~State()
{

}

const bool& State::getQuiut() const
{
	return this->quit;
}

void State::cheeckForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->quit = true;
	}
}
