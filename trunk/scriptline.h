#pragma once
#include <string>
#include <vector>

using namespace std;

class scriptline
{
public:
	string scline; // zawiera ca³¹ linie, mo¿e bêde potrzebowaæ
	vector<string> words; // wektor ze s³owami
	scriptline(void);
	void changestring(string line); // aktualizacja obiektu
	~scriptline(void);
};

