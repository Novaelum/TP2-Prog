#include "Game.h"
#include "Libraries.h"

Game* Game::instance = 0;

Game::Game()
	: player(new Player())
	, cursor(new Sprite(t_cursor))
{

}


Game::~Game()
{
	delete player;
	delete cursor;
}
