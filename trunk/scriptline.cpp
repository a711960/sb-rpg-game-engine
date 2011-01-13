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
	unsigned int i = 0; // licznik zewn., ³atwiej mi by³o wyobraziæ sobie to na pêtli while
	while (i<line.length()) 
	{
		if (line[i] == '"') // jeœli jest w cydzos³owach  to co miêdzy nimi ma trafiæ jak¹ jeden element wektora ( jako np. pojedynczy parametr komendy)
		{
			i++;
			while (line[i]!= '"')
			{
				tmp.push_back(line[i]); // dadajemy znaki do tmp , póki nie spotkamy cudzys³owiu
				i++;
			}
			words.push_back(tmp); // dodajemy na koñcu wektora nasz ³añcuch
			tmp.clear(); // czyœcimy  tymczasowy string
			i++;
		}

		else 
		{
			while(line[i] != ' ') // co spacje kolejne s³owo
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