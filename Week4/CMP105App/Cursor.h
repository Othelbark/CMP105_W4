#pragma once
#include "Framework/GameObject.h"
class Cursor :
	public GameObject
{
public:
	Cursor();
	~Cursor();

	void handleInput(float dt) override;
	void update(float dt) override;
};

