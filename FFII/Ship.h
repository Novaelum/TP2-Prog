#pragma once

#include "Common.h"
#include "Sprite.h"

class Ship :
	public Sprite
{
public:
	Ship();
	~Ship();

	void Start();
	void Update();
	void Stop();

private:
	float currentX, currentY;
	float currentTime;

	static const float SPEED;
};

