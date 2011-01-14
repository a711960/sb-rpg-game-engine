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
	if (!activeline.words.empty()) 
	{
		if ( activeline.words[0] == "exit")
		{
			if ( activeline.words.size() > 1)
			{
				int loc;
				if (loc = atoi(activeline.words[1].c_str()))
				{
					//bool t = 0;
					//for ( int i = 0; i < locations[locationid].exitids.size(); i++)
					//{
					//if ( loc == locations[locationid].exitids[i])
					//{
					//	t = 1;
					//}
					//	if (t == 1){
							changelocation(loc);
					//	}
					//}
				}
			}
		}
		if ( activeline.words[0] == "look") {
			//cout << locations[locationid].description << endl;
		}
	}
}
void character::changelocation(int loc)
{
	locationid = loc;
}