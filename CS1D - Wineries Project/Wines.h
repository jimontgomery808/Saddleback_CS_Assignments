#ifndef WINERIES_H_
#define WINERIES_H_
#include "header.h"

class Wines
{

	public:
			Wines::Wines();
			Wines::Wines(string nameSet, string yearSet, double priceSet);
			Wines::~Wines();
			void setName(string nameSet);
			void setYear(string yearSet);
			void setPrice(double priceSet);
			string getName();
			string getYear();
			double getPrice();
			void Display();

	private:
			string name;
			string year;
			double price;
};

Wines::Wines()
:name(""), year("0000"), price(0.00)
{}

Wines::Wines(string nameSet, string yearSet, double priceSet)
:name(nameSet), year(yearSet), price(priceSet)
{}

Wines::~Wines()
{}

void Wines::setName(string nameSet)
{
	name = nameSet;
}

void Wines::setYear(string yearSet)
{
	year = yearSet;
}

void Wines::setPrice(double priceSet)
{
	price = priceSet;
}

string Wines::getName()
{
	return name;
}

string Wines::getYear()
{
	return year;
}

double Wines::getPrice()
{
	return price;
}
void Wines::Display()
{
	cout << "Name: "  << name  << endl;
	cout << "Price: " << setprecision(2) << fixed << price << endl;
	cout << "Year: "  << year  << endl;
}

#endif /* WINERIES_H_ */
