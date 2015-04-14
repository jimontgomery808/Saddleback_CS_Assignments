/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY
 * CLASS      	   : CS1D SPRING 2015
 * DATE       	   : 1/22/2015
 * ASIGNMENT #     : 1
 * ASSIGNMENT NAME : Queue Palindrome
 ******************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

/******************************************************************************
 * FUNCTION - OutputHeader
 * ____________________________________________________________________________
 *
 * This function will output a table header to the result of the isPalindrome
 * check
 ******************************************************************************/
void OutputHeader()
{
	// OUTPUT - header
	cout << left << setw(39) << "Phrase/Word" << "Palindrome?\n";
	cout << setfill('-') << setw(37) << '-' << setfill(' ');
	cout << setw(2) << ' ' << setfill('-') << setw(11) << '-' << setfill(' ')
		 << endl;
}
