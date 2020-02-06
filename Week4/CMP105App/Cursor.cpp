#include "Cursor.h"

Cursor::Cursor()
{
}
Cursor::~Cursor()
{
}

void Cursor::handleInput(float dt)
{
}

void Cursor::update(float dt)
{
	setPosition(input->getMouseX(), input->getMouseY());
}
