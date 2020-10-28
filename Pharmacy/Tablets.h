#ifndef TABLETS_H
#define TABLETS_H

#include<string>
#include<iostream>
#include"Medicine.h"
using namespace std;

class Tablets : public Medicine
{
	
public:
	Tablets (string = "", string = " ", int = 2020, int = 1, string = "");

	void Write()
	{
		cout << "This is a Tablets" << endl;
	}
};

#endif // !TABLETS_H