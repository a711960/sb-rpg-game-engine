#include "game.h"
#include <string>

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
	while(!ms.msfile.eof())// sprawdza czy plik siê skoñczy³
	{
		ms.nextline();//odpala interpratacje kolejnej lini w pliku
	}
}