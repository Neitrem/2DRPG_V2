#include "Player.h"

//Initializers functions
void Player::initVariables()
{
	this->isAtacking = false;
	this->weapon = new Weapon(&this->isAtacking);
}

void Player::initComponents()
{
	
}

void Player::initAnimations()
{
	////Loading animations
	
	//IDLE
	this->animationComponent->addAnimation("IDLE_DOWN", std::vector<Job> {}, 5.f, 0, 0, 4, 0, 48, 48, 0);
	this->animationComponent->addAnimation("IDLE_LEFT", std::vector<Job> {}, 5.f, 0, 1, 4, 1, 48, 48, 0);
	this->animationComponent->addAnimation("IDLE_RIGHT", std::vector<Job> {}, 5.f, 0, 2, 4, 2, 48, 48, 0);
	this->animationComponent->addAnimation("IDLE_UP", std::vector<Job> {}, 5.f, 0, 3, 4, 3, 48, 48, 0);


	//MOVING
	this->animationComponent->addAnimation("WALK_DOWN", std::vector<Job> {}, 1.5f, 0, 4, 7, 4, 48, 48, 0);
	this->animationComponent->addAnimation("WALK_LEFT", std::vector<Job> {}, 2.5f, 0, 5, 7, 5, 48, 48, 0);
	this->animationComponent->addAnimation("WALK_RIGHT", std::vector<Job> {}, 2.5f, 0, 6, 7, 6, 48, 48, 0);
	this->animationComponent->addAnimation("WALK_UP", std::vector<Job> {}, 1.5f, 0, 7, 7, 7, 48, 48, 0);


	//ATACKING
	this->animationComponent->addAnimation("ATACK_DOWN",
		std::vector<Job>
		{
			Job(START_JOB, NULL),
			Job(PROCESS_JOB, NULL),
			Job(PROCESS_JOB, NULL),
			Job(PROCESS_JOB, NULL),
			Job(PROCESS_JOB, NULL),
			Job(CLEARING_JOB, this->weapon)
		},
		5.f, 0, 8, 5, 8, 48, 48, 1);
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
	delete this->weapon;
}

//Functions
void Player::update(const float& dt)
{
	this->movementComponent->update(dt);
	this->hitboxComponent->update();
	this->updateAnimations(dt);

}

void Player::updateAnimations(const float& dt)
{
	if (this->isAtacking)
	{
		this->animationComponent->play("ATACK_DOWN", dt);
	}
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
}

void Player::startAtack()
{
	if (!this->isAtacking)
		this->isAtacking = true;
}

void Player::endAtack()
{
	if (this->isAtacking)
		this->isAtacking = false;
}

void Player::move(const float dir_x, const float dir_y, const float& dt)
{
	if (this->movementComponent)
	{
		if(!this->isAtacking)
			this->movementComponent->move(dir_x, dir_y, dt);//Sets velocity
	}
}
