#include "GameState.h"

GameState::GameState(sf::RenderWindow* window) : State(window)
{

}

GameState::~GameState()
{

}



void GameState::endState()
{
	std::cout << "GameState ends!" << std::endl;
}

void GameState::updateKeyBinds(const float& dt)
{
	this->cheeckForQuit();
}

//Functions
void GameState::update(const float& dt)
{
	this->updateKeyBinds(dt);
	
	this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
	this->player.render(this->window);
}
