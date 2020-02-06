#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	playerTexture.loadFromFile("gfx/Mushroom.png");

	playerObject.setTexture(&playerTexture);
	playerObject.setSize(sf::Vector2f(100, 100));
	playerObject.setPosition(100, 100);
	playerObject.setSpeed(0.6f);

	playerObject.setInput(input);


	enemyTexture1.loadFromFile("gfx/Goomba.png");

	enemyObject1.setTexture(&enemyTexture1);
	enemyObject1.setSize(sf::Vector2f(100, 100));
	enemyObject1.setPosition(500, 200);

	enemyObject1.setWindow(window);

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}

	// Handle player input
	playerObject.handleInput(dt);

}

// Update game objects
void Level::update(float dt)
{
	// Update player
	playerObject.update(dt);
	enemyObject1.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(playerObject);
	window->draw(enemyObject1);

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