#pragma once
#include "Framework/Animation.h"
#include "Framework/GameObject.h"

class Player : 
	public GameObject
{
public:
	Player();
	~Player();

	void update(float dt) override;
	void handleInput(float dt) override;

protected:
	Animation idle;
	Animation* currentAnimation;

	bool lookingRight;
	float speed;
};

