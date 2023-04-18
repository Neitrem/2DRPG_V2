#include "AnimationComponent.h"

//Constructors / Destructors
AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet)
	: sprite(sprite), textureSheet(texture_sheet), lastAnimation(NULL)
{

}

AnimationComponent::~AnimationComponent()
{
	for (auto& i : this->animations)
	{
		delete i.second;
	}
}


//Function

void AnimationComponent::addAnimation(const std::string key,
	float animation_timer,
	int start_frame_x, int start_frame_y, int frames_x, int frames_y, int width, int heigh)
{
	this->animations[key] = new Animation(
		this->sprite, this->textureSheet,
		animation_timer,
		start_frame_x, start_frame_y, frames_x, frames_y, width, heigh
	);
}

void AnimationComponent::play(const std::string key, const float& dt)
{
	if (this->lastAnimation != this->animations[key])
	{
		if (this->lastAnimation == NULL)
		{
			this->lastAnimation = this->animations[key];
		}
		else
		{
			this->lastAnimation->reset();
			this->lastAnimation = this->animations[key];
		}
		
	}

	this->animations[key]->play(dt);
}


//Animation

//Cunstructor
AnimationComponent::Animation::Animation(sf::Sprite& sprite, sf::Texture& texture_sheet,
	float animation_timer,
	int start_frame_x, int start_frame_y, int frames_x, int frames_y, int width, int height)
	: sprite(sprite), textureSheet(texture_sheet),
	animationTimer(animation_timer),
	width(width), height(height)
{
	this->timer = 0.f;
	this->startRect = sf::IntRect(start_frame_x * width, start_frame_y * height, width, height);
	this->currentRect = this->startRect;
	this->endRect = sf::IntRect(frames_x * width, frames_y * height, width, height);

	this->sprite.setTexture(this->textureSheet, true);
	this->sprite.setTextureRect(this->startRect);
}

//Functions
void AnimationComponent::Animation::reset()
{
	this->timer = 0.f;
	this->currentRect = this->startRect;
}

void AnimationComponent::Animation::play(const float& dt)
{
	//Update timer
	this->timer += 30.f * dt;
	if (this->timer >= this->animationTimer)
	{  
		//Reset timer
		this->timer = 0.f;

		//Animate
		if (this->currentRect != this->endRect)
		{
			this->currentRect.left += this->width;
		}
		else // Reset
		{
			this->currentRect = this->startRect;
		}

		this->sprite.setTextureRect(this->currentRect);
	}
}