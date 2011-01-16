#include "game.h"

game::game(void)
{
	game::stan = start;
	gingame();
}

game::~game(void)
{
	game::stan = end;
}

void game::gpause()
{
	game::stan = paused;
}

void game::gingame()
{
	game::stan = ingame;
	while(!ms.msfile.eof())
	{
		ms.nextline();
	}
}