/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY
 * CLASS      	   : CS1C FALL 2014
 * DATE       	   : 11/20/2014
 * ASIGNMENT #     : 13
 * ASSIGNMENT NAME : LINKED LIST
 ******************************************************************************/
#include "LinkedList.h"
int main()
{
	// Variables
	int intInput;	 // integer input
	double dubInput; // double input

	// Linked lists: 2 integer and 2 double lists
	linkedListType<int> myList1;
	linkedListType<int> myList2;
	linkedListType<double> myDub1;
	linkedListType<double> myDub2;

/******************************************************************************
 * 						    INTEGER LIST
 ******************************************************************************/
	cout <<	"INTEGER LIST\n"
			"---------------------------------------------------------\n";
	// Creates integer list list
	for(int i = 0; i < 5; i ++)
	{
		cout << "Please enter an integer value to input into integer list: ";
		cin  >> intInput;
		myList1.insertLast(intInput);
	}
	cout << "List contents: ";
	myList1.print();


	// Copies list1 into list2
	cout << "\n\nCopied list, and reversed contents\n";
	myList2 = myList1;
	// Reverses list2
	myList2.reverseList();
	cout << "Second list contents: ";
	myList2.print();

	// Deletes a node from list1
	cout << "\n\nEnter an integer value to delete from first list: ";
	cin  >> intInput;
	myList1.deleteNode(intInput);
	cout << "First list contents: ";
	myList1.print();
	cout << endl;

	// Deletes a non-existent node from list1
	cout << "Enter an integer value to delete from first list: ";
	cin >> intInput;
	myList1.deleteNode(intInput);


	// Deletes a node from list2
	cout << "\nEnter an integer value to delete from second list: ";
	cin  >> intInput;
	myList2.deleteNode(intInput);
	cout << "Second list contents: ";
	myList2.print();

	// Deletes a non-existent node from list2
	cout << "\nEnter an integer value to delete from second list: ";
	cin  >> intInput;
	myList1.deleteNode(intInput);


	// Insert into middle of list1
	cout << "\nEnter an integer value to insert into middle of first list: ";
	cin  >> intInput;
	myList1.insertMiddle(intInput);
	cout << "First list contents: ";
	myList1.print();

	// Insert into middle of list2
	cout << "\n\nEnter a value to insert into middle of second list: ";
	cin  >> intInput;
	myList2.insertMiddle(intInput);
	cout << "Second list contents: ";
	myList2.print();

	// Destroys list1 and attempts to delete from an empty list
	cout << "\n\n***** Destroying first list *****\n";
	myList1.destroyList();
	myList1.print();
	cout << "Enter an integer value to delete from first list: ";
	cin  >> intInput;
	myList1.deleteNode(intInput);

	// Destroys list1 and attempts to delete from an empty list
	cout << "\n\n***** Destroying second list *****\n";
	myList2.destroyList();
	myList2.print();
	cout << "Enter an integer value to delete from second list: ";
	cin  >> intInput;
	myList2.deleteNode(intInput);
	cout << endl;
/******************************************************************************
 * 						    DOUBLE LIST
 ******************************************************************************/
	cout <<	"\nDOUBLE LIST\n"
		    "---------------------------------------------------------\n";
	// Creates list
	for(int i = 0; i < 5; i ++)
	{
		cout << "Please enter a double value to input into double list: ";
		cin  >> dubInput;
		myDub1.insertLast(dubInput);
	}
	cout << "List contents: ";
	myDub1.print();


	// Copies list1 into list2
	cout << "\n\nCopied list, and reversed contents\n";
	myDub2 = myDub1;
	// Reverses list2
	myDub2.reverseList();
	cout << "Second list contents: ";
	myDub2.print();

	// Deletes a node from list1
	cout << "\n\nEnter a double value to delete from first list: ";
	cin  >> dubInput;
	myDub1.deleteNode(dubInput);
	cout << "First list contents: ";
	myDub1.print();
	cout << endl;

	// Deletes a non-existent node from list1
	cout << "Enter a double value to delete from first list: ";
	cin >> dubInput;
	myDub1.deleteNode(dubInput);


	// Deletes a node from list2
	cout << "\nEnter a double value to delete from second list: ";
	cin  >> dubInput;
	myDub2.deleteNode(dubInput);
	cout << "Second list contents: ";
	myDub2.print();

	// Deletes a non-existent node from list2
	cout << "\nEnter a double value to delete from second list: ";
	cin  >> dubInput;
	myDub2.deleteNode(dubInput);


	// Insert into middle of list1
	cout << "\nEnter a double value to insert into middle of first list: ";
	cin  >> dubInput;
	myDub1.insertMiddle(dubInput);
	cout << "First list contents: ";
	myDub1.print();

	// Insert into middle of list2
	cout << "\n\nEnter a double value to insert into middle of second list: ";
	cin  >> dubInput;
	myDub2.insertMiddle(dubInput);
	cout << "Second list contents: ";
	myDub2.print();

	// Destroys list1 and attempts to delete from an empty list
	cout << "\n\n***** Destroying first list *****\n";
	myDub1.destroyList();
	myDub1.print();
	cout << "Enter a double value to delete from first list: ";
	cin  >> dubInput;
	myDub1.deleteNode(dubInput);

	// Destroys list1 and attempts to delete from an empty list
	cout << "\n\n***** Destroying second list *****\n";
	myDub2.destroyList();
	myDub2.print();
	cout << "Enter a double value to delete from second list: ";
	cin  >> dubInput;
	myDub2.deleteNode(dubInput);
	return 0;
}
