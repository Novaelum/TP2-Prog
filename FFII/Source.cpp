#include "Libraries.h"

char* const sound1 = "about_time.wav";
char* const sound2 = "enemy_hit.wav";

int main(int argc, char* args[])
{
	// Proportional resolution for NES (default: 256 * 240) (only to show it's working, default "Init()" has the same size as before (800 * 600))
	cEngine->Init(900, 600);
	cGame;
	cAudio->PlayMusic("musics/openingtheme.mp3");
	OpeningScene* opening = new OpeningScene();

	cEngine->Run();

	//delete opening;
	return 0;
}
