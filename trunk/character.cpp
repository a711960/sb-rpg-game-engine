#include "character.h"
#include <string>
#include "scriptline.h"
#include <cstdlib>
#include <iostream>

using namespace std;

character::character(void)
{
}


character::~character(void)
{
}

void character::characteraction()
{
	string line;
	getline(cin,line);
	scriptline activeline;
	activeline.changestring(line);
	if (!activeline.words.empty()) {
		if ( activeline.words[0] == "exit")
		{
			int loc;
			if (loc = atoi(activeline.words[1].c_str()))
			{
				changelocation(loc);
			}
		}
	}
}
void character::changelocation(int loc)
{
	locationid = loc;
}