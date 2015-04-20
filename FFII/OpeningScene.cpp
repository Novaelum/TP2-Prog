#include "OpeningScene.h"
#include "Libraries.h"


OpeningScene::OpeningScene()
{
	background = new Sprite("images/openingscreen.jpg");
	cAudio->PlayMusic("soundtracks/openingtheme.mp3");
	cAudio->SetMusicVolume(40);
	openingline = new Text("Push enter to begin", "dialog.ttf", 22, point<int>(300, 415), 0, Color::BLACK, OpFadeIn);
}

OpeningScene::~OpeningScene()
{
	delete background;
	delete openingline;
}

void OpeningScene::Update()
{
	if (ThisKeyReleased(SDL_SCANCODE_RETURN))
	{
		std::cout << "detected!";
		SDL_Quit();
	}
}
