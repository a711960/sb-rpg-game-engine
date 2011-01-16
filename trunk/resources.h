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
	int line; // numer lini.przyda siê póŸniej przy odniesieniach
	string activeline; // póŸniej usune, chwilowo zmienna pomocnicza
	scriptline active; // aktywna linia 
	ifstream msfile; // strumieñ g³ównego skryptu
	ifstream charfile; // strumieñ danych postaci, potworów
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