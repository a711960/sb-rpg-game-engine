#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "scriptline.h"
#include "character.h"
#include "location.h"

using namespace std;

class resources
{
public:
	int line;
	string activeline; 
	scriptline active;
	ifstream msfile; 
	ifstream charfile; 
	ifstream locfile; 
	vector<character> characters;
	vector<location> locations;
	void loadcharscript();
	void loadlocscript();
	void interpretuj();
	void nextline(); 
	void characteraction(character* a);
	resources(void);
	~resources(void);
};