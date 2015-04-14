/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY & STEVEN GRENROCK
 * CLASS      	   : CS1D SPRING 2015
 * DATE       	   : 3/31/2015
 * ASIGNMENT #     : 9
 * ASSIGNMENT NAME : Dictionary
 *******************************************************************************/
#include "SkipList.h"
/*******************************************************************************
 * Assignment 9 - Dictionary
 * ____________________________________________________________________________
 * This assignment will implement a dictionary by using a skip list
 *******************************************************************************/
int main()
{
	// Variables
	int selection;     // IN   - menu selection
	int key;		   // IN   - key to search/delete
	string city;       // IN   - city name
	info temp;         // IN   - temporary struct
	SkipList skipList;  // CALC - skip list

	// OUTPUT/INPUT - menu output and selection
	cout << MENU;
	cin >> selection;
	cin.ignore();

	while(selection != 0)
	{
		switch(selection)
		{
			// Insert an element
			case 1: cout << "Enter a key: ";
					cin  >> key;
					cin.ignore();

					cout << "Enter a city: ";
					getline(cin, city);
					temp.key = key;
					temp.city = city;
					skipList.insert(temp);

			break;

			// Delete an element
			case 2: cout << "Enter a key to delete from list: ";
					cin  >> key;

					if(skipList.contains(key))
					{
						cout << "Erased " << key << endl;
						skipList.erase(key);
					}
					else
					{
						cout << key << " not found" << endl;
					}

			break;

			// Print the list
			case 3: skipList.print();

			break;
		}

		cout << MENU;
		cin >> selection;
		cin.ignore();
	}

    return 0;
}
