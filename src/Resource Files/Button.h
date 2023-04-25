#pragma once



#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>

enum button_states {
	BTN_IDLE     = 0,
	BTN_HOVER,
	BTN_ACTIVE

};

class Button
{
private:
	short unsigned buttonsState;

	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color textiIdleColor;
	sf::Color textHoverColor;
	sf::Color textActiveColor;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

public:
	Button(float x, float y, float width, float height,
		sf::Font* font, std::string text, unsigned character_size,
		sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	virtual ~Button();

	//Accessors
	const bool isPressed() const;

	//Functions
	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget& target);
};

