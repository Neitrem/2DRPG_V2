#include "MainMenuState.h"

void MainMenuState::initKeybinds()
{
	std::ifstream ifs("Config/gamestate_keybinds.ini");

	if (ifs.is_open())
	{
		std::string action = "";
		std::string key = "";
		while (ifs >> action >> key)
		{
			this->keybinds[action] = this->supportedKeys->at(key);
		}
	}

	ifs.close();
}

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("src/Fonts/ChivoMono-VariableFont_wght.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
	: State(window, supportedKeys)
{
	this->initFonts();
	this->initKeybinds();

	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::endState()
{
	std::cout << "Ending MainMenuState!" << std::endl;
}

void MainMenuState::updateInput(const float& dt)
{
	this->cheeckForQuit();

	
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

	system("cls");
	std::cout << this->mousePosView.x << " " << this->mousePosView.y << std::endl;
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
}
