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
		while(tmps != "-"){
			getline(charfile,tmps);
			if (tmps == "ID:") charfile >> tmp.ID;
			if (tmps == "HP:") charfile >> tmp.HP;
			if (tmps == "HP_MAX:") charfile >> tmp.HP_MAX;
			if (tmps == "NAME:") getline(charfile,tmp.name);
		}
		characters.push_back(tmp);
	}
}