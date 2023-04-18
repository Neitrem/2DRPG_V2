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

		sf::IntRect startRect;
		sf::IntRect currentRect;
		sf::IntRect endRect;
		
		//Constructors / Destructors
		Animation(sf::Sprite& sprite, sf::Texture& textureSheet, float speed, int start_x, int start_y, int end_x, int end_y, int width, int height);

		//Functions
		void reset();

		void play(const float& dt);

	};


	sf::Sprite& sprite;
	sf::Texture& textureSheet;
	std::map<std::string, Animation*> animations;
	Animation* lastAnimation;
protected:

public:
	//Constructors / Destructors
	AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet);
	virtual ~AnimationComponent();

	//Functions
	void addAnimation(const std::string key,
		float animation_timer,
		int start_frame_x, int start_frame_y, int frames_x, int frames_y, int width, int heigh);

	void play(const std::string key, const float& dt);
};

