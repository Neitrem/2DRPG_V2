#pragma once

#include <iostream>
#include <string>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class AnimationComponent
{
private:
	class Animation
	{
	public:
		//Variables
		sf::Sprite& sprite;
		sf::Texture& textureSheet;
		float animationTimer;
		float timer;
		int width;
		int height;
		std::string directionName;

		bool isDone;

		int priorityLevel;

		sf::IntRect startRect;
		sf::IntRect currentRect;
		sf::IntRect endRect;
		
		//Constructors / Destructors
		Animation(
			std::string directionName, sf::Sprite& sprite,
			sf::Texture& textureSheet, float speed,
			int start_x, int start_y, int end_x, int end_y,
			int width, int height, const int priority_level
		);

		//Functions
		void reset();

		bool play(const float& dt);
		bool play(const float& dt, float movement_speed);

	};


	sf::Sprite& sprite;
	sf::Texture& textureSheet;
	std::map<std::string, Animation*> animations;

	Animation* lastAnimation;
	Animation* currentAnimation;
protected:

public:
	//Constructors / Destructors
	AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet);
	virtual ~AnimationComponent();

	//Accessors
	std::string& getViewDirection();

	//Functions
	void addAnimation(
		const std::string key,
		float animation_timer,
		int start_frame_x, int start_frame_y, int frames_x, int frames_y,
		int width, int heigh, const int priority_level
	);

	void play(const std::string key, const float& dt);
	void play(const std::string key, const float& dt, const float& movement_speed);
};

