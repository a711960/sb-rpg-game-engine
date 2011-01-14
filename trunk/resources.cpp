#include "resources.h"
#include <iostream>

resources::resources(void)
{
	msfile.open("mainscript.sc");
	charfile.open("charscript.sc");
	loadcharscript();
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
}

void resources::loadcharscript()
{
	while (!charfile.eof()) // rozwi¹zanie bardzo tymczasowe
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
				for ( int i = 0; i < tmp.enemynumber; i++)
				{
					locfile >> tmpi;
					tmp.npcids.push_back(tmpi);
				}
			}
			for ( int i = 0; i < tmp.enemynumber; i++)
			{
				tmp.enemies.push_back(characters[tmp.enemyids[i]]);
			}
			locations.push_back(tmp);
		}
	}
}
