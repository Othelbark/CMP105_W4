#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	view = window->getView();

	window->setMouseCursorVisible(false);

	// initialise game objects

	//cursor
	cursorTexture.loadFromFile("gfx/icon.png");
	cursor.setTexture(&cursorTexture);
	cursor.setSize(sf::Vector2f(30, 30));
	cursor.setPosition(-50, -50);
	cursor.setInput(input);
	cursor.setView(&view);

	//player
	playerTexture.loadFromFile("gfx/Mushroom.png");
	playerObject.setTexture(&playerTexture);
	playerObject.setSize(sf::Vector2f(100, 100));
	playerObject.setPosition(100, 100);
	playerObject.setSpeed(600);
	playerObject.setInput(input);

	//enemies
	enemyTexture1.loadFromFile("gfx/Goomba.png");
	enemyObject1.setTexture(&enemyTexture1);
	enemyObject1.setSize(sf::Vector2f(70, 70));
	enemyObject1.setPosition(500, 200);
	enemyObject1.setWindow(window);

	enemyObject2.setTexture(&cursorTexture);
	enemyObject2.setSize(sf::Vector2f(50, 50));
	enemyObject2.setPosition(300, 600);
	enemyObject2.setWindow(window);

	//background
	backgroundTexture.loadFromFile("gfx/Level1_1.png");
	background.setTexture(&backgroundTexture);
	background.setSize(sf::Vector2f(11038, 675));
	

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

	// Get view change input
	if (input->isKeyDown(sf::Keyboard::A))
	{
		view.move(-viewScrollSpeed * dt, 0);
		float leftSide = view.getCenter().x - (view.getSize().x / 2);
		//if view is all the way left
		if (leftSide < 0) 
		{
			view.setCenter((view.getSize().x / 2), view.getCenter().y);
		}
	}
	else if (input->isKeyDown(sf::Keyboard::D))
	{
		view.move(viewScrollSpeed * dt, 0);
		float rightSide = view.getCenter().x + (view.getSize().x / 2);
		float farRightSide = background.getPosition().x + background.getSize().x;
		//if view is all the way right
		if (rightSide > farRightSide)
		{
			view.setCenter(farRightSide - (view.getSize().x / 2), view.getCenter().y);
		}
	}


	// Handle cursor input
	cursor.handleInput(dt);
	// Handle player input
	playerObject.handleInput(dt);

}

// Update game objects
void Level::update(float dt)
{
	// Update player
	cursor.update(dt);
	playerObject.update(dt);
	enemyObject1.update(dt);
	enemyObject2.update(dt);
}

// Render level
void Level::render()
{
	window->setView(view);

	beginDraw();

	window->draw(background);
	window->draw(playerObject);
	window->draw(enemyObject1);
	window->draw(enemyObject2);
	window->draw(cursor);

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