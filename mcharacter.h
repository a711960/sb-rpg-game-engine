#pragma once
#include <string>

using namespace std;

class mcharacter
{
public:
	int ID;
	string name;
	int HP;
	int HP_MAX;
	int locid;
	mcharacter(void);
	void changelocation(int loc);
	~mcharacter(void);
};

