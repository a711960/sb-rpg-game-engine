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
	int line; // numer lini.przyda siê póŸniej przy odniesieniach
	string activeline; // póŸniej usune, chwilowo zmienna pomocnicza
	scriptline active; // aktywna linia 
	ifstream msfile; // strumieñ g³ównego skryptu
	ifstream charfile; // strumieñ danych postaci, potworów
	vector<character> characters;
	void loadcharscript();
	void interpretuj();
	void nextline(); 
	resources(void);
	~resources(void);
};