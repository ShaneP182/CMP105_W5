#pragma once
#include "Framework/Animation.h"
#include "Framework/GameObject.h"

class Mario : 
	public GameObject
{
public:
	Mario();
	~Mario();

	void update(float dt) override;
	void handleInput(float dt) override;

protected:
	Animation walk;
	Animation swim;
	Animation idle;
	Animation* currentAnimation;

	bool lookingRight;
	float speed;
};

