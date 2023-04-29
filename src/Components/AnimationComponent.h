#pragma once

#include <iostream>
#include <string>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Weapon.h"
#include "Job.h"

class AnimationComponent
{
private:
	class Animation
	{
	private:
	public:
		//Variables

		// Spite and texture stuff
		sf::Sprite& sprite;
		sf::Texture& textureSheet;

		// Animation time stuff
		float animationTimer;
		float timer;

		// Size of picture
		int width;
		int height;
		
		// State variables
		bool isDone;
		int priorityLevel;
		std::string directionName;
		std::vector<Job> animationJobs;

		// Frames positions
		sf::IntRect startRect;
		sf::IntRect currentRect;
		sf::IntRect endRect;
		
		// Constructors / Destructors
		Animation(
			std::string directionName, sf::Sprite& sprite,
			sf::Texture& textureSheet, std::vector<Job> animation_jobs,
			float speed, int start_x, int start_y, int end_x, int end_y,
			int width, int height, int priority_level
		);

		//Functions
		void reset();

		bool play(const float& dt);
		bool play(const float& dt, float movement_speed);

	};


	sf::Sprite& sprite;
	sf::Texture& textureSheet;
	std::map<std::string, Animation*> animations;

	//Animation* lastAnimation; // Deprecated for now, not sure if it will be used
	Animation* currentAnimation;
protected:

public:
	// Constructors / Destructors
	AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet);
	virtual ~AnimationComponent();

	// Accessors
	std::string& getViewDirection();

	// Functions
	void addAnimation(
		const std::string key, std::vector<Job> animation_jobs,
		float animation_timer,
		int start_frame_x, int start_frame_y, int frames_x, int frames_y,
		int width, int heigh, int priority_level
	);

	void play(const std::string key, const float& dt);
	void play(const std::string key, const float& dt, const float& movement_speed);
};

