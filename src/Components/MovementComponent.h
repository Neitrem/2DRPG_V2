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

enum movement_state {
	IDLE = 0,
	MOVING,
	MOVING_DOWN,
	MOVING_LEFT,
	MOVING_RIGHT,
	MOVING_UP
};

enum moving_direction {
	LEFT = 0,
	RIGHT,
	UP,
	DOWN
};

class MovementComponent
{
private:
	sf::Sprite& sprite;

	float maxVelocity;
	float acceleration;
	float deceleration;

	int direction;

	sf::Vector2f velocity;

	//Initializers functions
protected:
public:
	//Constructors / Desctructors
	MovementComponent(sf::Sprite& sprite, float maxVelocity, float acceleration, float decelerartion);
	virtual ~MovementComponent();

	//Accessors
	const sf::Vector2f& getVelocity() const;
	const float& getMaxVelocity() const;


	//Functions
	const bool getState(const short unsigned state);
	const int getDirection();


	void move(const float dir_x, const float dir_y, const float& dt);
	void update(const float& dt);
};

