#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/GameObject.h"
#include "PlayerObject.h"
#include "EnemyObject.h"
#include "Background.h"
#include "Cursor.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	
	// Veiw Object
	sf::View view;
	float viewScrollSpeed = 800.0f;

	// Level objects

	// Cursor
	Cursor cursor;
	sf::Texture cursorTexture;


	// Player
	PlayerObject playerObject;
	sf::Texture playerTexture;

	// Enemies
	EnemyObject enemyObject1;
	sf::Texture enemyTexture1;

	EnemyObject enemyObject2;
	sf::Texture enemyTexture2;

	// Background
	Background background;
	sf::Texture backgroundTexture;

};