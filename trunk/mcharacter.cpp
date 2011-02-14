#include "mcharacter.h"


mcharacter::mcharacter(void)
{
}


mcharacter::~mcharacter(void)
{
}

void mcharacter::changelocation(int loc)
{
	locid = loc;
}

void mcharacter::fight(character *a)
{
	while ( !((HP == 0) || (a->HP == 0)))
	{
		scriptline fightline;
		string tmp;
		getline(cin,tmp);
		fightline.changestring(tmp);
		srand(time(NULL));
		if ( fightline.words[0] == "atack")
		{
			if (fightline.words.size() > 1)
			{
				if ( fightline.words[1] == "light")
				{
					int k = rand() % 100 + 1;
					if ( k > 20 ) 
					{
						int bonus = rand() % level;
						int hit = bonus + STR + base_atk - a->DEF;
						if (hit > 0) a->HP = a->HP - hit;
					}
					else cout << "Your hit missed!!!" << endl;
				}
				else if ( fightline.words[1] == "heavy")
				{
					int k = rand() % 100 + 1;
					if ( k > 60)
					{
						int bonus = rand() % level;
						int hit = bonus + STR + 2 * base_atk - a->DEF;
						if ( hit > 0) a->HP = a->HP - hit;
						else cout << "Enemy defended himself!!!" << endl;
					}
					else cout << "Your hit missed!!!" << endl;
				}
			}
		}
		int k  = rand() % 100 + 1;
		if ( k > 40)
		{
			int bonus = rand() % a->level;
			int hit = bonus + a->STR + a->base_atk - DEF;
			if ( hit > 0) HP = HP - hit;
			else cout << "You defended yourself!!!" << endl;
		}
		else cout << "Enemy hit missed!!!" << endl;
	}
}