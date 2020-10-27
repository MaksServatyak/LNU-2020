#include "Drops.h"
#include <iostream>
using namespace std;

Drops::Drops(string name, string application, int year, int number, string klas)
{
	this->name = name;
	this->application = application;
	this->year = year;
	this->number = number;
	this->klas = klas;
}