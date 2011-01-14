#pragma once
#include <string>

using namespace std;

class character
{
public:
	int ID;
	string name;
	int HP;
	int HP_MAX;
	int locationid;
	character(void);
	~character(void);
};

