#include "MainMenuState.h"

//Initialisers funtions
void MainMenuState::initBackground()
{
	this->background.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));

	if (!this->bgTexture.loadFromFile("src/Assets/Images/Backgrounds/mainmenu.png"))
	{
		throw("ERROR::MAINMENUSTATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE");
	}

	this->background.setTexture(&this->bgTexture);
}

void MainMenuState::initVariables()
{
}

void MainMenuState::initKeybinds()
{
	std::ifstream ifs("Config/mainmenustate_keybind.ini");

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

void MainMenuState::initButtons()
{
	this->buttons["RUN_GAME"] = new Button(100, 200, 180, 60,
		&this->font, "Start Game", 25,
		sf::Color(255, 255, 255, 200), sf::Color(160, 160, 160, 250), sf::Color(58,58, 58, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));

	this->buttons["SETTINGS"] = new Button(100, 300, 180, 60,
		&this->font, "Settings", 25,
		sf::Color(255, 255, 255, 200), sf::Color(160, 160, 160, 250), sf::Color(58, 58, 58, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));

	this->buttons["RUN_EDITOR"] = new Button(100, 400, 180, 60,
		&this->font, "Run Editor", 25,
		sf::Color(255, 255, 255, 200), sf::Color(160, 160, 160, 250), sf::Color(58, 58, 58, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));

	this->buttons["EXIT_STATE"] = new Button(100, 500, 180, 60,
		&this->font, "Quit", 25,
		sf::Color(255, 255, 255, 200), sf::Color(160, 160, 160, 250), sf::Color(58, 58, 58, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
}

MainMenuState::~MainMenuState()
{
	
	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

void MainMenuState::updateInput(const float& dt)
{
	
}

void MainMenuState::updateButtons()
{
	/*Updates all buttons states and handle their functionality*/

	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	//Quit the game
	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		this->endState();
	}

	//Run game
	if (this->buttons["RUN_GAME"]->isPressed())
	{
		this->states->push(new GameState(this->window, this->supportedKeys, this->states));
	}

	//Settings
	if (this->buttons["SETTINGS"]->isPressed())
	{
		//this->states->push(new GameState(this->window, this->supportedKeys, this->states));
	}

	if (this->buttons["RUN_EDITOR"]->isPressed())
	{
		this->states->push(new EditorState(this->window, this->supportedKeys, this->states));
	}
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

	this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget& target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);

	this->renderButtons(*target);

	//REMOVE LATER
	/*sf::Text mouseText;
	
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(12);
	std::stringstream ss;
	ss << this->mousePosView.x << " " << this->mousePosView.y << std::endl;
	mouseText.setString(ss.str());
	mouseText.setPosition(this->mousePosView.x - mouseText.getGlobalBounds().width, this->mousePosView.y - mouseText.getGlobalBounds().height);
	target->draw(mouseText);*/
}
