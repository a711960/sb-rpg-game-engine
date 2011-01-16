#pragma once
#include "resources.h"

using namespace std;

class game
{
private:
	enum state { start = 0, ingame = 3, end = 4, paused = 5}; // póŸniej posprz¹tam, ma³y ba³agan koncpecyjny
	state stan;
public:
	resources ms; 
	game(void);
	void gingame();
	void gpause();
	~game(void);
};