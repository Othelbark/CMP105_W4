#include "PlayerObject.h"

PlayerObject::PlayerObject()
{
	speed = 1;
}

PlayerObject::~PlayerObject()
{
}

void PlayerObject::handleInput(float dt)
{
	//Find velocity from input
	sf::Vector2f velocity (0,0);

	//holding right
	if (input->isKeyDown(sf::Keyboard::Right) || input->isKeyDown(sf::Keyboard::D))
	{
		velocity.x += 1;
	}
	//holding left
	if (input->isKeyDown(sf::Keyboard::Left) || input->isKeyDown(sf::Keyboard::A))
	{
		velocity.x -= 1;
	}
	//holding down
	if (input->isKeyDown(sf::Keyboard::Down) || input->isKeyDown(sf::Keyboard::S))
	{
		velocity.y += 1;
	}
	//holding up
	if (input->isKeyDown(sf::Keyboard::Up) || input->isKeyDown(sf::Keyboard::W))
	{
		velocity.y -= 1;
	}

	//if moving diagonally
	if (velocity.y != 0 && velocity.x != 0)
	{
		//normalise
		float root2 = 1.41421356;
		velocity.x /= root2;
		velocity.y /= root2;
	}

	setVelocity(velocity * speed);
}

void PlayerObject::update(float dt)
{
	//Move based on velocity
	move(velocity);
	//setPosition(getPosition() + getVelocity());
}
