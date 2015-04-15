#include "Libraries.h"

char* const sound1 = "about_time.wav";
char* const sound2 = "enemy_hit.wav";

int main(int argc, char* args[])
{
	// Proportional resolution for NES (default: 256 * 240) (only to show it's working, default "Init()" has the same size as before (800 * 600))
	Engine::GetInstance()->Init(800, 750); 
	Gimmick* man = new Gimmick();
	man->ScaleSprite(125, 75);
	Sprite("ship.jpg", 662, 464);
	TextAnim* textTest = new TextAnim("Letter by letter", LETTER, "dialog.ttf");
	TextAnim* textTest2 = new TextAnim("Word by word", WORD, "dialog.ttf", 18, 0, 50);
	textTest2->SetTextColor(RED);
	TextAnim* textTest3 = new TextAnim("And now in color", LINE, "dialog.ttf", 18, 0, 100, GREEN);
	TextAnim* textTest4 = new TextAnim("Text animation - v.0.2.6", LINE, "dialog.ttf", 18, 0, 150);
	textTest4->SetTextColor(BLUE);
	textTest->SetFontsize(18);
	textTest->Play();
	textTest2->Play();
	textTest3->Play();
	textTest4->Play();
	AUDIO->SetMusicVolume(30);
	AUDIO->PlayMusic("testmusic.mp3");
	AUDIO->AddSoundToList(sound2);
	AUDIO->OverrideSoundInList(sound1, sound2);
	AUDIO->PlaySound(sound1, 1);

	// L'engin vire
	Engine::GetInstance()->Run();

	delete textTest;
	delete textTest2;
	delete textTest3;
	delete textTest4;
	return 0;
}
