/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY
 * CLASS      	   : CS1D SPRING 2015
 * DATE       	   : 2/10/2015
 * ASIGNMENT #     : 3
 * ASSIGNMENT NAME : Stacks and Deques
 ******************************************************************************/
#include "header.h"
#include "SinglyLinkedList.h"
#include "DEQUE.h"

template<class data>
void DisplayVector(vector<data> &inVector);
void CheckEquation(string inString);
void PrintAssignmentHeader(const string NAME,
						   const string CLASS,
						   const string DUE_DATE,
						   const int AS_NUM,
						   const string AS_NAME,
						   const char AS_TYPE);
/*******************************************************************************
 * ASSIGNMENT 3: Stacks and Deques
 * _____________________________________________________________________________
 *
 *This program will implement the STL vector as a stack, implement my own
 *version of a stack, and my own version of a deque. The program will then
 *check if an equation has proper formatting using a stack
 ******************************************************************************/
int main()
{
	/*VARIABELS */

	// temporary string array
	string tempString[] = {"Paula", "JoAnn", "Jack",
                           "Mark", "Paul", "Eric"};
	// temporary integer array
		int tempInt[]       = {98, 88, 88, 123,8445,
				               9833, 12, 354};
	// temporary double array
	double tempDouble[] = {2788.123, 243.76, 8445.5612,
			               19833.121, 12.4};

	/* VECTORS */

	// initiates stringVector with values located in each index of tempString
	vector<string> stringVector(tempString, tempString + 6);
	// initiates integerVector with values located in each index of tempInt
	vector<int>    integerVector(tempInt, tempInt + 8);
	// initiates doubleVector with values located in each index of tempDouble
	vector<double> doubleVector(tempDouble, tempDouble + 5);

	/* SINGLY LINKED LISTS */
	S_LIST<string> stringSList;
	S_LIST<int>    integerSList;
	S_LIST<double> doubleSList;

	/* DEQUEs */
	DEQUE<string> stringDList;
	DEQUE<int>    integerDList;
	DEQUE<double> doubleDList;

	/* INITIATES SINGLY LINKED LISTS */
	stringSList.initiate(tempString, 6);
	integerSList.initiate(tempInt, 8);
	doubleSList.initiate(tempDouble, 5);

	/* INITIATES DEQUES */
	stringDList.initiate(tempString, 6);
	integerDList.initiate(tempInt, 8);
	doubleDList.initiate(tempDouble, 5);

	/* OUTPUT - Assignment Header */
	PrintAssignmentHeader("Josh Montgomery", "CS1D", "02/10/2015", 3,
			              "Stacks and Deques", 'A');

	/* TESTING INITIALIZATION OF VECTORS BY OUTPUTTING CONTENTS */
	cout << "Outputting contents of string vector:\n";
	DisplayVector(stringVector);
	cout <<  endl;

	cout <<"Outputting contents of integer vector:\n";
	DisplayVector(integerVector);
	cout << endl;

	cout <<"Outputting contents of double vector:\n";
	DisplayVector(doubleVector);
	cout << endl;

	/* TESTING POP FUNCTION OF STL VECTOR */

	stringVector.pop_back();
	integerVector.pop_back();
	doubleVector.pop_back();

	cout << "Outputting contents of string vector after calling pop_back:\n";
	DisplayVector(stringVector);
	cout <<  endl;

	cout <<"Outputting contents of integer vector after calling pop_back:\n";
	DisplayVector(integerVector);
	cout << endl;

	cout <<"Outputting contents of double vector after calling pop_back:\n";
	DisplayVector(doubleVector);
	cout << endl;


	/* OUTPUT - CONTENTS OF SINGLY LIST LIST */
	cout << "Displaying contents of Singly Linked List (string)\n";
	stringSList.display();
	cout << endl;

	cout << "Displaying contents of Singly Linked List(int)\n";
	integerSList.display();
	cout << endl;

	cout << "Displaying contents of Singly Linked List(double)\n";
	doubleSList.display();
	cout << endl;

	/* TESTING POP METHOD OF SINGLY LINKED LIST */
	cout << "Popping Singly Linked List (string)\n";
	stringSList.pop();
	stringSList.display();
	cout << endl;

	cout << "Popping Singly Linked List (integer)\n";
	integerSList.pop();
	integerSList.display();
	cout << endl;

	cout << "Popping Singly Linked List (double)\n";
	doubleSList.pop();
	doubleSList.display();
	cout << endl;

	/* TESTING push FUNCTION OF SINGLY LINKED LIST */
	cout << "Pushing Josh onto the string stack:\n";
	stringSList.push("Josh");
	stringSList.display();
	cout << endl;

	cout << "Pushing 500 onto the integer stack:\n";
	integerSList.push(500);
	integerSList.display();
	cout << endl;

	cout << "Pushing 500.00 onto the double stack:\n";
	doubleSList.push(500.0000);
	doubleSList.display();
	cout << endl;

	/* OUTPUT - CONTENTS OF Double Ended Queue */
	cout << "Displaying contents of DEQUE(string)\n";
	stringDList.display();
	cout << endl;

	cout << "Displaying contents of DEQUE(int)\n";
	integerDList.display();
	cout << endl;

	cout << "Displaying contents of DEQUE(double)\n";
	doubleDList.display();
	cout << endl;


	/* TESTING push_back and push-front FUNCTION */
	cout << "Testing push_front and push_back functions (string, 'front' pushed to front, 'back' pushed to back):\n";
	stringDList.push_back("Back");
	stringDList.push_front("Front");
	stringDList.display();
	cout << endl;

	cout << "Testing push_front and push_back functions (integer, '100' pushed to front, '0' pushed to back):\n";
	integerDList.push_back(0);
	integerDList.push_front(100);
	integerDList.display();
	cout << endl;

	cout << "Testing push_front and push_back functions (double, '100.00' pushed to front, '0.00' pushed to back):\n";
	doubleDList.push_back(0.00);
	doubleDList.push_front(100.00);
	doubleDList.display();
	cout << endl;

	/* TESTING pop_front FUNCTION */
	cout << "Testing the pop_front function(string):\n";
	stringDList.pop_front();
	stringDList.display();
	cout << endl;

	cout << "Testing the pop_front function(integer):\n";
	integerDList.pop_front();
	integerDList.display();
	cout << endl;

	cout << "Testing the pop_front function(double):\n";
	doubleDList.pop_front();
	doubleDList.display();
	cout << endl;

	/* TESTING pop_back FUNCTION */
	cout << "Testing the pop_back function(string):\n";
	stringDList.pop_back();
	stringDList.display();
	cout << endl;

	cout << "Testing the pop_back function(integer):\n";
	integerDList.pop_back();
	integerDList.display();
	cout << endl;

	cout << "Testing the pop_back function(double):\n";
	doubleDList.pop_back();
	doubleDList.display();
	cout << endl;


	CheckEquation("{2x+3} {7x+8}");
	CheckEquation("{2x + 5) (6x+4)}");
	CheckEquation("[(8x+5) - 4x[9x+3]]");
	CheckEquation("{(8x+5) - 5x[9x+3]})");
	CheckEquation("(((8x+5) - x[9x+3])))");
	CheckEquation("(((8x+5) - x[9x+3])))");

	return 0;
}
