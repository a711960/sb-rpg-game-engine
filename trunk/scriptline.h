#pragma once
#include <string>
#include <vector>

using namespace std;

class scriptline
{
public:
	string scline; // zawiera ca�� linie, mo�e b�de potrzebowa�
	vector<string> words; // wektor ze s�owami
	scriptline(void);
	void changestring(string line); // aktualizacja obiektu
	~scriptline(void);
};

