/******************************************************************************
 * Josh Montgomery
 * CS1C Fall 2014
 * 12/04/2014
 * Assignment 14 - Miscellaneous Topics
 ******************************************************************************/
#include <cmath>
#include <iostream>
#include <cerrno>
#include <climits>
#include <iomanip>

#include <ctime>
using namespace std;

/******************************************************************************
 * PROTOTYPES
 ******************************************************************************/
double tabulate(double(*f)(double), double num);
double cubeFunc(double num);
double cubeRootFunc(double num);
int bitCount(int n);

/******************************************************************************
 * Assignment 14 - Miscellaneous Topics
 * ____________________________________________________________________________
 * This program will cover the various miscellaneous topics, including the time
 * functions, the built in math routines, pointers to functions, and number of
 * bits
 ******************************************************************************/
int main()
{
	// VARIABLES
	time_t currentTime = time(0);
	time_t eightyEight = currentTime + (7603200);
	clock_t t1;
	clock_t t2;
	double num1 = -2;
	int num2;
	double num3 = 4;
	int num4;
	int num5;
	int totalBits = 0;

	// Start timing program
	t1 = clock();

	cout << "1. Using the time functions \n"
			"***************************\n\n";

	// Ouput - current date and date 88 days from now
	cout << "Today's date: " << ctime(&currentTime);
	cout << "Date 88 days from now: " << ctime(&eightyEight);

	cout << endl;

	// Ouput - difference in days from July 25 and December 24
	struct tm a = {0,0,0,26,6,114};
	struct tm b = {0,0,0,24,11,114};
	time_t x = mktime(&a);
	time_t y = mktime(&b);
	if ( x != (time_t)(-1) && y != (time_t)(-1) )
	{
		double difference = difftime(y, x) / (60 * 60 * 24);
		cout << ctime(&x);
		cout << ctime(&y);
		cout << "difference = " << difference << " days" << endl;
	}


	// Ouput - Mathematical functions and error

	cout << "2. Using the built-in math routines \n"
		    "***********************************\n\n";
	num2 = sqrt(num1);
	cout << "sqrt error number is " << strerror(num2) << endl;
	cout <<  "sqrt of " << num1  << " is " << num2 << endl;

	num4 = num3/0;
	cout << "\ndivide by zero error number is " << strerror(num3) << endl;
	cout <<  num3 << " divided by zero is: " << num4 << endl;

	num5 = log(num1);
	cout << "\nnatural log of negative number error is: " << strerror(num5) << endl;
	cout << "natural log of " << num1 << " is: " << num5 << endl;

	cout << "\n1.0e18 + 4 - 1.0e18 is: ";
	int power1 = pow(10.0,18.0) + 4 - pow(10.0,18.0);
	cout << endl;
	cout << strerror(power1) << endl;

	cout << "\nFixing problem: " << endl;
	cout << "1.0e18 - 1.0e18 + 4 is: ";
	int power2 = pow(10.0,18.0) - pow(10.0,18.0) + 4;
	cout << power2 << endl << strerror(power2) << endl << endl;


	// Output - pointers to functions

	cout << "3. Pointers to functions \n"
		    "************************\n";

	double c1 = cubeFunc(23);
	cout << "Cube of 23 is: " << c1 << endl;

	double c2 = cubeRootFunc(27);
	cout << "Cube root of 27 is: " << c2 << endl;

	double cube = tabulate(cubeFunc, 5.0);
	cout << "Cube of 5 is: " << cube << endl;
	double cubeRoot = tabulate(cubeRootFunc, 8);
	cout << "Cube root of 8 is: " << cubeRoot << endl;


	// Output - bits in the alphabet
	cout <<"\n4a. Bit count for capital letters\n"
		   "***********************************\n";
	for(int i = 65; i < 91; i ++)
	{
		totalBits += bitCount(i);
		cout <<"Bit count for " << char(i) << " = " << bitCount(i) << endl;
	}
	cout <<"\n4b. Bit count for lower-case letters\n"
		   "**************************************\n";
	for(int i = 97; i < 123; i ++)
	{
		totalBits += bitCount(i);
		cout <<"Bit count for " << char(i) << " = " << bitCount(i) << endl;
	}

	cout << "Total Bits On: " << totalBits << endl;

	// End timing program
		t2 = clock();
		float diff = ((float)t2-(float)t1);
		cout<< "\nProgram time in nanoseconds: " << diff << endl << endl;


		return 0;

}

// Cube Function
double cubeFunc(double num)
{
	return num * num * num;
}

// Cube Root Function
double cubeRootFunc(double num)
{
	return cbrt(num);
}

// Tabulate - pointer function
double tabulate(double(*f)(double), double num)
{
	return (*f)(num);
}
// Bit Count Function
int bitCount(int n)
{
	int count = 0;
	while(n) {
		n = n & (n-1);
		count++;
	}
	return count;
}



