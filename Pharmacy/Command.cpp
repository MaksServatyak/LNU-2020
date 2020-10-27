#include"Command.h"
#include<iostream>
#include <fstream>


using namespace std;
string name;
Command::Command() {
	medicines = new Medicine[100];
	lastMedicineIndex = -1;

	ifstream fin("Medicine.txt");

	int maxLen = 50;
	char* name = new char[maxLen],
		* application = new char[maxLen],
		* year = new char[maxLen],
		* number = new char[maxLen],
		* klas = new char[maxLen];

	char delim = ',';
	while (!fin.eof()) //while(fin) while(fin.get())...
	{
		fin.get(name, maxLen, delim);
		fin.get(); //read delim
		fin.get(application, maxLen, delim);
		fin.get();
		fin.get(year, maxLen, delim);
		fin.get();
		fin.get(number, maxLen, delim);
		fin.get();
		fin.getline(klas, maxLen);

		Medicine medicine(name, application, atoi(year), atoi(number),klas);
		AddMedicine(medicine);

	}

	fin.close();

	delete[] name;
	delete[] application;
	delete[] year;
	delete[] number;
	delete[] klas;

}


	Command::~Command()
	{
		ofstream fout("Medicine.txt");

		for (int i = 0; i <= lastMedicineIndex; i++)
		{
			fout << medicines[i].GetName() << ","
				<< medicines[i].GetApplication() << ","
				<< medicines[i].GetYear() << ","
				<< medicines[i].GetNumber() << ","
				<< medicines[i].GetKlas();

			if (i < lastMedicineIndex)
				fout << endl;
		}

		fout.close();

		delete[] medicines;
	}

	void Command::AddCream(Cream& cream)
	{
		AddMedicine(cream);
	}
	void Command::AddDrops(Drops& drops)
	{
		AddMedicine(drops);
	}
	void Command::AddTablets(Tablets& tablets)
	{
		AddMedicine(tablets);
	}

void Command::AddMedicine(Medicine& medicine) {
	if (lastMedicineIndex>=100)
	{
		throw "no memory for medicines";

	}

	medicines[++lastMedicineIndex] = medicine;
}

void Command::WriteMedicines() {
	cout << "Added medicines:" << endl;
	for (int i = 0; i <= lastMedicineIndex; i++)
	{
		medicines[i].Write();
	}
}

string Command::GetMostPopularIll()
{
	int maxNrIll = -1;
	string maxIll = "";

	for (int i = 0; i <= lastMedicineIndex; i++)
	{
		int nrOfIlls = 0;
		for (int j = i + 1; j <= lastMedicineIndex; j++)
		{
			if (medicines[i].GetApplication() == medicines[j].GetApplication())
				nrOfIlls++;
		}
		if (nrOfIlls > maxNrIll)
		{
			maxNrIll = nrOfIlls;
			maxIll = medicines[i].GetApplication();
		}
	}

	return maxIll;
}

void Command::Start() {
	Command cmd;
	Medicine c;
	cout << "Pharmacy Application" << endl;

	while (true)
	{
		cout << "   MENU:   " << endl;
		cout << "1.Show medicines." << endl;
		cout << "2.Add new medicines." << endl;
		cout << "3.Get most popular ill" << endl;
		cout << "4.Stop Application." << endl;

		char userInput;
		string name;
		string application;
		int year;
		int number;
		string klas;
		char userInput2;

		cin >> userInput;
		if (userInput=='1')
		{
			cmd.WriteMedicines();

		}
		else if (userInput=='2')
		{

			cout << "Input name of medicine:";
			cin >> name;
			cout << endl;
			cout << "Input application of medicine:";
			cin >> application;
			cout << endl;
			cout << "Input year of medicine:";
			cin >> year;
			cout << endl;
			cout << "Input number of medicine:";
			cin >> number;
			cout << "Input class of Medicine:"<<endl;
			cout << "1.Tablets"<<endl;
			cout << "2.Drops"<<endl;
			cout << "3.Cream"<<endl;
			cin >> userInput2;
			if (userInput2=='1')
			{
				c = Medicine(name, application, year, number,"tablets");
			}
			else if(userInput2 == '2')
			{
				c = Medicine(name, application, year, number,"drops");
			}
			else if(userInput2=='3')
			{
				c = Medicine(name, application, year, number,"cream");
			}
			else
			{
				cout << "We do not have this class";
			}
				
				try
				{
					cmd.AddMedicine(c);
				}
				catch (const char* err)
				{
					cout << err << endl;
				}
			
			
		}
		else if (userInput=='3')
		{
			cout << "Most popular ill is " << cmd.GetMostPopularIll() << endl;
		}
		else if (userInput == '4')
		{
			break;
		}
		else
		{
			throw "There is no given function!!!";
		}
	}
}