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

using namespace std;

// Struct - holds character and next/prev
struct node
{
	char input;
    node *next;
    node *prev;
};

// CLASS - QUEUE
class Queue
{
	public:
			// Constructor
			Queue();
			// Destructor
			~Queue();
			// Initiate: add to back of queue
			void Initiate(string checkString);
			// isEmpty: checks if queue is empty
			bool isEmpty();
			// isPalindrome: checks if queue is a palindrome
			bool isPalindrome();
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
