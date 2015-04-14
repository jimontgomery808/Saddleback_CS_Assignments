/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY
 * CLASS      	   : CS1D SPRING 2015
 * DATE       	   : 3/10/2015
 * ASIGNMENT #     : 7
 * ASSIGNMENT NAME : Heaps
 *******************************************************************************/
#include "Heap.h"
/******************************************************************************
Assignment 7 - Heap
_______________________________________________________________________________
This program will implement a heap
 ******************************************************************************/
int main()
{
	// Creates a heap object
	Heap* myHeap = new Heap();

	// Inserts values into heap, then prints
	cout << "Inserting value, and printing heap:\n\n";
	myHeap->insert(67);
	myHeap->print();
	myHeap->insert(88);
	myHeap->print();
	myHeap->insert(77);
	myHeap->print();
	myHeap->insert(52);
	myHeap->print();
	myHeap->insert(44);
	myHeap->print();
	myHeap->insert(11);
	myHeap->print();
	myHeap->insert(66);
	myHeap->print();
	myHeap->insert(93);
	myHeap->print();

	// Deletes minimum value from heap, then prints
	cout << "\n\nDeleting min value, and printing heap:\n\n";
	myHeap->deletemin();
	myHeap->print();
	myHeap->deletemin();
	myHeap->print();
	myHeap->deletemin();
	myHeap->print();
	myHeap->deletemin();
	myHeap->print();
	myHeap->deletemin();
	myHeap->print();
	myHeap->deletemin();
	myHeap->print();
	myHeap->deletemin();
	myHeap->print();


	return 0;
}
