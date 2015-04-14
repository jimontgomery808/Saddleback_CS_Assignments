/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY
 * CLASS      	   : CS1D SPRING 2015
 * DATE       	   : 1/27/2015
 * ASIGNMENT #     : 1
 * ASSIGNMENT NAME : Queue Palindrome
 ******************************************************************************/
#include "Queue.h"

// Default constructor
Queue::Queue()
:head(NULL), tail(NULL)
{}

// Destructor
Queue::~Queue()
{}

// Enqueue - adds character to back of queue
void Queue::Initiate(string checkString)
{
	// temporary node
	node *temp;

	// CALC - loop runs until end of checkString
	for(unsigned int i = 0; i < checkString.size(); i ++)
	{
		// isalpha: checks if current index in checkString is a-z or A-Z
		if(isalpha(checkString[i]))
		{
			// Creates new node
			temp = new node;

			// Assigns data into input
			temp->input = checkString[i];

			// Current node is pointed to tail
			temp->next = NULL;

			if(isEmpty())
			{
				// Points head to temp
				head = temp;
				// Points tial to temp
				tail = temp;
				// Head->prev now points to NULL
				head->prev = NULL;
			}
			else
			{
				// Tail->next points to temp node
				tail->next = temp;
				// Temp->prev points to tail
				temp->prev = tail;
			}
			// Tail points to temp
			tail = temp;
		}

	}
}

// isEmpty: return if head is pointing to NULL
bool Queue::isEmpty()
{
	return head == NULL;
}

// isPalindrome: returns if queue is a palindrome
bool Queue::isPalindrome()
{
	// CALC - boolean to be returned, initialized to true
	bool palindrome = true;

	// CALC - runs while head and tail are not equal to NULL
	while(head != NULL && tail != NULL)
	{
		// Sets palindrome to false if head->input is not equal to tail->input
		if(toupper(head->input) != toupper(tail->input))
		{
			palindrome = false;
		}
		// Head points to next in queue
		head = head->next;
		tail = tail->prev;
	}

	return palindrome;
}
