#include "GameState.h"

//Initialisers functiuouns
void GameState::initKeybinds()
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

void GameState::initTextures()
{
	if (!this->textures["PLAER_SHEET"].loadFromFile("src/Assets/Images/Entities/Player/PlayerSheet.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_SHEET_TEXTURE";
	}
}

void GameState::initPlayer()
{
	this->player = new Player(96, 96, 0, 0, this->textures["PLAER_SHEET"]);
}

//Constructors / Destructors
GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initKeybinds();
	this->initTextures();
	this->initPlayer();
}

GameState::~GameState()
{
	delete this->player;
}

void GameState::updateInput(const float& dt)
{
	//Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player->move(-1.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player->move(1.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
		this->player->move(0.f, -1.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		this->player->move(0.f, 1.f, dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE_STATE"))))
		this->endState();

}

//Functions
void GameState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	
	this->player->update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	this->player->render(*target);
}
