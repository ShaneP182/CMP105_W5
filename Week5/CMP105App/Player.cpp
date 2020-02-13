#include "Player.h"

Player::Player()
{
	speed = 100;
	lookingRight = true;


	idle.addFrame(sf::IntRect(0, 0, 32, 32));
	idle.addFrame(sf::IntRect(32, 0, 32, 32));
	idle.addFrame(sf::IntRect(64, 0, 32, 32));
	idle.addFrame(sf::IntRect(96, 0, 32, 32));
	idle.addFrame(sf::IntRect(128, 0, 32, 32));
	idle.addFrame(sf::IntRect(160, 0, 32, 32));
	idle.setFrameSpeed(1.f);

	currentAnimation = &idle;
}

Player::~Player()
{

}

void Player::update(float dt)
{
	currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());
}

void Player::handleInput(float dt)
{

}