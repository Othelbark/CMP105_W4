#pragma once
#include "Framework/GameObject.h"
class Cursor :
	public GameObject
{
public:
	Cursor();
	~Cursor();

	sf::View* view;

	void handleInput(float dt) override;
	void update(float dt) override;

	// Set the view component
	void setView(sf::View* vw) { view = vw; };
};

