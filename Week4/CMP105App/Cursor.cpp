#include "Cursor.h"

Cursor::Cursor()
{
	view = nullptr;
}
Cursor::~Cursor()
{
}

void Cursor::handleInput(float dt)
{
}

void Cursor::update(float dt)
{
	setPosition(input->getMouseX() + view->getCenter().x - (view->getSize().x / 2), input->getMouseY() + view->getCenter().y - (view->getSize().y / 2));
}
