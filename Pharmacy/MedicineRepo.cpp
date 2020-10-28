#include "MedicineRepo.h"
#include <fstream>
#include <iostream>
using namespace std;

MedicineRepo::MedicineRepo(bool sync) : Repository(sync)
{
	ReadFromStorage();
}

MedicineRepo::~MedicineRepo()
{
}

void MedicineRepo::Show()
{
	for (int i = 0; i <= current; i++) {
		cout << i + 1 << endl;
		((Medicine*)data[i])->Write();
	}
}



