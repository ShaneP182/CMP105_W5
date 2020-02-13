#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	zombieTexture.loadFromFile("gfx/animZombie.png");
	marioTexture.loadFromFile("gfx/MarioSheetT.png");
	custom.loadFromFile("gfx/CustomSheet.png");

	jombie.setTexture(&zombieTexture);
	jombie.setPosition(0, 300);
	jombie.setSize(sf::Vector2f(55, 108));
	jombie.setInput(input);

	shmario.setTexture(&marioTexture);
	shmario.setPosition(0, 500);
	shmario.setSize(sf::Vector2f(100,100));
	shmario.setInput(input);

	slayer.setTexture(&custom);
	slayer.setPosition(500, 500);
	slayer.setSize(sf::Vector2f(100, 100));

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	jombie.handleInput(dt);
	shmario.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	jombie.update(dt);
	shmario.update(dt);
	slayer.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(jombie);
	window->draw(shmario);
	window->draw(slayer);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}