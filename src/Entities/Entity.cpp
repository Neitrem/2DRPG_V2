#include "Entity.h"

void Entity::initVariables()
{
	this->movementComponent = NULL;
}

//Constructors / Destructors
Entity::Entity()
{
	this->initVariables();
}

Entity::~Entity()
{
	delete this->movementComponent;
}

//Components functions
void Entity::setTexture(sf::Texture& texture)
{
	this->sprite.setTexture(texture);
}

void Entity::createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration)
{
	this->movementComponent = new MovementComponent(this->sprite, maxVelocity, acceleration, deceleration);
}

//Functions
void Entity::setSize(const float width, const float height)
{
	this->sprite.setScale(width / this->sprite.getGlobalBounds().width, height / this->sprite.getGlobalBounds().height);
}

void Entity::setPosition(const float x, const float y)
{

	this->sprite.setPosition(x, y);
}

void Entity::move(const float dir_x, const float dir_y, const float& dt)
{
	if (this->movementComponent)
	{
		this->movementComponent->move(dir_x, dir_y, dt);//Sets velocity
	}
}

void Entity::update(const float& dt)
{
	if (this->movementComponent)
		this->movementComponent->update(dt);
}

void Entity::render(sf::RenderTarget* target)
{

	target->draw(this->sprite);
}
