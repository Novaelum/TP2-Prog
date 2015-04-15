#include "Ship.h"

const float Ship::SPEED = 0.1f;

Ship::Ship()
	: Sprite("ship.jpg")
	, currentX(0)
	, currentY(0)
	, currentTime(0)
{
}

Ship::~Ship()
{
}

void Ship::Start()
{
}

void Ship::Update()
{
	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();

	if (Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_SPACE))
	{
		// Opération time Base
		currentX += SPEED * dt;
		currentY += SPEED * dt;
		SetPosition(currentX, currentY);
	}
}

void Ship::Stop()
{
}
