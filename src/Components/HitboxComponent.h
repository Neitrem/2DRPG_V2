#pragma once

#include <fstream>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <map>
#include <vector>

class HitboxComponent
{
private:
	sf::Sprite& sprite;
	sf::RectangleShape hitbox;

	float offsetX;
	float offsetY;

protected:
public:
	HitboxComponent(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height);
	virtual ~HitboxComponent();

	//Functions
	bool checkIntersect(const sf::FloatRect& f_rect);

	void update();
	void render(sf::RenderTarget& target);

};

