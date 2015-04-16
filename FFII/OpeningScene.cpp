#include "OpeningScene.h"
#include "Libraries.h"


OpeningScene::OpeningScene()
{
	background = new Sprite("images/openingscreen.jpg");
	AUDIO->PlayMusic("soundtracks/openingtheme.mp3");
	AUDIO->SetMusicVolume(40);
	dialog = new TextAnim("Press enter to begin", LINE, "dialog.ttf", 18, 340, 425, BLACK);
	dialog->Play();
}

OpeningScene::~OpeningScene()
{
	delete background;
	delete dialog;
}

void OpeningScene::Update()
{
	if (Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_SPACE))
	{
		std::cout << "detected!";
	}
}
