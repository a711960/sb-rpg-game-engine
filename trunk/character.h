#pragma once
#include <string>

using namespace std;

class character
{
public:
	int ID;
	int level;
	int STR;
	int base_atk;
	string name;
	int HP;
	int HP_MAX;
	int DEF;
	character(void);
	~character(void);
};