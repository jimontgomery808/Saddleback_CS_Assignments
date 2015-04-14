/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY
 * CLASS      	   : CS1D SPRING 2015
 * DATE       	   : 1/27/2015
 * ASIGNMENT #     : 1
 * ASSIGNMENT NAME : Queue Palindrome
 ******************************************************************************/
#ifndef QUEUE_H_
#define QUEUE_H_
#include <iostream>
#include <iomanip>
#include "Winery.h"

using namespace std;

struct node
{
	Winery  currentWinery;
	node *next;
	node *prev;
};

// CLASS - QUEUE
class WineryList
{



	public:
			// Constructor
			WineryList();
			// Destructor
			~WineryList();
			// Initiate: add to back of queue
			void Enqueue(Winery object);
			// isEmpty: checks if queue is empty
			bool isEmpty();
			// isPalindrome: checks if queue is a palindrome
			void Display();
	private:

			// head: keeps track of head of queue
			node *head;
			// tail: keeps track of tail of queue
			node *tail;

};

void OutputHeader();
void PrintStringArray(string strArray[]);
void PrintAssignmentHeader(const string NAME,
		                   const string CLASS,
		                   const string DUE_DATE,
		                   const int AS_NUM,
		                   const string AS_NAME,
		                   const char AS_TYPE);
#endif /* QUEUE_H_ */

// Default constructor
WineryList::WineryList()
:head(NULL), tail(NULL)
{
	ifstream inFile;
	inFile.open("wineries.txt");

	node *temp;
	temp = new node;

	while(inFile)
	{


		temp->currentWinery.Initiate(inFile);

		temp = temp->next;
	}

}

// Destructor
WineryList::~WineryList()
{}

// Enqueue - adds character to back of queue
void WineryList::Enqueue(Winery object)
{
	// temporary node
	node *temp;
    // Creates new node
	temp = new node;

	// Current node is pointed to tail
	temp->next = NULL;

	if(isEmpty())
	{

		temp->currentWinery = object;
		// Points head to temp
		head = temp;
		// Points tial to temp
		tail = temp;
		// Head->prev now points to NULL
		head->prev = NULL;
	}
	else
	{
		temp->currentWinery = object;
		// Tail->next points to temp node
		tail->next = temp;
		// Temp->prev points to tail
		temp->prev = tail;
	}
	// Tail points to temp
	tail = temp;
}

// isEmpty: return if head is pointing to NULL
bool WineryList::isEmpty()
{
	return head == NULL;
}
void WineryList::Display()
{
	node *temp;
	temp = head;

	while(head != NULL)
	{
		temp->currentWinery.display();
	}
}

