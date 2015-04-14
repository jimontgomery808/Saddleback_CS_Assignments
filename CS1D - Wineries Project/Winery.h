
#ifndef WINERY_H_
#define WINERY_H_
#include "Wines.h"

class Winery
{
	public:
			Winery::Winery();
			Winery::~Winery();
			void Initiate(ifstream &inFile);
			void setName(string nameSet);
			void setNum(string numSet);
			void setMilesFrom(string milesSet);
			void setNumWines(string numWinesSet);
			string getName();
			int getNum();
			double getMiles();
			int getNumWines();
			void display();

	private:
			string name;
			string number;
			string distanceFrom[30];
			string milesFrom;
			string numWines;
			Wines winesOffered[10];
};

Winery::Winery()
{}
void Winery::Initiate(ifstream &inFile)
{

	int numberWines;

	string tempName;
	string tempYear;
	double tempPrice;

	getline(inFile, name);
	getline(inFile, number);

	for(int i = 0; i < 10; i ++)
	{
		getline(inFile, distanceFrom[i] );
	}

	getline(inFile, milesFrom);

	getline(inFile, numWines);

	numberWines = atoi(numWines.c_str());

	for(int i = 0; i < numberWines; i ++)
	{

		getline(inFile, tempName);
		winesOffered[i].setName(tempName);

		getline(inFile, tempYear);
		winesOffered[i].setYear(tempYear);

		inFile >> tempPrice;
		winesOffered[i].setPrice(tempPrice);

		inFile.ignore();
	}

}

Winery::~Winery()
{}

void Winery::display()
{
	int numberWines = atoi(numWines.c_str());
	cout << "Winery: " << name << endl;
	cout << "Winery #" << number << endl;
	cout << "Distance from other wineries: " << endl;

	for(int i = 0; i < 10; i ++)
	{
		cout << distanceFrom[i] << endl;
	}

	cout << "Miles from Canyon Villa: " << milesFrom << endl;
	cout << "Number of wines offered: " << numWines << endl << endl;
	cout << "Wines offered" << endl;
	cout << "-------------" << endl;

	for(int i = 0; i < numberWines; i ++)
	{
		winesOffered[i].Display();
		cout << endl;
	}
}

#endif /* WINERY_H_ */
