#include "Player.h"

//Initializers functions
void Player::initVariables()
{
}

void Player::initComponents()
{
	
}

//Constructors / Destructors
Player::Player(float width, float height, float x, float y, sf::Texture& texture_sheet)
{
	this->initVariables();
	

	this->setPosition(x, y);
	this->setSize(width, height);

	this->createMovementComponent(300.f, 12.f, 6.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("IDLE_DOWN", 5.f, 0, 0, 4, 0, 48, 48);
	this->animationComponent->addAnimation("WALK_LEFT", 2.5f, 0, 5, 7, 5, 48, 48);
	this->animationComponent->addAnimation("WALK_RIGHT", 2.5f, 0, 6, 7, 6, 48, 48);

	this->initComponents();
}

Player::~Player()
{

}

//Functions
void Player::update(const float& dt)
{
	this->movementComponent->update(dt);

	/*if (this->movementComponent->idle())
		this->animationComponent->play("IDLE_DOWN", dt);
	else if(this->movementComponent->movingLeft())
		this->animationComponent->play("WALK_LEFT", dt);
	else if (this->movementComponent->movingRight())
		this->animationComponent->play("WALK_RIGHT", dt);*/

}
