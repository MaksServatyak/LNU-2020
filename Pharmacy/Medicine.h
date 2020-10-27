#ifndef MEDICINE_H
#define MEDICINE_H

#include<string>
using namespace std;

class Medicine 
{
protected:
	string name;
	string application;
	int year;
	int number;
	string klas;

public:
	Medicine(string = "",string =" ",int = 2020,int = 1,string ="");

	virtual void Write();

	string GetName();
	string GetApplication();
	int GetYear();
	int GetNumber();
	string GetKlas();

};

#endif // !MEDICINE_H