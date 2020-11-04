#ifndef COMMAND_H
#define COMMAND_H

#include<iostream>
#include"Cream.h"
#include"Drops.h"
#include"Tablets.h"
#include"Medicine.h"

using namespace std;
class Command
{
	Medicine* medicines;
	int lastMedicineIndex;
	string name;

public:
	Command();
	~Command();

	void AddDrops(Drops&);
	void AddTablets(Tablets&);
	void AddCream(Cream&);
	void AddMedicine(Medicine&);
	void WriteMedicines();
	string GetMostPopularIll();
	void Start();
};

#endif // !COMMAND_H
