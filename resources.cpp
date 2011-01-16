#include "resources.h"
#include <iostream>
#include <cstdlib>

resources::resources(void)
{
	msfile.open("mainscript.sc");
	charfile.open("charscript.sc");
	locfile.open("locscript.sc");
	loadcharscript();
	loadlocscript();
	line = 0;
}


resources::~resources(void)
{
}

void resources::nextline()
{
	this->line = this->line + 1; // zwiêksza numer lini
	getline(msfile,activeline); // pobiera aktywn¹ linie do pliku pomocniczego
	active.changestring(activeline); // ³aduje linie do scriptline, aby podzieli³ j¹ na wyra¿enia
	interpretuj();
}

void resources::interpretuj()
{
	if (active.words[0] == "write")
	{
		cout << active.words[1] << endl;
	}
	if (active.words[0] == "if")
	{
		if (active.words[1] == "location")
		{
			int loc = atoi(active.words[2].c_str());
			while (characters[0].locationid != loc) characteraction(&characters[0]);
		}
	}
}

void resources::loadcharscript()
{
	while (!charfile.eof()) 
	{
		character tmp;
		string tmps;
		while(tmps != "-")
		{
			getline(charfile,tmps);
			if (tmps == "ID:") charfile >> tmp.ID;
			if (tmps == "HP:") charfile >> tmp.HP;
			if (tmps == "HP_MAX:") charfile >> tmp.HP_MAX;
			if (tmps == "NAME:") getline(charfile,tmp.name);
			if (tmps == "LOCATIONID:") charfile >> tmp.locationid;
		}
		characters.push_back(tmp);
	}
}

void resources::loadlocscript()
{
	while (!locfile.eof())
	{
		location tmp;
		string tmps;
		int tmpi;
		while(tmps != "-")
		{
			getline(locfile,tmps);
			if (tmps == "ID:") locfile >> tmp.ID;
			if (tmps == "NAME:") getline(locfile,tmp.name);
			if (tmps == "DESCRIPTION:") getline(locfile,tmp.description);
			if (tmps == "ENEMYNUMBER:") locfile >> tmp.enemynumber;
			if (tmps == "NPCNUMBER:") locfile >> tmp.npcnumber;
			if (tmps == "ENEMYIDS:") 
			{
				for ( int i = 0; i < tmp.enemynumber; i++) 
				{
					locfile >> tmpi;
					tmp.enemyids.push_back(tmpi);
				}
			}
			if (tmps == "NPCIDS:")
			{
				for ( int i = 0; i < tmp.npcnumber; i++)
				{
					locfile >> tmpi;
					tmp.npcids.push_back(tmpi);
				}
			}
			if (tmps == "EXITIDS:")
			{
				locfile >> tmpi;
				tmp.exitids.push_back(tmpi);
			}
		}
		for ( int i = 0; i < tmp.enemynumber; i++)
		{
			tmp.enemies.push_back(characters[tmp.enemyids[i]]);
		}
		locations.push_back(tmp);
	}
}

void resources::characteraction(character* a)
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
					bool t = 0;
					for ( int i = 0; i < locations[a->locationid].exitids.size(); i++)
					{
					if ( loc == locations[a->locationid].exitids[i])
					{
						t = 1;
					}
						if (t == 1){
							a->changelocation(loc);
						}
					}
				}
			}
		}
		if ( activeline.words[0] == "look") {
			cout << locations[a->locationid].description << endl;
		}
	}
}