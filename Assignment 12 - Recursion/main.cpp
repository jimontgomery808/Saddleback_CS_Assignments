/******************************************************************************
 * Josh Montgomery
 * CS1C Fall 2014
 * 11/13/2014
 * Assignment 12 - Recursion
 ******************************************************************************/
#include <iostream>
using namespace std;
/*******************************************************************************
 * Assignment 12 - Recursion
 * ____________________________________________________________________________
 * This program will use recursion to reverse a certain section of the
 * alphabet
 ******************************************************************************/
string ReverseRecursion(int b, int e, string inString);
void GetIndex(int &begin, int &end);
int main()
{

	// CONSTANT - alphabet string
	const string alpha = "abcdefghijklmnopqrstuvwxyz";

	// VARIABLES
	int begin;		// INPUT - beginning of alphabet section
	int end;		// INPUT - end of alphabet section

	// INPUT - prompt user for a beginning and ending index
	GetIndex(begin, end);

	// OUTPUT - reversed section of string
	cout << "OUTPUT: ";
	cout << ReverseRecursion(begin, end, alpha);
	cout << endl << endl;

	// INPUT - prompt user for a beginning and ending index
	GetIndex(begin, end);

	// OUTPUT - reversed section of string
	cout << "OUTPUT: ";
	cout << ReverseRecursion(begin, end, alpha);
	cout << endl << endl;

	// OUTPUT - entire string reversed
	cout << "Print alphabet in reverse order using recursion" << endl;
	system("pause");
	cout << "OUTPUT: ";
	cout << ReverseRecursion(1, 26, alpha);

	return 0;
}

/******************************************************************************
 * Function - ReverseRecursion
 * ____________________________________________________________________________
 * This function will use recursion to reverse a section of a string
 ******************************************************************************/
string ReverseRecursion(int b,           // IN - beginning of string
		 	 	 	  int e, 		  // IN - end of string
		 	 	 	  string inString) // IN - string to be manipulated
{
	// OUTPUT - will output as long as the ending index is greater than or
	//			equal to the beginning index
	if(b <= e)
	{
		// OUTPUT - outputs index before ending index
		char temp = inString[b-1];
		inString[b-1] = inString[e-1];
		inString[e-1] = temp;
	   // CALC - Recursion function call
	   return ReverseRecursion(b + 1, e-1, inString);
	}
	return inString;
}
/******************************************************************************
 * Function - GetIndex
 * ____________________________________________________________________________
 * This function will prompt the user for a starting and ending index for a
 * string
 ******************************************************************************/
void GetIndex(int &begin, int &end)
{
	// INPUT - prompt user for a beginning index
	cout << "Enter a beginning index: ";
	cin  >> begin;

	// INPUT - prompt user for a beginning index
	cout << "Enter an ending index: ";
	cin  >> end;
	cout << endl;
}
