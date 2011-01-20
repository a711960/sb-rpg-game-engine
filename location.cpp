#include "location.h"


location::location(void)
{
	ID  = 0;
	enemynumber = 0;
	exitnumber = 0;
	npcnumber = 0;
}


location::~location(void)
{
}

void location::respawnenemys()
{
}

location::location(const location &cplocation){
	ID = cplocation.ID;
	enemynumber = cplocation.enemynumber;
	npcnumber = cplocation.npcnumber;
	exitnumber = cplocation.exitnumber;
	name = cplocation.name;
	description = cplocation.description;
	enemies = cplocation.enemies;
	npcids = cplocation.npcids;
	enemyids = cplocation.enemyids;
	exitids = cplocation.exitids;
}