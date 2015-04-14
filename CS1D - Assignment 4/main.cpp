/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY
 * CLASS      	   : CS1D SPRING 2015
 * DATE       	   : 2/17/2015
 * ASIGNMENT #     : 4
 * ASSIGNMENT NAME : Queue-DeQue Vector
 ******************************************************************************/
#include "Queue.h"
#include "Vector.h"
/*******************************************************************************
 * ASSIGNMENT 4: Queue-DeQue Vector
 * _____________________________________________________________________________
 *
 *This program will implement the Queue interface with a class that is based
 *on a doubly linked list. It will also implement the vector ADT with the same
 *class
 ******************************************************************************/
int main()
{
	/* Queue */
	Queue<string> myQueue;

	// Variables
	int selection;		  // INPUT - menu selection
	string stringEnqueue; // INPUT - string value to be enqueued
	int vectorInput1;     // INPUT - first integer input to be input into vector
	int vectorInput2;	  // INPUT - second integer input to be input into
						  // 		 vector

	// OUTPUT & INPUT  - menu selection
	cout << MENU;
	cin  >> selection;
	cin.ignore();

	while(selection != 0)
	{
		// SWITCH - allows user to utilize various functions of Queue class
		switch(selection)
		{
		case 1: cout << "Enter a string to enqueue: ";
				getline(cin, stringEnqueue);
				myQueue.enqueue(stringEnqueue);
				break;

		case 2: myQueue.dequeue();
				break;

		case 3:
				cout << "Size of Queue is: " << myQueue.size() << endl;
				break;

		case 4: if(myQueue.empty())
				cout << "Queue is empty\n";
				else
				cout << "Queue is NOT empty\n";
				break;

		case 5: myQueue.front();
				cout << endl;
				break;

		case 6: myQueue.display();
				break;
		}

		cout << endl << MENU;
		cin  >> selection;
		cin.ignore();
	}

	cout << "VECTOR ADT\n"
			"---------------------------------------------\n";
	cout << "Enter a size to allocate for Vector: ";
	cin >> vectorInput1;
	cout << "Enter a value to fill the vector: ";
	cin >> vectorInput2;

	/* Vector */
	Vector<int> myVector(vectorInput1, vectorInput2);

	// OUTPUT & INPUT  - menu selection
	cout << endl << V_MENU;
		cin  >> selection;
		cin.ignore();

		while(selection != 0)
		{
			// SWITCH - allows user to utilize various functions of Vector class
			switch(selection)
			{

			case 1: cout << "Enter a value to push_back: ";
					cin >> vectorInput1;
					myVector.push_back(vectorInput1);
					break;

			case 2: myVector.pop_back();
					break;

			case 3: cout << "Enter a value to insert into vector: ";
					cin  >> vectorInput1;
					cout << "Enter an index of the vector in which to insert  it: ";
					cin  >> vectorInput2;
					myVector.insert(vectorInput1, vectorInput2 -1);
					break;

			case 4: cout << "Size of vector is " << myVector.size() << endl;
					break;

			case 5: if(myVector.empty())
					cout << "Vector is empty\n";
					else
					cout << "Vector is NOT empty\n";
					break;

			case 6: myVector.front();
					cout << endl;
					break;

			case 7: myVector.display();
					break;
			}

			cout << endl << V_MENU;
			cin  >> selection;
			cin.ignore();
		}
}
