#include "Mario.h"

Mario::Mario()
{
	speed = 100;
	lookingRight = true;

	walk.addFrame(sf::IntRect(0, 0, 15, 21)); 
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.setFrameSpeed(0.25f);

	idle.addFrame(sf::IntRect(0, 41, 15, 21));
	idle.addFrame(sf::IntRect(16, 41, 15, 21));
	idle.setFrameSpeed(1.f);

	swim.addFrame(sf::IntRect(0, 21, 16, 20)); 
	swim.addFrame(sf::IntRect(16, 21, 16, 20)); 
	swim.addFrame(sf::IntRect(32, 21, 16, 20)); 
	swim.setFrameSpeed(0.25f);

	currentAnimation = &idle;
}

Mario::~Mario()
{

}

void Mario::update(float dt)
{
	currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());
}

void Mario::handleInput(float dt)
{

	if (input->isKeyDown(sf::Keyboard::D))
	{
		currentAnimation = &walk;
		currentAnimation->setFlipped(false);
		move(speed * dt, 0);
		lookingRight = true;
	}
	else if (input->isKeyDown(sf::Keyboard::A))
	{
		currentAnimation = &walk;
		currentAnimation->setFlipped(true);
		move(-speed * dt, 0);
		lookingRight = false;
	}
	else
	{
		currentAnimation = &idle;
		if (lookingRight)
		{
			currentAnimation->setFlipped(false);
		}
		else
		{
			currentAnimation->setFlipped(true);
		}
	}

	if (input->isKeyDown(sf::Keyboard::W))
	{
		currentAnimation = &swim;
		if (lookingRight)
		{
			currentAnimation->setFlipped(false);
		}
		else
		{
			currentAnimation->setFlipped(true);
		}
		move(0, -speed * dt);
	}
	else if (input->isKeyDown(sf::Keyboard::S))
	{
		currentAnimation = &swim;
		if (lookingRight)
		{
			currentAnimation->setFlipped(false);
		}
		else
		{
			currentAnimation->setFlipped(true);
		}
		move(0, speed * dt);
	}
}