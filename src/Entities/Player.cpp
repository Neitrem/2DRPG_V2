#include "Player.h"

//Initializers functions
void Player::initVariables()
{
}

void Player::initComponents()
{
	
}

void Player::initAnimations()
{
	////Loading animations
	
	//IDLE
	this->animationComponent->addAnimation("IDLE_DOWN", 5.f, 0, 0, 4, 0, 48, 48, 0);
	this->animationComponent->addAnimation("IDLE_LEFT", 5.f, 0, 1, 4, 1, 48, 48, 0);
	this->animationComponent->addAnimation("IDLE_RIGHT", 5.f, 0, 2, 4, 2, 48, 48, 0);
	this->animationComponent->addAnimation("IDLE_UP", 5.f, 0, 3, 4, 3, 48, 48, 0);


	//MOVING
	this->animationComponent->addAnimation("WALK_DOWN", 1.5f, 0, 4, 7, 4, 48, 48, 0);
	this->animationComponent->addAnimation("WALK_LEFT", 2.5f, 0, 5, 7, 5, 48, 48, 0);
	this->animationComponent->addAnimation("WALK_RIGHT", 2.5f, 0, 6, 7, 6, 48, 48, 0);
	this->animationComponent->addAnimation("WALK_UP", 1.5f, 0, 7, 7, 7, 48, 48, 0);
}

//Constructors / Destructors
Player::Player(float width, float height, float x, float y, sf::Texture& texture_sheet)
{
	this->initVariables();
	
	//Configuring itself
	this->setPosition(x, y);
	this->setSize(width, height);

	//Components initialization
	this->createHitboxComponent(this->sprite, 30, 20, 35, 60);
	this->createMovementComponent(300.f, 12.f, 6.f);
	this->createAnimationComponent(texture_sheet);

	
	this->initAnimations();
}

Player::~Player()
{

}

//Functions
void Player::update(const float& dt)
{
	this->movementComponent->update(dt);

	if (this->movementComponent->getState(IDLE))
	{
		switch (this->movementComponent->getDirection())
		{
		case DOWN:
			this->animationComponent->play("IDLE_DOWN", dt);
			break;
		case UP:
			this->animationComponent->play("IDLE_UP", dt);
			break;
		case LEFT:
			this->animationComponent->play("IDLE_LEFT", dt);
			break;
		case RIGHT:
			this->animationComponent->play("IDLE_RIGHT", dt);
			break;
		default:
			break;
		}
	}
	else if (this->movementComponent->getState(MOVING_RIGHT))
		this->animationComponent->play(
			"WALK_RIGHT", dt,
			this->movementComponent->getVelocity().x
		);
	else if (this->movementComponent->getState(MOVING_LEFT))
		this->animationComponent->play(
			"WALK_LEFT", dt,
			this->movementComponent->getVelocity().x
		);
	else if (this->movementComponent->getState(MOVING_DOWN))
		this->animationComponent->play(
			"WALK_DOWN", dt,
			this->movementComponent->getVelocity().y
		);
	else if (this->movementComponent->getState(MOVING_UP))
		this->animationComponent->play(
			"WALK_UP", dt,
			this->movementComponent->getVelocity().y
		);

	this->hitboxComponent->update();

}
