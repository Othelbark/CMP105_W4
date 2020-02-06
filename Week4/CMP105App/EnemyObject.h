#pragma once
#include "Framework/GameObject.h"
class EnemyObject :
	public GameObject
{
public:
	EnemyObject();
	~EnemyObject();

	void handleInput(float dt) override;
	void update(float dt) override;

	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; };

protected:
	//window component
	sf::RenderWindow* window;
};

