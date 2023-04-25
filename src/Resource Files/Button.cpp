#include "Button.h"

Button::Button(float x, float y, float width, float height,
	sf::Font* font, std::string text, unsigned character_size,
	sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
	sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
	this->buttonsState = BTN_IDLE;

	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	this->shape.setFillColor(idleColor);

	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(text_idle_color);
	this->text.setCharacterSize(character_size);

	this->text.setOrigin(
		this->text.getLocalBounds().left + this->text.getLocalBounds().width / 2.f,
		this->text.getLocalBounds().top + this->text.getLocalBounds().height / 2.f
	);

	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f),
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f)
	);

	this->textiIdleColor = text_idle_color;
	this->textHoverColor = text_hover_color;
	this->textActiveColor = text_active_color;

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;
}

Button::~Button()
{
	
}

//Accessors
const bool Button::isPressed() const
{
	if (this->buttonsState == BTN_ACTIVE)
		return  true;

	return false;
}

//Functions
void Button::update(const sf::Vector2f mousePos)
{
	/*Update states for buton*/

	//Idle
	this->buttonsState = BTN_IDLE;

	//Hover
	if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->buttonsState = BTN_HOVER;
		
		//Active
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonsState = BTN_ACTIVE;
		}
	}

	switch (this->buttonsState)
	{
	case BTN_IDLE:
		this->shape.setFillColor(this->idleColor);
		this->text.setFillColor(this->textiIdleColor);
		break;

	case BTN_HOVER:
		this->shape.setFillColor(this->hoverColor);
		this->text.setFillColor(this->textHoverColor);
		break;

	case BTN_ACTIVE:
		this->shape.setFillColor(this->activeColor);
		this->text.setFillColor(this->textActiveColor);
		break;

	default:
		this->shape.setFillColor(sf::Color::Red);
		this->text.setFillColor(sf::Color::Blue);
		break;
	}
}

void Button::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
	target.draw(this->text);
}
