#include "EnemyObject.h"

EnemyObject::EnemyObject()
{
	window = nullptr;
	setVelocity(0.35, 0.75);
}
EnemyObject::~EnemyObject()
{
}

void EnemyObject::handleInput(float dt)
{
}

void EnemyObject::update(float dt)
{

	//bounce off edge
	if (getPosition().x > window->getSize().x || getPosition().x < 0)
	{
		velocity.x *= -1;
	}
	if (getPosition().y > window->getSize().y || getPosition().y < 0)
	{
		velocity.y *= -1;
	}

	//find window size and player posistion
	float windowXSize = window->getSize().x;
	float windowYSize = window->getSize().y;
	float xPos = getPosition().x;
	float yPos = getPosition().y;

	// If enemy has passed the right side
	if (xPos > windowXSize)
	{
		//dont go off the side
		setPosition(windowXSize, yPos);
	}
	// If enemy has passed the left side
	else if (xPos < 0)
	{
		//dont go off the side
		setPosition(0, yPos);
	}

	//check if x value changed
	xPos = getPosition().x;

	// If enemy has passed the bottom side
	if (yPos > windowYSize)
	{
		//dont go off the side
		setPosition(xPos, windowYSize);
	}
	// If enemy has passed the left side
	else if (yPos < 0)
	{
		//dont go off the side
		setPosition(xPos, 0);
	}

	move(velocity);
}
