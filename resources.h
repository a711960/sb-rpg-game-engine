#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "scriptline.h"
#include "character.h"

using namespace std;

class resources
{
public:
	int line; // numer lini.przyda si� p�niej przy odniesieniach
	string activeline; // p�niej usune, chwilowo zmienna pomocnicza
	scriptline active; // aktywna linia 
	ifstream msfile; // strumie� g��wnego skryptu
	ifstream charfile; // strumie� danych postaci, potwor�w
	vector<character> characters;
	void loadcharscript();
	void interpretuj();
	void nextline(); 
	resources(void);
	~resources(void);
};