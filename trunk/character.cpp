#include "character.h"
#include <string>
#include "scriptline.h"
#include <cstdlib>
#include <iostream>

using namespace std;

character::character(void)
{
}


character::~character(void)
{
}

void character::changelocation(int loc)
{
	locationid = loc;
}