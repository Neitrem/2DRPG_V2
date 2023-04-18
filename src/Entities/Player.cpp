#include "Player.h"

//Initializers functions
void Player::initVariables()
{
}

void Player::initComponents()
{
	this->createMovementComponent(300.f, 12.f, 6.f);
}

//Constructors / Destructors
Player::Player(float width, float height, float x, float y, sf::Texture& texture)
{
	this->initVariables();
	this->initComponents();

	this->setTexture(texture);
	this->setPosition(x, y);
	this->setSize(width, height);
}

Player::~Player()
{

}
