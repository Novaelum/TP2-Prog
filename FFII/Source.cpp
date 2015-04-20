#include "Libraries.h"

char* const sound1 = "about_time.wav";
char* const sound2 = "enemy_hit.wav";

int main(int argc, char* args[])
{
	// Proportional resolution for NES (default: 256 * 240) (only to show it's working, default "Init()" has the same size as before (800 * 600))
	cEngine->Init(900, 600);
	OpeningScene* opening = new OpeningScene();

	Engine::GetInstance()->Run();

	//delete opening;
	return 0;
}
