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
	IDLE_DOWN,
	IDLE_LEFT,
	IDLE_RIGHT,
	IDLE_UP,
	MOVING,
	MOVING_DOWN,
	MOVING_LEFT,
	MOVING_RIGHT,
	MOVING_UP

};

class MovementComponent
{
private:
	sf::Sprite& sprite;

	float maxVelocity;
	float acceleration;
	float deceleration;

	sf::Vector2f velocity;

	//Initializers functions
protected:
public:
	//Constructors / Desctructors
	MovementComponent(sf::Sprite& sprite, float maxVelocity, float acceleration, float decelerartion);
	virtual ~MovementComponent();

	//Accessors
	const sf::Vector2f& getVelocity() const;


	//Functions
	const bool getState(const short unsigned state) const;


	void move(const float dir_x, const float dir_y, const float& dt);
	void update(const float& dt);
};

