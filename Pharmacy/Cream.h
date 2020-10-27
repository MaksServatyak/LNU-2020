#ifndef CREAM_H
#define CREAM_H

#include<string>
#include<iostream>
#include"Medicine.h"
using namespace std;

class Cream : public Medicine
{
	
public:
	Cream(string = "", string = " ", int = 2020, int = 1, string = "");
	void Write()
	{
		cout << "This is a Cream" << endl;
	}
};

#endif // !CREAM_H