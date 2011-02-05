#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "scriptline.h"
#include "character.h"
#include "location.h"
#include "mcharacter.h"
#include "npc.h"

using namespace std;

class resources
{
public:
	int line;
	int actcharid;
	string activeline; 
	scriptline active;
	ifstream msfile; 
	ifstream charfile; 
	ifstream locfile;
	ifstream mcharfile;
//	ifstream npcfile;
	vector<character> characters;
	vector<location> locations;
	vector<mcharacter> mcharacters;
	vector<npc> npcs;
	void loadcharscript();
	void loadlocscript();
	void interpretuj();
	void nextline(); 
	void mcharacteraction(mcharacter* a);
	void loadmcharscript();
	resources(void);
	~resources(void);
};