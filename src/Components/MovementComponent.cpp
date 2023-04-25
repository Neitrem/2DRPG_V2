#include "MovementComponent.h"


//Constructors / Desctructors
MovementComponent::MovementComponent(sf::Sprite& sprite,
	float maxVelocity, float acceleration, float deceleration)
	: sprite(sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration)
{
	this->maxVelocity = maxVelocity;
	this->direction = DOWN;
}

MovementComponent::~MovementComponent()
{

}

//Accessors
const sf::Vector2f& MovementComponent::getVelocity() const
{
	return this->velocity;
}

const float& MovementComponent::getMaxVelocity() const
{
	return this->maxVelocity;
}

//Functions
const bool MovementComponent::getState(const short unsigned state)
{
	switch (state)
	{
	case IDLE:
		if (this->velocity.x == 0 && this->velocity.y == 0)
			return true;
		return false;
		break;
	case MOVING:
		if (this->velocity.x != 0 && this->velocity.y != 0)
			return true;
		return false;
		break;
	case MOVING_DOWN:
		if (this->velocity.y > 0)
		{
			this->direction = DOWN;
			return true;
		}
			
		return false;
		break;
	case MOVING_LEFT:
		if (this->velocity.x < 0)
		{
			this->direction = LEFT;
			return true;
		}
			
		return false;
		break;
	case MOVING_RIGHT:
		if (this->velocity.x > 0)
		{
			this->direction = RIGHT;
			return true;
		}
			
		return false;
		break;
	case MOVING_UP:
		if (this->velocity.y < 0)
		{
			this->direction = UP;
			return true;
		}
			
		return false;
		break;
	default:
		break;
	}
}

const int MovementComponent::getDirection()
{
	return this->direction;
}

void MovementComponent::move(const float dir_x, const float dir_y, const float& dt)
{
	//Acceleration
	this->velocity.x += this->acceleration * dir_x;	

	this->velocity.y += this->acceleration * dir_y;
}

void MovementComponent::update(const float& dt)
{
	//Deceleration and max velocity check

	//X
	if (this->velocity.x > 0.f) //Check for positive x
	{
		//Max velocity check
		if (this->velocity.x > this->maxVelocity)
			this->velocity.x = this->maxVelocity;

		//Deceleration
		this->velocity.x -= deceleration;
		if (this->velocity.x < 0.f)
			this->velocity.x = 0.f;
	}
	else if (this->velocity.x < 0.f) //Check for negative x
	{
		//Max velocity check
		if (this->velocity.x < -this->maxVelocity)
			this->velocity.x = -this->maxVelocity;

		//Deceleraion
		this->velocity.x += deceleration;
		if (this->velocity.x > 0.f)
			this->velocity.x = 0.f;
	}

	//Y
	if (this->velocity.y > 0.f) //Check for positive y
	{
		//Max velocity check
		if (this->velocity.y > this->maxVelocity)
			this->velocity.y = this->maxVelocity;

		//Deceleration
		this->velocity.y -= deceleration;
		if (this->velocity.y < 0.f)
			this->velocity.y = 0.f;
	}
	else if (this->velocity.y < 0.f) //Check for negative y
	{
		//Max velocity check
		if (this->velocity.y < -this->maxVelocity)
			this->velocity.y = -this->maxVelocity;

		//Deceleraion
		this->velocity.y += deceleration;
		if (this->velocity.y > 0.f)
			this->velocity.y = 0.f;
	}

	//Final move

	this->sprite.move(this->velocity * dt);
}
