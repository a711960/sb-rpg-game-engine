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
	string description;
	vector<character> enemies;
	vector<int> enemyids;
	vector<int> npcids;
	void spawnenemys();
	location(void);
	~location(void);
};

