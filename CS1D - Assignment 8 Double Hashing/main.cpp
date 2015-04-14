/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY
 * CLASS      	   : CS1D SPRING 2015
 * DATE       	   : 3/17/2015
 * ASIGNMENT #     : 8
 * ASSIGNMENT NAME : Double Hashing
 *******************************************************************************/
#include "Hash.h"
#include <queue>
#include "DEQUE.h"

/******************************************************************************
 * ASSIGNMENT 8 - Double Hashing
 ******************************************************************************/
int main()
{
	// Variables
	int location;	 // number returned from hash function
	int selection;   // menu selection
	element temp;    // temporary element struct
	int number;      // key
	string town;     // city name
	DEQUE array[40]; // bucket array


/******************************************************************************
 * MENU - allows user to insert, delete, and display hashtable
 ******************************************************************************/

	// MENU
	cout << "\nHASH TABLE MENE\n"
			"----------------\n"
			"1.     Insert\n"
			"2.     Delete\n"
			"3.     Display\n"
			"0.     EXIT\n\n"
			"Selection: ";

	cin >> selection;
	cin.ignore();
	cout << endl;


	while(selection != 0)
	{
		switch(selection)
		{
			// INSERT - hashtable
			case 1: cout << "Enter number: ";
					cin  >> number;
					cin.ignore();
					cout << "Enter city: ";
					getline(cin, town);

					temp.num = number;
					temp.city = town;

					location = hashFunction(temp);
					array[location].push_back(temp);
				    break;

		    // DELETE - hashtable
			case 2: cout << "Enter a key to delete: ";
			        cin  >> number;
					location = deleteEntry(number);
					array[location].clear(number);
				    break;

			// DISPLAY - hashtable
			case 3: for(int i = 0; i < 40; i ++)
			{
				array[i].display(i);
			}
			break;
		}
		// MENU
		cout << "\nHASH TABLE MENE\n"
					"----------------\n"
					"1.     Insert\n"
					"2.     Delete\n"
					"3.     Display\n"
					"0.     EXIT\n\n"
					"Selection: ";

			cin >> selection;
			cin.ignore();
			cout << endl;
	}

	return 0;
}
