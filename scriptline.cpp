#include "scriptline.h"


scriptline::scriptline()
{
}


scriptline::~scriptline(void)
{
}

void scriptline::changestring(string line)
{
	scline = line;
	string tmp;
	words.clear();
	unsigned int i = 0;
	while (i<line.length()) 
	{
		if (line[i] == '"') 
		{
			i++;
			while (line[i]!= '"')
			{
				tmp.push_back(line[i]);
				i++;
			}
			words.push_back(tmp);
			tmp.clear(); 
			i++;
		}

		else 
		{
			while(line[i] != ' ') 
			{
				tmp.push_back(line[i]);
				i++;
				if (i == line.length()) break;
			}
			words.push_back(tmp);
			tmp.clear();
			i++;
		}
	}
}