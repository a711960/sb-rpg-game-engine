#pragma once
#include <string>
#include "character.h"
#include <vector>

using namespace std;
class location
{
public:
	int ID;
	int enemynumber;
	int npcnumber;
	string name;
	string description;
	vector<character> enemies;
	vector<int> enemyids;
	vector<int> npcids;
	vector<int> exitids;
	void spawnenemys();
	location(void);
	~location(void);
};

