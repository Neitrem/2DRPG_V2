#include "Game.h"

//Static functions

//Initialize functions

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");
}

//Cunstructors/Destructors
Game::Game()
{
	
}

Game::~Game()
{
	delete this->window;
}

//Functions
void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update()
{
}

void Game::render()
{

    window.clear();
    window.draw(shape);
    window.display();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}
