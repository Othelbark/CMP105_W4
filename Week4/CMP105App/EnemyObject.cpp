#include "EnemyObject.h"

EnemyObject::EnemyObject()
{
	window = nullptr;
	setVelocity(350, 750);
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
	if (getPosition().x + getSize().x > window->getSize().x || getPosition().x < 0)
	{
		velocity.x *= -1;
	}
	if (getPosition().y + getSize().y > window->getSize().y || getPosition().y < 0)
	{
		velocity.y *= -1;
	}

	//find window size and player posistion
	float windowXSize = window->getSize().x;
	float windowYSize = window->getSize().y;
	float xPos = getPosition().x;
	float yPos = getPosition().y;

	// If enemy has passed the right side
	if (xPos + getSize().x > windowXSize)
	{
		//dont go off the side
		setPosition(windowXSize - getSize().x, yPos);
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
	if (yPos + getSize().y > windowYSize)
	{
		//dont go off the side
		setPosition(xPos, windowYSize - getSize().y);
	}
	// If enemy has passed the left side
	else if (yPos < 0)
	{
		//dont go off the side
		setPosition(xPos, 0);
	}

	move(velocity * dt);
}
