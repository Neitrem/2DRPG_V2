#include "EditorState.h"

//Initialisers funtions
void EditorState::initBackground()
{
}

void EditorState::initVariables()
{
}

void EditorState::initKeybinds()
{
	std::ifstream ifs("Config/editorstate_keybind.ini");

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

void EditorState::initFonts()
{
	if (!this->font.loadFromFile("src/Fonts/ChivoMono-VariableFont_wght.ttf"))
	{
		throw("ERROR::EDITORSTATE::COULD NOT LOAD FONT");
	}
}

void EditorState::initButtons()
{

}

EditorState::EditorState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
}

EditorState::~EditorState()
{

	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

void EditorState::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE_STATE"))))
		this->endState();
}

void EditorState::updateButtons()
{
	/*Updates all buttons states and handle their functionality*/

	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

}

void EditorState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

	this->updateButtons();
}

void EditorState::renderButtons(sf::RenderTarget& target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void EditorState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

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
