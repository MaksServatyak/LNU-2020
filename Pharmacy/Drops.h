#ifndef DROPS_H
#define DROPS_H

#include<string>
#include<iostream>
#include"Medicine.h"
using namespace std;

class Drops : public Medicine
{
	string name;
	string application;
	int year;
	int number;
	string klas;
public:
	Drops(string = "", string = " ", int = 2020, int = 1, string = "");
	void Write()
	{
		cout << "This is a Drops" << endl;
	}
};

#endif // !DROPS_H