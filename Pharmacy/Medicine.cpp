#include "Medicine.h"
#include <iostream>
using namespace std;

Medicine::Medicine(string name,string application,int year,int number,string klas)
{
	this->name = name;
	this->application = application;
	this->year = year;
	this->number = number;
	this->klas = klas;
}

void Medicine::Write()
{
	cout << "Medicine info: " << name << " " << year << endl;
	cout << "Heals from:" << application << endl;
}
string Medicine::GetName()
{
	return name;
}
string Medicine::GetApplication()
{
	return application;
}
int Medicine::GetYear()
{
	return year;
}
int Medicine::GetNumber()
{
	return number;
}
string Medicine::GetKlas()
{
	return klas;
}