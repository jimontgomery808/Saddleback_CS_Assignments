/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY
 * CLASS      	   : CS1D SPRING 2015
 * DATE       	   : 1/27/2015
 * ASIGNMENT #     : 1
 * ASSIGNMENT NAME : Queue Palindrome
 ******************************************************************************/
#include "Queue.h"

/*******************************************************************************
 FUNCTION - PrintAssignmentHeader
 ______________________________________________________________________________
 This function will print an assignment header
 *******************************************************************************/
void PrintAssignmentHeader(const string NAME,
		                   const string CLASS,
		                   const string DUE_DATE,
		                   const int AS_NUM,
		                   const string AS_NAME,
		                   const char AS_TYPE)
{
	// OUTPUT - assignment header
	cout << setfill('*') << setw(40) << '*' << setfill(' ') << endl;
	cout << "PROGRAMMER" << right << setw(10) << ": " << NAME << endl;
	cout << "CLASS" << setw(15) << ": " << CLASS << endl;
	cout << "DATE" << setw(16) << ": " << DUE_DATE << endl;
	if(toupper(AS_TYPE) == 'A')
	{
		cout << "ASSIGNMENT #" << setw(8) << ": " << AS_NUM << endl;
		cout << "ASSIGNMENT NAME   : " << AS_NAME << endl;
	}
	else
	{
		cout << "LAB #" << setw(12) << ": " << AS_NUM << endl;
		cout << "LAB NAME" << setw(8) << ": " << AS_NAME << endl;
	}
	cout << setfill('*') << setw(40) << '*' << setfill(' ') << endl;
}
