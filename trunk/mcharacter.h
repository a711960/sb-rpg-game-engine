#pragma once
#include <string>
#include "character.h"
#include "scriptline.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class mcharacter
{
public:
	int ID;
	int level;
	string name;
	int HP;
	int HP_MAX;
	int STR;
	int DEF;
	int base_atk;
	int locid;
	mcharacter(void);
	void fight(character *a);
	void changelocation(int loc);
	~mcharacter(void);
};