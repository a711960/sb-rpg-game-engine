#include "resources.h"
#include <iostream>
#include <sstream>
#include <cstdlib>



resources::resources(void)
{
	msfile.open("mainscript.sc");
	charfile.open("charscript.sc");
	locfile.open("locscript.sc");
	mcharfile.open("mcharscript.sc");
//	npcfile.open("npcscript.sc");
	loadcharscript();
	loadmcharscript();
	loadlocscript();
	line = 0;
}

resources::~resources(void)
{
}

int stringtoint(string input)
{
	stringstream converter(input);
	int wynik;
	converter >> wynik;
	return wynik;
}

void resources::nextline()
{
	this->line = this->line + 1;
	getline(msfile,activeline);
	active.changestring(activeline); 
	interpretuj();
}

void resources::interpretuj()
{
	if (active.words[0] == "write")
	{
		cout << active.words[1] << endl;
	}
	if (active.words[0] == "if")
	{
		if (active.words[1] == "location")
		{
			int loc = atoi(active.words[2].c_str());
			while (mcharacters[0].locid != loc) mcharacteraction(&mcharacters[0]);
		}
	}
}

void resources::loadcharscript()
{
	vector<string> filedata;
	string line;
	if(charfile.is_open())
	{
		while(charfile.good())
		{
			getline(charfile,line);
			filedata.push_back(line);
		}
		charfile.close();
	}

	size_t j = 0;

	while (j < filedata.size()) 
	{
		character tmp;
		string tmps = filedata[j];
		j++;
		while(tmps != "-")
		{
			getline(charfile,tmps);
			if (tmps == "ID:") tmp.ID = stringtoint(filedata[j]);
			if (tmps == "HP:") tmp.HP = stringtoint(filedata[j]);
			if (tmps == "HP_MAX:") tmp.HP_MAX = stringtoint(filedata[j]);
			if (tmps == "NAME:") tmp.name = filedata[j];
			j++;
			tmps = filedata[j];
			j++;
		}
		characters.push_back(tmp);
	}
}

void resources::loadlocscript()
{
	vector<string> filedata;
	string line;
	if(locfile.is_open())
	{
		while(locfile.good())
		{
			getline(locfile,line);
			filedata.push_back(line);
		}
		locfile.close();
	}

	size_t j = 0;
	while (j < filedata.size())
	{
		location tmp;
		string tmps = filedata[j];
		j++;
		while(tmps != "-")
		{
			if (tmps == "ID:") tmp.ID = stringtoint(filedata[j]);
			if (tmps == "NAME:") tmp.name = filedata[j];
			if (tmps == "DESCRIPTION:") tmp.description = filedata[j];
			if (tmps == "ENEMYNUMBER:") tmp.enemynumber = stringtoint(filedata[j]);
			if (tmps == "NPCNUMBER:") tmp.npcnumber = stringtoint(filedata[j]);
			if (tmps == "EXITNUMBER:") tmp.exitnumber = stringtoint(filedata[j]);
			if (tmps == "ENEMYIDS:") 
			{
				for ( int i = 0; i < tmp.enemynumber; i++) 
				{
					tmp.enemyids.push_back(stringtoint(filedata[j]));
					if(tmp.enemynumber - 1 != i) j++;
				}
			}
			if (tmps == "NPCIDS:")
			{
				for ( int i = 0; i < tmp.npcnumber; i++)
				{
					tmp.npcids.push_back(stringtoint(filedata[j]));
					if(tmp.npcnumber - 1 != i) j++;
				}
			}
			if (tmps == "EXITIDS:")
			{
				for ( int i = 0; i < tmp.exitnumber; i++)
				{
					tmp.exitids.push_back(stringtoint(filedata[j]));
					if(tmp.exitnumber - 1 != i) j++;
				}
			}
			j++;
			tmps = filedata[j];
			j++;
		}
		for ( int i = 0; i < tmp.enemynumber; i++)
		{
			tmp.enemies.push_back(characters[tmp.enemyids[i]]);
		}
		locations.push_back(tmp);		
	}
}

void resources::loadmcharscript(){
	vector<string> filedata;
	string line;
	if(mcharfile.is_open())
	{
		while(charfile.good())
		{
			getline(mcharfile,line);
			filedata.push_back(line);
		}
		charfile.close();
	}

	size_t j = 0;

	while(j < filedata.size())
	{
		mcharacter tmp;
		string tmps = filedata[j];
		j++;
		while(tmps != "-")
		{
			getline(mcharfile,tmps);
			if (tmps == "ID:") tmp.ID = stringtoint(filedata[j]);
			if (tmps == "NAME:") tmp.name = filedata[j];
			if (tmps == "HP:") tmp.HP = stringtoint(filedata[j]);
			if (tmps == "HP_MAX") tmp.HP_MAX = stringtoint(filedata[j]);
			if (tmps == "LOC_ID:") tmp.locid = stringtoint(filedata[j]);
			j++;
			tmps = filedata[j];
			j++;
		}
		mcharacters.push_back(tmp);
	}
}

void resources::mcharacteraction(mcharacter* a)
{
	string line;
	getline(cin,line);
	scriptline actionline;
	actionline.changestring(line);
	if (!actionline.words.empty()) 
	{
		if ( actionline.words[0] == "exit")
		{
			if ( actionline.words.size() > 1)
			{
				int loc = stringtoint(actionline.words[1]);
				if (loc >= 0)
				{
					bool t = 0;
					for (unsigned int i = 0; i < locations[a->locid].exitnumber; i++)
					{
						if ( loc == locations[a->locid].exitids[i])
						{
							t = 1;
						}
						
					}
					if (t == 1)
						{
							a->changelocation(loc);
						}
				}
			}
		}
		if ( actionline.words[0] == "look") {
			cout << locations[a->locid].name << endl;
			cout << locations[a->locid].description << endl;
			cout << "Exits: " << endl;
			for(int i = 0; i < locations[a->locid].exitnumber; i++)
			{
				cout << locations[locations[a->locid].exitids[i]].name << " - " << locations[a->locid].exitids[i] << endl;
			}
		}
	}
}