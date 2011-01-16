#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "scriptline.h"
#include "character.h"
#include "location.h"

using namespace std;

class resources
{
public:
	int line; // numer lini.przyda si� p�niej przy odniesieniach
	string activeline; // p�niej usune, chwilowo zmienna pomocnicza
	scriptline active; // aktywna linia 
	ifstream msfile; // strumie� g��wnego skryptu
	ifstream charfile; // strumie� danych postaci, potwor�w
	ifstream locfile;
	vector<character> characters;
	vector<location> locations;
	void loadcharscript();
	void loadlocscript();
	void interpretuj();
	void nextline(); 
	void characteraction(character* a);
	resources(void);
	~resources(void);
};