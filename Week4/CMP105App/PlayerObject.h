#pragma once
#include "Framework/GameObject.h"

class PlayerObject :
	public GameObject
{
public:
	PlayerObject();
	~PlayerObject();

	void handleInput(float dt) override;
	void update(float dt) override;

	void setSpeed(float sp) { speed = sp; };
	float getSpeed() { return speed; };

private:
	float speed;
};

