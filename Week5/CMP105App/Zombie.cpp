#include "Zombie.h"
Zombie::Zombie()
{
	speed = 100;
	lookingRight = true;

	walk.addFrame(sf::IntRect(0, 0, 55, 108)); 
	walk.addFrame(sf::IntRect(55, 0, 55, 108)); 
	walk.addFrame(sf::IntRect(110, 0, 55, 108)); 
	walk.addFrame(sf::IntRect(165, 0, 55, 108)); 
	walk.addFrame(sf::IntRect(220, 0, 55, 108)); 
	walk.addFrame(sf::IntRect(275, 0, 55, 108)); 
	walk.addFrame(sf::IntRect(330, 0, 55, 108)); 
	walk.addFrame(sf::IntRect(385, 0, 55, 108)); 
	walk.setFrameSpeed(0.1f);

	idle.addFrame(sf::IntRect(385, 0, 55, 108));
	idle.setFrameSpeed(0.1f);

	currentAnimation = &idle;
}

Zombie::~Zombie()
{

}

void Zombie::update(float dt)
{
	currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());
}

void Zombie::handleInput(float dt)
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
}
