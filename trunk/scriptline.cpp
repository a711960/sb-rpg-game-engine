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
	unsigned int i = 0; // licznik zewn., �atwiej mi by�o wyobrazi� sobie to na p�tli while
	while (i<line.length()) 
	{
		if (line[i] == '"') // je�li jest w cydzos�owach  to co mi�dzy nimi ma trafi� jak� jeden element wektora ( jako np. pojedynczy parametr komendy)
		{
			i++;
			while (line[i]!= '"')
			{
				tmp.push_back(line[i]); // dadajemy znaki do tmp , p�ki nie spotkamy cudzys�owiu
				i++;
			}
			words.push_back(tmp); // dodajemy na ko�cu wektora nasz �a�cuch
			tmp.clear(); // czy�cimy  tymczasowy string
			i++;
		}

		else 
		{
			while(line[i] != ' ') // co spacje kolejne s�owo
			{
				tmp.push_back(line[i]);
			i++;
			}
			words.push_back(tmp);
			tmp.clear();
			i++;
		}
	}
}